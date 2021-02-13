//
// Created by mart on 2/12/21.
//

#ifndef VIPER_SPEAKERCORRECTION_H
#define VIPER_SPEAKERCORRECTION_H


class SpeakerCorrection {
    uint samplerate;
    bool enabled; // Created by retype action
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct MultiBiquad field_0x8;
    struct MultiBiquad field_0x2c;
    struct FixedBiquad field_0x50;
    struct FixedBiquad field_0x74;
    struct FixedBiquad field_0x98;
    struct FixedBiquad field_0xbc;

public:
    void Reset();
    SpeakerCorrection();
    undefined4 SetEnable(bool param_1);
    void SetSamplingRate(uint param_1);
    void Process(int *param_1,int param_2);
};


#endif //VIPER_SPEAKERCORRECTION_H
