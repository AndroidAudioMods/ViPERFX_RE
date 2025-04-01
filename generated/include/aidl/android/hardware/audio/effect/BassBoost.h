/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/BassBoost.aidl
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
#include <aidl/android/hardware/audio/effect/BassBoost.h>
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
class BassBoost {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class Tag : int32_t {
    vendor = 0,
    strengthPm = 1,
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
    std::variant<::aidl::android::hardware::audio::effect::VendorExtension, ::aidl::android::hardware::audio::effect::BassBoost::Tag> _value;
  };
  // Expose tag symbols for legacy code
  static const inline Tag vendor = Tag::vendor;
  static const inline Tag strengthPm = Tag::strengthPm;

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, BassBoost>;

  BassBoost() : _value(std::in_place_index<static_cast<size_t>(vendor)>, ::aidl::android::hardware::audio::effect::VendorExtension()) { }

  template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr BassBoost(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit BassBoost(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static BassBoost make(_Tp&&... _args) {
    return BassBoost(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static BassBoost make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return BassBoost(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

  inline bool operator==(const BassBoost& _rhs) const {
    return _value == _rhs._value;
  }
  inline bool operator<(const BassBoost& _rhs) const {
    return _value < _rhs._value;
  }
  inline bool operator!=(const BassBoost& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const BassBoost& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const BassBoost& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const BassBoost& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "BassBoost{";
    switch (getTag()) {
    case vendor: os << "vendor: " << ::android::internal::ToString(get<vendor>()); break;
    case strengthPm: os << "strengthPm: " << ::android::internal::ToString(get<strengthPm>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<::aidl::android::hardware::audio::effect::VendorExtension, int32_t> _value;
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
[[nodiscard]] static inline std::string toString(BassBoost::Id::Tag val) {
  switch(val) {
  case BassBoost::Id::Tag::vendorExtensionTag:
    return "vendorExtensionTag";
  case BassBoost::Id::Tag::commonTag:
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
constexpr inline std::array<aidl::android::hardware::audio::effect::BassBoost::Id::Tag, 2> enum_values<aidl::android::hardware::audio::effect::BassBoost::Id::Tag> = {
  aidl::android::hardware::audio::effect::BassBoost::Id::Tag::vendorExtensionTag,
  aidl::android::hardware::audio::effect::BassBoost::Id::Tag::commonTag,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
[[nodiscard]] static inline std::string toString(BassBoost::Tag val) {
  switch(val) {
  case BassBoost::Tag::vendor:
    return "vendor";
  case BassBoost::Tag::strengthPm:
    return "strengthPm";
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
constexpr inline std::array<aidl::android::hardware::audio::effect::BassBoost::Tag, 2> enum_values<aidl::android::hardware::audio::effect::BassBoost::Tag> = {
  aidl::android::hardware::audio::effect::BassBoost::Tag::vendor,
  aidl::android::hardware::audio::effect::BassBoost::Tag::strengthPm,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
