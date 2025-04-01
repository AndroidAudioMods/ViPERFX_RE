#pragma once

#include <cstdint>
#include "../utils/DynamicBass.h"

class DynamicSystem {
public:
    DynamicSystem();

    void Process(float *samples, uint32_t size);
    void Reset();
    void SetBassGain(float gain);
    void SetEnable(bool enable);
    void SetSamplingRate(uint32_t samplingRate);
    void SetSideGain(float gainX, float gainY);
    void SetXCoeffs(uint32_t low, uint32_t high);
    void SetYCoeffs(uint32_t low, uint32_t high);

private:
    DynamicBass dynamicBass;
    uint32_t samplingRate;
    bool enable;
};


