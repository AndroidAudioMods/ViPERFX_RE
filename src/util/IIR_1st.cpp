//
// Created by mart on 2/12/21.
//

#include "IIR_1st.h"

// IIR_1st::Mute()

void IIR_1st::Mute() {
    this->field_0xc = 0;
    return;
}



// IIR_1st::IIR_1st()

IIR_1st::IIR_1st() {
    Mute(this);
    return this;
}



// IIR_1st::setCoefficients(float, float, float)

void IIR_1st::setCoefficients(int param_1,int param_2,int param_3) {
    this->field_0x4 = ROUND((float)param_1 * 3.355443e+07 + 0.5);
    this->field_0x8 = ROUND((float)param_2 * 3.355443e+07 + 0.5);
    this->field_0x0 = ROUND((float)param_3 * 3.355443e+07 + 0.5);
    return;
}



// IIR_1st::setLPF_BW(float, float)

void IIR_1st::setLPF_BW(float param_1,float param_2) {
    undefined4 uVar1;
    undefined4 extraout_r1;
    float in_r2;
    undefined4 unaff_r4;
    undefined4 in_lr;
    undefined4 in_cr1;
    undefined4 in_cr2;
    float fVar2;
    double dVar3;

    coprocessor_function(0xb,6,5,in_cr1,in_cr2,in_cr1);
    uVar1 = SUB84(3.141592653589793 / (double)in_r2,0);
    tan((double)CONCAT44(in_lr,unaff_r4));
    dVar3 = (double)CONCAT44(extraout_r1,uVar1);
    fVar2 = SUB84(ROUND((dVar3 / (dVar3 + 1.0)) * 33554432.0 + 0.5),0);
    this->field_0x8 = fVar2;
    this->field_0x0 = SUB84(ROUND(((1.0 - dVar3) / (dVar3 + 1.0)) * 33554432.0 + 0.5),0);
    this->field_0x4 = fVar2;
    return;
}



// IIR_1st::setHPF_BW(float, float)

void IIR_1st::setHPF_BW(float param_1,float param_2) {
    undefined4 uVar1;
    undefined4 extraout_r1;
    float in_r2;
    undefined4 unaff_r4;
    undefined4 in_lr;
    undefined4 in_cr1;
    undefined4 in_cr2;
    double dVar2;
    double dVar3;

    coprocessor_function(0xb,6,5,in_cr1,in_cr2,in_cr1);
    uVar1 = SUB84(3.141592653589793 / (double)in_r2,0);
    tan((double)CONCAT44(in_lr,unaff_r4));
    dVar3 = (double)CONCAT44(extraout_r1,uVar1) + 1.0;
    dVar2 = 1.0 / dVar3;
    this->field_0x4 = SUB84(ROUND(dVar2 * 33554432.0 + 0.5),0);
    this->field_0x0 =
            SUB84(ROUND(((1.0 - (double)CONCAT44(extraout_r1,uVar1)) / dVar3) * 33554432.0 + 0.5),0);
    this->field_0x8 = SUB84(ROUND(0.5 - dVar2 * 33554432.0),0);
    return;
}



// IIR_1st::setLPF_A(float, float)

void IIR_1st::setLPF_A(float param_1,float param_2) {
    undefined4 uVar1;
    undefined4 extraout_r1;
    float in_r2;
    undefined4 in_cr0;
    undefined4 in_cr1;
    undefined4 in_cr2;
    undefined4 in_cr3;
    undefined4 in_cr8;
    double unaff_d8;
    double dVar2;

    coprocessor_function(0xb,6,5,in_cr1,in_cr2,in_cr1);
    coprocessor_function(0xb,6,4,in_cr0,in_cr0,in_cr8);
    uVar1 = SUB84(-3.141592653589793 / (double)in_r2,0);
    exp(unaff_d8);
    dVar2 = (double)CONCAT44(extraout_r1,uVar1);
    this->field_0x0 = SUB84(ROUND(dVar2 * 33554432.0 + 0.5),0);
    coprocessor_function(0xb,6,5,in_cr2,in_cr1,in_cr3);
    this->field_0x4 = SUB84(ROUND(((1.0 - dVar2) / 1.12) * 33554432.0 + 0.5),0);
    this->field_0x8 = SUB84(ROUND(dVar2 * 33554432.0 + 0.5),0);
    return;
}



// IIR_1st::setHPF_A(float, float)

void IIR_1st::setHPF_A(float param_1,float param_2) {
    undefined4 uVar1;
    undefined4 extraout_r1;
    float in_r2;
    undefined4 in_cr0;
    undefined4 in_cr1;
    undefined4 in_cr2;
    undefined4 in_cr8;
    double unaff_d8;
    double dVar2;

    coprocessor_function(0xb,6,5,in_cr1,in_cr2,in_cr1);
    coprocessor_function(0xb,6,4,in_cr0,in_cr0,in_cr8);
    uVar1 = SUB84(-3.141592653589793 / (double)in_r2,0);
    exp(unaff_d8);
    dVar2 = (double)CONCAT44(extraout_r1,uVar1) + 1.0;
    coprocessor_function(0xb,6,4,in_cr1,in_cr1,in_cr8);
    this->field_0x8 = SUB84(ROUND(0.5 - dVar2 * 33554432.0),0);
    this->field_0x0 = SUB84(ROUND((double)CONCAT44(extraout_r1,uVar1) * 33554432.0 + 0.5),0);
    this->field_0x4 = SUB84(ROUND(dVar2 * 33554432.0 + 0.5),0);
    return;
}



// IIR_1st::setLSF_A(float, float, float)

void IIR_1st::setLSF_A(float param_1,float param_2,float param_3) {
    undefined4 uVar1;
    float in_r1;
    undefined4 extraout_r1;
    undefined4 extraout_r1_00;
    float in_r3;
    undefined4 in_cr0;
    undefined4 in_cr1;
    undefined4 in_cr8;
    undefined4 in_cr10;
    undefined4 in_cr11;
    double unaff_d8;

    coprocessor_function(0xb,2,0,in_cr10,in_cr10,in_cr8);
    coprocessor_function(0xb,6,4,in_cr0,in_cr0,in_cr11);
    uVar1 = SUB84((double)in_r1 / (double)in_r3,0);
    exp(unaff_d8);
    this->field_0x4 = -4.25353e+37;
    coprocessor_function(0xb,2,4,in_cr11,in_cr1,in_cr11);
    this->field_0x0 = SUB84(ROUND(0.5 - (double)CONCAT44(extraout_r1,uVar1) * 33554432.0),0);
    uVar1 = SUB84(-3.141592653589793 / (double)in_r3,0);
    exp(unaff_d8);
    this->field_0x8 = SUB84(ROUND((double)CONCAT44(extraout_r1_00,uVar1) * 33554432.0 + 0.5),0);
    return;
}



// IIR_1st::setHSF_A(float, float, float)

void IIR_1st::setHSF_A(float param_1,float param_2,float param_3) {
    undefined4 uVar1;
    undefined4 uVar2;
    float in_r1;
    undefined4 extraout_r1;
    undefined4 extraout_r1_00;
    float in_r3;
    undefined4 in_cr0;
    undefined4 in_cr1;
    undefined4 in_cr2;
    undefined4 in_cr8;
    undefined4 in_cr10;
    undefined4 in_cr11;
    double unaff_d8;

    coprocessor_function(0xb,2,0,in_cr10,in_cr10,in_cr8);
    coprocessor_function(0xb,6,4,in_cr0,in_cr0,in_cr11);
    uVar1 = SUB84((double)in_r1 / (double)in_r3,0);
    exp(unaff_d8);
    coprocessor_function(0xb,2,4,in_cr11,in_cr0,in_cr11);
    uVar2 = SUB84(-3.141592653589793 / (double)in_r3,0);
    exp(unaff_d8);
    this->field_0x0 = SUB84(ROUND((double)CONCAT44(extraout_r1,uVar1) * 33554432.0 + 0.5),0);
    coprocessor_function(0xb,6,5,in_cr2,in_cr2,in_cr1);
    this->field_0x4 =
            SUB84(ROUND(0.5 - ((1.0 - (double)CONCAT44(extraout_r1,uVar1)) /
                               ((double)CONCAT44(extraout_r1_00,uVar2) - 1.0)) * 33554432.0),0);
    this->field_0x8 = SUB84(ROUND((double)CONCAT44(extraout_r1_00,uVar2) * 33554432.0 + 0.5),0);
    return;
}



// IIR_1st::setHPFwLFS_A(float, float)

void IIR_1st::setHPFwLFS_A(float param_1,float param_2) {
    undefined4 uVar1;
    undefined4 extraout_r1;
    float in_r2;
    undefined4 in_cr0;
    undefined4 in_cr1;
    undefined4 in_cr2;
    undefined4 in_cr8;
    int iVar2;
    double unaff_d8;

    coprocessor_function(0xb,6,5,in_cr1,in_cr2,in_cr1);
    coprocessor_function(0xb,6,4,in_cr0,in_cr0,in_cr8);
    uVar1 = SUB84(-3.141592653589793 / (double)in_r2,0);
    exp(unaff_d8);
    this->field_0x0 = -NAN;
    iVar2 = SUB84(ROUND((double)CONCAT44(extraout_r1,uVar1) - 1.0),0);
    if (iVar2 < 0) {
        iVar2 = -iVar2;
    }
    coprocessor_function(0xb,6,5,in_cr2,in_cr2,in_cr1);
    this->field_0x4 = SUB84(ROUND(0.5 - (1.12 / (double)(longlong)iVar2) * 33554432.0),0);
    this->field_0x8 = SUB84(ROUND((double)CONCAT44(extraout_r1,uVar1) * 33554432.0 + 0.5),0);
    return;
}



// IIR_1st::setLPF_C(float, float)

void IIR_1st::setLPF_C(float param_1,float param_2) {
    float in_r1;
    float in_r2;
    float fVar1;

    fVar1 = SUB84(ROUND((double)(in_r1 / (in_r2 + in_r1)) * 33554432.0 + 0.5),0);
    this->field_0x8 = fVar1;
    this->field_0x0 = SUB84(ROUND((double)((in_r2 - in_r1) / (in_r2 + in_r1)) * 33554432.0 + 0.5),0);
    this->field_0x4 = fVar1;
    return;
}



// IIR_1st::setHPF_C(float, float)

void IIR_1st::setHPF_C(float param_1,float param_2) {
    float in_r1;
    float in_r2;
    double dVar1;

    dVar1 = (double)(in_r2 / (in_r2 + in_r1));
    this->field_0x4 = SUB84(ROUND(dVar1 * 33554432.0 + 0.5),0);
    this->field_0x8 = SUB84(ROUND(0.5 - dVar1 * 33554432.0),0);
    this->field_0x0 = SUB84(ROUND((double)((in_r2 - in_r1) / (in_r2 + in_r1)) * 33554432.0 + 0.5),0);
    return;
}



// IIR_1st::setPole(float)

void IIR_1st::setPole(float param_1) {
    float in_r1;
    undefined4 in_cr2;
    undefined4 in_cr3;
    float fVar1;

    fVar1 = ROUND(in_r1);
    if ((int)fVar1 < 0) {
        fVar1 = (float)-(int)fVar1;
    }
    coprocessor_function(0xb,6,5,in_cr3,in_cr2,in_cr3);
    this->field_0x0 = SUB84(ROUND((double)in_r1 * 33554432.0 + 0.5),0);
    this->field_0x4 = SUB84(ROUND((1.0 - (double)(longlong)(int)fVar1) * 33554432.0 + 0.5),0);
    this->field_0x8 = 0.0;
    return;
}



// IIR_1st::setZero(float)

void IIR_1st::setZero(float param_1) {
    float in_r1;
    undefined4 in_cr2;
    undefined4 in_cr3;
    float fVar1;

    fVar1 = ROUND(in_r1);
    if ((int)fVar1 < 0) {
        fVar1 = (float)-(int)fVar1;
    }
    this->field_0x0 = 0.0;
    coprocessor_function(0xb,6,5,in_cr3,in_cr3,in_cr2);
    this->field_0x4 = SUB84(ROUND(0.5 - ((double)(longlong)(int)fVar1 + 1.0) * 33554432.0),0);
    this->field_0x8 = SUB84(ROUND((double)in_r1 * 33554432.0 + 0.5),0);
    return;
}



// IIR_1st::setPoleLPF(float, float)

void IIR_1st::setPoleLPF(float param_1,float param_2) {
    undefined4 uVar1;
    undefined4 extraout_r1;
    undefined4 extraout_r1_00;
    float in_r2;
    undefined in_ZR;
    undefined4 in_cr1;
    undefined4 in_cr2;
    double unaff_d8;
    double dVar2;
    double dVar3;
    double dVar4;

    coprocessor_function(0xb,6,5,in_cr1,in_cr2,in_cr1);
    uVar1 = SUB84(6.283185307179586 / (double)in_r2,0);
    cos(unaff_d8);
    dVar2 = 2.0 - (double)CONCAT44(extraout_r1,uVar1);
    dVar4 = dVar2 * dVar2 - 1.0;
    dVar3 = SQRT(dVar4);
    if (!(bool)in_ZR) {
        uVar1 = SUB84(dVar4,0);
        sqrt(unaff_d8);
        dVar3 = (double)CONCAT44(extraout_r1_00,uVar1);
    }
    this->field_0x8 = 0.0;
    this->field_0x0 = SUB84(ROUND((dVar2 - dVar3) * 33554432.0 + 0.5),0);
    this->field_0x4 = SUB84(ROUND((1.0 - (dVar2 - dVar3)) * 33554432.0 + 0.5),0);
    return;
}



// IIR_1st::setPoleHPF(float, float)

void IIR_1st::setPoleHPF(float param_1,float param_2) {
    undefined4 uVar1;
    undefined4 extraout_r1;
    undefined4 extraout_r1_00;
    float in_r2;
    undefined in_ZR;
    undefined4 in_cr1;
    undefined4 in_cr2;
    double unaff_d8;
    double dVar2;
    double dVar3;
    double dVar4;

    coprocessor_function(0xb,6,5,in_cr1,in_cr2,in_cr1);
    uVar1 = SUB84(6.283185307179586 / (double)in_r2,0);
    cos(unaff_d8);
    dVar2 = (double)CONCAT44(extraout_r1,uVar1) + 2.0;
    dVar4 = dVar2 * dVar2 - 1.0;
    dVar3 = SQRT(dVar4);
    if (!(bool)in_ZR) {
        uVar1 = SUB84(dVar4,0);
        sqrt(unaff_d8);
        dVar3 = (double)CONCAT44(extraout_r1_00,uVar1);
    }
    this->field_0x8 = 0.0;
    this->field_0x0 = SUB84(ROUND(0.5 - (dVar2 - dVar3) * 33554432.0),0);
    this->field_0x4 = SUB84(ROUND(((dVar2 - dVar3) - 1.0) * 33554432.0 + 0.5),0);
    return;
}



// IIR_1st::setZeroLPF(float, float)

void IIR_1st::setZeroLPF(float param_1,float param_2) {
    undefined4 uVar1;
    undefined4 extraout_r1;
    undefined4 extraout_r1_00;
    float in_r2;
    undefined in_ZR;
    undefined4 in_cr1;
    undefined4 in_cr2;
    double unaff_d8;
    double dVar2;
    double dVar3;
    double dVar4;

    coprocessor_function(0xb,6,5,in_cr1,in_cr2,in_cr1);
    uVar1 = SUB84(6.283185307179586 / (double)in_r2,0);
    cos(unaff_d8);
    dVar2 = 1.0 - ((double)CONCAT44(extraout_r1,uVar1) + (double)CONCAT44(extraout_r1,uVar1));
    dVar4 = dVar2 * dVar2 - 1.0;
    dVar3 = SQRT(dVar4);
    if (!(bool)in_ZR) {
        uVar1 = SUB84(dVar4,0);
        sqrt(unaff_d8);
        dVar3 = (double)CONCAT44(extraout_r1_00,uVar1);
    }
    dVar4 = (dVar2 - dVar3) + 1.0;
    this->field_0x0 = 0.0;
    this->field_0x4 = SUB84(ROUND((1.0 / dVar4) * 33554432.0 + 0.5),0);
    this->field_0x8 = SUB84(ROUND(((dVar2 - dVar3) / dVar4) * 33554432.0 + 0.5),0);
    return;
}



// IIR_1st::setZeroHPF(float, float)

void IIR_1st::setZeroHPF(float param_1,float param_2) {
    undefined4 uVar1;
    undefined4 extraout_r1;
    undefined4 extraout_r1_00;
    float in_r2;
    undefined in_ZR;
    undefined4 in_cr1;
    undefined4 in_cr2;
    double unaff_d8;
    double dVar2;
    double dVar3;
    double dVar4;

    coprocessor_function(0xb,6,5,in_cr1,in_cr2,in_cr1);
    uVar1 = SUB84(6.283185307179586 / (double)in_r2,0);
    cos(unaff_d8);
    dVar2 = (double)CONCAT44(extraout_r1,uVar1) + (double)CONCAT44(extraout_r1,uVar1) + 1.0;
    dVar4 = dVar2 * dVar2 - 1.0;
    dVar3 = SQRT(dVar4);
    if (!(bool)in_ZR) {
        uVar1 = SUB84(dVar4,0);
        sqrt(unaff_d8);
        dVar3 = (double)CONCAT44(extraout_r1_00,uVar1);
    }
    dVar4 = (dVar2 - dVar3) + 1.0;
    this->field_0x0 = 0.0;
    this->field_0x4 = SUB84(ROUND((1.0 / dVar4) * 33554432.0 + 0.5),0);
    this->field_0x8 = SUB84(ROUND(((0.0 - (dVar2 - dVar3)) / dVar4) * 33554432.0 + 0.5),0);
    return;
}
