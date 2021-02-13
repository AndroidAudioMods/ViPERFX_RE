//
// Created by mart on 2/13/21.
//

#ifndef VIPER_PROCESSUNIT_FX_H
#define VIPER_PROCESSUNIT_FX_H


#include "main.h"

class ProcessUnit_FX {
public:
    undefined * * field_0x0;
    Effect* field_0x4;
    uint samplerate; // Created by retype action
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined4 field_0x14;
    undefined4 field_0x18;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    undefined field_0x20;
    undefined field_0x21;
    undefined field_0x22;
    undefined field_0x23;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    undefined field_0x30;
    undefined field_0x31;
    undefined field_0x32;
    undefined field_0x33;
    undefined4 field_0x34;
    undefined4 field_0x38;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    undefined field_0x40;
    undefined field_0x41;
    undefined field_0x42;
    undefined field_0x43;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
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
    undefined4 field_0x60;
    undefined4 field_0x64;
    undefined * field_0x68;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    undefined8 field_0x70;
    undefined field_0x78;
    undefined field_0x79;
    undefined field_0x7a;
    undefined field_0x7b;
    undefined4 field_0x7c;
    AdaptiveBuffer_FPI32 * floatIntBuffer;
    WaveBuffer_R32 * waveBuffer;
    undefined4 field_0x88;
    Convolver;
    VHE;
    ViPERDDC * vddc;
    SpectrumExtend;
    IIRFilter;
    ColorfulMusic colorful;
    Reverberation * reverb;
    PlaybackGain;
    FETCompressor;
    DynamicSystem;
    ViPERBass * vbass;
    ViPERClarity * vclarity;
    DiffSurround;
    Cure;
    TubeSimulator * tubeSim;
    AnalogX;
    SpeakerCorrection;
    SoftwareLimiter * softLimit1;
    SoftwareLimiter * softLimit2;
    undefined4 field_0xd8;
    undefined4 field_0xdc;
    undefined4 field_0xe0;

public:
    ProcessUnit_FX();
    ~ProcessUnit_FX();
    void ResetAllEffects();
    void DispatchCommand(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,signed *param_7);
    int processBuffer(short *param_1,int param_2);
    int command(uint param_1,uint param_2,void *param_3,uint *param_4,void *param_5);
};


#endif //VIPER_PROCESSUNIT_FX_H
