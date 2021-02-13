//
// Created by mart on 2/13/21.
//

#include "Crossfeed.h"

// Crossfeed::~Crossfeed()

Crossfeed::~Crossfeed() {
    return;
}



// Crossfeed::FilterSample(int*)

void Crossfeed::FilterSample(int *param_1) {
    longlong lVar1;
    longlong lVar2;
    longlong lVar3;
    longlong lVar4;
    longlong lVar5;
    int iVar6;
    int iVar7;

    lVar1 = (longlong)this->field_0x4 * (longlong)this->field_0x20 + 0x1000000;
    lVar2 = (longlong)this->field_0x0 * (longlong)*param_1 + 0x1000000;
    lVar3 = (longlong)this->field_0x4 * (longlong)*(int *)&this->field_0x24 + 0x1000000;
    this->field_0x20 =
            ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7) +
            ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
    lVar1 = (longlong)this->field_0xc * (longlong)this->field_0x18 + 0x1000000;
    lVar2 = (longlong)this->field_0x0 * (longlong)param_1[1] + 0x1000000;
    lVar4 = (longlong)this->field_0xc * (longlong)*(int *)&this->field_0x1c + 0x1000000;
    iVar6 = ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7) +
            ((uint)lVar3 >> 0x19 | (int)((ulonglong)lVar3 >> 0x20) << 7);
    *(int *)&this->field_0x24 = iVar6;
    lVar2 = (longlong)this->field_0x10 * (longlong)this->field_0x28 + 0x1000000;
    lVar3 = (longlong)this->field_0x8 * (longlong)*param_1 + 0x1000000;
    lVar5 = (longlong)this->field_0x10 * (longlong)(int)this->field_0x2c + 0x1000000;
    iVar7 = ((uint)lVar3 >> 0x19 | (int)((ulonglong)lVar3 >> 0x20) << 7) +
            ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) +
            ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
    this->field_0x28 = iVar7;
    iVar6 = iVar6 + iVar7;
    lVar1 = (longlong)this->field_0x8 * (longlong)param_1[1] + 0x1000000;
    this->field_0x2c =
            ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) +
            ((uint)lVar4 >> 0x19 | (int)((ulonglong)lVar4 >> 0x20) << 7) +
            ((uint)lVar5 >> 0x19 | (int)((ulonglong)lVar5 >> 0x20) << 7);
    this->field_0x18 = *param_1;
    *(int *)&this->field_0x1c = param_1[1];
    *param_1 = iVar6;
    iVar7 = this->field_0x2c + this->field_0x20;
    param_1[1] = iVar7;
    lVar1 = (longlong)iVar6 * (longlong)this->field_0x14 + 0x1000000;
    *param_1 = (uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7;
    lVar1 = (longlong)iVar7 * (longlong)this->field_0x14 + 0x1000000;
    param_1[1] = (uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7;
    return;
}



// Crossfeed::Reset()

void Crossfeed::Reset() {
    undefined4 uVar1;
    undefined4 uVar2;
    undefined4 uVar3;
    undefined4 extraout_r1;
    undefined4 extraout_r1_00;
    undefined4 extraout_r1_01;
    undefined4 extraout_r1_02;
    undefined4 extraout_r1_03;
    undefined4 extraout_r1_04;
    undefined4 in_cr0;
    undefined4 in_cr1;
    undefined4 in_cr2;
    undefined4 in_cr3;
    undefined4 in_cr4;
    undefined4 in_cr11;
    undefined4 in_cr13;
    double dVar4;
    double dVar5;
    double dVar6;
    double __x;

    dVar5 = (double)(longlong)(int)(*(uint *)&this->cutoff & 0xffff);
    uVar2 = 0;
    coprocessor_function(0xb,6,1,in_cr0,in_cr13,in_cr0);
    __x = -3.833333333333333;
    uVar1 = uVar2;
    pow(-3.833333333333333,dVar5);
    pow(__x,dVar5);
    dVar4 = 1.0 - (double)CONCAT44(extraout_r1_00,uVar2);
    uVar2 = SUB84(dVar4,0);
    log10(__x);
    uVar3 = 0;
    dVar6 = __x - (double)CONCAT44(extraout_r1_01,uVar2) * 20.0;
    pow(__x,dVar5);
    coprocessor_function(0xb,6,5,in_cr1,in_cr0,in_cr2);
    uVar2 = SUB84(dVar6 / (double)(longlong)this->samplerate,0);
    exp(__x);
    coprocessor_function(0xb,2,4,in_cr11,in_cr3,in_cr11);
    coprocessor_function(0xb,6,5,in_cr0,in_cr1,in_cr4);
    coprocessor_function(0xb,2,1,in_cr11,in_cr11,in_cr3);
    this->field_0x4 = SUB84(ROUND((double)CONCAT44(extraout_r1_03,uVar2) * 33554432.0 + 0.5),0);
    this->field_0x0 = SUB84(ROUND((double)CONCAT44(extraout_r1_03,uVar2) * 33554432.0 + 0.5),0);
    uVar2 = SUB84((double)CONCAT44(extraout_r1_02,uVar3) / (double)(longlong)this->samplerate,0);
    exp(__x);
    dVar5 = (double)CONCAT44(extraout_r1_04,uVar2);
    this->field_0x10 = SUB84(ROUND(dVar5 * 33554432.0 + 0.5),0);
    this->field_0xc = SUB84(ROUND(0.5 - dVar5 * 33554432.0),0);
    this->field_0x8 = SUB84(ROUND((1.0 - (1.0 - dVar5) * dVar4) * 33554432.0 + 0.5),0);
    this->field_0x14 =
            SUB84(ROUND((1.0 / ((1.0 - dVar4) + (double)CONCAT44(extraout_r1,uVar1))) * 33554432.0 + 0.5)(0);
    memset(&this->field_0x18,0,0x18);
    return;
}



// Crossfeed::Crossfeed()

Crossfeed::Crossfeed() {
    memset(this,0,0x30);
    this->samplerate = 0xac44;
    *(undefined4 *)&this->cutoff = 0x2d02bc;
    Reset(this);
    return this;
}



// Crossfeed::SetSamplingRate(int)

void Crossfeed::SetSamplingRate(int param_1) {
    if (this->samplerate == param_1) {
        return;
    }
    this->samplerate = param_1;
    Reset(this);
    return;
}



// Crossfeed::SetPreset(unsigned int)

void Crossfeed::SetPreset(uint param_1) {
    *(uint *)&this->cutoff = param_1;
    Reset(this);
    return;
}



// Crossfeed::SetCutoff(int)

void Crossfeed::SetCutoff(int param_1) {
    SetPreset(this,param_1 | (uint)(ushort)this->feedback << 0x10);
    return;
}



// Crossfeed::SetFeedback(float)

void Crossfeed::SetFeedback(float param_1) {
    undefined4 in_cr7;

    coprocessor_function(10,6,1,in_cr7,in_cr7,in_cr7);
    SetPreset(this,(uint)(ushort)this->cutoff);
    return;
}



// Crossfeed::GetCutoff()

short Crossfeed::GetCutoff() {
    return this->cutoff;
}



// Crossfeed::GetFeedback()

float Crossfeed::GetFeedback() {
    return (float)(longlong)(int)(uint)(ushort)this->feedback / 10.0;
}



// Crossfeed::GetLevelDelay()

float Crossfeed::GetLevelDelay() {
    int iVar1;
    undefined4 in_cr7;
    float fVar2;

    iVar1 = GetCutoff(this);
    if (iVar1 - 300U < 0x6a5) {
        fVar2 = 18700.0 / (float)(longlong)iVar1;
        coprocessor_function(10,6,4,in_cr7,in_cr7,in_cr7);
    }
    else {
        fVar2 = 0.0;
    }
    return fVar2;
}



// Crossfeed::GetPreset()

undefined4 Crossfeed::GetPreset() {
    return *(undefined4 *)&this->cutoff;
}



// Crossfeed::ProcessFrames(int*, int)

void Crossfeed::ProcessFrames(int *param_1,int param_2) {
    int iVar1;

    if (param_2 < 1) {
        return;
    }
    iVar1 = param_2 + -1;
    do {
        iVar1 = iVar1 + -1;
        FilterSample(this,param_1);
        param_1 = param_1 + 2;
    } while (iVar1 != -1);
    return;
}
