#pragma once

#include <cstdint>
#include "../utils/PConvSingle_F32.h"
#include "../utils/WaveBuffer.h"

class VHE {
public:
    VHE();
    ~VHE();

    bool GetEnabled();
    uint32_t Process(float *source, float *dest, uint32_t frameSize);
    void Reset();
    void SetEffectLevel(uint32_t level);
    void SetEnable(bool enabled);
    void SetSamplingRate(uint32_t srate);

    PConvSingle_F32 convLeft, convRight;
    WaveBuffer *bufA, *bufB;
    uint32_t samplingRate;
    bool enabled;
    int effectLevel;
    int convSize;
};


