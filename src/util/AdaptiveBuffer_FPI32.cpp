//
// Created by mart on 2/12/21.
//

#include "AdaptiveBuffer_FPI32.h"


// AdaptiveBuffer_FPI32::AdaptiveBuffer_FPI32(unsigned int, unsigned int)

AdaptiveBuffer_FPI32::AdaptiveBuffer_FPI32(uint param_1,uint param_2) {
    void *pvVar1;

    this->channels = param_1;
    this->bufferPointer = nullptr;
    this->bufferLength = 0;
    this->bufferOffset = 0;
    if (param_1 != 0) {
        pvVar1 = valloc(param_1 * param_2 * 4);
        this->bufferPointer = pvVar1;
        if (pvVar1 != nullptr) {
            this->bufferLength = param_2;
        }
    }
    return this;
}



// AdaptiveBuffer_FPI32::~AdaptiveBuffer_FPI32()

AdaptiveBuffer_FPI32::~AdaptiveBuffer_FPI32() {
if (this->bufferPointer != nullptr) {
free(this->bufferPointer);
}
this->bufferPointer = nullptr;
return this;
}



// AdaptiveBuffer_FPI32::FlushBuffer()

void AdaptiveBuffer_FPI32::FlushBuffer() {
this->bufferOffset = 0;
return;
}



// AdaptiveBuffer_FPI32::PushZero(unsigned int)

undefined4 AdaptiveBuffer_FPI32::PushZero(uint param_1) {
    int iVar1;
    int iVar2;
    void *__dest;

    __dest = this->bufferPointer;
    if (__dest == nullptr) {
        return 0;
    }
    iVar2 = this->bufferOffset;
    if (this->bufferLength < param_1 + iVar2) {
        __dest = valloc((param_1 + iVar2) * this->channels * 4);
        if (__dest == nullptr) {
            return 0;
        }
        memcpy(__dest,this->bufferPointer,this->channels * this->bufferOffset * 4);
        free(this->bufferPointer);
        iVar2 = this->bufferOffset;
        this->bufferPointer = __dest;
        this->bufferLength = param_1 + iVar2;
    }
    iVar1 = this->channels * 4;
    memset((void *)(iVar2 * iVar1 + (int)__dest),0,iVar1 * param_1);
    this->bufferOffset = this->bufferOffset + param_1;
    return 1;
}



// AdaptiveBuffer_FPI32::PushFrames(short*, unsigned int)

undefined4 AdaptiveBuffer_FPI32::PushFrames(short *param_1,uint param_2) {
    undefined4 uVar1;
    undefined4 uVar2;
    int iVar3;
    undefined8 *puVar4;
    int *piVar5;
    short *psVar6;
    int iVar7;
    short *psVar8;
    void *__dest;
    undefined8 *puVar9;
    short *psVar10;
    uint uVar11;
    uint uVar12;
    short *psVar13;
    undefined auVar14 [16];
    undefined auVar15 [16];
    undefined auVar16 [16];
    undefined auVar17 [16];

    __dest = this->bufferPointer;
    if (__dest == nullptr) {
        return 0;
    }
    if (param_2 == 0) {
        return 1;
    }
    iVar7 = this->bufferOffset;
    if (this->bufferLength < param_2 + iVar7) {
        __dest = valloc((param_2 + iVar7) * this->channels * 4);
        if (__dest == nullptr) {
            return 0;
        }
        memcpy(__dest,this->bufferPointer,this->channels * this->bufferOffset * 4);
        free(this->bufferPointer);
        iVar7 = this->bufferOffset;
        this->bufferPointer = __dest;
        this->bufferLength = param_2 + iVar7;
    }
    uVar12 = this->channels * param_2;
    puVar4 = (undefined8 *)(iVar7 * this->channels * 4 + (int)__dest);
    if ((int)uVar12 < 0x10) {
        if (0 < (int)uVar12) {
            piVar5 = (int *)((int)puVar4 + -4);
            iVar7 = 0;
            do {
                psVar13 = (short *)((int)param_1 + iVar7);
                iVar7 = iVar7 + 2;
                piVar5 = piVar5 + 1;
                *piVar5 = (int)*psVar13 << 10;
            } while (iVar7 != uVar12 * 2);
            iVar7 = this->bufferOffset;
        }
        this->bufferOffset = iVar7 + param_2;
        return 1;
    }
    uVar11 = uVar12 & 0xfffffff0;
    if (uVar11 != 0) {
        iVar7 = 0;
        puVar9 = puVar4;
        psVar13 = param_1;
        do {
            psVar8 = psVar13 + 8;
            psVar6 = psVar13 + 0xc;
            iVar7 = iVar7 + 0x10;
            uVar1 = CONCAT22(*psVar13,*psVar13);
            psVar10 = psVar13 + 4;
            psVar13 = psVar13 + 0x10;
            uVar2 = CONCAT22(*psVar10,*psVar10);
            auVar17 = VectorShiftLongLeft(CONCAT44(uVar1,uVar1),10);
            uVar1 = CONCAT22(*psVar8,*psVar8);
            auVar16 = VectorShiftLongLeft(CONCAT44(uVar2,uVar2),10);
            uVar2 = CONCAT22(*psVar6,*psVar6);
            auVar15 = VectorShiftLongLeft(CONCAT44(uVar1,uVar1),10);
            auVar14 = VectorShiftLongLeft(CONCAT44(uVar2,uVar2),10);
            *puVar9 = CONCAT44(SUB164(auVar17,0),SUB164(auVar17,0));
            uVar1 = SUB164(auVar17 >> 0x40,0);
            *(ulonglong *)((int)puVar9 + 4) = CONCAT44(uVar1,uVar1);
            puVar9[2] = CONCAT44(SUB164(auVar16,0),SUB164(auVar16,0));
            uVar1 = SUB164(auVar16 >> 0x40,0);
            *(ulonglong *)((int)puVar9 + 0x14) = CONCAT44(uVar1,uVar1);
            puVar9[4] = CONCAT44(SUB164(auVar15,0),SUB164(auVar15,0));
            uVar1 = SUB164(auVar15 >> 0x40,0);
            *(ulonglong *)((int)puVar9 + 0x24) = CONCAT44(uVar1,uVar1);
            puVar9[6] = CONCAT44(SUB164(auVar14,0),SUB164(auVar14,0));
            uVar1 = SUB164(auVar14 >> 0x40,0);
            *(ulonglong *)((int)puVar9 + 0x34) = CONCAT44(uVar1,uVar1);
            puVar9 = puVar9 + 8;
        } while (iVar7 < (int)uVar11);
    }
    if (uVar12 - uVar11 != 0 && (int)uVar11 <= (int)uVar12) {
        puVar4 = (undefined8 *)((int)puVar4 + (uVar11 + 0x3fffffff) * 4);
        iVar7 = 0;
        do {
            iVar3 = iVar7 + uVar11 * 2;
            iVar7 = iVar7 + 2;
            puVar4 = (undefined8 *)((int)puVar4 + 4);
            *(int *)puVar4 = (int)*(short *)((int)param_1 + iVar3) << 10;
        } while (iVar7 != (uVar12 - uVar11) * 2);
    }
    this->bufferOffset = this->bufferOffset + param_2;
    return 1;
}



// AdaptiveBuffer_FPI32::PushFrames(int*, unsigned int)

undefined4 AdaptiveBuffer_FPI32::PushFrames(int *param_1,uint param_2) {
    int iVar1;
    int iVar2;
    void *__dest;

    __dest = this->bufferPointer;
    if (__dest == nullptr) {
        return 0;
    }
    if (param_2 != 0) {
        iVar2 = this->bufferOffset;
        if (this->bufferLength < param_2 + iVar2) {
            __dest = valloc((param_2 + iVar2) * this->channels * 4);
            if (__dest == nullptr) {
                return 0;
            }
            memcpy(__dest,this->bufferPointer,this->channels * this->bufferOffset * 4);
            free(this->bufferPointer);
            iVar2 = this->bufferOffset;
            this->bufferPointer = __dest;
            this->bufferLength = param_2 + iVar2;
        }
        iVar1 = this->channels * 4;
        memcpy((void *)(iVar2 * iVar1 + (int)__dest),param_1,iVar1 * param_2);
        this->bufferOffset = this->bufferOffset + param_2;
        return 1;
    }
    return 1;
}



// AdaptiveBuffer_FPI32::PopFrames(short*, unsigned int)

undefined4 AdaptiveBuffer_FPI32::PopFrames(short *param_1,uint param_2) {
    undefined auVar1 [16];
    int *piVar2;
    ulonglong *puVar3;
    uint uVar4;
    int iVar5;
    uint uVar6;
    uint uVar7;
    void *__dest;
    undefined4 *puVar8;
    int iVar9;
    ulonglong uVar10;
    undefined auVar11 [16];
    ulonglong uVar12;
    undefined auVar13 [16];
    ulonglong uVar14;
    undefined auVar15 [16];
    undefined8 uVar16;
    undefined auVar18 [16];
    ulonglong uVar17;

    __dest = this->bufferPointer;
    if ((__dest == nullptr) || (uVar4 = this->bufferOffset, uVar4 < param_2)) {
        return 0;
    }
    if (param_2 != 0) {
        uVar7 = this->channels;
        uVar6 = uVar7 * param_2;
        if ((int)uVar6 < 0x10) {
            if (0 < (int)uVar6) {
                piVar2 = (int *)((int)__dest + -4);
                iVar5 = 0;
                do {
                    piVar2 = piVar2 + 1;
                    iVar9 = *piVar2 + 0x200;
                    if (iVar9 < -0x2000000) {
                        iVar9 = -0x2000000;
                    }
                    if (0x1fffffe < iVar9) {
                        iVar9 = 0x1ffffff;
                    }
                    *(short *)((int)param_1 + iVar5) = (short)(iVar9 >> 10);
                    iVar5 = iVar5 + 2;
                } while (iVar5 != uVar6 * 2);
            }
            iVar5 = uVar4 - param_2;
            this->bufferOffset = iVar5;
            if (iVar5 != 0) {
                memmove(__dest,(void *)((int)__dest + uVar6 * 4),iVar5 * uVar7 * 4);
            }
        }
        else {
            uVar7 = uVar6 & 0xfffffff0;
            if (uVar7 != 0) {
                auVar1 = SIMDExpandImmediate(0,2,2);
                iVar5 = 0;
                puVar3 = (ulonglong *)(param_1 + 4);
                while( true ) {
                    puVar8 = (undefined4 *)((int)__dest + iVar5);
                    auVar18 = VectorAdd(CONCAT88(CONCAT44(puVar8[1],puVar8[1]),CONCAT44(*puVar8,*puVar8)),
                                        auVar1,4);
                    iVar5 = iVar5 + 0x40;
                    auVar15 = VectorAdd(CONCAT88(CONCAT44(puVar8[5],puVar8[5]),CONCAT44(puVar8[4],puVar8[4])),
                                        auVar1,4);
                    auVar13 = VectorAdd(CONCAT88(CONCAT44(puVar8[9],puVar8[9]),CONCAT44(puVar8[8],puVar8[8])),
                                        auVar1,4);
                    auVar11 = VectorAdd(CONCAT88(CONCAT44(puVar8[0xd],puVar8[0xd]),
                                                 CONCAT44(puVar8[0xc],puVar8[0xc])),auVar1,4);
                    uVar16 = VectorShiftRightNarrow(auVar18,10,2,0);
                    uVar17 = SatQ(uVar16,2,0);
                    uVar16 = VectorShiftRightNarrow(auVar15,10,2,0);
                    uVar14 = SatQ(uVar16,2,0);
                    uVar16 = VectorShiftRightNarrow(auVar13,10,2,0);
                    uVar12 = SatQ(uVar16,2,0);
                    uVar16 = VectorShiftRightNarrow(auVar11,10,2,0);
                    uVar10 = SatQ(uVar16,2,0);
                    uVar17 = uVar17 & 0xffff | (uVar17 & 0xffff) << 0x10;
                    puVar3[-1] = uVar17 | uVar17 << 0x20;
                    uVar17 = uVar14 & 0xffff | (uVar14 & 0xffff) << 0x10;
                    *puVar3 = uVar17 | uVar17 << 0x20;
                    uVar17 = uVar12 & 0xffff | (uVar12 & 0xffff) << 0x10;
                    puVar3[1] = uVar17 | uVar17 << 0x20;
                    uVar17 = uVar10 & 0xffff | (uVar10 & 0xffff) << 0x10;
                    puVar3[2] = uVar17 | uVar17 << 0x20;
                    if (puVar3 == (ulonglong *)((int)(param_1 + 4) + uVar7 * 2 + -0x20)) break;
                    __dest = this->bufferPointer;
                    puVar3 = puVar3 + 4;
                }
                uVar4 = this->bufferOffset;
            }
            if (uVar6 - uVar7 != 0 && (int)uVar7 <= (int)uVar6) {
                iVar5 = 0;
                piVar2 = (int *)((int)this->bufferPointer + (uVar7 + 0x3fffffff) * 4);
                do {
                    piVar2 = piVar2 + 1;
                    iVar9 = *piVar2 + 0x200;
                    if (iVar9 < -0x2000000) {
                        iVar9 = -0x2000000;
                    }
                    if (0x1fffffe < iVar9) {
                        iVar9 = 0x1ffffff;
                    }
                    *(short *)((int)param_1 + iVar5 + uVar7 * 2) = (short)(iVar9 >> 10);
                    iVar5 = iVar5 + 2;
                } while (iVar5 != (uVar6 - uVar7) * 2);
            }
            iVar5 = uVar4 - param_2;
            this->bufferOffset = iVar5;
            if (iVar5 != 0) {
                iVar9 = this->channels * 4;
                memmove(this->bufferPointer,(void *)(iVar9 * param_2 + (int)this->bufferPointer),
                        iVar9 * iVar5);
                return 1;
            }
        }
    }
    return 1;
}



// AdaptiveBuffer_FPI32::ScaleFrames(int)

void AdaptiveBuffer_FPI32::ScaleFrames(int param_1) {
    undefined4 uVar1;
    longlong lVar2;
    ulonglong *puVar3;
    int iVar4;
    int iVar5;
    uint *puVar6;
    uint *puVar7;
    uint *puVar8;
    uint uVar9;
    uint uVar10;
    ulonglong uVar11;
    undefined auVar12 [16];
    undefined8 uVar13;
    undefined auVar15 [16];
    ulonglong uVar14;

    puVar6 = (uint *)this->bufferPointer;
    if (puVar6 != nullptr) {
        uVar9 = this->bufferOffset * this->channels;
        if ((int)uVar9 < 4) {
            if (0 < (int)uVar9) {
                puVar7 = puVar6;
                do {
                    lVar2 = (longlong)(int)*puVar7 * (longlong)param_1 + 0x1000000;
                    puVar8 = puVar7 + 1;
                    *puVar7 = (uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7;
                    puVar7 = puVar8;
                } while (puVar8 != puVar6 + uVar9);
            }
        }
        else {
            uVar10 = uVar9 & 0xfffffffc;
            if (uVar10 != 0) {
                iVar4 = 8;
                iVar5 = 0;
                while( true ) {
                    puVar3 = (ulonglong *)(puVar6 + iVar5);
                    iVar5 = iVar5 + 4;
                    uVar1 = *(undefined4 *)puVar3;
                    auVar15 = VectorMultiply(CONCAT44(*(undefined4 *)((int)puVar6 + iVar4),
                                                      *(undefined4 *)((int)puVar6 + iVar4)),
                                             CONCAT44(param_1,param_1),4,0);
                    auVar12 = VectorMultiply(CONCAT44(uVar1,uVar1),CONCAT44(param_1,param_1),4,0);
                    auVar15 = VectorAdd(auVar15,CONCAT88(0x1000000,0x1000000),8);
                    auVar12 = VectorAdd(auVar12,CONCAT88(0x1000000,0x1000000),8);
                    uVar13 = VectorShiftRightNarrow(auVar15,0x19,4,0);
                    uVar14 = SatQ(uVar13,4,0);
                    uVar13 = VectorShiftRightNarrow(auVar12,0x19,4,0);
                    uVar11 = SatQ(uVar13,4,0);
                    *puVar3 = uVar11 & 0xffffffff | (uVar11 & 0xffffffff) << 0x20;
                    puVar3 = (ulonglong *)((int)this->bufferPointer + iVar4);
                    iVar4 = iVar4 + 0x10;
                    *puVar3 = uVar14 & 0xffffffff | (uVar14 & 0xffffffff) << 0x20;
                    if ((int)uVar10 <= iVar5) break;
                    puVar6 = (uint *)this->bufferPointer;
                }
            }
            if (uVar9 - uVar10 != 0 && (int)uVar10 <= (int)uVar9) {
                puVar6 = (uint *)((int)this->bufferPointer + uVar10 * 4);
                do {
                    uVar10 = uVar10 + 1;
                    lVar2 = (longlong)(int)*puVar6 * (longlong)param_1 + 0x1000000;
                    *puVar6 = (uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7;
                    puVar6 = puVar6 + 1;
                } while (uVar9 - uVar10 != 0);
                return;
            }
        }
    }
    return;
}



// AdaptiveBuffer_FPI32::PanFrames(int, int)

void AdaptiveBuffer_FPI32::PanFrames(int param_1,int param_2) {
    uint uVar1;
    undefined4 uVar2;
    longlong lVar3;
    ulonglong *puVar4;
    int iVar5;
    int iVar6;
    uint uVar7;
    uint uVar8;
    uint *puVar9;
    ulonglong uVar10;
    undefined auVar11 [16];
    undefined8 uVar12;
    undefined auVar14 [16];
    int local_20 [2];
    ulonglong uVar13;

    puVar9 = (uint *)this->bufferPointer;
    if ((puVar9 != nullptr) && (this->channels == 2)) {
        local_20[0] = param_1;
        local_20[1] = param_2;
        uVar1 = this->bufferOffset * 2;
        if ((int)uVar1 < 4) {
            if (0 < (int)uVar1) {
                uVar8 = 0;
                while( true ) {
                    uVar8 = uVar8 + 1;
                    lVar3 = (longlong)(int)*puVar9 * (longlong)param_1 + 0x1000000;
                    *puVar9 = (uint)lVar3 >> 0x19 | (int)((ulonglong)lVar3 >> 0x20) << 7;
                    if (uVar1 == uVar8) break;
                    param_1 = local_20[uVar8 & 1];
                    puVar9 = puVar9 + 1;
                }
                return;
            }
        }
        else {
            uVar8 = uVar1 & 0xfffffffc;
            if (uVar8 != 0) {
                iVar5 = 8;
                iVar6 = 0;
                while( true ) {
                    puVar4 = (ulonglong *)(puVar9 + iVar6);
                    iVar6 = iVar6 + 4;
                    uVar2 = *(undefined4 *)puVar4;
                    auVar14 = VectorMultiply(CONCAT44(*(undefined4 *)((int)puVar9 + iVar5),
                                                      *(undefined4 *)((int)puVar9 + iVar5)),
                                             CONCAT44(param_1,param_1),4,0);
                    auVar11 = VectorMultiply(CONCAT44(uVar2,uVar2),CONCAT44(param_1,param_1),4,0);
                    auVar14 = VectorAdd(auVar14,CONCAT88(0x1000000,0x1000000),8);
                    auVar11 = VectorAdd(auVar11,CONCAT88(0x1000000,0x1000000),8);
                    uVar12 = VectorShiftRightNarrow(auVar14,0x19,4,0);
                    uVar13 = SatQ(uVar12,4,0);
                    uVar12 = VectorShiftRightNarrow(auVar11,0x19,4,0);
                    uVar10 = SatQ(uVar12,4,0);
                    *puVar4 = uVar10 & 0xffffffff | (uVar10 & 0xffffffff) << 0x20;
                    puVar4 = (ulonglong *)((int)this->bufferPointer + iVar5);
                    iVar5 = iVar5 + 0x10;
                    *puVar4 = uVar13 & 0xffffffff | (uVar13 & 0xffffffff) << 0x20;
                    if ((int)uVar8 <= iVar6) break;
                    puVar9 = (uint *)this->bufferPointer;
                }
            }
            if ((int)uVar8 < (int)uVar1) {
                puVar9 = (uint *)((int)this->bufferPointer + uVar8 * 4);
                do {
                    uVar7 = uVar8 & 1;
                    uVar8 = uVar8 + 1;
                    lVar3 = (longlong)(int)*puVar9 * (longlong)local_20[uVar7] + 0x1000000;
                    *puVar9 = (uint)lVar3 >> 0x19 | (int)((ulonglong)lVar3 >> 0x20) << 7;
                    puVar9 = puVar9 + 1;
                } while (uVar1 != uVar8);
            }
        }
    }
    return;
}



// AdaptiveBuffer_FPI32::SetBufferOffset(unsigned int)

void AdaptiveBuffer_FPI32::SetBufferOffset(uint param_1) {
    this->bufferOffset = param_1;
    return;
}



// AdaptiveBuffer_FPI32::GetBufferPointer()

void * AdaptiveBuffer_FPI32::GetBufferPointer() {
return this->bufferPointer;
}



// AdaptiveBuffer_FPI32::GetBufferLength()

uint AdaptiveBuffer_FPI32::GetBufferLength() {
return this->bufferLength;
}



// AdaptiveBuffer_FPI32::GetBufferOffset()

undefined4 AdaptiveBuffer_FPI32::GetBufferOffset() {
return this->bufferOffset;
}


// AdaptiveBuffer_FPI32::GetChannels()

uint AdaptiveBuffer_FPI32::GetChannels() {
return this->channels;
}
