#pragma once

#include <cstdint>
#include "WaveBuffer.h"
#include "FIR.h"

class Polyphase {
public:
    Polyphase();
    ~Polyphase();

    uint32_t GetLatency();
    void Process(float *samples, uint32_t size);
    void Reset();
    void SetSamplingRate(uint32_t samplingRate);

private:
    FIR *fir1;
    FIR *fir2;
    WaveBuffer *waveBuffer1;
    WaveBuffer *waveBuffer2;
    int *unknown1;
    bool enabled;
    // 3 unknowns
    uint32_t samplingRate;
};


