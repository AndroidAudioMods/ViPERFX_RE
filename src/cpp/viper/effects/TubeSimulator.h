#pragma once

#include <cstdint>

class TubeSimulator {
public:
    TubeSimulator();
    ~TubeSimulator();

    void Reset();
    void SetEnable(bool enable);
    void TubeProcess(float *buffer, uint32_t size);

private:
    float acc[2];
    bool enable;
};

