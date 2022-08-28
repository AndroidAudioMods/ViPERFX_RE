//
// Created by mart on 7/30/21.
//

#pragma once


#include <cstdint>
#include "MultiBiquad.h"

class Subwoofer {
public:
    Subwoofer();

    void Process(float *samples, uint32_t size);

    void SetBassGain(uint32_t samplerate, float gainDb);

    MultiBiquad peak[2];
    MultiBiquad peakLow[2];
    MultiBiquad lowpass[2];
};


