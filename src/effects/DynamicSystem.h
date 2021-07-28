//
// Created by mart on 7/28/21.
//

#pragma once

#include <cstdint>
#include "../utils/DynamicBass.h"

class DynamicSystem {
public:
    DynamicSystem();

    void Process(float* samples, uint32_t size);
    void Reset();

    void SetBassGain(float gain);
    void SetEnable(bool enable);
    void SetSideGain(float gainX, float gainY);
    void SetXCoeffs(uint32_t low, uint32_t high);
    void SetYCoeffs(uint32_t low, uint32_t high);
    void SetSamplingRate(uint32_t samplerate);

    DynamicBass bass;
    uint32_t samplerate;
    bool enabled;
};


