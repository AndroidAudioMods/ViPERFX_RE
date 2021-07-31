//
// Created by mart on 7/31/21.
//

#pragma once


#include "../utils/NoiseSharpening.h"
#include "../utils/HiFi.h"
#include "../utils/HighShelf.h"

class ViPERClarity {
public:
    ViPERClarity();

    void Process(float* samples, uint32_t size);
    void Reset();

    void SetClarity(float gainPercent);
    void SetClarityToFilter();
    void SetEnable(bool enabled);
    void SetProcessMode(int mode);
    void SetSamplingRate(uint32_t samplerate);

    NoiseSharpening sharp;
    HighShelf hiShelf[2];
    HiFi hifi;
    bool enabled;
    int processMode;
    uint32_t samplerate;
    float clarityGainPercent;
};


