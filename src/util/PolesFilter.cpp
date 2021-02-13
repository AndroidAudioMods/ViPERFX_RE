//
// Created by mart on 2/12/21.
//

#include "PolesFilter.h"

// PolesFilter::UpdateCoeff()

void PolesFilter::UpdateCoeff() {
    undefined4 extraout_r1;
    undefined4 extraout_r1_00;
    undefined4 in_cr0;
    undefined4 in_cr1;
    undefined4 in_cr10;
    undefined4 in_cr11;
    undefined4 uVar1;
    undefined4 uVar2;
    double unaff_d8;
    double dVar3;
    undefined4 in_d17;

    memset(this,0,0x34);
    memset(&this->field_0x34,0,0x34);
    coprocessor_function(0xb,6,4,in_cr1,in_cr0,in_cr10);
    sin(unaff_d8);
    dVar3 = (double)CONCAT44(extraout_r1,in_d17) + (double)CONCAT44(extraout_r1,in_d17);
    uVar1 = SUB84(ROUND(dVar3 * 33554432.0 + 0.5),0);
    this->field_0x0 = uVar1;
    coprocessor_function(0xb,6,0,in_cr0,in_cr11,in_cr10);
    uVar2 = SUB84(dVar3,0);
    sin(unaff_d8);
    this->field_0x34 = uVar1;
    uVar2 = SUB84(ROUND(((double)CONCAT44(extraout_r1_00,uVar2) +
                         (double)CONCAT44(extraout_r1_00,uVar2)) * 33554432.0 + 0.5),0);
    this->field_0x4 = uVar2;
    this->field_0x38 = uVar2;
    return;
}



// PolesFilter::PolesFilter()

PolesFilter::PolesFilter() {
    this->samplerate = 0xac44;
    this->field_0x68 = 0xa0;
    this->field_0x6c = 8000;
    UpdateCoeff(this);
    return this;
}



// PolesFilter::DoFilterLeft(int, int*, int*, int*)

void PolesFilter::DoFilterLeft(int param_1,int *param_2,int *param_3,int *param_4) {
    longlong lVar1;
    longlong lVar2;
    int iVar3;
    undefined4 uVar4;
    int iVar5;
    undefined4 uVar6;
    int iVar7;
    int iVar8;

    iVar7 = *(int *)&this->field_0x10;
    iVar8 = this->field_0x4;
    lVar1 = (longlong)iVar8 * (longlong)(param_1 - *(int *)&this->field_0x24) + 0x1000000;
    lVar2 = (longlong)(int)this->field_0x0 * (longlong)(param_1 - *(int *)&this->field_0x14) +
                           0x1000000;
    uVar6 = *(undefined4 *)&this->field_0x8;
    *(int *)&this->field_0x8 = param_1;
    uVar4 = *(undefined4 *)&this->field_0xc;
    *(undefined4 *)&this->field_0xc = uVar6;
    iVar5 = *(int *)&this->field_0x24 + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
    *(undefined4 *)&this->field_0x10 = uVar4;
    *(int *)&this->field_0x24 = iVar5;
    iVar3 = *(int *)&this->field_0x14 + ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
    lVar1 = (longlong)iVar8 * (longlong)(iVar5 - *(int *)&this->field_0x28) + 0x1000000;
    *(int *)&this->field_0x14 = iVar3;
    lVar2 = (longlong)(int)this->field_0x0 * (longlong)(iVar3 - *(int *)&this->field_0x18) + 0x1000000
            ;
    iVar3 = *(int *)&this->field_0x28 + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
    *(int *)&this->field_0x28 = iVar3;
    lVar1 = (longlong)iVar8 * (longlong)(iVar3 - *(int *)&this->field_0x2c) + 0x1000000;
    iVar3 = *(int *)&this->field_0x18 + ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
    lVar2 = (longlong)(int)this->field_0x0 * (longlong)(iVar3 - *(int *)&this->field_0x1c) + 0x1000000
            ;
    *(int *)&this->field_0x18 = iVar3;
    iVar3 = *(int *)&this->field_0x2c + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
    *(int *)&this->field_0x2c = iVar3;
    lVar1 = (longlong)iVar8 * (longlong)(iVar3 - *(int *)&this->field_0x30) + 0x1000000;
    iVar3 = *(int *)&this->field_0x1c + ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
    *(int *)&this->field_0x1c = iVar3;
    lVar2 = (longlong)(int)this->field_0x0 * (longlong)(iVar3 - *(int *)&this->field_0x20) + 0x1000000
            ;
    iVar3 = *(int *)&this->field_0x30 + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
    *(int *)&this->field_0x30 = iVar3;
    iVar3 = iVar7 - iVar3;
    iVar5 = *(int *)&this->field_0x20 + ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
    *(int *)&this->field_0x20 = iVar5;
    *param_2 = iVar5;
    *param_3 = iVar3;
    *param_4 = iVar7 - (iVar5 + iVar3);
    return;
}



// PolesFilter::DoFilterRight(int, int*, int*, int*)

void PolesFilter::DoFilterRight(int param_1,int *param_2,int *param_3,int *param_4) {
    longlong lVar1;
    longlong lVar2;
    int iVar3;
    undefined4 uVar4;
    int iVar5;
    undefined4 uVar6;
    int iVar7;
    int iVar8;

    iVar7 = *(int *)&this->field_0x44;
    iVar8 = this->field_0x38;
    lVar1 = (longlong)iVar8 * (longlong)(param_1 - *(int *)&this->field_0x58) + 0x1000000;
    lVar2 = (longlong)(int)this->field_0x34 * (longlong)(param_1 - *(int *)&this->field_0x48) +
                           0x1000000;
    uVar6 = *(undefined4 *)&this->field_0x3c;
    *(int *)&this->field_0x3c = param_1;
    uVar4 = *(undefined4 *)&this->field_0x40;
    *(undefined4 *)&this->field_0x40 = uVar6;
    iVar5 = *(int *)&this->field_0x58 + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
    *(undefined4 *)&this->field_0x44 = uVar4;
    *(int *)&this->field_0x58 = iVar5;
    iVar3 = *(int *)&this->field_0x48 + ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
    lVar1 = (longlong)iVar8 * (longlong)(iVar5 - *(int *)&this->field_0x5c) + 0x1000000;
    *(int *)&this->field_0x48 = iVar3;
    lVar2 = (longlong)(int)this->field_0x34 * (longlong)(iVar3 - *(int *)&this->field_0x4c) +
                           0x1000000;
    iVar3 = *(int *)&this->field_0x5c + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
    *(int *)&this->field_0x5c = iVar3;
    lVar1 = (longlong)iVar8 * (longlong)(iVar3 - *(int *)&this->field_0x60) + 0x1000000;
    iVar3 = *(int *)&this->field_0x4c + ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
    lVar2 = (longlong)(int)this->field_0x34 * (longlong)(iVar3 - *(int *)&this->field_0x50) +
                           0x1000000;
    *(int *)&this->field_0x4c = iVar3;
    iVar3 = *(int *)&this->field_0x60 + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
    *(int *)&this->field_0x60 = iVar3;
    lVar1 = (longlong)iVar8 * (longlong)(iVar3 - *(int *)&this->field_0x64) + 0x1000000;
    iVar3 = *(int *)&this->field_0x50 + ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
    *(int *)&this->field_0x50 = iVar3;
    lVar2 = (longlong)(int)this->field_0x34 * (longlong)(iVar3 - *(int *)&this->field_0x54) +
                           0x1000000;
    iVar3 = *(int *)&this->field_0x64 + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
    *(int *)&this->field_0x64 = iVar3;
    iVar3 = iVar7 - iVar3;
    iVar5 = *(int *)&this->field_0x54 + ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
    *(int *)&this->field_0x54 = iVar5;
    *param_2 = iVar5;
    *param_3 = iVar3;
    *param_4 = iVar7 - (iVar5 + iVar3);
    return;
}



// PolesFilter::SetSamplingRate(int)

void PolesFilter::SetSamplingRate(int param_1) {
    this->samplerate = param_1;
    UpdateCoeff(this);
    return;
}



// PolesFilter::SetPassFilter(int, int)

void PolesFilter::SetPassFilter(int param_1,int param_2) {
    this->field_0x68 = param_1;
    this->field_0x6c = param_2;
    UpdateCoeff(this);
    return;
}



void PolesFilter::~ZN11PolesFilter5ResetEv() {
    undefined4 extraout_r1;
    undefined4 extraout_r1_00;
    undefined4 in_cr0;
    undefined4 in_cr1;
    undefined4 in_cr10;
    undefined4 in_cr11;
    undefined4 uVar1;
    undefined4 uVar2;
    double unaff_d8;
    double dVar3;
    undefined4 in_d17;

    memset(this,0,0x34);
    memset(&this->field_0x34,0,0x34);
    coprocessor_function(0xb,6,4,in_cr1,in_cr0,in_cr10);
    sin(unaff_d8);
    dVar3 = (double)CONCAT44(extraout_r1,in_d17) + (double)CONCAT44(extraout_r1,in_d17);
    uVar1 = SUB84(ROUND(dVar3 * 33554432.0 + 0.5),0);
    this->field_0x0 = uVar1;
    coprocessor_function(0xb,6,0,in_cr0,in_cr11,in_cr10);
    uVar2 = SUB84(dVar3,0);
    sin(unaff_d8);
    this->field_0x34 = uVar1;
    uVar2 = SUB84(ROUND(((double)CONCAT44(extraout_r1_00,uVar2) +
                         (double)CONCAT44(extraout_r1_00,uVar2)) * 33554432.0 + 0.5),0);
    this->field_0x4 = uVar2;
    this->field_0x38 = uVar2;
    return;
}
