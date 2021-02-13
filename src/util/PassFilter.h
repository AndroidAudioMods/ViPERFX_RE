//
// Created by mart on 2/13/21.
//

#ifndef VIPER_PASSFILTER_H
#define VIPER_PASSFILTER_H


class PassFilter {
    struct IIR_NOrder_BW_LH * field_0x0;
    struct IIR_NOrder_BW_LH * field_0x4;
    struct IIR_NOrder_BW_LH * field_0x8;
    struct IIR_NOrder_BW_LH * field_0xc;
    undefined4 samplerate;

public:
    ~PassFilter();
    void Reset();
    PassFilter();
    void SetSamplingRate(int param_1);
    void ProcessFrames(int *param_1,int param_2);
};


#endif //VIPER_PASSFILTER_H
