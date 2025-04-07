/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/AutomaticGainControlV2.aidl
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
#include <aidl/android/hardware/audio/effect/AutomaticGainControlV2.h>
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
class AutomaticGainControlV2 {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class Tag : int32_t {
    vendor = 0,
    fixedDigitalGainMb = 1,
    levelEstimator = 2,
    saturationMarginMb = 3,
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
    std::variant<::aidl::android::hardware::audio::effect::VendorExtension, ::aidl::android::hardware::audio::effect::AutomaticGainControlV2::Tag> _value;
  };
  enum class LevelEstimator : int32_t {
    RMS = 0,
    PEAK = 1,
  };

  // Expose tag symbols for legacy code
  static const inline Tag vendor = Tag::vendor;
  static const inline Tag fixedDigitalGainMb = Tag::fixedDigitalGainMb;
  static const inline Tag levelEstimator = Tag::levelEstimator;
  static const inline Tag saturationMarginMb = Tag::saturationMarginMb;

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, AutomaticGainControlV2>;

  AutomaticGainControlV2() : _value(std::in_place_index<static_cast<size_t>(vendor)>, ::aidl::android::hardware::audio::effect::VendorExtension()) { }

  template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr AutomaticGainControlV2(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit AutomaticGainControlV2(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static AutomaticGainControlV2 make(_Tp&&... _args) {
    return AutomaticGainControlV2(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static AutomaticGainControlV2 make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return AutomaticGainControlV2(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

  inline bool operator==(const AutomaticGainControlV2& _rhs) const {
    return _value == _rhs._value;
  }
  inline bool operator<(const AutomaticGainControlV2& _rhs) const {
    return _value < _rhs._value;
  }
  inline bool operator!=(const AutomaticGainControlV2& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AutomaticGainControlV2& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AutomaticGainControlV2& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AutomaticGainControlV2& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "AutomaticGainControlV2{";
    switch (getTag()) {
    case vendor: os << "vendor: " << ::android::internal::ToString(get<vendor>()); break;
    case fixedDigitalGainMb: os << "fixedDigitalGainMb: " << ::android::internal::ToString(get<fixedDigitalGainMb>()); break;
    case levelEstimator: os << "levelEstimator: " << ::android::internal::ToString(get<levelEstimator>()); break;
    case saturationMarginMb: os << "saturationMarginMb: " << ::android::internal::ToString(get<saturationMarginMb>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<::aidl::android::hardware::audio::effect::VendorExtension, int32_t, ::aidl::android::hardware::audio::effect::AutomaticGainControlV2::LevelEstimator, int32_t> _value;
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
[[nodiscard]] static inline std::string toString(AutomaticGainControlV2::Id::Tag val) {
  switch(val) {
  case AutomaticGainControlV2::Id::Tag::vendorExtensionTag:
    return "vendorExtensionTag";
  case AutomaticGainControlV2::Id::Tag::commonTag:
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
constexpr inline std::array<aidl::android::hardware::audio::effect::AutomaticGainControlV2::Id::Tag, 2> enum_values<aidl::android::hardware::audio::effect::AutomaticGainControlV2::Id::Tag> = {
  aidl::android::hardware::audio::effect::AutomaticGainControlV2::Id::Tag::vendorExtensionTag,
  aidl::android::hardware::audio::effect::AutomaticGainControlV2::Id::Tag::commonTag,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
[[nodiscard]] static inline std::string toString(AutomaticGainControlV2::LevelEstimator val) {
  switch(val) {
  case AutomaticGainControlV2::LevelEstimator::RMS:
    return "RMS";
  case AutomaticGainControlV2::LevelEstimator::PEAK:
    return "PEAK";
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
constexpr inline std::array<aidl::android::hardware::audio::effect::AutomaticGainControlV2::LevelEstimator, 2> enum_values<aidl::android::hardware::audio::effect::AutomaticGainControlV2::LevelEstimator> = {
  aidl::android::hardware::audio::effect::AutomaticGainControlV2::LevelEstimator::RMS,
  aidl::android::hardware::audio::effect::AutomaticGainControlV2::LevelEstimator::PEAK,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
[[nodiscard]] static inline std::string toString(AutomaticGainControlV2::Tag val) {
  switch(val) {
  case AutomaticGainControlV2::Tag::vendor:
    return "vendor";
  case AutomaticGainControlV2::Tag::fixedDigitalGainMb:
    return "fixedDigitalGainMb";
  case AutomaticGainControlV2::Tag::levelEstimator:
    return "levelEstimator";
  case AutomaticGainControlV2::Tag::saturationMarginMb:
    return "saturationMarginMb";
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
constexpr inline std::array<aidl::android::hardware::audio::effect::AutomaticGainControlV2::Tag, 4> enum_values<aidl::android::hardware::audio::effect::AutomaticGainControlV2::Tag> = {
  aidl::android::hardware::audio::effect::AutomaticGainControlV2::Tag::vendor,
  aidl::android::hardware::audio::effect::AutomaticGainControlV2::Tag::fixedDigitalGainMb,
  aidl::android::hardware::audio::effect::AutomaticGainControlV2::Tag::levelEstimator,
  aidl::android::hardware::audio::effect::AutomaticGainControlV2::Tag::saturationMarginMb,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
