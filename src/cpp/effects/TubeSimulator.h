//
// Created by mart on 7/26/21.
//

#pragma once

#include <cstdint>

class TubeSimulator {
public:
    TubeSimulator();

    void Reset();
    void TubeProcess(float* buffer, uint32_t size);

    float acc[2];
    bool enabled;
};

