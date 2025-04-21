/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioDeviceAddress.aidl
 */
#include "aidl/android/media/audio/common/AudioDeviceAddress.h"

#include <android/binder_parcel_utils.h>

namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
const char* AudioDeviceAddress::descriptor = "android.media.audio.common.AudioDeviceAddress";

binder_status_t AudioDeviceAddress::readFromParcel(const AParcel* _parcel) {
  binder_status_t _aidl_ret_status;
  int32_t _aidl_tag;
  if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_tag)) != STATUS_OK) return _aidl_ret_status;
  switch (static_cast<Tag>(_aidl_tag)) {
  case id: {
    std::string _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<std::string>) {
      set<id>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<id>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case mac: {
    std::vector<uint8_t> _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<std::vector<uint8_t>>) {
      set<mac>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<mac>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case ipv4: {
    std::vector<uint8_t> _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<std::vector<uint8_t>>) {
      set<ipv4>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<ipv4>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case ipv6: {
    std::vector<int32_t> _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<std::vector<int32_t>>) {
      set<ipv6>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<ipv6>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case alsa: {
    std::vector<int32_t> _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<std::vector<int32_t>>) {
      set<alsa>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<alsa>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  }
  return STATUS_BAD_VALUE;
}
binder_status_t AudioDeviceAddress::writeToParcel(AParcel* _parcel) const {
  binder_status_t _aidl_ret_status = ::ndk::AParcel_writeData(_parcel, static_cast<int32_t>(getTag()));
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;
  switch (getTag()) {
  case id: return ::ndk::AParcel_writeData(_parcel, get<id>());
  case mac: return ::ndk::AParcel_writeData(_parcel, get<mac>());
  case ipv4: return ::ndk::AParcel_writeData(_parcel, get<ipv4>());
  case ipv6: return ::ndk::AParcel_writeData(_parcel, get<ipv6>());
  case alsa: return ::ndk::AParcel_writeData(_parcel, get<alsa>());
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
