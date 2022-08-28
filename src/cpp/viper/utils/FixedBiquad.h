//
// Created by mart on 7/26/21.
//

#pragma once


#include <cstdint>

class FixedBiquad {
public:
    FixedBiquad();

    float ProcessSample(float sample);

    void Reset();

    void SetCoeffs(float a0, float a1, float a2, float b0, float b1, float b2);

    void SetBandPassParameter(float frequency, uint32_t samplerate, float qFactor);

    void SetHighPassParameter(float frequency, uint32_t samplerate, float param_4, float qFactor, float param_6);

    void SetLowPassParameter(float frequency, uint32_t samplerate, float qFactor);


    float y_2, y_1, x_2, x_1;
    float b0, b1, b2, a1, a2;
};
