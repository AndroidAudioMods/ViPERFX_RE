/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioPortExt.aidl
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
#include <aidl/android/media/audio/common/AudioPortDeviceExt.h>
#include <aidl/android/media/audio/common/AudioPortMixExt.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

#ifndef __BIONIC__
#define __assert2(a,b,c,d) ((void)0)
#endif

namespace aidl::android::media::audio::common {
class AudioPortDeviceExt;
class AudioPortMixExt;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class AudioPortExt {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class Tag : int32_t {
    unspecified = 0,
    device = 1,
    mix = 2,
    session = 3,
  };

  // Expose tag symbols for legacy code
  static const inline Tag unspecified = Tag::unspecified;
  static const inline Tag device = Tag::device;
  static const inline Tag mix = Tag::mix;
  static const inline Tag session = Tag::session;

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, AudioPortExt>;

  AudioPortExt() : _value(std::in_place_index<static_cast<size_t>(unspecified)>, bool(false)) { }

  template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr AudioPortExt(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit AudioPortExt(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static AudioPortExt make(_Tp&&... _args) {
    return AudioPortExt(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static AudioPortExt make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return AudioPortExt(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

  inline bool operator==(const AudioPortExt& _rhs) const {
    return _value == _rhs._value;
  }
  inline bool operator<(const AudioPortExt& _rhs) const {
    return _value < _rhs._value;
  }
  inline bool operator!=(const AudioPortExt& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AudioPortExt& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AudioPortExt& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AudioPortExt& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioPortExt{";
    switch (getTag()) {
    case unspecified: os << "unspecified: " << ::android::internal::ToString(get<unspecified>()); break;
    case device: os << "device: " << ::android::internal::ToString(get<device>()); break;
    case mix: os << "mix: " << ::android::internal::ToString(get<mix>()); break;
    case session: os << "session: " << ::android::internal::ToString(get<session>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<bool, ::aidl::android::media::audio::common::AudioPortDeviceExt, ::aidl::android::media::audio::common::AudioPortMixExt, int32_t> _value;
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
[[nodiscard]] static inline std::string toString(AudioPortExt::Tag val) {
  switch(val) {
  case AudioPortExt::Tag::unspecified:
    return "unspecified";
  case AudioPortExt::Tag::device:
    return "device";
  case AudioPortExt::Tag::mix:
    return "mix";
  case AudioPortExt::Tag::session:
    return "session";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioPortExt::Tag, 4> enum_values<aidl::android::media::audio::common::AudioPortExt::Tag> = {
  aidl::android::media::audio::common::AudioPortExt::Tag::unspecified,
  aidl::android::media::audio::common::AudioPortExt::Tag::device,
  aidl::android::media::audio::common::AudioPortExt::Tag::mix,
  aidl::android::media::audio::common::AudioPortExt::Tag::session,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
