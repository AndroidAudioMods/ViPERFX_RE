//
// Created by mart on 2/12/21.
//

#ifndef VIPER_ANALOGX_H
#define VIPER_ANALOGX_H


class AnalogX {
    struct MultiBiquad field_0x0;
    struct MultiBiquad field_0x24;
    struct Harmonic field_0x48;
    struct Harmonic field_0x84;
    struct MultiBiquad field_0xc0;
    struct MultiBiquad field_0xe4;
    struct MultiBiquad field_0x108;
    struct MultiBiquad field_0x12c;
    undefined field_0x150;
    undefined field_0x151;
    undefined field_0x152;
    undefined field_0x153;
    int field_0x154;
    undefined4 processingModel;
    int samplerate; // Created by retype action
    bool enabled; // Created by retype action
    undefined field_0x161;
    undefined field_0x162;
    undefined field_0x163;

public:
    void Reset();
    AnalogX();
    void SetSamplingRate(uint param_1);
    void SetProcessingModel(int param_1);
    void Process(int *param_1,int param_2);
};


#endif //VIPER_ANALOGX_H
