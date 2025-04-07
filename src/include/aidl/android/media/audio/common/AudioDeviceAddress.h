/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioDeviceAddress.aidl
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
class AudioDeviceAddress {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class Tag : int32_t {
    id = 0,
    mac = 1,
    ipv4 = 2,
    ipv6 = 3,
    alsa = 4,
  };

  // Expose tag symbols for legacy code
  static const inline Tag id = Tag::id;
  static const inline Tag mac = Tag::mac;
  static const inline Tag ipv4 = Tag::ipv4;
  static const inline Tag ipv6 = Tag::ipv6;
  static const inline Tag alsa = Tag::alsa;

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, AudioDeviceAddress>;

  AudioDeviceAddress() : _value(std::in_place_index<static_cast<size_t>(id)>, std::string()) { }

  template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr AudioDeviceAddress(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit AudioDeviceAddress(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static AudioDeviceAddress make(_Tp&&... _args) {
    return AudioDeviceAddress(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static AudioDeviceAddress make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return AudioDeviceAddress(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

  inline bool operator==(const AudioDeviceAddress& _rhs) const {
    return _value == _rhs._value;
  }
  inline bool operator<(const AudioDeviceAddress& _rhs) const {
    return _value < _rhs._value;
  }
  inline bool operator!=(const AudioDeviceAddress& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AudioDeviceAddress& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AudioDeviceAddress& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AudioDeviceAddress& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioDeviceAddress{";
    switch (getTag()) {
    case id: os << "id: " << ::android::internal::ToString(get<id>()); break;
    case mac: os << "mac: " << ::android::internal::ToString(get<mac>()); break;
    case ipv4: os << "ipv4: " << ::android::internal::ToString(get<ipv4>()); break;
    case ipv6: os << "ipv6: " << ::android::internal::ToString(get<ipv6>()); break;
    case alsa: os << "alsa: " << ::android::internal::ToString(get<alsa>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<std::string, std::vector<uint8_t>, std::vector<uint8_t>, std::vector<int32_t>, std::vector<int32_t>> _value;
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
[[nodiscard]] static inline std::string toString(AudioDeviceAddress::Tag val) {
  switch(val) {
  case AudioDeviceAddress::Tag::id:
    return "id";
  case AudioDeviceAddress::Tag::mac:
    return "mac";
  case AudioDeviceAddress::Tag::ipv4:
    return "ipv4";
  case AudioDeviceAddress::Tag::ipv6:
    return "ipv6";
  case AudioDeviceAddress::Tag::alsa:
    return "alsa";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioDeviceAddress::Tag, 5> enum_values<aidl::android::media::audio::common::AudioDeviceAddress::Tag> = {
  aidl::android::media::audio::common::AudioDeviceAddress::Tag::id,
  aidl::android::media::audio::common::AudioDeviceAddress::Tag::mac,
  aidl::android::media::audio::common::AudioDeviceAddress::Tag::ipv4,
  aidl::android::media::audio::common::AudioDeviceAddress::Tag::ipv6,
  aidl::android::media::audio::common::AudioDeviceAddress::Tag::alsa,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
