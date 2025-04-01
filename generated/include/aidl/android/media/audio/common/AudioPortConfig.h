/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioPortConfig.aidl
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
#include <aidl/android/media/audio/common/AudioFormatDescription.h>
#include <aidl/android/media/audio/common/AudioGainConfig.h>
#include <aidl/android/media/audio/common/AudioIoFlags.h>
#include <aidl/android/media/audio/common/AudioPortExt.h>
#include <aidl/android/media/audio/common/Int.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::media::audio::common {
class AudioFormatDescription;
class AudioGainConfig;
class Int;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class AudioPortConfig {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int32_t id = 0;
  int32_t portId = 0;
  std::optional<::aidl::android::media::audio::common::Int> sampleRate;
  std::optional<::aidl::android::media::audio::common::AudioChannelLayout> channelMask;
  std::optional<::aidl::android::media::audio::common::AudioFormatDescription> format;
  std::optional<::aidl::android::media::audio::common::AudioGainConfig> gain;
  std::optional<::aidl::android::media::audio::common::AudioIoFlags> flags;
  ::aidl::android::media::audio::common::AudioPortExt ext;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const AudioPortConfig& _rhs) const {
    return std::tie(id, portId, sampleRate, channelMask, format, gain, flags, ext) == std::tie(_rhs.id, _rhs.portId, _rhs.sampleRate, _rhs.channelMask, _rhs.format, _rhs.gain, _rhs.flags, _rhs.ext);
  }
  inline bool operator<(const AudioPortConfig& _rhs) const {
    return std::tie(id, portId, sampleRate, channelMask, format, gain, flags, ext) < std::tie(_rhs.id, _rhs.portId, _rhs.sampleRate, _rhs.channelMask, _rhs.format, _rhs.gain, _rhs.flags, _rhs.ext);
  }
  inline bool operator!=(const AudioPortConfig& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AudioPortConfig& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AudioPortConfig& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AudioPortConfig& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "AudioPortConfig{";
    _aidl_os << "id: " << ::android::internal::ToString(id);
    _aidl_os << ", portId: " << ::android::internal::ToString(portId);
    _aidl_os << ", sampleRate: " << ::android::internal::ToString(sampleRate);
    _aidl_os << ", channelMask: " << ::android::internal::ToString(channelMask);
    _aidl_os << ", format: " << ::android::internal::ToString(format);
    _aidl_os << ", gain: " << ::android::internal::ToString(gain);
    _aidl_os << ", flags: " << ::android::internal::ToString(flags);
    _aidl_os << ", ext: " << ::android::internal::ToString(ext);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
