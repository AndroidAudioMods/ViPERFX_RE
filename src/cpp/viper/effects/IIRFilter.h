#pragma once

#include <cstdint>

class IIRFilter {
public:
    IIRFilter();
    ~IIRFilter();

    void Process(float *samples, uint32_t size);
    void Reset();
    void SetBandLevel();
    void SetEnable(bool enable);
    void SetSamplingRate(unsigned int i);
};


