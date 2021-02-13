//
// Created by mart on 2/13/21.
//

#include "ViPERDDC.h"

// ViPERDDC::ViPERDDC()

ViPERDDC::ViPERDDC() {
    *(undefined4 *)&this->field_0x4 = 0xac44;
    *(undefined *)this = 0;
    *(undefined *)&this->field_0x1 = 0;
    *(undefined4 *)&this->field_0x8 = 0;
    *(undefined4 *)&this->field_0xc = 0;
    *(undefined4 *)&this->field_0x10 = 0;
    *(undefined4 *)&this->field_0x20 = 0;
    *(undefined4 *)&this->field_0x1c = 0;
    *(undefined4 *)&this->field_0x18 = 0;
    *(undefined4 *)&this->field_0x14 = 0;
    *(undefined4 *)&this->field_0x30 = 0;
    *(undefined4 *)&this->field_0x2c = 0;
    *(undefined4 *)&this->field_0x28 = 0;
    *(undefined4 *)&this->field_0x24 = 0;
    return;
}



// ViPERDDC::ReleaseResources()

void ViPERDDC::ReleaseResources() {
    void *pvVar1;
    void *pvVar2;
    int iVar3;
    int iVar4;

    pvVar1 = *(void **)&this->field_0xc;
    if (pvVar1 != nullptr) {
        iVar3 = *(int *)&this->field_0x8;
        if (iVar3 < 1) {
            LAB_0006da6c:
            operator_delete__(pvVar1);
        }
        else {
            iVar4 = 0;
            do {
                pvVar2 = *(void **)((int)pvVar1 + iVar4 * 4);
                iVar4 = iVar4 + 1;
                if (pvVar2 != nullptr) {
                    operator_delete__(pvVar2);
                    pvVar1 = *(void **)&this->field_0xc;
                    iVar3 = *(int *)&this->field_0x8;
                }
            } while (iVar4 < iVar3);
            if (pvVar1 != nullptr) goto LAB_0006da6c;
        }
        *(undefined4 *)&this->field_0xc = 0;
    }
    pvVar1 = *(void **)&this->field_0x10;
    if (pvVar1 == nullptr) goto LAB_0006dad4;
    iVar3 = *(int *)&this->field_0x8;
    if (iVar3 < 1) {
        LAB_0006dac4:
        operator_delete__(pvVar1);
    }
    else {
        iVar4 = 0;
        do {
            pvVar2 = *(void **)((int)pvVar1 + iVar4 * 4);
            iVar4 = iVar4 + 1;
            if (pvVar2 != nullptr) {
                operator_delete__(pvVar2);
                pvVar1 = *(void **)&this->field_0x10;
                iVar3 = *(int *)&this->field_0x8;
            }
        } while (iVar4 < iVar3);
        if (pvVar1 != nullptr) goto LAB_0006dac4;
    }
    *(undefined4 *)&this->field_0x10 = 0;
    LAB_0006dad4:
    if (*(void **)&this->field_0x14 != nullptr) {
        operator_delete__(*(void **)&this->field_0x14);
    }
    *(undefined4 *)&this->field_0x14 = 0;
    if (*(void **)&this->field_0x18 != nullptr) {
        operator_delete__(*(void **)&this->field_0x18);
    }
    *(undefined4 *)&this->field_0x18 = 0;
    if (*(void **)&this->field_0x1c != nullptr) {
        operator_delete__(*(void **)&this->field_0x1c);
    }
    *(undefined4 *)&this->field_0x1c = 0;
    if (*(void **)&this->field_0x20 != nullptr) {
        operator_delete__(*(void **)&this->field_0x20);
    }
    *(undefined4 *)&this->field_0x20 = 0;
    if (*(void **)&this->field_0x24 != nullptr) {
        operator_delete__(*(void **)&this->field_0x24);
    }
    *(undefined4 *)&this->field_0x24 = 0;
    if (*(void **)&this->field_0x28 != nullptr) {
        operator_delete__(*(void **)&this->field_0x28);
    }
    *(undefined4 *)&this->field_0x28 = 0;
    if (*(void **)&this->field_0x2c != nullptr) {
        operator_delete__(*(void **)&this->field_0x2c);
    }
    *(undefined4 *)&this->field_0x2c = 0;
    if (*(void **)&this->field_0x30 != nullptr) {
        operator_delete__(*(void **)&this->field_0x30);
    }
    *(undefined4 *)&this->field_0x30 = 0;
    *(undefined *)&this->field_0x1 = 0;
    return;
}



// ViPERDDC::~ViPERDDC()

ViPERDDC::~ViPERDDC() {
    ReleaseResources(this);
    return this;
}



// ViPERDDC::Reset()

void ViPERDDC::Reset() {
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;

    if ((*(char *)&this->field_0x1 != '\0') && (0 < *(int *)&this->field_0x8)) {
        iVar4 = *(int *)&this->field_0x14;
        iVar2 = 0;
        iVar3 = *(int *)&this->field_0x18;
        iVar1 = 0;
        do {
            *(undefined4 *)(iVar4 + iVar2) = 0;
            iVar1 = iVar1 + 1;
            *(undefined4 *)(iVar3 + iVar2) = 0;
            iVar2 = iVar2 + 4;
        } while (iVar1 < *(int *)&this->field_0x8);
    }
    return;
}



// ViPERDDC::SetEnable(bool)

undefined4 ViPERDDC::SetEnable(bool param_1) {
    char cVar1;

    cVar1 = *(char *)this;
    if (cVar1 == '\0') {
        if (param_1 == false) {
            return 0;
        }
        Reset(this);
        cVar1 = *(char *)this;
    }
    if (param_1 == (bool)cVar1) {
        return 0;
    }
    *(bool *)this = param_1;
    return 1;
}



// ViPERDDC::SetSamplingRate(int)

void ViPERDDC::SetSamplingRate(int param_1) {
    if (*(int *)&this->field_0x4 == param_1) {
        return;
    }
    *(int *)&this->field_0x4 = param_1;
    Reset(this);
    return;
}



// ViPERDDC::SetCoeffs(int, float*, float*)

void ViPERDDC::SetCoeffs(int param_1,float *param_2,float *param_3) {
    uint uVar1;
    void *pvVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    int iVar6;
    int iVar7;
    float *pfVar8;
    float *pfVar9;
    float fVar10;
    float fVar11;

    ReleaseResources(this);
    uVar1 = param_1 / 5;
    *(uint *)&this->field_0x8 = uVar1;
    if (uVar1 < 0x1fc00001) {
        uVar1 = uVar1 * 4;
    }
    else {
        uVar1 = 0xffffffff;
    }
    pvVar2 = operator_new__(uVar1);
    *(void **)&this->field_0xc = pvVar2;
    if (*(uint *)&this->field_0x8 < 0x1fc00001) {
        uVar1 = *(uint *)&this->field_0x8 << 2;
    }
    else {
        uVar1 = 0xffffffff;
    }
    pvVar2 = operator_new__(uVar1);
    *(void **)&this->field_0x10 = pvVar2;
    if ((*(void **)&this->field_0xc != nullptr) && (pvVar2 != nullptr)) {
        memset(*(void **)&this->field_0xc,0,*(int *)&this->field_0x8 << 2);
        memset(*(void **)&this->field_0x10,0,*(int *)&this->field_0x8 << 2);
        uVar1 = *(uint *)&this->field_0x8;
        if (0 < (int)uVar1) {
            iVar7 = *(int *)&this->field_0xc;
            iVar4 = 0;
            do {
                pvVar2 = operator_new__(0x14);
                *(void **)(iVar7 + iVar4 * 4) = pvVar2;
                iVar7 = *(int *)&this->field_0x10;
                pvVar2 = operator_new__(0x14);
                *(void **)(iVar7 + iVar4 * 4) = pvVar2;
                iVar7 = *(int *)&this->field_0xc;
                iVar5 = *(int *)(iVar7 + iVar4 * 4);
                if (iVar5 == 0) {
                    return;
                }
                iVar6 = *(int *)(*(int *)&this->field_0x10 + iVar4 * 4);
                if (iVar6 == 0) {
                    return;
                }
                iVar3 = 0;
                pfVar8 = param_2;
                pfVar9 = param_3;
                do {
                    fVar10 = *pfVar8;
                    pfVar8 = pfVar8 + 1;
                    fVar11 = *pfVar9;
                    pfVar9 = pfVar9 + 1;
                    *(float *)(iVar5 + iVar3) = ROUND(fVar10 * 3.355443e+07 + 0.5);
                    *(float *)(iVar6 + iVar3) = ROUND(fVar11 * 3.355443e+07 + 0.5);
                    iVar3 = iVar3 + 4;
                } while (iVar3 != 0x14);
                uVar1 = *(uint *)&this->field_0x8;
                iVar4 = iVar4 + 1;
                param_2 = param_2 + 5;
                param_3 = param_3 + 5;
            } while (iVar4 < (int)uVar1);
        }
        if (uVar1 < 0x1fc00001) {
            uVar1 = uVar1 << 2;
        }
        else {
            uVar1 = 0xffffffff;
        }
        pvVar2 = operator_new__(uVar1);
        *(void **)&this->field_0x14 = pvVar2;
        if (*(uint *)&this->field_0x8 < 0x1fc00001) {
            uVar1 = *(uint *)&this->field_0x8 << 2;
        }
        else {
            uVar1 = 0xffffffff;
        }
        pvVar2 = operator_new__(uVar1);
        *(void **)&this->field_0x18 = pvVar2;
        if (*(uint *)&this->field_0x8 < 0x1fc00001) {
            uVar1 = *(uint *)&this->field_0x8 << 2;
        }
        else {
            uVar1 = 0xffffffff;
        }
        pvVar2 = operator_new__(uVar1);
        *(void **)&this->field_0x1c = pvVar2;
        if (*(uint *)&this->field_0x8 < 0x1fc00001) {
            uVar1 = *(uint *)&this->field_0x8 << 2;
        }
        else {
            uVar1 = 0xffffffff;
        }
        pvVar2 = operator_new__(uVar1);
        *(void **)&this->field_0x20 = pvVar2;
        if (*(uint *)&this->field_0x8 < 0x1fc00001) {
            uVar1 = *(uint *)&this->field_0x8 << 2;
        }
        else {
            uVar1 = 0xffffffff;
        }
        pvVar2 = operator_new__(uVar1);
        *(void **)&this->field_0x24 = pvVar2;
        if (*(uint *)&this->field_0x8 < 0x1fc00001) {
            uVar1 = *(uint *)&this->field_0x8 << 2;
        }
        else {
            uVar1 = 0xffffffff;
        }
        pvVar2 = operator_new__(uVar1);
        *(void **)&this->field_0x28 = pvVar2;
        if (*(uint *)&this->field_0x8 < 0x1fc00001) {
            uVar1 = *(uint *)&this->field_0x8 << 2;
        }
        else {
            uVar1 = 0xffffffff;
        }
        pvVar2 = operator_new__(uVar1);
        *(void **)&this->field_0x2c = pvVar2;
        if (*(uint *)&this->field_0x8 < 0x1fc00001) {
            uVar1 = *(uint *)&this->field_0x8 << 2;
        }
        else {
            uVar1 = 0xffffffff;
        }
        pvVar2 = operator_new__(uVar1);
        *(void **)&this->field_0x30 = pvVar2;
        if (((((*(void **)&this->field_0x14 != nullptr) && (*(int *)&this->field_0x18 != 0)) &&
              (*(int *)&this->field_0x1c != 0)) &&
             ((*(int *)&this->field_0x20 != 0 && (*(int *)&this->field_0x24 != 0)))) &&
            ((*(int *)&this->field_0x28 != 0 && ((*(int *)&this->field_0x2c != 0 && (pvVar2 != nullptr))))))
        {
            memset(*(void **)&this->field_0x14,0,*(int *)&this->field_0x8 << 2);
            memset(*(void **)&this->field_0x18,0,*(int *)&this->field_0x8 << 2);
            memset(*(void **)&this->field_0x1c,0,*(int *)&this->field_0x8 << 2);
            memset(*(void **)&this->field_0x20,0,*(int *)&this->field_0x8 << 2);
            memset(*(void **)&this->field_0x24,0,*(int *)&this->field_0x8 << 2);
            memset(*(void **)&this->field_0x28,0,*(int *)&this->field_0x8 << 2);
            memset(*(void **)&this->field_0x2c,0,*(int *)&this->field_0x8 << 2);
            memset(*(void **)&this->field_0x30,0,*(int *)&this->field_0x8 << 2);
            *(undefined *)&this->field_0x1 = 1;
        }
    }
    return;
}



// ViPERDDC::Process(int*, int)

void ViPERDDC::Process(int *param_1,int param_2) {
    longlong lVar1;
    int iVar2;
    int iVar3;
    uint uVar4;
    int iVar5;
    uint uVar6;
    int iVar7;
    int *piVar8;
    int iVar9;
    int iVar10;
    uint uVar11;
    int iVar12;
    int iVar13;
    int iVar14;
    int iVar15;
    int iVar16;
    int iVar17;
    int iVar18;
    int iVar19;
    int iVar20;
    int iVar21;
    int *local_34;
    int *local_30;
    uint local_2c;

    if ((*(char *)&this->field_0x1 != '\0') && (*(char *)this != '\0')) {
        if (*(int *)&this->field_0x4 == 0xac44) {
            if (0 < param_2 * 2) {
                local_34 = param_1;
                local_30 = param_1 + 1;
                do {
                    uVar11 = local_34[1];
                    if (*(int *)&this->field_0x8 < 1) {
                        local_2c = 0;
                        uVar6 = 0;
                    }
                    else {
                        iVar12 = *(int *)&this->field_0x1c;
                        iVar2 = 0;
                        iVar17 = *(int *)&this->field_0x24;
                        iVar21 = 0;
                        iVar16 = *(int *)&this->field_0xc;
                        iVar7 = *(int *)&this->field_0x14;
                        iVar15 = *(int *)&this->field_0x2c;
                        uVar6 = local_30[-1];
                        do {
                            piVar8 = *(int **)(iVar16 + iVar2);
                            iVar21 = iVar21 + 1;
                            iVar5 = *(int *)(iVar7 + iVar2);
                            iVar13 = *(int *)(iVar12 + iVar2);
                            iVar3 = piVar8[1];
                            iVar19 = piVar8[2];
                            iVar14 = *piVar8;
                            iVar20 = piVar8[3];
                            iVar9 = piVar8[4];
                            iVar18 = *(int *)(iVar15 + iVar2);
                            iVar10 = *(int *)(iVar17 + iVar2);
                            *(int *)(iVar15 + iVar2) = iVar10;
                            lVar1 = (longlong)iVar9 * (longlong)iVar18 +
                                    (longlong)iVar20 * (longlong)iVar10 +
                                    (longlong)iVar19 * (longlong)iVar13 +
                                    (longlong)iVar14 * (longlong)(int)uVar6 + (longlong)iVar3 * (longlong)iVar5;
                            uVar4 = (uint)lVar1;
                            local_2c = uVar4 + 0x1000000 >> 0x19 |
                                       ((int)((ulonglong)lVar1 >> 0x20) + (uint)(0xfeffffff < uVar4)) * 0x80;
                            *(uint *)(iVar17 + iVar2) = local_2c;
                            *(undefined4 *)(iVar12 + iVar2) = *(undefined4 *)(iVar7 + iVar2);
                            *(uint *)(iVar7 + iVar2) = uVar6;
                            iVar2 = iVar2 + 4;
                            uVar6 = local_2c;
                        } while (iVar21 < *(int *)&this->field_0x8);
                        if (*(int *)&this->field_0x8 < 1) {
                            uVar6 = 0;
                        }
                        else {
                            iVar17 = *(int *)&this->field_0x30;
                            iVar7 = 0;
                            iVar15 = *(int *)&this->field_0x20;
                            iVar2 = 0;
                            iVar12 = *(int *)&this->field_0x28;
                            iVar21 = *(int *)&this->field_0x18;
                            do {
                                iVar2 = iVar2 + 1;
                                iVar13 = *(int *)(iVar21 + iVar7);
                                iVar18 = *(int *)(iVar15 + iVar7);
                                piVar8 = *(int **)(iVar16 + iVar7);
                                iVar3 = piVar8[1];
                                iVar5 = piVar8[2];
                                iVar19 = *piVar8;
                                iVar14 = piVar8[3];
                                iVar9 = piVar8[4];
                                iVar20 = *(int *)(iVar17 + iVar7);
                                iVar10 = *(int *)(iVar12 + iVar7);
                                *(int *)(iVar17 + iVar7) = iVar10;
                                lVar1 = (longlong)iVar9 * (longlong)iVar20 +
                                        (longlong)iVar14 * (longlong)iVar10 +
                                        (longlong)iVar5 * (longlong)iVar18 +
                                        (longlong)iVar19 * (longlong)(int)uVar11 +
                                                                          (longlong)iVar3 * (longlong)iVar13;
                                uVar6 = (uint)lVar1;
                                uVar6 = uVar6 + 0x1000000 >> 0x19 |
                                        ((int)((ulonglong)lVar1 >> 0x20) + (uint)(0xfeffffff < uVar6)) * 0x80;
                                *(uint *)(iVar12 + iVar7) = uVar6;
                                *(undefined4 *)(iVar15 + iVar7) = *(undefined4 *)(iVar21 + iVar7);
                                *(uint *)(iVar21 + iVar7) = uVar11;
                                iVar7 = iVar7 + 4;
                                uVar11 = uVar6;
                            } while (iVar2 < *(int *)&this->field_0x8);
                        }
                    }
                    piVar8 = local_34 + 2;
                    local_30[-1] = local_2c;
                    local_34[1] = uVar6;
                    local_34 = piVar8;
                    local_30 = local_30 + 2;
                } while (piVar8 != param_1 + param_2 * 2);
            }
        }
        else {
            if ((*(int *)&this->field_0x4 == 48000) && (0 < param_2 * 2)) {
                local_34 = param_1;
                local_30 = param_1 + 1;
                do {
                    uVar11 = local_34[1];
                    if (*(int *)&this->field_0x8 < 1) {
                        local_2c = 0;
                        uVar6 = 0;
                    }
                    else {
                        iVar12 = *(int *)&this->field_0x1c;
                        iVar2 = 0;
                        iVar17 = *(int *)&this->field_0x24;
                        iVar21 = 0;
                        iVar16 = *(int *)&this->field_0x10;
                        iVar7 = *(int *)&this->field_0x14;
                        iVar15 = *(int *)&this->field_0x2c;
                        uVar6 = local_30[-1];
                        do {
                            piVar8 = *(int **)(iVar16 + iVar2);
                            iVar21 = iVar21 + 1;
                            iVar5 = *(int *)(iVar7 + iVar2);
                            iVar18 = *(int *)(iVar12 + iVar2);
                            iVar3 = piVar8[1];
                            iVar13 = *piVar8;
                            iVar19 = piVar8[2];
                            iVar20 = piVar8[3];
                            iVar9 = piVar8[4];
                            iVar14 = *(int *)(iVar15 + iVar2);
                            iVar10 = *(int *)(iVar17 + iVar2);
                            *(int *)(iVar15 + iVar2) = iVar10;
                            lVar1 = (longlong)iVar9 * (longlong)iVar14 +
                                    (longlong)iVar20 * (longlong)iVar10 +
                                    (longlong)iVar19 * (longlong)iVar18 +
                                    (longlong)iVar13 * (longlong)(int)uVar6 + (longlong)iVar3 * (longlong)iVar5;
                            uVar4 = (uint)lVar1;
                            local_2c = uVar4 + 0x1000000 >> 0x19 |
                                       ((int)((ulonglong)lVar1 >> 0x20) + (uint)(0xfeffffff < uVar4)) * 0x80;
                            *(uint *)(iVar17 + iVar2) = local_2c;
                            *(undefined4 *)(iVar12 + iVar2) = *(undefined4 *)(iVar7 + iVar2);
                            *(uint *)(iVar7 + iVar2) = uVar6;
                            iVar2 = iVar2 + 4;
                            uVar6 = local_2c;
                        } while (iVar21 < *(int *)&this->field_0x8);
                        if (*(int *)&this->field_0x8 < 1) {
                            uVar6 = 0;
                        }
                        else {
                            iVar17 = *(int *)&this->field_0x30;
                            iVar7 = 0;
                            iVar15 = *(int *)&this->field_0x20;
                            iVar2 = 0;
                            iVar12 = *(int *)&this->field_0x28;
                            iVar21 = *(int *)&this->field_0x18;
                            do {
                                iVar2 = iVar2 + 1;
                                iVar13 = *(int *)(iVar21 + iVar7);
                                iVar18 = *(int *)(iVar15 + iVar7);
                                piVar8 = *(int **)(iVar16 + iVar7);
                                iVar3 = piVar8[1];
                                iVar5 = piVar8[2];
                                iVar19 = *piVar8;
                                iVar14 = piVar8[3];
                                iVar9 = piVar8[4];
                                iVar20 = *(int *)(iVar17 + iVar7);
                                iVar10 = *(int *)(iVar12 + iVar7);
                                *(int *)(iVar17 + iVar7) = iVar10;
                                lVar1 = (longlong)iVar9 * (longlong)iVar20 +
                                        (longlong)iVar14 * (longlong)iVar10 +
                                        (longlong)iVar5 * (longlong)iVar18 +
                                        (longlong)iVar19 * (longlong)(int)uVar11 +
                                                                          (longlong)iVar3 * (longlong)iVar13;
                                uVar6 = (uint)lVar1;
                                uVar6 = uVar6 + 0x1000000 >> 0x19 |
                                        ((int)((ulonglong)lVar1 >> 0x20) + (uint)(0xfeffffff < uVar6)) * 0x80;
                                *(uint *)(iVar12 + iVar7) = uVar6;
                                *(undefined4 *)(iVar15 + iVar7) = *(undefined4 *)(iVar21 + iVar7);
                                *(uint *)(iVar21 + iVar7) = uVar11;
                                iVar7 = iVar7 + 4;
                                uVar11 = uVar6;
                            } while (iVar2 < *(int *)&this->field_0x8);
                        }
                    }
                    piVar8 = local_34 + 2;
                    local_30[-1] = local_2c;
                    local_34[1] = uVar6;
                    local_34 = piVar8;
                    local_30 = local_30 + 2;
                } while (piVar8 != param_1 + param_2 * 2);
            }
        }
    }
    return;
}
