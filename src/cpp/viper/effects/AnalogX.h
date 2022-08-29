#pragma once

#include <cstdint>
#include "../utils/Harmonic.h"
#include "../utils/MultiBiquad.h"

class AnalogX {
public:
    AnalogX();
    ~AnalogX();

    void Process(float *samples, uint32_t size);
    void Reset();
    void SetProcessingModel(int model);
    void SetSamplingRate(uint32_t samplerate);

    MultiBiquad highpass[2];
    Harmonic harmonics[2];
    MultiBiquad lowpass[2];
    MultiBiquad peak[2];

    float gain;
    uint32_t freqRange;
    int processingModel;
    uint32_t samplerate;
    bool enabled;
};


