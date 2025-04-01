/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Descriptor.aidl
 */
#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#include <aidl/android/hardware/audio/effect/Capability.h>
#include <aidl/android/hardware/audio/effect/Descriptor.h>
#include <aidl/android/hardware/audio/effect/Flags.h>
#include <aidl/android/media/audio/common/AudioUuid.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::hardware::audio::effect {
class Capability;
class Flags;
}  // namespace aidl::android::hardware::audio::effect
namespace aidl::android::media::audio::common {
class AudioUuid;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
class Descriptor {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  class Identity {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::media::audio::common::AudioUuid type;
    ::aidl::android::media::audio::common::AudioUuid uuid;
    std::optional<::aidl::android::media::audio::common::AudioUuid> proxy;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const Identity& _rhs) const {
      return std::tie(type, uuid, proxy) == std::tie(_rhs.type, _rhs.uuid, _rhs.proxy);
    }
    inline bool operator<(const Identity& _rhs) const {
      return std::tie(type, uuid, proxy) < std::tie(_rhs.type, _rhs.uuid, _rhs.proxy);
    }
    inline bool operator!=(const Identity& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const Identity& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const Identity& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const Identity& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "Identity{";
      _aidl_os << "type: " << ::android::internal::ToString(type);
      _aidl_os << ", uuid: " << ::android::internal::ToString(uuid);
      _aidl_os << ", proxy: " << ::android::internal::ToString(proxy);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class Common {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::audio::effect::Descriptor::Identity id;
    ::aidl::android::hardware::audio::effect::Flags flags;
    int32_t cpuLoad = 0;
    int32_t memoryUsage = 0;
    std::string name;
    std::string implementor;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const Common& _rhs) const {
      return std::tie(id, flags, cpuLoad, memoryUsage, name, implementor) == std::tie(_rhs.id, _rhs.flags, _rhs.cpuLoad, _rhs.memoryUsage, _rhs.name, _rhs.implementor);
    }
    inline bool operator<(const Common& _rhs) const {
      return std::tie(id, flags, cpuLoad, memoryUsage, name, implementor) < std::tie(_rhs.id, _rhs.flags, _rhs.cpuLoad, _rhs.memoryUsage, _rhs.name, _rhs.implementor);
    }
    inline bool operator!=(const Common& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const Common& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const Common& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const Common& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "Common{";
      _aidl_os << "id: " << ::android::internal::ToString(id);
      _aidl_os << ", flags: " << ::android::internal::ToString(flags);
      _aidl_os << ", cpuLoad: " << ::android::internal::ToString(cpuLoad);
      _aidl_os << ", memoryUsage: " << ::android::internal::ToString(memoryUsage);
      _aidl_os << ", name: " << ::android::internal::ToString(name);
      _aidl_os << ", implementor: " << ::android::internal::ToString(implementor);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  ::aidl::android::hardware::audio::effect::Descriptor::Common common;
  ::aidl::android::hardware::audio::effect::Capability capability;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const Descriptor& _rhs) const {
    return std::tie(common, capability) == std::tie(_rhs.common, _rhs.capability);
  }
  inline bool operator<(const Descriptor& _rhs) const {
    return std::tie(common, capability) < std::tie(_rhs.common, _rhs.capability);
  }
  inline bool operator!=(const Descriptor& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const Descriptor& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const Descriptor& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const Descriptor& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  static const char* EFFECT_TYPE_UUID_AEC;
  static const char* EFFECT_TYPE_UUID_AGC1;
  static const char* EFFECT_TYPE_UUID_AGC2;
  static const char* EFFECT_TYPE_UUID_BASS_BOOST;
  static const char* EFFECT_TYPE_UUID_DOWNMIX;
  static const char* EFFECT_TYPE_UUID_DYNAMICS_PROCESSING;
  static const char* EFFECT_TYPE_UUID_ENV_REVERB;
  static const char* EFFECT_TYPE_UUID_EQUALIZER;
  static const char* EFFECT_TYPE_UUID_ERASER;
  static const char* EFFECT_TYPE_UUID_HAPTIC_GENERATOR;
  static const char* EFFECT_TYPE_UUID_LOUDNESS_ENHANCER;
  static const char* EFFECT_TYPE_UUID_NS;
  static const char* EFFECT_TYPE_UUID_PRESET_REVERB;
  static const char* EFFECT_TYPE_UUID_SPATIALIZER;
  static const char* EFFECT_TYPE_UUID_VIRTUALIZER;
  static const char* EFFECT_TYPE_UUID_VISUALIZER;
  static const char* EFFECT_TYPE_UUID_VOLUME;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "Descriptor{";
    _aidl_os << "common: " << ::android::internal::ToString(common);
    _aidl_os << ", capability: " << ::android::internal::ToString(capability);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
