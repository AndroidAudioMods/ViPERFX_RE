//
// Created by mart on 2/13/21.
//

#ifndef VIPER_CROSSFEED_H
#define VIPER_CROSSFEED_H


class Crossfeed {
    int field_0x0;
    int field_0x4;
    int field_0x8;
    int field_0xc;
    int field_0x10;
    int field_0x14;
    int field_0x18;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    int field_0x20;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    int field_0x28;
    uint field_0x2c;
    short cutoff;
    short feedback; // Created by retype action
    int samplerate;

public:
    ~Crossfeed();
    void FilterSample(int *param_1);
    void Reset();
    Crossfeed();
    void SetSamplingRate(int param_1);
    void SetPreset(uint param_1);
    void SetCutoff(int param_1);
    void SetFeedback(float param_1);
    short GetCutoff();
    float GetFeedback();
    float GetLevelDelay();
    undefined4 GetPreset();
    void ProcessFrames(int *param_1,int param_2);
};


#endif //VIPER_CROSSFEED_H
