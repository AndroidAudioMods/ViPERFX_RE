/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Parameter.aidl
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
#include <aidl/android/hardware/audio/common/SinkMetadata.h>
#include <aidl/android/hardware/audio/common/SourceMetadata.h>
#include <aidl/android/hardware/audio/effect/AcousticEchoCanceler.h>
#include <aidl/android/hardware/audio/effect/AutomaticGainControlV1.h>
#include <aidl/android/hardware/audio/effect/AutomaticGainControlV2.h>
#include <aidl/android/hardware/audio/effect/BassBoost.h>
#include <aidl/android/hardware/audio/effect/Downmix.h>
#include <aidl/android/hardware/audio/effect/DynamicsProcessing.h>
#include <aidl/android/hardware/audio/effect/EnvironmentalReverb.h>
#include <aidl/android/hardware/audio/effect/Equalizer.h>
#include <aidl/android/hardware/audio/effect/Eraser.h>
#include <aidl/android/hardware/audio/effect/HapticGenerator.h>
#include <aidl/android/hardware/audio/effect/LoudnessEnhancer.h>
#include <aidl/android/hardware/audio/effect/NoiseSuppression.h>
#include <aidl/android/hardware/audio/effect/Parameter.h>
#include <aidl/android/hardware/audio/effect/PresetReverb.h>
#include <aidl/android/hardware/audio/effect/Spatializer.h>
#include <aidl/android/hardware/audio/effect/VendorExtension.h>
#include <aidl/android/hardware/audio/effect/Virtualizer.h>
#include <aidl/android/hardware/audio/effect/Visualizer.h>
#include <aidl/android/hardware/audio/effect/Volume.h>
#include <aidl/android/media/audio/common/AudioConfig.h>
#include <aidl/android/media/audio/common/AudioDeviceDescription.h>
#include <aidl/android/media/audio/common/AudioMode.h>
#include <aidl/android/media/audio/common/AudioSource.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

#ifndef __BIONIC__
#define __assert2(a,b,c,d) ((void)0)
#endif

namespace aidl::android::hardware::audio::common {
class SinkMetadata;
class SourceMetadata;
}  // namespace aidl::android::hardware::audio::common
namespace aidl::android::hardware::audio::effect {
class VendorExtension;
}  // namespace aidl::android::hardware::audio::effect
namespace aidl::android::media::audio::common {
class AudioConfig;
class AudioDeviceDescription;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
class Parameter {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class Tag : int32_t {
    common = 0,
    deviceDescription = 1,
    mode = 2,
    source = 3,
    offload = 4,
    volumeStereo = 5,
    specific = 6,
    sinkMetadata = 7,
    sourceMetadata = 8,
  };

  class Id {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    enum class Tag : int32_t {
      vendorEffectTag = 0,
      acousticEchoCancelerTag = 1,
      automaticGainControlV1Tag = 2,
      automaticGainControlV2Tag = 3,
      bassBoostTag = 4,
      downmixTag = 5,
      dynamicsProcessingTag = 6,
      environmentalReverbTag = 7,
      equalizerTag = 8,
      hapticGeneratorTag = 9,
      loudnessEnhancerTag = 10,
      noiseSuppressionTag = 11,
      presetReverbTag = 12,
      virtualizerTag = 13,
      visualizerTag = 14,
      volumeTag = 15,
      commonTag = 16,
      spatializerTag = 17,
      eraserTag = 18,
    };

    // Expose tag symbols for legacy code
    static const inline Tag vendorEffectTag = Tag::vendorEffectTag;
    static const inline Tag acousticEchoCancelerTag = Tag::acousticEchoCancelerTag;
    static const inline Tag automaticGainControlV1Tag = Tag::automaticGainControlV1Tag;
    static const inline Tag automaticGainControlV2Tag = Tag::automaticGainControlV2Tag;
    static const inline Tag bassBoostTag = Tag::bassBoostTag;
    static const inline Tag downmixTag = Tag::downmixTag;
    static const inline Tag dynamicsProcessingTag = Tag::dynamicsProcessingTag;
    static const inline Tag environmentalReverbTag = Tag::environmentalReverbTag;
    static const inline Tag equalizerTag = Tag::equalizerTag;
    static const inline Tag hapticGeneratorTag = Tag::hapticGeneratorTag;
    static const inline Tag loudnessEnhancerTag = Tag::loudnessEnhancerTag;
    static const inline Tag noiseSuppressionTag = Tag::noiseSuppressionTag;
    static const inline Tag presetReverbTag = Tag::presetReverbTag;
    static const inline Tag virtualizerTag = Tag::virtualizerTag;
    static const inline Tag visualizerTag = Tag::visualizerTag;
    static const inline Tag volumeTag = Tag::volumeTag;
    static const inline Tag commonTag = Tag::commonTag;
    static const inline Tag spatializerTag = Tag::spatializerTag;
    static const inline Tag eraserTag = Tag::eraserTag;

    template<typename _Tp>
    static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, Id>;

    Id() : _value(std::in_place_index<static_cast<size_t>(vendorEffectTag)>, ::aidl::android::hardware::audio::effect::VendorExtension()) { }

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
      case vendorEffectTag: os << "vendorEffectTag: " << ::android::internal::ToString(get<vendorEffectTag>()); break;
      case acousticEchoCancelerTag: os << "acousticEchoCancelerTag: " << ::android::internal::ToString(get<acousticEchoCancelerTag>()); break;
      case automaticGainControlV1Tag: os << "automaticGainControlV1Tag: " << ::android::internal::ToString(get<automaticGainControlV1Tag>()); break;
      case automaticGainControlV2Tag: os << "automaticGainControlV2Tag: " << ::android::internal::ToString(get<automaticGainControlV2Tag>()); break;
      case bassBoostTag: os << "bassBoostTag: " << ::android::internal::ToString(get<bassBoostTag>()); break;
      case downmixTag: os << "downmixTag: " << ::android::internal::ToString(get<downmixTag>()); break;
      case dynamicsProcessingTag: os << "dynamicsProcessingTag: " << ::android::internal::ToString(get<dynamicsProcessingTag>()); break;
      case environmentalReverbTag: os << "environmentalReverbTag: " << ::android::internal::ToString(get<environmentalReverbTag>()); break;
      case equalizerTag: os << "equalizerTag: " << ::android::internal::ToString(get<equalizerTag>()); break;
      case hapticGeneratorTag: os << "hapticGeneratorTag: " << ::android::internal::ToString(get<hapticGeneratorTag>()); break;
      case loudnessEnhancerTag: os << "loudnessEnhancerTag: " << ::android::internal::ToString(get<loudnessEnhancerTag>()); break;
      case noiseSuppressionTag: os << "noiseSuppressionTag: " << ::android::internal::ToString(get<noiseSuppressionTag>()); break;
      case presetReverbTag: os << "presetReverbTag: " << ::android::internal::ToString(get<presetReverbTag>()); break;
      case virtualizerTag: os << "virtualizerTag: " << ::android::internal::ToString(get<virtualizerTag>()); break;
      case visualizerTag: os << "visualizerTag: " << ::android::internal::ToString(get<visualizerTag>()); break;
      case volumeTag: os << "volumeTag: " << ::android::internal::ToString(get<volumeTag>()); break;
      case commonTag: os << "commonTag: " << ::android::internal::ToString(get<commonTag>()); break;
      case spatializerTag: os << "spatializerTag: " << ::android::internal::ToString(get<spatializerTag>()); break;
      case eraserTag: os << "eraserTag: " << ::android::internal::ToString(get<eraserTag>()); break;
      }
      os << "}";
      return os.str();
    }
  private:
    std::variant<::aidl::android::hardware::audio::effect::VendorExtension, ::aidl::android::hardware::audio::effect::AcousticEchoCanceler::Id, ::aidl::android::hardware::audio::effect::AutomaticGainControlV1::Id, ::aidl::android::hardware::audio::effect::AutomaticGainControlV2::Id, ::aidl::android::hardware::audio::effect::BassBoost::Id, ::aidl::android::hardware::audio::effect::Downmix::Id, ::aidl::android::hardware::audio::effect::DynamicsProcessing::Id, ::aidl::android::hardware::audio::effect::EnvironmentalReverb::Id, ::aidl::android::hardware::audio::effect::Equalizer::Id, ::aidl::android::hardware::audio::effect::HapticGenerator::Id, ::aidl::android::hardware::audio::effect::LoudnessEnhancer::Id, ::aidl::android::hardware::audio::effect::NoiseSuppression::Id, ::aidl::android::hardware::audio::effect::PresetReverb::Id, ::aidl::android::hardware::audio::effect::Virtualizer::Id, ::aidl::android::hardware::audio::effect::Visualizer::Id, ::aidl::android::hardware::audio::effect::Volume::Id, ::aidl::android::hardware::audio::effect::Parameter::Tag, ::aidl::android::hardware::audio::effect::Spatializer::Id, ::aidl::android::hardware::audio::effect::Eraser::Id> _value;
  };
  class Common {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t session = 0;
    int32_t ioHandle = 0;
    ::aidl::android::media::audio::common::AudioConfig input;
    ::aidl::android::media::audio::common::AudioConfig output;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const Common& _rhs) const {
      return std::tie(session, ioHandle, input, output) == std::tie(_rhs.session, _rhs.ioHandle, _rhs.input, _rhs.output);
    }
    inline bool operator<(const Common& _rhs) const {
      return std::tie(session, ioHandle, input, output) < std::tie(_rhs.session, _rhs.ioHandle, _rhs.input, _rhs.output);
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
      _aidl_os << "session: " << ::android::internal::ToString(session);
      _aidl_os << ", ioHandle: " << ::android::internal::ToString(ioHandle);
      _aidl_os << ", input: " << ::android::internal::ToString(input);
      _aidl_os << ", output: " << ::android::internal::ToString(output);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class VolumeStereo {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    float left = 0.000000f;
    float right = 0.000000f;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const VolumeStereo& _rhs) const {
      return std::tie(left, right) == std::tie(_rhs.left, _rhs.right);
    }
    inline bool operator<(const VolumeStereo& _rhs) const {
      return std::tie(left, right) < std::tie(_rhs.left, _rhs.right);
    }
    inline bool operator!=(const VolumeStereo& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const VolumeStereo& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const VolumeStereo& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const VolumeStereo& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "VolumeStereo{";
      _aidl_os << "left: " << ::android::internal::ToString(left);
      _aidl_os << ", right: " << ::android::internal::ToString(right);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class Specific {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    enum class Tag : int32_t {
      vendorEffect = 0,
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
      eraser = 17,
    };

    // Expose tag symbols for legacy code
    static const inline Tag vendorEffect = Tag::vendorEffect;
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
    static const inline Tag eraser = Tag::eraser;

    template<typename _Tp>
    static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, Specific>;

    Specific() : _value(std::in_place_index<static_cast<size_t>(vendorEffect)>, ::aidl::android::hardware::audio::effect::VendorExtension()) { }

    template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
    // NOLINTNEXTLINE(google-explicit-constructor)
    constexpr Specific(_Tp&& _arg)
        : _value(std::forward<_Tp>(_arg)) {}

    template <size_t _Np, typename... _Tp>
    constexpr explicit Specific(std::in_place_index_t<_Np>, _Tp&&... _args)
        : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

    template <Tag _tag, typename... _Tp>
    static Specific make(_Tp&&... _args) {
      return Specific(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
    }

    template <Tag _tag, typename _Tp, typename... _Up>
    static Specific make(std::initializer_list<_Tp> _il, _Up&&... _args) {
      return Specific(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

    inline bool operator==(const Specific& _rhs) const {
      return _value == _rhs._value;
    }
    inline bool operator<(const Specific& _rhs) const {
      return _value < _rhs._value;
    }
    inline bool operator!=(const Specific& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const Specific& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const Specific& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const Specific& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream os;
      os << "Specific{";
      switch (getTag()) {
      case vendorEffect: os << "vendorEffect: " << ::android::internal::ToString(get<vendorEffect>()); break;
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
      case eraser: os << "eraser: " << ::android::internal::ToString(get<eraser>()); break;
      }
      os << "}";
      return os.str();
    }
  private:
    std::variant<::aidl::android::hardware::audio::effect::VendorExtension, ::aidl::android::hardware::audio::effect::AcousticEchoCanceler, ::aidl::android::hardware::audio::effect::AutomaticGainControlV1, ::aidl::android::hardware::audio::effect::AutomaticGainControlV2, ::aidl::android::hardware::audio::effect::BassBoost, ::aidl::android::hardware::audio::effect::Downmix, ::aidl::android::hardware::audio::effect::DynamicsProcessing, ::aidl::android::hardware::audio::effect::EnvironmentalReverb, ::aidl::android::hardware::audio::effect::Equalizer, ::aidl::android::hardware::audio::effect::HapticGenerator, ::aidl::android::hardware::audio::effect::LoudnessEnhancer, ::aidl::android::hardware::audio::effect::NoiseSuppression, ::aidl::android::hardware::audio::effect::PresetReverb, ::aidl::android::hardware::audio::effect::Virtualizer, ::aidl::android::hardware::audio::effect::Visualizer, ::aidl::android::hardware::audio::effect::Volume, ::aidl::android::hardware::audio::effect::Spatializer, ::aidl::android::hardware::audio::effect::Eraser> _value;
  };
  // Expose tag symbols for legacy code
  static const inline Tag common = Tag::common;
  static const inline Tag deviceDescription = Tag::deviceDescription;
  static const inline Tag mode = Tag::mode;
  static const inline Tag source = Tag::source;
  static const inline Tag offload = Tag::offload;
  static const inline Tag volumeStereo = Tag::volumeStereo;
  static const inline Tag specific = Tag::specific;
  static const inline Tag sinkMetadata = Tag::sinkMetadata;
  static const inline Tag sourceMetadata = Tag::sourceMetadata;

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, Parameter>;

  Parameter() : _value(std::in_place_index<static_cast<size_t>(common)>, ::aidl::android::hardware::audio::effect::Parameter::Common()) { }

  template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr Parameter(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit Parameter(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static Parameter make(_Tp&&... _args) {
    return Parameter(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static Parameter make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return Parameter(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

  inline bool operator==(const Parameter& _rhs) const {
    return _value == _rhs._value;
  }
  inline bool operator<(const Parameter& _rhs) const {
    return _value < _rhs._value;
  }
  inline bool operator!=(const Parameter& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const Parameter& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const Parameter& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const Parameter& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "Parameter{";
    switch (getTag()) {
    case common: os << "common: " << ::android::internal::ToString(get<common>()); break;
    case deviceDescription: os << "deviceDescription: " << ::android::internal::ToString(get<deviceDescription>()); break;
    case mode: os << "mode: " << ::android::internal::ToString(get<mode>()); break;
    case source: os << "source: " << ::android::internal::ToString(get<source>()); break;
    case offload: os << "offload: " << ::android::internal::ToString(get<offload>()); break;
    case volumeStereo: os << "volumeStereo: " << ::android::internal::ToString(get<volumeStereo>()); break;
    case specific: os << "specific: " << ::android::internal::ToString(get<specific>()); break;
    case sinkMetadata: os << "sinkMetadata: " << ::android::internal::ToString(get<sinkMetadata>()); break;
    case sourceMetadata: os << "sourceMetadata: " << ::android::internal::ToString(get<sourceMetadata>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<::aidl::android::hardware::audio::effect::Parameter::Common, std::vector<::aidl::android::media::audio::common::AudioDeviceDescription>, ::aidl::android::media::audio::common::AudioMode, ::aidl::android::media::audio::common::AudioSource, bool, ::aidl::android::hardware::audio::effect::Parameter::VolumeStereo, ::aidl::android::hardware::audio::effect::Parameter::Specific, ::aidl::android::hardware::audio::common::SinkMetadata, ::aidl::android::hardware::audio::common::SourceMetadata> _value;
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
[[nodiscard]] static inline std::string toString(Parameter::Id::Tag val) {
  switch(val) {
  case Parameter::Id::Tag::vendorEffectTag:
    return "vendorEffectTag";
  case Parameter::Id::Tag::acousticEchoCancelerTag:
    return "acousticEchoCancelerTag";
  case Parameter::Id::Tag::automaticGainControlV1Tag:
    return "automaticGainControlV1Tag";
  case Parameter::Id::Tag::automaticGainControlV2Tag:
    return "automaticGainControlV2Tag";
  case Parameter::Id::Tag::bassBoostTag:
    return "bassBoostTag";
  case Parameter::Id::Tag::downmixTag:
    return "downmixTag";
  case Parameter::Id::Tag::dynamicsProcessingTag:
    return "dynamicsProcessingTag";
  case Parameter::Id::Tag::environmentalReverbTag:
    return "environmentalReverbTag";
  case Parameter::Id::Tag::equalizerTag:
    return "equalizerTag";
  case Parameter::Id::Tag::hapticGeneratorTag:
    return "hapticGeneratorTag";
  case Parameter::Id::Tag::loudnessEnhancerTag:
    return "loudnessEnhancerTag";
  case Parameter::Id::Tag::noiseSuppressionTag:
    return "noiseSuppressionTag";
  case Parameter::Id::Tag::presetReverbTag:
    return "presetReverbTag";
  case Parameter::Id::Tag::virtualizerTag:
    return "virtualizerTag";
  case Parameter::Id::Tag::visualizerTag:
    return "visualizerTag";
  case Parameter::Id::Tag::volumeTag:
    return "volumeTag";
  case Parameter::Id::Tag::commonTag:
    return "commonTag";
  case Parameter::Id::Tag::spatializerTag:
    return "spatializerTag";
  case Parameter::Id::Tag::eraserTag:
    return "eraserTag";
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
constexpr inline std::array<aidl::android::hardware::audio::effect::Parameter::Id::Tag, 19> enum_values<aidl::android::hardware::audio::effect::Parameter::Id::Tag> = {
  aidl::android::hardware::audio::effect::Parameter::Id::Tag::vendorEffectTag,
  aidl::android::hardware::audio::effect::Parameter::Id::Tag::acousticEchoCancelerTag,
  aidl::android::hardware::audio::effect::Parameter::Id::Tag::automaticGainControlV1Tag,
  aidl::android::hardware::audio::effect::Parameter::Id::Tag::automaticGainControlV2Tag,
  aidl::android::hardware::audio::effect::Parameter::Id::Tag::bassBoostTag,
  aidl::android::hardware::audio::effect::Parameter::Id::Tag::downmixTag,
  aidl::android::hardware::audio::effect::Parameter::Id::Tag::dynamicsProcessingTag,
  aidl::android::hardware::audio::effect::Parameter::Id::Tag::environmentalReverbTag,
  aidl::android::hardware::audio::effect::Parameter::Id::Tag::equalizerTag,
  aidl::android::hardware::audio::effect::Parameter::Id::Tag::hapticGeneratorTag,
  aidl::android::hardware::audio::effect::Parameter::Id::Tag::loudnessEnhancerTag,
  aidl::android::hardware::audio::effect::Parameter::Id::Tag::noiseSuppressionTag,
  aidl::android::hardware::audio::effect::Parameter::Id::Tag::presetReverbTag,
  aidl::android::hardware::audio::effect::Parameter::Id::Tag::virtualizerTag,
  aidl::android::hardware::audio::effect::Parameter::Id::Tag::visualizerTag,
  aidl::android::hardware::audio::effect::Parameter::Id::Tag::volumeTag,
  aidl::android::hardware::audio::effect::Parameter::Id::Tag::commonTag,
  aidl::android::hardware::audio::effect::Parameter::Id::Tag::spatializerTag,
  aidl::android::hardware::audio::effect::Parameter::Id::Tag::eraserTag,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
[[nodiscard]] static inline std::string toString(Parameter::Specific::Tag val) {
  switch(val) {
  case Parameter::Specific::Tag::vendorEffect:
    return "vendorEffect";
  case Parameter::Specific::Tag::acousticEchoCanceler:
    return "acousticEchoCanceler";
  case Parameter::Specific::Tag::automaticGainControlV1:
    return "automaticGainControlV1";
  case Parameter::Specific::Tag::automaticGainControlV2:
    return "automaticGainControlV2";
  case Parameter::Specific::Tag::bassBoost:
    return "bassBoost";
  case Parameter::Specific::Tag::downmix:
    return "downmix";
  case Parameter::Specific::Tag::dynamicsProcessing:
    return "dynamicsProcessing";
  case Parameter::Specific::Tag::environmentalReverb:
    return "environmentalReverb";
  case Parameter::Specific::Tag::equalizer:
    return "equalizer";
  case Parameter::Specific::Tag::hapticGenerator:
    return "hapticGenerator";
  case Parameter::Specific::Tag::loudnessEnhancer:
    return "loudnessEnhancer";
  case Parameter::Specific::Tag::noiseSuppression:
    return "noiseSuppression";
  case Parameter::Specific::Tag::presetReverb:
    return "presetReverb";
  case Parameter::Specific::Tag::virtualizer:
    return "virtualizer";
  case Parameter::Specific::Tag::visualizer:
    return "visualizer";
  case Parameter::Specific::Tag::volume:
    return "volume";
  case Parameter::Specific::Tag::spatializer:
    return "spatializer";
  case Parameter::Specific::Tag::eraser:
    return "eraser";
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
constexpr inline std::array<aidl::android::hardware::audio::effect::Parameter::Specific::Tag, 18> enum_values<aidl::android::hardware::audio::effect::Parameter::Specific::Tag> = {
  aidl::android::hardware::audio::effect::Parameter::Specific::Tag::vendorEffect,
  aidl::android::hardware::audio::effect::Parameter::Specific::Tag::acousticEchoCanceler,
  aidl::android::hardware::audio::effect::Parameter::Specific::Tag::automaticGainControlV1,
  aidl::android::hardware::audio::effect::Parameter::Specific::Tag::automaticGainControlV2,
  aidl::android::hardware::audio::effect::Parameter::Specific::Tag::bassBoost,
  aidl::android::hardware::audio::effect::Parameter::Specific::Tag::downmix,
  aidl::android::hardware::audio::effect::Parameter::Specific::Tag::dynamicsProcessing,
  aidl::android::hardware::audio::effect::Parameter::Specific::Tag::environmentalReverb,
  aidl::android::hardware::audio::effect::Parameter::Specific::Tag::equalizer,
  aidl::android::hardware::audio::effect::Parameter::Specific::Tag::hapticGenerator,
  aidl::android::hardware::audio::effect::Parameter::Specific::Tag::loudnessEnhancer,
  aidl::android::hardware::audio::effect::Parameter::Specific::Tag::noiseSuppression,
  aidl::android::hardware::audio::effect::Parameter::Specific::Tag::presetReverb,
  aidl::android::hardware::audio::effect::Parameter::Specific::Tag::virtualizer,
  aidl::android::hardware::audio::effect::Parameter::Specific::Tag::visualizer,
  aidl::android::hardware::audio::effect::Parameter::Specific::Tag::volume,
  aidl::android::hardware::audio::effect::Parameter::Specific::Tag::spatializer,
  aidl::android::hardware::audio::effect::Parameter::Specific::Tag::eraser,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
[[nodiscard]] static inline std::string toString(Parameter::Tag val) {
  switch(val) {
  case Parameter::Tag::common:
    return "common";
  case Parameter::Tag::deviceDescription:
    return "deviceDescription";
  case Parameter::Tag::mode:
    return "mode";
  case Parameter::Tag::source:
    return "source";
  case Parameter::Tag::offload:
    return "offload";
  case Parameter::Tag::volumeStereo:
    return "volumeStereo";
  case Parameter::Tag::specific:
    return "specific";
  case Parameter::Tag::sinkMetadata:
    return "sinkMetadata";
  case Parameter::Tag::sourceMetadata:
    return "sourceMetadata";
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
constexpr inline std::array<aidl::android::hardware::audio::effect::Parameter::Tag, 9> enum_values<aidl::android::hardware::audio::effect::Parameter::Tag> = {
  aidl::android::hardware::audio::effect::Parameter::Tag::common,
  aidl::android::hardware::audio::effect::Parameter::Tag::deviceDescription,
  aidl::android::hardware::audio::effect::Parameter::Tag::mode,
  aidl::android::hardware::audio::effect::Parameter::Tag::source,
  aidl::android::hardware::audio::effect::Parameter::Tag::offload,
  aidl::android::hardware::audio::effect::Parameter::Tag::volumeStereo,
  aidl::android::hardware::audio::effect::Parameter::Tag::specific,
  aidl::android::hardware::audio::effect::Parameter::Tag::sinkMetadata,
  aidl::android::hardware::audio::effect::Parameter::Tag::sourceMetadata,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
