/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/android/media/audio/eraser/SoundClassification.aidl
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
enum class SoundClassification : int32_t {
  HUMAN = 0,
  ANIMAL = 1,
  NATURE = 2,
  MUSIC = 3,
  THINGS = 4,
  AMBIGUOUS = 5,
  ENVIRONMENT = 6,
  VENDOR_EXTENSION = 7,
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
[[nodiscard]] static inline std::string toString(SoundClassification val) {
  switch(val) {
  case SoundClassification::HUMAN:
    return "HUMAN";
  case SoundClassification::ANIMAL:
    return "ANIMAL";
  case SoundClassification::NATURE:
    return "NATURE";
  case SoundClassification::MUSIC:
    return "MUSIC";
  case SoundClassification::THINGS:
    return "THINGS";
  case SoundClassification::AMBIGUOUS:
    return "AMBIGUOUS";
  case SoundClassification::ENVIRONMENT:
    return "ENVIRONMENT";
  case SoundClassification::VENDOR_EXTENSION:
    return "VENDOR_EXTENSION";
  default:
    return std::to_string(static_cast<int32_t>(val));
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
constexpr inline std::array<aidl::android::media::audio::eraser::SoundClassification, 8> enum_values<aidl::android::media::audio::eraser::SoundClassification> = {
  aidl::android::media::audio::eraser::SoundClassification::HUMAN,
  aidl::android::media::audio::eraser::SoundClassification::ANIMAL,
  aidl::android::media::audio::eraser::SoundClassification::NATURE,
  aidl::android::media::audio::eraser::SoundClassification::MUSIC,
  aidl::android::media::audio::eraser::SoundClassification::THINGS,
  aidl::android::media::audio::eraser::SoundClassification::AMBIGUOUS,
  aidl::android::media::audio::eraser::SoundClassification::ENVIRONMENT,
  aidl::android::media::audio::eraser::SoundClassification::VENDOR_EXTENSION,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
