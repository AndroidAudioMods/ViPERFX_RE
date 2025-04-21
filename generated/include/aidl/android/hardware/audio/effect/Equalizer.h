/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Equalizer.aidl
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
#include <aidl/android/hardware/audio/effect/Equalizer.h>
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
class Equalizer {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class Tag : int32_t {
    vendor = 0,
    bandLevels = 1,
    preset = 2,
    centerFreqMh = 3,
    bandFrequencies = 4,
    presets = 5,
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
    std::variant<::aidl::android::hardware::audio::effect::VendorExtension, ::aidl::android::hardware::audio::effect::Equalizer::Tag> _value;
  };
  class BandLevel {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t index = 0;
    int32_t levelMb = 0;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const BandLevel& _rhs) const {
      return std::tie(index, levelMb) == std::tie(_rhs.index, _rhs.levelMb);
    }
    inline bool operator<(const BandLevel& _rhs) const {
      return std::tie(index, levelMb) < std::tie(_rhs.index, _rhs.levelMb);
    }
    inline bool operator!=(const BandLevel& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const BandLevel& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const BandLevel& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const BandLevel& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "BandLevel{";
      _aidl_os << "index: " << ::android::internal::ToString(index);
      _aidl_os << ", levelMb: " << ::android::internal::ToString(levelMb);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class BandFrequency {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t index = 0;
    int32_t minMh = 0;
    int32_t maxMh = 0;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const BandFrequency& _rhs) const {
      return std::tie(index, minMh, maxMh) == std::tie(_rhs.index, _rhs.minMh, _rhs.maxMh);
    }
    inline bool operator<(const BandFrequency& _rhs) const {
      return std::tie(index, minMh, maxMh) < std::tie(_rhs.index, _rhs.minMh, _rhs.maxMh);
    }
    inline bool operator!=(const BandFrequency& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const BandFrequency& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const BandFrequency& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const BandFrequency& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "BandFrequency{";
      _aidl_os << "index: " << ::android::internal::ToString(index);
      _aidl_os << ", minMh: " << ::android::internal::ToString(minMh);
      _aidl_os << ", maxMh: " << ::android::internal::ToString(maxMh);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class Preset {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t index = 0;
    std::string name;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const Preset& _rhs) const {
      return std::tie(index, name) == std::tie(_rhs.index, _rhs.name);
    }
    inline bool operator<(const Preset& _rhs) const {
      return std::tie(index, name) < std::tie(_rhs.index, _rhs.name);
    }
    inline bool operator!=(const Preset& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const Preset& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const Preset& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const Preset& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "Preset{";
      _aidl_os << "index: " << ::android::internal::ToString(index);
      _aidl_os << ", name: " << ::android::internal::ToString(name);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  // Expose tag symbols for legacy code
  static const inline Tag vendor = Tag::vendor;
  static const inline Tag bandLevels = Tag::bandLevels;
  static const inline Tag preset = Tag::preset;
  static const inline Tag centerFreqMh = Tag::centerFreqMh;
  static const inline Tag bandFrequencies = Tag::bandFrequencies;
  static const inline Tag presets = Tag::presets;

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, Equalizer>;

  Equalizer() : _value(std::in_place_index<static_cast<size_t>(vendor)>, ::aidl::android::hardware::audio::effect::VendorExtension()) { }

  template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr Equalizer(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit Equalizer(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static Equalizer make(_Tp&&... _args) {
    return Equalizer(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static Equalizer make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return Equalizer(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

  inline bool operator==(const Equalizer& _rhs) const {
    return _value == _rhs._value;
  }
  inline bool operator<(const Equalizer& _rhs) const {
    return _value < _rhs._value;
  }
  inline bool operator!=(const Equalizer& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const Equalizer& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const Equalizer& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const Equalizer& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "Equalizer{";
    switch (getTag()) {
    case vendor: os << "vendor: " << ::android::internal::ToString(get<vendor>()); break;
    case bandLevels: os << "bandLevels: " << ::android::internal::ToString(get<bandLevels>()); break;
    case preset: os << "preset: " << ::android::internal::ToString(get<preset>()); break;
    case centerFreqMh: os << "centerFreqMh: " << ::android::internal::ToString(get<centerFreqMh>()); break;
    case bandFrequencies: os << "bandFrequencies: " << ::android::internal::ToString(get<bandFrequencies>()); break;
    case presets: os << "presets: " << ::android::internal::ToString(get<presets>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<::aidl::android::hardware::audio::effect::VendorExtension, std::vector<::aidl::android::hardware::audio::effect::Equalizer::BandLevel>, int32_t, std::vector<int32_t>, std::vector<::aidl::android::hardware::audio::effect::Equalizer::BandFrequency>, std::vector<::aidl::android::hardware::audio::effect::Equalizer::Preset>> _value;
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
[[nodiscard]] static inline std::string toString(Equalizer::Id::Tag val) {
  switch(val) {
  case Equalizer::Id::Tag::vendorExtensionTag:
    return "vendorExtensionTag";
  case Equalizer::Id::Tag::commonTag:
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
constexpr inline std::array<aidl::android::hardware::audio::effect::Equalizer::Id::Tag, 2> enum_values<aidl::android::hardware::audio::effect::Equalizer::Id::Tag> = {
  aidl::android::hardware::audio::effect::Equalizer::Id::Tag::vendorExtensionTag,
  aidl::android::hardware::audio::effect::Equalizer::Id::Tag::commonTag,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
[[nodiscard]] static inline std::string toString(Equalizer::Tag val) {
  switch(val) {
  case Equalizer::Tag::vendor:
    return "vendor";
  case Equalizer::Tag::bandLevels:
    return "bandLevels";
  case Equalizer::Tag::preset:
    return "preset";
  case Equalizer::Tag::centerFreqMh:
    return "centerFreqMh";
  case Equalizer::Tag::bandFrequencies:
    return "bandFrequencies";
  case Equalizer::Tag::presets:
    return "presets";
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
constexpr inline std::array<aidl::android::hardware::audio::effect::Equalizer::Tag, 6> enum_values<aidl::android::hardware::audio::effect::Equalizer::Tag> = {
  aidl::android::hardware::audio::effect::Equalizer::Tag::vendor,
  aidl::android::hardware::audio::effect::Equalizer::Tag::bandLevels,
  aidl::android::hardware::audio::effect::Equalizer::Tag::preset,
  aidl::android::hardware::audio::effect::Equalizer::Tag::centerFreqMh,
  aidl::android::hardware::audio::effect::Equalizer::Tag::bandFrequencies,
  aidl::android::hardware::audio::effect::Equalizer::Tag::presets,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
