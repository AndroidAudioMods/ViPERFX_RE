#pragma once

#define TAG "ViPER4Android"

#ifdef __hexagon__
#define FARF_HIGH 1
#define FARF_MEDIUM 1
#define FARF_ERROR 1
#define FARF_LOW 1
#include <HAP_farf.h>

#define VIPER_LOGF(...) FARF(FATAL, TAG ": " __VA_ARGS__)
#define VIPER_LOGD(...) FARF(LOW, TAG ": " __VA_ARGS__)
#define VIPER_LOGI(...) FARF(MEDIUM, TAG ": " __VA_ARGS__)
#define VIPER_LOGE(...) FARF(ERROR, TAG ": " __VA_ARGS__)
#else
#include <android/log.h>

#define VIPER_LOGF(...) __android_log_print(ANDROID_LOG_FATAL, TAG, __VA_ARGS__)
#define VIPER_LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define VIPER_LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define VIPER_LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)
#endif
