/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioHalCapCriterionV2.aidl
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
#include <aidl/android/media/audio/common/AudioDeviceAddress.h>
#include <aidl/android/media/audio/common/AudioDeviceDescription.h>
#include <aidl/android/media/audio/common/AudioHalCapCriterionV2.h>
#include <aidl/android/media/audio/common/AudioMode.h>
#include <aidl/android/media/audio/common/AudioPolicyForceUse.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

#ifndef __BIONIC__
#define __assert2(a,b,c,d) ((void)0)
#endif

namespace aidl::android::media::audio::common {
class AudioDeviceDescription;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class AudioHalCapCriterionV2 {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class LogicalDisjunction : int8_t {
    EXCLUSIVE = 0,
    INCLUSIVE = 1,
  };

  class ForceConfigForUse {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    std::vector<::aidl::android::media::audio::common::AudioPolicyForceUse> values;
    ::aidl::android::media::audio::common::AudioPolicyForceUse defaultValue;
    ::aidl::android::media::audio::common::AudioHalCapCriterionV2::LogicalDisjunction logic = ::aidl::android::media::audio::common::AudioHalCapCriterionV2::LogicalDisjunction::EXCLUSIVE;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const ForceConfigForUse& _rhs) const {
      return std::tie(values, defaultValue, logic) == std::tie(_rhs.values, _rhs.defaultValue, _rhs.logic);
    }
    inline bool operator<(const ForceConfigForUse& _rhs) const {
      return std::tie(values, defaultValue, logic) < std::tie(_rhs.values, _rhs.defaultValue, _rhs.logic);
    }
    inline bool operator!=(const ForceConfigForUse& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const ForceConfigForUse& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const ForceConfigForUse& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const ForceConfigForUse& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "ForceConfigForUse{";
      _aidl_os << "values: " << ::android::internal::ToString(values);
      _aidl_os << ", defaultValue: " << ::android::internal::ToString(defaultValue);
      _aidl_os << ", logic: " << ::android::internal::ToString(logic);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class TelephonyMode {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    std::vector<::aidl::android::media::audio::common::AudioMode> values;
    ::aidl::android::media::audio::common::AudioMode defaultValue = ::aidl::android::media::audio::common::AudioMode::NORMAL;
    ::aidl::android::media::audio::common::AudioHalCapCriterionV2::LogicalDisjunction logic = ::aidl::android::media::audio::common::AudioHalCapCriterionV2::LogicalDisjunction::EXCLUSIVE;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const TelephonyMode& _rhs) const {
      return std::tie(values, defaultValue, logic) == std::tie(_rhs.values, _rhs.defaultValue, _rhs.logic);
    }
    inline bool operator<(const TelephonyMode& _rhs) const {
      return std::tie(values, defaultValue, logic) < std::tie(_rhs.values, _rhs.defaultValue, _rhs.logic);
    }
    inline bool operator!=(const TelephonyMode& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const TelephonyMode& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const TelephonyMode& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const TelephonyMode& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "TelephonyMode{";
      _aidl_os << "values: " << ::android::internal::ToString(values);
      _aidl_os << ", defaultValue: " << ::android::internal::ToString(defaultValue);
      _aidl_os << ", logic: " << ::android::internal::ToString(logic);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class AvailableDevices {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    std::vector<::aidl::android::media::audio::common::AudioDeviceDescription> values;
    ::aidl::android::media::audio::common::AudioHalCapCriterionV2::LogicalDisjunction logic = ::aidl::android::media::audio::common::AudioHalCapCriterionV2::LogicalDisjunction::INCLUSIVE;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const AvailableDevices& _rhs) const {
      return std::tie(values, logic) == std::tie(_rhs.values, _rhs.logic);
    }
    inline bool operator<(const AvailableDevices& _rhs) const {
      return std::tie(values, logic) < std::tie(_rhs.values, _rhs.logic);
    }
    inline bool operator!=(const AvailableDevices& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const AvailableDevices& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const AvailableDevices& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const AvailableDevices& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "AvailableDevices{";
      _aidl_os << "values: " << ::android::internal::ToString(values);
      _aidl_os << ", logic: " << ::android::internal::ToString(logic);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class AvailableDevicesAddresses {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    std::vector<::aidl::android::media::audio::common::AudioDeviceAddress> values;
    ::aidl::android::media::audio::common::AudioHalCapCriterionV2::LogicalDisjunction logic = ::aidl::android::media::audio::common::AudioHalCapCriterionV2::LogicalDisjunction::INCLUSIVE;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const AvailableDevicesAddresses& _rhs) const {
      return std::tie(values, logic) == std::tie(_rhs.values, _rhs.logic);
    }
    inline bool operator<(const AvailableDevicesAddresses& _rhs) const {
      return std::tie(values, logic) < std::tie(_rhs.values, _rhs.logic);
    }
    inline bool operator!=(const AvailableDevicesAddresses& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const AvailableDevicesAddresses& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const AvailableDevicesAddresses& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const AvailableDevicesAddresses& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "AvailableDevicesAddresses{";
      _aidl_os << "values: " << ::android::internal::ToString(values);
      _aidl_os << ", logic: " << ::android::internal::ToString(logic);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  enum class Tag : int32_t {
    availableInputDevices = 0,
    availableOutputDevices = 1,
    availableInputDevicesAddresses = 2,
    availableOutputDevicesAddresses = 3,
    telephonyMode = 4,
    forceConfigForUse = 5,
  };

  // Expose tag symbols for legacy code
  static const inline Tag availableInputDevices = Tag::availableInputDevices;
  static const inline Tag availableOutputDevices = Tag::availableOutputDevices;
  static const inline Tag availableInputDevicesAddresses = Tag::availableInputDevicesAddresses;
  static const inline Tag availableOutputDevicesAddresses = Tag::availableOutputDevicesAddresses;
  static const inline Tag telephonyMode = Tag::telephonyMode;
  static const inline Tag forceConfigForUse = Tag::forceConfigForUse;

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, AudioHalCapCriterionV2>;

  AudioHalCapCriterionV2() : _value(std::in_place_index<static_cast<size_t>(availableInputDevices)>, ::aidl::android::media::audio::common::AudioHalCapCriterionV2::AvailableDevices()) { }

  template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr AudioHalCapCriterionV2(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit AudioHalCapCriterionV2(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static AudioHalCapCriterionV2 make(_Tp&&... _args) {
    return AudioHalCapCriterionV2(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static AudioHalCapCriterionV2 make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return AudioHalCapCriterionV2(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

  inline bool operator==(const AudioHalCapCriterionV2& _rhs) const {
    return _value == _rhs._value;
  }
  inline bool operator<(const AudioHalCapCriterionV2& _rhs) const {
    return _value < _rhs._value;
  }
  inline bool operator!=(const AudioHalCapCriterionV2& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AudioHalCapCriterionV2& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AudioHalCapCriterionV2& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AudioHalCapCriterionV2& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioHalCapCriterionV2{";
    switch (getTag()) {
    case availableInputDevices: os << "availableInputDevices: " << ::android::internal::ToString(get<availableInputDevices>()); break;
    case availableOutputDevices: os << "availableOutputDevices: " << ::android::internal::ToString(get<availableOutputDevices>()); break;
    case availableInputDevicesAddresses: os << "availableInputDevicesAddresses: " << ::android::internal::ToString(get<availableInputDevicesAddresses>()); break;
    case availableOutputDevicesAddresses: os << "availableOutputDevicesAddresses: " << ::android::internal::ToString(get<availableOutputDevicesAddresses>()); break;
    case telephonyMode: os << "telephonyMode: " << ::android::internal::ToString(get<telephonyMode>()); break;
    case forceConfigForUse: os << "forceConfigForUse: " << ::android::internal::ToString(get<forceConfigForUse>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<::aidl::android::media::audio::common::AudioHalCapCriterionV2::AvailableDevices, ::aidl::android::media::audio::common::AudioHalCapCriterionV2::AvailableDevices, ::aidl::android::media::audio::common::AudioHalCapCriterionV2::AvailableDevicesAddresses, ::aidl::android::media::audio::common::AudioHalCapCriterionV2::AvailableDevicesAddresses, ::aidl::android::media::audio::common::AudioHalCapCriterionV2::TelephonyMode, ::aidl::android::media::audio::common::AudioHalCapCriterionV2::ForceConfigForUse> _value;
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
[[nodiscard]] static inline std::string toString(AudioHalCapCriterionV2::LogicalDisjunction val) {
  switch(val) {
  case AudioHalCapCriterionV2::LogicalDisjunction::EXCLUSIVE:
    return "EXCLUSIVE";
  case AudioHalCapCriterionV2::LogicalDisjunction::INCLUSIVE:
    return "INCLUSIVE";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioHalCapCriterionV2::LogicalDisjunction, 2> enum_values<aidl::android::media::audio::common::AudioHalCapCriterionV2::LogicalDisjunction> = {
  aidl::android::media::audio::common::AudioHalCapCriterionV2::LogicalDisjunction::EXCLUSIVE,
  aidl::android::media::audio::common::AudioHalCapCriterionV2::LogicalDisjunction::INCLUSIVE,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
[[nodiscard]] static inline std::string toString(AudioHalCapCriterionV2::Tag val) {
  switch(val) {
  case AudioHalCapCriterionV2::Tag::availableInputDevices:
    return "availableInputDevices";
  case AudioHalCapCriterionV2::Tag::availableOutputDevices:
    return "availableOutputDevices";
  case AudioHalCapCriterionV2::Tag::availableInputDevicesAddresses:
    return "availableInputDevicesAddresses";
  case AudioHalCapCriterionV2::Tag::availableOutputDevicesAddresses:
    return "availableOutputDevicesAddresses";
  case AudioHalCapCriterionV2::Tag::telephonyMode:
    return "telephonyMode";
  case AudioHalCapCriterionV2::Tag::forceConfigForUse:
    return "forceConfigForUse";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioHalCapCriterionV2::Tag, 6> enum_values<aidl::android::media::audio::common::AudioHalCapCriterionV2::Tag> = {
  aidl::android::media::audio::common::AudioHalCapCriterionV2::Tag::availableInputDevices,
  aidl::android::media::audio::common::AudioHalCapCriterionV2::Tag::availableOutputDevices,
  aidl::android::media::audio::common::AudioHalCapCriterionV2::Tag::availableInputDevicesAddresses,
  aidl::android::media::audio::common::AudioHalCapCriterionV2::Tag::availableOutputDevicesAddresses,
  aidl::android::media::audio::common::AudioHalCapCriterionV2::Tag::telephonyMode,
  aidl::android::media::audio::common::AudioHalCapCriterionV2::Tag::forceConfigForUse,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
