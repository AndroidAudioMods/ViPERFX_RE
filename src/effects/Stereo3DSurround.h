//
// Created by mart on 2/12/21.
//

#ifndef VIPER_STEREOSURROUND_H
#define VIPER_STEREOSURROUND_H


#include "../libv4a_fx.so.h"

class Stereo3DSurround {
    float field_0x0;
    uint field_0x4;
    uint field_0x8;
    uint field_0xc;
    uint field_0x10;
    uint field_0x14;

public:
    Stereo3DSurround();
    float SetStereoWiden(float param_1);
    float SetMiddleImage(float param_1);
    void Process(int *param_1,int param_2);
};


#endif //VIPER_STEREOSURROUND_H
