#pragma once

#include <cstdint>

class TimeConstDelay {
public:
    TimeConstDelay();
    ~TimeConstDelay();

    float ProcessSample(float sample);
    void SetParameters(uint32_t samplingRate, float delay);

private:
    float *samples;
    uint32_t offset;
    uint32_t sampleCount;
};
