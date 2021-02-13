//
// Created by mart on 2/13/21.
//

#include "HighShelf.h"

// HighShelf::SetSamplingRate(int)

void HighShelf::SetSamplingRate(int param_1) {
    undefined4 uVar1;
    undefined4 uVar2;
    undefined4 extraout_r1;
    undefined4 extraout_r1_00;
    undefined4 extraout_r1_01;
    undefined in_ZR;
    undefined4 in_cr0;
    undefined4 in_cr1;
    undefined4 in_cr2;
    undefined4 in_cr4;
    undefined4 in_cr8;
    undefined4 in_cr11;
    undefined4 in_cr12;
    undefined4 in_cr13;
    undefined4 in_cr14;
    undefined4 uVar3;
    int iVar5;
    double unaff_d8;
    double dVar6;
    double dVar7;
    double dVar8;
    double dVar9;
    double dVar4;

    coprocessor_function(0xb,2,1,in_cr8,in_cr8,in_cr1);
    uVar1 = SUB84((double)*(float *)this / (double)(longlong)param_1,0);
    uVar2 = uVar1;
    cos(unaff_d8);
    sin(unaff_d8);
    dVar6 = (double)CONCAT44(extraout_r1_00,uVar1);
    coprocessor_function(0xb,6,5,in_cr1,in_cr1,in_cr2);
    uVar1 = SUB84((double)*(float *)(this + 8) / 40.0,0);
    dVar4 = exp(unaff_d8);
    uVar3 = SUB84(dVar4,0);
    dVar4 = (double)CONCAT44(extraout_r1_01,uVar1);
    dVar9 = dVar4 + dVar4;
    if (!(bool)in_ZR) {
        dVar7 = sqrt(unaff_d8);
        uVar3 = SUB84(dVar7,0);
    }
    coprocessor_function(0xb,6,0,in_cr1,in_cr12,in_cr13);
    coprocessor_function(0xb,2,0,in_cr13,in_cr13,in_cr14);
    coprocessor_function(0xb,2,4,in_cr11,in_cr0,in_cr11);
    coprocessor_function(0xb,6,1,in_cr2,in_cr8,in_cr2);
    dVar8 = (dVar4 + 1.0) - dVar9;
    dVar7 = (dVar4 - 1.0) - (double)CONCAT44(extraout_r1,uVar2);
    coprocessor_function(0xb,6,5,in_cr2,in_cr2,in_cr4);
    coprocessor_function(0xb,6,4,in_cr1,in_cr1,in_cr8);
    coprocessor_function(0xb,2,4,in_cr8,in_cr0,in_cr8);
    *(int *)(this + 0x38) = SUB84(ROUND(dVar4 * 33554432.0 + 0.5),0);
    *(undefined4 *)(this + 0x20) = 0xf8000000;
    *(int *)(this + 0x1c) = SUB84(ROUND((dVar4 + 1.0 + dVar9 + dVar6) * 33554432.0 + 0.5),0);
    iVar5 = SUB84(ROUND((dVar6 + dVar8) * 33554432.0 + 0.5),0);
    *(int *)(this + 0x24) = SUB84(ROUND(dVar4 * 33554432.0 + 0.5),0);
    *(int *)(this + 0x28) = iVar5;
    uVar2 = __aeabi_ldivmod(uVar3,0,0x40000,iVar5,iVar5 >> 0x1f);
    *(undefined4 *)(this + 0x2c) = uVar2;
    *(undefined4 *)(this + 0xc) = 0;
    *(undefined4 *)(this + 0x10) = 0;
    *(undefined4 *)(this + 0x14) = 0;
    *(undefined4 *)(this + 0x18) = 0;
    *(int *)(this + 0x30) = SUB84(ROUND((dVar7 + dVar7) * 33554432.0 + 0.5),0);
    *(int *)(this + 0x34) = SUB84(ROUND((dVar8 - dVar6) * 33554432.0 + 0.5),0);
    return;
}



// HighShelf::SetFrequency(float)

void HighShelf::SetFrequency(float param_1) {
    undefined4 in_r1;

    *(undefined4 *)this = in_r1;
    return;
}



// HighShelf::SetQuality(float)

void HighShelf::SetQuality(float param_1) {
    undefined4 in_r1;

    *(undefined4 *)(this + 4) = in_r1;
    return;
}



// HighShelf::SetGain(float)

void HighShelf::SetGain(float param_1) {
    int in_r0;
    undefined4 unaff_r4;
    undefined4 in_lr;
    undefined4 in_cr0;
    undefined4 in_cr1;

    log10((double)CONCAT44(in_lr,unaff_r4));
    coprocessor_function(0xb,6,5,in_cr0,in_cr1,in_cr0);
    *(undefined4 *)(in_r0 + 8) = 0x41a00000;
    return;
}



// HighShelf::Process(int)

uint HighShelf::Process(int param_1) {
    longlong lVar1;
    longlong lVar2;
    longlong lVar3;
    longlong lVar4;
    longlong lVar5;
    uint uVar6;
    int iVar7;
    int iVar8;
    int iVar9;

    iVar8 = *(int *)(this + 0xc);
    lVar1 = (longlong)*(int *)(this + 0x1c) * (longlong)param_1 + 0x1000000;
    *(int *)(this + 0xc) = param_1;
    iVar7 = *(int *)(this + 0x10);
    lVar2 = (longlong)*(int *)(this + 0x20) * (longlong)iVar8 + 0x1000000;
    iVar9 = *(int *)(this + 0x18);
    *(int *)(this + 0x10) = iVar8;
    lVar3 = (longlong)*(int *)(this + 0x24) * (longlong)iVar7 + 0x1000000;
    *(int *)(this + 0x18) = *(int *)(this + 0x14);
    lVar4 = (longlong)*(int *)(this + 0x30) * (longlong)*(int *)(this + 0x14) + 0x1000000;
    lVar5 = (longlong)*(int *)(this + 0x34) * (longlong)iVar9 + 0x1000000;
    lVar1 = (longlong)
                    (int)(((((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) +
                            ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7) +
                            ((uint)lVar3 >> 0x19 | (int)((ulonglong)lVar3 >> 0x20) << 7)) -
                           ((uint)lVar4 >> 0x19 | (int)((ulonglong)lVar4 >> 0x20) << 7)) -
                          ((uint)lVar5 >> 0x19 | (int)((ulonglong)lVar5 >> 0x20) << 7)) *
            (longlong)*(int *)(this + 0x2c) + 0x1000000;
    uVar6 = (uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7;
    *(uint *)(this + 0x14) = uVar6;
    return uVar6;
}
