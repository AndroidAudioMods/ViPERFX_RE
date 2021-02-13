//
// Created by mart on 2/12/21.
//

#ifndef VIPER_CCOMBFILTER_H
#define VIPER_CCOMBFILTER_H


class CCombFilter {
    undefined4 feedback;
    undefined4 field_0x4;
    undefined4 damp;
    undefined4 field_0xc;
    int field_0x10;
    int field_0x14;
    undefined4 field_0x18;
    
public:
    CCombFilter();
    void SetBuffer(int *param_1,int param_2);
    int Process(int param_1);
    void Mute();
    void SetDamp(int param_1);
    undefined4 GetDamp();
    void SetFeedback(int param_1);
    undefined4 GetFeedback();
};


#endif //VIPER_CCOMBFILTER_H
