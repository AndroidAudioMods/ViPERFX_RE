//
// Created by mart on 2/12/21.
//

#ifndef VIPER_CALLPASSFILTER_H
#define VIPER_CALLPASSFILTER_H


#include "AdaptiveBuffer_FPI32.h"

class CAllpassFilter {
    undefined4 feedback;
    undefined4 field_0x4;
    undefined4 field_0x8;
    undefined4 field_0xc;

public:
    CAllpassFilter();
    void SetBuffer(int *param_1,int param_2);
    int Process(int param_1);
    void Mute();
    void SetFeedback(int param_1);
    undefined4 GetFeedback();
};


#endif //VIPER_CALLPASSFILTER_H
