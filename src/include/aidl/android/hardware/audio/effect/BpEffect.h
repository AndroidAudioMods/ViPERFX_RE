/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/IEffect.aidl
 */
#pragma once

#include "aidl/android/hardware/audio/effect/IEffect.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
class BpEffect : public ::ndk::BpCInterface<IEffect> {
public:
  explicit BpEffect(const ::ndk::SpAIBinder& binder);
  virtual ~BpEffect();

  ::ndk::ScopedAStatus open(const ::aidl::android::hardware::audio::effect::Parameter::Common& in_common, const std::optional<::aidl::android::hardware::audio::effect::Parameter::Specific>& in_specific, ::aidl::android::hardware::audio::effect::IEffect::OpenEffectReturn* _aidl_return) override;
  ::ndk::ScopedAStatus close() override;
  ::ndk::ScopedAStatus getDescriptor(::aidl::android::hardware::audio::effect::Descriptor* _aidl_return) override;
  ::ndk::ScopedAStatus command(::aidl::android::hardware::audio::effect::CommandId in_commandId) override;
  ::ndk::ScopedAStatus getState(::aidl::android::hardware::audio::effect::State* _aidl_return) override;
  ::ndk::ScopedAStatus setParameter(const ::aidl::android::hardware::audio::effect::Parameter& in_param) override;
  ::ndk::ScopedAStatus getParameter(const ::aidl::android::hardware::audio::effect::Parameter::Id& in_paramId, ::aidl::android::hardware::audio::effect::Parameter* _aidl_return) override;
  ::ndk::ScopedAStatus reopen(::aidl::android::hardware::audio::effect::IEffect::OpenEffectReturn* _aidl_return) override;
};
}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
