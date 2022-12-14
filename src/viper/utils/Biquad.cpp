#include "Biquad.h"
#include <cmath>

// Iscle: Verified with the latest version at 13/12/2022
// Some variable names RE'd with help from https://github.com/wooters/miniDSP/blob/master/biquad.c

Biquad::Biquad() {
    Reset();
    SetCoeffs(1.0, 0.0, 0.0, 1.0, 0.0, 0.0);
}

double Biquad::ProcessSample(double sample) {
    double out =
            sample * this->b0 +
            this->x1 * this->b1 +
            this->x2 * this->b2 +
            this->y1 * this->a1 +
            this->y2 * this->a2;

    this->x2 = this->x1;
    this->x1 = sample;
    this->y2 = this->y1;
    this->y1 = out;

    return out;
}

void Biquad::Reset() {
    this->a1 = 0.0;
    this->a2 = 0.0;
    this->b0 = 0.0;
    this->b1 = 0.0;
    this->b2 = 0.0;
    this->x1 = 0.0;
    this->x2 = 0.0;
    this->y1 = 0.0;
    this->y2 = 0.0;
}

void Biquad::SetBandPassParameter(float frequency, uint32_t samplingRate, float qFactor) {
    double omega = (2.0 * M_PI * (double) frequency) / (double) samplingRate;
    double sinOmega = sin(omega);
    double cosOmega = cos(omega);

    double alpha = sinOmega / ((double) qFactor + (double) qFactor);

    double a0 = alpha + 1.0;
    double a1 = cosOmega * -2.0;
    double a2 = 1.0 - alpha;
    double b0 = sinOmega / 2.0; // Reference biquad implementation would use alpha here
    double b1 = 0.0;
    double b2 = -(sinOmega / 2.0); // Reference biquad implementation would use -alpha here

    SetCoeffs(a0, a1, a2, b0, b1, b2);
}

void Biquad::SetCoeffs(double a0, double a1, double a2, double b0, double b1, double b2) {
    this->x2 = 0.0;
    this->x1 = 0.0;
    this->y2 = 0.0;
    this->y1 = 0.0;

    this->a1 = -(a1 / a0);
    this->a2 = -(a2 / a0);
    this->b0 = b0 / a0;
    this->b1 = b1 / a0;
    this->b2 = b2 / a0;
}

void
Biquad::SetHighPassParameter(float frequency, uint32_t samplingRate, double dbGain, float qFactor, double param_6) {
    double omega = (2.0 * M_PI * (double) frequency) / (double) samplingRate;
    double sinOmega = sin(omega);
    double cosOmega = cos(omega);

    double A = pow(10.0, dbGain / 40.0);
    double sqrtA = sqrt(A);

    double z = sinOmega / 2.0 * sqrt((1.0 / A + A) * (1.0 / (double) qFactor - 1.0) + 2.0);

    double a0 = (A + 1.0) - (A - 1.0) * cosOmega + (sqrtA * 2.0) * z;
    double a1 = ((A - 1.0) - (A + 1.0) * cosOmega) * 2.0;
    double a2 = (A + 1.0) - (A - 1.0) * cosOmega - (sqrtA * 2.0) * z;
    double b0 = ((A + 1.0) + (A - 1.0) * cosOmega + (sqrtA * 2.0) * z) * A * omega;
    double b1 = A * -2.0 * ((A - 1.0) + (A + 1.0) * cosOmega) * omega;
    double b2 = ((A + 1.0) + (A - 1.0) * cosOmega - (sqrtA * 2.0) * z) * A * omega;

    SetCoeffs(a0, a1, a2, b0, b1, b2);
}

void Biquad::SetLowPassParameter(float frequency, uint32_t samplingRate, float qFactor) {
    double omega = (2.0 * M_PI * (double) frequency) / (double) samplingRate;
    double sinOmega = sin(omega);
    double cosOmega = cos(omega);

    double alpha = sinOmega / ((double) qFactor + (double) qFactor);

    double a0 = alpha + 1.0;
    double a1 = cosOmega * -2.0;
    double a2 = 1.0 - alpha;
    double b0 = (1.0 - cosOmega) / 2.0;
    double b1 = 1.0 - cosOmega;
    double b2 = (1.0 - cosOmega) / 2.0;

    SetCoeffs(a0, a1, a2, b0, b1, b2);
}
