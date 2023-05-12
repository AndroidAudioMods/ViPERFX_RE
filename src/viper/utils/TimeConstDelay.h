#pragma once

#include <cstdint>
#include <vector>

class TimeConstDelay {
public:
    TimeConstDelay();

    float ProcessSample(float sample);
    void SetParameters(uint32_t samplingRate, float delay);

private:
    std::vector<float> samples;
    uint32_t offset;
    uint32_t sampleCount;
};
