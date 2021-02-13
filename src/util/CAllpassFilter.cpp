//
// Created by mart on 2/12/21.
//

#include "CAllpassFilter.h"


// CAllpassFilter::CAllpassFilter()

CAllpassFilter::CAllpassFilter() {
    this->field_0x4 = 0;
    this->field_0x8 = 0;
    this->field_0xc = 0;
    this->feedback = 0;
    return;
}



// CAllpassFilter::SetBuffer(int*, int)

void CAllpassFilter::SetBuffer(int *param_1,int param_2) {
    this->field_0x4 = param_1;
    this->field_0x8 = param_2;
    return;
}



// CAllpassFilter::Process(int)

int CAllpassFilter::Process(int param_1) {
    longlong lVar1;
    int iVar2;
    int iVar3;

    iVar3 = *(int *)(this->field_0x4 + this->field_0xc * 4);
    lVar1 = (longlong)iVar3 * (longlong)(int)this->feedback + 0x1000000;
    *(uint *)(this->field_0x4 + this->field_0xc * 4) =
            param_1 + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
    iVar2 = this->field_0xc + 1;
    this->field_0xc = iVar2;
    if ((int)this->field_0x8 <= iVar2) {
        this->field_0xc = 0;
    }
    return iVar3 - param_1;
}



// CAllpassFilter::Mute()

void CAllpassFilter::Mute() {
    undefined4 *puVar1;
    int iVar2;

    if ((int)this->field_0x8 < 1) {
        return;
    }
    iVar2 = 0;
    puVar1 = (undefined4 *)(this->field_0x4 + -4);
    do {
        puVar1 = puVar1 + 1;
        *puVar1 = 0;
        iVar2 = iVar2 + 1;
    } while (iVar2 < (int)this->field_0x8);
    return;
}



// CAllpassFilter::SetFeedback(int)

void CAllpassFilter::SetFeedback(int param_1) {
    this->feedback = param_1;
    return;
}



// CAllpassFilter::GetFeedback()

undefined4 CAllpassFilter::GetFeedback() {
    return this->feedback;
}
