#pragma once

#include <cstdint>

class ViPERDDC {
public:
    ViPERDDC();
    ~ViPERDDC();

    void Process(float *samples, uint32_t size);
    void ReleaseResources();
    void Reset();
    void SetCoeffs();
    void SetEnable(bool enable);
    void SetSamplingRate(uint32_t samplingRate);
};


