#include "TubeSimulator.h"

// Iscle: Verified with the latest version at 13/12/2022

TubeSimulator::TubeSimulator() :
    acc({
        0.0, 0.0
    }),
    enable(false) {}

void TubeSimulator::Reset() {
    this->acc[0] = 0.0;
    this->acc[1] = 0.0;
    this->enable = false;
}

void TubeSimulator::SetEnable(bool enable) {
    if (this->enable != enable) {
        if (!this->enable) {
            Reset();
        }
        this->enable = enable;
    }
}

void TubeSimulator::TubeProcess(float *buffer, uint32_t size) {
    if (!this->enable) return;

    for (uint32_t i = 0; i < size; i += 2) {
        this->acc[0] = (this->acc[0] + buffer[i * 2]) / 2.0;
        this->acc[1] = (this->acc[1] + buffer[i * 2 + 1]) / 2.0;
        buffer[i * 2] = (float) this->acc[0];
        buffer[i * 2 + 1] = (float) this->acc[1];
    }
}
