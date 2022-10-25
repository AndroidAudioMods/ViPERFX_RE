#pragma once

#include <android/log.h>

#define TAG "ViPER4Android"

#define VIPER_LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define VIPER_LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define VIPER_LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)