//
// Created by mart on 2/12/21.
//

#ifndef VIPER_SUBWOOFER_H
#define VIPER_SUBWOOFER_H


class Subwoofer {
    int field_0x0;
    int field_0x4;
    int field_0x8;
    int field_0xc;
    int field_0x10;
    undefined4 field_0x14;
    undefined4 field_0x18;
    undefined4 field_0x1c;
    undefined4 field_0x20;
    struct MultiBiquad field_0x24;
    struct MultiBiquad field_0x48;
    struct MultiBiquad field_0x6c;
    struct MultiBiquad field_0x90;
    struct MultiBiquad field_0xb4;

public:
    Subwoofer();
    void SetBassGain(int param_1,float param_2);
    void Process(int *param_1,int param_2);
};


#endif //VIPER_SUBWOOFER_H
