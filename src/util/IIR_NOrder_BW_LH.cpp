//
// Created by mart on 2/12/21.
//

#include "IIR_NOrder_BW_LH.h"

// IIR_NOrder_BW_LH::IIR_NOrder_BW_LH(int)

IIR_NOrder_BW_LH::IIR_NOrder_BW_LH(int param_1) {
    uint uVar1;
    IIR_1st *pIVar2;
    IIR_1st *this_00;
    int iVar3;

    this->field_0x0 = nullptr;
    this->field_0x4 = 0;
    if (0 < param_1) {
        iVar3 = param_1 + -1;
        if ((uint)param_1 < 0x7f00001) {
            uVar1 = param_1 * 0x10;
        }
        else {
            uVar1 = 0xffffffff;
        }
        pIVar2 = (IIR_1st *)operator_new__(uVar1);
        this_00 = pIVar2;
        do {
            iVar3 = iVar3 + -1;
            IIR_1st::IIR_1st(this_00);
            this_00 = this_00 + 1;
        } while (iVar3 != -1);
        this->field_0x0 = pIVar2;
        if (pIVar2 != nullptr) {
            iVar3 = 0;
            while( true ) {
                pIVar2 = pIVar2 + iVar3;
                iVar3 = iVar3 + 1;
                IIR_1st::Mute(pIVar2);
                if (iVar3 == param_1) break;
                pIVar2 = this->field_0x0;
            }
            this->field_0x4 = iVar3;
        }
    }
    return this;
}



// IIR_NOrder_BW_LH::~IIR_NOrder_BW_LH()

IIR_NOrder_BW_LH::~IIR_NOrder_BW_LH() {
    if (this->field_0x0 != nullptr) {
        operator_delete__(this->field_0x0);
    }
    return this;
}



// IIR_NOrder_BW_LH::Mute()

void IIR_NOrder_BW_LH::Mute() {
    IIR_1st *pIVar1;
    int iVar2;

    pIVar1 = this->field_0x0;
    if (pIVar1 == nullptr) {
        return;
    }
    if (this->field_0x4 < 1) {
        return;
    }
    iVar2 = 0;
    while( true ) {
        pIVar1 = pIVar1 + iVar2;
        iVar2 = iVar2 + 1;
        IIR_1st::Mute(pIVar1);
        if (this->field_0x4 <= iVar2) break;
        pIVar1 = this->field_0x0;
    }
    return;
}



// IIR_NOrder_BW_LH::setLPF(float, float)

void IIR_NOrder_BW_LH::setLPF(float param_1,float param_2) {
    IIR_1st *pIVar1;
    int iVar2;
    undefined8 uVar3;

    uVar3 = CONCAT44(param_2,param_1);
    pIVar1 = this->field_0x0;
    if (pIVar1 == nullptr) {
        return;
    }
    if (this->field_0x4 < 1) {
        return;
    }
    iVar2 = 0;
    while( true ) {
        uVar3 = IIR_1st::setLPF_BW(pIVar1 + iVar2,(float)uVar3,(float)((ulonglong)uVar3 >> 0x20));
        iVar2 = iVar2 + 1;
        if (this->field_0x4 <= iVar2) break;
        pIVar1 = this->field_0x0;
    }
    return;
}



// IIR_NOrder_BW_LH::setHPF(float, float)

void IIR_NOrder_BW_LH::setHPF(float param_1,float param_2) {
    IIR_1st *pIVar1;
    int iVar2;
    undefined8 uVar3;

    uVar3 = CONCAT44(param_2,param_1);
    pIVar1 = this->field_0x0;
    if (pIVar1 == nullptr) {
        return;
    }
    if (this->field_0x4 < 1) {
        return;
    }
    iVar2 = 0;
    while( true ) {
        uVar3 = IIR_1st::setHPF_BW(pIVar1 + iVar2,(float)uVar3,(float)((ulonglong)uVar3 >> 0x20));
        iVar2 = iVar2 + 1;
        if (this->field_0x4 <= iVar2) break;
        pIVar1 = this->field_0x0;
    }
    return;
}
