#pragma once

#include <cstdint>

class ColorfulMusic {
public:
    ColorfulMusic();
    ~ColorfulMusic();

    void Process(float *samples, uint32_t size);
    void Reset();
    void SetDepthValue();
    void SetEnable(bool enable);
    void SetMidImageValue();
    void SetSamplingRate(uint32_t samplingRate);
    void SetWidenValue();
};


