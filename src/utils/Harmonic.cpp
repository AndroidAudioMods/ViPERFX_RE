//
// Created by mart on 7/30/21.
//

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

void Harmonic::SetHarmonics(float *coeffs) {
    UpdateCoeffs(coeffs);
    Reset();
}

void Harmonic::UpdateCoeffs(float *coeffs) {
    // TODO
}
