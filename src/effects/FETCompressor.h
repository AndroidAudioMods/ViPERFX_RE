//
// Created by mart on 2/12/21.
//

#ifndef VIPER_FETCOMPRESSOR_H
#define VIPER_FETCOMPRESSOR_H


class FETCompressor {
    int samplerate;
    float parameters[17]; // Created by retype action
    undefined4 field_0x48;
    char field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    undefined field_0x50;
    undefined field_0x51;
    undefined field_0x52;
    undefined field_0x53;
    undefined4 field_0x54;
    undefined4 field_0x58;
    undefined4 field_0x5c;
    undefined4 field_0x60;
    undefined4 field_0x64;
    undefined4 field_0x68;
    undefined4 field_0x6c;
    undefined4 field_0x70;
    float field_0x74;
    undefined4 field_0x78;
    undefined4 field_0x7c;
    float field_0x80;
    int field_0x84;
    float field_0x88;
    int field_0x8c;
    float field_0x90;
    float field_0x94;
    float field_0x98;
    float field_0x9c;
    int field_0xa0;
    float field_0xa4;
    int field_0xa8;
    undefined field_0xac;
    undefined field_0xad;
    undefined field_0xae;
    undefined field_0xaf;

public:
    ~FETCompressor();
    void SetParameter(int param_1,float param_2);
    float GetParameter(int param_1);
    float GetParameterDefault(int param_1);
    float GetMeter(int param_1);
    void Reset();
    FETCompressor();
    void SetSamplingRate(int param_1);
    void ProcessSidechain(float param_1);
    void Process(int *param_1,int param_2);
};


#endif //VIPER_FETCOMPRESSOR_H
