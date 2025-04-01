/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Flags.aidl
 */
#pragma once

#include <array>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_enums.h>
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#include <aidl/android/hardware/audio/effect/Flags.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
class Flags {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class Type : int8_t {
    INSERT = 0,
    AUXILIARY = 1,
    REPLACE = 2,
    PRE_PROC = 3,
    POST_PROC = 4,
  };

  enum class Insert : int8_t {
    ANY = 0,
    FIRST = 1,
    LAST = 2,
    EXCLUSIVE = 3,
  };

  enum class Volume : int8_t {
    NONE = 0,
    CTRL = 1,
    IND = 2,
    MONITOR = 3,
  };

  enum class HardwareAccelerator : int8_t {
    NONE = 0,
    SIMPLE = 1,
    TUNNEL = 2,
  };

  ::aidl::android::hardware::audio::effect::Flags::Type type = ::aidl::android::hardware::audio::effect::Flags::Type::INSERT;
  ::aidl::android::hardware::audio::effect::Flags::Insert insert = ::aidl::android::hardware::audio::effect::Flags::Insert::ANY;
  ::aidl::android::hardware::audio::effect::Flags::Volume volume = ::aidl::android::hardware::audio::effect::Flags::Volume::NONE;
  ::aidl::android::hardware::audio::effect::Flags::HardwareAccelerator hwAcceleratorMode = ::aidl::android::hardware::audio::effect::Flags::HardwareAccelerator::NONE;
  bool offloadIndication = false;
  bool deviceIndication = false;
  bool audioModeIndication = false;
  bool audioSourceIndication = false;
  bool bypass = false;
  bool sinkMetadataIndication = false;
  bool sourceMetadataIndication = false;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const Flags& _rhs) const {
    return std::tie(type, insert, volume, hwAcceleratorMode, offloadIndication, deviceIndication, audioModeIndication, audioSourceIndication, bypass, sinkMetadataIndication, sourceMetadataIndication) == std::tie(_rhs.type, _rhs.insert, _rhs.volume, _rhs.hwAcceleratorMode, _rhs.offloadIndication, _rhs.deviceIndication, _rhs.audioModeIndication, _rhs.audioSourceIndication, _rhs.bypass, _rhs.sinkMetadataIndication, _rhs.sourceMetadataIndication);
  }
  inline bool operator<(const Flags& _rhs) const {
    return std::tie(type, insert, volume, hwAcceleratorMode, offloadIndication, deviceIndication, audioModeIndication, audioSourceIndication, bypass, sinkMetadataIndication, sourceMetadataIndication) < std::tie(_rhs.type, _rhs.insert, _rhs.volume, _rhs.hwAcceleratorMode, _rhs.offloadIndication, _rhs.deviceIndication, _rhs.audioModeIndication, _rhs.audioSourceIndication, _rhs.bypass, _rhs.sinkMetadataIndication, _rhs.sourceMetadataIndication);
  }
  inline bool operator!=(const Flags& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const Flags& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const Flags& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const Flags& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "Flags{";
    _aidl_os << "type: " << ::android::internal::ToString(type);
    _aidl_os << ", insert: " << ::android::internal::ToString(insert);
    _aidl_os << ", volume: " << ::android::internal::ToString(volume);
    _aidl_os << ", hwAcceleratorMode: " << ::android::internal::ToString(hwAcceleratorMode);
    _aidl_os << ", offloadIndication: " << ::android::internal::ToString(offloadIndication);
    _aidl_os << ", deviceIndication: " << ::android::internal::ToString(deviceIndication);
    _aidl_os << ", audioModeIndication: " << ::android::internal::ToString(audioModeIndication);
    _aidl_os << ", audioSourceIndication: " << ::android::internal::ToString(audioSourceIndication);
    _aidl_os << ", bypass: " << ::android::internal::ToString(bypass);
    _aidl_os << ", sinkMetadataIndication: " << ::android::internal::ToString(sinkMetadataIndication);
    _aidl_os << ", sourceMetadataIndication: " << ::android::internal::ToString(sourceMetadataIndication);
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
[[nodiscard]] static inline std::string toString(Flags::Type val) {
  switch(val) {
  case Flags::Type::INSERT:
    return "INSERT";
  case Flags::Type::AUXILIARY:
    return "AUXILIARY";
  case Flags::Type::REPLACE:
    return "REPLACE";
  case Flags::Type::PRE_PROC:
    return "PRE_PROC";
  case Flags::Type::POST_PROC:
    return "POST_PROC";
  default:
    return std::to_string(static_cast<int8_t>(val));
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
constexpr inline std::array<aidl::android::hardware::audio::effect::Flags::Type, 5> enum_values<aidl::android::hardware::audio::effect::Flags::Type> = {
  aidl::android::hardware::audio::effect::Flags::Type::INSERT,
  aidl::android::hardware::audio::effect::Flags::Type::AUXILIARY,
  aidl::android::hardware::audio::effect::Flags::Type::REPLACE,
  aidl::android::hardware::audio::effect::Flags::Type::PRE_PROC,
  aidl::android::hardware::audio::effect::Flags::Type::POST_PROC,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
[[nodiscard]] static inline std::string toString(Flags::Insert val) {
  switch(val) {
  case Flags::Insert::ANY:
    return "ANY";
  case Flags::Insert::FIRST:
    return "FIRST";
  case Flags::Insert::LAST:
    return "LAST";
  case Flags::Insert::EXCLUSIVE:
    return "EXCLUSIVE";
  default:
    return std::to_string(static_cast<int8_t>(val));
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
constexpr inline std::array<aidl::android::hardware::audio::effect::Flags::Insert, 4> enum_values<aidl::android::hardware::audio::effect::Flags::Insert> = {
  aidl::android::hardware::audio::effect::Flags::Insert::ANY,
  aidl::android::hardware::audio::effect::Flags::Insert::FIRST,
  aidl::android::hardware::audio::effect::Flags::Insert::LAST,
  aidl::android::hardware::audio::effect::Flags::Insert::EXCLUSIVE,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
[[nodiscard]] static inline std::string toString(Flags::Volume val) {
  switch(val) {
  case Flags::Volume::NONE:
    return "NONE";
  case Flags::Volume::CTRL:
    return "CTRL";
  case Flags::Volume::IND:
    return "IND";
  case Flags::Volume::MONITOR:
    return "MONITOR";
  default:
    return std::to_string(static_cast<int8_t>(val));
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
constexpr inline std::array<aidl::android::hardware::audio::effect::Flags::Volume, 4> enum_values<aidl::android::hardware::audio::effect::Flags::Volume> = {
  aidl::android::hardware::audio::effect::Flags::Volume::NONE,
  aidl::android::hardware::audio::effect::Flags::Volume::CTRL,
  aidl::android::hardware::audio::effect::Flags::Volume::IND,
  aidl::android::hardware::audio::effect::Flags::Volume::MONITOR,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
[[nodiscard]] static inline std::string toString(Flags::HardwareAccelerator val) {
  switch(val) {
  case Flags::HardwareAccelerator::NONE:
    return "NONE";
  case Flags::HardwareAccelerator::SIMPLE:
    return "SIMPLE";
  case Flags::HardwareAccelerator::TUNNEL:
    return "TUNNEL";
  default:
    return std::to_string(static_cast<int8_t>(val));
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
constexpr inline std::array<aidl::android::hardware::audio::effect::Flags::HardwareAccelerator, 3> enum_values<aidl::android::hardware::audio::effect::Flags::HardwareAccelerator> = {
  aidl::android::hardware::audio::effect::Flags::HardwareAccelerator::NONE,
  aidl::android::hardware::audio::effect::Flags::HardwareAccelerator::SIMPLE,
  aidl::android::hardware::audio::effect::Flags::HardwareAccelerator::TUNNEL,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
