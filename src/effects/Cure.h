//
// Created by mart on 2/13/21.
//

#ifndef VIPER_CURE_H
#define VIPER_CURE_H


class Cure {
    struct Crossfeed field_0x0;
    struct PassFilter field_0x38;
    bool enabled; // Created by retype action
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;

public:
    ~Cure();
    void Reset();
    Cure();
    undefined4 SetEnable(bool param_1);
    void SetSamplingRate(int param_1);
    void ~ZN4Cure9SetCutoffEi(int param_1);
    void ~ZN4Cure11SetFeedbackEf(float param_1);
    void ~ZN4Cure9SetPresetEj(uint param_1);
    short ~ZN4Cure9GetCutoffEv();
    float ~ZN4Cure11GetFeedbackEv();
    float ~ZN4Cure13GetLevelDelayEv();
    undefined4 ~ZN4Cure9GetPresetEv();
    void Process(int *param_1,int param_2);
};


#endif //VIPER_CURE_H
