//
// Created by mart on 7/28/21.
//

#pragma once

#include "../utils/CRevModel.h"

class Reverberation {
public:
    Reverberation();

    void Reset();

    void Process(float *buffer, uint32_t size);

    void SetEnable(bool enable);

    void SetRoomSize(float value);

    void SetDamp(float value);

    void SetWet(float value);

    void SetDry(float value);

    void SetWidth(float value);

    void SetSamplingRate(uint32_t value);

    float roomsize;
    float width;
    float damp;
    float wet;
    float dry;
    CRevModel model;
    uint32_t samplerate;
    bool enabled;
};



