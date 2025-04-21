/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioEncapsulationMetadataType.aidl
 */
#pragma once

#include <array>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_enums.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
enum class AudioEncapsulationMetadataType : int32_t {
  NONE = 0,
  FRAMEWORK_TUNER = 1,
  DVB_AD_DESCRIPTOR = 2,
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
[[nodiscard]] static inline std::string toString(AudioEncapsulationMetadataType val) {
  switch(val) {
  case AudioEncapsulationMetadataType::NONE:
    return "NONE";
  case AudioEncapsulationMetadataType::FRAMEWORK_TUNER:
    return "FRAMEWORK_TUNER";
  case AudioEncapsulationMetadataType::DVB_AD_DESCRIPTOR:
    return "DVB_AD_DESCRIPTOR";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioEncapsulationMetadataType, 3> enum_values<aidl::android::media::audio::common::AudioEncapsulationMetadataType> = {
  aidl::android::media::audio::common::AudioEncapsulationMetadataType::NONE,
  aidl::android::media::audio::common::AudioEncapsulationMetadataType::FRAMEWORK_TUNER,
  aidl::android::media::audio::common::AudioEncapsulationMetadataType::DVB_AD_DESCRIPTOR,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
