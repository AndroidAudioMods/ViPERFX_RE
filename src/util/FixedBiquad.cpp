//
// Created by mart on 2/12/21.
//

#include "FixedBiquad.h"


// FixedBiquad::SetCoeffs(float, float, float, float, float, float)

void FixedBiquad::SetCoeffs(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6
) {
    this->field_0x4 = 0;
    this->field_0x0 = 0;
    this->field_0xc = 0;
    this->field_0x8 = 0;
    this->field_0x1c = -SUB84(ROUND((double)((float)param_2 / (float)param_1) * 33554432.0 + 0.5),0);
    this->field_0x20 = -SUB84(ROUND((double)((float)param_3 / (float)param_1) * 33554432.0 + 0.5),0);
    this->field_0x10 = SUB84(ROUND((double)((float)param_4 / (float)param_1) * 33554432.0 + 0.5),0);
    this->field_0x18 = SUB84(ROUND((double)((float)param_6 / (float)param_1) * 33554432.0 + 0.5),0);
    this->field_0x14 = SUB84(ROUND((double)((float)param_5 / (float)param_1) * 33554432.0 + 0.5),0);
    return;
}



// FixedBiquad::Reset()

void FixedBiquad::Reset() {
    this->field_0x1c = 0;
    this->field_0x20 = 0;
    this->field_0x10 = 0;
    this->field_0x14 = 0;
    this->field_0x18 = 0;
    this->field_0x0 = 0;
    this->field_0x4 = 0;
    this->field_0x8 = 0;
    this->field_0xc = 0;
    return;
}



// FixedBiquad::FixedBiquad()

FixedBiquad::FixedBiquad() {
    Reset(this);
    SetCoeffs(this,0x3f800000,0,0,0x3f800000,0,0);
    return this;
}



// FixedBiquad::SetHighPassParameter(float, float, float, float, float)

void FixedBiquad::SetHighPassParameter(float param_1,float param_2,float param_3,float param_4,float param_5) {
    float fVar1;
    float fVar2;
    int iVar3;
    float fVar4;
    float in_r2;
    undefined in_ZR;
    undefined4 in_cr7;
    undefined4 in_cr8;
    undefined4 in_cr9;
    undefined4 in_cr10;
    undefined4 in_cr11;
    undefined4 in_cr12;
    undefined4 in_cr13;
    float fVar5;
    float __x;
    float extraout_s1;
    float __y;
    float extraout_s1_00;
    float extraout_s1_01;
    float extraout_s1_02;
    float extraout_s1_03;
    float fVar6;
    float fVar7;
    float fVar8;
    float fVar9;
    float fVar10;
    float unaff_s24;

    fVar1 = 10.0;
    coprocessor_function(10,6,1,in_cr10,in_cr7,in_cr10);
    fVar10 = 6.283185 / in_r2;
    fVar5 = powf(param_1,param_2);
    fVar2 = fVar10;
    fVar5 = sinf(fVar5);
    if (!(bool)in_ZR) {
        fVar5 = sqrtf(fVar5);
    }
    fVar6 = SQRT(fVar1);
    coprocessor_function(10,2,0,in_cr9,in_cr9,in_cr7);
    fVar7 = fVar1 - 1.0;
    fVar8 = fVar1 + 1.0;
    coprocessor_function(10,2,1,in_cr9,in_cr9,in_cr7);
    __x = cosf(fVar5);
    coprocessor_function(10,2,4,in_cr12,in_cr9,in_cr11);
    __y = extraout_s1;
    fVar5 = fVar6;
    if (!(bool)in_ZR) {
        fVar5 = fVar1;
        __x = sqrtf(__x);
        __y = extraout_s1_03;
    }
    coprocessor_function(10,2,0,in_cr11,in_cr10,in_cr11);
    coprocessor_function(10,6,5,in_cr12,in_cr8,in_cr12);
    coprocessor_function(10,6,5,in_cr12,in_cr12,in_cr7);
    coprocessor_function(10,2,1,in_cr13,in_cr13,in_cr8);
    if (!(bool)in_ZR) {
        __x = sqrtf(__x);
        __y = extraout_s1_02;
    }
    fVar9 = fVar8 - unaff_s24;
    coprocessor_function(10,2,1,in_cr12,in_cr12,in_cr8);
    fVar4 = fVar6;
    if (!(bool)in_ZR) {
        fVar4 = fVar1;
        __x = sqrtf(__x);
        __y = extraout_s1_01;
    }
    if (!(bool)in_ZR) {
        __x = sqrtf(__x);
        __y = extraout_s1_00;
        fVar6 = fVar1;
    }
    iVar3 = 0x41200000;
    powf(__x,__y);
    fVar7 = fVar7 - fVar10;
    coprocessor_function(10,2,1,in_cr13,in_cr13,in_cr7);
    coprocessor_function(10,6,5,in_cr12,in_cr12,in_cr7);
    coprocessor_function(10,6,1,in_cr7,in_cr12,in_cr7);
    SetCoeffs(this,(int)(fVar9 + (fVar4 + fVar4) * fVar2),(int)(fVar7 + fVar7),
              (int)(fVar9 - (fVar6 + fVar6) * fVar2),
              (int)(fVar8 + unaff_s24 + (fVar5 + fVar5) * fVar2),-0x40000000,iVar3);
    return;
}



// FixedBiquad::SetBandPassParameter(float, float, float)

void FixedBiquad::SetBandPassParameter(int param_1,int samplerate,int param_3) {
    float fVar1;
    undefined4 in_cr6;
    undefined4 in_cr7;
    undefined4 in_cr8;
    undefined4 in_cr9;
    float in_s0;
    float __x;
    float fVar2;
    float phaseStep;

    coprocessor_function(10,2,0,in_cr9,in_cr7,in_cr9);
    phaseStep = 6.283185 / (float)samplerate;
    fVar1 = phaseStep;
    __x = sinf(in_s0);
    fVar2 = fVar1 / ((float)param_3 + (float)param_3);
    cosf(__x);
    coprocessor_function(10,6,1,in_cr6,in_cr7,in_cr6);
    coprocessor_function(10,2,1,in_cr7,in_cr8,in_cr7);
    SetCoeffs(this,(int)(fVar2 + 1.0),-0x40000000,(int)(1.0 - fVar2),(int)phaseStep,0,
              (int)(0.0 - fVar1 * 0.5));
    return;
}



// FixedBiquad::SetLowPassParameter(float, float, float)

void FixedBiquad::SetLowPassParameter(float param_1,float param_2,float param_3) {
    float in_r2;
    float in_r3;
    undefined4 in_cr5;
    undefined4 in_cr6;
    undefined4 in_cr7;
    undefined4 in_cr8;
    float __x;
    float fVar1;
    float fVar2;

    coprocessor_function(10,6,1,in_cr8,in_cr7,in_cr8);
    fVar2 = 6.283185 / in_r2;
    fVar1 = fVar2;
    __x = sinf(param_1);
    fVar1 = fVar1 / (in_r3 + in_r3);
    cosf(__x);
    coprocessor_function(10,2,0,in_cr7,in_cr6,in_cr7);
    coprocessor_function(10,6,5,in_cr5,in_cr6,in_cr5);
    SetCoeffs(this,(int)(fVar1 + 1.0),-0x40000000,(int)(1.0 - fVar1),0x3f000000,(int)(1.0 - fVar2),
              0x3f000000);
    return;
}



// FixedBiquad::ProcessSample(int)

uint FixedBiquad::ProcessSample(int param_1) {
    longlong lVar1;
    uint uVar2;
    int iVar3;
    int iVar4;
    int iVar5;

    iVar3 = this->field_0x0;
    iVar5 = this->field_0x4;
    iVar4 = this->field_0xc;
    this->field_0x4 = iVar3;
    this->field_0x0 = param_1;
    this->field_0xc = this->field_0x8;
    lVar1 = (longlong)this->field_0x20 * (longlong)iVar4 +
                      (longlong)this->field_0x1c * (longlong)(int)this->field_0x8 +
                                                                  (longlong)this->field_0x18 * (longlong)iVar5 +
                                                                            (longlong)this->field_0x10 * (longlong)param_1 +
                                                                                      (longlong)this->field_0x14 * (longlong)iVar3;
    uVar2 = (uint)lVar1;
    uVar2 = uVar2 + 0x1000000 >> 0x19 |
            ((int)((ulonglong)lVar1 >> 0x20) + (uint)(0xfeffffff < uVar2)) * 0x80;
    this->field_0x8 = uVar2;
    return uVar2;
}
