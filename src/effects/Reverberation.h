//
// Created by mart on 2/12/21.
//

#ifndef VIPER_REVERBERATION_H
#define VIPER_REVERBERATION_H


class Reverberation {
    undefined4 roomSize;
    float width;
    float damp;
    float wet;
    float dry;
    struct CRevModel field_0x14;
    undefined4 samplerate;
    bool enabled;
    undefined field_0x2e9;
    undefined field_0x2ea;
    undefined field_0x2eb;

public:
    Reverberation();
    void SetSamplingRate(uint param_1);
    void SetRoomSize(int param_1);
    void SetWidth(int param_1);
    void SetDamp(int param_1);
    void SetWet(int param_1);
    void SetDry(int param_1);
    void Reset();
    undefined4 SetEnable(bool param_1);
    void Process(int *param_1,int param_2);
};


#endif //VIPER_REVERBERATION_H
