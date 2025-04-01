/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Downmix.aidl
 */
#include "aidl/android/hardware/audio/effect/Downmix.h"

#include <android/binder_parcel_utils.h>

namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
const char* Downmix::descriptor = "android.hardware.audio.effect.Downmix";

binder_status_t Downmix::readFromParcel(const AParcel* _parcel) {
  binder_status_t _aidl_ret_status;
  int32_t _aidl_tag;
  if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_tag)) != STATUS_OK) return _aidl_ret_status;
  switch (static_cast<Tag>(_aidl_tag)) {
  case vendor: {
    ::aidl::android::hardware::audio::effect::VendorExtension _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::VendorExtension>) {
      set<vendor>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<vendor>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case type: {
    ::aidl::android::hardware::audio::effect::Downmix::Type _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Downmix::Type>) {
      set<type>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<type>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  }
  return STATUS_BAD_VALUE;
}
binder_status_t Downmix::writeToParcel(AParcel* _parcel) const {
  binder_status_t _aidl_ret_status = ::ndk::AParcel_writeData(_parcel, static_cast<int32_t>(getTag()));
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;
  switch (getTag()) {
  case vendor: return ::ndk::AParcel_writeData(_parcel, get<vendor>());
  case type: return ::ndk::AParcel_writeData(_parcel, get<type>());
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
const char* Downmix::Id::descriptor = "android.hardware.audio.effect.Downmix.Id";

binder_status_t Downmix::Id::readFromParcel(const AParcel* _parcel) {
  binder_status_t _aidl_ret_status;
  int32_t _aidl_tag;
  if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_tag)) != STATUS_OK) return _aidl_ret_status;
  switch (static_cast<Tag>(_aidl_tag)) {
  case vendorExtensionTag: {
    ::aidl::android::hardware::audio::effect::VendorExtension _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::VendorExtension>) {
      set<vendorExtensionTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<vendorExtensionTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case commonTag: {
    ::aidl::android::hardware::audio::effect::Downmix::Tag _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Downmix::Tag>) {
      set<commonTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<commonTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  }
  return STATUS_BAD_VALUE;
}
binder_status_t Downmix::Id::writeToParcel(AParcel* _parcel) const {
  binder_status_t _aidl_ret_status = ::ndk::AParcel_writeData(_parcel, static_cast<int32_t>(getTag()));
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;
  switch (getTag()) {
  case vendorExtensionTag: return ::ndk::AParcel_writeData(_parcel, get<vendorExtensionTag>());
  case commonTag: return ::ndk::AParcel_writeData(_parcel, get<commonTag>());
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
