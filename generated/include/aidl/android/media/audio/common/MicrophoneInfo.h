/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/MicrophoneInfo.aidl
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
#include <aidl/android/media/audio/common/AudioDevice.h>
#include <aidl/android/media/audio/common/MicrophoneInfo.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::media::audio::common {
class AudioDevice;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class MicrophoneInfo {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class Location : int32_t {
    UNKNOWN = 0,
    MAINBODY = 1,
    MAINBODY_MOVABLE = 2,
    PERIPHERAL = 3,
  };

  class Sensitivity {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    float leveldBFS = 0.000000f;
    float maxSpldB = 0.000000f;
    float minSpldB = 0.000000f;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const Sensitivity& _rhs) const {
      return std::tie(leveldBFS, maxSpldB, minSpldB) == std::tie(_rhs.leveldBFS, _rhs.maxSpldB, _rhs.minSpldB);
    }
    inline bool operator<(const Sensitivity& _rhs) const {
      return std::tie(leveldBFS, maxSpldB, minSpldB) < std::tie(_rhs.leveldBFS, _rhs.maxSpldB, _rhs.minSpldB);
    }
    inline bool operator!=(const Sensitivity& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const Sensitivity& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const Sensitivity& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const Sensitivity& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "Sensitivity{";
      _aidl_os << "leveldBFS: " << ::android::internal::ToString(leveldBFS);
      _aidl_os << ", maxSpldB: " << ::android::internal::ToString(maxSpldB);
      _aidl_os << ", minSpldB: " << ::android::internal::ToString(minSpldB);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  enum class Directionality : int32_t {
    UNKNOWN = 0,
    OMNI = 1,
    BI_DIRECTIONAL = 2,
    CARDIOID = 3,
    HYPER_CARDIOID = 4,
    SUPER_CARDIOID = 5,
  };

  class FrequencyResponsePoint {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    float frequencyHz = 0.000000f;
    float leveldB = 0.000000f;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const FrequencyResponsePoint& _rhs) const {
      return std::tie(frequencyHz, leveldB) == std::tie(_rhs.frequencyHz, _rhs.leveldB);
    }
    inline bool operator<(const FrequencyResponsePoint& _rhs) const {
      return std::tie(frequencyHz, leveldB) < std::tie(_rhs.frequencyHz, _rhs.leveldB);
    }
    inline bool operator!=(const FrequencyResponsePoint& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const FrequencyResponsePoint& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const FrequencyResponsePoint& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const FrequencyResponsePoint& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "FrequencyResponsePoint{";
      _aidl_os << "frequencyHz: " << ::android::internal::ToString(frequencyHz);
      _aidl_os << ", leveldB: " << ::android::internal::ToString(leveldB);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class Coordinate {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    float x = 0.000000f;
    float y = 0.000000f;
    float z = 0.000000f;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const Coordinate& _rhs) const {
      return std::tie(x, y, z) == std::tie(_rhs.x, _rhs.y, _rhs.z);
    }
    inline bool operator<(const Coordinate& _rhs) const {
      return std::tie(x, y, z) < std::tie(_rhs.x, _rhs.y, _rhs.z);
    }
    inline bool operator!=(const Coordinate& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const Coordinate& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const Coordinate& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const Coordinate& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "Coordinate{";
      _aidl_os << "x: " << ::android::internal::ToString(x);
      _aidl_os << ", y: " << ::android::internal::ToString(y);
      _aidl_os << ", z: " << ::android::internal::ToString(z);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  std::string id;
  ::aidl::android::media::audio::common::AudioDevice device;
  ::aidl::android::media::audio::common::MicrophoneInfo::Location location = ::aidl::android::media::audio::common::MicrophoneInfo::Location::UNKNOWN;
  int32_t group = -1;
  int32_t indexInTheGroup = -1;
  std::optional<::aidl::android::media::audio::common::MicrophoneInfo::Sensitivity> sensitivity;
  ::aidl::android::media::audio::common::MicrophoneInfo::Directionality directionality = ::aidl::android::media::audio::common::MicrophoneInfo::Directionality::UNKNOWN;
  std::vector<::aidl::android::media::audio::common::MicrophoneInfo::FrequencyResponsePoint> frequencyResponse;
  std::optional<::aidl::android::media::audio::common::MicrophoneInfo::Coordinate> position;
  std::optional<::aidl::android::media::audio::common::MicrophoneInfo::Coordinate> orientation;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const MicrophoneInfo& _rhs) const {
    return std::tie(id, device, location, group, indexInTheGroup, sensitivity, directionality, frequencyResponse, position, orientation) == std::tie(_rhs.id, _rhs.device, _rhs.location, _rhs.group, _rhs.indexInTheGroup, _rhs.sensitivity, _rhs.directionality, _rhs.frequencyResponse, _rhs.position, _rhs.orientation);
  }
  inline bool operator<(const MicrophoneInfo& _rhs) const {
    return std::tie(id, device, location, group, indexInTheGroup, sensitivity, directionality, frequencyResponse, position, orientation) < std::tie(_rhs.id, _rhs.device, _rhs.location, _rhs.group, _rhs.indexInTheGroup, _rhs.sensitivity, _rhs.directionality, _rhs.frequencyResponse, _rhs.position, _rhs.orientation);
  }
  inline bool operator!=(const MicrophoneInfo& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const MicrophoneInfo& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const MicrophoneInfo& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const MicrophoneInfo& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  enum : int32_t { GROUP_UNKNOWN = -1 };
  enum : int32_t { INDEX_IN_THE_GROUP_UNKNOWN = -1 };
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "MicrophoneInfo{";
    _aidl_os << "id: " << ::android::internal::ToString(id);
    _aidl_os << ", device: " << ::android::internal::ToString(device);
    _aidl_os << ", location: " << ::android::internal::ToString(location);
    _aidl_os << ", group: " << ::android::internal::ToString(group);
    _aidl_os << ", indexInTheGroup: " << ::android::internal::ToString(indexInTheGroup);
    _aidl_os << ", sensitivity: " << ::android::internal::ToString(sensitivity);
    _aidl_os << ", directionality: " << ::android::internal::ToString(directionality);
    _aidl_os << ", frequencyResponse: " << ::android::internal::ToString(frequencyResponse);
    _aidl_os << ", position: " << ::android::internal::ToString(position);
    _aidl_os << ", orientation: " << ::android::internal::ToString(orientation);
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
[[nodiscard]] static inline std::string toString(MicrophoneInfo::Location val) {
  switch(val) {
  case MicrophoneInfo::Location::UNKNOWN:
    return "UNKNOWN";
  case MicrophoneInfo::Location::MAINBODY:
    return "MAINBODY";
  case MicrophoneInfo::Location::MAINBODY_MOVABLE:
    return "MAINBODY_MOVABLE";
  case MicrophoneInfo::Location::PERIPHERAL:
    return "PERIPHERAL";
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
constexpr inline std::array<aidl::android::media::audio::common::MicrophoneInfo::Location, 4> enum_values<aidl::android::media::audio::common::MicrophoneInfo::Location> = {
  aidl::android::media::audio::common::MicrophoneInfo::Location::UNKNOWN,
  aidl::android::media::audio::common::MicrophoneInfo::Location::MAINBODY,
  aidl::android::media::audio::common::MicrophoneInfo::Location::MAINBODY_MOVABLE,
  aidl::android::media::audio::common::MicrophoneInfo::Location::PERIPHERAL,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
[[nodiscard]] static inline std::string toString(MicrophoneInfo::Directionality val) {
  switch(val) {
  case MicrophoneInfo::Directionality::UNKNOWN:
    return "UNKNOWN";
  case MicrophoneInfo::Directionality::OMNI:
    return "OMNI";
  case MicrophoneInfo::Directionality::BI_DIRECTIONAL:
    return "BI_DIRECTIONAL";
  case MicrophoneInfo::Directionality::CARDIOID:
    return "CARDIOID";
  case MicrophoneInfo::Directionality::HYPER_CARDIOID:
    return "HYPER_CARDIOID";
  case MicrophoneInfo::Directionality::SUPER_CARDIOID:
    return "SUPER_CARDIOID";
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
constexpr inline std::array<aidl::android::media::audio::common::MicrophoneInfo::Directionality, 6> enum_values<aidl::android::media::audio::common::MicrophoneInfo::Directionality> = {
  aidl::android::media::audio::common::MicrophoneInfo::Directionality::UNKNOWN,
  aidl::android::media::audio::common::MicrophoneInfo::Directionality::OMNI,
  aidl::android::media::audio::common::MicrophoneInfo::Directionality::BI_DIRECTIONAL,
  aidl::android::media::audio::common::MicrophoneInfo::Directionality::CARDIOID,
  aidl::android::media::audio::common::MicrophoneInfo::Directionality::HYPER_CARDIOID,
  aidl::android::media::audio::common::MicrophoneInfo::Directionality::SUPER_CARDIOID,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
