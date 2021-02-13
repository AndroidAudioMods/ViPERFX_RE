//
// Created by mart on 2/12/21.
//

#ifndef VIPER_MULTIBIQUAD_H
#define VIPER_MULTIBIQUAD_H


class MultiBiquad {
    undefined4 field_0x0;
    undefined4 field_0x4;
    undefined4 field_0x8;
    undefined4 field_0xc;
    undefined4 field_0x10;
    undefined4 field_0x14;
    undefined4 field_0x18;
    undefined4 field_0x1c;
    undefined4 field_0x20;

public:
    MultiBiquad();
    void RefreshFilter(dword param_1,float param_2,float param_3,float param_4,float param_5,bool param_6);
    uint ProcessSample(int param_1);
};


#endif //VIPER_MULTIBIQUAD_H
