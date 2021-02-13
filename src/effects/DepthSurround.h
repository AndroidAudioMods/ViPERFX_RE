//
// Created by mart on 2/12/21.
//

#ifndef VIPER_DEPTHSURROUND_H
#define VIPER_DEPTHSURROUND_H


#include "../util/Stereo3DSurround.h"

class DepthSurround {
    short field_0x0;
    bool enabled;
    undefined field_0x3;
    int field_0x4;
    int field_0x8;
    int field_0xc;
    struct TimeConstDelay field_0x10;
    struct TimeConstDelay field_0x1c;
    struct FixedBiquad field_0x28;

public:
    void RefreshStrength(short param_1);
    void SetSamplingRate(uint param_1);
    DepthSurround();
    void SetStrength(short param_1);
    void Process(int *param_1,int param_2);
};


#endif //VIPER_DEPTHSURROUND_H
