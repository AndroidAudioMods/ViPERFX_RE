//
// Created by mart on 2/12/21.
//

#include "SoftwareLimiter.h"

// SoftwareLimiter::SetGate(float)

void SoftwareLimiter::SetGate(float param_1) {
    float in_r1;

    *(float *)&this->field_0x10 = ROUND(in_r1 * 3.355443e+07 + 0.5);
    return;
}



// SoftwareLimiter::Process(int)

uint SoftwareLimiter::Process(int param_1) {
    char cVar1;
    longlong lVar2;
    longlong lVar3;
    longlong lVar4;
    int iVar5;
    undefined4 *puVar6;
    uint in_r1;
    uint uVar7;
    int iVar8;
    uint uVar9;
    uint uVar10;
    int iVar11;
    uint uVar12;
    uint *puVar13;

    uVar12 = *(uint *)(param_1 + 0x10);
    uVar7 = (in_r1 ^ (int)in_r1 >> 0x1f) - ((int)in_r1 >> 0x1f);
    uVar9 = (uint)*(byte *)(param_1 + 0xc24);
    if ((int)uVar12 < (int)uVar7) {
        if (uVar9 == 0) {
            puVar6 = (undefined4 *)(param_1 + 0x41c);
            do {
                uVar9 = uVar9 + 1;
                puVar6 = puVar6 + 1;
                *puVar6 = 0;
            } while (uVar9 != 0x200);
        }
        *(undefined *)(param_1 + 0xc24) = 1;
        LAB_000677d8:
        uVar12 = 8;
        uVar9 = *(uint *)(param_1 + 0xc20);
        do {
            uVar10 = uVar9 ^ 1;
            puVar13 = (uint *)(param_1 + 0xc20) + -(2 << (uVar12 & 0xff));
            puVar13[uVar9] = uVar7;
            uVar9 = (int)uVar9 >> 1;
            uVar10 = puVar13[uVar10];
            if ((int)uVar7 < (int)uVar10) {
                uVar7 = uVar10;
            }
            uVar12 = uVar12 - 1;
        } while (uVar12 != 0);
        uVar12 = *(uint *)(param_1 + 0x10);
        if ((int)uVar12 < (int)uVar7) {
            cVar1 = *(char *)(param_1 + 0xc24);
            iVar5 = *(int *)(param_1 + 0x14);
            uVar9 = *(int *)(param_1 + 0xc20) + 1U & 0xff;
            *(uint *)(param_1 + (*(int *)(param_1 + 0xc20) + 8) * 4) = in_r1;
            *(uint *)(param_1 + 0xc20) = uVar9;
            uVar9 = *(uint *)(param_1 + (uVar9 + 8) * 4);
            if (cVar1 != '\0') {
                iVar5 = __aeabi_ldivmod(uVar12 << 0x19,((int)uVar12 >> 0x1f) << 0x19 | uVar12 >> 7,uVar7,
                                        (int)uVar7 >> 0x1f);
            }
            goto LAB_00067898;
        }
        *(undefined *)(param_1 + 0xc24) = 0;
    }
    else {
        if (uVar9 != 0) goto LAB_000677d8;
    }
    iVar5 = *(int *)(param_1 + 0x14);
    uVar7 = *(int *)(param_1 + 0xc20) + 1U & 0xff;
    *(uint *)(param_1 + (*(int *)(param_1 + 0xc20) + 8) * 4) = in_r1;
    *(uint *)(param_1 + 0xc20) = uVar7;
    uVar9 = *(uint *)(param_1 + (uVar7 + 8) * 4);
    LAB_00067898:
    lVar2 = (longlong)*(int *)param_1 * (longlong)*(int *)(param_1 + 0x1c) + 0x1000000;
    lVar3 = (longlong)*(int *)(param_1 + 4) * (longlong)iVar5 + 0x1000000;
    lVar4 = (longlong)*(int *)(param_1 + 0xc) * (longlong)*(int *)(param_1 + 0x18) + 0x1000000;
    iVar11 = ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7) +
             ((uint)lVar3 >> 0x19 | (int)((ulonglong)lVar3 >> 0x20) << 7);
    *(int *)(param_1 + 0x1c) = iVar11;
    iVar8 = *(int *)(param_1 + 8) + ((uint)lVar4 >> 0x19 | (int)((ulonglong)lVar4 >> 0x20) << 7);
    iVar5 = iVar11;
    if (iVar8 <= iVar11) {
        *(int *)(param_1 + 0x18) = iVar8;
        iVar5 = iVar8;
    }
    lVar2 = (longlong)(int)uVar9 * (longlong)iVar5 + 0x1000000;
    if (iVar11 < iVar8) {
        *(int *)(param_1 + 0x18) = iVar11;
    }
    uVar7 = (uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7;
    if ((int)((uVar7 ^ (int)uVar7 >> 0x1f) - ((int)uVar7 >> 0x1f)) <= (int)uVar12) {
        return uVar7;
    }
    iVar5 = (uVar9 ^ (int)uVar9 >> 0x1f) - ((int)uVar9 >> 0x1f);
    iVar5 = __aeabi_ldivmod(uVar12 << 0x19,((int)uVar12 >> 0x1f) << 0x19 | uVar12 >> 7,iVar5,
                            iVar5 >> 0x1f);
    lVar2 = (longlong)(int)uVar9 * (longlong)iVar5 + 0x1000000;
    *(int *)(param_1 + 0x18) = iVar5;
    return (uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7;
}



// SoftwareLimiter::ResetLimiter()

void SoftwareLimiter::ResetLimiter() {
    undefined4 *puVar1;
    int iVar2;

    iVar2 = 0x100;
    puVar1 = (undefined4 *)&this->field_0x1c;
    do {
        iVar2 = iVar2 + -1;
        puVar1 = puVar1 + 1;
        *puVar1 = 0;
    } while (iVar2 != 0);
    puVar1 = (undefined4 *)&this->field_0x41c;
    iVar2 = 0x200;
    do {
        iVar2 = iVar2 + -1;
        puVar1 = puVar1 + 1;
        *puVar1 = 0;
    } while (iVar2 != 0);
    *(undefined *)&this->field_0xc24 = 0;
    *(undefined4 *)&this->field_0xc20 = 0;
    *(undefined4 *)&this->field_0x18 = 0x2000000;
    *(undefined4 *)&this->field_0x1c = 0x2000000;
    return;
}



// SoftwareLimiter::SoftwareLimiter()

SoftwareLimiter::SoftwareLimiter() {
    *(undefined4 *)this = 0x1ccbfb2;
    *(undefined4 *)&this->field_0x4 = 0x332618;
    *(undefined4 *)&this->field_0x8 = 0xd1c;
    *(undefined4 *)&this->field_0xc = 0x1fff2e5;
    *(undefined4 *)&this->field_0x10 = 0x1ffffff;
    *(undefined *)&this->field_0xc24 = 0;
    *(undefined4 *)&this->field_0xc20 = 0;
    *(undefined4 *)&this->field_0x18 = 0x2000000;
    *(undefined4 *)&this->field_0x1c = 0x2000000;
    *(undefined4 *)&this->field_0x14 = 0x2000000;
    ResetLimiter(this);
    return this;
}
