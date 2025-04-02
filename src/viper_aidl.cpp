#include "viper_aidl.h"
#include "viper/constants.h"
#include <aidl/android/media/audio/common/PcmType.h>
#include <android-base/thread_annotations.h>

using aidl::android::hardware::audio::effect::CommandId;
using aidl::android::hardware::audio::effect::Descriptor;
using aidl::android::hardware::audio::effect::Flags;
using aidl::android::hardware::audio::effect::IEffect;
using aidl::android::hardware::audio::effect::Parameter;
using aidl::android::hardware::audio::effect::State;
using aidl::android::media::audio::common::AudioUuid;
using aidl::android::media::audio::common::PcmType;
using android::hardware::EventFlag;

/**
 * EventFlag to indicate that the data FMQ is not Empty after a write.
 * TODO: b/277900230, Define in future AIDL version.
 */
static constexpr uint32_t kEventFlagDataMqNotEmpty = 0x1 << 11;

inline AudioUuid stringToUuid(const char* str) {
    AudioUuid uuid{};
    uint32_t tmp[10];
    if (!str || sscanf(str, "%08x-%04x-%04x-%04x-%02x%02x%02x%02x%02x%02x", tmp,
                       tmp + 1, tmp + 2, tmp + 3, tmp + 4, tmp + 5, tmp + 6,
                       tmp + 7, tmp + 8, tmp + 9) < 10) {
        return uuid;
    }

    uuid.timeLow = (uint32_t)tmp[0];
    uuid.timeMid = (uint16_t)tmp[1];
    uuid.timeHiAndVersion = (uint16_t)tmp[2];
    uuid.clockSeq = (uint16_t)tmp[3];
    uuid.node.insert(uuid.node.end(), {(uint8_t)tmp[4], (uint8_t)tmp[5], (uint8_t)tmp[6],
                                       (uint8_t)tmp[7], (uint8_t)tmp[8], (uint8_t)tmp[9]});
    return uuid;
}

const AudioUuid kType = stringToUuid("b9bc100c-26cd-42e6-acb6-cad8c3f778de");
const AudioUuid kUuid = stringToUuid("90380da3-8536-4744-a6a3-5731970e640f");
const Descriptor kDescriptor = {
        .common = {
                .id = {
                        .type = kType,
                        .uuid = kUuid,
                        .proxy = std::nullopt
                },
                .flags = {
                        .type = Flags::Type::INSERT,
                        .insert = Flags::Insert::LAST,
                        .volume = Flags::Volume::NONE
                },
                .name = VIPER_NAME,
                .implementor = VIPER_AUTHORS,
        },
};

constexpr size_t getPcmSampleSizeInBytes(::aidl::android::media::audio::common::PcmType pcm) {
    using ::aidl::android::media::audio::common::PcmType;
    switch (pcm) {
        case PcmType::UINT_8_BIT:
            return 1;
        case PcmType::INT_16_BIT:
            return 2;
        case PcmType::INT_32_BIT:
            return 4;
        case PcmType::FIXED_Q_8_24:
            return 4;
        case PcmType::FLOAT_32_BIT:
            return 4;
        case PcmType::INT_24_BIT:
            return 3;
    }
    return 0;
}

constexpr size_t getChannelCount(
        const ::aidl::android::media::audio::common::AudioChannelLayout& layout,
        int32_t mask = std::numeric_limits<int32_t>::max()) {
    using Tag = ::aidl::android::media::audio::common::AudioChannelLayout::Tag;
    switch (layout.getTag()) {
        case Tag::none:
            return 0;
        case Tag::invalid:
            return 0;
        case Tag::indexMask:
            return __builtin_popcount(layout.get<Tag::indexMask>() & mask);
        case Tag::layoutMask:
            return __builtin_popcount(layout.get<Tag::layoutMask>() & mask);
        case Tag::voiceMask:
            return __builtin_popcount(layout.get<Tag::voiceMask>() & mask);
    }
    return 0;
}

constexpr size_t getFrameSizeInBytes(
        const ::aidl::android::media::audio::common::AudioFormatDescription& format,
        const ::aidl::android::media::audio::common::AudioChannelLayout& layout) {
    if (format == ::aidl::android::media::audio::common::AudioFormatDescription{}) {
        // Unspecified format.
        return 0;
    }
    using ::aidl::android::media::audio::common::AudioFormatType;
    if (format.type == AudioFormatType::PCM) {
        return getPcmSampleSizeInBytes(format.pcm) * getChannelCount(layout);
    } else if (format.type == AudioFormatType::NON_PCM) {
        // For non-PCM formats always use the underlying PCM size. The default value for
        // PCM is "UINT_8_BIT", thus non-encapsulated streams have the frame size of 1.
        return getPcmSampleSizeInBytes(format.pcm);
    }
    // Something unexpected.
    return 0;
}

ndk::ScopedAStatus ViPER4AndroidAIDL::open(const Parameter::Common &common,
                                           const std::optional<Parameter::Specific> &specific,
                                           IEffect::OpenEffectReturn *ret) {
    if (common.input.base.format.pcm != PcmType::FLOAT_32_BIT) {
        ALOGE("open called with invalid PCM type");
        return ndk::ScopedAStatus::fromExceptionCode(EX_ILLEGAL_ARGUMENT);
    }

    std::lock_guard lg(mMutex);

    if (mState != State::INIT) {
        ALOGD("open: already opened");
        return ndk::ScopedAStatus::ok();
    }

    size_t mInputFrameSize = getFrameSizeInBytes(
            common.input.base.format, common.input.base.channelMask);
    size_t mOutputFrameSize = getFrameSizeInBytes(
            common.output.base.format, common.output.base.channelMask);

    size_t inBufferSizeInFloat = common.input.frameCount * mInputFrameSize / sizeof(float);
    size_t outBufferSizeInFloat = common.output.frameCount * mOutputFrameSize / sizeof(float);

    // only status FMQ use the EventFlag
    mStatusMQ = std::make_shared<StatusMQ>(1, true /*configureEventFlagWord*/);
    mInputMQ = std::make_shared<DataMQ>(inBufferSizeInFloat);
    mOutputMQ = std::make_shared<DataMQ>(outBufferSizeInFloat);

    if (!mStatusMQ->isValid() || !mInputMQ->isValid() || !mOutputMQ->isValid()) {
        ALOGE("open: failed to create message queues");
        return ndk::ScopedAStatus::fromExceptionCode(EX_ILLEGAL_STATE);
    }

    android::status_t status = EventFlag::createEventFlag(
            mStatusMQ->getEventFlagWord(), &mEventFlag);
    if (status != android::OK || mEventFlag == nullptr) {
        ALOGE("open: failed to create event flag");
        return ndk::ScopedAStatus::fromExceptionCode(EX_ILLEGAL_STATE);
    }

    mWorkBuffer.resize(std::max(inBufferSizeInFloat, outBufferSizeInFloat));

    if (specific.has_value()) {
        ALOGD("open: specific parameters provided, ignoring for now...");
    }

    mState = State::IDLE;

    ret->statusMQ = mStatusMQ->dupeDesc();
    ret->inputDataMQ = mInputMQ->dupeDesc();
    ret->outputDataMQ = mOutputMQ->dupeDesc();

    mThread = std::thread(&ViPER4AndroidAIDL::threadLoop, this);

    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus ViPER4AndroidAIDL::close() {
    ALOGD("close called");
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus
ViPER4AndroidAIDL::getDescriptor(Descriptor *descriptor) {
    if (descriptor == nullptr) {
        ALOGE("getDescriptor called with null descriptor");
        return ndk::ScopedAStatus::fromExceptionCode(EX_ILLEGAL_ARGUMENT);
    }
    ALOGD("getDescriptor: returning descriptor");
    *descriptor = kDescriptor;
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus ViPER4AndroidAIDL::command(CommandId command_id) {
    ALOGD("command called");
    return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
}

ndk::ScopedAStatus ViPER4AndroidAIDL::getState(State *state) {
    ALOGD("getState called");
    return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
}

ndk::ScopedAStatus
ViPER4AndroidAIDL::setParameter(const Parameter &parameter) {
    ALOGD("setParameter called");
    return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
}

ndk::ScopedAStatus
ViPER4AndroidAIDL::getParameter(const Parameter::Id &parameter_id, Parameter *parameter) {
    ALOGD("getParameter called");
    return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
}

ndk::ScopedAStatus
ViPER4AndroidAIDL::reopen(IEffect::OpenEffectReturn *open_effect_return) {
    ALOGD("reopen called");
    return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
}

void ViPER4AndroidAIDL::threadLoop() {
    ALOGD("threadLoop started");
    while (true) {
        {
            std::unique_lock l(mThreadMutex);
            ::android::base::ScopedLockAssertion lock_assertion(mThreadMutex);
            mThreadCv.wait(l, [&]() REQUIRES(mThreadMutex) { return mThreadExit || !mThreadStop; });
            if (mThreadExit) {
                ALOGD("threadLoop exiting");
                return;
            }
        }
        process();
    }
}

void ViPER4AndroidAIDL::process() {
/**
     * wait for the EventFlag without lock, it's ok because the mEventFlag pointer will not change
     * in the life cycle of workerThread (threadLoop).
     */
    uint32_t efState = 0;
    if (!mEventFlag ||
        mEventFlag->wait(kEventFlagDataMqNotEmpty, &efState, 0 /* no timeout */, true /* retry */) != android::OK ||
        !(efState & kEventFlagDataMqNotEmpty)) {
        ALOGE("process: failed to wait for event flag");
        return;
    }

    {
        std::lock_guard lg(mMutex);
        if (mState != State::PROCESSING && mState != State::DRAINING) {
            ALOGD("process: skip process in state: %d", mState);
            return;
        }

        auto buffer = mWorkBuffer.data();
        auto processSamples = std::min(mInputMQ->availableToRead(), mOutputMQ->availableToWrite());
        if (processSamples) {
            mInputMQ->read(buffer, processSamples);
//            IEffect::Status status = effectProcessImpl(buffer, buffer, processSamples);
            ALOGD("process: processing %zu samples", processSamples);
            IEffect::Status status = {STATUS_OK, static_cast<int32_t>(processSamples), static_cast<int32_t>(processSamples)};
            mOutputMQ->write(buffer, status.fmqProduced);
            mStatusMQ->writeBlocking(&status, 1);
        }
    }
}

extern "C" binder_exception_t createEffect(const AudioUuid *audio_uuid, std::shared_ptr<IEffect> *instance) {
    if (audio_uuid == nullptr || instance == nullptr) {
        ALOGE("createEffect called with null arguments");
        return EX_ILLEGAL_ARGUMENT;
    }
    ALOGD("createEffect: creating effect instance");
    *instance = ndk::SharedRefBase::make<ViPER4AndroidAIDL>();
    return EX_NONE;
}

extern "C" binder_exception_t destroyEffect(const std::shared_ptr<IEffect> &instance) {
    ALOGD("destroyEffect called");
    return EX_ILLEGAL_STATE;
}

extern "C" binder_exception_t queryEffect(const AudioUuid *audio_uuid, Descriptor *descriptor) {
    if (audio_uuid == nullptr || descriptor == nullptr) {
        ALOGE("queryEffect called with null arguments");
        return EX_ILLEGAL_ARGUMENT;
    }
    if (*audio_uuid != kUuid) {
        ALOGE("queryEffect called with invalid uuid");
        return EX_ILLEGAL_ARGUMENT;
    }
    ALOGD("queryEffect: returning descriptor");
    *descriptor = kDescriptor;
    return EX_NONE;
}