//
// Created by mart on 2/12/21.
//

#include "FIR.h"

// FIR::FIR()

FIR::FIR() {
    this->field_0x0 = nullptr;
    this->field_0x20 = nullptr;
    this->field_0x40 = nullptr;
    this->field_0x44 = 0;
    this->blockLength = 0;
    this->field_0x4c = '\0';
    return;
}



// FIR::~FIR()

FIR::~FIR() {
    if (this->field_0x0 != nullptr) {
        free(this->field_0x0);
    }
    if (this->field_0x20 != nullptr) {
        free(this->field_0x20);
    }
    if (this->field_0x40 != nullptr) {
        free(this->field_0x40);
    }
    return this;
}



// FIR::GetBlockLength()

int FIR::GetBlockLength() {
    return this->blockLength;
}



// FIR::Reset()

void FIR::Reset() {
    undefined4 *puVar1;
    int iVar2;

    if ((this->field_0x0 != nullptr) && (-1 < this->field_0x44 + this->blockLength)) {
        iVar2 = 0;
        puVar1 = (undefined4 *)((int)this->field_0x0 + -4);
        do {
            puVar1 = puVar1 + 1;
            *puVar1 = 0;
            iVar2 = iVar2 + 1;
        } while (iVar2 <= this->field_0x44 + this->blockLength);
    }
    return;
}



// FIR::LoadCoefficients(int const*, int, int)

undefined4 FIR::LoadCoefficients(int *param_1,int param_2,int param_3) {
    void *pvVar1;
    void *pvVar2;
    int iVar3;
    int iVar4;
    bool bVar5;
    bool bVar6;

    bVar5 = param_3 < 0;
    bVar6 = param_3 == 0;
    if (0 < param_3) {
        bVar5 = param_2 < 0;
        bVar6 = param_2 == 0;
    }
    iVar3 = param_3;
    if (!bVar6 && !bVar5) {
        iVar3 = 0;
    }
    if ((!bVar6 && !bVar5) && (param_1 != nullptr)) {
        this->field_0x4c = (char)iVar3;
        if (this->field_0x0 != nullptr) {
            free(this->field_0x0);
        }
        if (this->field_0x20 != nullptr) {
            free(this->field_0x20);
        }
        if (this->field_0x40 != nullptr) {
            free(this->field_0x40);
        }
        this->field_0x0 = nullptr;
        this->field_0x20 = nullptr;
        this->field_0x40 = nullptr;
        pvVar1 = valloc((param_2 + param_3 + 1) * 4);
        this->field_0x0 = pvVar1;
        pvVar1 = valloc(param_2 << 2);
        this->field_0x20 = pvVar1;
        pvVar1 = valloc(param_3 << 2);
        this->field_0x40 = pvVar1;
        if (((this->field_0x0 != nullptr) && (pvVar2 = this->field_0x20, pvVar2 != nullptr)) &&
            (pvVar1 != nullptr)) {
            iVar3 = 0;
            iVar4 = 0;
            this->field_0x44 = param_2;
            this->blockLength = param_3;
            do {
                iVar4 = iVar4 + 1;
                *(undefined4 *)((int)pvVar2 + iVar3) = *(undefined4 *)((int)param_1 + iVar3);
                iVar3 = iVar3 + 4;
            } while (iVar4 < param_2);
            Reset(this);
            if (((this->field_0x0 != nullptr) && (this->field_0x20 != nullptr)) && (this->field_0x40 != nullptr)) {
                this->field_0x4c = '\x01';
                return 1;
            }
        }
    }
    return 0;
}



// FIR::FilterSamplesInterleaved(int*, int, int)

void FIR::FilterSamplesInterleaved(int *param_1,int param_2,int param_3) {
    undefined4 *puVar1;
    longlong lVar2;
    int iVar3;
    int iVar4;
    int *piVar5;
    int iVar6;
    undefined4 *puVar7;
    undefined4 *puVar8;
    int *piVar9;
    int *piVar10;
    void *pvVar12;
    undefined4 *puVar13;
    void *pvVar14;
    int *piVar15;
    int *piVar16;
    int iVar17;
    int iVar18;
    int iVar19;
    int *piVar11;

    if (this->field_0x4c != '\0') {
        iVar3 = this->field_0x44;
        iVar6 = this->blockLength;
        iVar4 = iVar6;
        if (0 < param_2) {
            puVar7 = (undefined4 *)this->field_0x40;
            iVar4 = 0;
            puVar13 = puVar7;
            do {
                puVar1 = (undefined4 *)((int)param_1 + iVar4);
                iVar4 = iVar4 + param_3 * 4;
                puVar8 = puVar13 + 1;
                *puVar13 = *puVar1;
                puVar13 = puVar8;
            } while (puVar8 != puVar7 + param_2);
            iVar4 = this->blockLength;
        }
        if (param_2 < iVar4) {
            puVar13 = (undefined4 *)((int)this->field_0x40 + (param_2 + 0x3fffffff) * 4);
            iVar4 = param_2;
            do {
                puVar13 = puVar13 + 1;
                *puVar13 = 0;
                iVar4 = iVar4 + 1;
            } while (iVar4 < this->blockLength);
        }
        if (0 < iVar6) {
            piVar9 = (int *)this->field_0x40;
            piVar16 = (int *)this->field_0x0;
            piVar15 = piVar16 + iVar3 + 0x3fffffff;
            piVar10 = piVar9;
            do {
                piVar11 = piVar10 + 1;
                piVar5 = piVar15 + 1;
                *piVar15 = *piVar10;
                piVar15 = piVar5;
                piVar10 = piVar11;
            } while (piVar11 != piVar9 + iVar6);
            iVar18 = 0;
            iVar4 = 0;
            do {
                if (iVar3 < 1) {
                    iVar19 = 0;
                }
                else {
                    iVar19 = 0;
                    piVar15 = (int *)((int)this->field_0x20 + -4);
                    piVar5 = piVar16 + iVar3 + 0x40000000;
                    do {
                        piVar15 = piVar15 + 1;
                        piVar5 = piVar5 + -1;
                        lVar2 = (longlong)*piVar15 * (longlong)*piVar5 + 0x1000000;
                        iVar19 = iVar19 + ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
                    } while (piVar16 != piVar5);
                }
                if (iVar4 < param_2) {
                    piVar5 = param_1;
                }
                iVar17 = iVar4 + 1;
                piVar16 = piVar16 + 1;
                if (iVar4 < param_2) {
                    *(int *)((int)piVar5 + iVar18) = iVar19;
                }
                iVar18 = iVar18 + param_3 * 4;
                iVar4 = iVar17;
            } while (iVar17 != iVar6);
        }
        if (1 < iVar3) {
            pvVar12 = this->field_0x40;
            puVar13 = (undefined4 *)((int)pvVar12 + iVar6 * 4);
            pvVar14 = (void *)((int)this->field_0x0 + iVar3 * 4);
            do {
                puVar13 = puVar13 + -1;
                *(undefined4 *)((int)pvVar14 + -8) = *puVar13;
                pvVar14 = (void *)((int)pvVar14 + -4);
            } while (puVar13 != (undefined4 *)((int)pvVar12 + iVar3 * -4 + iVar6 * 4 + 4));
        }
    }
    return;
}



// FIR::FilterSamples(int*, int)

void FIR::FilterSamples(int *param_1,int param_2) {
    FilterSamplesInterleaved(this,param_1,param_2,1);
    return;
}
