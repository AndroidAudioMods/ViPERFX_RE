//
// Created by mart on 2/12/21.
//

#include "SpectrumExtend.h"

// SpectrumExtend::~SpectrumExtend()

SpectrumExtend::~SpectrumExtend() {
    Harmonic *this_00;

    if (this != (SpectrumExtend *)0xffffff70) {
        this_00 = (Harmonic *)&this->field_0x108;
        do {
            this_00 = this_00 + -1;
            Harmonic::~Harmonic(this_00);
        } while ((Harmonic *)&this->field_0x90 != this_00);
    }
    return this;
}



// SpectrumExtend::Reset()

void SpectrumExtend::Reset(void) {
    MultiBiquad *in_r0;
    float in_s0;
    float in_s1;
    undefined8 uVar1;
    float in_s2;
    float extraout_s2;
    float extraout_s2_00;
    float extraout_s2_01;
    float in_s3;
    float extraout_s3;
    float extraout_s3_00;
    float extraout_s3_01;

    uVar1 = MultiBiquad::RefreshFilter(in_r0,1,in_s0,in_s1,in_s2,in_s3,false);
    uVar1 = MultiBiquad::RefreshFilter
            (in_r0 + 1,1,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20),extraout_s2,
             extraout_s3,false);
    uVar1 = MultiBiquad::RefreshFilter
            (in_r0 + 2,0,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20),extraout_s2_00,
             extraout_s3_00,false);
    MultiBiquad::RefreshFilter
            (in_r0 + 3,0,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20),extraout_s2_01,
             extraout_s3_01,false);
    Harmonic::Reset((Harmonic *)(in_r0 + 4));
    Harmonic::Reset((Harmonic *)&in_r0[5].field_0x18);
    Harmonic::SetHarmonics((Harmonic *)(in_r0 + 4),(float *)&DAT_000ce848);
    Harmonic::SetHarmonics((Harmonic *)&in_r0[5].field_0x18,(float *)&DAT_000ce848);
    return;
}



// SpectrumExtend::SpectrumExtend()

SpectrumExtend::SpectrumExtend() {
    MultiBiquad::MultiBiquad((MultiBiquad *)this);
    MultiBiquad::MultiBiquad((MultiBiquad *)&this->field_0x24);
    MultiBiquad::MultiBiquad((MultiBiquad *)&this->field_0x48);
    MultiBiquad::MultiBiquad((MultiBiquad *)&this->field_0x6c);
    Harmonic::Harmonic((Harmonic *)&this->field_0x90);
    Harmonic::Harmonic((Harmonic *)&this->field_0xcc);
    *(undefined4 *)&this->field_0x10c = 0xac44;
    *(undefined4 *)&this->field_0x110 = 0x1db0;
    *(undefined *)&this->field_0x108 = 0;
    *(undefined4 *)&this->field_0x114 = 0;
    Reset();
    return this;
}



// SpectrumExtend::SetEnable(bool)

undefined4 SpectrumExtend::SetEnable(bool param_1) {
    char cVar1;

    cVar1 = *(char *)&this->field_0x108;
    if (cVar1 == '\0') {
        if (param_1 == false) {
            return 0;
        }
        Reset();
        cVar1 = *(char *)&this->field_0x108;
    }
    if (param_1 == (bool)cVar1) {
        return 0;
    }
    *(bool *)&this->field_0x108 = param_1;
    return 1;
}



// SpectrumExtend::SetSamplingRate(int)

void SpectrumExtend::SetSamplingRate(int param_1) {
    if (*(int *)&this->field_0x10c != param_1) {
        *(int *)&this->field_0x10c = param_1;
        if (param_1 / 2 + -99 <= *(int *)&this->field_0x110) {
            *(int *)&this->field_0x110 = param_1 / 2 + -100;
        }
        Reset();
        return;
    }
    return;
}



// SpectrumExtend::SetReferenceFrequency(int)

void SpectrumExtend::SetReferenceFrequency(int param_1) {
    int iVar1;

    iVar1 = *(int *)&this->field_0x10c / 2;
    if (iVar1 + -99 <= param_1) {
        param_1 = iVar1 + -100;
    }
    *(int *)&this->field_0x110 = param_1;
    Reset();
    return;
}



// SpectrumExtend::SetExciter(float)

void SpectrumExtend::SetExciter(float param_1) {
    float in_r1;

    *(float *)&this->field_0x114 = ROUND(in_r1 * 3.355443e+07 + 0.5);
    return;
}



// SpectrumExtend::Process(int*, int)

void SpectrumExtend::Process(int *param_1,int param_2) {
    ulonglong uVar1;
    int iVar2;
    int iVar3;
    undefined8 uVar4;
    int local_40;

    if ((*(char *)&this->field_0x108 != '\0') && (0 < param_2 * 2)) {
        iVar3 = 0;
        do {
            iVar2 = MultiBiquad::ProcessSample((MultiBiquad *)this,*param_1);
            iVar2 = Harmonic::Process((Harmonic *)&this->field_0x90,iVar2);
            iVar3 = iVar3 + 2;
            uVar1 = (longlong)iVar2 * (longlong)*(int *)&this->field_0x114 + 0x1000000;
            uVar4 = VectorShiftRight((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff),0x19);
            local_40 = (int)uVar4;
            iVar2 = MultiBiquad::ProcessSample((MultiBiquad *)&this->field_0x48,local_40);
            *param_1 = *param_1 + iVar2;
            iVar2 = MultiBiquad::ProcessSample((MultiBiquad *)&this->field_0x24,param_1[1]);
            iVar2 = Harmonic::Process((Harmonic *)&this->field_0xcc,iVar2);
            uVar1 = (longlong)iVar2 * (longlong)*(int *)&this->field_0x114 + 0x1000000;
            uVar4 = VectorShiftRight((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff),0x19);
            local_40 = (int)uVar4;
            iVar2 = MultiBiquad::ProcessSample((MultiBiquad *)&this->field_0x6c,local_40);
            param_1[1] = param_1[1] + iVar2;
            param_1 = param_1 + 2;
        } while (iVar3 + param_2 * -2 < 0 != SBORROW4(iVar3,param_2 * 2));
    }
    return;
}
