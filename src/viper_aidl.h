#pragma once

#include "aidl/android/hardware/audio/effect/BnEffect.h"

using aidl::android::hardware::audio::effect::BnEffect;

class ViPER4AndroidAIDL : public BnEffect {
    ::ndk::ScopedAStatus open(const ::aidl::android::hardware::audio::effect::Parameter::Common &in_common, const std::optional< ::aidl::android::hardware::audio::effect::Parameter::Specific> &in_specific, ::aidl::android::hardware::audio::effect::IEffect::OpenEffectReturn *_aidl_return) override;
    ::ndk::ScopedAStatus close() override;
    ::ndk::ScopedAStatus getDescriptor(::aidl::android::hardware::audio::effect::Descriptor *_aidl_return) override;
    ::ndk::ScopedAStatus command(::aidl::android::hardware::audio::effect::CommandId in_commandId) override;
    ::ndk::ScopedAStatus getState(::aidl::android::hardware::audio::effect::State *_aidl_return) override;
    ::ndk::ScopedAStatus setParameter(const ::aidl::android::hardware::audio::effect::Parameter &in_param) override;
    ::ndk::ScopedAStatus getParameter(const ::aidl::android::hardware::audio::effect::Parameter::Id &in_paramId, ::aidl::android::hardware::audio::effect::Parameter *_aidl_return) override;
    ::ndk::ScopedAStatus reopen(::aidl::android::hardware::audio::effect::IEffect::OpenEffectReturn *_aidl_return) override;
};