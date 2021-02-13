//
// Created by mart on 2/12/21.
//

#include "WaveBuffer_I32.h"


// WaveBuffer_I32::WaveBuffer_I32(unsigned int, unsigned int)

WaveBuffer_I32::WaveBuffer_I32(uint param_1,uint param_2) {
    void *pvVar1;

    *(uint *)(this + 0xc) = param_1;
    *(uint *)(this + 4) = param_2 * param_1;
    *(undefined4 *)(this + 8) = 0;
    pvVar1 = valloc(param_2 * param_1 * 4);
    *(void **)this = pvVar1;
    return this;
}



// WaveBuffer_I32::~WaveBuffer_I32()

WaveBuffer_I32::~WaveBuffer_I32() {
    if (*(void **)this != nullptr) {
        free(*(void **)this);
    }
    *(undefined4 *)this = 0;
    return this;
}



// WaveBuffer_I32::PushZerosGetBuffer(unsigned int)

void * WaveBuffer_I32::PushZerosGetBuffer(uint param_1) {
    uint uVar1;
    int iVar2;
    void *pvVar3;
    int iVar4;

    pvVar3 = *(void **)this;
    if (pvVar3 == nullptr) {
        return nullptr;
    }
    if (param_1 != 0) {
        iVar4 = *(int *)(this + 8);
        iVar2 = *(int *)(this + 0xc);
        uVar1 = iVar2 * param_1 + iVar4;
        if (*(uint *)(this + 4) < uVar1) {
            pvVar3 = valloc(uVar1 * 4);
            if (pvVar3 == nullptr) {
                return nullptr;
            }
            memcpy(pvVar3,*(void **)this,*(int *)(this + 8) << 2);
            free(*(void **)this);
            iVar4 = *(int *)(this + 8);
            iVar2 = *(int *)(this + 0xc);
            *(void **)this = pvVar3;
            *(uint *)(this + 4) = iVar2 * param_1 + iVar4;
        }
        pvVar3 = (void *)((int)pvVar3 + iVar4 * 4);
        memset(pvVar3,0,iVar2 * param_1 * 4);
        *(uint *)(this + 8) = *(int *)(this + 0xc) * param_1 + *(int *)(this + 8);
        return pvVar3;
    }
    return (void *)((int)pvVar3 + *(int *)(this + 8) * 4);
}



// WaveBuffer_I32::PushZeros(unsigned int)

undefined4 WaveBuffer_I32::PushZeros(uint param_1) {
    uint uVar1;
    int iVar2;
    int iVar3;
    void *__dest;

    __dest = *(void **)this;
    if (__dest == nullptr) {
        return 0;
    }
    if (param_1 != 0) {
        iVar2 = *(int *)(this + 8);
        iVar3 = *(int *)(this + 0xc);
        uVar1 = iVar3 * param_1 + iVar2;
        if (*(uint *)(this + 4) < uVar1) {
            __dest = valloc(uVar1 * 4);
            if (__dest == nullptr) {
                return 0;
            }
            memcpy(__dest,*(void **)this,*(int *)(this + 8) << 2);
            free(*(void **)this);
            iVar2 = *(int *)(this + 8);
            iVar3 = *(int *)(this + 0xc);
            *(void **)this = __dest;
            *(uint *)(this + 4) = iVar3 * param_1 + iVar2;
        }
        memset((void *)((int)__dest + iVar2 * 4),0,iVar3 * param_1 * 4);
        *(uint *)(this + 8) = *(int *)(this + 0xc) * param_1 + *(int *)(this + 8);
        return 1;
    }
    return 1;
}



// WaveBuffer_I32::PushSamples(int*, unsigned int)

undefined4 WaveBuffer_I32::PushSamples(int *param_1,uint param_2) {
    uint uVar1;
    int iVar2;
    int iVar3;
    void *__dest;

    __dest = *(void **)this;
    if (__dest == nullptr) {
        return 0;
    }
    if (param_2 != 0) {
        iVar2 = *(int *)(this + 8);
        iVar3 = *(int *)(this + 0xc);
        uVar1 = iVar3 * param_2 + iVar2;
        if (*(uint *)(this + 4) < uVar1) {
            __dest = valloc(uVar1 * 4);
            if (__dest == nullptr) {
                return 0;
            }
            memcpy(__dest,*(void **)this,*(int *)(this + 8) << 2);
            free(*(void **)this);
            iVar2 = *(int *)(this + 8);
            iVar3 = *(int *)(this + 0xc);
            *(void **)this = __dest;
            *(uint *)(this + 4) = iVar3 * param_2 + iVar2;
        }
        memcpy((void *)((int)__dest + iVar2 * 4),param_1,iVar3 * param_2 * 4);
        *(uint *)(this + 8) = *(int *)(this + 0xc) * param_2 + *(int *)(this + 8);
        return 1;
    }
    return 1;
}



// WaveBuffer_I32::PopSamples(unsigned int, bool)

uint WaveBuffer_I32::PopSamples(uint param_1,bool param_2) {
    uint uVar1;
    void *__dest;
    uint uVar2;

    __dest = *(void **)this;
    if (__dest == nullptr) {
        return 0;
    }
    if (*(int *)(this + 4) == 0) {
        return 0;
    }
    uVar1 = *(uint *)(this + 8);
    uVar2 = *(int *)(this + 0xc) * param_1;
    if (uVar2 < uVar1 || uVar2 - uVar1 == 0) {
        *(uint *)(this + 8) = uVar1 - uVar2;
        memmove(__dest,(void *)((int)__dest + uVar2 * 4),(uVar1 - uVar2) * 4);
        return param_1;
    }
    if (param_2 == false) {
        return 0;
    }
    uVar1 = __udivsi3();
    *(undefined4 *)(this + 8) = 0;
    return uVar1;
}



// WaveBuffer_I32::PopSamples(int*, unsigned int, bool)

uint WaveBuffer_I32::PopSamples(int *param_1,uint param_2,bool param_3) {
    uint uVar1;
    int iVar2;
    void *__src;
    uint uVar3;

    __src = *(void **)this;
    if (__src == nullptr) {
        return 0;
    }
    if (*(int *)(this + 4) == 0) {
        return 0;
    }
    uVar3 = *(uint *)(this + 8);
    uVar1 = *(int *)(this + 0xc) * param_2;
    if (uVar1 < uVar3 || uVar1 - uVar3 == 0) {
        memcpy(param_1,__src,uVar1 * 4);
        iVar2 = *(int *)(this + 8) - *(int *)(this + 0xc) * param_2;
        *(int *)(this + 8) = iVar2;
        memmove(*(void **)this,(void *)((int)*(void **)this + *(int *)(this + 0xc) * param_2 * 4),
                iVar2 * 4);
        return param_2;
    }
    if (param_3 == false) {
        return 0;
    }
    uVar1 = __udivsi3(uVar3);
    memcpy(param_1,__src,uVar3 << 2);
    *(undefined4 *)(this + 8) = 0;
    return uVar1;
}



// WaveBuffer_I32::Reset()

void WaveBuffer_I32::Reset() {
    *(undefined4 *)(this + 8) = 0;
    return;
}



// WaveBuffer_I32::SetBufferOffset(unsigned int)

void WaveBuffer_I32::SetBufferOffset(uint param_1) {
    uint uVar1;
    int iVar2;

    iVar2 = *(int *)(this + 0xc);
    uVar1 = __udivsi3(*(undefined4 *)(this + 4),iVar2);
    if (param_1 <= uVar1) {
        *(uint *)(this + 8) = iVar2 * param_1;
    }
    return;
}



// WaveBuffer_I32::GetBufferOffset()

void WaveBuffer_I32::GetBufferOffset(void) {
    int in_r0;

    __udivsi3(*(undefined4 *)(in_r0 + 8),*(undefined4 *)(in_r0 + 0xc));
    return;
}



// WaveBuffer_I32::GetBufferSize()

void WaveBuffer_I32::GetBufferSize(void) {
    int in_r0;

    __udivsi3(*(undefined4 *)(in_r0 + 4),*(undefined4 *)(in_r0 + 0xc));
    return;
}



// WaveBuffer_I32::GetCurrentBufferI32Ptr()

undefined4 WaveBuffer_I32::GetCurrentBufferI32Ptr() {
    return *(undefined4 *)this;
}
