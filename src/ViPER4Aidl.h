#pragma once

#include <effect-impl/EffectThread.h>
#include "ViPERContext.h"

using aidl::android::hardware::common::fmq::SynchronizedReadWrite;
#if VIPER_AIDL_VERSION >= 2
using aidl::android::hardware::audio::effect::kEventFlagDataMqNotEmpty;
#else
using aidl::android::hardware::audio::effect::kEventFlagNotEmpty;
#endif

using aidl::android::hardware::audio::effect::BnEffect;
using aidl::android::hardware::audio::effect::CommandId;
using aidl::android::hardware::audio::effect::Descriptor;
using aidl::android::hardware::audio::effect::EffectThread;
using aidl::android::hardware::audio::effect::Parameter;
using aidl::android::hardware::audio::effect::RetCode;
using aidl::android::hardware::audio::effect::State;
using android::hardware::EventFlag;

class ViPER4AIDL : public BnEffect, public EffectThread {
public:
    // BnEffect
    ndk::ScopedAStatus open(const Parameter::Common &common,
                            const std::optional<Parameter::Specific> &specific,
                            IEffect::OpenEffectReturn *oer) override;
    ndk::ScopedAStatus close() override;
    ndk::ScopedAStatus getDescriptor(Descriptor *descriptor) override;
    ndk::ScopedAStatus command(CommandId command_id) override;
    ndk::ScopedAStatus getState(State *state) override;
    ndk::ScopedAStatus setParameter(const Parameter &parameter) override;
    ndk::ScopedAStatus getParameter(const Parameter::Id &parameter_id, Parameter *parameter) override;
#if VIPER_AIDL_VERSION >= 2
    ndk::ScopedAStatus reopen(IEffect::OpenEffectReturn *oer) override;
#endif

    // EffectThread
    void process() override;
private:
    typedef android::AidlMessageQueue<IEffect::Status, SynchronizedReadWrite> StatusMQ;
    typedef android::AidlMessageQueue<float, SynchronizedReadWrite> DataMQ;

    void dupeFmq(IEffect::OpenEffectReturn* oer);
    void dupeFmqWithReopen(IEffect::OpenEffectReturn* oer);
    RetCode notifyEventFlag(uint32_t flag);
    void resetBuffer();
    IEffect::Status effectProcessImpl(float *in, float *out, int32_t samples);

    std::mutex mImplMutex;
    State mState = State::INIT;

#if VIPER_AIDL_VERSION >= 2
    static const int mDataMqNotEmptyEf = kEventFlagDataMqNotEmpty;
#else
    static const int mDataMqNotEmptyEf = kEventFlagNotEmpty;
#endif

    Parameter::Common mCommon;
    std::shared_ptr<StatusMQ> mStatusMQ;
    std::shared_ptr<DataMQ> mInputMQ;
    std::shared_ptr<DataMQ> mOutputMQ;
    EventFlag *mEventFlag;
    std::vector<float> mWorkBuffer;
    ViPERContext viperContext;
};
