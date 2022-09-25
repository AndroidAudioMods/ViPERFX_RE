#pragma once

#include <cstdint>
#include "../utils/MinPhaseIIRCoeffs.h"

class IIRFilter {
public:
    IIRFilter(uint32_t bands);
    ~IIRFilter();

    void Process(float *samples, uint32_t size);
    void Reset();
    void SetBandLevel(uint32_t band, float level);
    void SetEnable(bool enable);
    void SetSamplingRate(uint32_t samplingRate);

private:
    uint32_t bands;
    uint32_t samplingRate;
    bool enable;
    MinPhaseIIRCoeffs coeffs;
    float buf[496];
    // 3 unknown
    float bandLevelsWithQ[31];
};


