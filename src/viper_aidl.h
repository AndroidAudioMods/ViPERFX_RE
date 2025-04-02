#pragma once

#include <mutex>
#include <thread>
#include <aidl/android/hardware/audio/effect/BnEffect.h>
#include <aidl/android/hardware/audio/effect/State.h>
#include <fmq/AidlMessageQueue.h>

using aidl::android::hardware::audio::effect::BnEffect;
using aidl::android::hardware::audio::effect::State;

class ViPER4AndroidAIDL : public BnEffect {
public:
    ::ndk::ScopedAStatus open(const ::aidl::android::hardware::audio::effect::Parameter::Common &common, const std::optional< ::aidl::android::hardware::audio::effect::Parameter::Specific> &specific, ::aidl::android::hardware::audio::effect::IEffect::OpenEffectReturn *ret) override;
    ::ndk::ScopedAStatus close() override;
    ::ndk::ScopedAStatus getDescriptor(::aidl::android::hardware::audio::effect::Descriptor *_aidl_return) override;
    ::ndk::ScopedAStatus command(::aidl::android::hardware::audio::effect::CommandId in_commandId) override;
    ::ndk::ScopedAStatus getState(::aidl::android::hardware::audio::effect::State *_aidl_return) override;
    ::ndk::ScopedAStatus setParameter(const ::aidl::android::hardware::audio::effect::Parameter &in_param) override;
    ::ndk::ScopedAStatus getParameter(const ::aidl::android::hardware::audio::effect::Parameter::Id &in_paramId, ::aidl::android::hardware::audio::effect::Parameter *_aidl_return) override;
    ::ndk::ScopedAStatus reopen(::aidl::android::hardware::audio::effect::IEffect::OpenEffectReturn *_aidl_return) override;
private:
    typedef ::android::AidlMessageQueue<
            IEffect::Status, ::aidl::android::hardware::common::fmq::SynchronizedReadWrite>
            StatusMQ;
    typedef ::android::AidlMessageQueue<
            float, ::aidl::android::hardware::common::fmq::SynchronizedReadWrite>
            DataMQ;

    void threadLoop();
    void process();

    std::mutex mMutex;
    State mState = State::INIT;

    std::shared_ptr<StatusMQ> mStatusMQ;
    std::shared_ptr<DataMQ> mInputMQ;
    std::shared_ptr<DataMQ> mOutputMQ;
    android::hardware::EventFlag *mEventFlag;
    std::vector<float> mWorkBuffer;

    std::thread mThread;
    std::mutex mThreadMutex;
    std::condition_variable mThreadCv;
    bool mThreadStop = true;
    bool mThreadExit = false;
};