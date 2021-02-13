//
// Created by mart on 2/12/21.
//

#ifndef VIPER_DIFFSURROUND_H
#define VIPER_DIFFSURROUND_H


#include "../libv4a_fx.so.h"

class DiffSurround {
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

public:
    ~DiffSurround();
    void Reset();
    DiffSurround();
    undefined4 SetEnable(bool param_1);
    void SetSamplingRate(uint param_1);
    void SetDelayTime(float param_1);
    void Process(int *param_1,int param_2);
};


#endif //VIPER_DIFFSURROUND_H
