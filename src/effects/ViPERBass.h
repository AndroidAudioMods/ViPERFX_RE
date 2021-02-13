//
// Created by mart on 2/12/21.
//

#ifndef VIPER_VIPERBASS_H
#define VIPER_VIPERBASS_H


class ViPERBass {
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
    undefined field_0x20;
    undefined field_0x21;
    undefined field_0x22;
    undefined field_0x23;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;

public:
    ~ViPERBass();
    void Reset();
    ViPERBass();
    undefined4 SetEnable(bool param_1);
    void SetSamplingRate(int param_1);
    void SetProcessMode(int param_1);
    void SetSpeaker(int param_1);
    void SetBassFactor(float param_1);
    int Process(int *param_1,int param_2);
};


#endif //VIPER_VIPERBASS_H
