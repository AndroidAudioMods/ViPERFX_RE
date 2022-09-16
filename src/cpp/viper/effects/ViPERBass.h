#pragma once

#include <cstdint>
#include "../utils/FixedBiquad.h"
#include "../utils/Subwoofer.h"
#include "../utils/WaveBuffer_I32.h"
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
    FixedBiquad *fixedBiquad;
    Subwoofer *subwoofer;
    WaveBuffer_I32 *waveBuffer;
    bool enable;
    bool initOk;
    int processMode;
    uint32_t samplingRate;
    float unknown1;
    float speaker;
    float bassFactor;
};


