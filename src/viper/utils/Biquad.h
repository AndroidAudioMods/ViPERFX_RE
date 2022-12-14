#pragma once

#include <cstdint>

// Iscle: Verified with the latest version at 13/12/2022

class Biquad {
public:
    Biquad();

    double ProcessSample(double sample);
    void Reset();
    void SetBandPassParameter(float frequency, uint32_t samplingRate, float qFactor);
    void SetCoeffs(double a0, double a1, double a2, double b0, double b1, double b2);
    void SetHighPassParameter(float frequency, uint32_t samplingRate, double dbGain, float qFactor, double param_6);
    void SetLowPassParameter(float frequency, uint32_t samplingRate, float qFactor);

private:
    double x1;
    double x2;
    double y1;
    double y2;
    double a1;
    double a2;
    double b0;
    double b1;
    double b2;
};
