#pragma once

#include <cstdint>

class Convolver {
public:
    Convolver();
    ~Convolver();

    void CommitKernelBuffer(uint32_t param_1, uint32_t param_2, uint32_t kernelId);
    bool GetEnabled();
    uint32_t GetKernelID();
    void PrepareKernelBuffer(uint32_t param_1, uint32_t param_2, int32_t kernelId);
    void Process(float *source, float *dest, int32_t frameSize);
    void Reset();
    void SetCrossChannel(float param_1);
    void SetEnable(bool enabled);
    void SetKernel(float *param_1, uint32_t param_2);
    void SetKernel(const char *param_1);
    void SetKernelBuffer(uint32_t param_1, float *param_2, uint32_t param_3);
    void SetKernelStereo(float *param_1, float *param_2, uint32_t param_3);
    void SetSamplingRate(uint32_t param_1);
};


