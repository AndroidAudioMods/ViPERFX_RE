/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioSource.aidl
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
enum class AudioSource : int32_t {
  SYS_RESERVED_INVALID = -1,
  DEFAULT = 0,
  MIC = 1,
  VOICE_UPLINK = 2,
  VOICE_DOWNLINK = 3,
  VOICE_CALL = 4,
  CAMCORDER = 5,
  VOICE_RECOGNITION = 6,
  VOICE_COMMUNICATION = 7,
  REMOTE_SUBMIX = 8,
  UNPROCESSED = 9,
  VOICE_PERFORMANCE = 10,
  ECHO_REFERENCE = 1997,
  FM_TUNER = 1998,
  HOTWORD = 1999,
  ULTRASOUND = 2000,
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
[[nodiscard]] static inline std::string toString(AudioSource val) {
  switch(val) {
  case AudioSource::SYS_RESERVED_INVALID:
    return "SYS_RESERVED_INVALID";
  case AudioSource::DEFAULT:
    return "DEFAULT";
  case AudioSource::MIC:
    return "MIC";
  case AudioSource::VOICE_UPLINK:
    return "VOICE_UPLINK";
  case AudioSource::VOICE_DOWNLINK:
    return "VOICE_DOWNLINK";
  case AudioSource::VOICE_CALL:
    return "VOICE_CALL";
  case AudioSource::CAMCORDER:
    return "CAMCORDER";
  case AudioSource::VOICE_RECOGNITION:
    return "VOICE_RECOGNITION";
  case AudioSource::VOICE_COMMUNICATION:
    return "VOICE_COMMUNICATION";
  case AudioSource::REMOTE_SUBMIX:
    return "REMOTE_SUBMIX";
  case AudioSource::UNPROCESSED:
    return "UNPROCESSED";
  case AudioSource::VOICE_PERFORMANCE:
    return "VOICE_PERFORMANCE";
  case AudioSource::ECHO_REFERENCE:
    return "ECHO_REFERENCE";
  case AudioSource::FM_TUNER:
    return "FM_TUNER";
  case AudioSource::HOTWORD:
    return "HOTWORD";
  case AudioSource::ULTRASOUND:
    return "ULTRASOUND";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioSource, 16> enum_values<aidl::android::media::audio::common::AudioSource> = {
  aidl::android::media::audio::common::AudioSource::SYS_RESERVED_INVALID,
  aidl::android::media::audio::common::AudioSource::DEFAULT,
  aidl::android::media::audio::common::AudioSource::MIC,
  aidl::android::media::audio::common::AudioSource::VOICE_UPLINK,
  aidl::android::media::audio::common::AudioSource::VOICE_DOWNLINK,
  aidl::android::media::audio::common::AudioSource::VOICE_CALL,
  aidl::android::media::audio::common::AudioSource::CAMCORDER,
  aidl::android::media::audio::common::AudioSource::VOICE_RECOGNITION,
  aidl::android::media::audio::common::AudioSource::VOICE_COMMUNICATION,
  aidl::android::media::audio::common::AudioSource::REMOTE_SUBMIX,
  aidl::android::media::audio::common::AudioSource::UNPROCESSED,
  aidl::android::media::audio::common::AudioSource::VOICE_PERFORMANCE,
  aidl::android::media::audio::common::AudioSource::ECHO_REFERENCE,
  aidl::android::media::audio::common::AudioSource::FM_TUNER,
  aidl::android::media::audio::common::AudioSource::HOTWORD,
  aidl::android::media::audio::common::AudioSource::ULTRASOUND,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
