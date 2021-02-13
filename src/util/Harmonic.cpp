//
// Created by mart on 2/12/21.
//

#include "Harmonic.h"


// Harmonic::~Harmonic()

Harmonic::~Harmonic() {
    return;
}



// Harmonic::UpdateCoeffs(float const*)

void Harmonic::UpdateCoeffs(float *param_1) {
    float *pfVar1;
    float *pfVar2;
    int iVar3;
    int iVar4;
    float *pfVar5;
    float *pfVar6;
    char in_NG;
    undefined in_ZR;
    char in_OV;
    undefined4 in_cr7;
    float coeff;
    float fVar7;
    float local_9c [20];
    float afStack76 [14];
    float *coeffptr;

    fVar7 = 0.0;
    iVar3 = 10;
    local_9c[0] = 0.0;
    local_9c[1] = 0.0;
    local_9c[2] = 0.0;
    local_9c[3] = 0.0;
    local_9c[4] = 0.0;
    local_9c[5] = 0.0;
    local_9c[6] = 0.0;
    local_9c[7] = 0.0;
    local_9c[8] = 0.0;
    local_9c[9] = 0.0;
    local_9c[10] = 0.0;
    coeffptr = param_1;
    do {
        coeff = *coeffptr;
        coeffptr = coeffptr + 1;
        if (!(bool)in_ZR && in_NG == in_OV) {
            fVar7 = ABS(coeff);
        }
        in_OV = SBORROW4(iVar3,1);
        iVar3 = iVar3 + -1;
        in_NG = iVar3 < 0;
        in_ZR = iVar3 == 0;
    } while (!(bool)in_ZR);
    coprocessor_function(10,6,4,in_cr7,in_cr7,in_cr7);
    this->field_0x34 = ROUND(fVar7);
    coeffptr = local_9c + 1;
    do {
        pfVar1 = coeffptr + 1;
        *coeffptr = *param_1;
        param_1 = param_1 + 1;
        coeffptr = pfVar1;
    } while (pfVar1 != local_9c + 0xb);
    coeffptr = local_9c;
    do {
        coprocessor_function(10,6,4,in_cr7,in_cr7,in_cr7);
        *coeffptr = *coeffptr;
        coeffptr = coeffptr + 1;
    } while (coeffptr != local_9c + 0xb);
    pfVar1 = afStack76 + 2;
    do {
        pfVar6 = pfVar1 + 1;
        *pfVar1 = 0.0;
        *coeffptr = 0.0;
        pfVar1 = pfVar6;
        coeffptr = coeffptr + 1;
    } while (pfVar6 != afStack76 + 0xd);
    coeffptr = local_9c + 10;
    pfVar1 = local_9c + 0xe;
    pfVar2 = afStack76 + 5;
    iVar4 = 2;
    local_9c[11] = local_9c[10];
    fVar7 = local_9c[11];
    pfVar6 = pfVar1;
    pfVar5 = pfVar2;
    iVar3 = iVar4;
    do {
        do {
            local_9c[11] = fVar7;
            coeff = pfVar1[-2];
            iVar4 = iVar4 + -1;
            fVar7 = pfVar2[-1];
            pfVar2 = pfVar2 + -1;
            *pfVar2 = pfVar1[-1];
            pfVar1 = pfVar1 + -1;
            *pfVar1 = (coeff + coeff) - fVar7;
            fVar7 = local_9c[11];
        } while (0 < iVar4);
        iVar4 = iVar3 + 1;
        coeffptr = coeffptr + -1;
        pfVar1 = pfVar6 + 1;
        pfVar2 = pfVar5 + 1;
        fVar7 = *coeffptr - afStack76[2];
        afStack76[2] = local_9c[11];
        pfVar6 = pfVar1;
        pfVar5 = pfVar2;
        iVar3 = iVar4;
    } while (iVar4 != 0xb);
    coeffptr = afStack76 + 0xd;
    pfVar1 = afStack76 + 2;
    do {
        pfVar6 = pfVar1 + -2;
        coeffptr = coeffptr + -1;
        pfVar1 = pfVar1 + -1;
        *pfVar1 = *pfVar6 - *coeffptr;
    } while (coeffptr != afStack76 + 3);
    coeffptr = local_9c + 0xc;
    iVar3 = 0;
    local_9c[11] = local_9c[0] * 0.5 - local_9c[11];
    while( true ) {
        *(float *)((int)this->field_0x0 + iVar3) = ROUND(local_9c[11] * 3.355443e+07 + 0.5);
        iVar3 = iVar3 + 4;
        if (iVar3 == 0x2c) break;
        local_9c[11] = *coeffptr;
        coeffptr = coeffptr + 1;
    }
    return;
}



// Harmonic::Reset()

void Harmonic::Reset() {
    this->field_0x2c = 0;
    this->field_0x30 = 0;
    this->field_0x38 = 0;
    return;
}



// Harmonic::Harmonic()

Harmonic::Harmonic() {
    UpdateCoeffs(this,FLOAT_ARRAY_000ce820);
    Reset(this);
    return this;
}



// Harmonic::SetHarmonics(float const*)

void Harmonic::SetHarmonics(float *param_1) {
    UpdateCoeffs(this,param_1);
    Reset(this);
    return;
}



// Harmonic::Process(int)

int Harmonic::Process(int param_1) {
    longlong lVar1;
    longlong lVar2;
    int iVar3;
    int iVar4;
    int iVar5;

    lVar1 = (longlong)(int)this->field_0x0[10] * (longlong)param_1 + 0x1000000;
    lVar1 = (longlong)param_1 *
            (longlong)
                    (int)((int)this->field_0x0[9] +
                          ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7)) + 0x1000000;
    lVar1 = (longlong)param_1 *
            (longlong)
                    (int)((int)this->field_0x0[8] +
                          ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7)) + 0x1000000;
    lVar2 = (longlong)(int)this->field_0x30 * 0x1ff7cee + 0x1000000;
    iVar3 = this->field_0x2c;
    lVar1 = (longlong)param_1 *
            (longlong)
                    (int)((int)this->field_0x0[7] +
                          ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7)) + 0x1000000;
    iVar5 = this->field_0x38;
    lVar1 = (longlong)param_1 *
            (longlong)
                    (int)((int)this->field_0x0[6] +
                          ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7)) + 0x1000000;
    if (iVar5 < (int)this->field_0x34) {
        this->field_0x38 = iVar5 + 1;
    }
    lVar1 = (longlong)param_1 *
            (longlong)
                    (int)((int)this->field_0x0[5] +
                          ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7)) + 0x1000000;
    lVar1 = (longlong)param_1 *
            (longlong)
                    (int)((int)this->field_0x0[4] +
                          ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7)) + 0x1000000;
    lVar1 = (longlong)param_1 *
            (longlong)
                    (int)((int)this->field_0x0[3] +
                          ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7)) + 0x1000000;
    lVar1 = (longlong)param_1 *
            (longlong)
                    (int)((int)this->field_0x0[2] +
                          ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7)) + 0x1000000;
    lVar1 = (longlong)param_1 *
            (longlong)
                    (int)((int)this->field_0x0[1] +
                          ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7)) + 0x1000000;
    iVar4 = (int)this->field_0x0[0] + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
    this->field_0x2c = iVar4;
    iVar3 = (iVar4 + ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7)) - iVar3;
    this->field_0x30 = iVar3;
    if (iVar5 < (int)this->field_0x34) {
        iVar3 = 0;
    }
    return iVar3;
}
