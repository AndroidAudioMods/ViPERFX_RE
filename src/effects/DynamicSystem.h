//
// Created by mart on 2/12/21.
//

#ifndef VIPER_DYNAMICSYSTEM_H
#define VIPER_DYNAMICSYSTEM_H


class DynamicSystem {
    undefined4 field_0x0;
    int field_0x4;
    int field_0x8;
    int field_0xc;
    uint field_0x10;
    undefined4 field_0x14;
    undefined4 field_0x18;
    undefined4 field_0x1c;
    undefined4 field_0x20;
    struct PolesFilter field_0x24;
    struct PolesFilter field_0x98;
    struct FixedBiquad field_0x10c;
    int samplerate; // Created by retype action
    bool enabled; // Created by retype action
    undefined field_0x135;
    undefined field_0x136;
    undefined field_0x137;
    
public:
    DynamicSystem();
    void SetSamplingRate(uint param_1);
    void ~ZN13DynamicSystem10SetXCoeffsEjj(int param_1,int param_2);
    void ~ZN13DynamicSystem10SetYCoeffsEjj(int param_1,int param_2);
    void ~ZN13DynamicSystem11SetSideGainEff(int param_1,int param_2);
    void ~ZN13DynamicSystem11SetBassGainEf(int param_1);
    void Reset();
    undefined4 SetEnable(bool param_1);
    void Process(int *param_1,int param_2);
};


#endif //VIPER_DYNAMICSYSTEM_H
