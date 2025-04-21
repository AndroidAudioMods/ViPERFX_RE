/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Range.aidl
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
#include <aidl/android/hardware/audio/effect/AcousticEchoCanceler.h>
#include <aidl/android/hardware/audio/effect/AutomaticGainControlV1.h>
#include <aidl/android/hardware/audio/effect/AutomaticGainControlV2.h>
#include <aidl/android/hardware/audio/effect/BassBoost.h>
#include <aidl/android/hardware/audio/effect/Downmix.h>
#include <aidl/android/hardware/audio/effect/DynamicsProcessing.h>
#include <aidl/android/hardware/audio/effect/EnvironmentalReverb.h>
#include <aidl/android/hardware/audio/effect/Equalizer.h>
#include <aidl/android/hardware/audio/effect/HapticGenerator.h>
#include <aidl/android/hardware/audio/effect/LoudnessEnhancer.h>
#include <aidl/android/hardware/audio/effect/NoiseSuppression.h>
#include <aidl/android/hardware/audio/effect/PresetReverb.h>
#include <aidl/android/hardware/audio/effect/Range.h>
#include <aidl/android/hardware/audio/effect/Spatializer.h>
#include <aidl/android/hardware/audio/effect/VendorExtension.h>
#include <aidl/android/hardware/audio/effect/Virtualizer.h>
#include <aidl/android/hardware/audio/effect/Visualizer.h>
#include <aidl/android/hardware/audio/effect/Volume.h>
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
class Range {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  class AcousticEchoCancelerRange {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::audio::effect::AcousticEchoCanceler min;
    ::aidl::android::hardware::audio::effect::AcousticEchoCanceler max;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const AcousticEchoCancelerRange& _rhs) const {
      return std::tie(min, max) == std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator<(const AcousticEchoCancelerRange& _rhs) const {
      return std::tie(min, max) < std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator!=(const AcousticEchoCancelerRange& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const AcousticEchoCancelerRange& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const AcousticEchoCancelerRange& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const AcousticEchoCancelerRange& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "AcousticEchoCancelerRange{";
      _aidl_os << "min: " << ::android::internal::ToString(min);
      _aidl_os << ", max: " << ::android::internal::ToString(max);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class AutomaticGainControlV1Range {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::audio::effect::AutomaticGainControlV1 min;
    ::aidl::android::hardware::audio::effect::AutomaticGainControlV1 max;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const AutomaticGainControlV1Range& _rhs) const {
      return std::tie(min, max) == std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator<(const AutomaticGainControlV1Range& _rhs) const {
      return std::tie(min, max) < std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator!=(const AutomaticGainControlV1Range& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const AutomaticGainControlV1Range& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const AutomaticGainControlV1Range& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const AutomaticGainControlV1Range& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "AutomaticGainControlV1Range{";
      _aidl_os << "min: " << ::android::internal::ToString(min);
      _aidl_os << ", max: " << ::android::internal::ToString(max);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class AutomaticGainControlV2Range {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::audio::effect::AutomaticGainControlV2 min;
    ::aidl::android::hardware::audio::effect::AutomaticGainControlV2 max;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const AutomaticGainControlV2Range& _rhs) const {
      return std::tie(min, max) == std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator<(const AutomaticGainControlV2Range& _rhs) const {
      return std::tie(min, max) < std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator!=(const AutomaticGainControlV2Range& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const AutomaticGainControlV2Range& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const AutomaticGainControlV2Range& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const AutomaticGainControlV2Range& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "AutomaticGainControlV2Range{";
      _aidl_os << "min: " << ::android::internal::ToString(min);
      _aidl_os << ", max: " << ::android::internal::ToString(max);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class BassBoostRange {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::audio::effect::BassBoost min;
    ::aidl::android::hardware::audio::effect::BassBoost max;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const BassBoostRange& _rhs) const {
      return std::tie(min, max) == std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator<(const BassBoostRange& _rhs) const {
      return std::tie(min, max) < std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator!=(const BassBoostRange& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const BassBoostRange& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const BassBoostRange& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const BassBoostRange& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "BassBoostRange{";
      _aidl_os << "min: " << ::android::internal::ToString(min);
      _aidl_os << ", max: " << ::android::internal::ToString(max);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class DownmixRange {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::audio::effect::Downmix min;
    ::aidl::android::hardware::audio::effect::Downmix max;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const DownmixRange& _rhs) const {
      return std::tie(min, max) == std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator<(const DownmixRange& _rhs) const {
      return std::tie(min, max) < std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator!=(const DownmixRange& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const DownmixRange& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const DownmixRange& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const DownmixRange& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "DownmixRange{";
      _aidl_os << "min: " << ::android::internal::ToString(min);
      _aidl_os << ", max: " << ::android::internal::ToString(max);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class DynamicsProcessingRange {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::audio::effect::DynamicsProcessing min;
    ::aidl::android::hardware::audio::effect::DynamicsProcessing max;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const DynamicsProcessingRange& _rhs) const {
      return std::tie(min, max) == std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator<(const DynamicsProcessingRange& _rhs) const {
      return std::tie(min, max) < std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator!=(const DynamicsProcessingRange& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const DynamicsProcessingRange& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const DynamicsProcessingRange& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const DynamicsProcessingRange& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "DynamicsProcessingRange{";
      _aidl_os << "min: " << ::android::internal::ToString(min);
      _aidl_os << ", max: " << ::android::internal::ToString(max);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class EnvironmentalReverbRange {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::audio::effect::EnvironmentalReverb min;
    ::aidl::android::hardware::audio::effect::EnvironmentalReverb max;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const EnvironmentalReverbRange& _rhs) const {
      return std::tie(min, max) == std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator<(const EnvironmentalReverbRange& _rhs) const {
      return std::tie(min, max) < std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator!=(const EnvironmentalReverbRange& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const EnvironmentalReverbRange& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const EnvironmentalReverbRange& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const EnvironmentalReverbRange& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "EnvironmentalReverbRange{";
      _aidl_os << "min: " << ::android::internal::ToString(min);
      _aidl_os << ", max: " << ::android::internal::ToString(max);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class EqualizerRange {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::audio::effect::Equalizer min;
    ::aidl::android::hardware::audio::effect::Equalizer max;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const EqualizerRange& _rhs) const {
      return std::tie(min, max) == std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator<(const EqualizerRange& _rhs) const {
      return std::tie(min, max) < std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator!=(const EqualizerRange& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const EqualizerRange& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const EqualizerRange& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const EqualizerRange& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "EqualizerRange{";
      _aidl_os << "min: " << ::android::internal::ToString(min);
      _aidl_os << ", max: " << ::android::internal::ToString(max);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class HapticGeneratorRange {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::audio::effect::HapticGenerator min;
    ::aidl::android::hardware::audio::effect::HapticGenerator max;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const HapticGeneratorRange& _rhs) const {
      return std::tie(min, max) == std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator<(const HapticGeneratorRange& _rhs) const {
      return std::tie(min, max) < std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator!=(const HapticGeneratorRange& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const HapticGeneratorRange& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const HapticGeneratorRange& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const HapticGeneratorRange& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "HapticGeneratorRange{";
      _aidl_os << "min: " << ::android::internal::ToString(min);
      _aidl_os << ", max: " << ::android::internal::ToString(max);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class LoudnessEnhancerRange {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::audio::effect::LoudnessEnhancer min;
    ::aidl::android::hardware::audio::effect::LoudnessEnhancer max;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const LoudnessEnhancerRange& _rhs) const {
      return std::tie(min, max) == std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator<(const LoudnessEnhancerRange& _rhs) const {
      return std::tie(min, max) < std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator!=(const LoudnessEnhancerRange& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const LoudnessEnhancerRange& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const LoudnessEnhancerRange& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const LoudnessEnhancerRange& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "LoudnessEnhancerRange{";
      _aidl_os << "min: " << ::android::internal::ToString(min);
      _aidl_os << ", max: " << ::android::internal::ToString(max);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class NoiseSuppressionRange {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::audio::effect::NoiseSuppression min;
    ::aidl::android::hardware::audio::effect::NoiseSuppression max;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const NoiseSuppressionRange& _rhs) const {
      return std::tie(min, max) == std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator<(const NoiseSuppressionRange& _rhs) const {
      return std::tie(min, max) < std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator!=(const NoiseSuppressionRange& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const NoiseSuppressionRange& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const NoiseSuppressionRange& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const NoiseSuppressionRange& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "NoiseSuppressionRange{";
      _aidl_os << "min: " << ::android::internal::ToString(min);
      _aidl_os << ", max: " << ::android::internal::ToString(max);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class PresetReverbRange {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::audio::effect::PresetReverb min;
    ::aidl::android::hardware::audio::effect::PresetReverb max;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const PresetReverbRange& _rhs) const {
      return std::tie(min, max) == std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator<(const PresetReverbRange& _rhs) const {
      return std::tie(min, max) < std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator!=(const PresetReverbRange& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const PresetReverbRange& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const PresetReverbRange& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const PresetReverbRange& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "PresetReverbRange{";
      _aidl_os << "min: " << ::android::internal::ToString(min);
      _aidl_os << ", max: " << ::android::internal::ToString(max);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class SpatializerRange {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::audio::effect::Spatializer min;
    ::aidl::android::hardware::audio::effect::Spatializer max;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const SpatializerRange& _rhs) const {
      return std::tie(min, max) == std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator<(const SpatializerRange& _rhs) const {
      return std::tie(min, max) < std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator!=(const SpatializerRange& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const SpatializerRange& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const SpatializerRange& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const SpatializerRange& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "SpatializerRange{";
      _aidl_os << "min: " << ::android::internal::ToString(min);
      _aidl_os << ", max: " << ::android::internal::ToString(max);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class VendorExtensionRange {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::audio::effect::VendorExtension min;
    ::aidl::android::hardware::audio::effect::VendorExtension max;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const VendorExtensionRange& _rhs) const {
      return std::tie(min, max) == std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator<(const VendorExtensionRange& _rhs) const {
      return std::tie(min, max) < std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator!=(const VendorExtensionRange& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const VendorExtensionRange& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const VendorExtensionRange& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const VendorExtensionRange& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "VendorExtensionRange{";
      _aidl_os << "min: " << ::android::internal::ToString(min);
      _aidl_os << ", max: " << ::android::internal::ToString(max);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class VirtualizerRange {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::audio::effect::Virtualizer min;
    ::aidl::android::hardware::audio::effect::Virtualizer max;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const VirtualizerRange& _rhs) const {
      return std::tie(min, max) == std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator<(const VirtualizerRange& _rhs) const {
      return std::tie(min, max) < std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator!=(const VirtualizerRange& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const VirtualizerRange& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const VirtualizerRange& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const VirtualizerRange& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "VirtualizerRange{";
      _aidl_os << "min: " << ::android::internal::ToString(min);
      _aidl_os << ", max: " << ::android::internal::ToString(max);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class VisualizerRange {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::audio::effect::Visualizer min;
    ::aidl::android::hardware::audio::effect::Visualizer max;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const VisualizerRange& _rhs) const {
      return std::tie(min, max) == std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator<(const VisualizerRange& _rhs) const {
      return std::tie(min, max) < std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator!=(const VisualizerRange& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const VisualizerRange& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const VisualizerRange& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const VisualizerRange& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "VisualizerRange{";
      _aidl_os << "min: " << ::android::internal::ToString(min);
      _aidl_os << ", max: " << ::android::internal::ToString(max);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class VolumeRange {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::audio::effect::Volume min;
    ::aidl::android::hardware::audio::effect::Volume max;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const VolumeRange& _rhs) const {
      return std::tie(min, max) == std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator<(const VolumeRange& _rhs) const {
      return std::tie(min, max) < std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator!=(const VolumeRange& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const VolumeRange& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const VolumeRange& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const VolumeRange& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "VolumeRange{";
      _aidl_os << "min: " << ::android::internal::ToString(min);
      _aidl_os << ", max: " << ::android::internal::ToString(max);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  enum class Tag : int32_t {
    vendorExtension = 0,
    acousticEchoCanceler = 1,
    automaticGainControlV1 = 2,
    automaticGainControlV2 = 3,
    bassBoost = 4,
    downmix = 5,
    dynamicsProcessing = 6,
    environmentalReverb = 7,
    equalizer = 8,
    hapticGenerator = 9,
    loudnessEnhancer = 10,
    noiseSuppression = 11,
    presetReverb = 12,
    virtualizer = 13,
    visualizer = 14,
    volume = 15,
    spatializer = 16,
  };

  // Expose tag symbols for legacy code
  static const inline Tag vendorExtension = Tag::vendorExtension;
  static const inline Tag acousticEchoCanceler = Tag::acousticEchoCanceler;
  static const inline Tag automaticGainControlV1 = Tag::automaticGainControlV1;
  static const inline Tag automaticGainControlV2 = Tag::automaticGainControlV2;
  static const inline Tag bassBoost = Tag::bassBoost;
  static const inline Tag downmix = Tag::downmix;
  static const inline Tag dynamicsProcessing = Tag::dynamicsProcessing;
  static const inline Tag environmentalReverb = Tag::environmentalReverb;
  static const inline Tag equalizer = Tag::equalizer;
  static const inline Tag hapticGenerator = Tag::hapticGenerator;
  static const inline Tag loudnessEnhancer = Tag::loudnessEnhancer;
  static const inline Tag noiseSuppression = Tag::noiseSuppression;
  static const inline Tag presetReverb = Tag::presetReverb;
  static const inline Tag virtualizer = Tag::virtualizer;
  static const inline Tag visualizer = Tag::visualizer;
  static const inline Tag volume = Tag::volume;
  static const inline Tag spatializer = Tag::spatializer;

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, Range>;

  Range() : _value(std::in_place_index<static_cast<size_t>(vendorExtension)>, std::vector<::aidl::android::hardware::audio::effect::Range::VendorExtensionRange>({})) { }

  template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr Range(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit Range(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static Range make(_Tp&&... _args) {
    return Range(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static Range make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return Range(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

  inline bool operator==(const Range& _rhs) const {
    return _value == _rhs._value;
  }
  inline bool operator<(const Range& _rhs) const {
    return _value < _rhs._value;
  }
  inline bool operator!=(const Range& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const Range& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const Range& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const Range& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "Range{";
    switch (getTag()) {
    case vendorExtension: os << "vendorExtension: " << ::android::internal::ToString(get<vendorExtension>()); break;
    case acousticEchoCanceler: os << "acousticEchoCanceler: " << ::android::internal::ToString(get<acousticEchoCanceler>()); break;
    case automaticGainControlV1: os << "automaticGainControlV1: " << ::android::internal::ToString(get<automaticGainControlV1>()); break;
    case automaticGainControlV2: os << "automaticGainControlV2: " << ::android::internal::ToString(get<automaticGainControlV2>()); break;
    case bassBoost: os << "bassBoost: " << ::android::internal::ToString(get<bassBoost>()); break;
    case downmix: os << "downmix: " << ::android::internal::ToString(get<downmix>()); break;
    case dynamicsProcessing: os << "dynamicsProcessing: " << ::android::internal::ToString(get<dynamicsProcessing>()); break;
    case environmentalReverb: os << "environmentalReverb: " << ::android::internal::ToString(get<environmentalReverb>()); break;
    case equalizer: os << "equalizer: " << ::android::internal::ToString(get<equalizer>()); break;
    case hapticGenerator: os << "hapticGenerator: " << ::android::internal::ToString(get<hapticGenerator>()); break;
    case loudnessEnhancer: os << "loudnessEnhancer: " << ::android::internal::ToString(get<loudnessEnhancer>()); break;
    case noiseSuppression: os << "noiseSuppression: " << ::android::internal::ToString(get<noiseSuppression>()); break;
    case presetReverb: os << "presetReverb: " << ::android::internal::ToString(get<presetReverb>()); break;
    case virtualizer: os << "virtualizer: " << ::android::internal::ToString(get<virtualizer>()); break;
    case visualizer: os << "visualizer: " << ::android::internal::ToString(get<visualizer>()); break;
    case volume: os << "volume: " << ::android::internal::ToString(get<volume>()); break;
    case spatializer: os << "spatializer: " << ::android::internal::ToString(get<spatializer>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<std::vector<::aidl::android::hardware::audio::effect::Range::VendorExtensionRange>, std::vector<::aidl::android::hardware::audio::effect::Range::AcousticEchoCancelerRange>, std::vector<::aidl::android::hardware::audio::effect::Range::AutomaticGainControlV1Range>, std::vector<::aidl::android::hardware::audio::effect::Range::AutomaticGainControlV2Range>, std::vector<::aidl::android::hardware::audio::effect::Range::BassBoostRange>, std::vector<::aidl::android::hardware::audio::effect::Range::DownmixRange>, std::vector<::aidl::android::hardware::audio::effect::Range::DynamicsProcessingRange>, std::vector<::aidl::android::hardware::audio::effect::Range::EnvironmentalReverbRange>, std::vector<::aidl::android::hardware::audio::effect::Range::EqualizerRange>, std::vector<::aidl::android::hardware::audio::effect::Range::HapticGeneratorRange>, std::vector<::aidl::android::hardware::audio::effect::Range::LoudnessEnhancerRange>, std::vector<::aidl::android::hardware::audio::effect::Range::NoiseSuppressionRange>, std::vector<::aidl::android::hardware::audio::effect::Range::PresetReverbRange>, std::vector<::aidl::android::hardware::audio::effect::Range::VirtualizerRange>, std::vector<::aidl::android::hardware::audio::effect::Range::VisualizerRange>, std::vector<::aidl::android::hardware::audio::effect::Range::VolumeRange>, std::vector<::aidl::android::hardware::audio::effect::Range::SpatializerRange>> _value;
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
[[nodiscard]] static inline std::string toString(Range::Tag val) {
  switch(val) {
  case Range::Tag::vendorExtension:
    return "vendorExtension";
  case Range::Tag::acousticEchoCanceler:
    return "acousticEchoCanceler";
  case Range::Tag::automaticGainControlV1:
    return "automaticGainControlV1";
  case Range::Tag::automaticGainControlV2:
    return "automaticGainControlV2";
  case Range::Tag::bassBoost:
    return "bassBoost";
  case Range::Tag::downmix:
    return "downmix";
  case Range::Tag::dynamicsProcessing:
    return "dynamicsProcessing";
  case Range::Tag::environmentalReverb:
    return "environmentalReverb";
  case Range::Tag::equalizer:
    return "equalizer";
  case Range::Tag::hapticGenerator:
    return "hapticGenerator";
  case Range::Tag::loudnessEnhancer:
    return "loudnessEnhancer";
  case Range::Tag::noiseSuppression:
    return "noiseSuppression";
  case Range::Tag::presetReverb:
    return "presetReverb";
  case Range::Tag::virtualizer:
    return "virtualizer";
  case Range::Tag::visualizer:
    return "visualizer";
  case Range::Tag::volume:
    return "volume";
  case Range::Tag::spatializer:
    return "spatializer";
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
constexpr inline std::array<aidl::android::hardware::audio::effect::Range::Tag, 17> enum_values<aidl::android::hardware::audio::effect::Range::Tag> = {
  aidl::android::hardware::audio::effect::Range::Tag::vendorExtension,
  aidl::android::hardware::audio::effect::Range::Tag::acousticEchoCanceler,
  aidl::android::hardware::audio::effect::Range::Tag::automaticGainControlV1,
  aidl::android::hardware::audio::effect::Range::Tag::automaticGainControlV2,
  aidl::android::hardware::audio::effect::Range::Tag::bassBoost,
  aidl::android::hardware::audio::effect::Range::Tag::downmix,
  aidl::android::hardware::audio::effect::Range::Tag::dynamicsProcessing,
  aidl::android::hardware::audio::effect::Range::Tag::environmentalReverb,
  aidl::android::hardware::audio::effect::Range::Tag::equalizer,
  aidl::android::hardware::audio::effect::Range::Tag::hapticGenerator,
  aidl::android::hardware::audio::effect::Range::Tag::loudnessEnhancer,
  aidl::android::hardware::audio::effect::Range::Tag::noiseSuppression,
  aidl::android::hardware::audio::effect::Range::Tag::presetReverb,
  aidl::android::hardware::audio::effect::Range::Tag::virtualizer,
  aidl::android::hardware::audio::effect::Range::Tag::visualizer,
  aidl::android::hardware::audio::effect::Range::Tag::volume,
  aidl::android::hardware::audio::effect::Range::Tag::spatializer,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
