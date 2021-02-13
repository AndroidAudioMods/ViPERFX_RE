//
// Created by mart on 2/12/21.
//

#ifndef VIPER_PCONVSINGLE_F32_H
#define VIPER_PCONVSINGLE_F32_H


class PConvSingle_F32 {
    bool field_0x0;
    char field_0x1;
    char field_0x2;
    char field_0x3;
    int field_0x4;
    int field_0x8;
    void* field_0xc;

public:
    void PConvSingle_F32();
    void ReleaseResources();
    ~PConvSingle_F32();
    undefined4 ProcessKernel(float *param_1,int param_2,int param_3);
    undefined4 ProcessKernel(float *param_1,float param_2,int param_3,int param_4);
    void ConvSegment(float *param_1,bool param_2,int param_3);
    void Reset();
    int GetFFTSize();
    undefined4 GetSegmentSize();
    undefined4 GetSegmentCount();
    void UnloadKernel();
    int LoadKernel(float *param_1,int param_2,int param_3);
    int LoadKernel(float *param_1,float param_2,int param_3,int param_4);
    PConvSingle_F32 InstanceUsable();
    void Convolve(float *param_1);
    void ConvolveInterleaved(float *param_1,int param_2);
};


#endif //VIPER_PCONVSINGLE_F32_H
