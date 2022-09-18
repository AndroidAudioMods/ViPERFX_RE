#pragma once


#include "IIR_NOrder_BW_LH.h"
#include "WaveBuffer.h"
#include "IIR_NOrder_BW_BP.h"

class HiFi {
public:
    HiFi();

    ~HiFi();

    void Process(float *samples, uint32_t size);

    void Reset();

    void SetClarity(float value);

    void SetSamplingRate(uint32_t samplerate);

    WaveBuffer *buffers[2];
    struct {
        IIR_NOrder_BW_LH *lowpass;
        IIR_NOrder_BW_LH *highpass;
        IIR_NOrder_BW_BP *bandpass;
    } filters[2];
    float gain;
    uint32_t samplerate;
};


