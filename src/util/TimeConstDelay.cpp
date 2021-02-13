//
// Created by mart on 2/12/21.
//

#include "TimeConstDelay.h"

// TimeConstDelay::TimeConstDelay()

TimeConstDelay::TimeConstDelay() {
    *(undefined4 *)this = 0;
    *(undefined4 *)(this + 4) = 0;
    *(undefined4 *)(this + 8) = 0;
    return;
}



// TimeConstDelay::~TimeConstDelay()

TimeConstDelay::~TimeConstDelay() {
    if (*(void **)this != nullptr) {
        operator_delete__(*(void **)this);
        *(undefined4 *)this = 0;
    }
    return this;
}



// TimeConstDelay::SetParameters(unsigned int, float)

void TimeConstDelay::SetParameters(uint param_1,float param_2) {
    uint uVar1;
    void *__s;
    float in_r2;
    float fVar2;

    fVar2 = ROUND((float)(ulonglong)param_1 * in_r2 + 0.5);
    *(float *)(this + 8) = fVar2;
    if (*(void **)this != nullptr) {
        operator_delete__(*(void **)this);
        fVar2 = *(float *)(this + 8);
    }
    if ((uint)fVar2 < 0x1fc00001) {
        uVar1 = (int)fVar2 << 2;
    }
    else {
        uVar1 = 0xffffffff;
    }
    __s = operator_new__(uVar1);
    *(void **)this = __s;
    memset(__s,0,*(int *)(this + 8) << 2);
    *(undefined4 *)(this + 4) = 0;
    return;
}



// TimeConstDelay::ProcessSample(int)

undefined4 TimeConstDelay::ProcessSample(int param_1) {
    undefined4 in_r1;
    undefined4 extraout_r1;
    int iVar1;
    undefined4 uVar2;

    iVar1 = *(int *)param_1;
    if (iVar1 != 0) {
        uVar2 = *(undefined4 *)(iVar1 + *(int *)(param_1 + 4) * 4);
        *(undefined4 *)(iVar1 + *(int *)(param_1 + 4) * 4) = in_r1;
        __aeabi_idivmod(*(int *)(param_1 + 4) + 1,*(undefined4 *)(param_1 + 8));
        *(undefined4 *)(param_1 + 4) = extraout_r1;
        return uVar2;
    }
    return 0;
}
