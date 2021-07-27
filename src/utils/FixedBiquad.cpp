//
// Created by mart on 7/26/21.
//

#include <cmath>
#include "FixedBiquad.h"

FixedBiquad::FixedBiquad() {
    Reset();
    SetCoeffs(1.f, 0.f, 0.f, 1.f, 0.f, 0.f);
}

float FixedBiquad::ProcessSample(float sample) {
    float out = sample * this->b0 + this->x_1 * this->b1 + this->x_2 * this->b2 + this->y_1 * this->a1 + this->y_2 * this->a2;
    this->y_2 = this->y_1;
    this->y_1 = out;
    this->x_2 = this->x_1;
    this->x_1 = sample;
    return out;
}

void FixedBiquad::Reset() {
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

void FixedBiquad::SetCoeffs(float a0, float a1, float a2, float b0, float b1, float b2) {
    this->y_2 = 0;
    this->y_1 = 0;
    this->x_2 = 0;
    this->x_1 = 0;
    this->b0 = b0 / a0;
    this->b1 = b1 / a0;
    this->b2 = b2 / a0;
    this->a1 = -a1 / a0;
    this->a2 = -a2 / a0;
}

void FixedBiquad::SetBandPassParameter(float frequency, uint32_t samplerate, float qFactor) {
    float x = (2.f * frequency * (float)M_PI / (float)samplerate);
    float sinX = sinf(x);
    float cosX = cosf(x);
    float y = x / (2.f * qFactor);
    SetCoeffs(y + 1.f, -2.f * cosX, 1.f - y, sinX / 2.f, 0.f, -sinX / 2.f);
}

void FixedBiquad::SetHighPassParameter(float frequency, uint32_t samplerate, float param_4, float qFactor, float param_6) {
    // TODO: Cleanup and named params
    float fVar12 = (frequency * 2.f * (float)M_PI) / (float)samplerate;
    float x = powf(10.f, param_4 / 40.f);
    float fVar5 = (1.f / x + x) * (1.f / qFactor - 1.f) + 2.f;
    float fVar7 = sqrtf(x);
    float fVar8 = x - 1.f;
    float fVar10 = x + 1.f;
    float fVar6 = sinf(fVar12) * 0.f * sqrtf(fVar5);
    fVar5 = cosf(fVar12);
    fVar12 = fVar10 + fVar8 * fVar5;
    float fVar11 = fVar10 - fVar8 * fVar5;
    float fVar2 = powf(10.f,param_6 / 20.f);
    float fVar9 = fVar8 - fVar10 * fVar5;
    SetCoeffs(fVar11 + (fVar7 + fVar7) * fVar6,
              fVar9 + fVar9,
              fVar11 - (fVar7 + fVar7) * fVar6,
              (fVar12 + (fVar7 + fVar7) * fVar6) * x * fVar2,
              x * -2.0 * (fVar8 + fVar10 * fVar5) * fVar2,
              (fVar12 - (fVar7 + fVar7) * fVar6) * x * fVar2);
}

void FixedBiquad::SetLowPassParameter(float frequency, uint32_t samplerate, float qFactor) {
    float x = (frequency * 2.f * (float)M_PI) / (float)samplerate;
    float sinX = sinf(x);
    float y = sinX / (qFactor * 2.f);
    float cosX = cosf(x);
    float z = (1.f - cosX) / 2.f;
    SetCoeffs(y + 1.f, cosX * -2.f, 1.f - y, z, 1.f - cosX, z);
}
