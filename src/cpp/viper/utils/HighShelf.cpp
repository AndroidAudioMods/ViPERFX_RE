#include "HighShelf.h"
#include <cmath>

double HighShelf::Process(double sample) {
    double out = (((this->x_1 * this->b1 + sample * this->b0 + this->b2 * this->x_2) - this->y_1 * this->a1) - this->a2 * this->y_2) * this->a0;
    this->y_2 = this->y_1;
    this->y_1 = out;
    this->x_2 = this->x_1;
    this->x_1 = sample;
    return out;
}

void HighShelf::SetFrequency(double freq) {
    this->frequency = freq;
}

void HighShelf::SetGain(double gain) {
    this->gain = log10(gain) * 20.0;
}

void HighShelf::SetSamplingRate(double samplingRate) {
    double x = (2 * M_PI * this->frequency) / samplingRate;
    double sinX = sin(x);
    double cosX = cos(x);
    double y = exp((this->gain * log(10.0)) / 40.0);

    this->x_1 = 0.0;
    this->x_2 = 0.0;
    this->y_1 = 0.0;
    this->y_2 = 0.0;

    double z = sqrt(y * 2.0) * sinX;
    double a = (y - 1.0) * cosX;
    double b = (y + 1.0) - a;
    double c = z + b;
    double d = (y + 1.0) * cosX;
    double e = (y + 1.0) + a;
    double f = (y - 1.0) - d;

    this->a0 = 1.0 / c;
    this->a1 = a * 2.0;
    this->a2 = b - z;
    this->b0 = (e + z) * y;
    this->b1 = -y * 2.0 * ((y - 1.0) + d);
    this->b2 = (e - z) * y;
}
