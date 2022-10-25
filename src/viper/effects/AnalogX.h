#pragma once

#include <cstdint>
#include "../utils/Harmonic.h"
#include "../utils/MultiBiquad.h"

class AnalogX {
public:
    AnalogX();

    void Process(float *samples, uint32_t size);
    void Reset();
    void SetEnable(bool enable);
    void SetProcessingModel(int processingModel);
    void SetSamplingRate(uint32_t samplingRate);

private:
    MultiBiquad highPass[2];
    Harmonic harmonic[2];
    MultiBiquad lowPass[2];
    MultiBiquad peak[2];

    float gain;
    uint32_t freqRange;
    int processingModel;
    uint32_t samplingRate;
    bool enable;
};


