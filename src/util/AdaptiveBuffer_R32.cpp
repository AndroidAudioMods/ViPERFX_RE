//
// Created by mart on 2/12/21.
//

#include "AdaptiveBuffer_R32.h"


// AdaptiveBuffer_R32::AdaptiveBuffer_R32(unsigned int, unsigned int)

AdaptiveBuffer_R32::AdaptiveBuffer_R32(uint param_1,uint param_2) {
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



// AdaptiveBuffer_R32::~AdaptiveBuffer_R32()

AdaptiveBuffer_R32::~AdaptiveBuffer_R32() {
    if (this->bufferPointer != nullptr) {
        free(this->bufferPointer);
    }
    this->bufferPointer = nullptr;
    return this;
}



// AdaptiveBuffer_R32::Short2Float(short*, float*, unsigned int)

void AdaptiveBuffer_R32::Short2Float(short *param_1,float *param_2,uint param_3) {
    bool bVar1;
    undefined4 uVar2;
    int iVar3;
    undefined8 *puVar4;
    short *psVar5;
    float *pfVar6;
    uint uVar7;
    uint uVar8;
    uint uVar9;
    undefined4 in_cr7;
    undefined auVar10 [16];

    uVar7 = this->channels * param_3;
    if (uVar7 < 4) {
        iVar3 = uVar7 - 1;
        if (uVar7 != 0) {
            psVar5 = param_1 + uVar7;
            pfVar6 = param_2 + uVar7;
            do {
                psVar5 = psVar5 + -1;
                iVar3 = iVar3 + -1;
                coprocessor_function(10,6,4,in_cr7,in_cr7,in_cr7);
                pfVar6 = pfVar6 + -1;
                *pfVar6 = (float)(longlong)(int)*psVar5;
            } while (iVar3 != -1);
        }
    }
    else {
        uVar9 = uVar7 & 3;
        if (uVar7 >> 2 != 0) {
            puVar4 = (undefined8 *)param_2;
            uVar7 = uVar7 >> 2;
            psVar5 = param_1;
            do {
                uVar2 = CONCAT22(*psVar5,*psVar5);
                psVar5 = psVar5 + 4;
                auVar10 = VectorCopyLong(CONCAT44(uVar2,uVar2),2,0);
                auVar10 = FixedToFP(auVar10,0x20,0x20,0,0,0);
                auVar10 = FloatVectorMult(auVar10,ZEXT816(0x3800010038000100) &
                                                  ZEXT816(0x3800010038000100) << 0x40,2,0x20);
                uVar8 = uVar7 - 1;
                *puVar4 = CONCAT44(SUB164(auVar10,0),SUB164(auVar10,0));
                uVar2 = SUB164(auVar10 >> 0x40,0);
                *(ulonglong *)((int)puVar4 + 4) = CONCAT44(uVar2,uVar2);
                puVar4 = puVar4 + 2;
                bVar1 = 0 < (int)uVar7;
                uVar7 = uVar8;
            } while (uVar8 != 0 && bVar1);
        }
        if (uVar9 != 0) {
            psVar5 = param_1 + uVar9;
            pfVar6 = param_2 + uVar9;
            iVar3 = uVar9 - 1;
            do {
                psVar5 = psVar5 + -1;
                iVar3 = iVar3 + -1;
                coprocessor_function(10,6,4,in_cr7,in_cr7,in_cr7);
                pfVar6 = pfVar6 + -1;
                *pfVar6 = (float)(longlong)(int)*psVar5;
            } while (iVar3 != -1);
            return;
        }
    }
    return;
}



// AdaptiveBuffer_R32::Float2Short(float*, short*, unsigned int)

void AdaptiveBuffer_R32::Float2Short(float *param_1,short *param_2,uint param_3) {
    bool bVar1;
    undefined auVar2 [16];
    float fVar3;
    int iVar4;
    ulonglong *puVar5;
    float *pfVar6;
    short *psVar7;
    uint uVar8;
    uint uVar9;
    uint uVar10;
    float *pfVar11;
    undefined4 in_cr7;
    ulonglong uVar12;
    undefined auVar13 [16];
    undefined auVar14 [16];

    uVar8 = this->channels * param_3;
    if (uVar8 < 4) {
        iVar4 = uVar8 - 1;
        if (uVar8 != 0) {
            pfVar6 = param_1 + uVar8;
            psVar7 = param_2 + uVar8;
            do {
                pfVar6 = pfVar6 + -1;
                iVar4 = iVar4 + -1;
                coprocessor_function(10,6,4,in_cr7,in_cr7,in_cr7);
                psVar7 = psVar7 + -1;
                *psVar7 = SUB42(ROUND(*pfVar6),0);
            } while (iVar4 != -1);
        }
    }
    else {
        uVar10 = uVar8 & 3;
        if (uVar8 >> 2 != 0) {
            auVar2 = ZEXT816(0x3f8000003f800000) & ZEXT816(0x3f8000003f800000) << 0x40;
            auVar14 = FloatVectorNeg(auVar2,2,0x20);
            puVar5 = (ulonglong *)param_2;
            uVar8 = uVar8 >> 2;
            pfVar6 = param_1;
            do {
                fVar3 = *pfVar6;
                pfVar11 = pfVar6 + 1;
                pfVar6 = pfVar6 + 4;
                auVar13 = FloatVectorMin(CONCAT88(CONCAT44(*pfVar11,*pfVar11),CONCAT44(fVar3,fVar3)),auVar2,
                                         2,0x20);
                auVar13 = FloatVectorMax(auVar13,auVar14,2,0x20);
                auVar13 = FloatVectorMult(auVar13,ZEXT816(0x46fffe0046fffe00) &
                                                  ZEXT816(0x46fffe0046fffe00) << 0x40,2,0x20);
                auVar13 = FPToFixed(auVar13,0x20,0x20,0x10,0,3);
                uVar12 = VectorRoundShiftRightNarrow(auVar13,0x10);
                uVar9 = uVar8 - 1;
                uVar12 = uVar12 & 0xffff | (uVar12 & 0xffff) << 0x10;
                *puVar5 = uVar12 | uVar12 << 0x20;
                puVar5 = puVar5 + 1;
                bVar1 = 0 < (int)uVar8;
                uVar8 = uVar9;
            } while (uVar9 != 0 && bVar1);
        }
        if (uVar10 != 0) {
            pfVar6 = param_1 + uVar10;
            psVar7 = param_2 + uVar10;
            iVar4 = uVar10 - 1;
            do {
                pfVar6 = pfVar6 + -1;
                iVar4 = iVar4 + -1;
                coprocessor_function(10,6,4,in_cr7,in_cr7,in_cr7);
                psVar7 = psVar7 + -1;
                *psVar7 = SUB42(ROUND(*pfVar6),0);
            } while (iVar4 != -1);
            return;
        }
    }
    return;
}



// AdaptiveBuffer_R32::FlushBuffer()

void AdaptiveBuffer_R32::FlushBuffer() {
    this->bufferOffset = 0;
    return;
}



// AdaptiveBuffer_R32::PushZero(unsigned int)

undefined4 AdaptiveBuffer_R32::PushZero(uint param_1) {
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



// AdaptiveBuffer_R32::PushFrames(short*, unsigned int)

undefined4 AdaptiveBuffer_R32::PushFrames(short *param_1,uint param_2) {
    int iVar1;
    void *__dest;

    __dest = this->bufferPointer;
    if (__dest == nullptr) {
        return 0;
    }
    if (param_2 != 0) {
        iVar1 = this->bufferOffset;
        if (this->bufferLength < param_2 + iVar1) {
            __dest = valloc((param_2 + iVar1) * this->channels * 4);
            if (__dest == nullptr) {
                return 0;
            }
            memcpy(__dest,this->bufferPointer,this->channels * this->bufferOffset * 4);
            free(this->bufferPointer);
            iVar1 = this->bufferOffset;
            this->bufferPointer = __dest;
            this->bufferLength = param_2 + iVar1;
        }
        Short2Float(this,param_1,(float *)(iVar1 * this->channels * 4 + (int)__dest),param_2);
        this->bufferOffset = this->bufferOffset + param_2;
        return 1;
    }
    return 1;
}



// AdaptiveBuffer_R32::PopFrames(short*, unsigned int)

undefined4 AdaptiveBuffer_R32::PopFrames(short *param_1,uint param_2) {
    int iVar1;
    int iVar2;

    if (((float *)this->bufferPointer != nullptr) && (param_2 <= (uint)this->bufferOffset)) {
        if (param_2 != 0) {
            Float2Short(this,(float *)this->bufferPointer,param_1,param_2);
            iVar2 = this->bufferOffset - param_2;
            this->bufferOffset = iVar2;
            if (iVar2 != 0) {
                iVar1 = this->channels * 4;
                memmove(this->bufferPointer,(void *)(iVar1 * param_2 + (int)this->bufferPointer),
                        iVar1 * iVar2);
            }
        }
        return 1;
    }
    return 0;
}



// WARNING: Restarted to delay deadcode elimination for space: register
// AdaptiveBuffer_R32::ScaleFrames(float)

void AdaptiveBuffer_R32::ScaleFrames(float param_1) {
    undefined auVar1 [16];
    undefined4 uVar2;
    undefined4 uVar4;
    undefined4 in_r1;
    uint uVar6;
    undefined4 *puVar7;
    undefined8 *puVar8;
    int iVar9;
    uint uVar10;
    int iVar11;
    int iVar12;
    undefined4 *puVar13;
    int iVar14;
    undefined4 in_cr7;
    undefined auVar15 [16];
    undefined auVar16 [16];
    undefined auVar17 [16];
    undefined4 uVar3;
    undefined4 uVar5;

    puVar7 = (undefined4 *)this->bufferPointer;
    if ((puVar7 != nullptr) && (-1 < (int)puVar7)) {
        uVar6 = this->bufferOffset * this->channels;
        if ((int)uVar6 < 0x10) {
            if (0 < (int)uVar6) {
                iVar9 = 0;
                do {
                    iVar9 = iVar9 + 1;
                    coprocessor_function(10,2,1,in_cr7,in_cr7,in_cr7);
                    *puVar7 = *puVar7;
                    puVar7 = puVar7 + 1;
                } while (uVar6 - iVar9 != 0);
            }
        }
        else {
            uVar10 = uVar6 & 0xfffffff0;
            auVar1 = ZEXT816(CONCAT44(in_r1,in_r1)) & ZEXT816(CONCAT44(in_r1,in_r1)) << 0x40;
            if (uVar10 != 0) {
                iVar9 = 0x10;
                iVar14 = 0;
                while( true ) {
                    puVar8 = (undefined8 *)(puVar7 + iVar14);
                    iVar12 = iVar9 + 0x10;
                    iVar11 = iVar9 + 0x20;
                    uVar2 = *(undefined4 *)((int)puVar7 + iVar9);
                    uVar3 = ((undefined4 *)((int)puVar7 + iVar9))[1];
                    puVar13 = (undefined4 *)((int)puVar7 + iVar12);
                    puVar7 = (undefined4 *)((int)puVar7 + iVar11);
                    iVar14 = iVar14 + 0x10;
                    auVar17 = FloatVectorMult(CONCAT88(CONCAT44(*(undefined4 *)((int)puVar8 + 4),
                                                                *(undefined4 *)((int)puVar8 + 4)),
                                                       CONCAT44(*(undefined4 *)puVar8,*(undefined4 *)puVar8)),
                                              auVar1,2,0x20);
                    auVar16 = FloatVectorMult(CONCAT88(CONCAT44(uVar3,uVar3),CONCAT44(uVar2,uVar2)),auVar1,2,
                                              0x20);
                    uVar2 = *puVar7;
                    uVar3 = puVar7[1];
                    uVar4 = *puVar13;
                    uVar5 = puVar13[1];
                    auVar15 = FloatVectorMult(CONCAT88(CONCAT44(uVar5,uVar5),CONCAT44(uVar4,uVar4)),auVar1,2,
                                              0x20);
                    *puVar8 = CONCAT44(SUB164(auVar17,0),SUB164(auVar17,0));
                    uVar4 = SUB164(auVar17 >> 0x40,0);
                    *(ulonglong *)((int)puVar8 + 4) = CONCAT44(uVar4,uVar4);
                    auVar17 = FloatVectorMult(CONCAT88(CONCAT44(uVar3,uVar3),CONCAT44(uVar2,uVar2)),auVar1,2,
                                              0x20);
                    puVar8 = (undefined8 *)((int)this->bufferPointer + iVar9);
                    iVar9 = iVar9 + 0x40;
                    *puVar8 = CONCAT44(SUB164(auVar16,0),SUB164(auVar16,0));
                    uVar2 = SUB164(auVar16 >> 0x40,0);
                    *(ulonglong *)((int)puVar8 + 4) = CONCAT44(uVar2,uVar2);
                    puVar8 = (undefined8 *)((int)this->bufferPointer + iVar12);
                    *puVar8 = CONCAT44(SUB164(auVar15,0),SUB164(auVar15,0));
                    uVar2 = SUB164(auVar15 >> 0x40,0);
                    *(ulonglong *)((int)puVar8 + 4) = CONCAT44(uVar2,uVar2);
                    puVar8 = (undefined8 *)((int)this->bufferPointer + iVar11);
                    *puVar8 = CONCAT44(SUB164(auVar17,0),SUB164(auVar17,0));
                    uVar2 = SUB164(auVar17 >> 0x40,0);
                    *(ulonglong *)((int)puVar8 + 4) = CONCAT44(uVar2,uVar2);
                    if ((int)uVar10 <= iVar14) break;
                    puVar7 = (undefined4 *)this->bufferPointer;
                }
            }
            if (uVar6 - uVar10 != 0 && (int)uVar10 <= (int)uVar6) {
                puVar7 = (undefined4 *)((int)this->bufferPointer + uVar10 * 4);
                do {
                    uVar10 = uVar10 + 1;
                    coprocessor_function(10,2,1,in_cr7,in_cr7,in_cr7);
                    *puVar7 = *puVar7;
                    puVar7 = puVar7 + 1;
                } while (uVar6 - uVar10 != 0);
            }
        }
    }
    return;
}



// AdaptiveBuffer_R32::PanFrames(float, float)

void AdaptiveBuffer_R32::PanFrames(float param_1,float param_2) {
    uint uVar1;
    undefined4 uVar2;
    undefined4 uVar4;
    undefined4 in_r1;
    int iVar6;
    undefined4 in_r2;
    int iVar7;
    uint uVar8;
    undefined4 *puVar9;
    uint uVar10;
    undefined8 *puVar11;
    int iVar12;
    int iVar13;
    undefined4 *puVar14;
    bool bVar15;
    undefined4 in_cr7;
    undefined8 uVar16;
    undefined8 uVar17;
    undefined auVar18 [16];
    undefined auVar19 [16];
    undefined auVar20 [16];
    undefined4 local_28 [4];
    undefined4 uVar3;
    undefined4 uVar5;

    puVar9 = (undefined4 *)this->bufferPointer;
    if (((puVar9 != nullptr) && (bVar15 = -1 < (int)(this->channels - 2), this->channels == 2)) &&
        ((bVar15 || (bVar15)))) {
        uVar1 = this->bufferOffset * 2;
        if ((int)uVar1 < 0x10) {
            if (0 < (int)uVar1) {
                uVar10 = 0;
                while( true ) {
                    uVar10 = uVar10 + 1;
                    coprocessor_function(10,6,1,in_cr7,in_cr7,in_cr7);
                    *puVar9 = in_r1;
                    puVar9 = puVar9 + 1;
                    if (uVar1 == uVar10) break;
                    in_r1 = local_28[uVar10 & 3];
                }
                return;
            }
        }
        else {
            uVar10 = uVar1 & 0xfffffff0;
            uVar16 = CONCAT44(in_r1,in_r1);
            uVar17 = CONCAT44(in_r2,in_r2);
            if (uVar10 != 0) {
                iVar7 = 0x10;
                iVar6 = 0;
                while( true ) {
                    puVar11 = (undefined8 *)(puVar9 + iVar6);
                    iVar13 = iVar7 + 0x10;
                    iVar12 = iVar7 + 0x20;
                    uVar2 = *(undefined4 *)((int)puVar9 + iVar7);
                    uVar3 = ((undefined4 *)((int)puVar9 + iVar7))[1];
                    puVar14 = (undefined4 *)((int)puVar9 + iVar13);
                    puVar9 = (undefined4 *)((int)puVar9 + iVar12);
                    iVar6 = iVar6 + 0x10;
                    auVar20 = FloatVectorMult(CONCAT88(CONCAT44(*(undefined4 *)((int)puVar11 + 4),
                                                                *(undefined4 *)((int)puVar11 + 4)),
                                                       CONCAT44(*(undefined4 *)puVar11,*(undefined4 *)puVar11)
                    ),CONCAT88(uVar17,uVar16),2,0x20);
                    auVar19 = FloatVectorMult(CONCAT88(CONCAT44(uVar3,uVar3),CONCAT44(uVar2,uVar2)),
                                              CONCAT88(uVar17,uVar16),2,0x20);
                    uVar2 = *puVar9;
                    uVar3 = puVar9[1];
                    uVar4 = *puVar14;
                    uVar5 = puVar14[1];
                    auVar18 = FloatVectorMult(CONCAT88(CONCAT44(uVar5,uVar5),CONCAT44(uVar4,uVar4)),
                                              CONCAT88(uVar17,uVar16),2,0x20);
                    *puVar11 = CONCAT44(SUB164(auVar20,0),SUB164(auVar20,0));
                    uVar4 = SUB164(auVar20 >> 0x40,0);
                    *(ulonglong *)((int)puVar11 + 4) = CONCAT44(uVar4,uVar4);
                    auVar20 = FloatVectorMult(CONCAT88(CONCAT44(uVar3,uVar3),CONCAT44(uVar2,uVar2)),
                                              CONCAT88(uVar17,uVar16),2,0x20);
                    puVar11 = (undefined8 *)((int)this->bufferPointer + iVar7);
                    iVar7 = iVar7 + 0x40;
                    *puVar11 = CONCAT44(SUB164(auVar19,0),SUB164(auVar19,0));
                    uVar2 = SUB164(auVar19 >> 0x40,0);
                    *(ulonglong *)((int)puVar11 + 4) = CONCAT44(uVar2,uVar2);
                    puVar11 = (undefined8 *)((int)this->bufferPointer + iVar13);
                    *puVar11 = CONCAT44(SUB164(auVar18,0),SUB164(auVar18,0));
                    uVar2 = SUB164(auVar18 >> 0x40,0);
                    *(ulonglong *)((int)puVar11 + 4) = CONCAT44(uVar2,uVar2);
                    puVar11 = (undefined8 *)((int)this->bufferPointer + iVar12);
                    *puVar11 = CONCAT44(SUB164(auVar20,0),SUB164(auVar20,0));
                    uVar2 = SUB164(auVar20 >> 0x40,0);
                    *(ulonglong *)((int)puVar11 + 4) = CONCAT44(uVar2,uVar2);
                    if ((int)uVar10 <= iVar6) break;
                    puVar9 = (undefined4 *)this->bufferPointer;
                }
            }
            if ((int)uVar10 < (int)uVar1) {
                puVar9 = (undefined4 *)((int)this->bufferPointer + uVar10 * 4);
                do {
                    uVar8 = uVar10 & 3;
                    uVar10 = uVar10 + 1;
                    coprocessor_function(10,6,1,in_cr7,in_cr7,in_cr7);
                    *puVar9 = local_28[uVar8];
                    puVar9 = puVar9 + 1;
                } while (uVar1 != uVar10);
            }
        }
    }
    return;
}



// AdaptiveBuffer_R32::SetBufferOffset(unsigned int)

void AdaptiveBuffer_R32::SetBufferOffset(uint param_1) {
    this->bufferOffset = param_1;
    return;
}



// AdaptiveBuffer_R32::GetBufferPointer()

void * AdaptiveBuffer_R32::GetBufferPointer() {
    return this->bufferPointer;
}



// AdaptiveBuffer_R32::GetBufferLength()

uint AdaptiveBuffer_R32::GetBufferLength() {
    return this->bufferLength;
}



// AdaptiveBuffer_R32::GetBufferOffset()

undefined4 AdaptiveBuffer_R32::GetBufferOffset() {
    return this->bufferOffset;
}



// AdaptiveBuffer_R32::GetChannels()

uint AdaptiveBuffer_R32::GetChannels() {
    return this->channels;
}
