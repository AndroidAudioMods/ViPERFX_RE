#pragma once

#include <cstdint>

class TubeSimulator {
public:
    TubeSimulator();
    ~TubeSimulator();

    void Reset();
    void TubeProcess(float *buffer, uint32_t size);

    float acc[2];
    bool enabled;
};

