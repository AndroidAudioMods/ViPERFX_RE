/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/android/media/audio/eraser/Mode.aidl
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
namespace eraser {
enum class Mode : int8_t {
  ERASER = 0,
  CLASSIFIER = 1,
};

}  // namespace eraser
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace eraser {
[[nodiscard]] static inline std::string toString(Mode val) {
  switch(val) {
  case Mode::ERASER:
    return "ERASER";
  case Mode::CLASSIFIER:
    return "CLASSIFIER";
  default:
    return std::to_string(static_cast<int8_t>(val));
  }
}
}  // namespace eraser
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::media::audio::eraser::Mode, 2> enum_values<aidl::android::media::audio::eraser::Mode> = {
  aidl::android::media::audio::eraser::Mode::ERASER,
  aidl::android::media::audio::eraser::Mode::CLASSIFIER,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
