//
// Created by mart on 2/12/21.
//

#ifndef VIPER_EFFECT
#define VIPER_EFFECT


class Effect{
    undefined4 field_0x0;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    undefined4 field_0x8;
    int * field_0xc;
    int * field_0x10;
    int field_0x14;
    int * field_0x18;
    int * field_0x1c;
    int * field_0x20;
    undefined4 field_0x24;
    char field_0x28;
    undefined field_0x29;
    undefined2 field_0x2a;
    int * field_0x2c;
    int * field_0x30;
    undefined4 samplerate;
    undefined4 field_0x38;
    int * field_0x3c;
    int * field_0x40;
    undefined4 field_0x44;
    char field_0x48;
    undefined field_0x49;
    undefined2 field_0x4a;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    undefined field_0x50;
    undefined field_0x51;
    undefined field_0x52;
    undefined field_0x53;
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    undefined field_0x58;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    void * field_0x60;
    int * field_0x64;
    struct ProcessUnit_FX * field_0x68;

public:
    Effect();
    ~Effect();
    int configure(effect_config_t *param_1);
    int command(uint param_1,uint param_2,void *param_3,uint *param_4,void *param_5);
    virtual int process(audio_buffer_s *param_1,audio_buffer_s *param_2);
};


#endif //VIPER_EFFECT
