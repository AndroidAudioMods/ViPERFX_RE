#pragma once

#include <cstdint>
#include "../utils/MultiBiquad.h"
#include "../utils/Biquad.h"

class SpeakerCorrection {
public:
    SpeakerCorrection();
    ~SpeakerCorrection();

    void Process(float *samples, uint32_t size);
    void Reset();
    void SetEnable(bool enabled);
    void SetSamplingRate(uint32_t samplingRate);

    uint32_t samplingRate;
    bool enabled;
    MultiBiquad highpass[2];
    Biquad lowpass[2];
    Biquad bandpass[2];
};
