/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioUsage.aidl
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
enum class AudioUsage : int32_t {
  INVALID = -1,
  UNKNOWN = 0,
  MEDIA = 1,
  VOICE_COMMUNICATION = 2,
  VOICE_COMMUNICATION_SIGNALLING = 3,
  ALARM = 4,
  NOTIFICATION = 5,
  NOTIFICATION_TELEPHONY_RINGTONE = 6,
  SYS_RESERVED_NOTIFICATION_COMMUNICATION_REQUEST = 7,
  SYS_RESERVED_NOTIFICATION_COMMUNICATION_INSTANT = 8,
  SYS_RESERVED_NOTIFICATION_COMMUNICATION_DELAYED = 9,
  NOTIFICATION_EVENT = 10,
  ASSISTANCE_ACCESSIBILITY = 11,
  ASSISTANCE_NAVIGATION_GUIDANCE = 12,
  ASSISTANCE_SONIFICATION = 13,
  GAME = 14,
  VIRTUAL_SOURCE = 15,
  ASSISTANT = 16,
  CALL_ASSISTANT = 17,
  EMERGENCY = 1000,
  SAFETY = 1001,
  VEHICLE_STATUS = 1002,
  ANNOUNCEMENT = 1003,
  SPEAKER_CLEANUP = 1004,
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
[[nodiscard]] static inline std::string toString(AudioUsage val) {
  switch(val) {
  case AudioUsage::INVALID:
    return "INVALID";
  case AudioUsage::UNKNOWN:
    return "UNKNOWN";
  case AudioUsage::MEDIA:
    return "MEDIA";
  case AudioUsage::VOICE_COMMUNICATION:
    return "VOICE_COMMUNICATION";
  case AudioUsage::VOICE_COMMUNICATION_SIGNALLING:
    return "VOICE_COMMUNICATION_SIGNALLING";
  case AudioUsage::ALARM:
    return "ALARM";
  case AudioUsage::NOTIFICATION:
    return "NOTIFICATION";
  case AudioUsage::NOTIFICATION_TELEPHONY_RINGTONE:
    return "NOTIFICATION_TELEPHONY_RINGTONE";
  case AudioUsage::SYS_RESERVED_NOTIFICATION_COMMUNICATION_REQUEST:
    return "SYS_RESERVED_NOTIFICATION_COMMUNICATION_REQUEST";
  case AudioUsage::SYS_RESERVED_NOTIFICATION_COMMUNICATION_INSTANT:
    return "SYS_RESERVED_NOTIFICATION_COMMUNICATION_INSTANT";
  case AudioUsage::SYS_RESERVED_NOTIFICATION_COMMUNICATION_DELAYED:
    return "SYS_RESERVED_NOTIFICATION_COMMUNICATION_DELAYED";
  case AudioUsage::NOTIFICATION_EVENT:
    return "NOTIFICATION_EVENT";
  case AudioUsage::ASSISTANCE_ACCESSIBILITY:
    return "ASSISTANCE_ACCESSIBILITY";
  case AudioUsage::ASSISTANCE_NAVIGATION_GUIDANCE:
    return "ASSISTANCE_NAVIGATION_GUIDANCE";
  case AudioUsage::ASSISTANCE_SONIFICATION:
    return "ASSISTANCE_SONIFICATION";
  case AudioUsage::GAME:
    return "GAME";
  case AudioUsage::VIRTUAL_SOURCE:
    return "VIRTUAL_SOURCE";
  case AudioUsage::ASSISTANT:
    return "ASSISTANT";
  case AudioUsage::CALL_ASSISTANT:
    return "CALL_ASSISTANT";
  case AudioUsage::EMERGENCY:
    return "EMERGENCY";
  case AudioUsage::SAFETY:
    return "SAFETY";
  case AudioUsage::VEHICLE_STATUS:
    return "VEHICLE_STATUS";
  case AudioUsage::ANNOUNCEMENT:
    return "ANNOUNCEMENT";
  case AudioUsage::SPEAKER_CLEANUP:
    return "SPEAKER_CLEANUP";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioUsage, 24> enum_values<aidl::android::media::audio::common::AudioUsage> = {
  aidl::android::media::audio::common::AudioUsage::INVALID,
  aidl::android::media::audio::common::AudioUsage::UNKNOWN,
  aidl::android::media::audio::common::AudioUsage::MEDIA,
  aidl::android::media::audio::common::AudioUsage::VOICE_COMMUNICATION,
  aidl::android::media::audio::common::AudioUsage::VOICE_COMMUNICATION_SIGNALLING,
  aidl::android::media::audio::common::AudioUsage::ALARM,
  aidl::android::media::audio::common::AudioUsage::NOTIFICATION,
  aidl::android::media::audio::common::AudioUsage::NOTIFICATION_TELEPHONY_RINGTONE,
  aidl::android::media::audio::common::AudioUsage::SYS_RESERVED_NOTIFICATION_COMMUNICATION_REQUEST,
  aidl::android::media::audio::common::AudioUsage::SYS_RESERVED_NOTIFICATION_COMMUNICATION_INSTANT,
  aidl::android::media::audio::common::AudioUsage::SYS_RESERVED_NOTIFICATION_COMMUNICATION_DELAYED,
  aidl::android::media::audio::common::AudioUsage::NOTIFICATION_EVENT,
  aidl::android::media::audio::common::AudioUsage::ASSISTANCE_ACCESSIBILITY,
  aidl::android::media::audio::common::AudioUsage::ASSISTANCE_NAVIGATION_GUIDANCE,
  aidl::android::media::audio::common::AudioUsage::ASSISTANCE_SONIFICATION,
  aidl::android::media::audio::common::AudioUsage::GAME,
  aidl::android::media::audio::common::AudioUsage::VIRTUAL_SOURCE,
  aidl::android::media::audio::common::AudioUsage::ASSISTANT,
  aidl::android::media::audio::common::AudioUsage::CALL_ASSISTANT,
  aidl::android::media::audio::common::AudioUsage::EMERGENCY,
  aidl::android::media::audio::common::AudioUsage::SAFETY,
  aidl::android::media::audio::common::AudioUsage::VEHICLE_STATUS,
  aidl::android::media::audio::common::AudioUsage::ANNOUNCEMENT,
  aidl::android::media::audio::common::AudioUsage::SPEAKER_CLEANUP,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
