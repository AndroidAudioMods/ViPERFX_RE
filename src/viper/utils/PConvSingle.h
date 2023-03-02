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

    int LoadKernel(float *buf, int param_2, int segmentSize);

    int LoadKernel(const float *param_2,float param_3,int param_4,int param_5);

    int ProcessKernel(float *param_1, int param_2, int param_3);

    int ProcessKernel(int param_2, float *param_3, int param_4, int param_5);

    void ReleaseResources();

    void UnloadKernel();

    bool instanceUsable;
    int segmentCount;
    int segmentSize;
    PConvData *data;
};
