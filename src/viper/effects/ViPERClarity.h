#pragma once

#include <cstdint>
#include "../utils/NoiseSharpening.h"
#include "../utils/HiFi.h"
#include "../utils/HighShelf.h"

// Iscle: Verified with the latest version at 13/12/2022

class ViPERClarity {
public:
    enum class ClarityMode : uint8_t {
        NATURAL = 0,
        OZONE,
        XHIFI
    };

    ViPERClarity();

    void Process(float *samples, uint32_t size);
    void Reset();
    void SetClarity(float gainPercent);
    void SetClarityToFilter();
    void SetEnable(bool enable);
    void SetProcessMode(ClarityMode processMode);
    void SetSamplingRate(uint32_t samplingRate);

private:
    NoiseSharpening noiseSharpening;
    HighShelf highShelf[2];
    HiFi hifi;
    bool enable;
    ClarityMode processMode;
    uint32_t samplingRate;
    float clarityGainPercent;
};


