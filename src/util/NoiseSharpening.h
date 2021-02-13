//
// Created by mart on 2/13/21.
//

#ifndef VIPER_NOISESHARPENING_H
#define VIPER_NOISESHARPENING_H


class NoiseSharpening {
    struct IIR_1st field_0x0;
    struct IIR_1st field_0x10;
    int field_0x20;
    int field_0x24;
    int field_0x28;
    int field_0x2c;

public:
    void Reset();
    NoiseSharpening();
    void SetSamplingRate(int param_1);
    void SetGain(float param_1);
    void Process(int *param_1,int param_2);
};


#endif //VIPER_NOISESHARPENING_H
