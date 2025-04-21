/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Virtualizer.aidl
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
#include <aidl/android/hardware/audio/effect/Virtualizer.h>
#include <aidl/android/media/audio/common/AudioChannelLayout.h>
#include <aidl/android/media/audio/common/AudioDeviceDescription.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

#ifndef __BIONIC__
#define __assert2(a,b,c,d) ((void)0)
#endif

namespace aidl::android::hardware::audio::effect {
class VendorExtension;
}  // namespace aidl::android::hardware::audio::effect
namespace aidl::android::media::audio::common {
class AudioDeviceDescription;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
class Virtualizer {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class Tag : int32_t {
    vendor = 0,
    strengthPm = 1,
    speakerAngles = 2,
    device = 3,
  };

  class SpeakerAnglesPayload {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::media::audio::common::AudioChannelLayout layout;
    ::aidl::android::media::audio::common::AudioDeviceDescription device;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const SpeakerAnglesPayload& _rhs) const {
      return std::tie(layout, device) == std::tie(_rhs.layout, _rhs.device);
    }
    inline bool operator<(const SpeakerAnglesPayload& _rhs) const {
      return std::tie(layout, device) < std::tie(_rhs.layout, _rhs.device);
    }
    inline bool operator!=(const SpeakerAnglesPayload& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const SpeakerAnglesPayload& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const SpeakerAnglesPayload& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const SpeakerAnglesPayload& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "SpeakerAnglesPayload{";
      _aidl_os << "layout: " << ::android::internal::ToString(layout);
      _aidl_os << ", device: " << ::android::internal::ToString(device);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class Id {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    enum class Tag : int32_t {
      vendorExtensionTag = 0,
      commonTag = 1,
      speakerAnglesPayload = 2,
    };

    // Expose tag symbols for legacy code
    static const inline Tag vendorExtensionTag = Tag::vendorExtensionTag;
    static const inline Tag commonTag = Tag::commonTag;
    static const inline Tag speakerAnglesPayload = Tag::speakerAnglesPayload;

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
      case speakerAnglesPayload: os << "speakerAnglesPayload: " << ::android::internal::ToString(get<speakerAnglesPayload>()); break;
      }
      os << "}";
      return os.str();
    }
  private:
    std::variant<::aidl::android::hardware::audio::effect::VendorExtension, ::aidl::android::hardware::audio::effect::Virtualizer::Tag, ::aidl::android::hardware::audio::effect::Virtualizer::SpeakerAnglesPayload> _value;
  };
  class ChannelAngle {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t channel = 0;
    int32_t azimuthDegree = 0;
    int32_t elevationDegree = 0;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const ChannelAngle& _rhs) const {
      return std::tie(channel, azimuthDegree, elevationDegree) == std::tie(_rhs.channel, _rhs.azimuthDegree, _rhs.elevationDegree);
    }
    inline bool operator<(const ChannelAngle& _rhs) const {
      return std::tie(channel, azimuthDegree, elevationDegree) < std::tie(_rhs.channel, _rhs.azimuthDegree, _rhs.elevationDegree);
    }
    inline bool operator!=(const ChannelAngle& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const ChannelAngle& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const ChannelAngle& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const ChannelAngle& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "ChannelAngle{";
      _aidl_os << "channel: " << ::android::internal::ToString(channel);
      _aidl_os << ", azimuthDegree: " << ::android::internal::ToString(azimuthDegree);
      _aidl_os << ", elevationDegree: " << ::android::internal::ToString(elevationDegree);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  // Expose tag symbols for legacy code
  static const inline Tag vendor = Tag::vendor;
  static const inline Tag strengthPm = Tag::strengthPm;
  static const inline Tag speakerAngles = Tag::speakerAngles;
  static const inline Tag device = Tag::device;

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, Virtualizer>;

  Virtualizer() : _value(std::in_place_index<static_cast<size_t>(vendor)>, ::aidl::android::hardware::audio::effect::VendorExtension()) { }

  template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr Virtualizer(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit Virtualizer(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static Virtualizer make(_Tp&&... _args) {
    return Virtualizer(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static Virtualizer make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return Virtualizer(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

  inline bool operator==(const Virtualizer& _rhs) const {
    return _value == _rhs._value;
  }
  inline bool operator<(const Virtualizer& _rhs) const {
    return _value < _rhs._value;
  }
  inline bool operator!=(const Virtualizer& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const Virtualizer& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const Virtualizer& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const Virtualizer& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "Virtualizer{";
    switch (getTag()) {
    case vendor: os << "vendor: " << ::android::internal::ToString(get<vendor>()); break;
    case strengthPm: os << "strengthPm: " << ::android::internal::ToString(get<strengthPm>()); break;
    case speakerAngles: os << "speakerAngles: " << ::android::internal::ToString(get<speakerAngles>()); break;
    case device: os << "device: " << ::android::internal::ToString(get<device>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<::aidl::android::hardware::audio::effect::VendorExtension, int32_t, std::vector<::aidl::android::hardware::audio::effect::Virtualizer::ChannelAngle>, ::aidl::android::media::audio::common::AudioDeviceDescription> _value;
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
[[nodiscard]] static inline std::string toString(Virtualizer::Id::Tag val) {
  switch(val) {
  case Virtualizer::Id::Tag::vendorExtensionTag:
    return "vendorExtensionTag";
  case Virtualizer::Id::Tag::commonTag:
    return "commonTag";
  case Virtualizer::Id::Tag::speakerAnglesPayload:
    return "speakerAnglesPayload";
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
constexpr inline std::array<aidl::android::hardware::audio::effect::Virtualizer::Id::Tag, 3> enum_values<aidl::android::hardware::audio::effect::Virtualizer::Id::Tag> = {
  aidl::android::hardware::audio::effect::Virtualizer::Id::Tag::vendorExtensionTag,
  aidl::android::hardware::audio::effect::Virtualizer::Id::Tag::commonTag,
  aidl::android::hardware::audio::effect::Virtualizer::Id::Tag::speakerAnglesPayload,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
[[nodiscard]] static inline std::string toString(Virtualizer::Tag val) {
  switch(val) {
  case Virtualizer::Tag::vendor:
    return "vendor";
  case Virtualizer::Tag::strengthPm:
    return "strengthPm";
  case Virtualizer::Tag::speakerAngles:
    return "speakerAngles";
  case Virtualizer::Tag::device:
    return "device";
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
constexpr inline std::array<aidl::android::hardware::audio::effect::Virtualizer::Tag, 4> enum_values<aidl::android::hardware::audio::effect::Virtualizer::Tag> = {
  aidl::android::hardware::audio::effect::Virtualizer::Tag::vendor,
  aidl::android::hardware::audio::effect::Virtualizer::Tag::strengthPm,
  aidl::android::hardware::audio::effect::Virtualizer::Tag::speakerAngles,
  aidl::android::hardware::audio::effect::Virtualizer::Tag::device,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
