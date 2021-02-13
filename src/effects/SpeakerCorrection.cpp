//
// Created by mart on 2/12/21.
//

#include "SpeakerCorrection.h"

// SpeakerCorrection::Reset()

void SpeakerCorrection::Reset() {
    undefined8 uVar1;
    undefined8 extraout_d0;
    float extraout_s2;
    float extraout_s2_00;
    float extraout_s2_01;
    float extraout_s2_02;
    float extraout_s3;
    float extraout_s3_00;

    FixedBiquad::Reset(&this->field_0x50);
    FixedBiquad::Reset(&this->field_0x74);
    FixedBiquad::Reset(&this->field_0x98);
    uVar1 = FixedBiquad::Reset(&this->field_0xbc);
    uVar1 = MultiBiquad::RefreshFilter
            (&this->field_0x8,1,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20),extraout_s2,
             extraout_s3,false);
    uVar1 = MultiBiquad::RefreshFilter
            (&this->field_0x2c,1,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20),
             extraout_s2_00,extraout_s3_00,false);
    FixedBiquad::SetLowPassParameter
            (&this->field_0x50,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20),extraout_s2_01);
    FixedBiquad::SetLowPassParameter
            (&this->field_0x74,(float)extraout_d0,(float)((ulonglong)extraout_d0 >> 0x20),
             extraout_s2_02);
    FixedBiquad::SetBandPassParameter
    (&this->field_0x98,0x43d20000,(int)(float)(ulonglong)this->samplerate,0x407851ec);
    FixedBiquad::SetBandPassParameter
    (&this->field_0xbc,0x43d20000,(int)(float)(ulonglong)this->samplerate,0x407851ec);
    return;
}



// SpeakerCorrection::SpeakerCorrection()

SpeakerCorrection::SpeakerCorrection() {
    MultiBiquad::MultiBiquad(&this->field_0x8);
    MultiBiquad::MultiBiquad(&this->field_0x2c);
    FixedBiquad::FixedBiquad(&this->field_0x50);
    FixedBiquad::FixedBiquad(&this->field_0x74);
    FixedBiquad::FixedBiquad(&this->field_0x98);
    FixedBiquad::FixedBiquad(&this->field_0xbc);
    this->samplerate = 0xac44;
    this->enabled = false;
    Reset(this);
    return this;
}



// SpeakerCorrection::SetEnable(bool)

undefined4 SpeakerCorrection::SetEnable(bool param_1) {
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



// SpeakerCorrection::SetSamplingRate(unsigned int)

void SpeakerCorrection::SetSamplingRate(uint param_1) {
    if (this->samplerate == param_1) {
        return;
    }
    this->samplerate = param_1;
    Reset(this);
    return;
}



// SpeakerCorrection::Process(int*, int)

void SpeakerCorrection::Process(int *param_1,int param_2) {
    longlong lVar1;
    int iVar2;
    uint uVar3;
    int iVar4;

    if ((this->enabled != false) && (0 < param_2 * 2)) {
        iVar4 = 0;
        do {
            iVar2 = FixedBiquad::ProcessSample(&this->field_0x50,*param_1);
            iVar2 = MultiBiquad::ProcessSample(&this->field_0x8,iVar2);
            lVar1 = (longlong)iVar2 * 0x1000000 + 0x1000000;
            iVar4 = iVar4 + 2;
            uVar3 = (uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7;
            iVar2 = FixedBiquad::ProcessSample(&this->field_0x98,uVar3);
            *param_1 = iVar2 + uVar3;
            iVar2 = FixedBiquad::ProcessSample(&this->field_0x74,param_1[1]);
            iVar2 = MultiBiquad::ProcessSample(&this->field_0x2c,iVar2);
            lVar1 = (longlong)iVar2 * 0x1000000 + 0x1000000;
            uVar3 = (uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7;
            iVar2 = FixedBiquad::ProcessSample(&this->field_0xbc,uVar3);
            param_1[1] = iVar2 + uVar3;
            param_1 = param_1 + 2;
        } while (iVar4 + param_2 * -2 < 0 != SBORROW4(iVar4,param_2 * 2));
    }
    return;
}
