/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioDeviceType.aidl
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
enum class AudioDeviceType : int32_t {
  NONE = 0,
  IN_DEFAULT = 1,
  IN_ACCESSORY = 2,
  IN_AFE_PROXY = 3,
  IN_DEVICE = 4,
  IN_ECHO_REFERENCE = 5,
  IN_FM_TUNER = 6,
  IN_HEADSET = 7,
  IN_LOOPBACK = 8,
  IN_MICROPHONE = 9,
  IN_MICROPHONE_BACK = 10,
  IN_SUBMIX = 11,
  IN_TELEPHONY_RX = 12,
  IN_TV_TUNER = 13,
  IN_DOCK = 14,
  IN_BUS = 4,
  OUT_DEFAULT = 129,
  OUT_ACCESSORY = 130,
  OUT_AFE_PROXY = 131,
  OUT_CARKIT = 132,
  OUT_DEVICE = 133,
  OUT_ECHO_CANCELLER = 134,
  OUT_FM = 135,
  OUT_HEADPHONE = 136,
  OUT_HEADSET = 137,
  OUT_HEARING_AID = 138,
  OUT_LINE_AUX = 139,
  OUT_SPEAKER = 140,
  OUT_SPEAKER_EARPIECE = 141,
  OUT_SPEAKER_SAFE = 142,
  OUT_SUBMIX = 143,
  OUT_TELEPHONY_TX = 144,
  OUT_DOCK = 145,
  OUT_BROADCAST = 146,
  OUT_BUS = 133,
  OUT_MULTICHANNEL_GROUP = 147,
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
[[nodiscard]] static inline std::string toString(AudioDeviceType val) {
  switch(val) {
  case AudioDeviceType::NONE:
    return "NONE";
  case AudioDeviceType::IN_DEFAULT:
    return "IN_DEFAULT";
  case AudioDeviceType::IN_ACCESSORY:
    return "IN_ACCESSORY";
  case AudioDeviceType::IN_AFE_PROXY:
    return "IN_AFE_PROXY";
  case AudioDeviceType::IN_DEVICE:
    return "IN_DEVICE";
  case AudioDeviceType::IN_ECHO_REFERENCE:
    return "IN_ECHO_REFERENCE";
  case AudioDeviceType::IN_FM_TUNER:
    return "IN_FM_TUNER";
  case AudioDeviceType::IN_HEADSET:
    return "IN_HEADSET";
  case AudioDeviceType::IN_LOOPBACK:
    return "IN_LOOPBACK";
  case AudioDeviceType::IN_MICROPHONE:
    return "IN_MICROPHONE";
  case AudioDeviceType::IN_MICROPHONE_BACK:
    return "IN_MICROPHONE_BACK";
  case AudioDeviceType::IN_SUBMIX:
    return "IN_SUBMIX";
  case AudioDeviceType::IN_TELEPHONY_RX:
    return "IN_TELEPHONY_RX";
  case AudioDeviceType::IN_TV_TUNER:
    return "IN_TV_TUNER";
  case AudioDeviceType::IN_DOCK:
    return "IN_DOCK";
  case AudioDeviceType::OUT_DEFAULT:
    return "OUT_DEFAULT";
  case AudioDeviceType::OUT_ACCESSORY:
    return "OUT_ACCESSORY";
  case AudioDeviceType::OUT_AFE_PROXY:
    return "OUT_AFE_PROXY";
  case AudioDeviceType::OUT_CARKIT:
    return "OUT_CARKIT";
  case AudioDeviceType::OUT_DEVICE:
    return "OUT_DEVICE";
  case AudioDeviceType::OUT_ECHO_CANCELLER:
    return "OUT_ECHO_CANCELLER";
  case AudioDeviceType::OUT_FM:
    return "OUT_FM";
  case AudioDeviceType::OUT_HEADPHONE:
    return "OUT_HEADPHONE";
  case AudioDeviceType::OUT_HEADSET:
    return "OUT_HEADSET";
  case AudioDeviceType::OUT_HEARING_AID:
    return "OUT_HEARING_AID";
  case AudioDeviceType::OUT_LINE_AUX:
    return "OUT_LINE_AUX";
  case AudioDeviceType::OUT_SPEAKER:
    return "OUT_SPEAKER";
  case AudioDeviceType::OUT_SPEAKER_EARPIECE:
    return "OUT_SPEAKER_EARPIECE";
  case AudioDeviceType::OUT_SPEAKER_SAFE:
    return "OUT_SPEAKER_SAFE";
  case AudioDeviceType::OUT_SUBMIX:
    return "OUT_SUBMIX";
  case AudioDeviceType::OUT_TELEPHONY_TX:
    return "OUT_TELEPHONY_TX";
  case AudioDeviceType::OUT_DOCK:
    return "OUT_DOCK";
  case AudioDeviceType::OUT_BROADCAST:
    return "OUT_BROADCAST";
  case AudioDeviceType::OUT_MULTICHANNEL_GROUP:
    return "OUT_MULTICHANNEL_GROUP";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioDeviceType, 36> enum_values<aidl::android::media::audio::common::AudioDeviceType> = {
  aidl::android::media::audio::common::AudioDeviceType::NONE,
  aidl::android::media::audio::common::AudioDeviceType::IN_DEFAULT,
  aidl::android::media::audio::common::AudioDeviceType::IN_ACCESSORY,
  aidl::android::media::audio::common::AudioDeviceType::IN_AFE_PROXY,
  aidl::android::media::audio::common::AudioDeviceType::IN_DEVICE,
  aidl::android::media::audio::common::AudioDeviceType::IN_ECHO_REFERENCE,
  aidl::android::media::audio::common::AudioDeviceType::IN_FM_TUNER,
  aidl::android::media::audio::common::AudioDeviceType::IN_HEADSET,
  aidl::android::media::audio::common::AudioDeviceType::IN_LOOPBACK,
  aidl::android::media::audio::common::AudioDeviceType::IN_MICROPHONE,
  aidl::android::media::audio::common::AudioDeviceType::IN_MICROPHONE_BACK,
  aidl::android::media::audio::common::AudioDeviceType::IN_SUBMIX,
  aidl::android::media::audio::common::AudioDeviceType::IN_TELEPHONY_RX,
  aidl::android::media::audio::common::AudioDeviceType::IN_TV_TUNER,
  aidl::android::media::audio::common::AudioDeviceType::IN_DOCK,
  aidl::android::media::audio::common::AudioDeviceType::IN_BUS,
  aidl::android::media::audio::common::AudioDeviceType::OUT_DEFAULT,
  aidl::android::media::audio::common::AudioDeviceType::OUT_ACCESSORY,
  aidl::android::media::audio::common::AudioDeviceType::OUT_AFE_PROXY,
  aidl::android::media::audio::common::AudioDeviceType::OUT_CARKIT,
  aidl::android::media::audio::common::AudioDeviceType::OUT_DEVICE,
  aidl::android::media::audio::common::AudioDeviceType::OUT_ECHO_CANCELLER,
  aidl::android::media::audio::common::AudioDeviceType::OUT_FM,
  aidl::android::media::audio::common::AudioDeviceType::OUT_HEADPHONE,
  aidl::android::media::audio::common::AudioDeviceType::OUT_HEADSET,
  aidl::android::media::audio::common::AudioDeviceType::OUT_HEARING_AID,
  aidl::android::media::audio::common::AudioDeviceType::OUT_LINE_AUX,
  aidl::android::media::audio::common::AudioDeviceType::OUT_SPEAKER,
  aidl::android::media::audio::common::AudioDeviceType::OUT_SPEAKER_EARPIECE,
  aidl::android::media::audio::common::AudioDeviceType::OUT_SPEAKER_SAFE,
  aidl::android::media::audio::common::AudioDeviceType::OUT_SUBMIX,
  aidl::android::media::audio::common::AudioDeviceType::OUT_TELEPHONY_TX,
  aidl::android::media::audio::common::AudioDeviceType::OUT_DOCK,
  aidl::android::media::audio::common::AudioDeviceType::OUT_BROADCAST,
  aidl::android::media::audio::common::AudioDeviceType::OUT_BUS,
  aidl::android::media::audio::common::AudioDeviceType::OUT_MULTICHANNEL_GROUP,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
