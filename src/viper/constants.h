#pragma once

#ifdef ANDROID_TOOLCHAIN
#include <android/errno.h>
#else
#include <cerrno>
#endif

#include "../log.h" // TODO: Remove this dependency

#define VIPER_DEFAULT_SAMPLING_RATE 44100
#define VIPER_AUTHORS "viper.WYF, Martmists, Iscle"