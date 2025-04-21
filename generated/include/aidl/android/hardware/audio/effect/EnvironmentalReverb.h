/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/EnvironmentalReverb.aidl
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
#include <aidl/android/hardware/audio/effect/EnvironmentalReverb.h>
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
class EnvironmentalReverb {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class Tag : int32_t {
    vendor = 0,
    roomLevelMb = 1,
    roomHfLevelMb = 2,
    decayTimeMs = 3,
    decayHfRatioPm = 4,
    reflectionsLevelMb = 5,
    reflectionsDelayMs = 6,
    levelMb = 7,
    delayMs = 8,
    diffusionPm = 9,
    densityPm = 10,
    bypass = 11,
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
    std::variant<::aidl::android::hardware::audio::effect::VendorExtension, ::aidl::android::hardware::audio::effect::EnvironmentalReverb::Tag> _value;
  };
  // Expose tag symbols for legacy code
  static const inline Tag vendor = Tag::vendor;
  static const inline Tag roomLevelMb = Tag::roomLevelMb;
  static const inline Tag roomHfLevelMb = Tag::roomHfLevelMb;
  static const inline Tag decayTimeMs = Tag::decayTimeMs;
  static const inline Tag decayHfRatioPm = Tag::decayHfRatioPm;
  static const inline Tag reflectionsLevelMb = Tag::reflectionsLevelMb;
  static const inline Tag reflectionsDelayMs = Tag::reflectionsDelayMs;
  static const inline Tag levelMb = Tag::levelMb;
  static const inline Tag delayMs = Tag::delayMs;
  static const inline Tag diffusionPm = Tag::diffusionPm;
  static const inline Tag densityPm = Tag::densityPm;
  static const inline Tag bypass = Tag::bypass;

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, EnvironmentalReverb>;

  EnvironmentalReverb() : _value(std::in_place_index<static_cast<size_t>(vendor)>, ::aidl::android::hardware::audio::effect::VendorExtension()) { }

  template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr EnvironmentalReverb(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit EnvironmentalReverb(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static EnvironmentalReverb make(_Tp&&... _args) {
    return EnvironmentalReverb(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static EnvironmentalReverb make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return EnvironmentalReverb(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

  inline bool operator==(const EnvironmentalReverb& _rhs) const {
    return _value == _rhs._value;
  }
  inline bool operator<(const EnvironmentalReverb& _rhs) const {
    return _value < _rhs._value;
  }
  inline bool operator!=(const EnvironmentalReverb& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const EnvironmentalReverb& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const EnvironmentalReverb& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const EnvironmentalReverb& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "EnvironmentalReverb{";
    switch (getTag()) {
    case vendor: os << "vendor: " << ::android::internal::ToString(get<vendor>()); break;
    case roomLevelMb: os << "roomLevelMb: " << ::android::internal::ToString(get<roomLevelMb>()); break;
    case roomHfLevelMb: os << "roomHfLevelMb: " << ::android::internal::ToString(get<roomHfLevelMb>()); break;
    case decayTimeMs: os << "decayTimeMs: " << ::android::internal::ToString(get<decayTimeMs>()); break;
    case decayHfRatioPm: os << "decayHfRatioPm: " << ::android::internal::ToString(get<decayHfRatioPm>()); break;
    case reflectionsLevelMb: os << "reflectionsLevelMb: " << ::android::internal::ToString(get<reflectionsLevelMb>()); break;
    case reflectionsDelayMs: os << "reflectionsDelayMs: " << ::android::internal::ToString(get<reflectionsDelayMs>()); break;
    case levelMb: os << "levelMb: " << ::android::internal::ToString(get<levelMb>()); break;
    case delayMs: os << "delayMs: " << ::android::internal::ToString(get<delayMs>()); break;
    case diffusionPm: os << "diffusionPm: " << ::android::internal::ToString(get<diffusionPm>()); break;
    case densityPm: os << "densityPm: " << ::android::internal::ToString(get<densityPm>()); break;
    case bypass: os << "bypass: " << ::android::internal::ToString(get<bypass>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<::aidl::android::hardware::audio::effect::VendorExtension, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, bool> _value;
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
[[nodiscard]] static inline std::string toString(EnvironmentalReverb::Id::Tag val) {
  switch(val) {
  case EnvironmentalReverb::Id::Tag::vendorExtensionTag:
    return "vendorExtensionTag";
  case EnvironmentalReverb::Id::Tag::commonTag:
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
constexpr inline std::array<aidl::android::hardware::audio::effect::EnvironmentalReverb::Id::Tag, 2> enum_values<aidl::android::hardware::audio::effect::EnvironmentalReverb::Id::Tag> = {
  aidl::android::hardware::audio::effect::EnvironmentalReverb::Id::Tag::vendorExtensionTag,
  aidl::android::hardware::audio::effect::EnvironmentalReverb::Id::Tag::commonTag,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
[[nodiscard]] static inline std::string toString(EnvironmentalReverb::Tag val) {
  switch(val) {
  case EnvironmentalReverb::Tag::vendor:
    return "vendor";
  case EnvironmentalReverb::Tag::roomLevelMb:
    return "roomLevelMb";
  case EnvironmentalReverb::Tag::roomHfLevelMb:
    return "roomHfLevelMb";
  case EnvironmentalReverb::Tag::decayTimeMs:
    return "decayTimeMs";
  case EnvironmentalReverb::Tag::decayHfRatioPm:
    return "decayHfRatioPm";
  case EnvironmentalReverb::Tag::reflectionsLevelMb:
    return "reflectionsLevelMb";
  case EnvironmentalReverb::Tag::reflectionsDelayMs:
    return "reflectionsDelayMs";
  case EnvironmentalReverb::Tag::levelMb:
    return "levelMb";
  case EnvironmentalReverb::Tag::delayMs:
    return "delayMs";
  case EnvironmentalReverb::Tag::diffusionPm:
    return "diffusionPm";
  case EnvironmentalReverb::Tag::densityPm:
    return "densityPm";
  case EnvironmentalReverb::Tag::bypass:
    return "bypass";
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
constexpr inline std::array<aidl::android::hardware::audio::effect::EnvironmentalReverb::Tag, 12> enum_values<aidl::android::hardware::audio::effect::EnvironmentalReverb::Tag> = {
  aidl::android::hardware::audio::effect::EnvironmentalReverb::Tag::vendor,
  aidl::android::hardware::audio::effect::EnvironmentalReverb::Tag::roomLevelMb,
  aidl::android::hardware::audio::effect::EnvironmentalReverb::Tag::roomHfLevelMb,
  aidl::android::hardware::audio::effect::EnvironmentalReverb::Tag::decayTimeMs,
  aidl::android::hardware::audio::effect::EnvironmentalReverb::Tag::decayHfRatioPm,
  aidl::android::hardware::audio::effect::EnvironmentalReverb::Tag::reflectionsLevelMb,
  aidl::android::hardware::audio::effect::EnvironmentalReverb::Tag::reflectionsDelayMs,
  aidl::android::hardware::audio::effect::EnvironmentalReverb::Tag::levelMb,
  aidl::android::hardware::audio::effect::EnvironmentalReverb::Tag::delayMs,
  aidl::android::hardware::audio::effect::EnvironmentalReverb::Tag::diffusionPm,
  aidl::android::hardware::audio::effect::EnvironmentalReverb::Tag::densityPm,
  aidl::android::hardware::audio::effect::EnvironmentalReverb::Tag::bypass,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
