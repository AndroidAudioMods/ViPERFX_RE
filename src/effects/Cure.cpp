//
// Created by mart on 2/13/21.
//

#include "Cure.h"

// Cure::~Cure()

Cure::~Cure() {
    PassFilter::~PassFilter(&this->field_0x38);
    Crossfeed::~Crossfeed((Crossfeed *)this);
    return this;
}



// Cure::Reset()

void Cure::Reset() {
    Crossfeed::Reset((Crossfeed *)this);
    PassFilter::Reset();
    return;
}



// Cure::Cure()

Cure::Cure() {
    Crossfeed::Crossfeed((Crossfeed *)this);
    PassFilter::PassFilter(&this->field_0x38);
    this->enabled = false;
    Reset(this);
    return this;
}



// Cure::SetEnable(bool)

undefined4 Cure::SetEnable(bool param_1) {
    if (this->enabled != param_1) {
        Reset(this);
        this->enabled = param_1;
        return 1;
    }
    return 0;
}



// Cure::SetSamplingRate(int)

void Cure::SetSamplingRate(int param_1) {
    Crossfeed::SetSamplingRate((Crossfeed *)this,param_1);
    PassFilter::SetSamplingRate(&this->field_0x38,param_1);
    return;
}


void Cure::~ZN4Cure9SetCutoffEi(int param_1) {
    SetPreset(this,param_1 | (uint)(ushort)this->feedback << 0x10);
    return;
}



void Cure::~ZN4Cure11SetFeedbackEf(float param_1) {
    undefined4 in_cr7;

    coprocessor_function(10,6,1,in_cr7,in_cr7,in_cr7);
    SetPreset(this,(uint)(ushort)this->cutoff);
    return;
}



void Cure::~ZN4Cure9SetPresetEj(uint param_1) {
    *(uint *)&this->cutoff = param_1;
    Reset(this);
    return;
}



short Cure::~ZN4Cure9GetCutoffEv() {
    return this->cutoff;
}



float Cure::~ZN4Cure11GetFeedbackEv() {
    return (float)(longlong)(int)(uint)(ushort)this->feedback / 10.0;
}



float Cure::~ZN4Cure13GetLevelDelayEv() {
    int iVar1;
    undefined4 in_cr7;
    float fVar2;

    iVar1 = GetCutoff(this);
    if (iVar1 - 300U < 0x6a5) {
        fVar2 = 18700.0 / (float)(longlong)iVar1;
        coprocessor_function(10,6,4,in_cr7,in_cr7,in_cr7);
    }
    else {
        fVar2 = 0.0;
    }
    return fVar2;
}



undefined4 Cure::~ZN4Cure9GetPresetEv() {
    return *(undefined4 *)&this->cutoff;
}



// Cure::Process(int*, int)

void Cure::Process(int *param_1,int param_2) {
    if (this->enabled == false) {
        return;
    }
    Crossfeed::ProcessFrames((Crossfeed *)this,param_1,param_2);
    PassFilter::ProcessFrames(&this->field_0x38,param_1,param_2);
    return;
}
