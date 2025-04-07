/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioPolicyForceUse.aidl
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
#include <aidl/android/media/audio/common/AudioPolicyForceUse.h>
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
class AudioPolicyForceUse {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class CommunicationDeviceCategory : int8_t {
    NONE = 0,
    SPEAKER = 1,
    BT_SCO = 2,
    BT_BLE = 3,
    WIRED_ACCESSORY = 4,
  };

  enum class MediaDeviceCategory : int8_t {
    NONE = 0,
    SPEAKER = 1,
    HEADPHONES = 2,
    BT_A2DP = 3,
    ANALOG_DOCK = 4,
    DIGITAL_DOCK = 5,
    WIRED_ACCESSORY = 6,
    NO_BT_A2DP = 7,
  };

  enum class DockType : int8_t {
    NONE = 0,
    BT_CAR_DOCK = 1,
    BT_DESK_DOCK = 2,
    ANALOG_DOCK = 3,
    DIGITAL_DOCK = 4,
    WIRED_ACCESSORY = 5,
  };

  enum class EncodedSurroundConfig : int8_t {
    UNSPECIFIED = 0,
    NEVER = 1,
    ALWAYS = 2,
    MANUAL = 3,
  };

  enum class Tag : int32_t {
    forMedia = 0,
    forCommunication = 1,
    forRecord = 2,
    forVibrateRinging = 3,
    dock = 4,
    systemSounds = 5,
    hdmiSystemAudio = 6,
    encodedSurround = 7,
  };

  // Expose tag symbols for legacy code
  static const inline Tag forMedia = Tag::forMedia;
  static const inline Tag forCommunication = Tag::forCommunication;
  static const inline Tag forRecord = Tag::forRecord;
  static const inline Tag forVibrateRinging = Tag::forVibrateRinging;
  static const inline Tag dock = Tag::dock;
  static const inline Tag systemSounds = Tag::systemSounds;
  static const inline Tag hdmiSystemAudio = Tag::hdmiSystemAudio;
  static const inline Tag encodedSurround = Tag::encodedSurround;

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, AudioPolicyForceUse>;

  AudioPolicyForceUse() : _value(std::in_place_index<static_cast<size_t>(forMedia)>, ::aidl::android::media::audio::common::AudioPolicyForceUse::MediaDeviceCategory(::aidl::android::media::audio::common::AudioPolicyForceUse::MediaDeviceCategory::NONE)) { }

  template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr AudioPolicyForceUse(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit AudioPolicyForceUse(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static AudioPolicyForceUse make(_Tp&&... _args) {
    return AudioPolicyForceUse(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static AudioPolicyForceUse make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return AudioPolicyForceUse(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

  inline bool operator==(const AudioPolicyForceUse& _rhs) const {
    return _value == _rhs._value;
  }
  inline bool operator<(const AudioPolicyForceUse& _rhs) const {
    return _value < _rhs._value;
  }
  inline bool operator!=(const AudioPolicyForceUse& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AudioPolicyForceUse& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AudioPolicyForceUse& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AudioPolicyForceUse& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioPolicyForceUse{";
    switch (getTag()) {
    case forMedia: os << "forMedia: " << ::android::internal::ToString(get<forMedia>()); break;
    case forCommunication: os << "forCommunication: " << ::android::internal::ToString(get<forCommunication>()); break;
    case forRecord: os << "forRecord: " << ::android::internal::ToString(get<forRecord>()); break;
    case forVibrateRinging: os << "forVibrateRinging: " << ::android::internal::ToString(get<forVibrateRinging>()); break;
    case dock: os << "dock: " << ::android::internal::ToString(get<dock>()); break;
    case systemSounds: os << "systemSounds: " << ::android::internal::ToString(get<systemSounds>()); break;
    case hdmiSystemAudio: os << "hdmiSystemAudio: " << ::android::internal::ToString(get<hdmiSystemAudio>()); break;
    case encodedSurround: os << "encodedSurround: " << ::android::internal::ToString(get<encodedSurround>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<::aidl::android::media::audio::common::AudioPolicyForceUse::MediaDeviceCategory, ::aidl::android::media::audio::common::AudioPolicyForceUse::CommunicationDeviceCategory, ::aidl::android::media::audio::common::AudioPolicyForceUse::CommunicationDeviceCategory, ::aidl::android::media::audio::common::AudioPolicyForceUse::CommunicationDeviceCategory, ::aidl::android::media::audio::common::AudioPolicyForceUse::DockType, bool, bool, ::aidl::android::media::audio::common::AudioPolicyForceUse::EncodedSurroundConfig> _value;
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
[[nodiscard]] static inline std::string toString(AudioPolicyForceUse::CommunicationDeviceCategory val) {
  switch(val) {
  case AudioPolicyForceUse::CommunicationDeviceCategory::NONE:
    return "NONE";
  case AudioPolicyForceUse::CommunicationDeviceCategory::SPEAKER:
    return "SPEAKER";
  case AudioPolicyForceUse::CommunicationDeviceCategory::BT_SCO:
    return "BT_SCO";
  case AudioPolicyForceUse::CommunicationDeviceCategory::BT_BLE:
    return "BT_BLE";
  case AudioPolicyForceUse::CommunicationDeviceCategory::WIRED_ACCESSORY:
    return "WIRED_ACCESSORY";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioPolicyForceUse::CommunicationDeviceCategory, 5> enum_values<aidl::android::media::audio::common::AudioPolicyForceUse::CommunicationDeviceCategory> = {
  aidl::android::media::audio::common::AudioPolicyForceUse::CommunicationDeviceCategory::NONE,
  aidl::android::media::audio::common::AudioPolicyForceUse::CommunicationDeviceCategory::SPEAKER,
  aidl::android::media::audio::common::AudioPolicyForceUse::CommunicationDeviceCategory::BT_SCO,
  aidl::android::media::audio::common::AudioPolicyForceUse::CommunicationDeviceCategory::BT_BLE,
  aidl::android::media::audio::common::AudioPolicyForceUse::CommunicationDeviceCategory::WIRED_ACCESSORY,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
[[nodiscard]] static inline std::string toString(AudioPolicyForceUse::MediaDeviceCategory val) {
  switch(val) {
  case AudioPolicyForceUse::MediaDeviceCategory::NONE:
    return "NONE";
  case AudioPolicyForceUse::MediaDeviceCategory::SPEAKER:
    return "SPEAKER";
  case AudioPolicyForceUse::MediaDeviceCategory::HEADPHONES:
    return "HEADPHONES";
  case AudioPolicyForceUse::MediaDeviceCategory::BT_A2DP:
    return "BT_A2DP";
  case AudioPolicyForceUse::MediaDeviceCategory::ANALOG_DOCK:
    return "ANALOG_DOCK";
  case AudioPolicyForceUse::MediaDeviceCategory::DIGITAL_DOCK:
    return "DIGITAL_DOCK";
  case AudioPolicyForceUse::MediaDeviceCategory::WIRED_ACCESSORY:
    return "WIRED_ACCESSORY";
  case AudioPolicyForceUse::MediaDeviceCategory::NO_BT_A2DP:
    return "NO_BT_A2DP";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioPolicyForceUse::MediaDeviceCategory, 8> enum_values<aidl::android::media::audio::common::AudioPolicyForceUse::MediaDeviceCategory> = {
  aidl::android::media::audio::common::AudioPolicyForceUse::MediaDeviceCategory::NONE,
  aidl::android::media::audio::common::AudioPolicyForceUse::MediaDeviceCategory::SPEAKER,
  aidl::android::media::audio::common::AudioPolicyForceUse::MediaDeviceCategory::HEADPHONES,
  aidl::android::media::audio::common::AudioPolicyForceUse::MediaDeviceCategory::BT_A2DP,
  aidl::android::media::audio::common::AudioPolicyForceUse::MediaDeviceCategory::ANALOG_DOCK,
  aidl::android::media::audio::common::AudioPolicyForceUse::MediaDeviceCategory::DIGITAL_DOCK,
  aidl::android::media::audio::common::AudioPolicyForceUse::MediaDeviceCategory::WIRED_ACCESSORY,
  aidl::android::media::audio::common::AudioPolicyForceUse::MediaDeviceCategory::NO_BT_A2DP,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
[[nodiscard]] static inline std::string toString(AudioPolicyForceUse::DockType val) {
  switch(val) {
  case AudioPolicyForceUse::DockType::NONE:
    return "NONE";
  case AudioPolicyForceUse::DockType::BT_CAR_DOCK:
    return "BT_CAR_DOCK";
  case AudioPolicyForceUse::DockType::BT_DESK_DOCK:
    return "BT_DESK_DOCK";
  case AudioPolicyForceUse::DockType::ANALOG_DOCK:
    return "ANALOG_DOCK";
  case AudioPolicyForceUse::DockType::DIGITAL_DOCK:
    return "DIGITAL_DOCK";
  case AudioPolicyForceUse::DockType::WIRED_ACCESSORY:
    return "WIRED_ACCESSORY";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioPolicyForceUse::DockType, 6> enum_values<aidl::android::media::audio::common::AudioPolicyForceUse::DockType> = {
  aidl::android::media::audio::common::AudioPolicyForceUse::DockType::NONE,
  aidl::android::media::audio::common::AudioPolicyForceUse::DockType::BT_CAR_DOCK,
  aidl::android::media::audio::common::AudioPolicyForceUse::DockType::BT_DESK_DOCK,
  aidl::android::media::audio::common::AudioPolicyForceUse::DockType::ANALOG_DOCK,
  aidl::android::media::audio::common::AudioPolicyForceUse::DockType::DIGITAL_DOCK,
  aidl::android::media::audio::common::AudioPolicyForceUse::DockType::WIRED_ACCESSORY,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
[[nodiscard]] static inline std::string toString(AudioPolicyForceUse::EncodedSurroundConfig val) {
  switch(val) {
  case AudioPolicyForceUse::EncodedSurroundConfig::UNSPECIFIED:
    return "UNSPECIFIED";
  case AudioPolicyForceUse::EncodedSurroundConfig::NEVER:
    return "NEVER";
  case AudioPolicyForceUse::EncodedSurroundConfig::ALWAYS:
    return "ALWAYS";
  case AudioPolicyForceUse::EncodedSurroundConfig::MANUAL:
    return "MANUAL";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioPolicyForceUse::EncodedSurroundConfig, 4> enum_values<aidl::android::media::audio::common::AudioPolicyForceUse::EncodedSurroundConfig> = {
  aidl::android::media::audio::common::AudioPolicyForceUse::EncodedSurroundConfig::UNSPECIFIED,
  aidl::android::media::audio::common::AudioPolicyForceUse::EncodedSurroundConfig::NEVER,
  aidl::android::media::audio::common::AudioPolicyForceUse::EncodedSurroundConfig::ALWAYS,
  aidl::android::media::audio::common::AudioPolicyForceUse::EncodedSurroundConfig::MANUAL,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
[[nodiscard]] static inline std::string toString(AudioPolicyForceUse::Tag val) {
  switch(val) {
  case AudioPolicyForceUse::Tag::forMedia:
    return "forMedia";
  case AudioPolicyForceUse::Tag::forCommunication:
    return "forCommunication";
  case AudioPolicyForceUse::Tag::forRecord:
    return "forRecord";
  case AudioPolicyForceUse::Tag::forVibrateRinging:
    return "forVibrateRinging";
  case AudioPolicyForceUse::Tag::dock:
    return "dock";
  case AudioPolicyForceUse::Tag::systemSounds:
    return "systemSounds";
  case AudioPolicyForceUse::Tag::hdmiSystemAudio:
    return "hdmiSystemAudio";
  case AudioPolicyForceUse::Tag::encodedSurround:
    return "encodedSurround";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioPolicyForceUse::Tag, 8> enum_values<aidl::android::media::audio::common::AudioPolicyForceUse::Tag> = {
  aidl::android::media::audio::common::AudioPolicyForceUse::Tag::forMedia,
  aidl::android::media::audio::common::AudioPolicyForceUse::Tag::forCommunication,
  aidl::android::media::audio::common::AudioPolicyForceUse::Tag::forRecord,
  aidl::android::media::audio::common::AudioPolicyForceUse::Tag::forVibrateRinging,
  aidl::android::media::audio::common::AudioPolicyForceUse::Tag::dock,
  aidl::android::media::audio::common::AudioPolicyForceUse::Tag::systemSounds,
  aidl::android::media::audio::common::AudioPolicyForceUse::Tag::hdmiSystemAudio,
  aidl::android::media::audio::common::AudioPolicyForceUse::Tag::encodedSurround,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
