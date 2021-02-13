//
// Created by mart on 2/12/21.
//

#ifndef VIPER_PLAYBACKGAIN_H
#define VIPER_PLAYBACKGAIN_H


class PlaybackGain {
    undefined4 field_0x0;
    undefined4 field_0x4;
    undefined4 field_0x8;
    undefined4 field_0xc;
    undefined4 field_0x10;
    undefined4 field_0x14;
    undefined4 field_0x18;
    undefined4 field_0x1c;
    undefined4 field_0x20;
    undefined4 field_0x24;
    struct FixedBiquad field_0x28;
    struct FixedBiquad field_0x4c;
    uint samplerate;
    undefined field_0x74;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;

public:
    PlaybackGain();
    void AnalyseWave(int *param_1,int param_2);
    void SetRatio(float param_1);
    void SetVolume(float param_1);
    void SetMaxGainFactor(float param_1);
    void Reset();
    undefined4 SetEnable(bool param_1);
    void SetSamplingRate(uint param_1);
    void Process(int *param_1,int param_2);
};


#endif //VIPER_PLAYBACKGAIN_H
