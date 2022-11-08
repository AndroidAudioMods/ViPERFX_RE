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
    float **arrPtr44100;
    float **arrPtr48000;
    float *arr1;
    float *arr2;
    float *arr3;
    float *arr4;
    float *arr5;
    float *arr6;
    float *arr7;
    float *arr8;
};


