//
// Created by mart on 7/28/21.
//

#pragma once
#include <cstdint>

class HighShelf {
public:
    float Process(float sample);

    void SetFrequency(uint32_t freq);
    void SetGain(float gain);
    void SetQuality(float q);
    void SetSamplingRate(uint32_t samplerate);

    uint32_t frequency, samplerate;
    float quality, gain;

    float y_2, y_1, x_2, x_1;
    float b0, b1, b2, a1, a2;
};



