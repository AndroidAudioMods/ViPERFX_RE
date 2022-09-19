#pragma once

#include <cstdint>

class Biquad {
public:
    Biquad();

    double ProcessSample(double sample);
    void Reset();
    void SetBandPassParameter(double frequency, double samplingRate, float qFactor);
    void SetCoeffs(double a0, double a1, double a2, double b0, double b1, double b2);
    void SetHighPassParameter(double frequency, double samplingRate, double param_4, float qFactor, double param_6);
    void SetLowPassParameter(double frequency, double samplingRate, float qFactor);

private:
    double x_1;
    double x_2;
    double y_1;
    double y_2;
    double a1;
    double a2;
    double b0;
    double b1;
    double b2;
};
