/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioOutputFlags.aidl
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
enum class AudioOutputFlags : int32_t {
  DIRECT = 0,
  PRIMARY = 1,
  FAST = 2,
  DEEP_BUFFER = 3,
  COMPRESS_OFFLOAD = 4,
  NON_BLOCKING = 5,
  HW_AV_SYNC = 6,
  TTS = 7,
  RAW = 8,
  SYNC = 9,
  IEC958_NONAUDIO = 10,
  DIRECT_PCM = 11,
  MMAP_NOIRQ = 12,
  VOIP_RX = 13,
  INCALL_MUSIC = 14,
  GAPLESS_OFFLOAD = 15,
  SPATIALIZER = 16,
  ULTRASOUND = 17,
  BIT_PERFECT = 18,
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
[[nodiscard]] static inline std::string toString(AudioOutputFlags val) {
  switch(val) {
  case AudioOutputFlags::DIRECT:
    return "DIRECT";
  case AudioOutputFlags::PRIMARY:
    return "PRIMARY";
  case AudioOutputFlags::FAST:
    return "FAST";
  case AudioOutputFlags::DEEP_BUFFER:
    return "DEEP_BUFFER";
  case AudioOutputFlags::COMPRESS_OFFLOAD:
    return "COMPRESS_OFFLOAD";
  case AudioOutputFlags::NON_BLOCKING:
    return "NON_BLOCKING";
  case AudioOutputFlags::HW_AV_SYNC:
    return "HW_AV_SYNC";
  case AudioOutputFlags::TTS:
    return "TTS";
  case AudioOutputFlags::RAW:
    return "RAW";
  case AudioOutputFlags::SYNC:
    return "SYNC";
  case AudioOutputFlags::IEC958_NONAUDIO:
    return "IEC958_NONAUDIO";
  case AudioOutputFlags::DIRECT_PCM:
    return "DIRECT_PCM";
  case AudioOutputFlags::MMAP_NOIRQ:
    return "MMAP_NOIRQ";
  case AudioOutputFlags::VOIP_RX:
    return "VOIP_RX";
  case AudioOutputFlags::INCALL_MUSIC:
    return "INCALL_MUSIC";
  case AudioOutputFlags::GAPLESS_OFFLOAD:
    return "GAPLESS_OFFLOAD";
  case AudioOutputFlags::SPATIALIZER:
    return "SPATIALIZER";
  case AudioOutputFlags::ULTRASOUND:
    return "ULTRASOUND";
  case AudioOutputFlags::BIT_PERFECT:
    return "BIT_PERFECT";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioOutputFlags, 19> enum_values<aidl::android::media::audio::common::AudioOutputFlags> = {
  aidl::android::media::audio::common::AudioOutputFlags::DIRECT,
  aidl::android::media::audio::common::AudioOutputFlags::PRIMARY,
  aidl::android::media::audio::common::AudioOutputFlags::FAST,
  aidl::android::media::audio::common::AudioOutputFlags::DEEP_BUFFER,
  aidl::android::media::audio::common::AudioOutputFlags::COMPRESS_OFFLOAD,
  aidl::android::media::audio::common::AudioOutputFlags::NON_BLOCKING,
  aidl::android::media::audio::common::AudioOutputFlags::HW_AV_SYNC,
  aidl::android::media::audio::common::AudioOutputFlags::TTS,
  aidl::android::media::audio::common::AudioOutputFlags::RAW,
  aidl::android::media::audio::common::AudioOutputFlags::SYNC,
  aidl::android::media::audio::common::AudioOutputFlags::IEC958_NONAUDIO,
  aidl::android::media::audio::common::AudioOutputFlags::DIRECT_PCM,
  aidl::android::media::audio::common::AudioOutputFlags::MMAP_NOIRQ,
  aidl::android::media::audio::common::AudioOutputFlags::VOIP_RX,
  aidl::android::media::audio::common::AudioOutputFlags::INCALL_MUSIC,
  aidl::android::media::audio::common::AudioOutputFlags::GAPLESS_OFFLOAD,
  aidl::android::media::audio::common::AudioOutputFlags::SPATIALIZER,
  aidl::android::media::audio::common::AudioOutputFlags::ULTRASOUND,
  aidl::android::media::audio::common::AudioOutputFlags::BIT_PERFECT,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
