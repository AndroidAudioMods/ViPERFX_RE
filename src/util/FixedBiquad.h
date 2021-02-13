//
// Created by mart on 2/12/21.
//

#ifndef VIPER_FIXEDBIQUAD_H
#define VIPER_FIXEDBIQUAD_H


class FixedBiquad {
    undefined4 field_0x0;
    undefined4 field_0x4;
    undefined4 field_0x8;
    undefined4 field_0xc;
    int field_0x10;
    int field_0x14;
    int field_0x18;
    int field_0x1c;
    int field_0x20;

public:
    void SetCoeffs(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6);
    void Reset();
    FixedBiquad();
    void SetHighPassParameter(float param_1,float param_2,float param_3,float param_4,float param_5);
    void SetBandPassParameter(int param_1,int samplerate,int param_3);
    void SetLowPassParameter(float param_1,float param_2,float param_3);
    uint ProcessSample(int param_1);
};


#endif //VIPER_FIXEDBIQUAD_H
