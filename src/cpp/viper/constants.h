//
// Created by mart on 7/25/21.
//

#pragma once

#ifdef ANDROID_TOOLCHAIN
#include <android/errno.h>
#else
#include <cerrno>
#endif

#include "../log.h" // TODO: Remove this dependency

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#define VERSION_STRING "v" STR(VERSION_MAJOR) "." STR(VERSION_MINOR)

#define DEFAULT_SAMPLERATE 44100
#define VIPER_AUTHORS "viper.WYF, Martmists, Iscle"