/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioOffloadInfo.aidl
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
#include <aidl/android/media/audio/common/AudioConfigBase.h>
#include <aidl/android/media/audio/common/AudioEncapsulationMode.h>
#include <aidl/android/media/audio/common/AudioStreamType.h>
#include <aidl/android/media/audio/common/AudioUsage.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::media::audio::common {
class AudioConfigBase;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class AudioOffloadInfo {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  ::aidl::android::media::audio::common::AudioConfigBase base;
  ::aidl::android::media::audio::common::AudioStreamType streamType = ::aidl::android::media::audio::common::AudioStreamType::INVALID;
  int32_t bitRatePerSecond = 0;
  int64_t durationUs = 0L;
  bool hasVideo = false;
  bool isStreaming = false;
  int32_t bitWidth = 16;
  int32_t offloadBufferSize = 0;
  ::aidl::android::media::audio::common::AudioUsage usage = ::aidl::android::media::audio::common::AudioUsage::INVALID;
  ::aidl::android::media::audio::common::AudioEncapsulationMode encapsulationMode = ::aidl::android::media::audio::common::AudioEncapsulationMode::INVALID;
  int32_t contentId = 0;
  int32_t syncId = 0;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const AudioOffloadInfo& _rhs) const {
    return std::tie(base, streamType, bitRatePerSecond, durationUs, hasVideo, isStreaming, bitWidth, offloadBufferSize, usage, encapsulationMode, contentId, syncId) == std::tie(_rhs.base, _rhs.streamType, _rhs.bitRatePerSecond, _rhs.durationUs, _rhs.hasVideo, _rhs.isStreaming, _rhs.bitWidth, _rhs.offloadBufferSize, _rhs.usage, _rhs.encapsulationMode, _rhs.contentId, _rhs.syncId);
  }
  inline bool operator<(const AudioOffloadInfo& _rhs) const {
    return std::tie(base, streamType, bitRatePerSecond, durationUs, hasVideo, isStreaming, bitWidth, offloadBufferSize, usage, encapsulationMode, contentId, syncId) < std::tie(_rhs.base, _rhs.streamType, _rhs.bitRatePerSecond, _rhs.durationUs, _rhs.hasVideo, _rhs.isStreaming, _rhs.bitWidth, _rhs.offloadBufferSize, _rhs.usage, _rhs.encapsulationMode, _rhs.contentId, _rhs.syncId);
  }
  inline bool operator!=(const AudioOffloadInfo& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AudioOffloadInfo& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AudioOffloadInfo& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AudioOffloadInfo& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "AudioOffloadInfo{";
    _aidl_os << "base: " << ::android::internal::ToString(base);
    _aidl_os << ", streamType: " << ::android::internal::ToString(streamType);
    _aidl_os << ", bitRatePerSecond: " << ::android::internal::ToString(bitRatePerSecond);
    _aidl_os << ", durationUs: " << ::android::internal::ToString(durationUs);
    _aidl_os << ", hasVideo: " << ::android::internal::ToString(hasVideo);
    _aidl_os << ", isStreaming: " << ::android::internal::ToString(isStreaming);
    _aidl_os << ", bitWidth: " << ::android::internal::ToString(bitWidth);
    _aidl_os << ", offloadBufferSize: " << ::android::internal::ToString(offloadBufferSize);
    _aidl_os << ", usage: " << ::android::internal::ToString(usage);
    _aidl_os << ", encapsulationMode: " << ::android::internal::ToString(encapsulationMode);
    _aidl_os << ", contentId: " << ::android::internal::ToString(contentId);
    _aidl_os << ", syncId: " << ::android::internal::ToString(syncId);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
