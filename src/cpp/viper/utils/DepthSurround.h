#pragma once

#include <cstdint>
#include "FixedBiquad.h"
#include "TimeConstDelay.h"


class DepthSurround {
public:
    DepthSurround();

    void Process(float *samples, uint32_t size);

    void RefreshStrength(short strength);

    void SetSamplingRate(uint32_t samplerate);

    void SetStrength(short strength);

    short strength;
    bool enabled;
    bool strengthAtLeast500;
    uint32_t gain;
    float prev[2];
    TimeConstDelay delay[2];
    FixedBiquad highpass;
};
