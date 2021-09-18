//
// Created by mart on 9/18/21.
//

#pragma once


#include "../utils/PConvSingle_F32.h"
#include "../utils/WaveBuffer_I32.h"

class VHE {
public:
    VHE();
    ~VHE();

    void Process(float* source, float* dest, int frameSize);
    void Reset();

    bool GetEnabled();
    void SetEffectLevel(uint32_t level);
    void SetEnable(bool enabled);
    void SetSamplingRate(uint32_t srate);

    PConvSingle_F32 convLeft, convRight;
    WaveBuffer_I32 *bufA, *bufB;
    uint32_t samplerate;
    bool enabled;
    int effectLevel;
    int convSize;
};


