#pragma once

#include <cstdint>
#include "../utils/WaveBuffer_I32.h"

class DiffSurround {
public:
    DiffSurround();
    ~DiffSurround();

    void Process(float *samples, uint32_t size);
    void Reset();
    void SetDelayTime(float value);
    void SetEnable(bool enabled);
    void SetSamplingRate(uint32_t samplerate);

    uint32_t samplerate;
    bool enabled;
    float delayTime;
    WaveBuffer_I32 *buffers[2];
};


