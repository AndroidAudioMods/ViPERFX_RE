#pragma once

#include <cstdint>

class AidlVersions {
public:
    const static uint32_t ANDROID_HARDWARE_AUDIO_COMMON_MAX_VERSION = 1;
    const static uint32_t ANDROID_HARDWARE_AUDIO_EFFECT_MAX_VERSION = 3;
    const static uint32_t ANDROID_HARDWARE_COMMON_MAX_VERSION = 1;
    const static uint32_t ANDROID_HARDWARE_COMMON_FMQ_MAX_VERSION = 1;
    const static uint32_t ANDROID_MEDIA_AUDIO_COMMON_TYPES_MAX_VERSION = 4;
    const static uint32_t ANDROID_MEDIA_AUDIO_ERASER_TYPES_MAX_VERSION = 1;

    static void init();

    static inline uint32_t androidHardwareAudioCommonVersion = 0;
    static inline uint32_t androidHardwareAudioEffectVersion = 0;
    static inline uint32_t androidHardwareCommonVersion = 0;
    static inline uint32_t androidHardwareCommonFmqVersion = 0;
    static inline uint32_t androidMediaAudioCommonTypesVersion = 0;
    static inline uint32_t androidMediaAudioEraserTypesVersion = 0;
};
