//
// Created by mart on 7/26/21.
//
#pragma once

#include <cstdint>

class TimeConstDelay {
public:
    TimeConstDelay();

    ~TimeConstDelay();

    float ProcessSample(float sample);

    void SetParameters(uint32_t samplerate, float delay);

    float *samples;
    uint32_t offset;
    uint32_t sampleCount;
};
