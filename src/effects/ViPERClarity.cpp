//
// Created by mart on 2/13/21.
//

#include "ViPERClarity.h"

// ViPERClarity::~ViPERClarity()

ViPERClarity::~ViPERClarity() {
    HiFi::~HiFi((HiFi *)&this->field_0xa8);
    return this;
}



// ViPERClarity::SetClarityToFilter()

void ViPERClarity::SetClarityToFilter(void) {
    NoiseSharpening *in_r0;
    float in_s0;
    float fVar1;

    fVar1 = (float)NoiseSharpening::SetGain(in_r0,in_s0);
    fVar1 = (float)HighShelf::SetGain(fVar1);
    fVar1 = (float)HighShelf::SetGain(fVar1);
    HiFi::SetClarity((HiFi *)(in_r0 + 0xa8),fVar1);
    return;
}



// ViPERClarity::Reset()

void ViPERClarity::Reset() {
    HighShelf *this_00;
    HighShelf *this_01;
    float fVar1;

    this_01 = (HighShelf *)&this->field_0x30;
    NoiseSharpening::SetSamplingRate((NoiseSharpening *)this,*(int *)&this->field_0xd8);
    NoiseSharpening::Reset();
    this_00 = (HighShelf *)&this->field_0x6c;
    fVar1 = (float)SetClarityToFilter();
    fVar1 = (float)HighShelf::SetFrequency(this_01,fVar1);
    HighShelf::SetQuality(this_01,fVar1);
    fVar1 = (float)HighShelf::SetSamplingRate(this_01,*(int *)&this->field_0xd8);
    fVar1 = (float)HighShelf::SetFrequency(this_00,fVar1);
    HighShelf::SetQuality(this_00,fVar1);
    HighShelf::SetSamplingRate(this_00,*(int *)&this->field_0xd8);
    HiFi::SetSamplingRate((HiFi *)&this->field_0xa8,*(int *)&this->field_0xd8);
    HiFi::Reset();
    return;
}



// ViPERClarity::ViPERClarity()

ViPERClarity::ViPERClarity() {
    HighShelf *this_00;
    HiFi *this_01;
    float fVar1;

    fVar1 = (float)NoiseSharpening::NoiseSharpening((NoiseSharpening *)this);
    this_00 = (HighShelf *)&this->field_0x30;
    do {
        fVar1 = (float)HighShelf::SetFrequency(this_00,fVar1);
        fVar1 = (float)HighShelf::SetQuality(this_00,fVar1);
        HighShelf::SetGain(fVar1);
        this_01 = (HiFi *)(this_00 + 0x3c);
        fVar1 = (float)HighShelf::SetSamplingRate(this_00,0xac44);
        this_00 = (HighShelf *)this_01;
    } while (this_01 != (HiFi *)&this->field_0xa8);
    HiFi::HiFi(this_01);
    *(undefined *)&this->field_0xd0 = 0;
    *(undefined4 *)&this->field_0xd4 = 0;
    *(undefined4 *)&this->field_0xdc = 0;
    *(undefined4 *)&this->field_0xd8 = 0xac44;
    Reset(this);
    return this;
}



// ViPERClarity::SetEnable(bool)

undefined4 ViPERClarity::SetEnable(bool param_1) {
    char cVar1;

    cVar1 = *(char *)&this->field_0xd0;
    if (cVar1 == '\0') {
        if (param_1 == false) {
            return 0;
        }
        Reset(this);
        cVar1 = *(char *)&this->field_0xd0;
    }
    if (param_1 == (bool)cVar1) {
        return 0;
    }
    *(bool *)&this->field_0xd0 = param_1;
    return 1;
}



// ViPERClarity::SetSamplingRate(int)

void ViPERClarity::SetSamplingRate(int param_1) {
    if (*(int *)&this->field_0xd8 == param_1) {
        return;
    }
    *(int *)&this->field_0xd8 = param_1;
    Reset(this);
    return;
}



// ViPERClarity::SetProcessMode(int)

void ViPERClarity::SetProcessMode(int param_1) {
    if (2 < (uint)param_1) {
        return;
    }
    if (*(int *)&this->field_0xd4 == param_1) {
        return;
    }
    *(int *)&this->field_0xd4 = param_1;
    Reset(this);
    return;
}



// ViPERClarity::SetClarity(float)

void ViPERClarity::SetClarity(float param_1) {
    undefined4 in_r1;

    *(undefined4 *)&this->field_0xdc = in_r1;
    if (*(int *)&this->field_0xd4 != 1) {
        SetClarityToFilter();
        return;
    }
    Reset(this);
    return;
}



// ViPERClarity::Process(int*, int)

int ViPERClarity::Process(int *param_1,int param_2) {
    int iVar1;
    int *piVar2;
    int iVar3;

    if (*(char *)&this->field_0xd0 != '\0') {
        if (*(int *)&this->field_0xd4 == 0) {
            NoiseSharpening::Process((NoiseSharpening *)this,param_1,param_2);
            return param_2;
        }
        if (*(int *)&this->field_0xd4 != 1) {
            iVar3 = HiFi::Process((HiFi *)&this->field_0xa8,param_1,param_2);
            return iVar3;
        }
        if (0 < param_2 * 2) {
            piVar2 = param_1 + 1;
            iVar3 = 0;
            do {
                iVar1 = HighShelf::Process((HighShelf *)&this->field_0x30,piVar2[-1]);
                iVar3 = iVar3 + 2;
                piVar2[-1] = iVar1;
                iVar1 = HighShelf::Process((HighShelf *)&this->field_0x6c,param_1[1]);
                param_1[1] = iVar1;
                piVar2 = piVar2 + 2;
                param_1 = param_1 + 2;
            } while (iVar3 < param_2 * 2);
        }
    }
    return param_2;
}
