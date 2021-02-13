//
// Created by mart on 2/12/21.
//

#ifndef VIPER_WAVEBUFFER_I32_H
#define VIPER_WAVEBUFFER_I32_H


class WaveBuffer_I32 {
    void* field_0x0;
    uint field_0x4;
    undefined4 field_0x8;
    uint field_0xc;
    
public:
    WaveBuffer_I32(uint param_1,uint param_2);
    ~WaveBuffer_I32();
    void * PushZerosGetBuffer(uint param_1);
    undefined4 PushZeros(uint param_1);
    undefined4 PushSamples(int *param_1,uint param_2);
    uint PopSamples(uint param_1,bool param_2);
    uint PopSamples(int *param_1,uint param_2,bool param_3);
    void Reset();
    void SetBufferOffset(uint param_1);
    void GetBufferOffset();
    void GetBufferSize();
    undefined4 GetCurrentBufferI32Ptr();
};


#endif //VIPER_WAVEBUFFER_I32_H
