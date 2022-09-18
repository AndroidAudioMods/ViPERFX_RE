#pragma once

#include <cstdint>
#include "../utils/Biquad.h"
#include "../utils/Subwoofer.h"
#include "../utils/WaveBuffer.h"
#include "../utils/Polyphase.h"

class ViPERBass {
public:
    ViPERBass();
    ~ViPERBass();

    void Process(float *samples, uint32_t size);
    void Reset();
    void SetBassFactor(float bassFactor);
    void SetEnable(bool enable);
    void SetProcessMode(int processMode);
    void SetSamplingRate(uint32_t samplingRate);
    void SetSpeaker(float speaker);

private:
    Polyphase *polyphase;
    Biquad *fixedBiquad;
    Subwoofer *subwoofer;
    WaveBuffer *waveBuffer;
    bool enable;
    bool initOk;
    int processMode;
    uint32_t samplingRate;
    float unknown1;
    float speaker;
    float bassFactor;
};


