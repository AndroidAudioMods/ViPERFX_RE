//
// Created by mart on 2/12/21.
//

#include "DepthSurround.h"

// DepthSurround::RefreshStrength(short)

void DepthSurround::RefreshStrength(short param_1) {
    undefined4 uVar1;
    uint uVar2;
    undefined4 extraout_r1;
    uint uVar3;
    short sVar4;
    undefined4 unaff_r4;
    undefined4 unaff_r5;
    undefined4 unaff_r6;
    undefined4 in_lr;
    undefined4 in_cr0;
    undefined4 in_cr1;
    double dVar5;
    longlong lVar6;

    sVar4 = param_1;
    if (param_1 != 0) {
        sVar4 = 1;
    }
    this[3] = (DepthSurround)(499 < param_1);
    this[2] = SUB21(sVar4,0);
    if (sVar4 != 0) {
        uVar1 = 0;
        dVar5 = pow((double)CONCAT44(unaff_r5,unaff_r4),(double)CONCAT44(in_lr,unaff_r6));
        coprocessor_function(0xb,6,5,in_cr1,in_cr1,in_cr0);
        lVar6 = __fixdfdi(SUB84(dVar5,0),uVar1,extraout_r1);
        uVar3 = (uint)((ulonglong)lVar6 >> 0x20);
        uVar2 = (uint)lVar6;
        if (0 < (int)(uVar3 + (uVar2 >= 0x80000000)) !=
            (lVar6 < 0 && (int)(~uVar3 + (uint)(uVar2 < 0x80000000)) < 0)) {
            uVar2 = 0x7fffffff;
        }
        *(uint *)(this + 4) = uVar2;
        return;
    }
    *(undefined4 *)(this + 4) = 0;
    return;
}



// DepthSurround::SetSamplingRate(unsigned int)

void DepthSurround::SetSamplingRate(uint param_1) {
    uint in_r1;
    float in_s0;
    float fVar1;
    undefined8 uVar2;
    float extraout_s2;
    float extraout_s3;
    float extraout_s4;

    fVar1 = (float)TimeConstDelay::SetParameters
            ((TimeConstDelay *)(param_1 + 0x10),(uint)ROUND((float)(ulonglong)in_r1),
             in_s0);
    uVar2 = TimeConstDelay::SetParameters
            ((TimeConstDelay *)(param_1 + 0x1c),(uint)ROUND((float)(ulonglong)in_r1),fVar1);
    FixedBiquad::SetHighPassParameter
            ((FixedBiquad *)(param_1 + 0x28),(float)uVar2,(float)((ulonglong)uVar2 >> 0x20),
             extraout_s2,extraout_s3,extraout_s4);
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    return;
}



// DepthSurround::DepthSurround()

DepthSurround::DepthSurround() {
    TimeConstDelay::TimeConstDelay((TimeConstDelay *)(this + 0x10));
    TimeConstDelay::TimeConstDelay((TimeConstDelay *)(this + 0x1c));
    FixedBiquad::FixedBiquad((FixedBiquad *)(this + 0x28));
    *(undefined2 *)this = 0;
    this[2] = (DepthSurround)0x0;
    this[3] = (DepthSurround)0x0;
    *(undefined4 *)(this + 4) = 0;
    *(undefined4 *)(this + 8) = 0;
    *(undefined4 *)(this + 0xc) = 0;
    SetSamplingRate((uint)this);
    RefreshStrength(this,*(short *)this);
    return this;
}



// DepthSurround::SetStrength(short)

void DepthSurround::SetStrength(short param_1) {
    *(short *)this = param_1;
    RefreshStrength(this,param_1);
    return;
}



// DepthSurround::Process(int*, int)

void DepthSurround::Process(int *param_1,int param_2) {
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    int *piVar6;
    uint uVar7;
    undefined8 uVar8;
    int local_48;
    int local_40;

    if (this[2] != (DepthSurround)0x0) {
        uVar7 = (uint)(byte)this[3];
        if (uVar7 == 0) {
            if (0 < param_2) {
                piVar6 = param_1 + 1;
                do {
                    iVar3 = piVar6[-1];
                    uVar7 = uVar7 + 1;
                    iVar4 = param_1[1];
                    iVar1 = TimeConstDelay::ProcessSample((int)(this + 0x10));
                    iVar2 = TimeConstDelay::ProcessSample((int)(this + 0x1c));
                    uVar8 = VectorShiftRight((longlong)*(int *)(this + 4) * (longlong)iVar2 + 0x1000000,0x19);
                    local_48 = (int)uVar8;
                    uVar8 = VectorShiftRight((longlong)iVar1 * (longlong)*(int *)(this + 4) + 0x1000000,0x19);
                    *(int *)(this + 0xc) = local_48;
                    local_40 = (int)uVar8;
                    *(int *)(this + 8) = local_40;
                    iVar1 = (iVar3 + local_40) - (iVar4 + local_48) >> 1;
                    iVar2 = iVar3 + local_40 + iVar4 + local_48 >> 1;
                    iVar3 = FixedBiquad::ProcessSample((FixedBiquad *)(this + 0x28),iVar1);
                    iVar1 = iVar1 - iVar3;
                    piVar6[-1] = iVar2 + iVar1;
                    param_1[1] = iVar2 - iVar1;
                    param_1 = param_1 + 2;
                    piVar6 = piVar6 + 2;
                } while (uVar7 != param_2);
            }
        }
        else {
            if (0 < param_2) {
                iVar1 = 0;
                piVar6 = param_1 + 1;
                do {
                    iVar4 = piVar6[-1];
                    iVar1 = iVar1 + 1;
                    iVar5 = param_1[1];
                    iVar2 = TimeConstDelay::ProcessSample((int)(this + 0x10));
                    iVar3 = TimeConstDelay::ProcessSample((int)(this + 0x1c));
                    uVar8 = VectorShiftRight((longlong)*(int *)(this + 4) * (longlong)-iVar3 + 0x1000000,0x19)
                            ;
                    local_48 = (int)uVar8;
                    uVar8 = VectorShiftRight((longlong)iVar2 * (longlong)*(int *)(this + 4) + 0x1000000,0x19);
                    *(int *)(this + 0xc) = local_48;
                    local_40 = (int)uVar8;
                    *(int *)(this + 8) = local_40;
                    iVar2 = (iVar4 + local_40) - (iVar5 + local_48) >> 1;
                    iVar3 = iVar4 + local_40 + iVar5 + local_48 >> 1;
                    iVar4 = FixedBiquad::ProcessSample((FixedBiquad *)(this + 0x28),iVar2);
                    iVar2 = iVar2 - iVar4;
                    piVar6[-1] = iVar3 + iVar2;
                    param_1[1] = iVar3 - iVar2;
                    param_1 = param_1 + 2;
                    piVar6 = piVar6 + 2;
                } while (iVar1 != param_2);
                return;
            }
        }
    }
    return;
}
