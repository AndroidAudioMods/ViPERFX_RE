#pragma once

#include <cstdint>
#include "../utils/MultiBiquad.h"
#include "../utils/Biquad.h"
#include <array>

// Iscle: Verified with the latest version at 13/12/2022

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
    std::array<MultiBiquad, 2> highPass;
    std::array<Biquad, 2> lowPass;
    std::array<Biquad, 2> bandPass;
};
