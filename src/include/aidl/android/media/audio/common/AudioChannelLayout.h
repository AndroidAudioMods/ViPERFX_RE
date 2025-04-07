/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioChannelLayout.aidl
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
class AudioChannelLayout {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class Tag : int32_t {
    none = 0,
    invalid = 1,
    indexMask = 2,
    layoutMask = 3,
    voiceMask = 4,
  };

  // Expose tag symbols for legacy code
  static const inline Tag none = Tag::none;
  static const inline Tag invalid = Tag::invalid;
  static const inline Tag indexMask = Tag::indexMask;
  static const inline Tag layoutMask = Tag::layoutMask;
  static const inline Tag voiceMask = Tag::voiceMask;

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, AudioChannelLayout>;

  AudioChannelLayout() : _value(std::in_place_index<static_cast<size_t>(none)>, int32_t(0)) { }

  template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr AudioChannelLayout(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit AudioChannelLayout(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static AudioChannelLayout make(_Tp&&... _args) {
    return AudioChannelLayout(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static AudioChannelLayout make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return AudioChannelLayout(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

  inline bool operator==(const AudioChannelLayout& _rhs) const {
    return _value == _rhs._value;
  }
  inline bool operator<(const AudioChannelLayout& _rhs) const {
    return _value < _rhs._value;
  }
  inline bool operator!=(const AudioChannelLayout& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AudioChannelLayout& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AudioChannelLayout& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AudioChannelLayout& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  enum : int32_t { INDEX_MASK_1 = 1 };
  enum : int32_t { INDEX_MASK_2 = 3 };
  enum : int32_t { INDEX_MASK_3 = 7 };
  enum : int32_t { INDEX_MASK_4 = 15 };
  enum : int32_t { INDEX_MASK_5 = 31 };
  enum : int32_t { INDEX_MASK_6 = 63 };
  enum : int32_t { INDEX_MASK_7 = 127 };
  enum : int32_t { INDEX_MASK_8 = 255 };
  enum : int32_t { INDEX_MASK_9 = 511 };
  enum : int32_t { INDEX_MASK_10 = 1023 };
  enum : int32_t { INDEX_MASK_11 = 2047 };
  enum : int32_t { INDEX_MASK_12 = 4095 };
  enum : int32_t { INDEX_MASK_13 = 8191 };
  enum : int32_t { INDEX_MASK_14 = 16383 };
  enum : int32_t { INDEX_MASK_15 = 32767 };
  enum : int32_t { INDEX_MASK_16 = 65535 };
  enum : int32_t { INDEX_MASK_17 = 131071 };
  enum : int32_t { INDEX_MASK_18 = 262143 };
  enum : int32_t { INDEX_MASK_19 = 524287 };
  enum : int32_t { INDEX_MASK_20 = 1048575 };
  enum : int32_t { INDEX_MASK_21 = 2097151 };
  enum : int32_t { INDEX_MASK_22 = 4194303 };
  enum : int32_t { INDEX_MASK_23 = 8388607 };
  enum : int32_t { INDEX_MASK_24 = 16777215 };
  enum : int32_t { LAYOUT_MONO = 1 };
  enum : int32_t { LAYOUT_STEREO = 3 };
  enum : int32_t { LAYOUT_2POINT1 = 11 };
  enum : int32_t { LAYOUT_TRI = 7 };
  enum : int32_t { LAYOUT_TRI_BACK = 259 };
  enum : int32_t { LAYOUT_3POINT1 = 15 };
  enum : int32_t { LAYOUT_2POINT0POINT2 = 786435 };
  enum : int32_t { LAYOUT_2POINT1POINT2 = 786443 };
  enum : int32_t { LAYOUT_3POINT0POINT2 = 786439 };
  enum : int32_t { LAYOUT_3POINT1POINT2 = 786447 };
  enum : int32_t { LAYOUT_QUAD = 51 };
  enum : int32_t { LAYOUT_QUAD_SIDE = 1539 };
  enum : int32_t { LAYOUT_SURROUND = 263 };
  enum : int32_t { LAYOUT_PENTA = 55 };
  enum : int32_t { LAYOUT_5POINT1 = 63 };
  enum : int32_t { LAYOUT_5POINT1_SIDE = 1551 };
  enum : int32_t { LAYOUT_5POINT1POINT2 = 786495 };
  enum : int32_t { LAYOUT_5POINT1POINT4 = 184383 };
  enum : int32_t { LAYOUT_6POINT1 = 319 };
  enum : int32_t { LAYOUT_7POINT1 = 1599 };
  enum : int32_t { LAYOUT_7POINT1POINT2 = 788031 };
  enum : int32_t { LAYOUT_7POINT1POINT4 = 185919 };
  enum : int32_t { LAYOUT_9POINT1POINT4 = 50517567 };
  enum : int32_t { LAYOUT_9POINT1POINT6 = 51303999 };
  enum : int32_t { LAYOUT_13POINT_360RA = 7534087 };
  enum : int32_t { LAYOUT_22POINT2 = 16777215 };
  enum : int32_t { LAYOUT_MONO_HAPTIC_A = 1073741825 };
  enum : int32_t { LAYOUT_STEREO_HAPTIC_A = 1073741827 };
  enum : int32_t { LAYOUT_HAPTIC_AB = 1610612736 };
  enum : int32_t { LAYOUT_MONO_HAPTIC_AB = 1610612737 };
  enum : int32_t { LAYOUT_STEREO_HAPTIC_AB = 1610612739 };
  enum : int32_t { LAYOUT_FRONT_BACK = 260 };
  enum : int32_t { INTERLEAVE_LEFT = 0 };
  enum : int32_t { INTERLEAVE_RIGHT = 1 };
  enum : int32_t { CHANNEL_FRONT_LEFT = 1 };
  enum : int32_t { CHANNEL_FRONT_RIGHT = 2 };
  enum : int32_t { CHANNEL_FRONT_CENTER = 4 };
  enum : int32_t { CHANNEL_LOW_FREQUENCY = 8 };
  enum : int32_t { CHANNEL_BACK_LEFT = 16 };
  enum : int32_t { CHANNEL_BACK_RIGHT = 32 };
  enum : int32_t { CHANNEL_FRONT_LEFT_OF_CENTER = 64 };
  enum : int32_t { CHANNEL_FRONT_RIGHT_OF_CENTER = 128 };
  enum : int32_t { CHANNEL_BACK_CENTER = 256 };
  enum : int32_t { CHANNEL_SIDE_LEFT = 512 };
  enum : int32_t { CHANNEL_SIDE_RIGHT = 1024 };
  enum : int32_t { CHANNEL_TOP_CENTER = 2048 };
  enum : int32_t { CHANNEL_TOP_FRONT_LEFT = 4096 };
  enum : int32_t { CHANNEL_TOP_FRONT_CENTER = 8192 };
  enum : int32_t { CHANNEL_TOP_FRONT_RIGHT = 16384 };
  enum : int32_t { CHANNEL_TOP_BACK_LEFT = 32768 };
  enum : int32_t { CHANNEL_TOP_BACK_CENTER = 65536 };
  enum : int32_t { CHANNEL_TOP_BACK_RIGHT = 131072 };
  enum : int32_t { CHANNEL_TOP_SIDE_LEFT = 262144 };
  enum : int32_t { CHANNEL_TOP_SIDE_RIGHT = 524288 };
  enum : int32_t { CHANNEL_BOTTOM_FRONT_LEFT = 1048576 };
  enum : int32_t { CHANNEL_BOTTOM_FRONT_CENTER = 2097152 };
  enum : int32_t { CHANNEL_BOTTOM_FRONT_RIGHT = 4194304 };
  enum : int32_t { CHANNEL_LOW_FREQUENCY_2 = 8388608 };
  enum : int32_t { CHANNEL_FRONT_WIDE_LEFT = 16777216 };
  enum : int32_t { CHANNEL_FRONT_WIDE_RIGHT = 33554432 };
  enum : int32_t { CHANNEL_HAPTIC_B = 536870912 };
  enum : int32_t { CHANNEL_HAPTIC_A = 1073741824 };
  enum : int32_t { VOICE_UPLINK_MONO = 16384 };
  enum : int32_t { VOICE_DNLINK_MONO = 32768 };
  enum : int32_t { VOICE_CALL_MONO = 49152 };
  enum : int32_t { CHANNEL_VOICE_UPLINK = 16384 };
  enum : int32_t { CHANNEL_VOICE_DNLINK = 32768 };
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioChannelLayout{";
    switch (getTag()) {
    case none: os << "none: " << ::android::internal::ToString(get<none>()); break;
    case invalid: os << "invalid: " << ::android::internal::ToString(get<invalid>()); break;
    case indexMask: os << "indexMask: " << ::android::internal::ToString(get<indexMask>()); break;
    case layoutMask: os << "layoutMask: " << ::android::internal::ToString(get<layoutMask>()); break;
    case voiceMask: os << "voiceMask: " << ::android::internal::ToString(get<voiceMask>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<int32_t, int32_t, int32_t, int32_t, int32_t> _value;
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
[[nodiscard]] static inline std::string toString(AudioChannelLayout::Tag val) {
  switch(val) {
  case AudioChannelLayout::Tag::none:
    return "none";
  case AudioChannelLayout::Tag::invalid:
    return "invalid";
  case AudioChannelLayout::Tag::indexMask:
    return "indexMask";
  case AudioChannelLayout::Tag::layoutMask:
    return "layoutMask";
  case AudioChannelLayout::Tag::voiceMask:
    return "voiceMask";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioChannelLayout::Tag, 5> enum_values<aidl::android::media::audio::common::AudioChannelLayout::Tag> = {
  aidl::android::media::audio::common::AudioChannelLayout::Tag::none,
  aidl::android::media::audio::common::AudioChannelLayout::Tag::invalid,
  aidl::android::media::audio::common::AudioChannelLayout::Tag::indexMask,
  aidl::android::media::audio::common::AudioChannelLayout::Tag::layoutMask,
  aidl::android::media::audio::common::AudioChannelLayout::Tag::voiceMask,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
