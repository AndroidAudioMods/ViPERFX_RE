/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/CommandId.aidl
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
namespace hardware {
namespace audio {
namespace effect {
enum class CommandId : int32_t {
  START = 0,
  STOP = 1,
  RESET = 2,
  VENDOR_COMMAND_0 = 256,
  VENDOR_COMMAND_1 = 257,
  VENDOR_COMMAND_2 = 258,
  VENDOR_COMMAND_3 = 259,
  VENDOR_COMMAND_4 = 260,
  VENDOR_COMMAND_5 = 261,
  VENDOR_COMMAND_6 = 262,
  VENDOR_COMMAND_7 = 263,
  VENDOR_COMMAND_8 = 264,
  VENDOR_COMMAND_9 = 265,
};

}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
[[nodiscard]] static inline std::string toString(CommandId val) {
  switch(val) {
  case CommandId::START:
    return "START";
  case CommandId::STOP:
    return "STOP";
  case CommandId::RESET:
    return "RESET";
  case CommandId::VENDOR_COMMAND_0:
    return "VENDOR_COMMAND_0";
  case CommandId::VENDOR_COMMAND_1:
    return "VENDOR_COMMAND_1";
  case CommandId::VENDOR_COMMAND_2:
    return "VENDOR_COMMAND_2";
  case CommandId::VENDOR_COMMAND_3:
    return "VENDOR_COMMAND_3";
  case CommandId::VENDOR_COMMAND_4:
    return "VENDOR_COMMAND_4";
  case CommandId::VENDOR_COMMAND_5:
    return "VENDOR_COMMAND_5";
  case CommandId::VENDOR_COMMAND_6:
    return "VENDOR_COMMAND_6";
  case CommandId::VENDOR_COMMAND_7:
    return "VENDOR_COMMAND_7";
  case CommandId::VENDOR_COMMAND_8:
    return "VENDOR_COMMAND_8";
  case CommandId::VENDOR_COMMAND_9:
    return "VENDOR_COMMAND_9";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::hardware::audio::effect::CommandId, 13> enum_values<aidl::android::hardware::audio::effect::CommandId> = {
  aidl::android::hardware::audio::effect::CommandId::START,
  aidl::android::hardware::audio::effect::CommandId::STOP,
  aidl::android::hardware::audio::effect::CommandId::RESET,
  aidl::android::hardware::audio::effect::CommandId::VENDOR_COMMAND_0,
  aidl::android::hardware::audio::effect::CommandId::VENDOR_COMMAND_1,
  aidl::android::hardware::audio::effect::CommandId::VENDOR_COMMAND_2,
  aidl::android::hardware::audio::effect::CommandId::VENDOR_COMMAND_3,
  aidl::android::hardware::audio::effect::CommandId::VENDOR_COMMAND_4,
  aidl::android::hardware::audio::effect::CommandId::VENDOR_COMMAND_5,
  aidl::android::hardware::audio::effect::CommandId::VENDOR_COMMAND_6,
  aidl::android::hardware::audio::effect::CommandId::VENDOR_COMMAND_7,
  aidl::android::hardware::audio::effect::CommandId::VENDOR_COMMAND_8,
  aidl::android::hardware::audio::effect::CommandId::VENDOR_COMMAND_9,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
