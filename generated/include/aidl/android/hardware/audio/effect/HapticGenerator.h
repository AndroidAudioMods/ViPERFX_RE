/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/HapticGenerator.aidl
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
#include <aidl/android/hardware/audio/effect/HapticGenerator.h>
#include <aidl/android/hardware/audio/effect/VendorExtension.h>
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
class HapticGenerator {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class Tag : int32_t {
    vendor = 0,
    hapticScales = 1,
    vibratorInfo = 2,
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
    std::variant<::aidl::android::hardware::audio::effect::VendorExtension, ::aidl::android::hardware::audio::effect::HapticGenerator::Tag> _value;
  };
  enum class VibratorScale : int32_t {
    MUTE = -100,
    VERY_LOW = -2,
    LOW = -1,
    NONE = 0,
    HIGH = 1,
    VERY_HIGH = 2,
  };

  class HapticScale {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t id = 0;
    ::aidl::android::hardware::audio::effect::HapticGenerator::VibratorScale scale = ::aidl::android::hardware::audio::effect::HapticGenerator::VibratorScale::MUTE;
    float scaleFactor = -1.000000f;
    float adaptiveScaleFactor = -1.000000f;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const HapticScale& _rhs) const {
      return std::tie(id, scale, scaleFactor, adaptiveScaleFactor) == std::tie(_rhs.id, _rhs.scale, _rhs.scaleFactor, _rhs.adaptiveScaleFactor);
    }
    inline bool operator<(const HapticScale& _rhs) const {
      return std::tie(id, scale, scaleFactor, adaptiveScaleFactor) < std::tie(_rhs.id, _rhs.scale, _rhs.scaleFactor, _rhs.adaptiveScaleFactor);
    }
    inline bool operator!=(const HapticScale& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const HapticScale& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const HapticScale& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const HapticScale& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    static constexpr float UNDEFINED_SCALE_FACTOR = -1.000000f;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "HapticScale{";
      _aidl_os << "id: " << ::android::internal::ToString(id);
      _aidl_os << ", scale: " << ::android::internal::ToString(scale);
      _aidl_os << ", scaleFactor: " << ::android::internal::ToString(scaleFactor);
      _aidl_os << ", adaptiveScaleFactor: " << ::android::internal::ToString(adaptiveScaleFactor);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class VibratorInformation {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    float resonantFrequencyHz = 0.000000f;
    float qFactor = 0.000000f;
    float maxAmplitude = 0.000000f;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const VibratorInformation& _rhs) const {
      return std::tie(resonantFrequencyHz, qFactor, maxAmplitude) == std::tie(_rhs.resonantFrequencyHz, _rhs.qFactor, _rhs.maxAmplitude);
    }
    inline bool operator<(const VibratorInformation& _rhs) const {
      return std::tie(resonantFrequencyHz, qFactor, maxAmplitude) < std::tie(_rhs.resonantFrequencyHz, _rhs.qFactor, _rhs.maxAmplitude);
    }
    inline bool operator!=(const VibratorInformation& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const VibratorInformation& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const VibratorInformation& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const VibratorInformation& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "VibratorInformation{";
      _aidl_os << "resonantFrequencyHz: " << ::android::internal::ToString(resonantFrequencyHz);
      _aidl_os << ", qFactor: " << ::android::internal::ToString(qFactor);
      _aidl_os << ", maxAmplitude: " << ::android::internal::ToString(maxAmplitude);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  // Expose tag symbols for legacy code
  static const inline Tag vendor = Tag::vendor;
  static const inline Tag hapticScales = Tag::hapticScales;
  static const inline Tag vibratorInfo = Tag::vibratorInfo;

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, HapticGenerator>;

  HapticGenerator() : _value(std::in_place_index<static_cast<size_t>(vendor)>, ::aidl::android::hardware::audio::effect::VendorExtension()) { }

  template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr HapticGenerator(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit HapticGenerator(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static HapticGenerator make(_Tp&&... _args) {
    return HapticGenerator(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static HapticGenerator make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return HapticGenerator(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

  inline bool operator==(const HapticGenerator& _rhs) const {
    return _value == _rhs._value;
  }
  inline bool operator<(const HapticGenerator& _rhs) const {
    return _value < _rhs._value;
  }
  inline bool operator!=(const HapticGenerator& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const HapticGenerator& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const HapticGenerator& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const HapticGenerator& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "HapticGenerator{";
    switch (getTag()) {
    case vendor: os << "vendor: " << ::android::internal::ToString(get<vendor>()); break;
    case hapticScales: os << "hapticScales: " << ::android::internal::ToString(get<hapticScales>()); break;
    case vibratorInfo: os << "vibratorInfo: " << ::android::internal::ToString(get<vibratorInfo>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<::aidl::android::hardware::audio::effect::VendorExtension, std::vector<::aidl::android::hardware::audio::effect::HapticGenerator::HapticScale>, ::aidl::android::hardware::audio::effect::HapticGenerator::VibratorInformation> _value;
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
[[nodiscard]] static inline std::string toString(HapticGenerator::Id::Tag val) {
  switch(val) {
  case HapticGenerator::Id::Tag::vendorExtensionTag:
    return "vendorExtensionTag";
  case HapticGenerator::Id::Tag::commonTag:
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
constexpr inline std::array<aidl::android::hardware::audio::effect::HapticGenerator::Id::Tag, 2> enum_values<aidl::android::hardware::audio::effect::HapticGenerator::Id::Tag> = {
  aidl::android::hardware::audio::effect::HapticGenerator::Id::Tag::vendorExtensionTag,
  aidl::android::hardware::audio::effect::HapticGenerator::Id::Tag::commonTag,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
[[nodiscard]] static inline std::string toString(HapticGenerator::VibratorScale val) {
  switch(val) {
  case HapticGenerator::VibratorScale::MUTE:
    return "MUTE";
  case HapticGenerator::VibratorScale::VERY_LOW:
    return "VERY_LOW";
  case HapticGenerator::VibratorScale::LOW:
    return "LOW";
  case HapticGenerator::VibratorScale::NONE:
    return "NONE";
  case HapticGenerator::VibratorScale::HIGH:
    return "HIGH";
  case HapticGenerator::VibratorScale::VERY_HIGH:
    return "VERY_HIGH";
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
constexpr inline std::array<aidl::android::hardware::audio::effect::HapticGenerator::VibratorScale, 6> enum_values<aidl::android::hardware::audio::effect::HapticGenerator::VibratorScale> = {
  aidl::android::hardware::audio::effect::HapticGenerator::VibratorScale::MUTE,
  aidl::android::hardware::audio::effect::HapticGenerator::VibratorScale::VERY_LOW,
  aidl::android::hardware::audio::effect::HapticGenerator::VibratorScale::LOW,
  aidl::android::hardware::audio::effect::HapticGenerator::VibratorScale::NONE,
  aidl::android::hardware::audio::effect::HapticGenerator::VibratorScale::HIGH,
  aidl::android::hardware::audio::effect::HapticGenerator::VibratorScale::VERY_HIGH,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
[[nodiscard]] static inline std::string toString(HapticGenerator::Tag val) {
  switch(val) {
  case HapticGenerator::Tag::vendor:
    return "vendor";
  case HapticGenerator::Tag::hapticScales:
    return "hapticScales";
  case HapticGenerator::Tag::vibratorInfo:
    return "vibratorInfo";
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
constexpr inline std::array<aidl::android::hardware::audio::effect::HapticGenerator::Tag, 3> enum_values<aidl::android::hardware::audio::effect::HapticGenerator::Tag> = {
  aidl::android::hardware::audio::effect::HapticGenerator::Tag::vendor,
  aidl::android::hardware::audio::effect::HapticGenerator::Tag::hapticScales,
  aidl::android::hardware::audio::effect::HapticGenerator::Tag::vibratorInfo,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
