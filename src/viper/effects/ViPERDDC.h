#pragma once

#include <cstdint>

class ViPERDDC {
public:
    ViPERDDC();
    ~ViPERDDC();

    void Process(float *samples, uint32_t size);
    void ReleaseResources();
    void Reset();
    void SetCoeffs(uint32_t param_1, float *param_2, float *param_3);
    void SetEnable(bool enable);
    void SetSamplingRate(uint32_t samplingRate);

private:
    bool enable;
    bool setCoeffsOk;
    uint32_t samplingRate;
    uint32_t arrSize;
    float **coeffsArr44100;
    float **coeffsArr48000;
    float *x1L;
    float *x1R;
    float *x2L;
    float *x2R;
    float *y1L;
    float *y1R;
    float *y2L;
    float *y2R;
};


