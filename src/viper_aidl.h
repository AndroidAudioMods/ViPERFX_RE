#pragma once

#include <mutex>
#include <thread>
#include <aidl/android/hardware/audio/effect/BnEffect.h>
#include <aidl/android/hardware/audio/effect/State.h>
#include <fmq/AidlMessageQueue.h>
#include "aidl/EffectThread.h"

using aidl::android::hardware::common::fmq::SynchronizedReadWrite;
using aidl::android::hardware::audio::effect::BnEffect;
using aidl::android::hardware::audio::effect::CommandId;
using aidl::android::hardware::audio::effect::Descriptor;
using aidl::android::hardware::audio::effect::EffectThread;
using aidl::android::hardware::audio::effect::Parameter;
using aidl::android::hardware::audio::effect::State;

class ViPER4AndroidAIDL : public BnEffect, public EffectThread {
public:
    // BnEffect
    ndk::ScopedAStatus open(const Parameter::Common &common, const std::optional<Parameter::Specific> &specific, IEffect::OpenEffectReturn *ret) override;
    ndk::ScopedAStatus close() override;
    ndk::ScopedAStatus getDescriptor(Descriptor *_aidl_return) override;
    ndk::ScopedAStatus command(CommandId id) override;
    ndk::ScopedAStatus getState(State *_aidl_return) override;
    ndk::ScopedAStatus setParameter(const Parameter &in_param) override;
    ndk::ScopedAStatus getParameter(const Parameter::Id &in_paramId, Parameter *_aidl_return) override;
    ndk::ScopedAStatus reopen(IEffect::OpenEffectReturn *_aidl_return) override;

    // EffectThread
    void process() override;
private:
    typedef android::AidlMessageQueue<IEffect::Status, SynchronizedReadWrite> StatusMQ;
    typedef android::AidlMessageQueue<float, SynchronizedReadWrite> DataMQ;

    std::mutex mImplMutex;
    State mState = State::INIT;

    std::shared_ptr<StatusMQ> mStatusMQ;
    std::shared_ptr<DataMQ> mInputMQ;
    std::shared_ptr<DataMQ> mOutputMQ;
    android::hardware::EventFlag *mEventFlag;
    std::vector<float> mWorkBuffer;
};