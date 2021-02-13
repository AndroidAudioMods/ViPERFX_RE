//
// Created by mart on 2/12/21.
//

#include "CCombFilter.h"


// CCombFilter::CCombFilter()

CCombFilter::CCombFilter() {
    this->field_0x10 = 0;
    this->field_0x14 = 0;
    this->field_0x18 = 0;
    this->feedback = 0;
    this->field_0x4 = 0;
    this->damp = 0;
    this->field_0xc = 0;
    return;
}



// CCombFilter::SetBuffer(int*, int)

void CCombFilter::SetBuffer(int *param_1,int param_2) {
    this->field_0x10 = (int)param_1;
    this->field_0x14 = param_2;
    return;
}



// CCombFilter::Process(int)

int CCombFilter::Process(int param_1) {
    longlong lVar1;
    longlong lVar2;
    int iVar3;
    int iVar4;

    iVar4 = *(int *)(this->field_0x10 + this->field_0x18 * 4);
    lVar1 = (longlong)iVar4 * (longlong)(int)this->field_0xc + 0x1000000;
    lVar2 = (longlong)(int)this->field_0x4 * (longlong)(int)this->damp + 0x1000000;
    iVar3 = ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) +
            ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
    this->field_0x4 = iVar3;
    lVar1 = (longlong)iVar3 * (longlong)(int)this->feedback + 0x1000000;
    *(uint *)(this->field_0x10 + this->field_0x18 * 4) =
            param_1 + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
    iVar3 = this->field_0x18 + 1;
    this->field_0x18 = iVar3;
    if (this->field_0x14 <= iVar3) {
        this->field_0x18 = 0;
    }
    return iVar4;
}



// CCombFilter::Mute()

void CCombFilter::Mute() {
    undefined4 *puVar1;
    int iVar2;

    if (this->field_0x14 < 1) {
        return;
    }
    iVar2 = 0;
    puVar1 = (undefined4 *)(this->field_0x10 + -4);
    do {
        puVar1 = puVar1 + 1;
        *puVar1 = 0;
        iVar2 = iVar2 + 1;
    } while (iVar2 < this->field_0x14);
    return;
}



// CCombFilter::SetDamp(int)

void CCombFilter::SetDamp(int param_1) {
    this->damp = param_1;
    this->field_0xc = 0x2000000 - param_1;
    return;
}



// CCombFilter::GetDamp()

undefined4 CCombFilter::GetDamp() {
    return this->damp;
}



// CCombFilter::SetFeedback(int)

void CCombFilter::SetFeedback(int param_1) {
    this->feedback = param_1;
    return;
}



// CCombFilter::GetFeedback()

undefined4 CCombFilter::GetFeedback() {
    return this->feedback;
}

