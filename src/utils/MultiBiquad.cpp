//
// Created by mart on 7/27/21.
//

#include "MultiBiquad.h"

MultiBiquad::MultiBiquad() {
    this->y_2 = 0;
    this->y_1 = 0;
    this->x_2 = 0;
    this->x_1 = 0;
    this->b0 = 0;
    this->b1 = 0;
    this->b2 = 0;
    this->a1 = 0;
    this->a2 = 0;
}

float MultiBiquad::ProcessSample(float sample) {
    float out = sample * this->b0 + this->x_1 * this->b1 + this->x_2 * this->b2 + this->y_1 * this->a1 + this->y_2 * this->a2;
    this->y_2 = this->y_1;
    this->y_1 = out;
    this->x_2 = this->x_1;
    this->x_1 = sample;
    return out;
}

void MultiBiquad::RefreshFilter(FilterType type, float gainAmp, float freq, float samplerate, float qFactor, bool param_7) {
    // TODO

    this->y_2 = 0.f;
    this->y_1 = 0.f;
    this->x_2 = 0.f;
    this->x_1 = 0.f;
}
