//
// Created by mart on 2/12/21.
//

#include "Convolver.h"


// Convolver::Convolver()

Convolver::Convolver() {
    WaveBuffer_R32 *pWVar1;
    PConvSingle_F32 *this_00;
    PConvSingle_F32 *__s;

    this_00 = (PConvSingle_F32 *)&this->field_0x8;
    do {
        __s = this_00 + 0x10;
        PConvSingle_F32::PConvSingle_F32(this_00);
        this_00 = __s;
    } while (__s != (PConvSingle_F32 *)&this->field_0x48);
    *(undefined4 *)&this->field_0x16c = 0xac44;
    *(undefined *)&this->field_0x170 = 0;
    pWVar1 = (WaveBuffer_R32 *)operator_new(0x20);
    WaveBuffer_R32::WaveBuffer_R32(pWVar1,2,0x1000);
    *(WaveBuffer_R32 **)this = pWVar1;
    pWVar1 = (WaveBuffer_R32 *)operator_new(0x20);
    WaveBuffer_R32::WaveBuffer_R32(pWVar1,2,0x1000);
    *(WaveBuffer_R32 **)&this->field_0x4 = pWVar1;
    memset(__s,0,0x100);
    *(undefined4 *)&this->field_0x148 = 0;
    *(undefined4 *)&this->field_0x14c = 0;
    *(undefined4 *)&this->field_0x150 = 0;
    *(undefined4 *)&this->field_0x154 = 0;
    *(undefined4 *)&this->field_0x158 = 0;
    *(undefined4 *)&this->field_0x15c = 0;
    *(undefined4 *)&this->field_0x160 = 0;
    *(undefined4 *)&this->field_0x164 = 0;
    return this;
}



// Convolver::~Convolver()

Convolver::~Convolver() {
    WaveBuffer_R32 *pWVar1;
    PConvSingle_F32 *this_00;

    pWVar1 = *(WaveBuffer_R32 **)this;
    if (pWVar1 != nullptr) {
        WaveBuffer_R32::~WaveBuffer_R32(pWVar1);
        operator_delete(pWVar1);
    }
    pWVar1 = *(WaveBuffer_R32 **)&this->field_0x4;
    *(undefined4 *)this = 0;
    if (pWVar1 != nullptr) {
        WaveBuffer_R32::~WaveBuffer_R32(pWVar1);
        operator_delete(pWVar1);
    }
    *(undefined4 *)&this->field_0x4 = 0;
    *(undefined4 *)&this->field_0x148 = 0;
    if (*(void **)&this->field_0x14c != nullptr) {
        operator_delete__(*(void **)&this->field_0x14c);
    }
    this_00 = (PConvSingle_F32 *)&this->field_0x48;
    *(undefined4 *)&this->field_0x14c = 0;
    *(undefined4 *)&this->field_0x150 = 0;
    *(undefined4 *)&this->field_0x154 = 0;
    *(undefined4 *)&this->field_0x158 = 0;
    *(undefined4 *)&this->field_0x15c = 0;
    do {
        this_00 = this_00 + -0x10;
        PConvSingle_F32::~PConvSingle_F32(this_00);
    } while ((PConvSingle_F32 *)&this->field_0x8 != this_00);
    return this;
}



// Convolver::GetEnabled()

undefined Convolver::GetEnabled() {
    return *(undefined *)&this->field_0x170;
}



// Convolver::SetSamplingRate(unsigned int)

void Convolver::SetSamplingRate(uint param_1) {
    if (*(uint *)&this->field_0x16c != param_1) {
        *(uint *)&this->field_0x16c = param_1;
    }
    return;
}



// Convolver::PrepareKernelBuffer(unsigned int, unsigned int, int)

void Convolver::PrepareKernelBuffer(uint param_1,uint param_2,int param_3) {
    bool bVar1;

    if (param_3 == 0) {
        bVar1 = 3 < param_2;
        if (param_2 != 4) {
            bVar1 = param_2 != 1;
        }
        if (!bVar1 || (param_2 == 4 || param_2 == 2)) {
            if (*(void **)&this->field_0x14c != nullptr) {
                operator_delete__(*(void **)&this->field_0x14c);
            }
            *(uint *)&this->field_0x150 = param_1;
            *(uint *)&this->field_0x158 = param_2;
            *(undefined4 *)&this->field_0x14c = 0;
            *(undefined4 *)&this->field_0x154 = 0;
            return;
        }
    }
    else {
        *(undefined4 *)&this->field_0x160 = 0;
        if (*(void **)&this->field_0x14c != nullptr) {
            operator_delete__(*(void **)&this->field_0x14c);
        }
        *(undefined4 *)&this->field_0x14c = 0;
        *(undefined4 *)&this->field_0x150 = 0;
        *(undefined4 *)&this->field_0x154 = 0;
        *(undefined4 *)&this->field_0x158 = 0;
        *(undefined4 *)&this->field_0x15c = 0;
        PConvSingle_F32::Reset((PConvSingle_F32 *)&this->field_0x8);
        PConvSingle_F32::Reset((PConvSingle_F32 *)&this->field_0x18);
        PConvSingle_F32::Reset((PConvSingle_F32 *)&this->field_0x28);
        PConvSingle_F32::Reset((PConvSingle_F32 *)&this->field_0x38);
        PConvSingle_F32::UnloadKernel((PConvSingle_F32 *)&this->field_0x8);
        PConvSingle_F32::UnloadKernel((PConvSingle_F32 *)&this->field_0x18);
        PConvSingle_F32::UnloadKernel((PConvSingle_F32 *)&this->field_0x28);
        PConvSingle_F32::UnloadKernel((PConvSingle_F32 *)&this->field_0x38);
        memset((void *)&this->field_0x48,0,0x100);
        *(undefined4 *)&this->field_0x148 = 0;
    }
    return;
}



// Convolver::SetKernelBuffer(unsigned int, float*, unsigned int)

void Convolver::SetKernelBuffer(uint param_1,float *param_2,uint param_3) {
    int iVar1;
    uint uVar2;
    void *pvVar3;

    if (param_3 == 0 || param_2 == nullptr) {
        return;
    }
    if (*(uint *)&this->field_0x150 != param_1) {
        return;
    }
    if (*(int *)&this->field_0x14c != 0) {
        iVar1 = param_3 + *(int *)&this->field_0x154;
        if ((uint)(iVar1 * 4) < 0x1fc00001) {
            uVar2 = iVar1 * 0x10;
        }
        else {
            uVar2 = 0xffffffff;
        }
        pvVar3 = operator_new__(uVar2);
        if (pvVar3 != nullptr) {
            memcpy(pvVar3,*(void **)&this->field_0x14c,*(int *)&this->field_0x154 << 2);
            if (*(void **)&this->field_0x14c != nullptr) {
                operator_delete__(*(void **)&this->field_0x14c);
            }
            *(void **)&this->field_0x14c = pvVar3;
            memcpy((void *)((int)pvVar3 + *(int *)&this->field_0x154 * 4),param_2,param_3 << 2);
            *(uint *)&this->field_0x154 = *(int *)&this->field_0x154 + param_3;
            return;
        }
        return;
    }
    if (param_3 * 4 < 0x1fc00001) {
        uVar2 = param_3 << 4;
    }
    else {
        uVar2 = 0xffffffff;
    }
    pvVar3 = operator_new__(uVar2);
    *(void **)&this->field_0x14c = pvVar3;
    if (pvVar3 != nullptr) {
        memcpy(pvVar3,param_2,param_3 * 4);
        *(uint *)&this->field_0x154 = *(int *)&this->field_0x154 + param_3;
        return;
    }
    return;
}



// Convolver::GetKernelID()

undefined4 Convolver::GetKernelID() {
    return *(undefined4 *)&this->field_0x148;
}



// Convolver::SetCrossChannel(float)

void Convolver::SetCrossChannel(float param_1) {
    undefined4 in_r1;
    bool in_NG;
    bool in_ZR;
    char in_OV;

    if (in_NG) {
        *(undefined4 *)&this->field_0x164 = 0;
    }
    else {
        if (!in_ZR && in_NG == (bool)in_OV) {
            *(undefined4 *)&this->field_0x164 = 0x3f800000;
        }
        if ((!in_ZR && in_NG == (bool)in_OV) ||
            (*(undefined4 *)&this->field_0x164 = in_r1, !in_ZR && in_NG == (bool)in_OV)) {
            *(undefined *)&this->field_0x168 = 1;
            return;
        }
    }
    *(undefined *)&this->field_0x168 = 0;
    return;
}



// Convolver::Reset()

void Convolver::Reset() {
    if (*(WaveBuffer_R32 **)this != nullptr) {
        WaveBuffer_R32::Reset(*(WaveBuffer_R32 **)this);
    }
    if (*(WaveBuffer_R32 **)&this->field_0x4 != nullptr) {
        WaveBuffer_R32::Reset(*(WaveBuffer_R32 **)&this->field_0x4);
    }
    PConvSingle_F32::Reset((PConvSingle_F32 *)&this->field_0x8);
    PConvSingle_F32::Reset((PConvSingle_F32 *)&this->field_0x18);
    PConvSingle_F32::Reset((PConvSingle_F32 *)&this->field_0x28);
    PConvSingle_F32::Reset((PConvSingle_F32 *)&this->field_0x38);
    return;
}



// Convolver::SetEnable(bool)

undefined4 Convolver::SetEnable(bool param_1) {
    char cVar1;

    cVar1 = *(char *)&this->field_0x170;
    if (cVar1 == '\0') {
        if (param_1 == false) {
            return 0;
        }
        Reset(this);
        cVar1 = *(char *)&this->field_0x170;
    }
    if (param_1 == (bool)cVar1) {
        return 0;
    }
    *(bool *)&this->field_0x170 = param_1;
    return 1;
}



// Convolver::SetKernel(float*, unsigned int)

void Convolver::SetKernel(float *param_1,uint param_2) {
    byte bVar1;
    byte bVar2;
    PConvSingle_F32 *this_00;
    PConvSingle_F32 *this_01;
    PConvSingle_F32 *this_02;
    PConvSingle_F32 *this_03;

    if (param_2 < 0x10) {
        return;
    }
    this_01 = (PConvSingle_F32 *)&this->field_0x8;
    *(undefined4 *)&this->field_0x160 = 0;
    this_00 = (PConvSingle_F32 *)&this->field_0x18;
    this_03 = (PConvSingle_F32 *)&this->field_0x28;
    PConvSingle_F32::Reset(this_01);
    this_02 = (PConvSingle_F32 *)&this->field_0x38;
    PConvSingle_F32::Reset(this_00);
    PConvSingle_F32::Reset(this_03);
    PConvSingle_F32::Reset(this_02);
    PConvSingle_F32::UnloadKernel(this_01);
    PConvSingle_F32::UnloadKernel(this_00);
    PConvSingle_F32::UnloadKernel(this_03);
    PConvSingle_F32::UnloadKernel(this_02);
    bVar1 = PConvSingle_F32::LoadKernel(this_01,param_1,param_2,0x1000);
    bVar2 = PConvSingle_F32::LoadKernel(this_00,param_1,param_2,0x1000);
    if ((bVar2 & bVar1) == 0) {
        PConvSingle_F32::UnloadKernel(this_01);
        PConvSingle_F32::UnloadKernel(this_00);
        PConvSingle_F32::UnloadKernel(this_03);
        PConvSingle_F32::UnloadKernel(this_02);
    }
    *(undefined4 *)&this->field_0x148 = 0;
    *(undefined4 *)&this->field_0x15c = 0;
    Reset(this);
    return;
}



// Convolver::SetKernelStereo(float*, float*, unsigned int)

void Convolver::SetKernelStereo(float *param_1,float *param_2,uint param_3) {
    byte bVar1;
    byte bVar2;
    PConvSingle_F32 *this_00;
    PConvSingle_F32 *this_01;
    PConvSingle_F32 *this_02;
    PConvSingle_F32 *this_03;

    if (param_3 < 0x10) {
        return;
    }
    this_01 = (PConvSingle_F32 *)&this->field_0x8;
    *(undefined4 *)&this->field_0x160 = 0;
    this_00 = (PConvSingle_F32 *)&this->field_0x18;
    this_03 = (PConvSingle_F32 *)&this->field_0x28;
    PConvSingle_F32::Reset(this_01);
    this_02 = (PConvSingle_F32 *)&this->field_0x38;
    PConvSingle_F32::Reset(this_00);
    PConvSingle_F32::Reset(this_03);
    PConvSingle_F32::Reset(this_02);
    PConvSingle_F32::UnloadKernel(this_01);
    PConvSingle_F32::UnloadKernel(this_00);
    PConvSingle_F32::UnloadKernel(this_03);
    PConvSingle_F32::UnloadKernel(this_02);
    bVar1 = PConvSingle_F32::LoadKernel(this_01,param_1,param_3,0x1000);
    bVar2 = PConvSingle_F32::LoadKernel(this_00,param_2,param_3,0x1000);
    if ((bVar2 & bVar1) == 0) {
        PConvSingle_F32::UnloadKernel(this_01);
        PConvSingle_F32::UnloadKernel(this_00);
        PConvSingle_F32::UnloadKernel(this_03);
        PConvSingle_F32::UnloadKernel(this_02);
    }
    *(undefined4 *)&this->field_0x148 = 0;
    *(undefined4 *)&this->field_0x15c = 0;
    Reset(this);
    return;
}



// Convolver::SetKernel(char const*)

void Convolver::SetKernel(char *param_1) {
    byte bVar1;
    byte bVar2;
    byte bVar3;
    byte bVar4;
    int iVar5;
    uint uVar6;
    float *pfVar7;
    float *pfVar8;
    float *pfVar9;
    uint uVar10;
    float *pfVar11;
    float *pfVar12;
    char *__s2;
    PConvSingle_F32 *this_00;
    PConvSingle_F32 *this_01;
    PConvSingle_F32 *this_02;
    PConvSingle_F32 *this_03;
    float *pfVar13;
    float *pfVar14;
    bool bVar15;
    undefined8 uVar16;
    float *local_60;
    float *local_5c;
    float *local_54;
    uint local_48;
    int local_44;
    undefined4 local_40;
    uint local_3c;
    undefined4 local_38;
    undefined4 local_34;
    undefined4 local_30;
    undefined4 local_2c;

    if (param_1 == nullptr) {
        return;
    }
    __s2 = (char *)&this->field_0x48;
    iVar5 = strcmp(param_1,__s2);
    if (iVar5 == 0) {
        return;
    }
    this_00 = (PConvSingle_F32 *)&this->field_0x8;
    this_01 = (PConvSingle_F32 *)&this->field_0x18;
    *(undefined4 *)&this->field_0x160 = 0;
    this_02 = (PConvSingle_F32 *)&this->field_0x28;
    PConvSingle_F32::Reset(this_00);
    this_03 = (PConvSingle_F32 *)&this->field_0x38;
    PConvSingle_F32::Reset(this_01);
    PConvSingle_F32::Reset(this_02);
    PConvSingle_F32::Reset(this_03);
    PConvSingle_F32::UnloadKernel(this_00);
    PConvSingle_F32::UnloadKernel(this_01);
    PConvSingle_F32::UnloadKernel(this_02);
    PConvSingle_F32::UnloadKernel(this_03);
    *(undefined4 *)&this->field_0x15c = 0;
    *(undefined4 *)&this->field_0x148 = 0;
    if (*param_1 == '\0') {
        memset(__s2,0,0x100);
        return;
    }
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    iVar5 = sf_open(param_1,0x10,&local_48);
    if (iVar5 == 0) {
        return;
    }
    bVar15 = 3 < local_3c;
    if (local_3c != 4) {
        bVar15 = local_3c != 1;
    }
    if ((bVar15 && (local_3c != 4 && local_3c != 2)) ||
        ((int)(local_44 - (uint)(0xf >= local_48)) < 0 !=
         (local_44 < 0 && (int)(local_44 + -1 + (uint)(0xf < local_48)) < 0 != local_44 < 0))) {
        LAB_00064430:
        sf_close(iVar5);
        return;
    }
    if (local_48 * local_3c < 0x1fc00001) {
        uVar6 = local_48 * local_3c * 4;
    }
    else {
        uVar6 = 0xffffffff;
    }
    pfVar7 = (float *)operator_new__(uVar6);
    if (pfVar7 == nullptr) goto LAB_00064430;
    uVar16 = sf_readf_float(iVar5,pfVar7,local_48,local_44);
    uVar6 = local_48;
    if (local_44 != (int)((ulonglong)uVar16 >> 0x20) || local_48 != (uint)uVar16) {
        operator_delete__(pfVar7);
        goto LAB_00064430;
    }
    sf_close(iVar5);
    if (local_3c == 1) {
        bVar1 = PConvSingle_F32::LoadKernel(this_00,pfVar7,uVar6,0x1000);
        bVar4 = PConvSingle_F32::LoadKernel(this_01,pfVar7,uVar6,0x1000);
        bVar4 = bVar4 & bVar1;
        LAB_000645d0:
        if (bVar4 != 0) {
            memset(__s2,0,0x100);
            strcpy(__s2,param_1);
            goto LAB_000645f4;
        }
    }
    else {
        if (local_3c == 2) {
            if (uVar6 < 0x1fc00001) {
                uVar10 = uVar6 << 2;
                pfVar8 = (float *)operator_new__(uVar10);
            }
            else {
                pfVar8 = (float *)operator_new__(0xffffffff);
                uVar10 = 0xffffffff;
            }
            local_60 = (float *)operator_new__(uVar10);
            if (pfVar8 != nullptr && local_60 != nullptr) {
                iVar5 = 0;
                if (0 < (int)uVar6) {
                    pfVar9 = pfVar8;
                    pfVar11 = local_60;
                    pfVar12 = pfVar7 + 1;
                    do {
                        iVar5 = iVar5 + 4;
                        *pfVar9 = pfVar12[-1];
                        *pfVar11 = *pfVar12;
                        pfVar9 = pfVar9 + 1;
                        pfVar11 = pfVar11 + 1;
                        pfVar12 = pfVar12 + 2;
                    } while (iVar5 != uVar6 * 4);
                }
                operator_delete__(pfVar7);
                bVar1 = PConvSingle_F32::LoadKernel(this_00,pfVar8,uVar6,0x1000);
                bVar4 = PConvSingle_F32::LoadKernel(this_01,local_60,uVar6,0x1000);
                bVar4 = bVar4 & bVar1;
                operator_delete__(pfVar8);
                operator_delete__(local_60);
                goto LAB_000645d0;
            }
            if (pfVar8 != nullptr) {
                operator_delete__(pfVar8);
            }
            LAB_00064654:
            if (local_60 != nullptr) {
                operator_delete__(local_60);
            }
        }
        else {
            if (uVar6 < 0x1fc00001) {
                uVar10 = uVar6 << 2;
                local_5c = (float *)operator_new__(uVar10);
                local_60 = (float *)operator_new__(uVar10);
                local_54 = (float *)operator_new__(uVar10);
            }
            else {
                local_5c = (float *)operator_new__(0xffffffff);
                local_60 = (float *)operator_new__(0xffffffff);
                local_54 = (float *)operator_new__(0xffffffff);
                uVar10 = 0xffffffff;
            }
            pfVar8 = (float *)operator_new__(uVar10);
            if (local_5c == nullptr || local_60 == nullptr) {
                if (local_5c != nullptr) goto LAB_0006460c;
            }
            else {
                if (local_54 != nullptr && pfVar8 != nullptr) {
                    iVar5 = 0;
                    if (0 < (int)uVar6) {
                        pfVar9 = local_54;
                        pfVar11 = pfVar8;
                        pfVar12 = pfVar7 + 3;
                        pfVar13 = local_5c;
                        pfVar14 = local_60;
                        do {
                            iVar5 = iVar5 + 4;
                            *pfVar13 = pfVar12[-3];
                            *pfVar14 = pfVar12[-2];
                            *pfVar9 = pfVar12[-1];
                            *pfVar11 = *pfVar12;
                            pfVar9 = pfVar9 + 1;
                            pfVar11 = pfVar11 + 1;
                            pfVar12 = pfVar12 + 4;
                            pfVar13 = pfVar13 + 1;
                            pfVar14 = pfVar14 + 1;
                        } while (iVar5 != uVar6 << 2);
                    }
                    operator_delete__(pfVar7);
                    bVar1 = PConvSingle_F32::LoadKernel(this_00,local_5c,uVar6,0x1000);
                    bVar2 = PConvSingle_F32::LoadKernel(this_01,local_60,uVar6,0x1000);
                    bVar3 = PConvSingle_F32::LoadKernel(this_02,local_54,uVar6,0x1000);
                    bVar4 = PConvSingle_F32::LoadKernel(this_03,pfVar8,uVar6,0x1000);
                    bVar4 = bVar2 & bVar1 & bVar3 & bVar4;
                    operator_delete__(local_5c);
                    operator_delete__(local_60);
                    operator_delete__(local_54);
                    operator_delete__(pfVar8);
                    *(undefined4 *)&this->field_0x160 = 1;
                    goto LAB_000645d0;
                }
                LAB_0006460c:
                operator_delete__(local_5c);
            }
            if (local_60 != nullptr) {
                operator_delete__(local_60);
            }
            if ((local_54 != nullptr) && (local_5c != nullptr)) {
                operator_delete__(local_5c);
            }
            if (pfVar8 != nullptr) goto LAB_00064654;
        }
        operator_delete__(pfVar7);
    }
    *(undefined4 *)&this->field_0x160 = 0;
    PConvSingle_F32::UnloadKernel(this_00);
    PConvSingle_F32::UnloadKernel(this_01);
    PConvSingle_F32::UnloadKernel(this_02);
    PConvSingle_F32::UnloadKernel(this_03);
    LAB_000645f4:
    Reset(this);
    return;
}



// Convolver::CommitKernelBuffer(unsigned int, unsigned int, unsigned int)

void Convolver::CommitKernelBuffer(uint param_1,uint param_2,uint param_3) {
    bool bVar1;
    byte bVar2;
    byte bVar3;
    byte bVar4;
    byte bVar5;
    float *pfVar6;
    float *pfVar7;
    float *pfVar8;
    uint uVar9;
    float *pfVar10;
    float *pfVar11;
    float *pfVar12;
    uint uVar13;
    float *pfVar14;
    void *pvVar15;
    PConvSingle_F32 *this_00;
    PConvSingle_F32 *this_01;
    undefined4 unaff_r8;
    PConvSingle_F32 *this_02;
    PConvSingle_F32 *this_03;
    int iVar16;
    float *pfVar17;
    bool bVar18;
    bool bVar19;
    float *local_34;
    float *local_2c;

    pvVar15 = *(void **)&this->field_0x14c;
    if (pvVar15 == nullptr) {
        *(undefined4 *)&this->field_0x150 = 0;
        *(undefined4 *)&this->field_0x154 = 0;
        *(undefined4 *)&this->field_0x158 = 0;
        return;
    }
    if (*(uint *)&this->field_0x150 != param_1) {
        LAB_00064830:
        operator_delete__(pvVar15);
        *(undefined4 *)&this->field_0x14c = 0;
        *(undefined4 *)&this->field_0x150 = 0;
        *(undefined4 *)&this->field_0x154 = 0;
        *(undefined4 *)&this->field_0x158 = 0;
        return;
    }
    if (*(int *)&this->field_0x154 == 0) {
        operator_delete__(pvVar15);
        *(undefined4 *)&this->field_0x14c = 0;
        *(undefined4 *)&this->field_0x150 = 0;
        *(undefined4 *)&this->field_0x154 = 0;
        *(undefined4 *)&this->field_0x158 = 0;
        return;
    }
    uVar13 = *(uint *)&this->field_0x158;
    bVar19 = 3 < uVar13;
    bVar18 = uVar13 == 4;
    if (!bVar18) {
        bVar19 = uVar13 != 1;
    }
    bVar1 = uVar13 != 2;
    if (!bVar19 || (bVar18 || !bVar1)) {
        unaff_r8 = 0;
    }
    if (bVar19 && (!bVar18 && bVar1)) {
        unaff_r8 = 1;
    }
    if (bVar19 && (!bVar18 && bVar1)) goto LAB_00064830;
    uVar13 = FUN_00063c3c(pvVar15,*(int *)&this->field_0x154 << 2);
    if ((uVar13 != param_2) || (*(uint *)&this->field_0x15c == uVar13)) {
        operator_delete__(pvVar15);
        *(undefined4 *)&this->field_0x14c = unaff_r8;
        *(undefined4 *)&this->field_0x150 = unaff_r8;
        *(undefined4 *)&this->field_0x154 = unaff_r8;
        *(undefined4 *)&this->field_0x158 = unaff_r8;
        return;
    }
    this_00 = (PConvSingle_F32 *)&this->field_0x8;
    *(uint *)&this->field_0x15c = uVar13;
    *(undefined4 *)&this->field_0x160 = unaff_r8;
    this_01 = (PConvSingle_F32 *)&this->field_0x18;
    this_02 = (PConvSingle_F32 *)&this->field_0x28;
    PConvSingle_F32::Reset(this_00);
    this_03 = (PConvSingle_F32 *)&this->field_0x38;
    PConvSingle_F32::Reset(this_01);
    PConvSingle_F32::Reset(this_02);
    PConvSingle_F32::Reset(this_03);
    PConvSingle_F32::UnloadKernel(this_00);
    PConvSingle_F32::UnloadKernel(this_01);
    PConvSingle_F32::UnloadKernel(this_02);
    PConvSingle_F32::UnloadKernel(this_03);
    iVar16 = *(int *)&this->field_0x158;
    uVar13 = __divsi3(*(undefined4 *)&this->field_0x154,iVar16);
    if (iVar16 == 1) {
        bVar2 = PConvSingle_F32::LoadKernel(this_00,*(float **)&this->field_0x14c,uVar13,0x1000);
        bVar5 = PConvSingle_F32::LoadKernel(this_01,*(float **)&this->field_0x14c,uVar13,0x1000);
        bVar5 = bVar5 & bVar2;
        LAB_00064a9c:
        if (bVar5 != 0) {
            memset((void *)&this->field_0x48,0,0x100);
            *(uint *)&this->field_0x148 = param_3;
            goto LAB_00064ab8;
        }
    }
    else {
        if (iVar16 == 2) {
            if (uVar13 < 0x1fc00001) {
                uVar9 = uVar13 << 2;
                pfVar7 = (float *)operator_new__(uVar9);
            }
            else {
                pfVar7 = (float *)operator_new__(0xffffffff);
                uVar9 = 0xffffffff;
            }
            pfVar6 = (float *)operator_new__(uVar9);
            if (pfVar7 != nullptr && pfVar6 != nullptr) {
                if (0 < (int)uVar13) {
                    pfVar8 = pfVar6;
                    pfVar10 = pfVar7;
                    pfVar11 = (float *)(*(int *)&this->field_0x14c + 4);
                    do {
                        pfVar14 = pfVar10 + 1;
                        *pfVar10 = pfVar11[-1];
                        *pfVar8 = *pfVar11;
                        pfVar8 = pfVar8 + 1;
                        pfVar10 = pfVar14;
                        pfVar11 = pfVar11 + 2;
                    } while (pfVar14 != pfVar7 + uVar13);
                }
                bVar2 = PConvSingle_F32::LoadKernel(this_00,pfVar7,uVar13,0x1000);
                bVar5 = PConvSingle_F32::LoadKernel(this_01,pfVar6,uVar13,0x1000);
                bVar5 = bVar5 & bVar2;
                operator_delete__(pfVar7);
                operator_delete__(pfVar6);
                goto LAB_00064a9c;
            }
            if (pfVar7 != nullptr) {
                operator_delete__(pfVar7);
            }
        }
        else {
            if (uVar13 < 0x1fc00001) {
                uVar9 = uVar13 << 2;
                local_34 = (float *)operator_new__(uVar9);
                pfVar6 = (float *)operator_new__(uVar9);
                local_2c = (float *)operator_new__(uVar9);
            }
            else {
                local_34 = (float *)operator_new__(0xffffffff);
                pfVar6 = (float *)operator_new__(0xffffffff);
                local_2c = (float *)operator_new__(0xffffffff);
                uVar9 = 0xffffffff;
            }
            pfVar7 = (float *)operator_new__(uVar9);
            if (local_34 == nullptr || pfVar6 == nullptr) {
                if (local_34 != nullptr) goto LAB_00064af8;
            }
            else {
                if (local_2c != nullptr && pfVar7 != nullptr) {
                    if (0 < (int)uVar13) {
                        pfVar8 = local_2c;
                        pfVar10 = pfVar7;
                        pfVar11 = local_34;
                        pfVar14 = (float *)(*(int *)&this->field_0x14c + 0xc);
                        pfVar17 = pfVar6;
                        do {
                            pfVar12 = pfVar11 + 1;
                            *pfVar11 = pfVar14[-3];
                            *pfVar17 = pfVar14[-2];
                            *pfVar8 = pfVar14[-1];
                            *pfVar10 = *pfVar14;
                            pfVar8 = pfVar8 + 1;
                            pfVar10 = pfVar10 + 1;
                            pfVar11 = pfVar12;
                            pfVar14 = pfVar14 + 4;
                            pfVar17 = pfVar17 + 1;
                        } while (pfVar12 != local_34 + uVar13);
                    }
                    bVar2 = PConvSingle_F32::LoadKernel(this_00,local_34,uVar13,0x1000);
                    bVar3 = PConvSingle_F32::LoadKernel(this_01,pfVar6,uVar13,0x1000);
                    bVar4 = PConvSingle_F32::LoadKernel(this_02,local_2c,uVar13,0x1000);
                    bVar5 = PConvSingle_F32::LoadKernel(this_03,pfVar7,uVar13,0x1000);
                    bVar5 = bVar3 & bVar2 & bVar4 & bVar5;
                    operator_delete__(local_34);
                    operator_delete__(pfVar6);
                    operator_delete__(local_2c);
                    operator_delete__(pfVar7);
                    *(undefined4 *)&this->field_0x160 = 1;
                    goto LAB_00064a9c;
                }
                LAB_00064af8:
                operator_delete__(local_34);
            }
            if (pfVar6 != nullptr) {
                operator_delete__(pfVar6);
            }
            if ((local_2c != nullptr) && (local_34 != nullptr)) {
                operator_delete__(local_34);
            }
            if (pfVar7 == nullptr) goto LAB_00064b4c;
        }
        if (pfVar6 != nullptr) {
            operator_delete__(pfVar6);
        }
    }
    LAB_00064b4c:
    *(undefined4 *)&this->field_0x160 = 0;
    PConvSingle_F32::UnloadKernel(this_00);
    PConvSingle_F32::UnloadKernel(this_01);
    PConvSingle_F32::UnloadKernel(this_02);
    PConvSingle_F32::UnloadKernel(this_03);
    *(undefined4 *)&this->field_0x15c = 0;
    *(undefined4 *)&this->field_0x148 = 0;
    LAB_00064ab8:
    if (*(void **)&this->field_0x14c != nullptr) {
        operator_delete__(*(void **)&this->field_0x14c);
    }
    *(undefined4 *)&this->field_0x14c = 0;
    *(undefined4 *)&this->field_0x150 = 0;
    *(undefined4 *)&this->field_0x154 = 0;
    *(undefined4 *)&this->field_0x158 = 0;
    Reset(this);
    return;
}



// WARNING: Type propagation algorithm not settling
// Convolver::Process(float*, float*, int)

int Convolver::Process(float *param_1,float *param_2,int param_3) {
    undefined auVar1 [16];
    undefined4 uVar2;
    int iVar3;
    uint uVar4;
    float fVar5;
    float *pfVar6;
    undefined8 *puVar7;
    undefined8 *puVar8;
    float *pfVar9;
    undefined8 *puVar10;
    float *pfVar11;
    float *pfVar12;
    undefined8 *puVar13;
    undefined8 *puVar14;
    undefined8 *puVar15;
    float *pfVar16;
    float *pfVar17;
    PConvSingle_F32 *this_00;
    float fVar18;
    undefined8 *puVar19;
    undefined8 *puVar20;
    undefined auVar21 [16];
    undefined auVar22 [16];
    undefined auVar23 [16];
    undefined auVar24 [16];
    undefined auVar25 [16];
    undefined auVar26 [16];
    undefined auVar27 [16];
    undefined auVar28 [16];
    undefined auVar29 [16];
    undefined auVar30 [16];
    undefined auVar31 [16];
    undefined auVar32 [16];
    undefined auVar33 [16];
    undefined auVar34 [16];
    undefined auVar35 [16];
    undefined auVar36 [16];
    float afStack98496 [8192];
    float afStack65728 [16423];

    if (*(char *)&this->field_0x170 == '\0') {
        return param_3;
    }
    if (*(int *)this == 0) {
        return param_3;
    }
    if (*(int *)&this->field_0x4 == 0) {
        return param_3;
    }
    this_00 = (PConvSingle_F32 *)&this->field_0x8;
    if (*(int *)&this->field_0x160 == 0) {
        iVar3 = PConvSingle_F32::InstanceUsable(this_00);
        if (iVar3 == 0) {
            return param_3;
        }
        iVar3 = PConvSingle_F32::InstanceUsable((PConvSingle_F32 *)&this->field_0x18);
    }
    else {
        iVar3 = PConvSingle_F32::InstanceUsable(this_00);
        if (iVar3 == 0) {
            return param_3;
        }
        iVar3 = PConvSingle_F32::InstanceUsable((PConvSingle_F32 *)&this->field_0x18);
        if (iVar3 == 0) {
            return param_3;
        }
        iVar3 = PConvSingle_F32::InstanceUsable((PConvSingle_F32 *)&this->field_0x28);
        if (iVar3 == 0) {
            return param_3;
        }
        iVar3 = PConvSingle_F32::InstanceUsable((PConvSingle_F32 *)&this->field_0x38);
    }
    if ((iVar3 != 0) &&
        (iVar3 = WaveBuffer_R32::PushSamples(*(WaveBuffer_R32 **)this,param_1,param_3), iVar3 != 0)) {
        if (*(int *)&this->field_0x160 == 0) {
            while (uVar4 = WaveBuffer_R32::GetBufferOffset(), 0xfff < uVar4) {
                pfVar6 = (float *)WaveBuffer_R32::GetCurrentBufferR32Ptr(*(WaveBuffer_R32 **)this);
                PConvSingle_F32::ConvolveInterleaved(this_00,pfVar6,0);
                PConvSingle_F32::ConvolveInterleaved((PConvSingle_F32 *)&this->field_0x18,pfVar6,1);
                if (*(char *)&this->field_0x168 != '\0') {
                    iVar3 = 0;
                    auVar1 = ZEXT816(CONCAT44(*(undefined4 *)&this->field_0x164,
                                              *(undefined4 *)&this->field_0x164));
                    auVar1 = auVar1 & auVar1 << 0x40;
                    do {
                        puVar14 = (undefined8 *)((int)pfVar6 + iVar3 + 0x10);
                        puVar15 = (undefined8 *)(iVar3 + (int)pfVar6);
                        auVar35 = CONCAT88(CONCAT44(*(undefined4 *)((int)puVar14 + 4),
                                                    *(undefined4 *)((int)puVar14 + 4)),
                                           CONCAT44(*(undefined4 *)puVar14,*(undefined4 *)puVar14));
                        puVar20 = (undefined8 *)((int)pfVar6 + iVar3 + 0x20);
                        puVar19 = (undefined8 *)((int)(pfVar6 + 0xc) + iVar3);
                        puVar7 = (undefined8 *)((int)(pfVar6 + 0x10) + iVar3);
                        auVar22 = FloatVectorMult(auVar35,auVar1,2,0x20);
                        puVar10 = (undefined8 *)((int)(pfVar6 + 0x18) + iVar3);
                        auVar36 = CONCAT88(CONCAT44(*(undefined4 *)((int)puVar15 + 4),
                                                    *(undefined4 *)((int)puVar15 + 4)),
                                           CONCAT44(*(undefined4 *)puVar15,*(undefined4 *)puVar15));
                        puVar8 = (undefined8 *)((int)(pfVar6 + 0x14) + iVar3);
                        auVar27 = FloatVectorMult(auVar36,auVar1,2,0x20);
                        puVar13 = (undefined8 *)((int)(pfVar6 + 0x1c) + iVar3);
                        auVar34 = CONCAT88(CONCAT44(*(undefined4 *)((int)puVar20 + 4),
                                                    *(undefined4 *)((int)puVar20 + 4)),
                                           CONCAT44(*(undefined4 *)puVar20,*(undefined4 *)puVar20));
                        iVar3 = iVar3 + 0x80;
                        auVar33 = CONCAT88(CONCAT44(*(undefined4 *)((int)puVar19 + 4),
                                                    *(undefined4 *)((int)puVar19 + 4)),
                                           CONCAT44(*(undefined4 *)puVar19,*(undefined4 *)puVar19));
                        auVar25 = FloatVectorMult(auVar34,auVar1,2,0x20);
                        auVar32 = CONCAT88(CONCAT44(*(undefined4 *)((int)puVar7 + 4),
                                                    *(undefined4 *)((int)puVar7 + 4)),
                                           CONCAT44(*(undefined4 *)puVar7,*(undefined4 *)puVar7));
                        auVar31 = CONCAT88(CONCAT44(*(undefined4 *)((int)puVar8 + 4),
                                                    *(undefined4 *)((int)puVar8 + 4)),
                                           CONCAT44(*(undefined4 *)puVar8,*(undefined4 *)puVar8));
                        auVar24 = FloatVectorMult(auVar33,auVar1,2,0x20);
                        auVar30 = CONCAT88(CONCAT44(*(undefined4 *)((int)puVar10 + 4),
                                                    *(undefined4 *)((int)puVar10 + 4)),
                                           CONCAT44(*(undefined4 *)puVar10,*(undefined4 *)puVar10));
                        auVar29 = CONCAT88(CONCAT44(*(undefined4 *)((int)puVar13 + 4),
                                                    *(undefined4 *)((int)puVar13 + 4)),
                                           CONCAT44(*(undefined4 *)puVar13,*(undefined4 *)puVar13));
                        auVar23 = FloatVectorMult(auVar32,auVar1,2,0x20);
                        auVar21 = vrev(auVar22,4);
                        auVar28 = vrev(auVar27,4);
                        auVar22 = FloatVectorMult(auVar31,auVar1,2,0x20);
                        auVar27 = FloatVectorMult(auVar30,auVar1,2,0x20);
                        auVar26 = vrev(auVar25,4);
                        auVar25 = vrev(auVar24,4);
                        auVar24 = FloatVectorMult(auVar29,auVar1,2,0x20);
                        auVar23 = vrev(auVar23,4);
                        auVar22 = vrev(auVar22,4);
                        auVar27 = vrev(auVar27,4);
                        auVar36 = FloatVectorAdd(auVar36,auVar28,2,0x20);
                        auVar28 = FloatVectorAdd(auVar34,auVar26,2,0x20);
                        auVar24 = vrev(auVar24,4);
                        auVar21 = FloatVectorAdd(auVar35,auVar21,2,0x20);
                        auVar26 = FloatVectorAdd(auVar33,auVar25,2,0x20);
                        *puVar15 = CONCAT44(SUB164(auVar36,0),SUB164(auVar36,0));
                        uVar2 = SUB164(auVar36 >> 0x40,0);
                        *(ulonglong *)((int)puVar15 + 4) = CONCAT44(uVar2,uVar2);
                        auVar25 = FloatVectorAdd(auVar32,auVar23,2,0x20);
                        auVar23 = FloatVectorAdd(auVar31,auVar22,2,0x20);
                        *puVar14 = CONCAT44(SUB164(auVar21,0),SUB164(auVar21,0));
                        uVar2 = SUB164(auVar21 >> 0x40,0);
                        *(ulonglong *)((int)puVar14 + 4) = CONCAT44(uVar2,uVar2);
                        auVar21 = FloatVectorAdd(auVar30,auVar27,2,0x20);
                        auVar22 = FloatVectorAdd(auVar29,auVar24,2,0x20);
                        *puVar20 = CONCAT44(SUB164(auVar28,0),SUB164(auVar28,0));
                        uVar2 = SUB164(auVar28 >> 0x40,0);
                        *(ulonglong *)((int)puVar20 + 4) = CONCAT44(uVar2,uVar2);
                        *puVar19 = CONCAT44(SUB164(auVar26,0),SUB164(auVar26,0));
                        uVar2 = SUB164(auVar26 >> 0x40,0);
                        *(ulonglong *)((int)puVar19 + 4) = CONCAT44(uVar2,uVar2);
                        *puVar7 = CONCAT44(SUB164(auVar25,0),SUB164(auVar25,0));
                        uVar2 = SUB164(auVar25 >> 0x40,0);
                        *(ulonglong *)((int)puVar7 + 4) = CONCAT44(uVar2,uVar2);
                        *puVar8 = CONCAT44(SUB164(auVar23,0),SUB164(auVar23,0));
                        uVar2 = SUB164(auVar23 >> 0x40,0);
                        *(ulonglong *)((int)puVar8 + 4) = CONCAT44(uVar2,uVar2);
                        *puVar10 = CONCAT44(SUB164(auVar21,0),SUB164(auVar21,0));
                        uVar2 = SUB164(auVar21 >> 0x40,0);
                        *(ulonglong *)((int)puVar10 + 4) = CONCAT44(uVar2,uVar2);
                        *puVar13 = CONCAT44(SUB164(auVar22,0),SUB164(auVar22,0));
                        uVar2 = SUB164(auVar22 >> 0x40,0);
                        *(ulonglong *)((int)puVar13 + 4) = CONCAT44(uVar2,uVar2);
                    } while (iVar3 != 0x8000);
                }
                WaveBuffer_R32::PushSamples(*(WaveBuffer_R32 **)&this->field_0x4,pfVar6,0x1000);
                WaveBuffer_R32::PopSamples(*(WaveBuffer_R32 **)this,0x1000,true);
            }
        }
        else {
            while (uVar4 = WaveBuffer_R32::GetBufferOffset(), 0xfff < uVar4) {
                WaveBuffer_R32::PopSamples(*(WaveBuffer_R32 **)this,afStack65728 + 0x2000,0x1000,false);
                pfVar16 = afStack65728 + 1;
                pfVar17 = afStack98496 + 1;
                pfVar6 = pfVar17;
                pfVar9 = afStack65728 + 0x2001;
                pfVar11 = pfVar16;
                do {
                    fVar18 = pfVar9[-1];
                    fVar5 = *pfVar9;
                    pfVar11[-1] = fVar18;
                    pfVar12 = pfVar11 + 2;
                    *pfVar11 = fVar18;
                    pfVar6[-1] = fVar5;
                    *pfVar6 = fVar5;
                    pfVar6 = pfVar6 + 2;
                    pfVar9 = pfVar9 + 2;
                    pfVar11 = pfVar12;
                } while (pfVar12 != afStack65728 + 0x2001);
                PConvSingle_F32::ConvolveInterleaved(this_00,afStack65728,0);
                PConvSingle_F32::ConvolveInterleaved((PConvSingle_F32 *)&this->field_0x18,afStack65728,1);
                PConvSingle_F32::ConvolveInterleaved((PConvSingle_F32 *)&this->field_0x28,afStack98496,0);
                PConvSingle_F32::ConvolveInterleaved((PConvSingle_F32 *)&this->field_0x38,afStack98496,1);
                pfVar6 = afStack65728 + 0x2001;
                do {
                    pfVar9 = pfVar16 + -1;
                    fVar5 = *pfVar16;
                    fVar18 = *pfVar17;
                    pfVar16 = pfVar16 + 2;
                    pfVar11 = pfVar17 + -1;
                    pfVar17 = pfVar17 + 2;
                    pfVar6[-1] = *pfVar9 + *pfVar11;
                    *pfVar6 = fVar5 + fVar18;
                    pfVar6 = pfVar6 + 2;
                } while (pfVar16 != afStack65728 + 0x2001);
                WaveBuffer_R32::PushSamples
                        (*(WaveBuffer_R32 **)&this->field_0x4,afStack65728 + 0x2000,0x1000);
            }
        }
        param_3 = WaveBuffer_R32::PopSamples(*(WaveBuffer_R32 **)&this->field_0x4,param_2,param_3,false)
                ;
    }
    return param_3;
}
