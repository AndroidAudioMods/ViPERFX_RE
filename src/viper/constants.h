#pragma once

#ifdef ANDROID_TOOLCHAIN
#include <android/errno.h>
#else
#include <cerrno>
#endif

#include "../log.h" // TODO: Remove this dependency

typedef enum {
    ARCH_UNKNOWN = 0,
    ARCH_ARM,
    ARCH_ARM64,
    ARCH_X86,
    ARCH_X86_64,
} arch_t;

#if defined(__arm__)
#define VIPER_ARCHITECTURE ARCH_ARM
#elif defined(__aarch64__)
#define VIPER_ARCHITECTURE ARCH_ARM64
#elif defined(__i386__)
#define VIPER_ARCHITECTURE ARCH_X86
#elif defined(__x86_64__)
#define VIPER_ARCHITECTURE ARCH_X86_64
#else
#warning "Unknown architecture"
#define VIPER_ARCHITECTURE ARCH_UNKNOWN
/*
 * Note from the developer:
 *
 * There's no architecture dependent code in ViPER4Android, this is just for debugging purposes.
 * Feel free to add your architecture if it's not listed here
 */
#endif

#define VIPER_NAME "ViPER4Android"
#define VIPER_AUTHORS "viper.WYF, Martmists, Iscle"
#define VIPER_DEFAULT_SAMPLING_RATE 44100