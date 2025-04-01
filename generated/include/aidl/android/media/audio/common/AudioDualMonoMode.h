/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioDualMonoMode.aidl
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
enum class AudioDualMonoMode : int32_t {
  OFF = 0,
  LR = 1,
  LL = 2,
  RR = 3,
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
[[nodiscard]] static inline std::string toString(AudioDualMonoMode val) {
  switch(val) {
  case AudioDualMonoMode::OFF:
    return "OFF";
  case AudioDualMonoMode::LR:
    return "LR";
  case AudioDualMonoMode::LL:
    return "LL";
  case AudioDualMonoMode::RR:
    return "RR";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioDualMonoMode, 4> enum_values<aidl::android::media::audio::common::AudioDualMonoMode> = {
  aidl::android::media::audio::common::AudioDualMonoMode::OFF,
  aidl::android::media::audio::common::AudioDualMonoMode::LR,
  aidl::android::media::audio::common::AudioDualMonoMode::LL,
  aidl::android::media::audio::common::AudioDualMonoMode::RR,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
