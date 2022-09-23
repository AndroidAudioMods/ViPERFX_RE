#pragma once

#include <cstdint>
#include "PolesFilter.h"
#include "Biquad.h"

class DynamicBass {
public:
    DynamicBass();

    void FilterSamples(float *samples, uint32_t size);

    void Reset();

    void SetBassGain(float gain);

    void SetFilterXPassFrequency(uint32_t low, uint32_t high);

    void SetFilterYPassFrequency(uint32_t low, uint32_t high);

    void SetSamplingRate(uint32_t samplingRate);

    void SetSideGain(float gainX, float gainY);

    uint32_t lowFreqX, highFreqX;
    uint32_t lowFreqY, highFreqY;
    uint32_t samplingRate;
    float qPeak;
    float bassGain;
    float sideGainX, sideGainY;

    PolesFilter filterX;
    PolesFilter filterY;
    Biquad lowPass;
};
