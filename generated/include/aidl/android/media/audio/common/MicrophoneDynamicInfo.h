/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/MicrophoneDynamicInfo.aidl
 */
#pragma once

#include <array>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_enums.h>
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#include <aidl/android/media/audio/common/MicrophoneDynamicInfo.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class MicrophoneDynamicInfo {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class ChannelMapping : int32_t {
    UNUSED = 0,
    DIRECT = 1,
    PROCESSED = 2,
  };

  std::string id;
  std::vector<::aidl::android::media::audio::common::MicrophoneDynamicInfo::ChannelMapping> channelMapping;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const MicrophoneDynamicInfo& _rhs) const {
    return std::tie(id, channelMapping) == std::tie(_rhs.id, _rhs.channelMapping);
  }
  inline bool operator<(const MicrophoneDynamicInfo& _rhs) const {
    return std::tie(id, channelMapping) < std::tie(_rhs.id, _rhs.channelMapping);
  }
  inline bool operator!=(const MicrophoneDynamicInfo& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const MicrophoneDynamicInfo& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const MicrophoneDynamicInfo& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const MicrophoneDynamicInfo& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "MicrophoneDynamicInfo{";
    _aidl_os << "id: " << ::android::internal::ToString(id);
    _aidl_os << ", channelMapping: " << ::android::internal::ToString(channelMapping);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
[[nodiscard]] static inline std::string toString(MicrophoneDynamicInfo::ChannelMapping val) {
  switch(val) {
  case MicrophoneDynamicInfo::ChannelMapping::UNUSED:
    return "UNUSED";
  case MicrophoneDynamicInfo::ChannelMapping::DIRECT:
    return "DIRECT";
  case MicrophoneDynamicInfo::ChannelMapping::PROCESSED:
    return "PROCESSED";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::media::audio::common::MicrophoneDynamicInfo::ChannelMapping, 3> enum_values<aidl::android::media::audio::common::MicrophoneDynamicInfo::ChannelMapping> = {
  aidl::android::media::audio::common::MicrophoneDynamicInfo::ChannelMapping::UNUSED,
  aidl::android::media::audio::common::MicrophoneDynamicInfo::ChannelMapping::DIRECT,
  aidl::android::media::audio::common::MicrophoneDynamicInfo::ChannelMapping::PROCESSED,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
