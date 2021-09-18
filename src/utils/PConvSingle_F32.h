//
// Created by mart on 9/12/21.
//

#pragma once

typedef struct {
    int unk_0x00;
    int unk_0x04;
    int unk_0x08;
    float* unk_buffer;
    float* fftInputBuffer;
    float* fftOutputBuffer;
    float* unk_buffer_2;
    float* unk_buffer_3;
    int size_A;
    void* field_A1;
    void* field_A2;
    int size_B;
    void* field_B1;
    void* field_B2;
    int* unk_0x120;
    void* fft_plan_1;
    void* fft_plan_2;
} PConvData;


class PConvSingle_F32 {
public:
    PConvSingle_F32();
    ~PConvSingle_F32();

    void Reset();
    int GetFFTSize();
    int GetSegmentCount();
    int GetSegmentSize();
    bool InstanceUsable();

    void Convolve(float* buffer);
    void ConvolveInterleaved(float* buffer, int channel);
    void ConvSegment(float* buffer, bool interleaved, int channel);

    int LoadKernel(float* buf, int param_2, int segmentSize);
    int LoadKernel(float* buf, float* param_2, int segmentSize, int param_4, int param_5);
    int ProcessKernel(float* param_1, int param_2, int param_3);
    int ProcessKernel(int param_2, float *param_3, int param_4, int param_5);
    void ReleaseResources();
    void UnloadKernel();

    bool enabled;
    int segments, segmentSize;
    PConvData* data;  // TODO: Type
};
