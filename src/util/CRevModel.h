//
// Created by mart on 2/12/21.
//

#ifndef VIPER_CREVMODEL_H
#define VIPER_CREVMODEL_H


class CRevModel {
    int field_0x0;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    uint field_0x8;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    uint field_0x10;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    uint field_0x18;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    undefined field_0x20;
    undefined field_0x21;
    undefined field_0x22;
    undefined field_0x23;
    int field_0x24;
    int field_0x28;
    int field_0x2c;
    struct CCombFilter field_0x30[8];
    struct CCombFilter field_0x110[8];
    struct CAllpassFilter field_0x1f0[8];
    void * field_0x270;
    void * field_0x274;
    void * field_0x278;
    void * field_0x27c;
    void * field_0x280;
    void * field_0x284;
    void * field_0x288;
    void * field_0x28c;
    void * field_0x290;
    void * field_0x294;
    void * field_0x298;
    void * field_0x29c;
    void * field_0x2a0;
    void * field_0x2a4;
    void * field_0x2a8;
    void * field_0x2ac;
    void * field_0x2b0;
    void * field_0x2b4;
    void * field_0x2b8;
    void * field_0x2bc;
    void * field_0x2c0;
    void * field_0x2c4;
    void * field_0x2c8;
    void * field_0x2cc;
    
public:
    ~CRevModel();
    void ProcessReplace(int *param_1,int *param_2,int param_3);
    void UpdateCoeffs();
    void SetRoomSize(int param_1);
    void GetRoomSize();
    void SetDamp(int param_1);
    void GetDamp();
    void SetWet(int param_1);
    void GetWet();
    void SetDry(int param_1);
    undefined8 GetDry();
    void SetWidth(int param_1);
    int GetWidth();
    void SetMode(int param_1);
    undefined4 GetMode();
    void Mute();
    void ~ZN9CRevModel5ResetEv();
    CRevModel();
};


#endif //VIPER_CREVMODEL_H
