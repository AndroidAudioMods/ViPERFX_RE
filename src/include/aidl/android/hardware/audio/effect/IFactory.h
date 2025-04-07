/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/IFactory.aidl
 */
#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#include <aidl/android/hardware/audio/effect/Descriptor.h>
#include <aidl/android/hardware/audio/effect/IEffect.h>
#include <aidl/android/hardware/audio/effect/Processing.h>
#include <aidl/android/media/audio/common/v1/AudioUuid.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::hardware::audio::effect {
class Descriptor;
class IEffect;
class Processing;
}  // namespace aidl::android::hardware::audio::effect
namespace aidl::android::media::audio::common {
class AudioUuid;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
class IFactoryDelegator;

class IFactory : public ::ndk::ICInterface {
public:
  typedef IFactoryDelegator DefaultDelegator;
  static const char* descriptor;
  IFactory();
  virtual ~IFactory();

  static constexpr uint32_t TRANSACTION_queryEffects = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_queryProcessing = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_createEffect = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_destroyEffect = FIRST_CALL_TRANSACTION + 3;

  static std::shared_ptr<IFactory> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IFactory>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IFactory>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IFactory>& impl);
  static const std::shared_ptr<IFactory>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus queryEffects(const std::optional<::aidl::android::media::audio::common::v1::AudioUuid>& in_type, const std::optional<::aidl::android::media::audio::common::v1::AudioUuid>& in_implementation, const std::optional<::aidl::android::media::audio::common::v1::AudioUuid>& in_proxy, std::vector<::aidl::android::hardware::audio::effect::Descriptor>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus queryProcessing(const std::optional<::aidl::android::hardware::audio::effect::Processing::Type>& in_type, std::vector<::aidl::android::hardware::audio::effect::Processing>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus createEffect(const ::aidl::android::media::audio::common::v1::AudioUuid& in_implUuid, std::shared_ptr<::aidl::android::hardware::audio::effect::IEffect>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus destroyEffect(const std::shared_ptr<::aidl::android::hardware::audio::effect::IEffect>& in_handle) = 0;
private:
  static std::shared_ptr<IFactory> default_impl;
};
class IFactoryDefault : public IFactory {
public:
  ::ndk::ScopedAStatus queryEffects(const std::optional<::aidl::android::media::audio::common::v1::AudioUuid>& in_type, const std::optional<::aidl::android::media::audio::common::v1::AudioUuid>& in_implementation, const std::optional<::aidl::android::media::audio::common::v1::AudioUuid>& in_proxy, std::vector<::aidl::android::hardware::audio::effect::Descriptor>* _aidl_return) override;
  ::ndk::ScopedAStatus queryProcessing(const std::optional<::aidl::android::hardware::audio::effect::Processing::Type>& in_type, std::vector<::aidl::android::hardware::audio::effect::Processing>* _aidl_return) override;
  ::ndk::ScopedAStatus createEffect(const ::aidl::android::media::audio::common::v1::AudioUuid& in_implUuid, std::shared_ptr<::aidl::android::hardware::audio::effect::IEffect>* _aidl_return) override;
  ::ndk::ScopedAStatus destroyEffect(const std::shared_ptr<::aidl::android::hardware::audio::effect::IEffect>& in_handle) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
