#pragma once

#include <cstdint>

class Harmonic {
public:
    Harmonic();
    ~Harmonic();

    float Process(float sample);
    void Reset();
    void SetHarmonics(float *coeffs);
    void UpdateCoeffs(float *coeffs);

private:
    float coeffs[11];
    float lastProcessed;
    float prevOut;
    uint32_t buildup;
    uint32_t sampleCounter;
};


