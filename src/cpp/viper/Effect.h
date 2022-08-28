//
// Created by mart on 7/25/21.
//

#pragma once

#include <cstdint>
#include "essential.h"

class Effect {
public:
    Effect();

    ~Effect();

    virtual int32_t command(uint32_t cmdCode, uint32_t cmdSize, void *pCmdData, uint32_t *replySize, void *pReplyData);

    int32_t process(audio_buffer_s *in, audio_buffer_s *out);

    int32_t configure(effect_config_t *config);

    bool enabled;
    bool configureOk;
    uint32_t sampleRate;
    effect_config_t config;
    // Misc data here?

    // TODO: Figure out what buffer is used for
    float *buffer;
    uint32_t bufferSize;
    void *instance;  // type: ViPER
};
