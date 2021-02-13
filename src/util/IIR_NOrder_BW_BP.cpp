//
// Created by mart on 2/12/21.
//

#include "IIR_NOrder_BW_BP.h"

// IIR_NOrder_BW_BP::IIR_NOrder_BW_BP(int)

IIR_NOrder_BW_BP::IIR_NOrder_BW_BP(int param_1) {
    int iVar1;
    uint uVar2;
    IIR_1st *pIVar3;
    void *pvVar4;
    IIR_1st *pIVar5;
    int iVar6;
    uint uVar7;

    *(undefined4 *)this = 0;
    *(undefined4 *)(this + 4) = 0;
    *(undefined4 *)(this + 8) = 0;
    if (0 < param_1) {
        uVar7 = param_1 - 1;
        if ((uint)param_1 < 0x7f00001) {
            uVar2 = param_1 * 0x10;
        }
        else {
            uVar2 = 0xffffffff;
        }
        pIVar3 = (IIR_1st *)operator_new__(uVar2);
        uVar2 = uVar7;
        pIVar5 = pIVar3;
        do {
            uVar2 = uVar2 - 1;
            IIR_1st::IIR_1st(pIVar5);
            pIVar5 = pIVar5 + 1;
        } while (uVar2 != 0xffffffff);
        *(IIR_1st **)this = pIVar3;
        if ((uint)param_1 < 0x7f00001) {
            uVar2 = param_1 * 0x10;
        }
        pIVar3 = (IIR_1st *)operator_new__(uVar2);
        pIVar5 = pIVar3;
        do {
            uVar7 = uVar7 - 1;
            IIR_1st::IIR_1st(pIVar5);
            pIVar5 = pIVar5 + 1;
        } while (uVar7 != 0xffffffff);
        pvVar4 = *(void **)this;
        *(IIR_1st **)(this + 4) = pIVar3;
        if (pvVar4 != nullptr) {
            if (pIVar3 != nullptr) {
                iVar6 = 0;
                while( true ) {
                    iVar1 = iVar6 * 0x10;
                    iVar6 = iVar6 + 1;
                    IIR_1st::Mute((IIR_1st *)((int)pvVar4 + iVar1));
                    IIR_1st::Mute((IIR_1st *)(*(int *)(this + 4) + iVar1));
                    if (iVar6 == param_1) break;
                    pvVar4 = *(void **)this;
                }
                *(int *)(this + 8) = iVar6;
                return this;
            }
            operator_delete__(pvVar4);
            pIVar3 = *(IIR_1st **)(this + 4);
        }
        if (pIVar3 != nullptr) {
            operator_delete__(pIVar3);
            return this;
        }
    }
    return this;
}



// IIR_NOrder_BW_BP::~IIR_NOrder_BW_BP()

IIR_NOrder_BW_BP::~IIR_NOrder_BW_BP() {
    if (*(void **)this != nullptr) {
        operator_delete__(*(void **)this);
    }
    if (*(void **)(this + 4) != nullptr) {
        operator_delete__(*(void **)(this + 4));
    }
    return this;
}



// IIR_NOrder_BW_BP::Mute()

void IIR_NOrder_BW_BP::Mute() {
    int iVar1;
    int iVar2;
    int iVar3;

    iVar2 = *(int *)this;
    if ((iVar2 != 0) && (0 < *(int *)(this + 8))) {
        iVar3 = 0;
        while( true ) {
            iVar1 = iVar3 * 0x10;
            iVar3 = iVar3 + 1;
            IIR_1st::Mute((IIR_1st *)(iVar2 + iVar1));
            if (*(int *)(this + 8) <= iVar3) break;
            iVar2 = *(int *)this;
        }
    }
    iVar2 = *(int *)(this + 4);
    if (iVar2 == 0) {
        return;
    }
    if (*(int *)(this + 8) < 1) {
        return;
    }
    iVar3 = 0;
    while( true ) {
        iVar1 = iVar3 * 0x10;
        iVar3 = iVar3 + 1;
        IIR_1st::Mute((IIR_1st *)(iVar2 + iVar1));
        if (*(int *)(this + 8) <= iVar3) break;
        iVar2 = *(int *)(this + 4);
    }
    return;
}



// IIR_NOrder_BW_BP::setBPF(float, float, float)

void IIR_NOrder_BW_BP::setBPF(float param_1,float param_2,float param_3) {
    int *in_r0;
    int iVar1;
    int iVar2;
    undefined8 uVar3;

    uVar3 = CONCAT44(param_2,param_1);
    iVar1 = *in_r0;
    if ((iVar1 != 0) && (0 < in_r0[2])) {
        iVar2 = 0;
        while( true ) {
            uVar3 = IIR_1st::setLPF_BW((IIR_1st *)(iVar1 + iVar2 * 0x10),(float)uVar3,
                                       (float)((ulonglong)uVar3 >> 0x20));
            iVar2 = iVar2 + 1;
            if (in_r0[2] <= iVar2) break;
            iVar1 = *in_r0;
        }
    }
    iVar1 = in_r0[1];
    if (iVar1 == 0) {
        return;
    }
    if (in_r0[2] < 1) {
        return;
    }
    iVar2 = 0;
    while( true ) {
        uVar3 = IIR_1st::setHPF_BW((IIR_1st *)(iVar1 + iVar2 * 0x10),(float)uVar3,
                                   (float)((ulonglong)uVar3 >> 0x20));
        iVar2 = iVar2 + 1;
        if (in_r0[2] <= iVar2) break;
        iVar1 = in_r0[1];
    }
    return;
}
