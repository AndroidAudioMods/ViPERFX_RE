//
// Created by mart on 2/12/21.
//

#include "FIREqualizer.h"

// FIREqualizer::~FIREqualizer()

FIREqualizer::~FIREqualizer() {
    if ((void *)this->field_0x0 != nullptr) {
        operator_delete((void *)this->field_0x0);
    }
    this->field_0x0 = 0;
    return this;
}



// FIREqualizer::SetBandLevel(unsigned int, float)

void FIREqualizer::SetBandLevel(uint param_1,float param_2) {
    float in_r2;
    float fVar1;

    if (this->field_0x0 == 0) {
        return;
    }
    if (9 < param_1) {
        return;
    }
    if (9 < (int)param_1) {
        in_r2 = in_r2 + in_r2;
    }
    fVar1 = ROUND((in_r2 + 1.0) * 3.355443e+07 + 0.5);
    *(uint *)(this->field_0x0 + (9 - param_1) * 4) = (uint)fVar1 & ~((int)fVar1 >> 0x1f);
    return;
}



// FIREqualizer::Reset()

void FIREqualizer::Reset() {
    if (this->field_0x0 == 0) {
        return;
    }
    memset((void *)(this->field_0x0 + 0x28),0,0x400);
    memset((void *)(this->field_0x0 + 0x428),0,0x400);
    memset((void *)(this->field_0x0 + 0x828),0,0x400);
    memset((void *)(this->field_0x0 + 0xc28),0,0x400);
    memset((void *)(this->field_0x0 + 0x1028),0,0x48);
    memset((void *)(this->field_0x0 + 0x1070),0,0x48);
    *(undefined4 *)(this->field_0x0 + 0x10b8) = 0;
    return;
}



// FIREqualizer::SetEnable(bool)

undefined4 FIREqualizer::SetEnable(bool param_1) {
    bool cVar1;

    cVar1 = this->enabled;
    if (cVar1 == false) {
        if (param_1 == false) {
            return 0;
        }
        Reset(this);
        cVar1 = this->enabled;
    }
    if (param_1 == cVar1) {
        return 0;
    }
    this->enabled = param_1;
    return 1;
}



// FIREqualizer::SetSamplingRate(unsigned int)

void FIREqualizer::SetSamplingRate(uint param_1) {
    if (this->samplerate == param_1) {
        return;
    }
    this->samplerate = param_1;
    Reset(this);
    return;
}



// FIREqualizer::FIREqualizer()

FIREqualizer::FIREqualizer() {
    void *__s;
    uint uVar1;
    uint uVar2;
    float extraout_s0;
    float fVar3;

    __s = operator_new(0x10c0);
    memset(__s,0,0x10c0);
    this->field_0x0 = (int)__s;
    uVar1 = 0;
    fVar3 = extraout_s0;
    do {
        uVar2 = uVar1 + 1;
        fVar3 = (float)SetBandLevel(this,uVar1,fVar3);
        uVar1 = uVar2;
    } while (uVar2 != 10);
    Reset(this);
    this->samplerate = 0;
    SetSamplingRate(this,0xac44);
    this->enabled = false;
    return this;
}



// FIREqualizer::Process(int*, int)

void FIREqualizer::Process(int *param_1,int param_2) {
    int *piVar1;
    uint *puVar2;
    int *piVar3;
    longlong lVar4;
    longlong lVar5;
    int *piVar6;
    uint uVar7;
    int iVar8;
    uint uVar9;
    uint uVar10;
    uint uVar11;
    int iVar12;
    uint uVar13;
    int iVar14;
    uint *puVar15;
    int *piVar16;
    uint uVar17;
    int *local_90;
    int *local_8c;
    uint local_84;
    uint local_68 [8];
    int local_48;
    uint local_44 [9];

    piVar16 = (int *)this->field_0x0;
    if (((piVar16 != nullptr) && (this->enabled != false)) && (param_2 << 1 != 0)) {
        uVar9 = piVar16[0x42e];
        local_84 = 0;
        local_90 = param_1;
        local_8c = param_1 + 1;
        do {
            piVar6 = piVar16 + uVar9;
            iVar8 = 0;
            iVar12 = piVar6[0x20a];
            iVar14 = piVar6[0x30a];
            piVar6[0x20a] = local_8c[-1];
            piVar6[0x30a] = local_90[1];
            piVar6 = piVar16;
            do {
                piVar1 = (int *)((int)&DAT_000ce550 + iVar8);
                uVar10 = piVar6[0x40a];
                iVar8 = iVar8 + 4;
                uVar13 = (piVar16 + (uVar9 + *piVar1 & 0xff))[0x20a];
                uVar11 = (piVar16 + (uVar9 + *piVar1 & 0xff))[0x30a];
                piVar6[0x40a] = uVar10 + uVar13;
                piVar6[0x40b] = piVar6[0x40b] + ((int)uVar13 >> 0x1f) + (uint)CARRY4(uVar10,uVar13);
                uVar10 = piVar6[0x41c];
                piVar6[0x41c] = uVar10 + uVar11;
                piVar6[0x41d] = piVar6[0x41d] + ((int)uVar11 >> 0x1f) + (uint)CARRY4(uVar10,uVar11);
                piVar6 = piVar6 + 2;
            } while (iVar8 != 0x24);
            iVar8 = 0;
            piVar6 = piVar16;
            uVar10 = 0;
            do {
                puVar15 = (uint *)(piVar6 + 0x40a);
                piVar1 = piVar6 + 0x40b;
                uVar17 = uVar10 + 1;
                puVar2 = (uint *)(piVar6 + 0x41c);
                piVar3 = piVar6 + 0x41d;
                piVar6 = piVar6 + 2;
                uVar11 = *puVar15 >> (uVar17 & 0xff) | *piVar1 << (0x20 - uVar17 & 0xff);
                uVar13 = *puVar2 >> (uVar17 & 0xff) | *piVar3 << (0x20 - uVar17 & 0xff);
                if (-1 < (int)(uVar10 - 0x1f)) {
                    uVar11 = uVar11 | *piVar1 >> (uVar10 - 0x1f & 0xff);
                }
                if (-1 < (int)(uVar10 - 0x1f)) {
                    uVar13 = uVar13 | *piVar3 >> (uVar10 - 0x1f & 0xff);
                }
                *(uint *)((int)local_68 + iVar8) = uVar11;
                *(uint *)((int)local_44 + iVar8) = uVar13;
                iVar8 = iVar8 + 4;
                uVar10 = uVar17;
            } while (uVar17 != 9);
            puVar15 = local_68;
            iVar8 = 0;
            lVar4 = (longlong)(int)(iVar12 - local_68[0]) * (longlong)*piVar16 + 0x1000000;
            uVar13 = (uint)lVar4 >> 0x19 | (int)((ulonglong)lVar4 >> 0x20) << 7;
            lVar4 = (longlong)*piVar16 * (longlong)(int)(iVar14 - local_44[0]) + 0x1000000;
            uVar17 = (uint)lVar4 >> 0x19 | (int)((ulonglong)lVar4 >> 0x20) << 7;
            uVar10 = local_44[0];
            uVar11 = local_68[0];
            piVar6 = piVar16;
            do {
                iVar8 = iVar8 + 4;
                puVar15 = puVar15 + 1;
                uVar7 = *(uint *)((int)local_44 + iVar8);
                piVar6 = piVar6 + 1;
                lVar4 = (longlong)*piVar6 * (longlong)(int)(uVar10 - uVar7) + 0x1000000;
                lVar5 = (longlong)(int)(uVar11 - *puVar15) * (longlong)*piVar6 + 0x1000000;
                uVar17 = uVar17 + ((uint)lVar4 >> 0x19 | (int)((ulonglong)lVar4 >> 0x20) << 7);
                uVar13 = uVar13 + ((uint)lVar5 >> 0x19 | (int)((ulonglong)lVar5 >> 0x20) << 7);
                uVar10 = uVar7;
                uVar11 = *puVar15;
            } while (iVar8 != 0x20);
            iVar8 = 0;
            lVar4 = (longlong)local_48 * (longlong)piVar16[9] + 0x1000000;
            lVar5 = (longlong)piVar16[9] * (longlong)(int)local_44[8] + 0x1000000;
            piVar6 = piVar16;
            do {
                piVar1 = (int *)((int)&DAT_000ce574 + iVar8);
                iVar8 = iVar8 + 4;
                uVar7 = (piVar16 + (uVar9 + *piVar1 & 0xff))[10];
                uVar10 = (piVar16 + (uVar9 + *piVar1 & 0xff))[0x10a];
                uVar11 = piVar6[0x40a];
                piVar6[0x40a] = uVar11 - uVar7;
                piVar6[0x40b] = piVar6[0x40b] - (((int)uVar7 >> 0x1f) + (uint)(uVar11 < uVar7));
                uVar11 = piVar6[0x41c];
                piVar6[0x41c] = uVar11 - uVar10;
                piVar6[0x41d] = piVar6[0x41d] - (((int)uVar10 >> 0x1f) + (uint)(uVar11 < uVar10));
                piVar6 = piVar6 + 2;
            } while (iVar8 != 0x24);
            local_8c[-1] = uVar13 + ((uint)lVar4 >> 0x19 | (int)((ulonglong)lVar4 >> 0x20) << 7);
            local_90[1] = uVar17 + ((uint)lVar5 >> 0x19 | (int)((ulonglong)lVar5 >> 0x20) << 7);
            local_84 = local_84 + 2;
            iVar8 = piVar16[0x42e];
            uVar9 = iVar8 + 1U & 0xff;
            (piVar16 + iVar8)[10] = iVar12;
            (piVar16 + iVar8)[0x10a] = iVar14;
            piVar16[0x42e] = uVar9;
            local_90 = local_90 + 2;
            local_8c = local_8c + 2;
        } while (local_84 < (uint)(param_2 << 1));
    }
    return;
}
