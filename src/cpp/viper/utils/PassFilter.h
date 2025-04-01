#pragma once

#include <cstdint>
#include "IIR_NOrder_BW_LH.h"
#include <array>

class PassFilter {
public:
    PassFilter();

    void Reset();
    void ProcessFrames(float *buffer, uint32_t size);
    void SetSamplingRate(uint32_t samplingRate);

private:
    std::array<IIR_NOrder_BW_LH, 4> filters;
    uint32_t samplingRate;
};
