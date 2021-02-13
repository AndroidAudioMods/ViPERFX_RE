//
// Created by mart on 2/12/21.
//

#ifndef VIPER_ADAPTIVEBUFFER_R32_H
#define VIPER_ADAPTIVEBUFFER_R32_H


#include "AdaptiveBuffer_FPI32.h"

class AdaptiveBuffer_R32 {
    void * bufferPointer;
    uint bufferLength;
    undefined4 bufferOffset;
    uint channels;

public:
    AdaptiveBuffer_R32(uint param_1,uint param_2);
    ~AdaptiveBuffer_R32();
    void Short2Float(short *param_1,float *param_2,uint param_3);
    void Float2Short(float *param_1,short *param_2,uint param_3);
    void FlushBuffer();
    undefined4 PushZero(uint param_1);
    undefined4 PushFrames(short *param_1,uint param_2);
    undefined4 PopFrames(short *param_1,uint param_2);
    void ScaleFrames(float param_1);
    void PanFrames(float param_1,float param_2);
    void SetBufferOffset(uint param_1);
    void * GetBufferPointer();
    uint GetBufferLength();
    undefined4 GetBufferOffset();
    uint GetChannels();
};


#endif //VIPER_ADAPTIVEBUFFER_R32_H
