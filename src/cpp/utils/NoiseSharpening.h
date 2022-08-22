//
// Created by mart on 7/28/21.
//

#pragma once


#include "IIR_1st.h"

class NoiseSharpening {
public:
    NoiseSharpening();

    void Process(float *buffer, uint32_t size);

    void Reset();

    void SetGain(float gain);

    void SetSamplingRate(uint32_t samplerate);

    IIR_1st filters[2];
    float in[2];
    int32_t samplerate;
    float gain;
};



