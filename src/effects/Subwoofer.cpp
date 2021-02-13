//
// Created by mart on 2/12/21.
//

#include "Subwoofer.h"

// Subwoofer::Subwoofer()

Subwoofer::Subwoofer() {
    undefined8 uVar1;
    float extraout_s2;
    float extraout_s2_00;
    float extraout_s2_01;
    float extraout_s2_02;
    float extraout_s2_03;
    float extraout_s2_04;
    float extraout_s3;
    float extraout_s3_00;
    float extraout_s3_01;
    float extraout_s3_02;
    float extraout_s3_03;
    float extraout_s3_04;

    MultiBiquad::MultiBiquad((MultiBiquad *)this);
    MultiBiquad::MultiBiquad((MultiBiquad *)(this + 0x24));
    MultiBiquad::MultiBiquad((MultiBiquad *)(this + 0x48));
    MultiBiquad::MultiBiquad((MultiBiquad *)(this + 0x6c));
    MultiBiquad::MultiBiquad((MultiBiquad *)(this + 0x90));
    uVar1 = MultiBiquad::MultiBiquad((MultiBiquad *)(this + 0xb4));
    uVar1 = MultiBiquad::RefreshFilter
            ((MultiBiquad *)this,5,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20),
            extraout_s2,extraout_s3,false);
    uVar1 = MultiBiquad::RefreshFilter
            ((MultiBiquad *)(this + 0x24),5,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20),
             extraout_s2_00,extraout_s3_00,false);
    uVar1 = MultiBiquad::RefreshFilter
            ((MultiBiquad *)(this + 0x48),5,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20),
             extraout_s2_01,extraout_s3_01,false);
    uVar1 = MultiBiquad::RefreshFilter
            ((MultiBiquad *)(this + 0x6c),5,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20),
             extraout_s2_02,extraout_s3_02,false);
    uVar1 = MultiBiquad::RefreshFilter
            ((MultiBiquad *)(this + 0x90),0,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20),
             extraout_s2_03,extraout_s3_03,false);
    MultiBiquad::RefreshFilter
            ((MultiBiquad *)(this + 0xb4),0,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20),
             extraout_s2_04,extraout_s3_04,false);
    return this;
}



// WARNING: Unknown calling convention yet parameter storage is locked
// Subwoofer::SetBassGain(int, float)

void Subwoofer::SetBassGain(int param_1,float param_2) {
    float in_r2;
    char in_NG;
    bool in_ZR;
    char in_OV;
    undefined4 in_cr0;
    undefined4 in_cr1;
    undefined4 in_cr7;
    undefined4 in_cr8;
    undefined4 in_cr9;
    undefined4 in_s1;
    undefined8 uVar1;
    double dVar2;
    float in_s2;
    float extraout_s2;
    float extraout_s2_00;
    float extraout_s2_01;
    float extraout_s2_02;
    float extraout_s2_03;
    float extraout_s2_04;
    float in_s3;
    float extraout_s3;
    float extraout_s3_00;
    float extraout_s3_01;
    float extraout_s3_02;
    float extraout_s3_03;
    float extraout_s3_04;
    undefined uVar3;
    double dVar4;
    undefined4 in_stack_ffffffc8;
    undefined4 in_stack_ffffffcc;

    dVar2 = (double)CONCAT44(in_s1,param_2);
    dVar4 = (double)in_r2;
    if (in_ZR || in_NG != in_OV) {
        uVar3 = false;
    }
    else {
        log10((double)CONCAT44(in_stack_ffffffcc,in_stack_ffffffc8));
        coprocessor_function(0xb,6,4,in_cr0,in_cr1,in_cr8);
        coprocessor_function(10,6,1,in_cr7,in_cr9,in_cr7);
        uVar3 = SUB41((float)dVar4,0);
        dVar2 = log10((double)CONCAT44(in_stack_ffffffcc,in_stack_ffffffc8));
        coprocessor_function(0xb,2,4,in_cr8,in_cr1,in_cr8);
        in_s2 = extraout_s2_04;
        in_s3 = extraout_s3_04;
    }
    uVar1 = MultiBiquad::RefreshFilter
            ((MultiBiquad *)param_1,5,SUB84(dVar2,0),(float)((ulonglong)dVar2 >> 0x20),in_s2(in_s3,(bool)uVar3);
    uVar1 = MultiBiquad::RefreshFilter
            ((MultiBiquad *)(param_1 + 0x24),5,(float)uVar1,
             (float)((ulonglong)uVar1 >> 0x20),extraout_s2,extraout_s3,(bool)uVar3);
    uVar1 = MultiBiquad::RefreshFilter
            ((MultiBiquad *)(param_1 + 0x48),5,(float)uVar1,
             (float)((ulonglong)uVar1 >> 0x20),extraout_s2_00,extraout_s3_00,false);
    uVar1 = MultiBiquad::RefreshFilter
            ((MultiBiquad *)(param_1 + 0x6c),5,(float)uVar1,
             (float)((ulonglong)uVar1 >> 0x20),extraout_s2_01,extraout_s3_01,false);
    uVar1 = MultiBiquad::RefreshFilter
            ((MultiBiquad *)(param_1 + 0x90),0,(float)uVar1,
             (float)((ulonglong)uVar1 >> 0x20),extraout_s2_02,extraout_s3_02,false);
    MultiBiquad::RefreshFilter
            ((MultiBiquad *)(param_1 + 0xb4),0,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20),
             extraout_s2_03,extraout_s3_03,false);
    return;
}



// Subwoofer::Process(int*, int)

void Subwoofer::Process(int *param_1,int param_2) {
    longlong lVar1;
    longlong lVar2;
    longlong lVar3;
    longlong lVar4;
    int iVar5;
    int iVar6;
    int iVar7;

    if (0 < param_2) {
        iVar7 = param_2 + -1;
        do {
            iVar7 = iVar7 + -1;
            iVar5 = MultiBiquad::ProcessSample((MultiBiquad *)this,*param_1);
            iVar5 = MultiBiquad::ProcessSample((MultiBiquad *)(this + 0x48),iVar5);
            iVar5 = MultiBiquad::ProcessSample((MultiBiquad *)(this + 0x90),iVar5 - *param_1);
            iVar6 = MultiBiquad::ProcessSample((MultiBiquad *)(this + 0x24),param_1[1]);
            iVar6 = MultiBiquad::ProcessSample((MultiBiquad *)(this + 0x6c),iVar6);
            iVar6 = MultiBiquad::ProcessSample((MultiBiquad *)(this + 0xb4),iVar6 - param_1[1]);
            lVar1 = (longlong)iVar6 * 0x1333334 + 0x1000000;
            lVar2 = (longlong)iVar5 * 0x1333334 + 0x1000000;
            lVar3 = (longlong)param_1[1] * 0x1000000 + 0x1000000;
            lVar4 = (longlong)*param_1 * 0x1000000 + 0x1000000;
            param_1[1] = ((uint)lVar3 >> 0x19 | (int)((ulonglong)lVar3 >> 0x20) << 7) +
                         ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
            *param_1 = ((uint)lVar4 >> 0x19 | (int)((ulonglong)lVar4 >> 0x20) << 7) +
                       ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
            param_1 = param_1 + 2;
        } while (iVar7 != -1);
    }
    return;
}
