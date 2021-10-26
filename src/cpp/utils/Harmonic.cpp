//
// Created by mart on 7/30/21.
//

#include <cstring>
#include <cstdlib>
#include <cmath>
#include "Harmonic.h"

static float HARMONIC_DEFAULT[10] = {
        1.f,
        0.f,
        0.f,
        0.f,
        0.f,
        0.f,
        0.f,
        0.f,
        0.f,
        0.f,
};

Harmonic::Harmonic() {
    UpdateCoeffs(HARMONIC_DEFAULT);
    Reset();
}

Harmonic::~Harmonic() {

}

float Harmonic::Process(float sample) {
    float prevLast = this->lastProcessed;
    this->lastProcessed = (
            sample * this->coeffs[0] +
            sample * this->coeffs[1] +
            sample * this->coeffs[2] +
            sample * this->coeffs[3] +
            sample * this->coeffs[4] +
            sample * this->coeffs[5] +
            sample * this->coeffs[6] +
            sample * this->coeffs[7] +
            sample * this->coeffs[8] +
            sample * this->coeffs[9] +
            sample * this->coeffs[10]
    );
    this->prevOut = this->lastProcessed + this->prevOut * 0.999f - prevLast;
    if (this->sampleCounter < this->buildup) {
        this->sampleCounter++;
        return 0;
    }
    return this->prevOut;
}

void Harmonic::Reset() {
    this->lastProcessed = 0.f;
    this->prevOut = 0.f;
    this->sampleCounter = 0.f;
}

void Harmonic::SetHarmonics(float *coefficients) {
    UpdateCoeffs(coefficients);
    Reset();
}

void Harmonic::UpdateCoeffs(float *coefficients) {
    float fVar5;
    float fVar6;
    float _coeffs[20];
    float afStack76[14];
    
    memset(_coeffs, 0, 11 * sizeof(float));
    this->buildup = (int)fabsf(coefficients[10]);
    memcpy(&_coeffs[1], coefficients, 10 * sizeof(float));

    fVar6 = 1.f / (
            fabsf(_coeffs[1]) +
            fabsf(_coeffs[2]) +
            fabsf(_coeffs[3]) +
            fabsf(_coeffs[4]) +
            fabsf(_coeffs[5]) +
            fabsf(_coeffs[6]) +
            fabsf(_coeffs[7]) +
            fabsf(_coeffs[8]) +
            fabsf(_coeffs[9]) +
            fabsf(_coeffs[10])
    );

    for (int i = 0; i < 11; i++) {
        _coeffs[i] *= fVar6;
    }

    for (int i = 0; i < 11; i++) {
        afStack76[2 + i] = 0;
        _coeffs[10 + i] = 0;
    }

    _coeffs[11] = _coeffs[10];
    fVar6 = _coeffs[11];
    for (int i = 2; i < 11; i++) {
        for(int idx = 0; idx < i; idx++) {
            _coeffs[11] = fVar6;
            fVar5 = _coeffs[10 - idx + i];
            fVar6 = afStack76[2 - idx + i];
            afStack76[2 - idx + i] = _coeffs[11 - idx + i];
            _coeffs[11 - idx + i] = 2 * fVar5 - fVar6;
            fVar6 = _coeffs[11];
        }
        fVar6 = _coeffs[11 - i] - afStack76[2];
        afStack76[2] = _coeffs[11];
    }

    for (int i = 1; i < 11; i++) {
        afStack76[2 + i] = afStack76[i - 1] - afStack76[13 - i];
    }

    _coeffs[11] = _coeffs[0] * 0.5f - _coeffs[11];
    for (int i = 0; i < 11; i++) {
        this->coeffs[i] = _coeffs[11+i];
    }
}
