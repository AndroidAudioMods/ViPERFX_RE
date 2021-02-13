//
// Created by mart on 2/12/21.
//

#ifndef VIPER_POLYPHASE_H
#define VIPER_POLYPHASE_H


class Polyphase {
    struct FIR* field_0x0;
    struct FIR* field_0x4;
    struct WaveBuffer_I32* field_0x8;
    struct WaveBuffer_I32* field_0xc;
    void* field_0x10;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    undefined4 field_0x18;

public:
    Polyphase(int param_1);
    ~Polyphase();
    undefined4 GetLatency();
    void Reset();
    void SetSamplingRate(int param_1);
    int Process(int *param_1,int param_2);
};


#endif //VIPER_POLYPHASE_H
