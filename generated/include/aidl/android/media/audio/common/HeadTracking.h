/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/HeadTracking.aidl
 */
#pragma once

#include <array>
#include <cassert>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>
#include <android/binder_enums.h>
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

#ifndef __BIONIC__
#define __assert2(a,b,c,d) ((void)0)
#endif

namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class HeadTracking {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class Mode : int8_t {
    OTHER = 0,
    DISABLED = 1,
    RELATIVE_WORLD = 2,
    RELATIVE_SCREEN = 3,
  };

  enum class ConnectionMode : int8_t {
    FRAMEWORK_PROCESSED = 0,
    DIRECT_TO_SENSOR_SW = 1,
    DIRECT_TO_SENSOR_TUNNEL = 2,
  };

  class SensorData {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    enum class Tag : int32_t {
      headToStage = 0,
    };

    // Expose tag symbols for legacy code
    static const inline Tag headToStage = Tag::headToStage;

    template<typename _Tp>
    static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, SensorData>;

    SensorData() : _value(std::in_place_index<static_cast<size_t>(headToStage)>, std::array<float, 6>({{0.000000f, 0.000000f, 0.000000f, 0.000000f, 0.000000f, 0.000000f}})) { }

    template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
    // NOLINTNEXTLINE(google-explicit-constructor)
    constexpr SensorData(_Tp&& _arg)
        : _value(std::forward<_Tp>(_arg)) {}

    template <size_t _Np, typename... _Tp>
    constexpr explicit SensorData(std::in_place_index_t<_Np>, _Tp&&... _args)
        : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

    template <Tag _tag, typename... _Tp>
    static SensorData make(_Tp&&... _args) {
      return SensorData(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
    }

    template <Tag _tag, typename _Tp, typename... _Up>
    static SensorData make(std::initializer_list<_Tp> _il, _Up&&... _args) {
      return SensorData(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
    }

    Tag getTag() const {
      return static_cast<Tag>(_value.index());
    }

    template <Tag _tag>
    const auto& get() const {
      if (getTag() != _tag) { __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "bad access: a wrong tag"); }
      return std::get<static_cast<size_t>(_tag)>(_value);
    }

    template <Tag _tag>
    auto& get() {
      if (getTag() != _tag) { __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "bad access: a wrong tag"); }
      return std::get<static_cast<size_t>(_tag)>(_value);
    }

    template <Tag _tag, typename... _Tp>
    void set(_Tp&&... _args) {
      _value.emplace<static_cast<size_t>(_tag)>(std::forward<_Tp>(_args)...);
    }

    binder_status_t readFromParcel(const AParcel* _parcel);
    binder_status_t writeToParcel(AParcel* _parcel) const;

    inline bool operator==(const SensorData& _rhs) const {
      return _value == _rhs._value;
    }
    inline bool operator<(const SensorData& _rhs) const {
      return _value < _rhs._value;
    }
    inline bool operator!=(const SensorData& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const SensorData& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const SensorData& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const SensorData& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream os;
      os << "SensorData{";
      switch (getTag()) {
      case headToStage: os << "headToStage: " << ::android::internal::ToString(get<headToStage>()); break;
      }
      os << "}";
      return os.str();
    }
  private:
    std::variant<std::array<float, 6>> _value;
  };

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const HeadTracking&) const {
    return std::tie() == std::tie();
  }
  inline bool operator<(const HeadTracking&) const {
    return std::tie() < std::tie();
  }
  inline bool operator!=(const HeadTracking& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const HeadTracking& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const HeadTracking& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const HeadTracking& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "HeadTracking{";
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
[[nodiscard]] static inline std::string toString(HeadTracking::Mode val) {
  switch(val) {
  case HeadTracking::Mode::OTHER:
    return "OTHER";
  case HeadTracking::Mode::DISABLED:
    return "DISABLED";
  case HeadTracking::Mode::RELATIVE_WORLD:
    return "RELATIVE_WORLD";
  case HeadTracking::Mode::RELATIVE_SCREEN:
    return "RELATIVE_SCREEN";
  default:
    return std::to_string(static_cast<int8_t>(val));
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
constexpr inline std::array<aidl::android::media::audio::common::HeadTracking::Mode, 4> enum_values<aidl::android::media::audio::common::HeadTracking::Mode> = {
  aidl::android::media::audio::common::HeadTracking::Mode::OTHER,
  aidl::android::media::audio::common::HeadTracking::Mode::DISABLED,
  aidl::android::media::audio::common::HeadTracking::Mode::RELATIVE_WORLD,
  aidl::android::media::audio::common::HeadTracking::Mode::RELATIVE_SCREEN,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
[[nodiscard]] static inline std::string toString(HeadTracking::ConnectionMode val) {
  switch(val) {
  case HeadTracking::ConnectionMode::FRAMEWORK_PROCESSED:
    return "FRAMEWORK_PROCESSED";
  case HeadTracking::ConnectionMode::DIRECT_TO_SENSOR_SW:
    return "DIRECT_TO_SENSOR_SW";
  case HeadTracking::ConnectionMode::DIRECT_TO_SENSOR_TUNNEL:
    return "DIRECT_TO_SENSOR_TUNNEL";
  default:
    return std::to_string(static_cast<int8_t>(val));
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
constexpr inline std::array<aidl::android::media::audio::common::HeadTracking::ConnectionMode, 3> enum_values<aidl::android::media::audio::common::HeadTracking::ConnectionMode> = {
  aidl::android::media::audio::common::HeadTracking::ConnectionMode::FRAMEWORK_PROCESSED,
  aidl::android::media::audio::common::HeadTracking::ConnectionMode::DIRECT_TO_SENSOR_SW,
  aidl::android::media::audio::common::HeadTracking::ConnectionMode::DIRECT_TO_SENSOR_TUNNEL,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
[[nodiscard]] static inline std::string toString(HeadTracking::SensorData::Tag val) {
  switch(val) {
  case HeadTracking::SensorData::Tag::headToStage:
    return "headToStage";
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
constexpr inline std::array<aidl::android::media::audio::common::HeadTracking::SensorData::Tag, 1> enum_values<aidl::android::media::audio::common::HeadTracking::SensorData::Tag> = {
  aidl::android::media::audio::common::HeadTracking::SensorData::Tag::headToStage,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
