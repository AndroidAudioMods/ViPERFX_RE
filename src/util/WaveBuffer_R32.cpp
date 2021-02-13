//
// Created by mart on 2/12/21.
//

#include "WaveBuffer_R32.h"



// WaveBuffer_R32::WaveBuffer_R32(unsigned int, unsigned int)

WaveBuffer_R32::WaveBuffer_R32(uint param_1,uint param_2) {
    void *pvVar1;

    *(uint *)&this->field_0xc = param_1;
    *(uint *)&this->field_0x4 = param_2 * param_1;
    *(undefined4 *)&this->field_0x8 = 0;
    pvVar1 = valloc(param_2 * param_1 * 4);
    *(void **)this = pvVar1;
    return this;
}



// WaveBuffer_R32::~WaveBuffer_R32()

WaveBuffer_R32::~WaveBuffer_R32() {
    if (*(void **)this != nullptr) {
        free(*(void **)this);
    }
    *(undefined4 *)this = 0;
    return this;
}



// WaveBuffer_R32::Short2Float(short*, float*, unsigned int)

void WaveBuffer_R32::Short2Float(short *param_1,float *param_2,uint param_3) {
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

    uVar7 = *(int *)&this->field_0xc * param_3;
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



// WaveBuffer_R32::Float2Short(float*, short*, unsigned int)

void WaveBuffer_R32::Float2Short(float *param_1,short *param_2,uint param_3) {
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

    uVar8 = *(int *)&this->field_0xc * param_3;
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



// WaveBuffer_R32::Int2Float(int*, float*, unsigned int)

void WaveBuffer_R32::Int2Float(int *param_1,float *param_2,uint param_3) {
    undefined4 uVar1;
    int iVar2;
    uint uVar3;
    int *piVar4;
    float *pfVar5;
    undefined8 *puVar6;
    uint uVar7;
    uint uVar8;
    undefined4 in_cr7;
    undefined auVar9 [16];
    int iVar10;
    undefined auVar11 [16];
    undefined auVar12 [16];
    undefined auVar13 [16];
    undefined auVar14 [16];
    undefined auVar15 [16];
    undefined auVar16 [16];
    undefined auVar17 [16];

    uVar7 = *(int *)&this->field_0xc * param_3;
    if (uVar7 < 0x20) {
        iVar2 = uVar7 - 1;
        if (uVar7 != 0) {
            piVar4 = param_1 + uVar7;
            pfVar5 = param_2 + uVar7;
            do {
                piVar4 = piVar4 + -1;
                iVar2 = iVar2 + -1;
                coprocessor_function(10,6,4,in_cr7,in_cr7,in_cr7);
                pfVar5 = pfVar5 + -1;
                *pfVar5 = (float)(longlong)*piVar4;
            } while (iVar2 != -1);
        }
    }
    else {
        uVar8 = uVar7 & 0xffffffe0;
        if (uVar8 != 0) {
            uVar3 = 0;
            piVar4 = param_1;
            puVar6 = (undefined8 *)param_2;
            do {
                uVar3 = uVar3 + 0x20;
                auVar9 = FixedToFP(CONCAT88(CONCAT44(piVar4[1],piVar4[1]),CONCAT44(*piVar4,*piVar4)),0x20,
                                   0x20,0,0,0);
                auVar17 = FixedToFP(CONCAT88(CONCAT44(piVar4[5],piVar4[5]),CONCAT44(piVar4[4],piVar4[4])),
                                    0x20,0x20,0,0,0);
                param_1 = piVar4 + 0x20;
                auVar16 = FixedToFP(CONCAT88(CONCAT44(piVar4[9],piVar4[9]),CONCAT44(piVar4[8],piVar4[8])),
                                    0x20,0x20,0,0,0);
                param_2 = (float *)(puVar6 + 0x10);
                auVar15 = FixedToFP(CONCAT88(CONCAT44(piVar4[0xd],piVar4[0xd]),
                                             CONCAT44(piVar4[0xc],piVar4[0xc])),0x20,0x20,0,0,0);
                auVar14 = FixedToFP(CONCAT88(CONCAT44(piVar4[0x11],piVar4[0x11]),
                                             CONCAT44(piVar4[0x10],piVar4[0x10])),0x20,0x20,0,0,0);
                auVar13 = FixedToFP(CONCAT88(CONCAT44(piVar4[0x15],piVar4[0x15]),
                                             CONCAT44(piVar4[0x14],piVar4[0x14])),0x20,0x20,0,0,0);
                auVar12 = FixedToFP(CONCAT88(CONCAT44(piVar4[0x19],piVar4[0x19]),
                                             CONCAT44(piVar4[0x18],piVar4[0x18])),0x20,0x20,0,0,0);
                auVar11 = FixedToFP(CONCAT88(CONCAT44(piVar4[0x1d],piVar4[0x1d]),
                                             CONCAT44(piVar4[0x1c],piVar4[0x1c])),0x20,0x20,0,0,0);
                auVar9 = FloatVectorMult(auVar9,CONCAT88(0x3300000033000000,0x3300000033000000),2,0x20);
                auVar17 = FloatVectorMult(auVar17,CONCAT88(0x3300000033000000,0x3300000033000000),2,0x20);
                auVar16 = FloatVectorMult(auVar16,CONCAT88(0x3300000033000000,0x3300000033000000),2,0x20);
                *puVar6 = CONCAT44(SUB164(auVar9,0),SUB164(auVar9,0));
                uVar1 = SUB164(auVar9 >> 0x40,0);
                *(ulonglong *)((int)puVar6 + 4) = CONCAT44(uVar1,uVar1);
                auVar15 = FloatVectorMult(auVar15,CONCAT88(0x3300000033000000,0x3300000033000000),2,0x20);
                auVar14 = FloatVectorMult(auVar14,CONCAT88(0x3300000033000000,0x3300000033000000),2,0x20);
                puVar6[2] = CONCAT44(SUB164(auVar17,0),SUB164(auVar17,0));
                uVar1 = SUB164(auVar17 >> 0x40,0);
                *(ulonglong *)((int)puVar6 + 0x14) = CONCAT44(uVar1,uVar1);
                auVar13 = FloatVectorMult(auVar13,CONCAT88(0x3300000033000000,0x3300000033000000),2,0x20);
                auVar12 = FloatVectorMult(auVar12,CONCAT88(0x3300000033000000,0x3300000033000000),2,0x20);
                puVar6[4] = CONCAT44(SUB164(auVar16,0),SUB164(auVar16,0));
                uVar1 = SUB164(auVar16 >> 0x40,0);
                *(ulonglong *)((int)puVar6 + 0x24) = CONCAT44(uVar1,uVar1);
                auVar9 = FloatVectorMult(auVar11,CONCAT88(0x3300000033000000,0x3300000033000000),2,0x20);
                puVar6[6] = CONCAT44(SUB164(auVar15,0),SUB164(auVar15,0));
                uVar1 = SUB164(auVar15 >> 0x40,0);
                *(ulonglong *)((int)puVar6 + 0x34) = CONCAT44(uVar1,uVar1);
                puVar6[8] = CONCAT44(SUB164(auVar14,0),SUB164(auVar14,0));
                uVar1 = SUB164(auVar14 >> 0x40,0);
                *(ulonglong *)((int)puVar6 + 0x44) = CONCAT44(uVar1,uVar1);
                puVar6[10] = CONCAT44(SUB164(auVar13,0),SUB164(auVar13,0));
                uVar1 = SUB164(auVar13 >> 0x40,0);
                *(ulonglong *)((int)puVar6 + 0x54) = CONCAT44(uVar1,uVar1);
                puVar6[0xc] = CONCAT44(SUB164(auVar12,0),SUB164(auVar12,0));
                uVar1 = SUB164(auVar12 >> 0x40,0);
                *(ulonglong *)((int)puVar6 + 100) = CONCAT44(uVar1,uVar1);
                puVar6[0xe] = CONCAT44(SUB164(auVar9,0),SUB164(auVar9,0));
                uVar1 = SUB164(auVar9 >> 0x40,0);
                *(ulonglong *)((int)puVar6 + 0x74) = CONCAT44(uVar1,uVar1);
                piVar4 = param_1;
                puVar6 = (undefined8 *)param_2;
            } while (uVar3 < uVar8);
        }
        iVar2 = (uVar7 - uVar8) + -1;
        if (uVar7 - uVar8 != 0) {
            do {
                iVar10 = *param_1;
                param_1 = param_1 + 1;
                iVar2 = iVar2 + -1;
                coprocessor_function(10,6,4,in_cr7,in_cr7,in_cr7);
                *param_2 = (float)(longlong)iVar10;
                param_2 = (float *)((int)param_2 + 4);
            } while (iVar2 != -1);
            return;
        }
    }
    return;
}



// WaveBuffer_R32::Float2Int(float*, int*, unsigned int)

void WaveBuffer_R32::Float2Int(float *param_1,int *param_2,uint param_3) {
    undefined4 uVar1;
    int iVar2;
    uint uVar3;
    float *pfVar4;
    float *pfVar5;
    undefined8 *puVar6;
    uint uVar7;
    uint uVar8;
    undefined4 in_cr7;
    float fVar9;
    undefined in_q3 [16];
    float fVar11;
    undefined auVar10 [16];
    undefined auVar12 [16];
    undefined auVar13 [16];
    undefined auVar14 [16];
    undefined auVar15 [16];
    undefined auVar16 [16];
    undefined auVar17 [16];
    undefined auVar18 [16];

    uVar7 = *(int *)&this->field_0xc * param_3;
    if (uVar7 < 0x20) {
        iVar2 = uVar7 - 1;
        if (uVar7 != 0) {
            auVar10 = CONCAT412(SUB164(in_q3 >> 0x60,0),
                                CONCAT48(0x3f000000,
                                         SUB128(CONCAT84(SUB168(in_q3 >> 0x40,0),0x4c000000),0) << 0x20));
            pfVar4 = param_1 + uVar7;
            pfVar5 = (float *)(param_2 + uVar7);
            do {
                pfVar4 = pfVar4 + -1;
                iVar2 = iVar2 + -1;
                fVar9 = SUB164(auVar10 >> 0x40,0) + *pfVar4 * SUB164(auVar10 >> 0x20,0);
                fVar11 = ROUND(fVar9);
                auVar10 = CONCAT412(fVar11,SUB1612(CONCAT124(SUB1612(CONCAT412(*pfVar4,SUB1612(auVar10,0))
                                                                             >> 0x20,0),fVar9),0));
                pfVar5 = pfVar5 + -1;
                *pfVar5 = fVar11;
            } while (iVar2 != -1);
        }
    }
    else {
        uVar8 = uVar7 & 0xffffffe0;
        if (uVar8 != 0) {
            uVar3 = 0;
            pfVar4 = param_1;
            puVar6 = (undefined8 *)param_2;
            do {
                uVar3 = uVar3 + 0x20;
                auVar10 = FloatVectorMult(CONCAT88(CONCAT44(pfVar4[1],pfVar4[1]),CONCAT44(*pfVar4,*pfVar4)),
                                          CONCAT88(0x4c0000004c000000,0x4c0000004c000000),2,0x20);
                auVar18 = FloatVectorMult(CONCAT88(CONCAT44(pfVar4[5],pfVar4[5]),
                                                   CONCAT44(pfVar4[4],pfVar4[4])),
                                          CONCAT88(0x4c0000004c000000,0x4c0000004c000000),2,0x20);
                param_1 = pfVar4 + 0x20;
                auVar17 = FloatVectorMult(CONCAT88(CONCAT44(pfVar4[9],pfVar4[9]),
                                                   CONCAT44(pfVar4[8],pfVar4[8])),
                                          CONCAT88(0x4c0000004c000000,0x4c0000004c000000),2,0x20);
                param_2 = (int *)(puVar6 + 0x10);
                auVar16 = FloatVectorMult(CONCAT88(CONCAT44(pfVar4[0xd],pfVar4[0xd]),
                                                   CONCAT44(pfVar4[0xc],pfVar4[0xc])),
                                          CONCAT88(0x4c0000004c000000,0x4c0000004c000000),2,0x20);
                auVar15 = FloatVectorMult(CONCAT88(CONCAT44(pfVar4[0x11],pfVar4[0x11]),
                                                   CONCAT44(pfVar4[0x10],pfVar4[0x10])),
                                          CONCAT88(0x4c0000004c000000,0x4c0000004c000000),2,0x20);
                auVar14 = FloatVectorMult(CONCAT88(CONCAT44(pfVar4[0x15],pfVar4[0x15]),
                                                   CONCAT44(pfVar4[0x14],pfVar4[0x14])),
                                          CONCAT88(0x4c0000004c000000,0x4c0000004c000000),2,0x20);
                auVar13 = FloatVectorMult(CONCAT88(CONCAT44(pfVar4[0x19],pfVar4[0x19]),
                                                   CONCAT44(pfVar4[0x18],pfVar4[0x18])),
                                          CONCAT88(0x4c0000004c000000,0x4c0000004c000000),2,0x20);
                auVar12 = FloatVectorMult(CONCAT88(CONCAT44(pfVar4[0x1d],pfVar4[0x1d]),
                                                   CONCAT44(pfVar4[0x1c],pfVar4[0x1c])),
                                          CONCAT88(0x4c0000004c000000,0x4c0000004c000000),2,0x20);
                auVar10 = FPToFixed(auVar10,0x20,0x20,0,0,3);
                auVar18 = FPToFixed(auVar18,0x20,0x20,0,0,3);
                auVar17 = FPToFixed(auVar17,0x20,0x20,0,0,3);
                *puVar6 = CONCAT44(SUB164(auVar10,0),SUB164(auVar10,0));
                uVar1 = SUB164(auVar10 >> 0x40,0);
                *(ulonglong *)((int)puVar6 + 4) = CONCAT44(uVar1,uVar1);
                auVar16 = FPToFixed(auVar16,0x20,0x20,0,0,3);
                auVar15 = FPToFixed(auVar15,0x20,0x20,0,0,3);
                puVar6[2] = CONCAT44(SUB164(auVar18,0),SUB164(auVar18,0));
                uVar1 = SUB164(auVar18 >> 0x40,0);
                *(ulonglong *)((int)puVar6 + 0x14) = CONCAT44(uVar1,uVar1);
                auVar14 = FPToFixed(auVar14,0x20,0x20,0,0,3);
                auVar13 = FPToFixed(auVar13,0x20,0x20,0,0,3);
                puVar6[4] = CONCAT44(SUB164(auVar17,0),SUB164(auVar17,0));
                uVar1 = SUB164(auVar17 >> 0x40,0);
                *(ulonglong *)((int)puVar6 + 0x24) = CONCAT44(uVar1,uVar1);
                auVar10 = FPToFixed(auVar12,0x20,0x20,0,0,3);
                puVar6[6] = CONCAT44(SUB164(auVar16,0),SUB164(auVar16,0));
                uVar1 = SUB164(auVar16 >> 0x40,0);
                *(ulonglong *)((int)puVar6 + 0x34) = CONCAT44(uVar1,uVar1);
                puVar6[8] = CONCAT44(SUB164(auVar15,0),SUB164(auVar15,0));
                uVar1 = SUB164(auVar15 >> 0x40,0);
                *(ulonglong *)((int)puVar6 + 0x44) = CONCAT44(uVar1,uVar1);
                puVar6[10] = CONCAT44(SUB164(auVar14,0),SUB164(auVar14,0));
                uVar1 = SUB164(auVar14 >> 0x40,0);
                *(ulonglong *)((int)puVar6 + 0x54) = CONCAT44(uVar1,uVar1);
                puVar6[0xc] = CONCAT44(SUB164(auVar13,0),SUB164(auVar13,0));
                uVar1 = SUB164(auVar13 >> 0x40,0);
                *(ulonglong *)((int)puVar6 + 100) = CONCAT44(uVar1,uVar1);
                puVar6[0xe] = CONCAT44(SUB164(auVar10,0),SUB164(auVar10,0));
                uVar1 = SUB164(auVar10 >> 0x40,0);
                *(ulonglong *)((int)puVar6 + 0x74) = CONCAT44(uVar1,uVar1);
                pfVar4 = param_1;
                puVar6 = (undefined8 *)param_2;
            } while (uVar3 < uVar8);
        }
        iVar2 = (uVar7 - uVar8) + -1;
        if (uVar7 - uVar8 != 0) {
            do {
                fVar9 = *param_1;
                param_1 = param_1 + 1;
                iVar2 = iVar2 + -1;
                coprocessor_function(10,6,4,in_cr7,in_cr7,in_cr7);
                *param_2 = (int)ROUND(fVar9);
                param_2 = (int *)((int)param_2 + 4);
            } while (iVar2 != -1);
            return;
        }
    }
    return;
}



// WaveBuffer_R32::PushZerosGetBuffer(unsigned int)

void * WaveBuffer_R32::PushZerosGetBuffer(uint param_1) {
    uint uVar1;
    int iVar2;
    void *pvVar3;
    int iVar4;

    pvVar3 = *(void **)this;
    if (pvVar3 == nullptr) {
        return nullptr;
    }
    if (param_1 != 0) {
        iVar4 = *(int *)&this->field_0x8;
        iVar2 = *(int *)&this->field_0xc;
        uVar1 = iVar2 * param_1 + iVar4;
        if (*(uint *)&this->field_0x4 < uVar1) {
            pvVar3 = valloc(uVar1 * 4);
            if (pvVar3 == nullptr) {
                return nullptr;
            }
            memcpy(pvVar3,*(void **)this,*(int *)&this->field_0x8 << 2);
            free(*(void **)this);
            iVar4 = *(int *)&this->field_0x8;
            iVar2 = *(int *)&this->field_0xc;
            *(void **)this = pvVar3;
            *(uint *)&this->field_0x4 = iVar2 * param_1 + iVar4;
        }
        pvVar3 = (void *)((int)pvVar3 + iVar4 * 4);
        memset(pvVar3,0,iVar2 * param_1 * 4);
        *(uint *)&this->field_0x8 = *(int *)&this->field_0xc * param_1 + *(int *)&this->field_0x8;
        return pvVar3;
    }
    return (void *)((int)pvVar3 + *(int *)&this->field_0x8 * 4);
}



// WaveBuffer_R32::PushZeros(unsigned int)

undefined4 WaveBuffer_R32::PushZeros(uint param_1) {
    uint uVar1;
    int iVar2;
    int iVar3;
    void *__dest;

    __dest = *(void **)this;
    if (__dest == nullptr) {
        return 0;
    }
    if (param_1 != 0) {
        iVar2 = *(int *)&this->field_0x8;
        iVar3 = *(int *)&this->field_0xc;
        uVar1 = iVar3 * param_1 + iVar2;
        if (*(uint *)&this->field_0x4 < uVar1) {
            __dest = valloc(uVar1 * 4);
            if (__dest == nullptr) {
                return 0;
            }
            memcpy(__dest,*(void **)this,*(int *)&this->field_0x8 << 2);
            free(*(void **)this);
            iVar2 = *(int *)&this->field_0x8;
            iVar3 = *(int *)&this->field_0xc;
            *(void **)this = __dest;
            *(uint *)&this->field_0x4 = iVar3 * param_1 + iVar2;
        }
        memset((void *)((int)__dest + iVar2 * 4),0,iVar3 * param_1 * 4);
        *(uint *)&this->field_0x8 = *(int *)&this->field_0xc * param_1 + *(int *)&this->field_0x8;
        return 1;
    }
    return 1;
}



// WaveBuffer_R32::PushSamples(short*, unsigned int)

undefined4 WaveBuffer_R32::PushSamples(short *param_1,uint param_2) {
    uint uVar1;
    int iVar2;
    void *__dest;

    __dest = *(void **)this;
    if (__dest == nullptr) {
        return 0;
    }
    if (param_2 != 0) {
        iVar2 = *(int *)&this->field_0x8;
        uVar1 = *(int *)&this->field_0xc * param_2 + iVar2;
        if (*(uint *)&this->field_0x4 < uVar1) {
            __dest = valloc(uVar1 * 4);
            if (__dest == nullptr) {
                return 0;
            }
            memcpy(__dest,*(void **)this,*(int *)&this->field_0x8 << 2);
            free(*(void **)this);
            iVar2 = *(int *)&this->field_0x8;
            *(void **)this = __dest;
            *(uint *)&this->field_0x4 = *(int *)&this->field_0xc * param_2 + iVar2;
        }
        Short2Float(this,param_1,(float *)((int)__dest + iVar2 * 4),param_2);
        *(uint *)&this->field_0x8 = *(int *)&this->field_0xc * param_2 + *(int *)&this->field_0x8;
        return 1;
    }
    return 1;
}



// WaveBuffer_R32::PushSamples(int*, unsigned int)

undefined4 WaveBuffer_R32::PushSamples(int *param_1,uint param_2) {
    uint uVar1;
    int iVar2;
    void *__dest;

    __dest = *(void **)this;
    if (__dest == nullptr) {
        return 0;
    }
    if (param_2 != 0) {
        iVar2 = *(int *)&this->field_0x8;
        uVar1 = *(int *)&this->field_0xc * param_2 + iVar2;
        if (*(uint *)&this->field_0x4 < uVar1) {
            __dest = valloc(uVar1 * 4);
            if (__dest == nullptr) {
                return 0;
            }
            memcpy(__dest,*(void **)this,*(int *)&this->field_0x8 << 2);
            free(*(void **)this);
            iVar2 = *(int *)&this->field_0x8;
            *(void **)this = __dest;
            *(uint *)&this->field_0x4 = *(int *)&this->field_0xc * param_2 + iVar2;
        }
        Int2Float(this,param_1,(float *)((int)__dest + iVar2 * 4),param_2);
        *(uint *)&this->field_0x8 = *(int *)&this->field_0xc * param_2 + *(int *)&this->field_0x8;
        return 1;
    }
    return 1;
}



// WaveBuffer_R32::PushSamples(float*, unsigned int)

undefined4 WaveBuffer_R32::PushSamples(float *param_1,uint param_2) {
    uint uVar1;
    int iVar2;
    int iVar3;
    void *__dest;

    __dest = *(void **)this;
    if (__dest == nullptr) {
        return 0;
    }
    if (param_2 != 0) {
        iVar2 = *(int *)&this->field_0x8;
        iVar3 = *(int *)&this->field_0xc;
        uVar1 = iVar3 * param_2 + iVar2;
        if (*(uint *)&this->field_0x4 < uVar1) {
            __dest = valloc(uVar1 * 4);
            if (__dest == nullptr) {
                return 0;
            }
            memcpy(__dest,*(void **)this,*(int *)&this->field_0x8 << 2);
            free(*(void **)this);
            iVar2 = *(int *)&this->field_0x8;
            iVar3 = *(int *)&this->field_0xc;
            *(void **)this = __dest;
            *(uint *)&this->field_0x4 = iVar3 * param_2 + iVar2;
        }
        memcpy((void *)((int)__dest + iVar2 * 4),param_1,iVar3 * param_2 * 4);
        *(uint *)&this->field_0x8 = *(int *)&this->field_0xc * param_2 + *(int *)&this->field_0x8;
        return 1;
    }
    return 1;
}



// WaveBuffer_R32::PopSamples(unsigned int, bool)

uint WaveBuffer_R32::PopSamples(uint param_1,bool param_2) {
    uint uVar1;
    void *__dest;
    uint uVar2;

    __dest = *(void **)this;
    if (__dest == nullptr) {
        return 0;
    }
    if (*(int *)&this->field_0x4 == 0) {
        return 0;
    }
    uVar1 = *(uint *)&this->field_0x8;
    uVar2 = *(int *)&this->field_0xc * param_1;
    if (uVar2 < uVar1 || uVar2 - uVar1 == 0) {
        *(uint *)&this->field_0x8 = uVar1 - uVar2;
        memmove(__dest,(void *)((int)__dest + uVar2 * 4),(uVar1 - uVar2) * 4);
        return param_1;
    }
    if (param_2 == false) {
        return 0;
    }
    uVar1 = __udivsi3();
    *(undefined4 *)&this->field_0x8 = 0;
    return uVar1;
}



// WaveBuffer_R32::PopSamples(short*, unsigned int, bool)

uint WaveBuffer_R32::PopSamples(short *param_1,uint param_2,bool param_3) {
    int iVar1;
    uint uVar2;
    int iVar3;
    float *pfVar4;
    uint uVar5;

    pfVar4 = *(float **)this;
    if (pfVar4 == nullptr) {
        return 0;
    }
    if (*(int *)&this->field_0x4 == 0) {
        return 0;
    }
    uVar2 = *(uint *)&this->field_0x8;
    uVar5 = *(int *)&this->field_0xc * param_2;
    if (uVar5 < uVar2 || uVar5 - uVar2 == 0) {
        Float2Short(this,pfVar4,param_1,param_2);
        iVar1 = *(int *)&this->field_0xc * param_2;
        iVar3 = *(int *)&this->field_0x8 - iVar1;
        *(int *)&this->field_0x8 = iVar3;
        memmove(*(void **)this,(void *)((int)*(void **)this + iVar1 * 4),iVar3 * 4);
        return param_2;
    }
    if (param_3 == false) {
        return 0;
    }
    uVar2 = __udivsi3(uVar2);
    Float2Short(this,pfVar4,param_1,uVar2);
    *(undefined4 *)&this->field_0x8 = 0;
    return uVar2;
}



// WaveBuffer_R32::PopSamples(int*, unsigned int, bool)

uint WaveBuffer_R32::PopSamples(int *param_1,uint param_2,bool param_3) {
    int iVar1;
    uint uVar2;
    int iVar3;
    float *pfVar4;
    uint uVar5;

    pfVar4 = *(float **)this;
    if (pfVar4 == nullptr) {
        return 0;
    }
    if (*(int *)&this->field_0x4 == 0) {
        return 0;
    }
    uVar2 = *(uint *)&this->field_0x8;
    uVar5 = *(int *)&this->field_0xc * param_2;
    if (uVar5 < uVar2 || uVar5 - uVar2 == 0) {
        Float2Int(this,pfVar4,param_1,param_2);
        iVar1 = *(int *)&this->field_0xc * param_2;
        iVar3 = *(int *)&this->field_0x8 - iVar1;
        *(int *)&this->field_0x8 = iVar3;
        memmove(*(void **)this,(void *)((int)*(void **)this + iVar1 * 4),iVar3 * 4);
        return param_2;
    }
    if (param_3 == false) {
        return 0;
    }
    uVar2 = __udivsi3(uVar2);
    Float2Int(this,pfVar4,param_1,uVar2);
    *(undefined4 *)&this->field_0x8 = 0;
    return uVar2;
}



// WaveBuffer_R32::PopSamples(float*, unsigned int, bool)

uint WaveBuffer_R32::PopSamples(float *param_1,uint param_2,bool param_3) {
    int iVar1;
    uint uVar2;
    int iVar3;
    void *__src;
    uint uVar4;

    __src = *(void **)this;
    if (__src == nullptr) {
        return 0;
    }
    if (*(int *)&this->field_0x4 == 0) {
        return 0;
    }
    uVar4 = *(uint *)&this->field_0x8;
    uVar2 = *(int *)&this->field_0xc * param_2;
    if (uVar2 < uVar4 || uVar2 - uVar4 == 0) {
        memcpy(param_1,__src,uVar2 * 4);
        iVar1 = *(int *)&this->field_0xc * param_2;
        iVar3 = *(int *)&this->field_0x8 - iVar1;
        *(int *)&this->field_0x8 = iVar3;
        memmove(*(void **)this,(void *)((int)*(void **)this + iVar1 * 4),iVar3 * 4);
        return param_2;
    }
    if (param_3 == false) {
        return 0;
    }
    uVar2 = __udivsi3(uVar4);
    memcpy(param_1,__src,uVar4 << 2);
    *(undefined4 *)&this->field_0x8 = 0;
    return uVar2;
}



// WaveBuffer_R32::Reset()

void WaveBuffer_R32::Reset() {
    *(undefined4 *)&this->field_0x8 = 0;
    return;
}



// WaveBuffer_R32::SetBufferOffset(unsigned int)

void WaveBuffer_R32::SetBufferOffset(uint param_1) {
    uint uVar1;
    int iVar2;

    iVar2 = *(int *)&this->field_0xc;
    uVar1 = __udivsi3(*(undefined4 *)&this->field_0x4,iVar2);
    if (param_1 <= uVar1) {
        *(uint *)&this->field_0x8 = iVar2 * param_1;
    }
    return;
}



// WaveBuffer_R32::GetBufferOffset()

void WaveBuffer_R32::GetBufferOffset(void) {
    int in_r0;

    __udivsi3(*(undefined4 *)(in_r0 + 8),*(undefined4 *)(in_r0 + 0xc));
    return;
}



// WaveBuffer_R32::GetBufferSize()

void WaveBuffer_R32::GetBufferSize(void) {
    int in_r0;

    __udivsi3(*(undefined4 *)(in_r0 + 4),*(undefined4 *)(in_r0 + 0xc));
    return;
}



// WaveBuffer_R32::GetCurrentBufferR32Ptr()

undefined4 WaveBuffer_R32::GetCurrentBufferR32Ptr() {
    return *(undefined4 *)this;
}
