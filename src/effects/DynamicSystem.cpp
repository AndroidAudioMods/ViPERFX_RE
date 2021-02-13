//
// Created by mart on 2/12/21.
//

#include "DynamicSystem.h"

// DynamicSystem::DynamicSystem()

DynamicSystem::DynamicSystem() {
    DynamicBass::DynamicBass((DynamicBass *)this);
    this->enabled = false;
    this->samplerate = 0xac44;
    DynamicBass::SetSamplingRate((DynamicBass *)this,0xac44);
    DynamicBass::Reset((DynamicBass *)this);
    return this;
}



// DynamicSystem::SetSamplingRate(unsigned int)

void DynamicSystem::SetSamplingRate(uint param_1) {
    if (this->samplerate == param_1) {
        return;
    }
    this->samplerate = param_1;
    DynamicBass::SetSamplingRate((DynamicBass *)this,param_1);
    return;
}



void DynamicSystem::~ZN13DynamicSystem10SetXCoeffsEjj(int param_1,int param_2) {
    undefined8 uVar1;
    float extraout_s2;

    this->field_0x0 = param_1;
    this->field_0x4 = param_2;
    PolesFilter::SetPassFilter(&this->field_0x24,param_1,param_2);
    uVar1 = PolesFilter::SetSamplingRate(&this->field_0x24,this->field_0x10);
    FixedBiquad::SetLowPassParameter
            (&this->field_0x10c,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20),extraout_s2);
    return;
}



void DynamicSystem::~ZN13DynamicSystem10SetYCoeffsEjj(int param_1,int param_2) {
    this->field_0x8 = param_1;
    this->field_0xc = param_2;
    PolesFilter::SetPassFilter(&this->field_0x98,param_1,param_2);
    PolesFilter::SetSamplingRate(&this->field_0x98,this->field_0x10);
    return;
}



void DynamicSystem::~ZN13DynamicSystem11SetSideGainEff(int param_1,int param_2) {
    this->field_0x20 = ROUND((float)param_1 * 3.355443e+07 + 0.5);
    this->field_0x1c = ROUND((float)param_2 * 3.355443e+07 + 0.5);
    return;
}



void DynamicSystem::~ZN13DynamicSystem11SetBassGainEf(int param_1) {
    int iVar1;
    undefined4 in_cr6;
    undefined4 in_cr7;
    float in_s0;
    float in_s1;
    float in_s2;
    float fVar2;

    fVar2 = ROUND((float)param_1 * 3.355443e+07 + 0.5);
    coprocessor_function(10,6,1,in_cr7,in_cr6,in_cr6);
    this->field_0x18 = fVar2;
    iVar1 = (int)SUB42(ROUND(fVar2),0);
    if (iVar1 < 0x641) {
        this->field_0x14 = iVar1;
    }
    else {
        this->field_0x14 = 0x640;
    }
    FixedBiquad::SetLowPassParameter(&this->field_0x10c,in_s0,in_s1,in_s2);
    return;
}



// DynamicSystem::Reset()

void DynamicSystem::Reset() {
    DynamicBass::SetSamplingRate((DynamicBass *)this,this->samplerate);
    DynamicBass::Reset((DynamicBass *)this);
    return;
}



// DynamicSystem::SetEnable(bool)

undefined4 DynamicSystem::SetEnable(bool param_1) {
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



// DynamicSystem::Process(int*, int)

void DynamicSystem::Process(int *param_1,int param_2) {
    if (this->enabled == false) {
        return;
    }
    DynamicBass::FilterSamples((DynamicBass *)this,param_1,param_2);
    return;
}
