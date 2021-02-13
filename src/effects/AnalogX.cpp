//
// Created by mart on 2/12/21.
//

#include "AnalogX.h"

// AnalogX::Reset()

void AnalogX::Reset() {
    int iVar1;
    Harmonic *this_00;
    Harmonic *this_01;
    float in_s0;
    float in_s1;
    undefined8 uVar2;
    float in_s2;
    float extraout_s2;
    float extraout_s2_00;
    float extraout_s2_01;
    float extraout_s2_02;
    float extraout_s2_03;
    float extraout_s2_04;
    float extraout_s2_05;
    float extraout_s2_06;
    float extraout_s2_07;
    float in_s3;
    float extraout_s3;
    float extraout_s3_00;
    float extraout_s3_01;
    float extraout_s3_02;
    float extraout_s3_03;
    float extraout_s3_04;
    float extraout_s3_05;
    float extraout_s3_06;
    float extraout_s3_07;

    this_01 = &this->field_0x48;
    this_00 = &this->field_0x84;
    uVar2 = MultiBiquad::RefreshFilter((MultiBiquad *)this,1,in_s0,in_s1,in_s2,in_s3,false);
    uVar2 = MultiBiquad::RefreshFilter
            (&this->field_0x24,1,(float)uVar2,(float)((ulonglong)uVar2 >> 0x20),extraout_s2,
             extraout_s3,false);
    uVar2 = MultiBiquad::RefreshFilter
            (&this->field_0x108,5,(float)uVar2,(float)((ulonglong)uVar2 >> 0x20),
             extraout_s2_00,extraout_s3_00,true);
    MultiBiquad::RefreshFilter
            (&this->field_0x12c,5,(float)uVar2,(float)((ulonglong)uVar2 >> 0x20),extraout_s2_01,
             extraout_s3_01,true);
    Harmonic::Reset(this_01);
    Harmonic::Reset(this_00);
    iVar1 = this->processingModel;
    if (iVar1 == 1) {
        Harmonic::SetHarmonics(this_01,(float *)&DAT_000ce8dc);
        uVar2 = Harmonic::SetHarmonics(this_00,(float *)&DAT_000ce8dc);
        *(undefined4 *)&this->field_0x150 = 0x266594b;
        uVar2 = MultiBiquad::RefreshFilter
                (&this->field_0xc0,0,(float)uVar2,(float)((ulonglong)uVar2 >> 0x20),
                 extraout_s2_06,extraout_s3_06,false);
        MultiBiquad::RefreshFilter
                (&this->field_0xe4,0,(float)uVar2,(float)((ulonglong)uVar2 >> 0x20),extraout_s2_07,
                 extraout_s3_07,false);
        this->field_0x154 = 0;
        return;
    }
    if (iVar1 != 2) {
        if (iVar1 != 0) {
            this->field_0x154 = 0;
            return;
        }
        Harmonic::SetHarmonics(this_01,(float *)&DAT_000ce8b4);
        uVar2 = Harmonic::SetHarmonics(this_00,(float *)&DAT_000ce8b4);
        *(undefined4 *)&this->field_0x150 = 0x1332618;
        uVar2 = MultiBiquad::RefreshFilter
                (&this->field_0xc0,0,(float)uVar2,(float)((ulonglong)uVar2 >> 0x20),
                 extraout_s2_02,extraout_s3_02,false);
        MultiBiquad::RefreshFilter
                (&this->field_0xe4,0,(float)uVar2,(float)((ulonglong)uVar2 >> 0x20),extraout_s2_03,
                 extraout_s3_03,false);
        this->field_0x154 = 0;
        return;
    }
    Harmonic::SetHarmonics(this_01,(float *)&DAT_000ce904);
    uVar2 = Harmonic::SetHarmonics(this_00,(float *)&DAT_000ce904);
    *(undefined4 *)&this->field_0x150 = 0x4ccbfb1;
    uVar2 = MultiBiquad::RefreshFilter
            (&this->field_0xc0,0,(float)uVar2,(float)((ulonglong)uVar2 >> 0x20),
             extraout_s2_04,extraout_s3_04,false);
    MultiBiquad::RefreshFilter
            (&this->field_0xe4,0,(float)uVar2,(float)((ulonglong)uVar2 >> 0x20),extraout_s2_05,
             extraout_s3_05,false);
    this->field_0x154 = 0;
    return;
}



// AnalogX::AnalogX()

AnalogX::AnalogX() {
    MultiBiquad::MultiBiquad((MultiBiquad *)this);
    MultiBiquad::MultiBiquad(&this->field_0x24);
    Harmonic::Harmonic(&this->field_0x48);
    Harmonic::Harmonic(&this->field_0x84);
    MultiBiquad::MultiBiquad(&this->field_0xc0);
    MultiBiquad::MultiBiquad(&this->field_0xe4);
    MultiBiquad::MultiBiquad(&this->field_0x108);
    MultiBiquad::MultiBiquad(&this->field_0x12c);
    this->samplerate = 0xac44;
    this->processingModel = 0;
    this->enabled = false;
    Reset(this);
    return this;
}



// AnalogX::SetSamplingRate(unsigned int)

void AnalogX::SetSamplingRate(uint param_1) {
    if (this->samplerate == param_1) {
        return;
    }
    this->samplerate = param_1;
    Reset(this);
    return;
}



// AnalogX::SetProcessingModel(int)

void AnalogX::SetProcessingModel(int param_1) {
    if (this->processingModel == param_1) {
        return;
    }
    this->processingModel = param_1;
    Reset(this);
    return;
}



// AnalogX::Process(int*, int)

void AnalogX::Process(int *param_1,int param_2) {
    ulonglong uVar1;
    longlong lVar2;
    int iVar3;
    int *piVar4;
    int iVar5;
    int iVar6;
    undefined8 uVar7;
    int local_58;

    if (this->enabled != false) {
        if (0 < param_2 * 2) {
            iVar5 = 0;
            piVar4 = param_1;
            do {
                iVar6 = *piVar4;
                iVar5 = iVar5 + 2;
                iVar3 = MultiBiquad::ProcessSample((MultiBiquad *)this,iVar6);
                iVar3 = Harmonic::Process(&this->field_0x48,iVar3);
                uVar1 = (longlong)iVar3 * (longlong)*(int *)&this->field_0x150 + 0x1000000;
                uVar7 = VectorShiftRight((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff),0x19);
                local_58 = (int)uVar7;
                iVar3 = MultiBiquad::ProcessSample(&this->field_0xc0,iVar6 + local_58);
                lVar2 = (longlong)iVar3 * 0x1998c7e + 0x1000000;
                iVar3 = MultiBiquad::ProcessSample
                        (&this->field_0x108,
                         (uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
                iVar6 = piVar4[1];
                *piVar4 = iVar3;
                iVar3 = MultiBiquad::ProcessSample(&this->field_0x24,iVar6);
                iVar3 = Harmonic::Process(&this->field_0x84,iVar3);
                uVar1 = (longlong)iVar3 * (longlong)*(int *)&this->field_0x150 + 0x1000000;
                uVar7 = VectorShiftRight((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff),0x19);
                local_58 = (int)uVar7;
                iVar3 = MultiBiquad::ProcessSample(&this->field_0xe4,iVar6 + local_58);
                lVar2 = (longlong)iVar3 * 0x1998c7e + 0x1000000;
                iVar3 = MultiBiquad::ProcessSample
                        (&this->field_0x12c,
                         (uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
                piVar4[1] = iVar3;
                piVar4 = piVar4 + 2;
            } while (iVar5 + param_2 * -2 < 0 != SBORROW4(iVar5,param_2 * 2));
        }
        if (this->field_0x154 < (int)((uint)this->samplerate >> 2)) {
            this->field_0x154 = param_2 + this->field_0x154;
            memset(param_1,0,param_2 << 3);
            return;
        }
    }
    return;
}
