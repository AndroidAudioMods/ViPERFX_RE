//
// Created by mart on 7/25/21.
//

#pragma once

#ifdef ANDROID_TOOLCHAIN
#include <android/log.h>
#include <android/errno.h>
#else
#define __android_log_write(...) do {} while (0)
#define __android_log_print(...) do {} while (0)
#define ANDROID_LOG_INFO 1
#include <errno.h>
#endif

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#define VERSION_STRING STR(VERSION_MAJOR) "." STR(VERSION_MINOR) "." STR(VERSION_REVISION) "." STR(VERSION_BUILD)

#define DEFAULT_SAMPLERATE 44100
#define v4a_print(status, message) __android_log_write(status, "ViPER4Android_Reworked", message)
#define v4a_printf(status, format, ...) __android_log_print(status, "ViPER4Android_Reworked", format, __VA_ARGS__)