//
// Created by mart on 2/12/21.
//

#include "Stereo3DSurround.h"


// Stereo3DSurround::Stereo3DSurround()

Stereo3DSurround::Stereo3DSurround() {
    this->field_0x4 = 0x2000000;
    this->field_0x0 = 0.0;
    this->field_0x8 = 0x2000000;
    this->field_0xc = 0x1000000;
    this->field_0x10 = 0x1000000;
    this->field_0x14 = 0x1000000;
    return;
}



// Stereo3DSurround::SetStereoWiden(float)

float Stereo3DSurround::SetStereoWiden(float param_1) {
    uint uVar1;
    float in_r1;
    int iVar2;
    uint uVar3;
    uint uVar4;
    uint uVar5;
    uint uVar6;
    float extraout_s0;
    float fVar7;

    this->field_0x0 = in_r1;
    fVar7 = ROUND(in_r1 * 3.355443e+07 + 0.5);
    uVar3 = (int)fVar7 + 0x2000000;
    this->field_0x8 = uVar3;
    if ((int)uVar3 < 0x2000000) {
        uVar1 = 0x1000000;
        iVar2 = 0;
    }
    else {
        iVar2 = (int)fVar7 + 0x4000000;
        uVar1 = __aeabi_ldivmod(0,0x40000,iVar2,iVar2 >> 0x1f);
        iVar2 = (int)uVar1 >> 0x1f;
        param_1 = extraout_s0;
    }
    uVar5 = this->field_0x4;
    uVar4 = (uint)((ulonglong)uVar1 * (ulonglong)uVar3);
    this->field_0xc = uVar1;
    uVar6 = (uint)((ulonglong)uVar1 * (ulonglong)uVar5);
    this->field_0x10 =
            uVar6 + 0x1000000 >> 0x19 |
            (uVar1 * ((int)uVar5 >> 0x1f) + uVar5 * iVar2 +
             (int)((ulonglong)uVar1 * (ulonglong)uVar5 >> 0x20) + (uint)(0xfeffffff < uVar6)) * 0x80;
    this->field_0x14 =
            uVar4 + 0x1000000 >> 0x19 |
            (uVar1 * ((int)uVar3 >> 0x1f) + uVar3 * iVar2 +
             (int)((ulonglong)uVar1 * (ulonglong)uVar3 >> 0x20) + (uint)(0xfeffffff < uVar4)) * 0x80;
    return param_1;
}



// Stereo3DSurround::SetMiddleImage(float)

float Stereo3DSurround::SetMiddleImage(float param_1) {
    uint uVar1;
    float in_r1;
    int iVar2;
    uint uVar3;
    uint uVar4;
    uint uVar5;
    float extraout_s0;
    float fVar6;
    float fVar7;
    undefined8 uVar8;
    int iStack36;

    fVar7 = ROUND(this->field_0x0 * 3.355443e+07 + 0.5);
    fVar6 = ROUND(in_r1 * 3.355443e+07 + 0.5);
    uVar3 = (int)fVar7 + 0x2000000;
    this->field_0x4 = (uint)fVar6;
    this->field_0x8 = uVar3;
    if ((int)uVar3 < 0x2000000) {
        uVar1 = 0x1000000;
        iVar2 = 0;
    }
    else {
        iVar2 = (int)fVar7 + 0x4000000;
        uVar1 = __aeabi_ldivmod(0,0x40000,iVar2,iVar2 >> 0x1f);
        iVar2 = (int)uVar1 >> 0x1f;
        param_1 = extraout_s0;
    }
    this->field_0xc = uVar1;
    uVar8 = VectorShiftRight(CONCAT44(uVar3,uVar3),0x20);
    iStack36 = (int)((ulonglong)uVar8 >> 0x20);
    uVar5 = (uint)((ulonglong)uVar1 * (ulonglong)(uint)fVar6);
    uVar4 = (uint)((ulonglong)uVar1 * (ulonglong)uVar3);
    this->field_0x10 =
            uVar5 + 0x1000000 >> 0x19 |
            (uVar1 * ((int)fVar6 >> 0x1f) + (int)fVar6 * iVar2 +
             (int)((ulonglong)uVar1 * (ulonglong)(uint)fVar6 >> 0x20) + (uint)(0xfeffffff < uVar5)) *
            0x80;
    this->field_0x14 =
            uVar4 + 0x1000000 >> 0x19 |
            (uVar1 * iStack36 + uVar3 * iVar2 + (int)((ulonglong)uVar1 * (ulonglong)uVar3 >> 0x20) +
             (uint)(0xfeffffff < uVar4)) * 0x80;
    return param_1;
}



// Stereo3DSurround::Process(int*, int)

void Stereo3DSurround::Process(int *param_1,int param_2) {
    uint uVar1;
    longlong lVar2;
    longlong lVar3;
    uint uVar4;
    uint uVar5;
    uint uVar6;
    int *piVar7;
    uint uVar8;
    int *piVar9;

    uVar1 = param_2 << 1;
    uVar4 = uVar1 & 0xfffffffc;
    if (uVar4 != 0) {
        uVar8 = 0;
        piVar7 = param_1 + 1;
        piVar9 = param_1;
        do {
            uVar8 = uVar8 + 4;
            lVar2 = (longlong)(int)this->field_0x10 * (longlong)(piVar7[-1] + piVar9[1]) + 0x1000000;
            uVar6 = (uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7;
            lVar2 = (longlong)(int)this->field_0x14 * (longlong)(piVar9[1] - piVar7[-1]) + 0x1000000;
            lVar3 = (longlong)(int)this->field_0x10 * (longlong)(piVar9[2] + piVar9[3]) + 0x1000000;
            uVar5 = (uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7;
            lVar2 = (longlong)(int)this->field_0x14 * (longlong)(piVar9[3] - piVar9[2]) + 0x1000000;
            piVar7[-1] = uVar6 - uVar5;
            piVar9[1] = uVar5 + uVar6;
            uVar5 = (uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7;
            uVar6 = (uint)lVar3 >> 0x19 | (int)((ulonglong)lVar3 >> 0x20) << 7;
            piVar9[2] = uVar6 - uVar5;
            piVar9[3] = uVar5 + uVar6;
            piVar7 = piVar7 + 4;
            piVar9 = piVar9 + 4;
        } while (uVar8 < uVar4);
    }
    if ((uVar1 & 2) != 0) {
        while (uVar4 < uVar1) {
            lVar2 = (longlong)(int)this->field_0x10 * (longlong)(param_1[uVar4] + param_1[uVar4 + 1]) +
                                   0x1000000;
            lVar3 = (longlong)(int)this->field_0x14 * (longlong)(param_1[uVar4 + 1] - param_1[uVar4]) +
                                   0x1000000;
            uVar5 = (uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7;
            uVar8 = (uint)lVar3 >> 0x19 | (int)((ulonglong)lVar3 >> 0x20) << 7;
            param_1[uVar4] = uVar5 - uVar8;
            param_1[uVar4 + 1] = uVar8 + uVar5;
            uVar4 = uVar4 + 2;
        }
    }
    return;
}
