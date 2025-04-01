#pragma once

#include <cstdint>
#include "../utils/PConvSingle.h"
#include "../utils/WaveBuffer.h"

class VHE {
public:
    VHE();
    ~VHE();

    bool GetEnabled();
    uint32_t Process(float *source, float *dest, uint32_t frameSize);
    void Reset();
    void SetEffectLevel(uint32_t effectLevel);
    void SetEnable(bool enabled);
    void SetSamplingRate(uint32_t samplingRate);

private:
    PConvSingle convLeft, convRight;
    WaveBuffer *bufA, *bufB;
    uint32_t samplingRate;
    bool enabled;
    uint32_t effectLevel;
    uint32_t convSize;
};


