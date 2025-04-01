/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioChannelLayout.aidl
 */
#include "aidl/android/media/audio/common/AudioChannelLayout.h"

#include <android/binder_parcel_utils.h>

namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
const char* AudioChannelLayout::descriptor = "android.media.audio.common.AudioChannelLayout";

binder_status_t AudioChannelLayout::readFromParcel(const AParcel* _parcel) {
  binder_status_t _aidl_ret_status;
  int32_t _aidl_tag;
  if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_tag)) != STATUS_OK) return _aidl_ret_status;
  switch (static_cast<Tag>(_aidl_tag)) {
  case none: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<none>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<none>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case invalid: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<invalid>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<invalid>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case indexMask: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<indexMask>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<indexMask>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case layoutMask: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<layoutMask>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<layoutMask>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case voiceMask: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<voiceMask>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<voiceMask>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  }
  return STATUS_BAD_VALUE;
}
binder_status_t AudioChannelLayout::writeToParcel(AParcel* _parcel) const {
  binder_status_t _aidl_ret_status = ::ndk::AParcel_writeData(_parcel, static_cast<int32_t>(getTag()));
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;
  switch (getTag()) {
  case none: return ::ndk::AParcel_writeData(_parcel, get<none>());
  case invalid: return ::ndk::AParcel_writeData(_parcel, get<invalid>());
  case indexMask: return ::ndk::AParcel_writeData(_parcel, get<indexMask>());
  case layoutMask: return ::ndk::AParcel_writeData(_parcel, get<layoutMask>());
  case voiceMask: return ::ndk::AParcel_writeData(_parcel, get<voiceMask>());
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
