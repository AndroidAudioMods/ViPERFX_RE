#pragma once

#include <cstdint>

class AidlVersions {
public:
    const static uint32_t ANDROID_HARDWARE_AUDIO_COMMON_MAX_VERSION = 5;
    const static uint32_t ANDROID_HARDWARE_AUDIO_EFFECT_MAX_VERSION = 4;
    const static uint32_t ANDROID_HARDWARE_COMMON_MAX_VERSION = 3;
    const static uint32_t ANDROID_HARDWARE_COMMON_FMQ_MAX_VERSION = 2;
    const static uint32_t ANDROID_MEDIA_AUDIO_COMMON_TYPES_MAX_VERSION = 5;
    const static uint32_t ANDROID_MEDIA_AUDIO_ERASER_TYPES_MAX_VERSION = 2;

    uint32_t androidHardwareAudioCommonVersion = 0;
    uint32_t androidHardwareAudioEffectVersion = 0;
    uint32_t androidHardwareCommonVersion = 0;
    uint32_t androidHardwareCommonFmqVersion = 0;
    uint32_t androidMediaAudioCommonTypesVersion = 0;
    uint32_t androidMediaAudioEraserTypesVersion = 0;

    static inline AidlVersions &instance() {
        static AidlVersions instance;
        return instance;
    }
private:
    AidlVersions();

    void findAndroidHardwareAudioCommonVersion();
    void findAndroidHardwareAudioEffectVersion();
    void findAndroidHardwareCommonVersion();
    void findAndroidHardwareCommonFmqVersion();
    void findAndroidMediaAudioCommonTypesVersion();
    void findAndroidMediaAudioEraserTypesVersion();
};
