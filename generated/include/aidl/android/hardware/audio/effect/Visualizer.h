/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Visualizer.aidl
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
#include <aidl/android/hardware/audio/effect/VendorExtension.h>
#include <aidl/android/hardware/audio/effect/Visualizer.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

#ifndef __BIONIC__
#define __assert2(a,b,c,d) ((void)0)
#endif

namespace aidl::android::hardware::audio::effect {
class VendorExtension;
}  // namespace aidl::android::hardware::audio::effect
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
class Visualizer {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class Tag : int32_t {
    id = 0,
    vendor = 1,
    measurement = 2,
    captureSampleBuffer = 3,
    latencyMs = 4,
    captureSamples = 5,
    scalingMode = 6,
    measurementMode = 7,
  };

  class Id {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    enum class Tag : int32_t {
      vendorExtensionTag = 0,
      commonTag = 1,
    };

    // Expose tag symbols for legacy code
    static const inline Tag vendorExtensionTag = Tag::vendorExtensionTag;
    static const inline Tag commonTag = Tag::commonTag;

    template<typename _Tp>
    static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, Id>;

    Id() : _value(std::in_place_index<static_cast<size_t>(vendorExtensionTag)>, ::aidl::android::hardware::audio::effect::VendorExtension()) { }

    template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
    // NOLINTNEXTLINE(google-explicit-constructor)
    constexpr Id(_Tp&& _arg)
        : _value(std::forward<_Tp>(_arg)) {}

    template <size_t _Np, typename... _Tp>
    constexpr explicit Id(std::in_place_index_t<_Np>, _Tp&&... _args)
        : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

    template <Tag _tag, typename... _Tp>
    static Id make(_Tp&&... _args) {
      return Id(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
    }

    template <Tag _tag, typename _Tp, typename... _Up>
    static Id make(std::initializer_list<_Tp> _il, _Up&&... _args) {
      return Id(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

    inline bool operator==(const Id& _rhs) const {
      return _value == _rhs._value;
    }
    inline bool operator<(const Id& _rhs) const {
      return _value < _rhs._value;
    }
    inline bool operator!=(const Id& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const Id& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const Id& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const Id& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream os;
      os << "Id{";
      switch (getTag()) {
      case vendorExtensionTag: os << "vendorExtensionTag: " << ::android::internal::ToString(get<vendorExtensionTag>()); break;
      case commonTag: os << "commonTag: " << ::android::internal::ToString(get<commonTag>()); break;
      }
      os << "}";
      return os.str();
    }
  private:
    std::variant<::aidl::android::hardware::audio::effect::VendorExtension, ::aidl::android::hardware::audio::effect::Visualizer::Tag> _value;
  };
  enum class ScalingMode : int8_t {
    NORMALIZED = 0,
    AS_PLAYED = 1,
  };

  enum class MeasurementMode : int8_t {
    NONE = 0,
    PEAK_RMS = 1,
  };

  class Measurement {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t rms = 0;
    int32_t peak = 0;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const Measurement& _rhs) const {
      return std::tie(rms, peak) == std::tie(_rhs.rms, _rhs.peak);
    }
    inline bool operator<(const Measurement& _rhs) const {
      return std::tie(rms, peak) < std::tie(_rhs.rms, _rhs.peak);
    }
    inline bool operator!=(const Measurement& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const Measurement& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const Measurement& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const Measurement& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "Measurement{";
      _aidl_os << "rms: " << ::android::internal::ToString(rms);
      _aidl_os << ", peak: " << ::android::internal::ToString(peak);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  // Expose tag symbols for legacy code
  static const inline Tag id = Tag::id;
  static const inline Tag vendor = Tag::vendor;
  static const inline Tag measurement = Tag::measurement;
  static const inline Tag captureSampleBuffer = Tag::captureSampleBuffer;
  static const inline Tag latencyMs = Tag::latencyMs;
  static const inline Tag captureSamples = Tag::captureSamples;
  static const inline Tag scalingMode = Tag::scalingMode;
  static const inline Tag measurementMode = Tag::measurementMode;

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, Visualizer>;

  Visualizer() : _value(std::in_place_index<static_cast<size_t>(id)>, ::aidl::android::hardware::audio::effect::Visualizer::Id()) { }

  template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr Visualizer(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit Visualizer(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static Visualizer make(_Tp&&... _args) {
    return Visualizer(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static Visualizer make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return Visualizer(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

  inline bool operator==(const Visualizer& _rhs) const {
    return _value == _rhs._value;
  }
  inline bool operator<(const Visualizer& _rhs) const {
    return _value < _rhs._value;
  }
  inline bool operator!=(const Visualizer& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const Visualizer& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const Visualizer& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const Visualizer& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "Visualizer{";
    switch (getTag()) {
    case id: os << "id: " << ::android::internal::ToString(get<id>()); break;
    case vendor: os << "vendor: " << ::android::internal::ToString(get<vendor>()); break;
    case measurement: os << "measurement: " << ::android::internal::ToString(get<measurement>()); break;
    case captureSampleBuffer: os << "captureSampleBuffer: " << ::android::internal::ToString(get<captureSampleBuffer>()); break;
    case latencyMs: os << "latencyMs: " << ::android::internal::ToString(get<latencyMs>()); break;
    case captureSamples: os << "captureSamples: " << ::android::internal::ToString(get<captureSamples>()); break;
    case scalingMode: os << "scalingMode: " << ::android::internal::ToString(get<scalingMode>()); break;
    case measurementMode: os << "measurementMode: " << ::android::internal::ToString(get<measurementMode>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<::aidl::android::hardware::audio::effect::Visualizer::Id, ::aidl::android::hardware::audio::effect::VendorExtension, ::aidl::android::hardware::audio::effect::Visualizer::Measurement, std::vector<uint8_t>, int32_t, int32_t, ::aidl::android::hardware::audio::effect::Visualizer::ScalingMode, ::aidl::android::hardware::audio::effect::Visualizer::MeasurementMode> _value;
};
}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
[[nodiscard]] static inline std::string toString(Visualizer::Id::Tag val) {
  switch(val) {
  case Visualizer::Id::Tag::vendorExtensionTag:
    return "vendorExtensionTag";
  case Visualizer::Id::Tag::commonTag:
    return "commonTag";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::hardware::audio::effect::Visualizer::Id::Tag, 2> enum_values<aidl::android::hardware::audio::effect::Visualizer::Id::Tag> = {
  aidl::android::hardware::audio::effect::Visualizer::Id::Tag::vendorExtensionTag,
  aidl::android::hardware::audio::effect::Visualizer::Id::Tag::commonTag,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
[[nodiscard]] static inline std::string toString(Visualizer::ScalingMode val) {
  switch(val) {
  case Visualizer::ScalingMode::NORMALIZED:
    return "NORMALIZED";
  case Visualizer::ScalingMode::AS_PLAYED:
    return "AS_PLAYED";
  default:
    return std::to_string(static_cast<int8_t>(val));
  }
}
}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::hardware::audio::effect::Visualizer::ScalingMode, 2> enum_values<aidl::android::hardware::audio::effect::Visualizer::ScalingMode> = {
  aidl::android::hardware::audio::effect::Visualizer::ScalingMode::NORMALIZED,
  aidl::android::hardware::audio::effect::Visualizer::ScalingMode::AS_PLAYED,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
[[nodiscard]] static inline std::string toString(Visualizer::MeasurementMode val) {
  switch(val) {
  case Visualizer::MeasurementMode::NONE:
    return "NONE";
  case Visualizer::MeasurementMode::PEAK_RMS:
    return "PEAK_RMS";
  default:
    return std::to_string(static_cast<int8_t>(val));
  }
}
}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::hardware::audio::effect::Visualizer::MeasurementMode, 2> enum_values<aidl::android::hardware::audio::effect::Visualizer::MeasurementMode> = {
  aidl::android::hardware::audio::effect::Visualizer::MeasurementMode::NONE,
  aidl::android::hardware::audio::effect::Visualizer::MeasurementMode::PEAK_RMS,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
[[nodiscard]] static inline std::string toString(Visualizer::Tag val) {
  switch(val) {
  case Visualizer::Tag::id:
    return "id";
  case Visualizer::Tag::vendor:
    return "vendor";
  case Visualizer::Tag::measurement:
    return "measurement";
  case Visualizer::Tag::captureSampleBuffer:
    return "captureSampleBuffer";
  case Visualizer::Tag::latencyMs:
    return "latencyMs";
  case Visualizer::Tag::captureSamples:
    return "captureSamples";
  case Visualizer::Tag::scalingMode:
    return "scalingMode";
  case Visualizer::Tag::measurementMode:
    return "measurementMode";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::hardware::audio::effect::Visualizer::Tag, 8> enum_values<aidl::android::hardware::audio::effect::Visualizer::Tag> = {
  aidl::android::hardware::audio::effect::Visualizer::Tag::id,
  aidl::android::hardware::audio::effect::Visualizer::Tag::vendor,
  aidl::android::hardware::audio::effect::Visualizer::Tag::measurement,
  aidl::android::hardware::audio::effect::Visualizer::Tag::captureSampleBuffer,
  aidl::android::hardware::audio::effect::Visualizer::Tag::latencyMs,
  aidl::android::hardware::audio::effect::Visualizer::Tag::captureSamples,
  aidl::android::hardware::audio::effect::Visualizer::Tag::scalingMode,
  aidl::android::hardware::audio::effect::Visualizer::Tag::measurementMode,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
