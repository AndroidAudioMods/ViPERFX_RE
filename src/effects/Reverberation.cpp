//
// Created by mart on 2/12/21.
//

#include "Reverberation.h"

// Reverberation::Reverberation()

Reverberation::Reverberation() {
    CRevModel *this_00;

    this_00 = &this->field_0x14;
    CRevModel::CRevModel(this_00);
    this->roomSize = 0;
    this->width = 0.0;
    this->damp = 0.0;
    this->wet = 0.0;
    this->dry = 0.5;
    CRevModel::SetRoomSize(this_00,0);
    CRevModel::SetWidth(this_00,(int)ROUND(this->width * 3.355443e+07 + 0.5));
    CRevModel::SetDamp(this_00,(int)ROUND(this->damp * 3.355443e+07 + 0.5));
    CRevModel::SetWet(this_00,(int)ROUND(this->wet * 3.355443e+07 + 0.5));
    CRevModel::SetDry(this_00,(int)ROUND(this->dry * 3.355443e+07 + 0.5));
    CRevModel::~ZN9CRevModel5ResetEv(this_00);
    this->samplerate = 0xac44;
    this->enabled = false;
    return this;
}



// Reverberation::SetSamplingRate(unsigned int)

void Reverberation::SetSamplingRate(uint param_1) {
    if (this->samplerate == param_1) {
        return;
    }
    this->samplerate = param_1;
    CRevModel::~ZN9CRevModel5ResetEv(&this->field_0x14);
    return;
}



// Reverberation::SetRoomSize(float)

void Reverberation::SetRoomSize(int param_1) {
    this->roomSize = param_1;
    CRevModel::SetRoomSize(&this->field_0x14,(int)ROUND((float)param_1 * 3.355443e+07 + 0.5));
    return;
}



// Reverberation::SetWidth(float)

void Reverberation::SetWidth(int param_1) {
    this->width = (float)param_1;
    CRevModel::SetWidth(&this->field_0x14,(int)ROUND((float)param_1 * 3.355443e+07 + 0.5));
    return;
}



// Reverberation::SetDamp(float)

void Reverberation::SetDamp(int param_1) {
    this->damp = (float)param_1;
    CRevModel::SetDamp(&this->field_0x14,(int)ROUND((float)param_1 * 3.355443e+07 + 0.5));
    return;
}



// Reverberation::SetWet(float)

void Reverberation::SetWet(int param_1) {
    this->wet = (float)param_1;
    CRevModel::SetWet(&this->field_0x14,(int)ROUND((float)param_1 * 3.355443e+07 + 0.5));
    return;
}



// Reverberation::SetDry(float)

void Reverberation::SetDry(int param_1) {
    this->dry = (float)param_1;
    CRevModel::SetDry(&this->field_0x14,(int)ROUND((float)param_1 * 3.355443e+07 + 0.5));
    return;
}



// Reverberation::Reset()

void Reverberation::Reset() {
    CRevModel::~ZN9CRevModel5ResetEv(&this->field_0x14);
    return;
}



// Reverberation::SetEnable(bool)

undefined4 Reverberation::SetEnable(bool param_1) {
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



// Reverberation::Process(int*, int)

void Reverberation::Process(int *param_1,int param_2) {
    if (this->enabled == false) {
        return;
    }
    CRevModel::ProcessReplace(&this->field_0x14,param_1,param_1 + 1,param_2);
    return;
}
