#pragma once

#ifdef ANDROID_TOOLCHAIN
#include <android/log.h>
#else
#define __android_log_write(...) do {} while (0)
#define __android_log_print(...) do {} while (0)
#define ANDROID_LOG_INFO 1
#endif

#define v4a_print(status, message) __android_log_write(status, "ViPER4Android_Reworked", message)
#define v4a_printf(status, format, ...) __android_log_print(status, "ViPER4Android_Reworked", format, __VA_ARGS__)