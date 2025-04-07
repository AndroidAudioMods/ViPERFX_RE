#include "AidlVersions.h"
#include "log/log.h"
#include <string>
#include <dlfcn.h>

AidlVersions::AidlVersions() {
    ALOGD("AidlVersions::init()");
    findAndroidHardwareAudioCommonVersion();
    findAndroidHardwareAudioEffectVersion();
    findAndroidHardwareCommonVersion();
    findAndroidHardwareCommonFmqVersion();
    findAndroidMediaAudioCommonTypesVersion();
    findAndroidMediaAudioEraserTypesVersion();
}

void AidlVersions::findAndroidHardwareAudioCommonVersion() {
    char tmp[128];
    for (uint32_t i = ANDROID_HARDWARE_AUDIO_COMMON_MAX_VERSION; i > 0; i--) {
        snprintf(tmp, sizeof(tmp), "android.hardware.audio.common-V%u-ndk.so", i);
        void *handle = dlopen(tmp, RTLD_LAZY);
        if (handle) {
            ALOGD("Found android.hardware.audio.common-V%u-ndk.so", i);
            androidHardwareAudioCommonVersion = i;
            dlclose(handle);
            break;
        }
    }
}

void AidlVersions::findAndroidHardwareAudioEffectVersion() {
    char tmp[128];
    for (uint32_t i = ANDROID_HARDWARE_AUDIO_EFFECT_MAX_VERSION; i > 0; i--) {
        snprintf(tmp, sizeof(tmp), "android.hardware.audio.effect-V%u-ndk.so", i);
        void *handle = dlopen(tmp, RTLD_LAZY);
        if (handle) {
            ALOGD("Found android.hardware.audio.effect-V%u-ndk.so", i);
            androidHardwareAudioEffectVersion = i;
            dlclose(handle);
            break;
        }
    }
    if (androidHardwareAudioEffectVersion == 0) {
        ALOGE("Failed to find android.hardware.audio.effect version!");
    }
}

void AidlVersions::findAndroidHardwareCommonVersion() {
    char tmp[128];
    for (uint32_t i = ANDROID_HARDWARE_COMMON_MAX_VERSION; i > 0; i--) {
        snprintf(tmp, sizeof(tmp), "android.hardware.common-V%u-ndk.so", i);
        void *handle = dlopen(tmp, RTLD_LAZY);
        if (handle) {
            ALOGD("Found android.hardware.common-V%u-ndk.so", i);
            androidHardwareCommonVersion = i;
            dlclose(handle);
            break;
        }
    }
    if (androidHardwareCommonVersion == 0) {
        ALOGE("Failed to find android.hardware.common version!");
    }
}

void AidlVersions::findAndroidHardwareCommonFmqVersion() {
    char tmp[128];
    for (uint32_t i = ANDROID_HARDWARE_COMMON_FMQ_MAX_VERSION; i > 0; i--) {
        snprintf(tmp, sizeof(tmp), "android.hardware.common.fmq-V%u-ndk.so", i);
        void *handle = dlopen(tmp, RTLD_LAZY);
        if (handle) {
            ALOGD("Found android.hardware.common.fmq-V%u-ndk.so", i);
            androidHardwareCommonFmqVersion = i;
            dlclose(handle);
            break;
        }
    }
    if (androidHardwareCommonFmqVersion == 0) {
        ALOGE("Failed to find android.hardware.common.fmq version!");
    }
}

void AidlVersions::findAndroidMediaAudioCommonTypesVersion() {
    char tmp[128];
    for (uint32_t i = ANDROID_MEDIA_AUDIO_COMMON_TYPES_MAX_VERSION; i > 0; i--) {
        snprintf(tmp, sizeof(tmp), "android.media.audio.common.types-V%u-ndk.so", i);
        void *handle = dlopen(tmp, RTLD_LAZY);
        if (handle) {
            ALOGD("Found android.media.audio.common.types-V%u-ndk.so", i);
            androidMediaAudioCommonTypesVersion = i;
            dlclose(handle);
            break;
        }
    }
    if (androidMediaAudioCommonTypesVersion == 0) {
        ALOGE("Failed to find android.media.audio.common.types version!");
    }
}

void AidlVersions::findAndroidMediaAudioEraserTypesVersion() {
    char tmp[128];
    // TODO
}
