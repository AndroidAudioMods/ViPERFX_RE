#pragma once


#include <cstdint>

class Biquad {
public:
    Biquad();

    double ProcessSample(double sample);
    void Reset();
    void SetBandPassParameter(double frequency, double samplingRate, double qFactor);
    void SetCoeffs(double a0, double a1, double a2, double b0, double b1, double b2);
    void SetHighPassParameter(double frequency, double samplingRate, double param_4, double qFactor, double param_6);
    void SetLowPassParameter(double frequency, double samplingRate, double qFactor);

private:
    double y_2, y_1, x_2, x_1;
    double b0, b1, b2, a1, a2;
};
