//
// Created by mart on 2/12/21.
//

#ifndef VIPER_DYNAMICBASS_H
#define VIPER_DYNAMICBASS_H


class DynamicBass {
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

public:
    void SetSamplingRate(uint param_1);
    void SetFilterXPassFrequency(int param_1,int param_2);
    void SetFilterYPassFrequency(int param_1,int param_2);
    void SetSideGain(int param_1,int param_2);
    void SetBassGain(int param_1);
    void Reset();
    DynamicBass();
    void FilterSamples(int *param_1,int param_2);
};


#endif //VIPER_DYNAMICBASS_H
