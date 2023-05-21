#pragma once

class PConvSingle {
    struct PConvData {

    };
public:
    PConvSingle();

    ~PConvSingle();

    void Reset();

    int GetFFTSize();

    int GetSegmentCount();

    int GetSegmentSize();

    bool InstanceUsable();

    void Convolve(float *buffer);

    void ConvolveInterleaved(float *buffer, int channel);

    void ConvSegment(float *buffer, bool interleaved, int channel);

    int LoadKernel(const float *kernel, int kernelSize, int segmentSize);

    int LoadKernel(const float *kernel, float param_3, int kernelSize, int segmentSize);

    int ProcessKernel(const float *kernel, int kernelSize, int param_4);

    int ProcessKernel(const float *kernel, float param_3, int kernelSize, int param_5);

    void ReleaseResources();

    void UnloadKernel();

    bool instanceUsable;
    int segmentCount;
    int segmentSize;
    PConvData *data;
};
