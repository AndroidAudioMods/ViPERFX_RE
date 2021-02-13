//
// Created by mart on 2/12/21.
//

#ifndef VIPER_WAVEBUFFER_R32_H
#define VIPER_WAVEBUFFER_R32_H


class WaveBuffer_R32 {
    undefined field_0x0;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    undefined field_0x8;
    undefined field_0x9;
    undefined field_0xa;
    undefined field_0xb;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    undefined field_0x18;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;

public:
    WaveBuffer_R32(uint param_1,uint param_2);
    ~WaveBuffer_R32();
    void Short2Float(short *param_1,float *param_2,uint param_3);
    void Float2Short(float *param_1,short *param_2,uint param_3);
    void Int2Float(int *param_1,float *param_2,uint param_3);
    void Float2Int(float *param_1,int *param_2,uint param_3);
    void * PushZerosGetBuffer(uint param_1);
    undefined4 PushZeros(uint param_1);
    undefined4 PushSamples(short *param_1,uint param_2);
    undefined4 PushSamples(int *param_1,uint param_2);
    undefined4 PushSamples(float *param_1,uint param_2);
    uint PopSamples(uint param_1,bool param_2);
    uint PopSamples(short *param_1,uint param_2,bool param_3);
    uint PopSamples(int *param_1,uint param_2,bool param_3);
    uint PopSamples(float *param_1,uint param_2,bool param_3);
    void Reset();
    void SetBufferOffset(uint param_1);
    void GetBufferOffset();
    void GetBufferSize();
    undefined4 GetCurrentBufferR32Ptr();
};


#endif //VIPER_WAVEBUFFER_R32_H
