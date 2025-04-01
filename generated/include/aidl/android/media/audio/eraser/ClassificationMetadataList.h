/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/android/media/audio/eraser/ClassificationMetadataList.aidl
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
#include <aidl/android/media/audio/eraser/ClassificationMetadata.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::media::audio::eraser {
class ClassificationMetadata;
}  // namespace aidl::android::media::audio::eraser
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace eraser {
class ClassificationMetadataList {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int32_t timeMs = 0;
  std::vector<::aidl::android::media::audio::eraser::ClassificationMetadata> metadatas;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const ClassificationMetadataList& _rhs) const {
    return std::tie(timeMs, metadatas) == std::tie(_rhs.timeMs, _rhs.metadatas);
  }
  inline bool operator<(const ClassificationMetadataList& _rhs) const {
    return std::tie(timeMs, metadatas) < std::tie(_rhs.timeMs, _rhs.metadatas);
  }
  inline bool operator!=(const ClassificationMetadataList& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const ClassificationMetadataList& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const ClassificationMetadataList& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const ClassificationMetadataList& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "ClassificationMetadataList{";
    _aidl_os << "timeMs: " << ::android::internal::ToString(timeMs);
    _aidl_os << ", metadatas: " << ::android::internal::ToString(metadatas);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace eraser
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
