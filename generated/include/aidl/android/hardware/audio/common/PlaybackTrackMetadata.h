/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/android/hardware/audio/common/PlaybackTrackMetadata.aidl
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
#include <aidl/android/media/audio/common/AudioContentType.h>
#include <aidl/android/media/audio/common/AudioDevice.h>
#include <aidl/android/media/audio/common/AudioUsage.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::media::audio::common {
class AudioDevice;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace common {
class PlaybackTrackMetadata {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  ::aidl::android::media::audio::common::AudioUsage usage = ::aidl::android::media::audio::common::AudioUsage::INVALID;
  ::aidl::android::media::audio::common::AudioContentType contentType = ::aidl::android::media::audio::common::AudioContentType::UNKNOWN;
  float gain = 0.000000f;
  ::aidl::android::media::audio::common::AudioChannelLayout channelMask;
  std::optional<::aidl::android::media::audio::common::AudioDevice> sourceDevice;
  std::vector<std::string> tags;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const PlaybackTrackMetadata& _rhs) const {
    return std::tie(usage, contentType, gain, channelMask, sourceDevice, tags) == std::tie(_rhs.usage, _rhs.contentType, _rhs.gain, _rhs.channelMask, _rhs.sourceDevice, _rhs.tags);
  }
  inline bool operator<(const PlaybackTrackMetadata& _rhs) const {
    return std::tie(usage, contentType, gain, channelMask, sourceDevice, tags) < std::tie(_rhs.usage, _rhs.contentType, _rhs.gain, _rhs.channelMask, _rhs.sourceDevice, _rhs.tags);
  }
  inline bool operator!=(const PlaybackTrackMetadata& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const PlaybackTrackMetadata& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const PlaybackTrackMetadata& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const PlaybackTrackMetadata& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "PlaybackTrackMetadata{";
    _aidl_os << "usage: " << ::android::internal::ToString(usage);
    _aidl_os << ", contentType: " << ::android::internal::ToString(contentType);
    _aidl_os << ", gain: " << ::android::internal::ToString(gain);
    _aidl_os << ", channelMask: " << ::android::internal::ToString(channelMask);
    _aidl_os << ", sourceDevice: " << ::android::internal::ToString(sourceDevice);
    _aidl_os << ", tags: " << ::android::internal::ToString(tags);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace common
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
