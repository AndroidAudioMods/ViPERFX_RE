//
// Created by mart on 7/28/21.
//

#pragma once

#include <cstdint>
#include "PolesFilter.h"
#include "FixedBiquad.h"

class DynamicBass {
public:
    DynamicBass();

    void FilterSamples(float* samples, uint32_t size);
    void Reset();
    void SetBassGain(float gain);
    void SetFilterXPassFrequency(uint32_t low, uint32_t high);
    void SetFilterYPassFrequency(uint32_t low, uint32_t high);
    void SetSamplingRate(uint32_t samplerate);
    void SetSideGain(float gainX, float gainY);

    uint32_t lowFreqX, highFreqX;
    uint32_t lowFreqY, highFreqY;
    uint32_t samplerate;
    uint32_t qPeak;
    float bassGain;
    float sideGainX, sideGainY;

    PolesFilter filterX;
    PolesFilter filterY;
    FixedBiquad lowPass;
};
