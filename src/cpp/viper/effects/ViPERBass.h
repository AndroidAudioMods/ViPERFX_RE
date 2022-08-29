#pragma once

#include <cstdint>

class ViPERBass {
public:
    ViPERBass();
    ~ViPERBass();

    void Process(float *samples, uint32_t size);
    void Reset();
    void SetBassFactor();
    void SetEnable(bool enable);
    void SetProcessMode();
    void SetSamplingRate(uint32_t samplingRate);
    void SetSpeaker();
};


