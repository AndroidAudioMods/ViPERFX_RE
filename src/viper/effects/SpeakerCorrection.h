#pragma once

#include <cstdint>
#include "../utils/MultiBiquad.h"
#include "../utils/Biquad.h"

class SpeakerCorrection {
public:
    SpeakerCorrection();

    void Process(float *samples, uint32_t size);
    void Reset();
    void SetEnable(bool enable);
    void SetSamplingRate(uint32_t samplingRate);

private:
    uint32_t samplingRate;
    bool enable;
    MultiBiquad highPass[2];
    Biquad lowPass[2];
    Biquad bandPass[2];
};
