#include "Biquad.h"
#include <cmath>

Biquad::Biquad() {
    Reset();
    SetCoeffs(1.0, 0.0, 0.0, 1.0, 0.0, 0.0);
}

double Biquad::ProcessSample(double sample) {
    double out = sample * this->b0 + this->x_1 * this->b1 + this->x_2 * this->b2 + this->y_1 * this->a1 +
                this->y_2 * this->a2;
    this->y_2 = this->y_1;
    this->y_1 = out;
    this->x_2 = this->x_1;
    this->x_1 = sample;
    return out;
}

void Biquad::Reset() {
    this->a1 = 0;
    this->a2 = 0;
    this->b0 = 0;
    this->b1 = 0;
    this->b2 = 0;
    this->x_1 = 0;
    this->x_2 = 0;
    this->y_1 = 0;
    this->y_2 = 0;
}

void Biquad::SetBandPassParameter(double frequency, double samplingRate, float qFactor) {
    double x = (2.0 * M_PI * frequency) / samplingRate;
    double sinX = sin(x);
    double cosX = cos(x);
    double y = sinX / ((double) qFactor * 2.0);

    double a0 = 1.0 + y;
    double a1 = -cosX * 2.0;
    double a2 = 1.0 - y;
    double b0 = sinX / 2.0;
    double b1 = 0.0;
    double b2 = -sinX / 2.0;
    this->SetCoeffs(a0, a1, a2, b0, b1, b2);
}

void Biquad::SetCoeffs(double a0, double a1, double a2, double b0, double b1, double b2) {
    this->x_2 = 0;
    this->x_1 = 0;
    this->y_2 = 0;
    this->y_1 = 0;
    this->a1 = -a1 / a0;
    this->a2 = -a2 / a0;
    this->b0 = b0 / a0;
    this->b1 = b1 / a0;
    this->b2 = b2 / a0;
}

void
Biquad::SetHighPassParameter(double frequency, double samplingRate, double param_4, float qFactor, double param_6) {
    double x = (2.0 * M_PI * frequency) / samplingRate;
    double sinX = sin(x);
    double cosX = cos(x);

    double y = pow(10.0, param_4 / 40.0);
    double sqrtY = sqrt(y);

    double z = sinX / 2.0 * sqrt((1.0 / y + y) * (1.0 / (double) qFactor - 1.0) + 2.0);
    double a = (y - 1.0) * cosX;
    double b = (y + 1.0) + a;
    double c = (y + 1.0) * cosX;
    double d = (y + 1.0) - a;
    double e = pow(10.0, param_6 / 20.0);
    double f = (y - 1.0) - c;

    double a0 = d + (sqrtY * 2.0) * z;
    double a1 = f * 2.0;
    double a2 = d - (sqrtY * 2.0) * z;
    double b0 = (b + (sqrtY * 2.0) * z) * y * e;
    double b1 = y * -2.0 * ((y - 1.0) + c) * e;
    double b2 = (b - (sqrtY * 2.0) * z) * y * e;
    this->SetCoeffs(a0, a1, a2, b0, b1, b2);
}

void Biquad::SetLowPassParameter(double frequency, double samplingRate, float qFactor) {
    double x = (2.0 * M_PI * frequency) / samplingRate;
    double sinX = sin(x);
    double y = sinX / ((double) qFactor * 2.0);
    double cosX = cos(x);
    double z = 1.0 - cosX;

    double a0 = y + 1.0;
    double a1 = -cosX * 2.0;
    double a2 = 1.0 - y;
    double b0 = z / 2.0;
    double b1 = z;
    double b2 = z / 2.0;
    this->SetCoeffs(a0, a1, a2, b0, b1, b2);
}
