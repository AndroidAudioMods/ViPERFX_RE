/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioPortDeviceExt.aidl
 */
#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#include <aidl/android/media/audio/common/AudioChannelLayout.h>
#include <aidl/android/media/audio/common/AudioDevice.h>
#include <aidl/android/media/audio/common/AudioFormatDescription.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::media::audio::common {
class AudioDevice;
class AudioFormatDescription;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class AudioPortDeviceExt {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  ::aidl::android::media::audio::common::AudioDevice device;
  int32_t flags = 0;
  std::vector<::aidl::android::media::audio::common::AudioFormatDescription> encodedFormats;
  int32_t encapsulationModes = 0;
  int32_t encapsulationMetadataTypes = 0;
  std::optional<::aidl::android::media::audio::common::AudioChannelLayout> speakerLayout;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const AudioPortDeviceExt& _rhs) const {
    return std::tie(device, flags, encodedFormats, encapsulationModes, encapsulationMetadataTypes, speakerLayout) == std::tie(_rhs.device, _rhs.flags, _rhs.encodedFormats, _rhs.encapsulationModes, _rhs.encapsulationMetadataTypes, _rhs.speakerLayout);
  }
  inline bool operator<(const AudioPortDeviceExt& _rhs) const {
    return std::tie(device, flags, encodedFormats, encapsulationModes, encapsulationMetadataTypes, speakerLayout) < std::tie(_rhs.device, _rhs.flags, _rhs.encodedFormats, _rhs.encapsulationModes, _rhs.encapsulationMetadataTypes, _rhs.speakerLayout);
  }
  inline bool operator!=(const AudioPortDeviceExt& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AudioPortDeviceExt& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AudioPortDeviceExt& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AudioPortDeviceExt& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  enum : int32_t { FLAG_INDEX_DEFAULT_DEVICE = 0 };
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "AudioPortDeviceExt{";
    _aidl_os << "device: " << ::android::internal::ToString(device);
    _aidl_os << ", flags: " << ::android::internal::ToString(flags);
    _aidl_os << ", encodedFormats: " << ::android::internal::ToString(encodedFormats);
    _aidl_os << ", encapsulationModes: " << ::android::internal::ToString(encapsulationModes);
    _aidl_os << ", encapsulationMetadataTypes: " << ::android::internal::ToString(encapsulationMetadataTypes);
    _aidl_os << ", speakerLayout: " << ::android::internal::ToString(speakerLayout);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
