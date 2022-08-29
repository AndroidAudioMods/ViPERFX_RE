#pragma once

#include <cstdint>

class SoftwareLimiter {
public:
    SoftwareLimiter();
    ~SoftwareLimiter();

    void Process(float *samples, uint32_t size);
    void ResetLimiter();
    void SetGate();
};


