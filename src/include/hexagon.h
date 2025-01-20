#pragma once

#include "essential.h"

typedef struct {
    uint32_t   frameCount;      // number of frames in buffer
    union {
        uint32_t    raw;        // raw pointer to start of buffer
        uint32_t    f32;        // pointer to float 32 bit data at start of buffer
        uint32_t    s32;        // pointer to signed 32 bit data at start of buffer
        uint32_t    s16;        // pointer to signed 16 bit data at start of buffer
        uint32_t    u8;         // pointer to unsigned 8 bit data at start of buffer
    };
} hexagon_audio_buffer_t;

typedef struct
{
    uint32_t getBuffer;       // retrieve next buffer
    uint32_t releaseBuffer;   // release used buffer
    uint32_t cookie;         // for use by client of buffer provider functions
} hexagon_buffer_provider_t;

typedef struct {
    hexagon_audio_buffer_t  buffer;     // buffer for use by process() function if not passed explicitly
    uint32_t   samplingRate;    // sampling rate
    uint32_t   channels;        // channel mask (see audio_channel_mask_t in audio.h)
    hexagon_buffer_provider_t bufferProvider;   // buffer provider
    uint8_t    format;          // Audio format (see audio_format_t in audio.h)
    uint8_t    accessMode;      // read/write or accumulate in buffer (effect_buffer_access_e)
    uint16_t   mask;            // indicates which of the above fields is valid
} hexagon_buffer_config_t;

typedef struct {
    hexagon_buffer_config_t inputCfg;
    hexagon_buffer_config_t outputCfg;
} hexagon_effect_config_t;

static_assert(sizeof(hexagon_effect_config_t) == 64, "hexagon_effect_config_t must be 64 bytes");

static inline void host2hexagon(buffer_config_t *in, hexagon_buffer_config_t *out) {
    if (in->mask & EFFECT_CONFIG_SMP_RATE) {
        out->mask |= EFFECT_CONFIG_SMP_RATE;
        out->samplingRate = in->samplingRate;
    }

    if (in->mask & EFFECT_CONFIG_CHANNELS) {
        out->mask |= EFFECT_CONFIG_CHANNELS;
        out->channels = in->channels;
    }

    if (in->mask & EFFECT_CONFIG_FORMAT) {
        out->mask |= EFFECT_CONFIG_FORMAT;
        out->format = in->format;
    }

    if (in->mask & EFFECT_CONFIG_ACC_MODE) {
        out->mask |= EFFECT_CONFIG_ACC_MODE;
        out->accessMode = in->accessMode;
    }
}

static inline void host2hexagon(effect_config_t *in, hexagon_effect_config_t *out) {
    memset(out, 0, sizeof(*out));
    host2hexagon(&in->inputCfg, &out->inputCfg);
    host2hexagon(&in->outputCfg, &out->outputCfg);
}

static inline void hexagon2host(hexagon_buffer_config_t *in, buffer_config_t *out) {
    if (in->mask & EFFECT_CONFIG_SMP_RATE) {
        out->mask |= EFFECT_CONFIG_SMP_RATE;
        out->samplingRate = in->samplingRate;
    }

    if (in->mask & EFFECT_CONFIG_CHANNELS) {
        out->mask |= EFFECT_CONFIG_CHANNELS;
        out->channels = in->channels;
    }

    if (in->mask & EFFECT_CONFIG_FORMAT) {
        out->mask |= EFFECT_CONFIG_FORMAT;
        out->format = in->format;
    }

    if (in->mask & EFFECT_CONFIG_ACC_MODE) {
        out->mask |= EFFECT_CONFIG_ACC_MODE;
        out->accessMode = in->accessMode;
    }
}

static inline void hexagon2host(hexagon_effect_config_t *in, effect_config_t *out) {
    memset(out, 0, sizeof(*out));
    hexagon2host(&in->inputCfg, &out->inputCfg);
    hexagon2host(&in->outputCfg, &out->outputCfg);
}
