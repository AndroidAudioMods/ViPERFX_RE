//
// Created by mart on 2/13/21.
//

#ifndef VIPER_HIGHSHELF_H
#define VIPER_HIGHSHELF_H


class HighShelf {
    float field_0x0;
    float field_0x4;
    float field_0x8;
    int field_0xc;
    int field_0x10;
    int field_0x14;
    int field_0x18;
    int field_0x1c;
    int field_0x20;
    int field_0x24;
    int field_0x28;
    int field_0x2c;
    int field_0x30;
    int field_0x34;
    int field_0x38;

public:
    void SetSamplingRate(int param_1);
    void SetFrequency(float param_1);
    void SetQuality(float param_1);
    void SetGain(float param_1);
    uint Process(int param_1);
};


#endif //VIPER_HIGHSHELF_H
