#pragma once

#include <cstdint>
#include "Biquad.h"
#include "TimeConstDelay.h"

class DepthSurround {
public:
    DepthSurround();

    void Process(float *samples, uint32_t size);
    void RefreshStrength(short strength);
    void SetSamplingRate(uint32_t samplingRate);
    void SetStrength(short strength);

private:
    short strength;
    bool enabled;
    bool strengthAtLeast500;
    float gain;
    float prev[2];
    TimeConstDelay timeConstDelay[2];
    Biquad highpass;
};
