/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioStreamType.aidl
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
enum class AudioStreamType : int32_t {
  INVALID = -2,
  SYS_RESERVED_DEFAULT = -1,
  VOICE_CALL = 0,
  SYSTEM = 1,
  RING = 2,
  MUSIC = 3,
  ALARM = 4,
  NOTIFICATION = 5,
  BLUETOOTH_SCO = 6,
  ENFORCED_AUDIBLE = 7,
  DTMF = 8,
  TTS = 9,
  ACCESSIBILITY = 10,
  ASSISTANT = 11,
  SYS_RESERVED_REROUTING = 12,
  SYS_RESERVED_PATCH = 13,
  CALL_ASSISTANT = 14,
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
[[nodiscard]] static inline std::string toString(AudioStreamType val) {
  switch(val) {
  case AudioStreamType::INVALID:
    return "INVALID";
  case AudioStreamType::SYS_RESERVED_DEFAULT:
    return "SYS_RESERVED_DEFAULT";
  case AudioStreamType::VOICE_CALL:
    return "VOICE_CALL";
  case AudioStreamType::SYSTEM:
    return "SYSTEM";
  case AudioStreamType::RING:
    return "RING";
  case AudioStreamType::MUSIC:
    return "MUSIC";
  case AudioStreamType::ALARM:
    return "ALARM";
  case AudioStreamType::NOTIFICATION:
    return "NOTIFICATION";
  case AudioStreamType::BLUETOOTH_SCO:
    return "BLUETOOTH_SCO";
  case AudioStreamType::ENFORCED_AUDIBLE:
    return "ENFORCED_AUDIBLE";
  case AudioStreamType::DTMF:
    return "DTMF";
  case AudioStreamType::TTS:
    return "TTS";
  case AudioStreamType::ACCESSIBILITY:
    return "ACCESSIBILITY";
  case AudioStreamType::ASSISTANT:
    return "ASSISTANT";
  case AudioStreamType::SYS_RESERVED_REROUTING:
    return "SYS_RESERVED_REROUTING";
  case AudioStreamType::SYS_RESERVED_PATCH:
    return "SYS_RESERVED_PATCH";
  case AudioStreamType::CALL_ASSISTANT:
    return "CALL_ASSISTANT";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioStreamType, 17> enum_values<aidl::android::media::audio::common::AudioStreamType> = {
  aidl::android::media::audio::common::AudioStreamType::INVALID,
  aidl::android::media::audio::common::AudioStreamType::SYS_RESERVED_DEFAULT,
  aidl::android::media::audio::common::AudioStreamType::VOICE_CALL,
  aidl::android::media::audio::common::AudioStreamType::SYSTEM,
  aidl::android::media::audio::common::AudioStreamType::RING,
  aidl::android::media::audio::common::AudioStreamType::MUSIC,
  aidl::android::media::audio::common::AudioStreamType::ALARM,
  aidl::android::media::audio::common::AudioStreamType::NOTIFICATION,
  aidl::android::media::audio::common::AudioStreamType::BLUETOOTH_SCO,
  aidl::android::media::audio::common::AudioStreamType::ENFORCED_AUDIBLE,
  aidl::android::media::audio::common::AudioStreamType::DTMF,
  aidl::android::media::audio::common::AudioStreamType::TTS,
  aidl::android::media::audio::common::AudioStreamType::ACCESSIBILITY,
  aidl::android::media::audio::common::AudioStreamType::ASSISTANT,
  aidl::android::media::audio::common::AudioStreamType::SYS_RESERVED_REROUTING,
  aidl::android::media::audio::common::AudioStreamType::SYS_RESERVED_PATCH,
  aidl::android::media::audio::common::AudioStreamType::CALL_ASSISTANT,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
