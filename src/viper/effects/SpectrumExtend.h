#pragma once

#include <cstdint>
#include "../utils/Harmonic.h"
#include "../utils/MultiBiquad.h"
#include <array>

class SpectrumExtend {
public:
    SpectrumExtend();

    void Process(float *samples, uint32_t size);
    void Reset();
    void SetEnable(bool enable);
    void SetExciter(float value);
    void SetReferenceFrequency(uint32_t freq);
    void SetSamplingRate(uint32_t samplingRate);

private:
    std::array<MultiBiquad, 2> highpass;
    std::array<MultiBiquad, 2> lowpass;
    std::array<Harmonic, 2> harmonics;
    bool enabled;
    uint32_t samplingRate;
    uint32_t referenceFreq;
    float exciter;
};


