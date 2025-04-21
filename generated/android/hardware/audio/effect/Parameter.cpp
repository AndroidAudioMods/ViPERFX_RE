/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Parameter.aidl
 */
#include "aidl/android/hardware/audio/effect/Parameter.h"

#include <android/binder_parcel_utils.h>
#include <aidl/android/media/audio/eraser/BnEraserCallback.h>
#include <aidl/android/media/audio/eraser/BpEraserCallback.h>
#include <aidl/android/media/audio/eraser/IEraserCallback.h>

namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
const char* Parameter::descriptor = "android.hardware.audio.effect.Parameter";

binder_status_t Parameter::readFromParcel(const AParcel* _parcel) {
  binder_status_t _aidl_ret_status;
  int32_t _aidl_tag;
  if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_tag)) != STATUS_OK) return _aidl_ret_status;
  switch (static_cast<Tag>(_aidl_tag)) {
  case common: {
    ::aidl::android::hardware::audio::effect::Parameter::Common _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Parameter::Common>) {
      set<common>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<common>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case deviceDescription: {
    std::vector<::aidl::android::media::audio::common::AudioDeviceDescription> _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<std::vector<::aidl::android::media::audio::common::AudioDeviceDescription>>) {
      set<deviceDescription>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<deviceDescription>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case mode: {
    ::aidl::android::media::audio::common::AudioMode _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::media::audio::common::AudioMode>) {
      set<mode>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<mode>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case source: {
    ::aidl::android::media::audio::common::AudioSource _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::media::audio::common::AudioSource>) {
      set<source>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<source>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case offload: {
    bool _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<bool>) {
      set<offload>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<offload>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case volumeStereo: {
    ::aidl::android::hardware::audio::effect::Parameter::VolumeStereo _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Parameter::VolumeStereo>) {
      set<volumeStereo>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<volumeStereo>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case specific: {
    ::aidl::android::hardware::audio::effect::Parameter::Specific _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Parameter::Specific>) {
      set<specific>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<specific>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case sinkMetadata: {
    ::aidl::android::hardware::audio::common::SinkMetadata _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::common::SinkMetadata>) {
      set<sinkMetadata>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<sinkMetadata>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case sourceMetadata: {
    ::aidl::android::hardware::audio::common::SourceMetadata _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::common::SourceMetadata>) {
      set<sourceMetadata>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<sourceMetadata>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  }
  return STATUS_BAD_VALUE;
}
binder_status_t Parameter::writeToParcel(AParcel* _parcel) const {
  binder_status_t _aidl_ret_status = ::ndk::AParcel_writeData(_parcel, static_cast<int32_t>(getTag()));
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;
  switch (getTag()) {
  case common: return ::ndk::AParcel_writeData(_parcel, get<common>());
  case deviceDescription: return ::ndk::AParcel_writeData(_parcel, get<deviceDescription>());
  case mode: return ::ndk::AParcel_writeData(_parcel, get<mode>());
  case source: return ::ndk::AParcel_writeData(_parcel, get<source>());
  case offload: return ::ndk::AParcel_writeData(_parcel, get<offload>());
  case volumeStereo: return ::ndk::AParcel_writeData(_parcel, get<volumeStereo>());
  case specific: return ::ndk::AParcel_writeData(_parcel, get<specific>());
  case sinkMetadata: return ::ndk::AParcel_writeData(_parcel, get<sinkMetadata>());
  case sourceMetadata: return ::ndk::AParcel_writeData(_parcel, get<sourceMetadata>());
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

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
const char* Parameter::Id::descriptor = "android.hardware.audio.effect.Parameter.Id";

binder_status_t Parameter::Id::readFromParcel(const AParcel* _parcel) {
  binder_status_t _aidl_ret_status;
  int32_t _aidl_tag;
  if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_tag)) != STATUS_OK) return _aidl_ret_status;
  switch (static_cast<Tag>(_aidl_tag)) {
  case vendorEffectTag: {
    ::aidl::android::hardware::audio::effect::VendorExtension _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::VendorExtension>) {
      set<vendorEffectTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<vendorEffectTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case acousticEchoCancelerTag: {
    ::aidl::android::hardware::audio::effect::AcousticEchoCanceler::Id _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::AcousticEchoCanceler::Id>) {
      set<acousticEchoCancelerTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<acousticEchoCancelerTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case automaticGainControlV1Tag: {
    ::aidl::android::hardware::audio::effect::AutomaticGainControlV1::Id _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::AutomaticGainControlV1::Id>) {
      set<automaticGainControlV1Tag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<automaticGainControlV1Tag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case automaticGainControlV2Tag: {
    ::aidl::android::hardware::audio::effect::AutomaticGainControlV2::Id _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::AutomaticGainControlV2::Id>) {
      set<automaticGainControlV2Tag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<automaticGainControlV2Tag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case bassBoostTag: {
    ::aidl::android::hardware::audio::effect::BassBoost::Id _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::BassBoost::Id>) {
      set<bassBoostTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<bassBoostTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case downmixTag: {
    ::aidl::android::hardware::audio::effect::Downmix::Id _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Downmix::Id>) {
      set<downmixTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<downmixTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case dynamicsProcessingTag: {
    ::aidl::android::hardware::audio::effect::DynamicsProcessing::Id _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::DynamicsProcessing::Id>) {
      set<dynamicsProcessingTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<dynamicsProcessingTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case environmentalReverbTag: {
    ::aidl::android::hardware::audio::effect::EnvironmentalReverb::Id _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::EnvironmentalReverb::Id>) {
      set<environmentalReverbTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<environmentalReverbTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case equalizerTag: {
    ::aidl::android::hardware::audio::effect::Equalizer::Id _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Equalizer::Id>) {
      set<equalizerTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<equalizerTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case hapticGeneratorTag: {
    ::aidl::android::hardware::audio::effect::HapticGenerator::Id _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::HapticGenerator::Id>) {
      set<hapticGeneratorTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<hapticGeneratorTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case loudnessEnhancerTag: {
    ::aidl::android::hardware::audio::effect::LoudnessEnhancer::Id _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::LoudnessEnhancer::Id>) {
      set<loudnessEnhancerTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<loudnessEnhancerTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case noiseSuppressionTag: {
    ::aidl::android::hardware::audio::effect::NoiseSuppression::Id _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::NoiseSuppression::Id>) {
      set<noiseSuppressionTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<noiseSuppressionTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case presetReverbTag: {
    ::aidl::android::hardware::audio::effect::PresetReverb::Id _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::PresetReverb::Id>) {
      set<presetReverbTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<presetReverbTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case virtualizerTag: {
    ::aidl::android::hardware::audio::effect::Virtualizer::Id _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Virtualizer::Id>) {
      set<virtualizerTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<virtualizerTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case visualizerTag: {
    ::aidl::android::hardware::audio::effect::Visualizer::Id _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Visualizer::Id>) {
      set<visualizerTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<visualizerTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case volumeTag: {
    ::aidl::android::hardware::audio::effect::Volume::Id _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Volume::Id>) {
      set<volumeTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<volumeTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case commonTag: {
    ::aidl::android::hardware::audio::effect::Parameter::Tag _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Parameter::Tag>) {
      set<commonTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<commonTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case spatializerTag: {
    ::aidl::android::hardware::audio::effect::Spatializer::Id _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Spatializer::Id>) {
      set<spatializerTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<spatializerTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case eraserTag: {
    ::aidl::android::hardware::audio::effect::Eraser::Id _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Eraser::Id>) {
      set<eraserTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<eraserTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  }
  return STATUS_BAD_VALUE;
}
binder_status_t Parameter::Id::writeToParcel(AParcel* _parcel) const {
  binder_status_t _aidl_ret_status = ::ndk::AParcel_writeData(_parcel, static_cast<int32_t>(getTag()));
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;
  switch (getTag()) {
  case vendorEffectTag: return ::ndk::AParcel_writeData(_parcel, get<vendorEffectTag>());
  case acousticEchoCancelerTag: return ::ndk::AParcel_writeData(_parcel, get<acousticEchoCancelerTag>());
  case automaticGainControlV1Tag: return ::ndk::AParcel_writeData(_parcel, get<automaticGainControlV1Tag>());
  case automaticGainControlV2Tag: return ::ndk::AParcel_writeData(_parcel, get<automaticGainControlV2Tag>());
  case bassBoostTag: return ::ndk::AParcel_writeData(_parcel, get<bassBoostTag>());
  case downmixTag: return ::ndk::AParcel_writeData(_parcel, get<downmixTag>());
  case dynamicsProcessingTag: return ::ndk::AParcel_writeData(_parcel, get<dynamicsProcessingTag>());
  case environmentalReverbTag: return ::ndk::AParcel_writeData(_parcel, get<environmentalReverbTag>());
  case equalizerTag: return ::ndk::AParcel_writeData(_parcel, get<equalizerTag>());
  case hapticGeneratorTag: return ::ndk::AParcel_writeData(_parcel, get<hapticGeneratorTag>());
  case loudnessEnhancerTag: return ::ndk::AParcel_writeData(_parcel, get<loudnessEnhancerTag>());
  case noiseSuppressionTag: return ::ndk::AParcel_writeData(_parcel, get<noiseSuppressionTag>());
  case presetReverbTag: return ::ndk::AParcel_writeData(_parcel, get<presetReverbTag>());
  case virtualizerTag: return ::ndk::AParcel_writeData(_parcel, get<virtualizerTag>());
  case visualizerTag: return ::ndk::AParcel_writeData(_parcel, get<visualizerTag>());
  case volumeTag: return ::ndk::AParcel_writeData(_parcel, get<volumeTag>());
  case commonTag: return ::ndk::AParcel_writeData(_parcel, get<commonTag>());
  case spatializerTag: return ::ndk::AParcel_writeData(_parcel, get<spatializerTag>());
  case eraserTag: return ::ndk::AParcel_writeData(_parcel, get<eraserTag>());
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

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
const char* Parameter::Common::descriptor = "android.hardware.audio.effect.Parameter.Common";

binder_status_t Parameter::Common::readFromParcel(const AParcel* _aidl_parcel) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  int32_t _aidl_start_pos = AParcel_getDataPosition(_aidl_parcel);
  int32_t _aidl_parcelable_size = 0;
  _aidl_ret_status = AParcel_readInt32(_aidl_parcel, &_aidl_parcelable_size);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  if (_aidl_parcelable_size < 4) return STATUS_BAD_VALUE;
  if (_aidl_start_pos > INT32_MAX - _aidl_parcelable_size) return STATUS_BAD_VALUE;
  if (AParcel_getDataPosition(_aidl_parcel) - _aidl_start_pos >= _aidl_parcelable_size) {
    AParcel_setDataPosition(_aidl_parcel, _aidl_start_pos + _aidl_parcelable_size);
    return _aidl_ret_status;
  }
  _aidl_ret_status = ::ndk::AParcel_readData(_aidl_parcel, &session);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  if (AParcel_getDataPosition(_aidl_parcel) - _aidl_start_pos >= _aidl_parcelable_size) {
    AParcel_setDataPosition(_aidl_parcel, _aidl_start_pos + _aidl_parcelable_size);
    return _aidl_ret_status;
  }
  _aidl_ret_status = ::ndk::AParcel_readData(_aidl_parcel, &ioHandle);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  if (AParcel_getDataPosition(_aidl_parcel) - _aidl_start_pos >= _aidl_parcelable_size) {
    AParcel_setDataPosition(_aidl_parcel, _aidl_start_pos + _aidl_parcelable_size);
    return _aidl_ret_status;
  }
  _aidl_ret_status = ::ndk::AParcel_readData(_aidl_parcel, &input);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  if (AParcel_getDataPosition(_aidl_parcel) - _aidl_start_pos >= _aidl_parcelable_size) {
    AParcel_setDataPosition(_aidl_parcel, _aidl_start_pos + _aidl_parcelable_size);
    return _aidl_ret_status;
  }
  _aidl_ret_status = ::ndk::AParcel_readData(_aidl_parcel, &output);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  AParcel_setDataPosition(_aidl_parcel, _aidl_start_pos + _aidl_parcelable_size);
  return _aidl_ret_status;
}
binder_status_t Parameter::Common::writeToParcel(AParcel* _aidl_parcel) const {
  binder_status_t _aidl_ret_status;
  size_t _aidl_start_pos = AParcel_getDataPosition(_aidl_parcel);
  _aidl_ret_status = AParcel_writeInt32(_aidl_parcel, 0);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_parcel, session);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_parcel, ioHandle);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_parcel, input);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_parcel, output);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  size_t _aidl_end_pos = AParcel_getDataPosition(_aidl_parcel);
  AParcel_setDataPosition(_aidl_parcel, _aidl_start_pos);
  AParcel_writeInt32(_aidl_parcel, _aidl_end_pos - _aidl_start_pos);
  AParcel_setDataPosition(_aidl_parcel, _aidl_end_pos);
  return _aidl_ret_status;
}

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
const char* Parameter::VolumeStereo::descriptor = "android.hardware.audio.effect.Parameter.VolumeStereo";

binder_status_t Parameter::VolumeStereo::readFromParcel(const AParcel* _aidl_parcel) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  int32_t _aidl_start_pos = AParcel_getDataPosition(_aidl_parcel);
  int32_t _aidl_parcelable_size = 0;
  _aidl_ret_status = AParcel_readInt32(_aidl_parcel, &_aidl_parcelable_size);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  if (_aidl_parcelable_size < 4) return STATUS_BAD_VALUE;
  if (_aidl_start_pos > INT32_MAX - _aidl_parcelable_size) return STATUS_BAD_VALUE;
  if (AParcel_getDataPosition(_aidl_parcel) - _aidl_start_pos >= _aidl_parcelable_size) {
    AParcel_setDataPosition(_aidl_parcel, _aidl_start_pos + _aidl_parcelable_size);
    return _aidl_ret_status;
  }
  _aidl_ret_status = ::ndk::AParcel_readData(_aidl_parcel, &left);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  if (AParcel_getDataPosition(_aidl_parcel) - _aidl_start_pos >= _aidl_parcelable_size) {
    AParcel_setDataPosition(_aidl_parcel, _aidl_start_pos + _aidl_parcelable_size);
    return _aidl_ret_status;
  }
  _aidl_ret_status = ::ndk::AParcel_readData(_aidl_parcel, &right);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  AParcel_setDataPosition(_aidl_parcel, _aidl_start_pos + _aidl_parcelable_size);
  return _aidl_ret_status;
}
binder_status_t Parameter::VolumeStereo::writeToParcel(AParcel* _aidl_parcel) const {
  binder_status_t _aidl_ret_status;
  size_t _aidl_start_pos = AParcel_getDataPosition(_aidl_parcel);
  _aidl_ret_status = AParcel_writeInt32(_aidl_parcel, 0);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_parcel, left);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_parcel, right);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  size_t _aidl_end_pos = AParcel_getDataPosition(_aidl_parcel);
  AParcel_setDataPosition(_aidl_parcel, _aidl_start_pos);
  AParcel_writeInt32(_aidl_parcel, _aidl_end_pos - _aidl_start_pos);
  AParcel_setDataPosition(_aidl_parcel, _aidl_end_pos);
  return _aidl_ret_status;
}

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
const char* Parameter::Specific::descriptor = "android.hardware.audio.effect.Parameter.Specific";

binder_status_t Parameter::Specific::readFromParcel(const AParcel* _parcel) {
  binder_status_t _aidl_ret_status;
  int32_t _aidl_tag;
  if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_tag)) != STATUS_OK) return _aidl_ret_status;
  switch (static_cast<Tag>(_aidl_tag)) {
  case vendorEffect: {
    ::aidl::android::hardware::audio::effect::VendorExtension _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::VendorExtension>) {
      set<vendorEffect>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<vendorEffect>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case acousticEchoCanceler: {
    ::aidl::android::hardware::audio::effect::AcousticEchoCanceler _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::AcousticEchoCanceler>) {
      set<acousticEchoCanceler>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<acousticEchoCanceler>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case automaticGainControlV1: {
    ::aidl::android::hardware::audio::effect::AutomaticGainControlV1 _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::AutomaticGainControlV1>) {
      set<automaticGainControlV1>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<automaticGainControlV1>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case automaticGainControlV2: {
    ::aidl::android::hardware::audio::effect::AutomaticGainControlV2 _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::AutomaticGainControlV2>) {
      set<automaticGainControlV2>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<automaticGainControlV2>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case bassBoost: {
    ::aidl::android::hardware::audio::effect::BassBoost _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::BassBoost>) {
      set<bassBoost>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<bassBoost>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case downmix: {
    ::aidl::android::hardware::audio::effect::Downmix _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Downmix>) {
      set<downmix>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<downmix>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case dynamicsProcessing: {
    ::aidl::android::hardware::audio::effect::DynamicsProcessing _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::DynamicsProcessing>) {
      set<dynamicsProcessing>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<dynamicsProcessing>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case environmentalReverb: {
    ::aidl::android::hardware::audio::effect::EnvironmentalReverb _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::EnvironmentalReverb>) {
      set<environmentalReverb>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<environmentalReverb>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case equalizer: {
    ::aidl::android::hardware::audio::effect::Equalizer _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Equalizer>) {
      set<equalizer>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<equalizer>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case hapticGenerator: {
    ::aidl::android::hardware::audio::effect::HapticGenerator _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::HapticGenerator>) {
      set<hapticGenerator>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<hapticGenerator>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case loudnessEnhancer: {
    ::aidl::android::hardware::audio::effect::LoudnessEnhancer _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::LoudnessEnhancer>) {
      set<loudnessEnhancer>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<loudnessEnhancer>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case noiseSuppression: {
    ::aidl::android::hardware::audio::effect::NoiseSuppression _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::NoiseSuppression>) {
      set<noiseSuppression>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<noiseSuppression>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case presetReverb: {
    ::aidl::android::hardware::audio::effect::PresetReverb _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::PresetReverb>) {
      set<presetReverb>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<presetReverb>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case virtualizer: {
    ::aidl::android::hardware::audio::effect::Virtualizer _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Virtualizer>) {
      set<virtualizer>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<virtualizer>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case visualizer: {
    ::aidl::android::hardware::audio::effect::Visualizer _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Visualizer>) {
      set<visualizer>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<visualizer>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case volume: {
    ::aidl::android::hardware::audio::effect::Volume _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Volume>) {
      set<volume>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<volume>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case spatializer: {
    ::aidl::android::hardware::audio::effect::Spatializer _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Spatializer>) {
      set<spatializer>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<spatializer>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case eraser: {
    ::aidl::android::hardware::audio::effect::Eraser _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Eraser>) {
      set<eraser>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<eraser>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  }
  return STATUS_BAD_VALUE;
}
binder_status_t Parameter::Specific::writeToParcel(AParcel* _parcel) const {
  binder_status_t _aidl_ret_status = ::ndk::AParcel_writeData(_parcel, static_cast<int32_t>(getTag()));
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;
  switch (getTag()) {
  case vendorEffect: return ::ndk::AParcel_writeData(_parcel, get<vendorEffect>());
  case acousticEchoCanceler: return ::ndk::AParcel_writeData(_parcel, get<acousticEchoCanceler>());
  case automaticGainControlV1: return ::ndk::AParcel_writeData(_parcel, get<automaticGainControlV1>());
  case automaticGainControlV2: return ::ndk::AParcel_writeData(_parcel, get<automaticGainControlV2>());
  case bassBoost: return ::ndk::AParcel_writeData(_parcel, get<bassBoost>());
  case downmix: return ::ndk::AParcel_writeData(_parcel, get<downmix>());
  case dynamicsProcessing: return ::ndk::AParcel_writeData(_parcel, get<dynamicsProcessing>());
  case environmentalReverb: return ::ndk::AParcel_writeData(_parcel, get<environmentalReverb>());
  case equalizer: return ::ndk::AParcel_writeData(_parcel, get<equalizer>());
  case hapticGenerator: return ::ndk::AParcel_writeData(_parcel, get<hapticGenerator>());
  case loudnessEnhancer: return ::ndk::AParcel_writeData(_parcel, get<loudnessEnhancer>());
  case noiseSuppression: return ::ndk::AParcel_writeData(_parcel, get<noiseSuppression>());
  case presetReverb: return ::ndk::AParcel_writeData(_parcel, get<presetReverb>());
  case virtualizer: return ::ndk::AParcel_writeData(_parcel, get<virtualizer>());
  case visualizer: return ::ndk::AParcel_writeData(_parcel, get<visualizer>());
  case volume: return ::ndk::AParcel_writeData(_parcel, get<volume>());
  case spatializer: return ::ndk::AParcel_writeData(_parcel, get<spatializer>());
  case eraser: return ::ndk::AParcel_writeData(_parcel, get<eraser>());
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
