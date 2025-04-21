/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioPortMixExtUseCase.aidl
 */
#include "aidl/android/media/audio/common/AudioPortMixExtUseCase.h"

#include <android/binder_parcel_utils.h>

namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
const char* AudioPortMixExtUseCase::descriptor = "android.media.audio.common.AudioPortMixExtUseCase";

binder_status_t AudioPortMixExtUseCase::readFromParcel(const AParcel* _parcel) {
  binder_status_t _aidl_ret_status;
  int32_t _aidl_tag;
  if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_tag)) != STATUS_OK) return _aidl_ret_status;
  switch (static_cast<Tag>(_aidl_tag)) {
  case unspecified: {
    bool _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<bool>) {
      set<unspecified>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<unspecified>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case stream: {
    ::aidl::android::media::audio::common::AudioStreamType _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::media::audio::common::AudioStreamType>) {
      set<stream>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<stream>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case source: {
    ::aidl::android::media::audio::common::AudioSource _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::media::audio::common::AudioSource>) {
      set<source>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<source>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  }
  return STATUS_BAD_VALUE;
}
binder_status_t AudioPortMixExtUseCase::writeToParcel(AParcel* _parcel) const {
  binder_status_t _aidl_ret_status = ::ndk::AParcel_writeData(_parcel, static_cast<int32_t>(getTag()));
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;
  switch (getTag()) {
  case unspecified: return ::ndk::AParcel_writeData(_parcel, get<unspecified>());
  case stream: return ::ndk::AParcel_writeData(_parcel, get<stream>());
  case source: return ::ndk::AParcel_writeData(_parcel, get<source>());
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
