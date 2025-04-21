/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Processing.aidl
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
#include <aidl/android/hardware/audio/effect/Descriptor.h>
#include <aidl/android/hardware/audio/effect/Processing.h>
#include <aidl/android/media/audio/common/AudioDevice.h>
#include <aidl/android/media/audio/common/AudioSource.h>
#include <aidl/android/media/audio/common/AudioStreamType.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

#ifndef __BIONIC__
#define __assert2(a,b,c,d) ((void)0)
#endif

namespace aidl::android::hardware::audio::effect {
class Descriptor;
}  // namespace aidl::android::hardware::audio::effect
namespace aidl::android::media::audio::common {
class AudioDevice;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
class Processing {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  class Type {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    enum class Tag : int32_t {
      streamType = 0,
      source = 1,
      device = 2,
    };

    // Expose tag symbols for legacy code
    static const inline Tag streamType = Tag::streamType;
    static const inline Tag source = Tag::source;
    static const inline Tag device = Tag::device;

    template<typename _Tp>
    static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, Type>;

    Type() : _value(std::in_place_index<static_cast<size_t>(streamType)>, ::aidl::android::media::audio::common::AudioStreamType(::aidl::android::media::audio::common::AudioStreamType::INVALID)) { }

    template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
    // NOLINTNEXTLINE(google-explicit-constructor)
    constexpr Type(_Tp&& _arg)
        : _value(std::forward<_Tp>(_arg)) {}

    template <size_t _Np, typename... _Tp>
    constexpr explicit Type(std::in_place_index_t<_Np>, _Tp&&... _args)
        : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

    template <Tag _tag, typename... _Tp>
    static Type make(_Tp&&... _args) {
      return Type(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
    }

    template <Tag _tag, typename _Tp, typename... _Up>
    static Type make(std::initializer_list<_Tp> _il, _Up&&... _args) {
      return Type(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

    inline bool operator==(const Type& _rhs) const {
      return _value == _rhs._value;
    }
    inline bool operator<(const Type& _rhs) const {
      return _value < _rhs._value;
    }
    inline bool operator!=(const Type& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const Type& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const Type& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const Type& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream os;
      os << "Type{";
      switch (getTag()) {
      case streamType: os << "streamType: " << ::android::internal::ToString(get<streamType>()); break;
      case source: os << "source: " << ::android::internal::ToString(get<source>()); break;
      case device: os << "device: " << ::android::internal::ToString(get<device>()); break;
      }
      os << "}";
      return os.str();
    }
  private:
    std::variant<::aidl::android::media::audio::common::AudioStreamType, ::aidl::android::media::audio::common::AudioSource, ::aidl::android::media::audio::common::AudioDevice> _value;
  };
  ::aidl::android::hardware::audio::effect::Processing::Type type;
  std::vector<::aidl::android::hardware::audio::effect::Descriptor> ids;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const Processing& _rhs) const {
    return std::tie(type, ids) == std::tie(_rhs.type, _rhs.ids);
  }
  inline bool operator<(const Processing& _rhs) const {
    return std::tie(type, ids) < std::tie(_rhs.type, _rhs.ids);
  }
  inline bool operator!=(const Processing& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const Processing& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const Processing& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const Processing& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "Processing{";
    _aidl_os << "type: " << ::android::internal::ToString(type);
    _aidl_os << ", ids: " << ::android::internal::ToString(ids);
    _aidl_os << "}";
    return _aidl_os.str();
  }
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
[[nodiscard]] static inline std::string toString(Processing::Type::Tag val) {
  switch(val) {
  case Processing::Type::Tag::streamType:
    return "streamType";
  case Processing::Type::Tag::source:
    return "source";
  case Processing::Type::Tag::device:
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
constexpr inline std::array<aidl::android::hardware::audio::effect::Processing::Type::Tag, 3> enum_values<aidl::android::hardware::audio::effect::Processing::Type::Tag> = {
  aidl::android::hardware::audio::effect::Processing::Type::Tag::streamType,
  aidl::android::hardware::audio::effect::Processing::Type::Tag::source,
  aidl::android::hardware::audio::effect::Processing::Type::Tag::device,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
