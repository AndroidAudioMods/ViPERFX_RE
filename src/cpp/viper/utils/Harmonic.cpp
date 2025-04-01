#include <cstring>
#include <cmath>
#include "Harmonic.h"

static const float HARMONIC_DEFAULT[] = {
        1.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
};

Harmonic::Harmonic() {
    UpdateCoeffs(HARMONIC_DEFAULT);
    Reset();
}

double Harmonic::Process(double sample) {
    double prevLast = this->lastProcessed;

    this->lastProcessed =
            (this->coeffs[0] + sample *
            (this->coeffs[1] + sample *
            (this->coeffs[2] + sample *
            (this->coeffs[3] + sample *
            (this->coeffs[4] + sample *
            (this->coeffs[5] + sample *
            (this->coeffs[6] + sample *
            (this->coeffs[7] + sample *
            (this->coeffs[8] + sample *
            (this->coeffs[9] + sample *
            (this->coeffs[10])))))))))));

    this->prevOut = (this->lastProcessed + this->prevOut * 0.999) - prevLast;

    if (this->sampleCounter < this->biggestCoeff) {
        this->sampleCounter++;
        return 0.0;
    }

    return this->prevOut;
}

void Harmonic::Reset() {
    this->lastProcessed = 0.0;
    this->sampleCounter = 0;
    this->prevOut = 0.0;
}

void Harmonic::SetHarmonics(const float *coefficients) {
    UpdateCoeffs(coefficients);
    Reset();
}

void Harmonic::UpdateCoeffs(const float *coefficients) {
    float unkarr1[11];
    float unkarr2[11];

    memset(unkarr1, 0, 11 * sizeof(float));

    float biggestCoeffVal = 0.0;
    float absCoeffSum = 0.0;
    for (uint32_t i = 0; i < 10; i++) {
        float absCoeffVal = abs(coefficients[i]);
        absCoeffSum += absCoeffVal;
        if (absCoeffVal > biggestCoeffVal) {
            biggestCoeffVal = absCoeffVal;
        }
    }
    this->biggestCoeff = (uint32_t) (biggestCoeffVal * 10000.0);

    memcpy(unkarr1 + 1, coefficients, 10 * sizeof(float));

    float unk1 = 1.0;
    if (absCoeffSum > 1.0) {
        unk1 = 1.0f / absCoeffSum;
    }
    for (uint32_t i = 1; i < 11; i++) {
        unkarr1[i] *= unk1;
    }

    memset(this->coeffs, 0, 11 * sizeof(float));
    memset(unkarr2, 0, 11 * sizeof(float));

    this->coeffs[10] = unkarr1[10];

    for (uint32_t i = 2; i < 11; i++) {
        for (uint32_t j = 0; j < i; j++) {
            float tmp = unkarr2[i - j];
            unkarr2[i - j] = this->coeffs[i - j];
            this->coeffs[i - j] = this->coeffs[i - j - 1] * 2.0f - tmp;
        }
        float tmp = unkarr1[10 - i + 1] - unkarr2[0];
        unkarr2[0] = this->coeffs[0];
        this->coeffs[0] = tmp;
    }

    for (uint32_t i = 1; i < 11; i++) {
        this->coeffs[10 - i + 1] = this->coeffs[10 - i] - unkarr2[10 - i + 1];
    }

    this->coeffs[0] = unkarr1[0] / 2.0f - unkarr2[0];
}
