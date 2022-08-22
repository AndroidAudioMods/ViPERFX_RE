//
// Created by mart on 7/30/21.
//

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

    float coeffs[11];
    float lastProcessed;
    float prevOut;
    int buildup;
    int sampleCounter;
};


