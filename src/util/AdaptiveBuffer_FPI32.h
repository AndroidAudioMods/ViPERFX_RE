//
// Created by mart on 2/12/21.
//

#ifndef VIPER_ADAPTIVEBUFFER_FPI32_H
#define VIPER_ADAPTIVEBUFFER_FPI32_H

#include "../libv4a_fx.so.h"

class AdaptiveBuffer_FPI32 {
    void * bufferPointer;
    uint bufferLength;
    undefined4 bufferOffset;
    uint channels;
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
    AdaptiveBuffer_FPI32(uint param_1,uint param_2);
    ~AdaptiveBuffer_FPI32();
    void FlushBuffer();
    undefined4 PushZero(uint param_1);
    undefined4 PushFrames(short *param_1,uint param_2);
    undefined4 PushFrames(int *param_1,uint param_2);
    undefined4 PopFrames(short *param_1,uint param_2);
    void ScaleFrames(int param_1);
    void PanFrames(int param_1,int param_2);
    void SetBufferOffset(uint param_1);
    void * GetBufferPointer();
    uint GetBufferLength();
    undefined4 GetBufferOffset();
    uint GetChannels();
};


#endif //VIPER_ADAPTIVEBUFFER_FPI32_H
