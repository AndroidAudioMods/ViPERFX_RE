#pragma once

#include <cstdint>
#include "../utils/MultiBiquad.h"
#include "../utils/FixedBiquad.h"

class SpeakerCorrection {
public:
    SpeakerCorrection();
    ~SpeakerCorrection();

    void Process(float *samples, uint32_t size);
    void Reset();
    void SetEnable(bool enabled);
    void SetSamplingRate(uint32_t samplerate);

    uint32_t samplerate;
    bool enabled;
    MultiBiquad highpass[2];
    FixedBiquad lowpass[2];
    FixedBiquad bandpass[2];
};
