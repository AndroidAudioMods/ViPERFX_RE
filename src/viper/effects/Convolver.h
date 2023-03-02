#pragma once

#include <cstdint>
#include "../utils/WaveBuffer.h"
#include "../utils/PConvSingle.h"

class Convolver {
public:
    Convolver();
    ~Convolver();

    void CommitKernelBuffer(uint32_t param_1, uint32_t param_2, uint32_t kernelId);
    bool GetEnabled();
    uint32_t GetKernelID();
    void PrepareKernelBuffer(uint32_t param_1, uint32_t param_2, int32_t param_3);
    uint32_t Process(float *source, float *dest, uint32_t frameSize);
    void Reset();
    void SetCrossChannel(float param_1);
    void SetEnable(bool enabled);
    void SetKernel(float *buf, uint32_t len);
    void SetKernelBuffer(uint32_t param_1, float *buf, uint32_t len);
    void SetKernelStereo(float *param_1, float *param_2, uint32_t param_3);
    void SetSamplingRate(uint32_t param_1);

private:
    WaveBuffer *waveBufferL;
    WaveBuffer *waveBufferR;
    PConvSingle kernelCh1;
    PConvSingle kernelCh2;
    PConvSingle kernelCh3;
    PConvSingle kernelCh4;
    char kernelFilePath[256];
    uint32_t kernelId;
    float *unknown1;
    uint32_t unknown2;
    uint32_t unknown3;
    uint32_t unknown4;
    uint32_t currentKernelBufferCrc;
    int isQuadChannel;
    float crossChannel;
    bool isValidCrossChannel;
    uint32_t samplingRate;
    bool enable;
};


