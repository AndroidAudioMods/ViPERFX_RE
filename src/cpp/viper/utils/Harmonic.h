#pragma once

#include <cstdint>

class Harmonic {
public:
    Harmonic();

    double Process(double sample);
    void Reset();
    void SetHarmonics(float *coeffs);
    void UpdateCoeffs(float *coeffs);

private:
    float coeffs[11];
    double lastProcessed;
    double prevOut;
    uint32_t biggestCoeff;
    uint32_t sampleCounter;
};


