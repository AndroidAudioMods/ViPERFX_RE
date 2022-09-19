#pragma once

#include <cstdint>
#include "../utils/NoiseSharpening.h"
#include "../utils/HiFi.h"
#include "../utils/HighShelf.h"

class ViPERClarity {
public:
    enum ClarityMode {
        NATURAL,
        OZONE,
        XHIFI
    };

    ViPERClarity();

    void Process(float *samples, uint32_t size);
    void Reset();
    void SetClarity(float gainPercent);
    void SetClarityToFilter();
    void SetProcessMode(ClarityMode processMode);
    void SetSamplingRate(uint32_t samplingRate);

private:
    NoiseSharpening noiseSharpening;
    HighShelf highShelf[2];
    HiFi hifi;
    ClarityMode processMode;
    uint32_t samplingRate;
    float clarityGainPercent;
};


