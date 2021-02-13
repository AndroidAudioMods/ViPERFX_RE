//
// Created by mart on 2/12/21.
//

#ifndef VIPER_MISC_H
#define VIPER_MISC_H

#include <cstdarg>
#include <cstdio>
#include <iostream>

typedef unsigned char   undefined;
typedef unsigned char    byte;
typedef long long    longlong;
typedef unsigned int    uint;
typedef unsigned long long    ulonglong;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;

#define OK 0

union audio_buffer {
    int * s32;
    short * s16;
    byte * s8;
    void * raw;
};

struct buffer_provider_t {
    int (* getBuffer)(void *, struct audio_buffer_t *);
    int (* releaseBuffer)(void *, struct audio_buffer_t *);
    void * cookie;
};

struct audio_buffer_t {
    int frameCount;
    union audio_buffer buffer;
};

struct buffer_config_t {
    struct audio_buffer_t buffer;
    uint samplingRate;
    uint channels;
    struct buffer_provider_t bufferProvider;
    byte format;
    byte accessMode;
    short mask;
};

struct effect_config_t {
    struct buffer_config_t inputCfg;
    struct buffer_config_t outputCfg;
};

struct audio_buffer_s { // PlaceHolder Structure
};

typedef struct effect_uuid_s { // PlaceHolder Structure
    int field_0x0;
    short field_0x4;
    short field_0x6;
    short field_0x8;
    char field_0xa;
    char field_0xb;
    char field_0xc;
    char field_0xd;
    char field_0xe;
    char field_0xf;
} effect_uuid_t;

typedef struct effect_descriptor_s {
    effect_uuid_t type;     // UUID of to the OpenSL ES interface implemented by this effect
    effect_uuid_t uuid;     // UUID for this particular implementation
    uint32_t apiVersion;    // Version of the effect control API implemented
    uint32_t flags;         // effect engine capabilities/requirements flags (see below)
    uint16_t cpuLoad;       // CPU load indication (see below)
    uint16_t memoryUsage;   // Data Memory usage (see below)
    char    name[64];   // human readable effect name
    char    implementor[64];    // human readable effect implementor name
} effect_descriptor_t;

// Dummy replacement
void __android_log_print(int n, const std::string& name, const std::string& fmt, ...) {
    va_list ap;

    std::cout << "[" << name << "]: ";
    va_start(ap, fmt);
    printf(fmt.c_str(), ap);
    va_end(ap);
    std::cout << "\n";
}

uint FUN_00063c3c(byte *param_1,int param_2);
float FUN_00067ef8(float param_1,float param_2);

#endif //VIPER_MISC_H
