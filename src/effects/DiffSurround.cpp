//
// Created by mart on 2/12/21.
//

#include "DiffSurround.h"


// DiffSurround::~DiffSurround()

DiffSurround::~DiffSurround() {
    WaveBuffer_I32 *pWVar1;

    pWVar1 = *(WaveBuffer_I32 **)&this->field_0xc;
    *(undefined4 *)&this->field_0x8 = 0;
    if (pWVar1 != nullptr) {
        WaveBuffer_I32::~WaveBuffer_I32(pWVar1);
        operator_delete(pWVar1);
    }
    pWVar1 = *(WaveBuffer_I32 **)&this->field_0x10;
    *(undefined4 *)&this->field_0xc = 0;
    if (pWVar1 != nullptr) {
        WaveBuffer_I32::~WaveBuffer_I32(pWVar1);
        operator_delete(pWVar1);
    }
    *(undefined4 *)&this->field_0x10 = 0;
    return this;
}



// DiffSurround::Reset()

void DiffSurround::Reset() {
    undefined4 in_cr0;
    undefined4 in_cr1;

    if (*(WaveBuffer_I32 **)&this->field_0xc == nullptr) {
        return;
    }
    if (*(int *)&this->field_0x10 == 0) {
        return;
    }
    WaveBuffer_I32::Reset(*(WaveBuffer_I32 **)&this->field_0xc);
    WaveBuffer_I32::Reset(*(WaveBuffer_I32 **)&this->field_0x10);
    coprocessor_function(0xb,6,5,in_cr0,in_cr1,in_cr0);
    WaveBuffer_I32::PushZeros
    (*(WaveBuffer_I32 **)&this->field_0x10,SUB84(ROUND((double)(ulonglong)*(uint *)this),0))
    ;
    return;
}



// DiffSurround::DiffSurround()

DiffSurround::DiffSurround() {
    WaveBuffer_I32 *pWVar1;

    *(undefined4 *)this = 0xac44;
    *(undefined4 *)&this->field_0x8 = 0;
    *(undefined *)&this->field_0x4 = 0;
    pWVar1 = (WaveBuffer_I32 *)operator_new(0x20);
    WaveBuffer_I32::WaveBuffer_I32(pWVar1,1,0x1000);
    *(WaveBuffer_I32 **)&this->field_0xc = pWVar1;
    pWVar1 = (WaveBuffer_I32 *)operator_new(0x20);
    WaveBuffer_I32::WaveBuffer_I32(pWVar1,1,0x1000);
    *(WaveBuffer_I32 **)&this->field_0x10 = pWVar1;
    Reset(this);
    return this;
}



// DiffSurround::SetEnable(bool)

undefined4 DiffSurround::SetEnable(bool param_1) {
    char cVar1;

    cVar1 = *(char *)&this->field_0x4;
    if (cVar1 == '\0') {
        if (param_1 == false) {
            return 0;
        }
        Reset(this);
        cVar1 = *(char *)&this->field_0x4;
    }
    if (param_1 == (bool)cVar1) {
        return 0;
    }
    *(bool *)&this->field_0x4 = param_1;
    return 1;
}



// DiffSurround::SetSamplingRate(unsigned int)

void DiffSurround::SetSamplingRate(uint param_1) {
    if (*(uint *)this == param_1) {
        return;
    }
    *(uint *)this = param_1;
    Reset(this);
    return;
}



// DiffSurround::SetDelayTime(float)

void DiffSurround::SetDelayTime(float param_1) {
    undefined4 in_r1;
    bool in_ZR;

    if (in_ZR) {
        return;
    }
    *(undefined4 *)&this->field_0x8 = in_r1;
    Reset(this);
    return;
}



// DiffSurround::Process(int*, int)

void DiffSurround::Process(int *param_1,int param_2) {
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int *piVar5;
    int *piVar6;

    if (*(char *)&this->field_0x4 == '\0') {
        return;
    }
    if (*(WaveBuffer_I32 **)&this->field_0xc == nullptr) {
        return;
    }
    if (*(int *)&this->field_0x10 == 0) {
        return;
    }
    iVar2 = WaveBuffer_I32::PushZerosGetBuffer(*(WaveBuffer_I32 **)&this->field_0xc,param_2);
    iVar3 = WaveBuffer_I32::PushZerosGetBuffer(*(WaveBuffer_I32 **)&this->field_0x10,param_2);
    if (iVar2 == 0 || iVar3 == 0) {
        Reset(this);
        return;
    }
    iVar4 = 0;
    iVar1 = param_2 * 2;
    if (iVar1 < 1) {
        WaveBuffer_I32::GetCurrentBufferI32Ptr(*(WaveBuffer_I32 **)&this->field_0xc);
        WaveBuffer_I32::GetCurrentBufferI32Ptr(*(WaveBuffer_I32 **)&this->field_0x10);
    }
    else {
        piVar5 = param_1;
        do {
            piVar6 = piVar5 + 2;
            *(int *)(iVar2 + iVar4) = *piVar5;
            *(int *)(iVar3 + iVar4) = piVar5[1];
            iVar4 = iVar4 + 4;
            piVar5 = piVar6;
        } while (piVar6 != param_1 + iVar1);
        iVar2 = WaveBuffer_I32::GetCurrentBufferI32Ptr(*(WaveBuffer_I32 **)&this->field_0xc);
        iVar3 = WaveBuffer_I32::GetCurrentBufferI32Ptr(*(WaveBuffer_I32 **)&this->field_0x10);
        iVar4 = 0;
        do {
            *param_1 = *(int *)(iVar2 + iVar4);
            piVar5 = (int *)(iVar3 + iVar4);
            iVar4 = iVar4 + 4;
            param_1[1] = *piVar5;
            param_1 = param_1 + 2;
        } while (iVar4 != ((iVar1 - 1U >> 1) + 1) * 4);
    }
    WaveBuffer_I32::PopSamples(*(WaveBuffer_I32 **)&this->field_0xc,param_2,false);
    WaveBuffer_I32::PopSamples(*(WaveBuffer_I32 **)&this->field_0x10,param_2,false);
    return;
}
