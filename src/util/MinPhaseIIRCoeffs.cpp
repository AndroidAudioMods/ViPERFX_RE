//
// Created by mart on 2/12/21.
//

#include "MinPhaseIIRCoeffs.h"

// MinPhaseIIRCoeffs::MinPhaseIIRCoeffs()

MinPhaseIIRCoeffs::MinPhaseIIRCoeffs() {
    this->samplerate = 0xac44;
    this->coefficients = nullptr;
    this->field_0x8 = 0;
    return;
}



// MinPhaseIIRCoeffs::~MinPhaseIIRCoeffs()

MinPhaseIIRCoeffs::~MinPhaseIIRCoeffs() {
    if (this->coefficients != nullptr) {
        operator_delete__(this->coefficients);
        this->coefficients = nullptr;
    }
    return this;
}



// MinPhaseIIRCoeffs::Find_F1_F2(double, double, double*, double*)

void MinPhaseIIRCoeffs::Find_F1_F2(double param_1,double param_2,double *param_3,double *param_4) {
    undefined4 uVar1;
    undefined4 extraout_r1;
    undefined4 in_r2;
    undefined4 in_r3;
    undefined4 unaff_r4;
    undefined4 in_cr0;
    undefined4 in_cr1;
    undefined4 in_cr2;
    undefined4 in_cr8;
    double unaff_d8;

    uVar1 = 0;
    coprocessor_function(0xb,6,5,in_cr2,in_cr0,in_cr1);
    pow(unaff_d8,(double)CONCAT44(unaff_r4,in_r3));
    coprocessor_function(0xb,2,1,in_cr8,in_cr8,in_cr0);
    *param_2._0_4_ = (double)CONCAT44(in_r3,in_r2) / (double)CONCAT44(extraout_r1,uVar1);
    *param_2._4_4_ = (double)CONCAT44(in_r3,in_r2);
    return;
}



// MinPhaseIIRCoeffs::SolveRoot(double, double, double, double*)

double * MinPhaseIIRCoeffs::SolveRoot(double param_1,double param_2,double param_3,double *param_4) {
    undefined4 uVar1;
    undefined4 uVar2;
    undefined4 extraout_r1;
    undefined4 extraout_r1_00;
    undefined4 in_r2;
    undefined4 in_r3;
    char in_NG;
    undefined in_ZR;
    char in_OV;
    undefined4 in_cr0;
    undefined4 in_cr1;
    undefined4 in_cr3;
    undefined4 in_cr4;
    double unaff_d8;
    double dVar3;
    double dVar4;
    double dVar5;
    double in_d20;

    dVar5 = (double)CONCAT44(in_r3,in_r2);
    coprocessor_function(0xb,6,5,in_cr3,in_cr0,in_cr3);
    coprocessor_function(0xb,6,5,in_cr4,in_cr1,in_cr1);
    dVar4 = param_1 / (dVar5 + dVar5);
    if (!(bool)in_ZR && in_NG == in_OV) {
        param_4 = (double *)0xffffffff;
    }
    if ((bool)in_ZR || in_NG != in_OV) {
        dVar5 = 0.0 - (param_2 - in_d20 / 4.0) / dVar5;
        dVar3 = SQRT(dVar5);
        uVar2 = SUB84(dVar5,0);
        dVar5 = dVar3;
        if (!(bool)in_ZR) {
            uVar1 = uVar2;
            sqrt(unaff_d8);
            dVar5 = (double)CONCAT44(extraout_r1,uVar1);
        }
        *param_3._0_4_ = (0.0 - dVar4) - dVar5;
        if (!(bool)in_ZR) {
            sqrt(unaff_d8);
            dVar3 = (double)CONCAT44(extraout_r1_00,uVar2);
        }
        param_4 = nullptr;
        if ((bool)in_NG) {
            *param_3._0_4_ = dVar3 - dVar4;
        }
    }
    return param_4;
}



// MinPhaseIIRCoeffs::UpdateCoeffs(int, int)

undefined4 MinPhaseIIRCoeffs::UpdateCoeffs(int param_1,int samplerate) {
    uint uVar1;
    void *pvVar2;
    undefined4 uVar3;
    undefined4 uVar4;
    double *extraout_r1;
    undefined4 extraout_r1_00;
    undefined4 extraout_r1_01;
    double *pdVar5;
    double *pdVar6;
    int iVar7;
    undefined4 in_cr0;
    undefined4 in_cr1;
    undefined4 in_cr3;
    undefined4 in_cr4;
    undefined4 in_cr8;
    undefined4 in_cr9;
    undefined4 in_cr10;
    undefined4 in_cr11;
    undefined4 in_cr12;
    undefined4 in_cr13;
    undefined4 in_cr14;
    undefined4 in_cr15;
    int iVar8;
    double unaff_d13;
    double unaff_d14;
    double dVar9;
    double dVar10;
    undefined8 uVar11;
    undefined4 in_stack_ffffff6c;
    double local_90;
    double local_80;
    undefined auStack120 [8];
    double local_70;

    if ((param_1 != 10 && (param_1 & 0xffffffefU) != 0xf) && (param_1 != 0x19)) {
        return 0;
    }
    if (samplerate < 0xac44) {
        return 0;
    }
    this->field_0x8 = param_1;
    this->samplerate = samplerate;
    if (this->coefficients != nullptr) {
        operator_delete__(this->coefficients);
        param_1 = this->field_0x8;
        this->coefficients = nullptr;
    }
    if ((uint)param_1 < 0x7f00001) {
        uVar1 = param_1 << 4;
    }
    else {
        uVar1 = 0xffffffff;
    }
    pvVar2 = operator_new__(uVar1);
    this->coefficients = pvVar2;
    if (pvVar2 == nullptr) {
        return 0;
    }
    memset(pvVar2,0,this->field_0x8 << 4);
    switch(this->field_0x8) {
        case 10:
            local_90 = 1.0;
            pdVar6 = (double *)&DAT_000ce7d0;
            goto LAB_00065e84;
        case 0xb:
            break;
        case 0xc:
            break;
        case 0xd:
            break;
        case 0xe:
            break;
        case 0xf:
            local_90 = 0.6666666666666666;
            pdVar6 = (double *)&DAT_000ce598;
            goto LAB_00065e84;
        case 0x10:
            break;
        case 0x11:
            break;
        case 0x12:
            break;
        case 0x13:
            break;
        case 0x14:
            break;
        case 0x15:
            break;
        case 0x16:
            break;
        case 0x17:
            break;
        case 0x18:
            break;
        case 0x19:
            pdVar6 = (double *)&DAT_000ce610;
            local_90 = 0.3333333333333333;
            goto LAB_00065e84;
        case 0x1a:
            break;
        case 0x1b:
            break;
        case 0x1c:
            break;
        case 0x1d:
            break;
        case 0x1e:
            break;
        case 0x1f:
            local_90 = 0.3333333333333333;
            pdVar6 = (double *)&DAT_000ce6d8;
        LAB_00065e84:
            iVar7 = 0;
            pdVar5 = extraout_r1;
            do {
                dVar10 = local_90;
                Find_F1_F2(local_90,(double)CONCAT44(auStack120,&local_80),(double *)this,pdVar5);
                dVar9 = *pdVar6;
                pdVar6 = pdVar6 + 1;
                iVar8 = this->samplerate;
                coprocessor_function(0xb,6,4,in_cr0,in_cr0,in_cr15);
                uVar3 = SUB84(dVar9 / (double)(longlong)iVar8,0);
                cos(dVar10);
                coprocessor_function(0xb,2,0,in_cr14,in_cr8,in_cr8);
                coprocessor_function(0xb,2,0,in_cr12,in_cr12,in_cr15);
                coprocessor_function(0xb,2,0,in_cr13,in_cr14,in_cr11);
                dVar9 = local_80 / (double)(longlong)iVar8;
                uVar4 = SUB84(dVar9,0);
                cos(dVar10);
                coprocessor_function(0xb,2,1,in_cr12,in_cr9,in_cr0);
                sin(dVar10);
                coprocessor_function(0xb,2,0,in_cr12,in_cr8,in_cr12);
                coprocessor_function(0xb,6,1,in_cr3,in_cr9,in_cr0);
                coprocessor_function(0xb,2,0,in_cr9,in_cr9,in_cr9);
                coprocessor_function(0xb,6,5,in_cr0,in_cr4,in_cr4);
                coprocessor_function(0xb,2,1,in_cr8,in_cr8,in_cr3);
                unaff_d13 = unaff_d13 + (double)CONCAT44(extraout_r1_01,uVar4) * 0.9999999999999998;
                dVar10 = ((unaff_d13 - dVar9) - 0.4999999999999999) + 0.2499999999999999;
                uVar11 = SolveRoot(dVar10,((unaff_d14 * 0.125 - (double)CONCAT44(extraout_r1_00,uVar3)) +
                                           0.125) - 0.06249999999999999,
                                   (double)CONCAT44(in_stack_ffffff6c,&local_70),(double *)this);
                pdVar5 = (double *)((ulonglong)uVar11 >> 0x20);
                if ((int)uVar11 == 0) {
                    coprocessor_function(0xb,6,4,in_cr1,in_cr1,in_cr15);
                    coprocessor_function(0xb,6,4,in_cr0,in_cr0,in_cr10);
                    pvVar2 = (void *)((int)this->coefficients + iVar7 * 0x10);
                    dVar9 = local_70 + 0.5;
                    *(int *)((int)this->coefficients + iVar7 * 0x10) =
                            SUB84(ROUND((local_70 + local_70) * 33554432.0 + 0.5),0);
                    *(int *)((int)pvVar2 + 4) =
                            SUB84(ROUND(((0.5 - local_70) + (0.5 - local_70)) * 33554432.0 + 0.5),0);
                    cos(dVar10);
                    pdVar5 = (double *)0x41800000;
                    coprocessor_function(0xb,2,1,in_cr8,in_cr8,in_cr0);
                    *(int *)((int)pvVar2 + 8) = SUB84(ROUND((dVar9 + dVar9) * 33554432.0 + 0.5),0);
                }
                iVar7 = iVar7 + 1;
            } while (iVar7 < this->field_0x8);
            return 1;
    }
    return 0;
}



// MinPhaseIIRCoeffs::GetCoefficients()

void * MinPhaseIIRCoeffs::GetCoefficients() {
    return this->coefficients;
}



// MinPhaseIIRCoeffs::GetIndexFrequency(int)

undefined8 MinPhaseIIRCoeffs::GetIndexFrequency(int param_1) {
    if ((-1 < param_1) && (param_1 < this->field_0x8)) {
        switch(this->field_0x8) {
            case 10:
                return *(undefined8 *)(&DAT_000ce7d0 + param_1 * 2);
            case 0xb:
                break;
            case 0xc:
                break;
            case 0xd:
                break;
            case 0xe:
                break;
            case 0xf:
                return *(undefined8 *)(&DAT_000ce598 + param_1 * 2);
            case 0x10:
                break;
            case 0x11:
                break;
            case 0x12:
                break;
            case 0x13:
                break;
            case 0x14:
                break;
            case 0x15:
                break;
            case 0x16:
                break;
            case 0x17:
                break;
            case 0x18:
                break;
            case 0x19:
                return *(undefined8 *)(&DAT_000ce610 + param_1 * 2);
            case 0x1a:
                break;
            case 0x1b:
                break;
            case 0x1c:
                break;
            case 0x1d:
                break;
            case 0x1e:
                break;
            case 0x1f:
                return *(undefined8 *)(&DAT_000ce6d8 + param_1 * 8);
        }
    }
    return 0;
}
