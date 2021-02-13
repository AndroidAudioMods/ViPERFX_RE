//
// Created by mart on 2/12/21.
//

#include "IIRFilter.h"

// IIRFilter::~IIRFilter()

IIRFilter::~IIRFilter() {
    MinPhaseIIRCoeffs::~MinPhaseIIRCoeffs(&this->field_0xc);
    return this;
}



// IIRFilter::SetBandLevel(int, float)

double IIRFilter::SetBandLevel(int param_1,float param_2) {
    uint in_r1;
    undefined4 in_r3;
    undefined4 unaff_r4;
    undefined4 unaff_r5;
    undefined4 in_lr;
    undefined4 in_cr2;
    undefined4 in_cr3;
    undefined4 in_s1;
    double dVar1;

    if (0x1e < in_r1) {
        return (double)CONCAT44(in_s1,param_2);
    }
    dVar1 = pow((double)CONCAT44(unaff_r4,in_r3),(double)CONCAT44(in_lr,unaff_r5));
    coprocessor_function(0xb,6,5,in_cr2,in_cr3,in_cr2);
    *(undefined4 *)(param_1 + in_r1 * 4 + 0x7e4) = 0x30000000;
    return dVar1;
}



// IIRFilter::Reset()

void IIRFilter::Reset() {
    memset(this->field_0x18,0,0x7c0);
    this->field_0x7d8 = 2;
    this->field_0x7dc = 1;
    this->field_0x7e0 = 0;
    return;
}



// IIRFilter::IIRFilter(int)

IIRFilter::IIRFilter(int param_1) {
    undefined4 *puVar1;
    int iVar2;

    MinPhaseIIRCoeffs::MinPhaseIIRCoeffs(&this->field_0xc);
    this->enabled = false;
    if ((param_1 == 10 || (param_1 & 0xffffffefU) == 0xf) || (param_1 == 0x19)) {
        this->field_0x0 = param_1;
        this->samplerate = 0xac44;
        MinPhaseIIRCoeffs::UpdateCoeffs(&this->field_0xc,param_1,0xac44);
    }
    else {
        this->field_0x0 = 0;
        this->samplerate = 0xac44;
    }
    puVar1 = &this->field_0x7e0;
    iVar2 = 0x1f;
    do {
        iVar2 = iVar2 + -1;
        puVar1 = puVar1 + 1;
        *puVar1 = 0x145a983;
    } while (iVar2 != 0);
    Reset(this);
    return this;
}



// IIRFilter::SetEnable(bool)

undefined4 IIRFilter::SetEnable(bool param_1) {
    char cVar1;

    cVar1 = this->enabled;
    if ((bool)cVar1 == false) {
        if (param_1 == false) {
            return 0;
        }
        Reset(this);
        cVar1 = this->enabled;
    }
    if (param_1 == (bool)cVar1) {
        return 0;
    }
    this->enabled = param_1;
    return 1;
}



// IIRFilter::SetSamplingRate(int)

void IIRFilter::SetSamplingRate(int param_1) {
    if (this->samplerate == param_1) {
        return;
    }
    this->samplerate = param_1;
    if (this->field_0x0 == 0) {
        Reset(this);
        return;
    }
    MinPhaseIIRCoeffs::UpdateCoeffs(&this->field_0xc,this->field_0x0,param_1);
    Reset(this);
    return;
}



// IIRFilter::Process(int*, int)

void IIRFilter::Process(int *param_1,int param_2) {
    longlong lVar1;
    longlong lVar2;
    longlong lVar3;
    int iVar4;
    int iVar5;
    int iVar6;
    int *piVar7;
    int iVar8;
    int *piVar9;
    int iVar10;
    int iVar11;
    int iVar12;
    int iVar13;
    int *piVar14;
    int *piVar15;
    int *piVar16;
    int local_44;
    int *local_40;
    int *local_3c;
    int local_34;

    if (((this->enabled != false) &&
         (iVar4 = MinPhaseIIRCoeffs::GetCoefficients(&this->field_0xc), iVar4 != 0)) &&
        (local_34 = param_2 + -1, local_3c = param_1, param_2 != 0)) {
        do {
            local_44 = 0;
            local_40 = local_3c;
            do {
                iVar6 = this->field_0x0;
                iVar13 = *local_40;
                if (iVar6 < 1) {
                    iVar12 = 0;
                }
                else {
                    iVar12 = 0;
                    iVar10 = this->field_0x7d8;
                    iVar11 = this->field_0x7e0;
                    iVar8 = this->field_0x7dc;
                    piVar14 = &this->field_0x7e0;
                    piVar9 = (int *)(iVar4 + 8);
                    piVar15 = (int *)(this->field_0x18 + (iVar10 + local_44 * 8) * 4);
                    do {
                        iVar5 = piVar9[-1];
                        piVar7 = piVar15 + -iVar10;
                        *piVar15 = iVar13;
                        piVar16 = piVar15 + 0x10;
                        lVar1 = (longlong)iVar5 * (longlong)(iVar13 - piVar7[iVar11]) + 0x1000000;
                        lVar2 = (longlong)*piVar9 * (longlong)piVar7[iVar8 + 3] + 0x1000000;
                        lVar3 = (longlong)piVar9[-2] * (longlong)(piVar7 + iVar11)[3] + 0x1000000;
                        iVar5 = (((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) +
                                 ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7)) -
                                ((uint)lVar3 >> 0x19 | (int)((ulonglong)lVar3 >> 0x20) << 7);
                        piVar15[3] = iVar5;
                        piVar14 = piVar14 + 1;
                        lVar1 = (longlong)iVar5 * (longlong)*piVar14 + 0x1000000;
                        iVar12 = iVar12 + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
                        piVar9 = piVar9 + 4;
                        piVar15 = piVar16;
                    } while (piVar16 != (int *)(this->field_0x18 + (iVar10 + (local_44 + iVar6 * 2) * 8) * 4))
                            ;
                }
                local_44 = local_44 + 1;
                *local_40 = iVar12;
                local_40 = local_40 + 1;
            } while (local_44 != 2);
            local_34 = local_34 + -1;
            local_3c = local_3c + 2;
            this->field_0x7d8 = (this->field_0x7d8 + 1) % 3;
            this->field_0x7dc = (this->field_0x7dc + 1) % 3;
            this->field_0x7e0 = (this->field_0x7e0 + 1) % 3;
        } while (local_34 != -1);
        return;
    }
    return;
}
