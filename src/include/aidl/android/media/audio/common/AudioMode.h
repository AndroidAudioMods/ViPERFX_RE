/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioMode.aidl
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
enum class AudioMode : int32_t {
  SYS_RESERVED_INVALID = -2,
  SYS_RESERVED_CURRENT = -1,
  NORMAL = 0,
  RINGTONE = 1,
  IN_CALL = 2,
  IN_COMMUNICATION = 3,
  CALL_SCREEN = 4,
  SYS_RESERVED_CALL_REDIRECT = 5,
  SYS_RESERVED_COMMUNICATION_REDIRECT = 6,
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
[[nodiscard]] static inline std::string toString(AudioMode val) {
  switch(val) {
  case AudioMode::SYS_RESERVED_INVALID:
    return "SYS_RESERVED_INVALID";
  case AudioMode::SYS_RESERVED_CURRENT:
    return "SYS_RESERVED_CURRENT";
  case AudioMode::NORMAL:
    return "NORMAL";
  case AudioMode::RINGTONE:
    return "RINGTONE";
  case AudioMode::IN_CALL:
    return "IN_CALL";
  case AudioMode::IN_COMMUNICATION:
    return "IN_COMMUNICATION";
  case AudioMode::CALL_SCREEN:
    return "CALL_SCREEN";
  case AudioMode::SYS_RESERVED_CALL_REDIRECT:
    return "SYS_RESERVED_CALL_REDIRECT";
  case AudioMode::SYS_RESERVED_COMMUNICATION_REDIRECT:
    return "SYS_RESERVED_COMMUNICATION_REDIRECT";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioMode, 9> enum_values<aidl::android::media::audio::common::AudioMode> = {
  aidl::android::media::audio::common::AudioMode::SYS_RESERVED_INVALID,
  aidl::android::media::audio::common::AudioMode::SYS_RESERVED_CURRENT,
  aidl::android::media::audio::common::AudioMode::NORMAL,
  aidl::android::media::audio::common::AudioMode::RINGTONE,
  aidl::android::media::audio::common::AudioMode::IN_CALL,
  aidl::android::media::audio::common::AudioMode::IN_COMMUNICATION,
  aidl::android::media::audio::common::AudioMode::CALL_SCREEN,
  aidl::android::media::audio::common::AudioMode::SYS_RESERVED_CALL_REDIRECT,
  aidl::android::media::audio::common::AudioMode::SYS_RESERVED_COMMUNICATION_REDIRECT,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
