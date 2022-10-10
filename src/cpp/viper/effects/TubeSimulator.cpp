#include "TubeSimulator.h"

TubeSimulator::TubeSimulator() {
    this->acc[0] = 0.f;
    this->acc[1] = 0.f;
    this->enable = false;
}

void TubeSimulator::Reset() {
    this->acc[0] = 0.f;
    this->acc[1] = 0.f;
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
    if (this->enable) {
        for (int x = 0; x < size; x++) {
            this->acc[0] = (this->acc[0] + buffer[2 * x]) / 2.f;
            this->acc[1] = (this->acc[1] + buffer[2 * x + 1]) / 2.f;
            buffer[2 * x] = this->acc[0];
            buffer[2 * x + 1] = this->acc[1];
        }
    }
}

TubeSimulator::~TubeSimulator() {

}
