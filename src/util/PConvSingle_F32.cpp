//
// Created by mart on 2/12/21.
//

#include "PConvSingle_F32.h"


// PConvSingle_F32::PConvSingle_F32()

void PConvSingle_F32::PConvSingle_F32() {
    *this = (PConvSingle_F32)0x0;
    *(undefined4 *)(this + 4) = 0;
    *(undefined4 *)(this + 8) = 0;
    *(undefined4 *)(this + 0xc) = 0;
    return;
}



// PConvSingle_F32::ReleaseResources()

void PConvSingle_F32::ReleaseResources() {
    void *pvVar1;
    void *__ptr;
    int iVar2;

    __ptr = *(void **)(this + 0xc);
    if (__ptr != nullptr) {
        if (*(int *)((int)__ptr + 0x124) != 0) {
            ffts_free();
            __ptr = *(void **)(this + 0xc);
        }
        if (*(int *)((int)__ptr + 0x128) != 0) {
            ffts_free();
            __ptr = *(void **)(this + 0xc);
        }
        if (*(void **)((int)__ptr + 0x120) != nullptr) {
            free(*(void **)((int)__ptr + 0x120));
            __ptr = *(void **)(this + 0xc);
        }
        pvVar1 = *(void **)((int)__ptr + 0xe0);
        if (pvVar1 != nullptr) {
            if (0 < *(int *)((int)__ptr + 0xc4)) {
                iVar2 = 0;
                do {
                    pvVar1 = *(void **)((int)pvVar1 + iVar2 * 4);
                    iVar2 = iVar2 + 1;
                    if (pvVar1 != nullptr) {
                        free(pvVar1);
                        __ptr = *(void **)(this + 0xc);
                    }
                    pvVar1 = *(void **)((int)__ptr + 0xe0);
                } while (iVar2 < *(int *)((int)__ptr + 0xc4));
            }
            free(pvVar1);
            __ptr = *(void **)(this + 0xc);
        }
        pvVar1 = *(void **)((int)__ptr + 0x100);
        if (pvVar1 != nullptr) {
            if (0 < *(int *)((int)__ptr + 0xc4)) {
                iVar2 = 0;
                do {
                    pvVar1 = *(void **)((int)pvVar1 + iVar2 * 4);
                    iVar2 = iVar2 + 1;
                    if (pvVar1 != nullptr) {
                        free(pvVar1);
                        __ptr = *(void **)(this + 0xc);
                    }
                    pvVar1 = *(void **)((int)__ptr + 0x100);
                } while (iVar2 < *(int *)((int)__ptr + 0xc4));
            }
            free(pvVar1);
            __ptr = *(void **)(this + 0xc);
        }
        pvVar1 = *(void **)((int)__ptr + 0xa0);
        if (pvVar1 != nullptr) {
            if (0 < *(int *)((int)__ptr + 0x84)) {
                iVar2 = 0;
                do {
                    pvVar1 = *(void **)((int)pvVar1 + iVar2 * 4);
                    iVar2 = iVar2 + 1;
                    if (pvVar1 != nullptr) {
                        free(pvVar1);
                        __ptr = *(void **)(this + 0xc);
                    }
                    pvVar1 = *(void **)((int)__ptr + 0xa0);
                } while (iVar2 < *(int *)((int)__ptr + 0x84));
            }
            free(pvVar1);
            __ptr = *(void **)(this + 0xc);
        }
        pvVar1 = *(void **)((int)__ptr + 0xc0);
        if (pvVar1 != nullptr) {
            if (0 < *(int *)((int)__ptr + 0x84)) {
                iVar2 = 0;
                do {
                    pvVar1 = *(void **)((int)pvVar1 + iVar2 * 4);
                    iVar2 = iVar2 + 1;
                    if (pvVar1 != nullptr) {
                        free(pvVar1);
                        __ptr = *(void **)(this + 0xc);
                    }
                    pvVar1 = *(void **)((int)__ptr + 0xc0);
                } while (iVar2 < *(int *)((int)__ptr + 0x84));
            }
            free(pvVar1);
            __ptr = *(void **)(this + 0xc);
        }
        if (*(void **)((int)__ptr + 0x60) != nullptr) {
            free(*(void **)((int)__ptr + 0x60));
            __ptr = *(void **)(this + 0xc);
        }
        if (*(void **)((int)__ptr + 0x80) != nullptr) {
            free(*(void **)((int)__ptr + 0x80));
            __ptr = *(void **)(this + 0xc);
        }
        if (*(void **)((int)__ptr + 0x20) != nullptr) {
            free(*(void **)((int)__ptr + 0x20));
            __ptr = *(void **)(this + 0xc);
        }
        if (*(void **)((int)__ptr + 0x40) != nullptr) {
            free(*(void **)((int)__ptr + 0x40));
            __ptr = *(void **)(this + 0xc);
        }
        if (*(void **)((int)__ptr + 0xc) != nullptr) {
            free(*(void **)((int)__ptr + 0xc));
            __ptr = *(void **)(this + 0xc);
        }
        free(__ptr);
        *(undefined4 *)(this + 0xc) = 0;
    }
    *this = (PConvSingle_F32)0x0;
    *(undefined4 *)(this + 4) = 0;
    *(undefined4 *)(this + 8) = 0;
    return;
}



// PConvSingle_F32::~PConvSingle_F32()

PConvSingle_F32::~PConvSingle_F32() {
    ReleaseResources(this);
    return this;
}



// PConvSingle_F32::ProcessKernel(float const*, int, int)

undefined4 PConvSingle_F32::ProcessKernel(float *param_1,int param_2,int param_3) {
    int iVar1;
    void *pvVar2;
    int iVar3;
    undefined4 uVar4;
    int extraout_r1;
    int iVar5;
    float *pfVar6;
    int *piVar7;
    float *pfVar8;
    undefined4 *puVar9;
    size_t sVar10;
    int iVar11;
    float *pfVar12;
    undefined4 *puVar13;
    undefined4 *puVar14;
    undefined4 *puVar15;
    int iVar16;
    undefined4 *puVar17;
    int iVar18;
    int *piVar19;
    int *piVar20;
    undefined4 in_cr7;
    undefined4 in_cr8;
    float fVar21;

    iVar18 = *(int *)(this + 8);
    puVar17 = *(undefined4 **)(this + 0xc);
    *puVar17 = 0;
    puVar17[1] = param_3;
    puVar17[2] = 0;
    iVar1 = __divsi3(iVar18 + param_2 + -1,iVar18);
    *(int *)(this + 4) = iVar1;
    puVar17[0x21] = iVar1;
    puVar17[0x31] = iVar1 + 1;
    pvVar2 = valloc(iVar18 << 3);
    iVar1 = *(int *)(this + 0xc);
    puVar17[8] = pvVar2;
    if (*(int *)(iVar1 + 0x20) == 0) {
        return 0;
    }
    pvVar2 = valloc((*(int *)(this + 8) + 1) * 8);
    iVar18 = *(int *)(this + 0xc);
    *(void **)(iVar1 + 0x40) = pvVar2;
    if (*(int *)(iVar18 + 0x40) == 0) {
        return 0;
    }
    sVar10 = (*(int *)(this + 8) + 1) * 4;
    pvVar2 = valloc(sVar10);
    *(void **)(iVar18 + 0x60) = pvVar2;
    iVar1 = *(int *)(this + 0xc);
    pvVar2 = valloc(sVar10);
    iVar18 = *(int *)(this + 0xc);
    *(void **)(iVar1 + 0x80) = pvVar2;
    if (*(int *)(iVar18 + 0x60) == 0) {
        return 0;
    }
    if (*(int *)(iVar18 + 0x80) == 0) {
        return 0;
    }
    sVar10 = (param_3 + 1) * 4;
    pvVar2 = valloc(sVar10);
    iVar1 = *(int *)(this + 0xc);
    *(void **)(iVar18 + 0xc) = pvVar2;
    iVar18 = *(int *)(iVar1 + 0xc);
    if (iVar18 == 0) {
        return 0;
    }
    iVar11 = *(int *)(iVar1 + 0x84);
    iVar3 = __divsi3(iVar11,param_3);
    if (-1 < param_3) {
        iVar11 = 0;
        piVar7 = (int *)(iVar18 + -4);
        do {
            piVar7 = piVar7 + 1;
            *piVar7 = iVar11;
            iVar11 = iVar11 + iVar3;
        } while (piVar7 != (int *)(iVar18 + (sVar10 - 4)));
        iVar11 = *(int *)(iVar1 + 0x84);
    }
    if (*(int *)(iVar18 + 4) == 0) {
        iVar3 = 1;
    }
    else {
        iVar3 = 2;
    }
    __aeabi_idivmod(iVar11,param_3);
    iVar5 = iVar3 + extraout_r1;
    if (iVar3 < iVar5) {
        piVar7 = (int *)(iVar18 + (iVar3 + 0x3fffffff) * 4);
        do {
            piVar19 = piVar7;
            if (iVar3 <= param_3) {
                do {
                    piVar20 = piVar19 + 1;
                    *piVar20 = piVar19[1] + 1;
                    piVar19 = piVar20;
                } while (piVar20 != (int *)(iVar18 + (sVar10 - 4)));
            }
            iVar3 = iVar3 + 1;
            piVar7 = piVar7 + 1;
        } while (iVar3 != iVar5);
        iVar11 = *(int *)(iVar1 + 0x84);
    }
    sVar10 = iVar11 << 2;
    pvVar2 = valloc(sVar10);
    *(void **)(iVar1 + 0xa0) = pvVar2;
    iVar18 = *(int *)(this + 0xc);
    pvVar2 = valloc(sVar10);
    iVar1 = *(int *)(this + 0xc);
    *(void **)(iVar18 + 0xc0) = pvVar2;
    pvVar2 = *(void **)(iVar1 + 0xa0);
    if (pvVar2 == nullptr) {
        return 0;
    }
    if (*(int *)(iVar1 + 0xc0) == 0) {
        return 0;
    }
    memset(pvVar2,0,sVar10);
    memset(*(void **)(*(int *)(this + 0xc) + 0xc0),0,sVar10);
    iVar1 = *(int *)(this + 0xc);
    if (0 < *(int *)(iVar1 + 0x84)) {
        iVar3 = *(int *)(iVar1 + 0xa0);
        iVar18 = 0;
        do {
            sVar10 = (*(int *)(this + 8) + 1) * 4;
            pvVar2 = valloc(sVar10);
            *(void **)(iVar3 + iVar18 * 4) = pvVar2;
            iVar1 = *(int *)(*(int *)(this + 0xc) + 0xc0);
            pvVar2 = valloc(sVar10);
            *(void **)(iVar1 + iVar18 * 4) = pvVar2;
            iVar1 = *(int *)(this + 0xc);
            iVar3 = *(int *)(iVar1 + 0xa0);
            if (*(int *)(iVar3 + iVar18 * 4) == 0) {
                return 0;
            }
            iVar11 = iVar18 * 4;
            iVar18 = iVar18 + 1;
            if (*(int *)(*(int *)(iVar1 + 0xc0) + iVar11) == 0) {
                return 0;
            }
        } while (iVar18 < *(int *)(iVar1 + 0x84));
    }
    sVar10 = *(int *)(iVar1 + 0xc4) << 2;
    pvVar2 = valloc(sVar10);
    *(void **)(iVar1 + 0xe0) = pvVar2;
    iVar18 = *(int *)(this + 0xc);
    pvVar2 = valloc(sVar10);
    iVar1 = *(int *)(this + 0xc);
    *(void **)(iVar18 + 0x100) = pvVar2;
    pvVar2 = *(void **)(iVar1 + 0xe0);
    if (pvVar2 == nullptr) {
        return 0;
    }
    if (*(int *)(iVar1 + 0x100) == 0) {
        return 0;
    }
    memset(pvVar2,0,sVar10);
    memset(*(void **)(*(int *)(this + 0xc) + 0x100),0,sVar10);
    iVar1 = *(int *)(this + 0xc);
    if (0 < *(int *)(iVar1 + 0xc4)) {
        iVar18 = 0;
        do {
            iVar3 = iVar18 * 4;
            iVar1 = *(int *)(iVar1 + 0xe0);
            sVar10 = (*(int *)(this + 8) + 1) * 4;
            pvVar2 = valloc(sVar10);
            *(void **)(iVar1 + iVar18 * 4) = pvVar2;
            iVar1 = *(int *)(*(int *)(this + 0xc) + 0x100);
            pvVar2 = valloc(sVar10);
            *(void **)(iVar1 + iVar18 * 4) = pvVar2;
            pvVar2 = *(void **)(*(int *)(*(int *)(this + 0xc) + 0xe0) + iVar18 * 4);
            if (pvVar2 == nullptr) {
                return 0;
            }
            iVar1 = iVar18 * 4;
            iVar18 = iVar18 + 1;
            if (*(int *)(*(int *)(*(int *)(this + 0xc) + 0x100) + iVar1) == 0) {
                return 0;
            }
            memset(pvVar2,0,sVar10);
            memset(*(void **)(*(int *)(*(int *)(this + 0xc) + 0x100) + iVar3),0,sVar10);
            iVar1 = *(int *)(this + 0xc);
        } while (iVar18 < *(int *)(iVar1 + 0xc4));
    }
    iVar3 = *(int *)(this + 8);
    pvVar2 = valloc(iVar3 << 2);
    iVar18 = *(int *)(this + 0xc);
    *(void **)(iVar1 + 0x120) = pvVar2;
    if (*(void **)(iVar18 + 0x120) == nullptr) {
        return 0;
    }
    memset(*(void **)(iVar18 + 0x120),0,iVar3 << 2);
    iVar18 = *(int *)(this + 0xc);
    uVar4 = ffts_init_1d_real(*(int *)(this + 8) << 1,0xffffffff);
    iVar1 = *(int *)(this + 8);
    *(undefined4 *)(iVar18 + 0x124) = uVar4;
    iVar18 = *(int *)(this + 0xc);
    uVar4 = ffts_init_1d_real(iVar1 << 1);
    iVar1 = *(int *)(this + 0xc);
    *(undefined4 *)(iVar18 + 0x128) = uVar4;
    if (*(int *)(iVar1 + 0x124) == 0) {
        return 0;
    }
    if (*(int *)(iVar1 + 0x128) == 0) {
        return 0;
    }
    memset(*(void **)(iVar1 + 0x20),0,*(int *)(this + 8) << 3);
    iVar18 = *(int *)(this + 0xc);
    iVar1 = *(int *)(this + 8);
    if (*(int *)(iVar18 + 0x84) < 2) {
        iVar11 = 0;
        iVar5 = 1;
        iVar3 = iVar11;
    }
    else {
        iVar3 = 0;
        do {
            iVar5 = iVar3;
            pfVar6 = *(float **)(iVar18 + 0x20);
            if (0 < iVar1) {
                pfVar8 = param_1 + iVar1 * iVar5;
                pfVar12 = pfVar6;
                do {
                    fVar21 = *pfVar8;
                    pfVar8 = pfVar8 + 1;
                    coprocessor_function(10,6,4,in_cr7,in_cr7,in_cr8);
                    *pfVar12 = fVar21;
                    pfVar12 = pfVar12 + 1;
                } while (pfVar12 != pfVar6 + iVar1);
            }
            ffts_execute(*(undefined4 *)(iVar18 + 0x124),pfVar6,*(undefined4 *)(iVar18 + 0x40));
            iVar1 = *(int *)(this + 8);
            iVar18 = *(int *)(this + 0xc);
            if (-1 < iVar1) {
                puVar13 = *(undefined4 **)(*(int *)(iVar18 + 0xa0) + iVar5 * 4);
                puVar17 = *(undefined4 **)(*(int *)(iVar18 + 0xc0) + iVar5 * 4);
                puVar9 = (undefined4 *)(*(int *)(iVar18 + 0x40) + 4);
                puVar14 = puVar13;
                do {
                    puVar15 = puVar14 + 1;
                    *puVar14 = puVar9[-1];
                    *puVar17 = *puVar9;
                    puVar17 = puVar17 + 1;
                    puVar9 = puVar9 + 2;
                    puVar14 = puVar15;
                } while (puVar15 != puVar13 + iVar1 + 1);
            }
            iVar3 = iVar5 + 1;
        } while (iVar3 < *(int *)(iVar18 + 0x84) + -1);
        iVar11 = iVar1 * iVar3;
        iVar5 = iVar5 + 2;
    }
    iVar16 = param_2 - iVar11;
    if (iVar16 < 1) {
        sVar10 = (iVar1 * iVar5 - param_2) * 4;
        if (((int)sVar10 < 0) || (iVar16 < 0)) goto LAB_0006266c;
        pfVar6 = *(float **)(iVar18 + 0x20);
    }
    else {
        pfVar6 = *(float **)(iVar18 + 0x20);
        pfVar8 = param_1 + iVar11;
        pfVar12 = pfVar6;
        do {
            fVar21 = *pfVar8;
            pfVar8 = pfVar8 + 1;
            coprocessor_function(10,6,4,in_cr7,in_cr7,in_cr8);
            *pfVar12 = fVar21;
            pfVar12 = pfVar12 + 1;
        } while (pfVar12 != pfVar6 + iVar16);
        sVar10 = (iVar1 * iVar5 - param_2) * 4;
        if ((int)sVar10 < 0) goto LAB_0006266c;
    }
    memset(pfVar6 + iVar16,0,sVar10);
    iVar18 = *(int *)(this + 0xc);
    LAB_0006266c:
    ffts_execute(*(undefined4 *)(iVar18 + 0x124),*(undefined4 *)(iVar18 + 0x20),
                 *(undefined4 *)(iVar18 + 0x40));
    iVar1 = *(int *)(this + 8);
    if (-1 < iVar1) {
        iVar18 = *(int *)(this + 0xc);
        puVar13 = *(undefined4 **)(*(int *)(iVar18 + 0xa0) + iVar3 * 4);
        puVar17 = *(undefined4 **)(*(int *)(iVar18 + 0xc0) + iVar3 * 4);
        puVar9 = (undefined4 *)(*(int *)(iVar18 + 0x40) + 4);
        puVar14 = puVar13;
        do {
            puVar15 = puVar14 + 1;
            *puVar14 = puVar9[-1];
            *puVar17 = *puVar9;
            puVar17 = puVar17 + 1;
            puVar9 = puVar9 + 2;
            puVar14 = puVar15;
        } while (puVar15 != puVar13 + iVar1 + 1);
    }
    return 1;
}



// PConvSingle_F32::ProcessKernel(float const*, float, int, int)

undefined4 PConvSingle_F32::ProcessKernel(float *param_1,float param_2,int param_3,int param_4) {
int iVar1;
void *pvVar2;
int iVar3;
undefined4 uVar4;
int extraout_r1;
int iVar5;
float *pfVar6;
int *piVar7;
int *piVar8;
float *pfVar9;
undefined4 *puVar10;
size_t sVar11;
int iVar12;
int *piVar13;
float *pfVar14;
undefined4 *puVar15;
undefined4 *puVar16;
undefined4 *puVar17;
int iVar18;
undefined4 *puVar19;
int iVar20;
undefined4 in_cr7;
undefined4 in_cr8;
float fVar21;
int in_stack_00000000;

iVar20 = *(int *)(this + 8);
puVar19 = *(undefined4 **)(this + 0xc);
*puVar19 = 0;
puVar19[1] = in_stack_00000000;
puVar19[2] = 0;
iVar1 = __divsi3(iVar20 + param_4 + -1,iVar20);
*(int *)(this + 4) = iVar1;
puVar19[0x21] = iVar1;
puVar19[0x31] = iVar1 + 1;
pvVar2 = valloc(iVar20 << 3);
iVar1 = *(int *)(this + 0xc);
puVar19[8] = pvVar2;
if (*(int *)(iVar1 + 0x20) == 0) {
return 0;
}
pvVar2 = valloc((*(int *)(this + 8) + 1) * 8);
iVar20 = *(int *)(this + 0xc);
*(void **)(iVar1 + 0x40) = pvVar2;
if (*(int *)(iVar20 + 0x40) == 0) {
return 0;
}
sVar11 = (*(int *)(this + 8) + 1) * 4;
pvVar2 = valloc(sVar11);
*(void **)(iVar20 + 0x60) = pvVar2;
iVar1 = *(int *)(this + 0xc);
pvVar2 = valloc(sVar11);
iVar20 = *(int *)(this + 0xc);
*(void **)(iVar1 + 0x80) = pvVar2;
if (*(int *)(iVar20 + 0x60) == 0) {
return 0;
}
if (*(int *)(iVar20 + 0x80) == 0) {
return 0;
}
sVar11 = (in_stack_00000000 + 1) * 4;
pvVar2 = valloc(sVar11);
iVar1 = *(int *)(this + 0xc);
*(void **)(iVar20 + 0xc) = pvVar2;
iVar20 = *(int *)(iVar1 + 0xc);
if (iVar20 == 0) {
return 0;
}
iVar12 = *(int *)(iVar1 + 0x84);
iVar3 = __divsi3(iVar12,in_stack_00000000);
if (-1 < in_stack_00000000) {
iVar12 = 0;
piVar13 = (int *)(iVar20 + -4);
do {
piVar13 = piVar13 + 1;
*piVar13 = iVar12;
iVar12 = iVar12 + iVar3;
} while (piVar13 != (int *)(iVar20 + (sVar11 - 4)));
iVar12 = *(int *)(iVar1 + 0x84);
}
if (*(int *)(iVar20 + 4) == 0) {
iVar3 = 1;
}
else {
iVar3 = 2;
}
__aeabi_idivmod(iVar12,in_stack_00000000);
iVar5 = iVar3 + extraout_r1;
if (iVar3 < iVar5) {
piVar13 = (int *)(iVar20 + (iVar3 + 0x3fffffff) * 4);
do {
piVar7 = piVar13;
if (iVar3 <= in_stack_00000000) {
do {
piVar8 = piVar7 + 1;
*piVar8 = piVar7[1] + 1;
piVar7 = piVar8;
} while (piVar8 != (int *)(iVar20 + (sVar11 - 4)));
}
iVar3 = iVar3 + 1;
piVar13 = piVar13 + 1;
} while (iVar3 != iVar5);
iVar12 = *(int *)(iVar1 + 0x84);
}
sVar11 = iVar12 << 2;
pvVar2 = valloc(sVar11);
*(void **)(iVar1 + 0xa0) = pvVar2;
iVar20 = *(int *)(this + 0xc);
pvVar2 = valloc(sVar11);
iVar1 = *(int *)(this + 0xc);
*(void **)(iVar20 + 0xc0) = pvVar2;
pvVar2 = *(void **)(iVar1 + 0xa0);
if (pvVar2 == nullptr) {
return 0;
}
if (*(int *)(iVar1 + 0xc0) == 0) {
return 0;
}
memset(pvVar2,0,sVar11);
memset(*(void **)(*(int *)(this + 0xc) + 0xc0),0,sVar11);
iVar1 = *(int *)(this + 0xc);
if (0 < *(int *)(iVar1 + 0x84)) {
iVar3 = *(int *)(iVar1 + 0xa0);
iVar20 = 0;
do {
sVar11 = (*(int *)(this + 8) + 1) * 4;
pvVar2 = valloc(sVar11);
*(void **)(iVar3 + iVar20 * 4) = pvVar2;
iVar1 = *(int *)(*(int *)(this + 0xc) + 0xc0);
pvVar2 = valloc(sVar11);
*(void **)(iVar1 + iVar20 * 4) = pvVar2;
iVar1 = *(int *)(this + 0xc);
iVar3 = *(int *)(iVar1 + 0xa0);
if (*(int *)(iVar3 + iVar20 * 4) == 0) {
return 0;
}
iVar12 = iVar20 * 4;
iVar20 = iVar20 + 1;
if (*(int *)(*(int *)(iVar1 + 0xc0) + iVar12) == 0) {
return 0;
}
} while (iVar20 < *(int *)(iVar1 + 0x84));
}
sVar11 = *(int *)(iVar1 + 0xc4) << 2;
pvVar2 = valloc(sVar11);
*(void **)(iVar1 + 0xe0) = pvVar2;
iVar20 = *(int *)(this + 0xc);
pvVar2 = valloc(sVar11);
iVar1 = *(int *)(this + 0xc);
*(void **)(iVar20 + 0x100) = pvVar2;
pvVar2 = *(void **)(iVar1 + 0xe0);
if (pvVar2 == nullptr) {
return 0;
}
if (*(int *)(iVar1 + 0x100) == 0) {
return 0;
}
memset(pvVar2,0,sVar11);
memset(*(void **)(*(int *)(this + 0xc) + 0x100),0,sVar11);
iVar1 = *(int *)(this + 0xc);
if (0 < *(int *)(iVar1 + 0xc4)) {
iVar20 = 0;
do {
iVar3 = iVar20 * 4;
iVar1 = *(int *)(iVar1 + 0xe0);
sVar11 = (*(int *)(this + 8) + 1) * 4;
pvVar2 = valloc(sVar11);
*(void **)(iVar1 + iVar20 * 4) = pvVar2;
iVar1 = *(int *)(*(int *)(this + 0xc) + 0x100);
pvVar2 = valloc(sVar11);
*(void **)(iVar1 + iVar20 * 4) = pvVar2;
pvVar2 = *(void **)(*(int *)(*(int *)(this + 0xc) + 0xe0) + iVar20 * 4);
if (pvVar2 == nullptr) {
return 0;
}
iVar1 = iVar20 * 4;
iVar20 = iVar20 + 1;
if (*(int *)(*(int *)(*(int *)(this + 0xc) + 0x100) + iVar1) == 0) {
return 0;
}
memset(pvVar2,0,sVar11);
memset(*(void **)(*(int *)(*(int *)(this + 0xc) + 0x100) + iVar3),0,sVar11);
iVar1 = *(int *)(this + 0xc);
} while (iVar20 < *(int *)(iVar1 + 0xc4));
}
iVar3 = *(int *)(this + 8);
pvVar2 = valloc(iVar3 << 2);
iVar20 = *(int *)(this + 0xc);
*(void **)(iVar1 + 0x120) = pvVar2;
if (*(void **)(iVar20 + 0x120) == nullptr) {
return 0;
}
memset(*(void **)(iVar20 + 0x120),0,iVar3 << 2);
iVar20 = *(int *)(this + 0xc);
uVar4 = ffts_init_1d_real(*(int *)(this + 8) << 1,0xffffffff);
iVar1 = *(int *)(this + 8);
*(undefined4 *)(iVar20 + 0x124) = uVar4;
iVar20 = *(int *)(this + 0xc);
uVar4 = ffts_init_1d_real(iVar1 << 1);
iVar1 = *(int *)(this + 0xc);
*(undefined4 *)(iVar20 + 0x128) = uVar4;
if (*(int *)(iVar1 + 0x124) == 0) {
return 0;
}
if (*(int *)(iVar1 + 0x128) == 0) {
return 0;
}
memset(*(void **)(iVar1 + 0x20),0,*(int *)(this + 8) << 3);
iVar20 = *(int *)(this + 0xc);
iVar1 = *(int *)(this + 8);
if (*(int *)(iVar20 + 0x84) < 2) {
iVar12 = 0;
iVar5 = 1;
iVar3 = iVar12;
}
else {
iVar3 = 0;
do {
iVar5 = iVar3;
pfVar6 = *(float **)(iVar20 + 0x20);
if (0 < iVar1) {
pfVar9 = param_1 + iVar1 * iVar5;
pfVar14 = pfVar6;
do {
fVar21 = *pfVar9;
pfVar9 = pfVar9 + 1;
coprocessor_function(10,6,5,in_cr7,in_cr7,in_cr8);
coprocessor_function(10,6,4,in_cr7,in_cr7,in_cr8);
*pfVar14 = fVar21;
pfVar14 = pfVar14 + 1;
} while (pfVar14 != pfVar6 + iVar1);
}
ffts_execute(*(undefined4 *)(iVar20 + 0x124),pfVar6,*(undefined4 *)(iVar20 + 0x40));
iVar1 = *(int *)(this + 8);
iVar20 = *(int *)(this + 0xc);
if (-1 < iVar1) {
puVar15 = *(undefined4 **)(*(int *)(iVar20 + 0xa0) + iVar5 * 4);
puVar19 = *(undefined4 **)(*(int *)(iVar20 + 0xc0) + iVar5 * 4);
puVar10 = (undefined4 *)(*(int *)(iVar20 + 0x40) + 4);
puVar16 = puVar15;
do {
puVar17 = puVar16 + 1;
*puVar16 = puVar10[-1];
*puVar19 = *puVar10;
puVar19 = puVar19 + 1;
puVar10 = puVar10 + 2;
puVar16 = puVar17;
} while (puVar17 != puVar15 + iVar1 + 1);
}
iVar3 = iVar5 + 1;
} while (iVar3 < *(int *)(iVar20 + 0x84) + -1);
iVar12 = iVar1 * iVar3;
iVar5 = iVar5 + 2;
}
iVar18 = param_4 - iVar12;
if (iVar18 < 1) {
sVar11 = (iVar1 * iVar5 - param_4) * 4;
if (((int)sVar11 < 0) || (iVar18 < 0)) goto LAB_00062c64;
pfVar6 = *(float **)(iVar20 + 0x20);
}
else {
pfVar6 = *(float **)(iVar20 + 0x20);
pfVar9 = param_1 + iVar12;
pfVar14 = pfVar6;
do {
fVar21 = *pfVar9;
pfVar9 = pfVar9 + 1;
coprocessor_function(10,6,5,in_cr7,in_cr7,in_cr8);
coprocessor_function(10,6,4,in_cr7,in_cr7,in_cr8);
*pfVar14 = fVar21;
pfVar14 = pfVar14 + 1;
} while (pfVar14 != pfVar6 + iVar18);
sVar11 = (iVar1 * iVar5 - param_4) * 4;
if ((int)sVar11 < 0) goto LAB_00062c64;
}
memset(pfVar6 + iVar18,0,sVar11);
iVar20 = *(int *)(this + 0xc);
LAB_00062c64:
ffts_execute(*(undefined4 *)(iVar20 + 0x124),*(undefined4 *)(iVar20 + 0x20),
*(undefined4 *)(iVar20 + 0x40));
iVar1 = *(int *)(this + 8);
if (-1 < iVar1) {
iVar20 = *(int *)(this + 0xc);
puVar15 = *(undefined4 **)(*(int *)(iVar20 + 0xa0) + iVar3 * 4);
puVar19 = *(undefined4 **)(*(int *)(iVar20 + 0xc0) + iVar3 * 4);
puVar10 = (undefined4 *)(*(int *)(iVar20 + 0x40) + 4);
puVar16 = puVar15;
do {
puVar17 = puVar16 + 1;
*puVar16 = puVar10[-1];
*puVar19 = *puVar10;
puVar19 = puVar19 + 1;
puVar10 = puVar10 + 2;
puVar16 = puVar17;
} while (puVar17 != puVar15 + iVar1 + 1);
}
return 1;
}



// PConvSingle_F32::ConvSegment(float*, bool, int)

void PConvSingle_F32::ConvSegment(float *param_1,bool param_2,int param_3) {
    undefined4 uVar1;
    undefined4 uVar2;
    undefined4 uVar4;
    undefined4 uVar6;
    float *pfVar8;
    float *pfVar9;
    int iVar10;
    float *pfVar11;
    undefined8 *puVar12;
    undefined4 *puVar13;
    int iVar14;
    undefined4 *puVar15;
    undefined4 *puVar16;
    int *piVar17;
    int extraout_r1;
    undefined4 *puVar18;
    int extraout_r1_00;
    undefined4 extraout_r1_01;
    undefined4 *puVar19;
    float *pfVar20;
    undefined4 *puVar21;
    undefined4 *puVar22;
    int iVar23;
    int iVar24;
    undefined4 *puVar25;
    float *pfVar26;
    int iVar27;
    float *pfVar28;
    int iVar29;
    undefined4 *puVar30;
    float *pfVar31;
    undefined8 *puVar32;
    undefined4 *puVar33;
    int iVar34;
    undefined8 *puVar35;
    int iVar36;
    undefined4 *puVar37;
    undefined8 *puVar38;
    undefined4 *puVar39;
    undefined4 *puVar40;
    undefined4 *puVar41;
    undefined4 *puVar42;
    undefined4 *puVar43;
    float *pfVar44;
    int iVar45;
    int iVar46;
    undefined4 *puVar47;
    undefined *puVar48;
    undefined *puVar49;
    undefined *puVar50;
    float *pfVar51;
    int iVar52;
    undefined4 uVar53;
    int iVar54;
    longlong lVar55;
    undefined4 in_cr5;
    undefined4 in_cr7;
    undefined in_q0 [16];
    undefined in_q1 [16];
    undefined in_q2 [16];
    float fVar56;
    float fVar57;
    float fVar58;
    undefined in_q3 [16];
    float fVar59;
    undefined in_q4 [16];
    undefined in_q5 [16];
    undefined in_q6 [16];
    undefined in_q7 [16];
    undefined in_q8 [16];
    undefined auVar60 [16];
    undefined in_q9 [16];
    undefined auVar61 [16];
    undefined in_q10 [16];
    undefined auVar62 [16];
    undefined in_q11 [16];
    undefined auVar63 [16];
    undefined auVar64 [16];
    undefined in_q12 [16];
    undefined auVar65 [16];
    undefined in_q13 [16];
    undefined auVar66 [16];
    undefined in_q14 [16];
    undefined auVar67 [16];
    undefined in_q15 [16];
    undefined auStack528 [188];
    int local_154;
    float *local_150;
    uint local_14c;
    undefined8 uStack100;
    undefined8 uStack92;
    undefined8 uStack84;
    undefined8 uStack76;
    undefined8 uStack68;
    undefined8 uStack60;
    undefined8 uStack52;
    undefined8 uStack44;
    undefined4 uVar3;
    undefined4 uVar5;
    undefined4 uVar7;

    uStack100 = SUB168(in_q4,0);
    uStack92 = SUB168(in_q4 >> 0x40,0);
    uStack84 = SUB168(in_q5,0);
    uStack76 = SUB168(in_q5 >> 0x40,0);
    uStack68 = SUB168(in_q6,0);
    uStack60 = SUB168(in_q6 >> 0x40,0);
    uStack52 = SUB168(in_q7,0);
    uStack44 = SUB168(in_q7 >> 0x40,0);
    puVar50 = auStack528;
    puVar48 = auStack528;
    local_14c = (uint)param_2;
    local_154 = param_3;
    local_150 = param_1;
    if (param_2 == 0) {
        memcpy(*(void **)(*(int *)(this + 0xc) + 0x20),param_1,*(int *)(this + 8) << 2);
        iVar10 = *(int *)(this + 8);
        puVar49 = auStack528;
    }
    else {
        iVar10 = *(int *)(this + 8);
        if (param_3 == 0) {
            puVar49 = auStack528;
            if (0 < iVar10) {
                iVar23 = 0x10;
                do {
                    iVar10 = *(int *)(this + 0xc);
                    pfVar44 = param_1 + 0x10;
                    pfVar31 = param_1 + 0x18;
                    pfVar8 = (float *)0x360;
                    pfVar9 = (float *)0x370;
                    lVar55 = 2;
                    pfVar20 = param_1;
                    pfVar11 = param_1;
                    while( true ) {
                        *pfVar8 = *pfVar11;
                        pfVar11 = pfVar11 + 1;
                        *pfVar9 = *pfVar11;
                        pfVar11 = pfVar11 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x368;
                    pfVar9 = (float *)0x378;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar11;
                        pfVar11 = pfVar11 + 1;
                        *pfVar9 = *pfVar11;
                        pfVar11 = pfVar11 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar11 = param_1 + 8;
                    pfVar28 = pfVar20 + 0x20;
                    iVar10 = *(int *)(iVar10 + 0x20);
                    pfVar26 = pfVar20 + 0x28;
                    pfVar8 = (float *)0x300;
                    pfVar9 = (float *)0x310;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar44;
                        pfVar44 = pfVar44 + 1;
                        *pfVar9 = *pfVar44;
                        pfVar44 = pfVar44 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x308;
                    pfVar9 = (float *)0x318;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar44;
                        pfVar44 = pfVar44 + 1;
                        *pfVar9 = *pfVar44;
                        pfVar44 = pfVar44 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar51 = pfVar20 + 0x30;
                    pfVar44 = pfVar20 + 0x38;
                    param_1 = pfVar20 + 0x40;
                    pfVar8 = (float *)0x340;
                    pfVar9 = (float *)0x350;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar11;
                        pfVar11 = pfVar11 + 1;
                        *pfVar9 = *pfVar11;
                        pfVar11 = pfVar11 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x348;
                    pfVar9 = (float *)0x358;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar11;
                        pfVar11 = pfVar11 + 1;
                        *pfVar9 = *pfVar11;
                        pfVar11 = pfVar11 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    puVar12 = (undefined8 *)(iVar10 + param_3 * 2);
                    param_3 = param_3 + 0x40;
                    pfVar8 = (float *)0x320;
                    pfVar9 = (float *)0x330;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar31;
                        pfVar31 = pfVar31 + 1;
                        *pfVar9 = *pfVar31;
                        pfVar31 = pfVar31 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x328;
                    pfVar9 = (float *)0x338;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar31;
                        pfVar31 = pfVar31 + 1;
                        *pfVar9 = *pfVar31;
                        pfVar31 = pfVar31 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x3e0;
                    pfVar9 = (float *)0x3f0;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar28;
                        pfVar28 = pfVar28 + 1;
                        *pfVar9 = *pfVar28;
                        pfVar28 = pfVar28 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x3e8;
                    pfVar9 = (float *)0x3f8;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar28;
                        pfVar28 = pfVar28 + 1;
                        *pfVar9 = *pfVar28;
                        pfVar28 = pfVar28 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x3c0;
                    pfVar9 = (float *)0x3d0;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar26;
                        pfVar26 = pfVar26 + 1;
                        *pfVar9 = *pfVar26;
                        pfVar26 = pfVar26 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x3c8;
                    pfVar9 = (float *)0x3d8;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar26;
                        pfVar26 = pfVar26 + 1;
                        *pfVar9 = *pfVar26;
                        pfVar26 = pfVar26 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x3a0;
                    pfVar9 = (float *)0x3b0;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar51;
                        pfVar51 = pfVar51 + 1;
                        *pfVar9 = *pfVar51;
                        pfVar51 = pfVar51 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x3a8;
                    pfVar9 = (float *)0x3b8;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar51;
                        pfVar51 = pfVar51 + 1;
                        *pfVar9 = *pfVar51;
                        pfVar51 = pfVar51 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x380;
                    pfVar9 = (float *)0x390;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar44;
                        pfVar44 = pfVar44 + 1;
                        *pfVar9 = *pfVar44;
                        pfVar44 = pfVar44 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x388;
                    pfVar9 = (float *)0x398;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar44;
                        pfVar44 = pfVar44 + 1;
                        *pfVar9 = *pfVar44;
                        pfVar44 = pfVar44 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    *puVar12 = CONCAT44(SUB164(in_q6,0),SUB164(in_q6,0));
                    uVar53 = SUB164(in_q6 >> 0x40,0);
                    *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
                    puVar12 = (undefined8 *)(*(int *)(*(int *)(this + 0xc) + 0x20) + iVar23);
                    *puVar12 = CONCAT44(SUB164(in_q4,0),SUB164(in_q4,0));
                    uVar53 = SUB164(in_q4 >> 0x40,0);
                    *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
                    iVar10 = *(int *)(*(int *)(this + 0xc) + 0x20) + iVar23;
                    *(ulonglong *)(iVar10 + 0x10) = CONCAT44(SUB164(in_q0,0),SUB164(in_q0,0));
                    uVar53 = SUB164(in_q0 >> 0x40,0);
                    *(ulonglong *)(iVar10 + 0x14) = CONCAT44(uVar53,uVar53);
                    iVar10 = *(int *)(*(int *)(this + 0xc) + 0x20) + iVar23;
                    *(ulonglong *)(iVar10 + 0x20) = CONCAT44(SUB164(in_q2,0),SUB164(in_q2,0));
                    uVar53 = SUB164(in_q2 >> 0x40,0);
                    *(ulonglong *)(iVar10 + 0x24) = CONCAT44(uVar53,uVar53);
                    iVar10 = *(int *)(*(int *)(this + 0xc) + 0x20) + iVar23;
                    *(ulonglong *)(iVar10 + 0x30) = CONCAT44(SUB164(in_q14,0),SUB164(in_q14,0));
                    uVar53 = SUB164(in_q14 >> 0x40,0);
                    *(ulonglong *)(iVar10 + 0x34) = CONCAT44(uVar53,uVar53);
                    iVar10 = *(int *)(*(int *)(this + 0xc) + 0x20) + iVar23;
                    *(ulonglong *)(iVar10 + 0x40) = CONCAT44(SUB164(in_q12,0),SUB164(in_q12,0));
                    uVar53 = SUB164(in_q12 >> 0x40,0);
                    *(ulonglong *)(iVar10 + 0x44) = CONCAT44(uVar53,uVar53);
                    iVar10 = *(int *)(*(int *)(this + 0xc) + 0x20) + iVar23;
                    *(ulonglong *)(iVar10 + 0x50) = CONCAT44(SUB164(in_q10,0),SUB164(in_q10,0));
                    uVar53 = SUB164(in_q10 >> 0x40,0);
                    *(ulonglong *)(iVar10 + 0x54) = CONCAT44(uVar53,uVar53);
                    iVar10 = *(int *)(*(int *)(this + 0xc) + 0x20) + iVar23;
                    iVar23 = iVar23 + 0x80;
                    *(ulonglong *)(iVar10 + 0x60) = CONCAT44(SUB164(in_q8,0),SUB164(in_q8,0));
                    uVar53 = SUB164(in_q8 >> 0x40,0);
                    *(ulonglong *)(iVar10 + 100) = CONCAT44(uVar53,uVar53);
                    iVar10 = *(int *)(this + 8);
                    puVar49 = puVar48;
                } while (param_3 + iVar10 * -2 < 0 != SBORROW4(param_3,iVar10 * 2));
            }
        }
        else {
            puVar49 = auStack528;
            if (0 < iVar10) {
                iVar24 = 0x10;
                iVar23 = 0;
                do {
                    iVar10 = *(int *)(this + 0xc);
                    pfVar44 = param_1 + 0x10;
                    pfVar31 = param_1 + 0x18;
                    pfVar8 = (float *)0x360;
                    pfVar9 = (float *)0x370;
                    lVar55 = 2;
                    pfVar20 = param_1;
                    pfVar11 = param_1;
                    while( true ) {
                        *pfVar8 = *pfVar11;
                        pfVar11 = pfVar11 + 1;
                        *pfVar9 = *pfVar11;
                        pfVar11 = pfVar11 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x368;
                    pfVar9 = (float *)0x378;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar11;
                        pfVar11 = pfVar11 + 1;
                        *pfVar9 = *pfVar11;
                        pfVar11 = pfVar11 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar11 = param_1 + 8;
                    pfVar28 = pfVar20 + 0x20;
                    iVar10 = *(int *)(iVar10 + 0x20);
                    pfVar26 = pfVar20 + 0x28;
                    pfVar8 = (float *)0x300;
                    pfVar9 = (float *)0x310;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar44;
                        pfVar44 = pfVar44 + 1;
                        *pfVar9 = *pfVar44;
                        pfVar44 = pfVar44 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x308;
                    pfVar9 = (float *)0x318;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar44;
                        pfVar44 = pfVar44 + 1;
                        *pfVar9 = *pfVar44;
                        pfVar44 = pfVar44 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar51 = pfVar20 + 0x30;
                    pfVar44 = pfVar20 + 0x38;
                    param_1 = pfVar20 + 0x40;
                    pfVar8 = (float *)0x340;
                    pfVar9 = (float *)0x350;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar11;
                        pfVar11 = pfVar11 + 1;
                        *pfVar9 = *pfVar11;
                        pfVar11 = pfVar11 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x348;
                    pfVar9 = (float *)0x358;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar11;
                        pfVar11 = pfVar11 + 1;
                        *pfVar9 = *pfVar11;
                        pfVar11 = pfVar11 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    puVar12 = (undefined8 *)(iVar10 + iVar23 * 2);
                    iVar23 = iVar23 + 0x40;
                    pfVar8 = (float *)0x320;
                    pfVar9 = (float *)0x330;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar31;
                        pfVar31 = pfVar31 + 1;
                        *pfVar9 = *pfVar31;
                        pfVar31 = pfVar31 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x328;
                    pfVar9 = (float *)0x338;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar31;
                        pfVar31 = pfVar31 + 1;
                        *pfVar9 = *pfVar31;
                        pfVar31 = pfVar31 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x3e0;
                    pfVar9 = (float *)0x3f0;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar28;
                        pfVar28 = pfVar28 + 1;
                        *pfVar9 = *pfVar28;
                        pfVar28 = pfVar28 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x3e8;
                    pfVar9 = (float *)0x3f8;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar28;
                        pfVar28 = pfVar28 + 1;
                        *pfVar9 = *pfVar28;
                        pfVar28 = pfVar28 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x3c0;
                    pfVar9 = (float *)0x3d0;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar26;
                        pfVar26 = pfVar26 + 1;
                        *pfVar9 = *pfVar26;
                        pfVar26 = pfVar26 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x3c8;
                    pfVar9 = (float *)0x3d8;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar26;
                        pfVar26 = pfVar26 + 1;
                        *pfVar9 = *pfVar26;
                        pfVar26 = pfVar26 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x3a0;
                    pfVar9 = (float *)0x3b0;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar51;
                        pfVar51 = pfVar51 + 1;
                        *pfVar9 = *pfVar51;
                        pfVar51 = pfVar51 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x3a8;
                    pfVar9 = (float *)0x3b8;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar51;
                        pfVar51 = pfVar51 + 1;
                        *pfVar9 = *pfVar51;
                        pfVar51 = pfVar51 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x380;
                    pfVar9 = (float *)0x390;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar44;
                        pfVar44 = pfVar44 + 1;
                        *pfVar9 = *pfVar44;
                        pfVar44 = pfVar44 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    pfVar8 = (float *)0x388;
                    pfVar9 = (float *)0x398;
                    lVar55 = 2;
                    while( true ) {
                        *pfVar8 = *pfVar44;
                        pfVar44 = pfVar44 + 1;
                        *pfVar9 = *pfVar44;
                        pfVar44 = pfVar44 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        pfVar8 = pfVar8 + 1;
                        pfVar9 = pfVar9 + 1;
                    }
                    *puVar12 = CONCAT44(SUB164(in_q7,0),SUB164(in_q7,0));
                    uVar53 = SUB164(in_q7 >> 0x40,0);
                    *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
                    puVar12 = (undefined8 *)(*(int *)(*(int *)(this + 0xc) + 0x20) + iVar24);
                    *puVar12 = CONCAT44(SUB164(in_q5,0),SUB164(in_q5,0));
                    uVar53 = SUB164(in_q5 >> 0x40,0);
                    *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
                    iVar10 = *(int *)(*(int *)(this + 0xc) + 0x20) + iVar24;
                    *(ulonglong *)(iVar10 + 0x10) = CONCAT44(SUB164(in_q1,0),SUB164(in_q1,0));
                    uVar53 = SUB164(in_q1 >> 0x40,0);
                    *(ulonglong *)(iVar10 + 0x14) = CONCAT44(uVar53,uVar53);
                    iVar10 = *(int *)(*(int *)(this + 0xc) + 0x20) + iVar24;
                    *(ulonglong *)(iVar10 + 0x20) = CONCAT44(SUB164(in_q3,0),SUB164(in_q3,0));
                    uVar53 = SUB164(in_q3 >> 0x40,0);
                    *(ulonglong *)(iVar10 + 0x24) = CONCAT44(uVar53,uVar53);
                    iVar10 = *(int *)(*(int *)(this + 0xc) + 0x20) + iVar24;
                    *(ulonglong *)(iVar10 + 0x30) = CONCAT44(SUB164(in_q15,0),SUB164(in_q15,0));
                    uVar53 = SUB164(in_q15 >> 0x40,0);
                    *(ulonglong *)(iVar10 + 0x34) = CONCAT44(uVar53,uVar53);
                    iVar10 = *(int *)(*(int *)(this + 0xc) + 0x20) + iVar24;
                    *(ulonglong *)(iVar10 + 0x40) = CONCAT44(SUB164(in_q13,0),SUB164(in_q13,0));
                    uVar53 = SUB164(in_q13 >> 0x40,0);
                    *(ulonglong *)(iVar10 + 0x44) = CONCAT44(uVar53,uVar53);
                    iVar10 = *(int *)(*(int *)(this + 0xc) + 0x20) + iVar24;
                    *(ulonglong *)(iVar10 + 0x50) = CONCAT44(SUB164(in_q11,0),SUB164(in_q11,0));
                    uVar53 = SUB164(in_q11 >> 0x40,0);
                    *(ulonglong *)(iVar10 + 0x54) = CONCAT44(uVar53,uVar53);
                    iVar10 = *(int *)(*(int *)(this + 0xc) + 0x20) + iVar24;
                    iVar24 = iVar24 + 0x80;
                    *(ulonglong *)(iVar10 + 0x60) = CONCAT44(SUB164(in_q9,0),SUB164(in_q9,0));
                    uVar53 = SUB164(in_q9 >> 0x40,0);
                    *(ulonglong *)(iVar10 + 100) = CONCAT44(uVar53,uVar53);
                    iVar10 = *(int *)(this + 8);
                    puVar49 = puVar50;
                } while (iVar23 + iVar10 * -2 < 0 != SBORROW4(iVar23,iVar10 * 2));
            }
        }
    }
    memset((void *)(*(int *)(*(int *)(this + 0xc) + 0x20) + iVar10 * 4),0,iVar10 * 4,*puVar49);
    iVar10 = *(int *)(this + 0xc);
    ffts_execute(*(undefined4 *)(iVar10 + 0x124),*(undefined4 *)(iVar10 + 0x20),
                 *(undefined4 *)(iVar10 + 0x40));
    iVar10 = *(int *)(this + 8);
    piVar17 = *(int **)(this + 0xc);
    puVar40 = (undefined4 *)piVar17[0x10];
    if (0 < iVar10) {
        iVar24 = 0x10;
        iVar23 = 0;
        while( true ) {
            iVar34 = piVar17[0x18];
            iVar10 = iVar23 << 1;
            puVar16 = puVar40 + 0x10;
            puVar15 = (undefined4 *)0x360;
            puVar18 = (undefined4 *)0x370;
            lVar55 = 2;
            puVar21 = puVar40;
            puVar13 = puVar40;
            while( true ) {
                *puVar15 = *puVar13;
                puVar13 = puVar13 + 1;
                *puVar18 = *puVar13;
                puVar13 = puVar13 + 1;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar15 = puVar15 + 1;
                puVar18 = puVar18 + 1;
            }
            puVar15 = (undefined4 *)0x368;
            puVar18 = (undefined4 *)0x378;
            lVar55 = 2;
            while( true ) {
                *puVar15 = *puVar13;
                puVar13 = puVar13 + 1;
                *puVar18 = *puVar13;
                puVar13 = puVar13 + 1;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar15 = puVar15 + 1;
                puVar18 = puVar18 + 1;
            }
            puVar40 = puVar40 + 8;
            puVar37 = puVar21 + 0x18;
            puVar12 = (undefined8 *)(iVar34 + iVar10);
            puVar33 = puVar21 + 0x20;
            puVar13 = puVar21 + 0x28;
            puVar30 = puVar21 + 0x30;
            puVar22 = puVar21 + 0x38;
            puVar15 = (undefined4 *)0x340;
            puVar18 = (undefined4 *)0x350;
            lVar55 = 2;
            while( true ) {
                *puVar15 = *puVar40;
                puVar40 = puVar40 + 1;
                *puVar18 = *puVar40;
                puVar40 = puVar40 + 1;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar15 = puVar15 + 1;
                puVar18 = puVar18 + 1;
            }
            puVar15 = (undefined4 *)0x348;
            puVar18 = (undefined4 *)0x358;
            lVar55 = 2;
            while( true ) {
                *puVar15 = *puVar40;
                puVar40 = puVar40 + 1;
                *puVar18 = *puVar40;
                puVar40 = puVar40 + 1;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar15 = puVar15 + 1;
                puVar18 = puVar18 + 1;
            }
            iVar29 = iVar24 + 0x10;
            iVar34 = iVar24 + 0x60;
            puVar40 = (undefined4 *)0x300;
            puVar15 = (undefined4 *)0x310;
            lVar55 = 2;
            while( true ) {
                *puVar40 = *puVar16;
                puVar16 = puVar16 + 1;
                *puVar15 = *puVar16;
                puVar16 = puVar16 + 1;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar40 = puVar40 + 1;
                puVar15 = puVar15 + 1;
            }
            puVar40 = (undefined4 *)0x308;
            puVar15 = (undefined4 *)0x318;
            lVar55 = 2;
            while( true ) {
                *puVar40 = *puVar16;
                puVar16 = puVar16 + 1;
                *puVar15 = *puVar16;
                puVar16 = puVar16 + 1;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar40 = puVar40 + 1;
                puVar15 = puVar15 + 1;
            }
            iVar27 = iVar24 + 0x20;
            iVar23 = iVar23 + 0x40;
            puVar40 = puVar21 + 0x40;
            puVar15 = (undefined4 *)0x320;
            puVar18 = (undefined4 *)0x330;
            lVar55 = 2;
            while( true ) {
                *puVar15 = *puVar37;
                puVar37 = puVar37 + 1;
                *puVar18 = *puVar37;
                puVar37 = puVar37 + 1;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar15 = puVar15 + 1;
                puVar18 = puVar18 + 1;
            }
            puVar15 = (undefined4 *)0x328;
            puVar18 = (undefined4 *)0x338;
            lVar55 = 2;
            while( true ) {
                *puVar15 = *puVar37;
                puVar37 = puVar37 + 1;
                *puVar18 = *puVar37;
                puVar37 = puVar37 + 1;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar15 = puVar15 + 1;
                puVar18 = puVar18 + 1;
            }
            iVar52 = iVar24 + 0x30;
            puVar15 = (undefined4 *)0x3e0;
            puVar18 = (undefined4 *)0x3f0;
            lVar55 = 2;
            while( true ) {
                *puVar15 = *puVar33;
                puVar33 = puVar33 + 1;
                *puVar18 = *puVar33;
                puVar33 = puVar33 + 1;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar15 = puVar15 + 1;
                puVar18 = puVar18 + 1;
            }
            puVar15 = (undefined4 *)0x3e8;
            puVar18 = (undefined4 *)0x3f8;
            lVar55 = 2;
            while( true ) {
                *puVar15 = *puVar33;
                puVar33 = puVar33 + 1;
                *puVar18 = *puVar33;
                puVar33 = puVar33 + 1;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar15 = puVar15 + 1;
                puVar18 = puVar18 + 1;
            }
            iVar45 = iVar24 + 0x40;
            puVar15 = (undefined4 *)0x3c0;
            puVar18 = (undefined4 *)0x3d0;
            lVar55 = 2;
            while( true ) {
                *puVar15 = *puVar13;
                puVar13 = puVar13 + 1;
                *puVar18 = *puVar13;
                puVar13 = puVar13 + 1;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar15 = puVar15 + 1;
                puVar18 = puVar18 + 1;
            }
            puVar15 = (undefined4 *)0x3c8;
            puVar18 = (undefined4 *)0x3d8;
            lVar55 = 2;
            while( true ) {
                *puVar15 = *puVar13;
                puVar13 = puVar13 + 1;
                *puVar18 = *puVar13;
                puVar13 = puVar13 + 1;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar15 = puVar15 + 1;
                puVar18 = puVar18 + 1;
            }
            iVar14 = iVar24 + 0x50;
            puVar15 = (undefined4 *)0x3a0;
            puVar18 = (undefined4 *)0x3b0;
            lVar55 = 2;
            while( true ) {
                *puVar15 = *puVar30;
                puVar30 = puVar30 + 1;
                *puVar18 = *puVar30;
                puVar30 = puVar30 + 1;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar15 = puVar15 + 1;
                puVar18 = puVar18 + 1;
            }
            puVar15 = (undefined4 *)0x3a8;
            puVar18 = (undefined4 *)0x3b8;
            lVar55 = 2;
            while( true ) {
                *puVar15 = *puVar30;
                puVar30 = puVar30 + 1;
                *puVar18 = *puVar30;
                puVar30 = puVar30 + 1;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar15 = puVar15 + 1;
                puVar18 = puVar18 + 1;
            }
            puVar15 = (undefined4 *)0x380;
            puVar18 = (undefined4 *)0x390;
            lVar55 = 2;
            while( true ) {
                *puVar15 = *puVar22;
                puVar22 = puVar22 + 1;
                *puVar18 = *puVar22;
                puVar22 = puVar22 + 1;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar15 = puVar15 + 1;
                puVar18 = puVar18 + 1;
            }
            puVar15 = (undefined4 *)0x388;
            puVar18 = (undefined4 *)0x398;
            lVar55 = 2;
            while( true ) {
                *puVar15 = *puVar22;
                puVar22 = puVar22 + 1;
                *puVar18 = *puVar22;
                puVar22 = puVar22 + 1;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar15 = puVar15 + 1;
                puVar18 = puVar18 + 1;
            }
            *puVar12 = CONCAT44(SUB164(in_q6,0),SUB164(in_q6,0));
            uVar53 = SUB164(in_q6 >> 0x40,0);
            *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
            puVar12 = (undefined8 *)(*(int *)(*(int *)(this + 0xc) + 0x60) + iVar24);
            *puVar12 = CONCAT44(SUB164(in_q4,0),SUB164(in_q4,0));
            uVar53 = SUB164(in_q4 >> 0x40,0);
            *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
            puVar12 = (undefined8 *)(*(int *)(*(int *)(this + 0xc) + 0x60) + iVar29);
            *puVar12 = CONCAT44(SUB164(in_q0,0),SUB164(in_q0,0));
            uVar53 = SUB164(in_q0 >> 0x40,0);
            *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
            puVar12 = (undefined8 *)(*(int *)(*(int *)(this + 0xc) + 0x60) + iVar27);
            *puVar12 = CONCAT44(SUB164(in_q2,0),SUB164(in_q2,0));
            uVar53 = SUB164(in_q2 >> 0x40,0);
            *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
            puVar12 = (undefined8 *)(*(int *)(*(int *)(this + 0xc) + 0x60) + iVar52);
            *puVar12 = CONCAT44(SUB164(in_q14,0),SUB164(in_q14,0));
            uVar53 = SUB164(in_q14 >> 0x40,0);
            *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
            puVar12 = (undefined8 *)(*(int *)(*(int *)(this + 0xc) + 0x60) + iVar45);
            *puVar12 = CONCAT44(SUB164(in_q12,0),SUB164(in_q12,0));
            uVar53 = SUB164(in_q12 >> 0x40,0);
            *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
            puVar12 = (undefined8 *)(*(int *)(*(int *)(this + 0xc) + 0x60) + iVar14);
            *puVar12 = CONCAT44(SUB164(in_q10,0),SUB164(in_q10,0));
            uVar53 = SUB164(in_q10 >> 0x40,0);
            *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
            puVar12 = (undefined8 *)(*(int *)(*(int *)(this + 0xc) + 0x60) + iVar34);
            *puVar12 = CONCAT44(SUB164(in_q8,0),SUB164(in_q8,0));
            uVar53 = SUB164(in_q8 >> 0x40,0);
            *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
            puVar12 = (undefined8 *)(*(int *)(*(int *)(this + 0xc) + 0x80) + iVar10);
            *puVar12 = CONCAT44(SUB164(in_q7,0),SUB164(in_q7,0));
            uVar53 = SUB164(in_q7 >> 0x40,0);
            *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
            puVar12 = (undefined8 *)(*(int *)(*(int *)(this + 0xc) + 0x80) + iVar24);
            iVar24 = iVar24 + 0x80;
            *puVar12 = CONCAT44(SUB164(in_q5,0),SUB164(in_q5,0));
            uVar53 = SUB164(in_q5 >> 0x40,0);
            *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
            puVar12 = (undefined8 *)(*(int *)(*(int *)(this + 0xc) + 0x80) + iVar29);
            *puVar12 = CONCAT44(SUB164(in_q1,0),SUB164(in_q1,0));
            uVar53 = SUB164(in_q1 >> 0x40,0);
            *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
            puVar12 = (undefined8 *)(*(int *)(*(int *)(this + 0xc) + 0x80) + iVar27);
            *puVar12 = CONCAT44(SUB164(in_q3,0),SUB164(in_q3,0));
            uVar53 = SUB164(in_q3 >> 0x40,0);
            *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
            puVar12 = (undefined8 *)(*(int *)(*(int *)(this + 0xc) + 0x80) + iVar52);
            *puVar12 = CONCAT44(SUB164(in_q15,0),SUB164(in_q15,0));
            uVar53 = SUB164(in_q15 >> 0x40,0);
            *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
            puVar12 = (undefined8 *)(*(int *)(*(int *)(this + 0xc) + 0x80) + iVar45);
            *puVar12 = CONCAT44(SUB164(in_q13,0),SUB164(in_q13,0));
            uVar53 = SUB164(in_q13 >> 0x40,0);
            *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
            puVar12 = (undefined8 *)(*(int *)(*(int *)(this + 0xc) + 0x80) + iVar14);
            *puVar12 = CONCAT44(SUB164(in_q11,0),SUB164(in_q11,0));
            uVar53 = SUB164(in_q11 >> 0x40,0);
            *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
            puVar12 = (undefined8 *)(*(int *)(*(int *)(this + 0xc) + 0x80) + iVar34);
            *puVar12 = CONCAT44(SUB164(in_q9,0),SUB164(in_q9,0));
            uVar53 = SUB164(in_q9 >> 0x40,0);
            *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
            iVar10 = *(int *)(this + 8);
            if (iVar23 + iVar10 * -2 < 0 == SBORROW4(iVar23,iVar10 * 2)) break;
            piVar17 = *(int **)(this + 0xc);
        }
        piVar17 = *(int **)(this + 0xc);
        puVar40 = (undefined4 *)piVar17[0x10];
    }
    iVar23 = piVar17[3];
    iVar24 = *piVar17;
    iVar34 = piVar17[0x18];
    uVar53 = puVar40[iVar10 * 2];
    iVar29 = *(int *)(iVar23 + iVar24 * 4);
    iVar27 = piVar17[0x20];
    *(int *)(puVar49 + 0xb4) = iVar34;
    iVar23 = *(int *)(iVar23 + iVar24 * 4 + 4);
    *(undefined4 *)(iVar34 + iVar10 * 4) = uVar53;
    uVar53 = (puVar40 + iVar10 * 2)[1];
    *(int *)(puVar49 + 0x8c) = iVar29;
    *(int *)(puVar49 + 0xb8) = iVar23;
    *(int *)(puVar49 + 8) = iVar27;
    *(undefined4 *)(iVar27 + iVar10 * 4) = uVar53;
    if (iVar29 < iVar23) {
        iVar34 = piVar17[2];
        iVar29 = piVar17[0x38];
        iVar23 = piVar17[0x40];
        *(PConvSingle_F32 **)(puVar49 + 0x28) = this;
        *(int *)(puVar49 + 0xb0) = *(int *)(puVar49 + 0x8c) << 2;
        do {
            __aeabi_idivmod(*(int *)(puVar49 + 0x8c) + iVar34,piVar17[0x31]);
            iVar27 = *(int *)(iVar29 + extraout_r1 * 4);
            iVar52 = *(int *)(iVar23 + extraout_r1 * 4);
            iVar24 = *(int *)(piVar17[0x30] + *(int *)(puVar49 + 0xb0));
            *(undefined4 *)(puVar49 + 0x88) = *(undefined4 *)(piVar17[0x28] + *(int *)(puVar49 + 0xb0));
            if (0 < iVar10) {
                iVar23 = 0;
                iVar34 = 0;
                *(int *)(puVar49 + 0x48) = iVar27 + 0x10;
                *(int *)(puVar49 + 0x68) = iVar52 + 0x10;
                *(int *)(puVar49 + 4) = iVar24;
                puVar40 = *(undefined4 **)(puVar49 + 0xb4);
                do {
                    puVar35 = (undefined8 *)(iVar23 + iVar27);
                    puVar32 = (undefined8 *)(iVar23 + iVar52);
                    puVar15 = (undefined4 *)(*(int *)(puVar49 + 0x88) + iVar23);
                    puVar18 = (undefined4 *)(*(int *)(puVar49 + 4) + iVar23);
                    auVar61 = CONCAT88(CONCAT44(puVar40[1],puVar40[1]),CONCAT44(*puVar40,*puVar40));
                    puVar21 = (undefined4 *)(*(int *)(puVar49 + 8) + iVar23);
                    auVar62 = CONCAT88(CONCAT44(puVar18[1],puVar18[1]),CONCAT44(*puVar18,*puVar18));
                    puVar12 = (undefined8 *)(*(int *)(puVar49 + 0x48) + iVar23);
                    iVar34 = iVar34 + 8;
                    auVar60 = CONCAT88(CONCAT44(puVar15[1],puVar15[1]),CONCAT44(*puVar15,*puVar15));
                    puVar38 = (undefined8 *)(*(int *)(puVar49 + 0x68) + iVar23);
                    iVar23 = iVar23 + 0x20;
                    FloatVectorMultiplyAccumulate(auVar61,auVar60,2,0x10);
                    FloatVectorMultiplyAccumulate(auVar61,auVar62,2,0x10);
                    auVar63 = CONCAT88(CONCAT44(puVar40[5],puVar40[5]),CONCAT44(puVar40[4],puVar40[4]));
                    iVar24 = *(int *)(puVar49 + 0x28);
                    auVar65 = CONCAT88(CONCAT44(puVar15[5],puVar15[5]),CONCAT44(puVar15[4],puVar15[4]));
                    auVar61 = CONCAT88(CONCAT44(puVar18[5],puVar18[5]),CONCAT44(puVar18[4],puVar18[4]));
                    FloatVectorMultiplyAccumulate(auVar63,auVar65,2,0x10);
                    FloatVectorMultiplyAccumulate(auVar63,auVar61,2,0x10);
                    auVar66 = CONCAT88(CONCAT44(puVar21[1],puVar21[1]),CONCAT44(*puVar21,*puVar21));
                    auVar63 = FloatVectorMultiplySubtract(auVar66,auVar62,2,0x10);
                    auVar64 = CONCAT88(CONCAT44(puVar21[5],puVar21[5]),CONCAT44(puVar21[4],puVar21[4]));
                    auVar62 = FloatVectorMultiplyAccumulate(auVar66,auVar60,2,0x10);
                    auVar61 = FloatVectorMultiplySubtract(auVar64,auVar61,2,0x10);
                    auVar60 = FloatVectorMultiplyAccumulate(auVar64,auVar65,2,0x10);
                    *puVar35 = CONCAT44(SUB164(auVar63,0),SUB164(auVar63,0));
                    uVar53 = SUB164(auVar63 >> 0x40,0);
                    *(ulonglong *)((int)puVar35 + 4) = CONCAT44(uVar53,uVar53);
                    *puVar32 = CONCAT44(SUB164(auVar62,0),SUB164(auVar62,0));
                    uVar53 = SUB164(auVar62 >> 0x40,0);
                    *(ulonglong *)((int)puVar32 + 4) = CONCAT44(uVar53,uVar53);
                    *puVar12 = CONCAT44(SUB164(auVar61,0),SUB164(auVar61,0));
                    uVar53 = SUB164(auVar61 >> 0x40,0);
                    *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
                    *puVar38 = CONCAT44(SUB164(auVar60,0),SUB164(auVar60,0));
                    uVar53 = SUB164(auVar60 >> 0x40,0);
                    *(ulonglong *)((int)puVar38 + 4) = CONCAT44(uVar53,uVar53);
                    iVar10 = *(int *)(iVar24 + 8);
                    puVar40 = puVar40 + 8;
                } while (iVar34 < iVar10);
                piVar17 = *(int **)(iVar24 + 0xc);
                iVar24 = *(int *)(puVar49 + 4);
                iVar34 = piVar17[2];
                iVar29 = piVar17[0x38];
                iVar23 = piVar17[0x40];
            }
            iVar14 = *(int *)(puVar49 + 0x8c);
            iVar45 = iVar10 * 4;
            iVar46 = *(int *)(puVar49 + 0xb8);
            iVar54 = *(int *)(puVar49 + 0x88);
            fVar59 = *(float *)(iVar24 + iVar45);
            *(int *)(puVar49 + 0x8c) = iVar14 + 1;
            fVar57 = *(float *)(iVar54 + iVar45);
            fVar58 = *(float *)(iVar27 + iVar45);
            iVar36 = *(int *)(puVar49 + 0xb4);
            fVar56 = *(float *)(iVar36 + iVar45);
            coprocessor_function(10,6,5,in_cr7,in_cr5,in_cr7);
            *(int *)(puVar49 + 0xb0) = *(int *)(puVar49 + 0xb0) + 4;
            *(float *)(iVar27 + iVar45) = fVar58 + (fVar56 * fVar57 - fVar59);
            fVar56 = *(float *)(iVar36 + iVar45);
            fVar57 = *(float *)(iVar24 + iVar45);
            fVar58 = *(float *)(iVar52 + iVar45);
            coprocessor_function(10,6,5,in_cr7,in_cr5,in_cr7);
            fVar59 = fVar58 + *(float *)(iVar54 + iVar45) + fVar56 * fVar57;
            in_q3 = CONCAT412(fVar59,CONCAT48(fVar58,CONCAT44(fVar57,fVar56)));
            *(float *)(iVar52 + iVar45) = fVar59;
        } while (iVar14 + 1 != iVar46);
        this = *(PConvSingle_F32 **)(puVar49 + 0x28);
        iVar24 = *piVar17;
        puVar40 = (undefined4 *)piVar17[0x10];
    }
    else {
        iVar34 = piVar17[2];
        iVar29 = piVar17[0x38];
        iVar23 = piVar17[0x40];
    }
    __aeabi_idivmod(iVar24 + 1,piVar17[1]);
    *piVar17 = extraout_r1_00;
    puVar15 = *(undefined4 **)(iVar29 + iVar34 * 4);
    iVar24 = iVar34 * 4;
    puVar18 = *(undefined4 **)(iVar23 + iVar34 * 4);
    if (0 < iVar10) {
        iVar23 = 0;
        do {
            iVar23 = iVar23 + 0x20;
            uVar53 = puVar15[1];
            *(ulonglong *)(puVar49 + 0x90) = CONCAT44(*puVar15,*puVar15);
            *(ulonglong *)(puVar49 + 0x98) = CONCAT44(uVar53,uVar53);
            in_q4 = CONCAT88(CONCAT44(puVar15[0x1d],puVar15[0x1d]),CONCAT44(puVar15[0x1c],puVar15[0x1c]));
            puVar37 = puVar40 + 0x10;
            puVar33 = puVar40 + 0x18;
            puVar30 = puVar40 + 0x20;
            in_q3 = CONCAT88(CONCAT44(puVar18[0x15],puVar18[0x15]),CONCAT44(puVar18[0x14],puVar18[0x14]));
            puVar22 = puVar40 + 0x28;
            puVar39 = puVar40 + 0x30;
            puVar25 = puVar40 + 0x38;
            uVar53 = puVar18[1];
            *(ulonglong *)(puVar49 + 0xa0) = CONCAT44(*puVar18,*puVar18);
            *(ulonglong *)(puVar49 + 0xa8) = CONCAT44(uVar53,uVar53);
            puVar18 = puVar18 + 0x20;
            puVar21 = (undefined4 *)0x360;
            puVar13 = (undefined4 *)0x370;
            lVar55 = 2;
            puVar16 = puVar40;
            while( true ) {
                *puVar16 = *puVar21;
                puVar16[1] = *puVar13;
                puVar16 = puVar16 + 2;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar21 = puVar21 + 1;
                puVar13 = puVar13 + 1;
            }
            puVar21 = (undefined4 *)0x368;
            puVar13 = (undefined4 *)0x378;
            lVar55 = 2;
            while( true ) {
                *puVar16 = *puVar21;
                puVar16[1] = *puVar13;
                puVar16 = puVar16 + 2;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar21 = puVar21 + 1;
                puVar13 = puVar13 + 1;
            }
            puVar16 = puVar40 + 8;
            puVar21 = (undefined4 *)0x380;
            puVar13 = (undefined4 *)0x390;
            lVar55 = 2;
            while( true ) {
                *puVar16 = *puVar21;
                puVar16[1] = *puVar13;
                puVar16 = puVar16 + 2;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar21 = puVar21 + 1;
                puVar13 = puVar13 + 1;
            }
            puVar21 = (undefined4 *)0x388;
            puVar13 = (undefined4 *)0x398;
            lVar55 = 2;
            while( true ) {
                *puVar16 = *puVar21;
                puVar16[1] = *puVar13;
                puVar16 = puVar16 + 2;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar21 = puVar21 + 1;
                puVar13 = puVar13 + 1;
            }
            puVar21 = (undefined4 *)0x3a0;
            puVar13 = (undefined4 *)0x3b0;
            lVar55 = 2;
            while( true ) {
                *puVar37 = *puVar21;
                puVar37[1] = *puVar13;
                puVar37 = puVar37 + 2;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar21 = puVar21 + 1;
                puVar13 = puVar13 + 1;
            }
            puVar21 = (undefined4 *)0x3a8;
            puVar13 = (undefined4 *)0x3b8;
            lVar55 = 2;
            while( true ) {
                *puVar37 = *puVar21;
                puVar37[1] = *puVar13;
                puVar37 = puVar37 + 2;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar21 = puVar21 + 1;
                puVar13 = puVar13 + 1;
            }
            puVar21 = (undefined4 *)0x3c0;
            puVar13 = (undefined4 *)0x3d0;
            lVar55 = 2;
            while( true ) {
                *puVar33 = *puVar21;
                puVar33[1] = *puVar13;
                puVar33 = puVar33 + 2;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar21 = puVar21 + 1;
                puVar13 = puVar13 + 1;
            }
            puVar21 = (undefined4 *)0x3c8;
            puVar13 = (undefined4 *)0x3d8;
            lVar55 = 2;
            while( true ) {
                *puVar33 = *puVar21;
                puVar33[1] = *puVar13;
                puVar33 = puVar33 + 2;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar21 = puVar21 + 1;
                puVar13 = puVar13 + 1;
            }
            puVar21 = (undefined4 *)0x3e0;
            puVar13 = (undefined4 *)0x3f0;
            lVar55 = 2;
            while( true ) {
                *puVar30 = *puVar21;
                puVar30[1] = *puVar13;
                puVar30 = puVar30 + 2;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar21 = puVar21 + 1;
                puVar13 = puVar13 + 1;
            }
            puVar21 = (undefined4 *)0x3e8;
            puVar13 = (undefined4 *)0x3f8;
            lVar55 = 2;
            while( true ) {
                *puVar30 = *puVar21;
                puVar30[1] = *puVar13;
                puVar30 = puVar30 + 2;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar21 = puVar21 + 1;
                puVar13 = puVar13 + 1;
            }
            puVar21 = (undefined4 *)0x320;
            puVar13 = (undefined4 *)0x330;
            lVar55 = 2;
            while( true ) {
                *puVar22 = *puVar21;
                puVar22[1] = *puVar13;
                puVar22 = puVar22 + 2;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar21 = puVar21 + 1;
                puVar13 = puVar13 + 1;
            }
            puVar21 = (undefined4 *)0x328;
            puVar13 = (undefined4 *)0x338;
            lVar55 = 2;
            while( true ) {
                *puVar22 = *puVar21;
                puVar22[1] = *puVar13;
                puVar22 = puVar22 + 2;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar21 = puVar21 + 1;
                puVar13 = puVar13 + 1;
            }
            puVar21 = (undefined4 *)0x300;
            puVar13 = (undefined4 *)0x310;
            lVar55 = 2;
            while( true ) {
                *puVar39 = *puVar21;
                puVar39[1] = *puVar13;
                puVar39 = puVar39 + 2;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar21 = puVar21 + 1;
                puVar13 = puVar13 + 1;
            }
            puVar21 = (undefined4 *)0x308;
            puVar13 = (undefined4 *)0x318;
            lVar55 = 2;
            while( true ) {
                *puVar39 = *puVar21;
                puVar39[1] = *puVar13;
                puVar39 = puVar39 + 2;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar21 = puVar21 + 1;
                puVar13 = puVar13 + 1;
            }
            puVar21 = (undefined4 *)0x340;
            puVar13 = (undefined4 *)0x350;
            lVar55 = 2;
            while( true ) {
                *puVar25 = *puVar21;
                puVar25[1] = *puVar13;
                puVar25 = puVar25 + 2;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar21 = puVar21 + 1;
                puVar13 = puVar13 + 1;
            }
            puVar21 = (undefined4 *)0x348;
            puVar13 = (undefined4 *)0x358;
            lVar55 = 2;
            while( true ) {
                *puVar25 = *puVar21;
                puVar25[1] = *puVar13;
                puVar25 = puVar25 + 2;
                lVar55 = lVar55 + -1;
                if (lVar55 == 0) break;
                puVar21 = puVar21 + 1;
                puVar13 = puVar13 + 1;
            }
            iVar10 = *(int *)(this + 8);
            puVar15 = puVar15 + 0x20;
            puVar40 = puVar40 + 0x40;
        } while (iVar23 < iVar10);
        iVar23 = *(int *)(this + 0xc);
        puVar40 = *(undefined4 **)(iVar23 + 0x40);
        puVar15 = *(undefined4 **)(*(int *)(iVar23 + 0xe0) + iVar24);
        puVar18 = *(undefined4 **)(*(int *)(iVar23 + 0x100) + iVar24);
    }
    puVar40[iVar10 * 2] = puVar15[iVar10];
    (puVar40 + iVar10 * 2)[1] = puVar18[iVar10];
    memset(puVar15,0,iVar10 * 4 + 4,*puVar49);
    memset(*(void **)(*(int *)(*(int *)(this + 0xc) + 0x100) + iVar24),0,(*(int *)(this + 8) + 1) * 4,
           *puVar49);
    iVar10 = *(int *)(this + 0xc);
    ffts_execute(*(undefined4 *)(iVar10 + 0x128),*(undefined4 *)(iVar10 + 0x40),
                 *(undefined4 *)(iVar10 + 0x20));
    iVar10 = *(int *)(puVar49 + 0xc4);
    puVar40 = *(undefined4 **)(*(int *)(this + 0xc) + 0x20);
    uVar53 = *(undefined4 *)(*(int *)(this + 0xc) + 0x120);
    *(undefined4 **)(puVar49 + 0xb0) = puVar40;
    *(undefined4 *)(puVar49 + 0x90) = uVar53;
    if (iVar10 == 0) {
        iVar23 = *(int *)(this + 8);
        if (0 < iVar23) {
            puVar15 = *(undefined4 **)(puVar49 + 0x90);
            puVar12 = *(undefined8 **)(puVar49 + 0xc0);
            do {
                auVar60 = FloatVectorAdd(CONCAT88(CONCAT44(puVar40[1],puVar40[1]),
                                                  CONCAT44(*puVar40,*puVar40)),
                                         CONCAT88(CONCAT44(puVar15[1],puVar15[1]),
                                                  CONCAT44(*puVar15,*puVar15)),2,0x20);
                iVar10 = iVar10 + 0x20;
                auVar67 = FloatVectorAdd(CONCAT88(CONCAT44(puVar40[5],puVar40[5]),
                                                  CONCAT44(puVar40[4],puVar40[4])),
                                         CONCAT88(CONCAT44(puVar15[5],puVar15[5]),
                                                  CONCAT44(puVar15[4],puVar15[4])),2,0x20);
                auVar66 = FloatVectorAdd(CONCAT88(CONCAT44(puVar40[9],puVar40[9]),
                                                  CONCAT44(puVar40[8],puVar40[8])),
                                         CONCAT88(CONCAT44(puVar15[9],puVar15[9]),
                                                  CONCAT44(puVar15[8],puVar15[8])),2,0x20);
                auVar65 = FloatVectorAdd(CONCAT88(CONCAT44(puVar40[0xd],puVar40[0xd]),
                                                  CONCAT44(puVar40[0xc],puVar40[0xc])),
                                         CONCAT88(CONCAT44(puVar15[0xd],puVar15[0xd]),
                                                  CONCAT44(puVar15[0xc],puVar15[0xc])),2,0x20);
                auVar64 = FloatVectorAdd(CONCAT88(CONCAT44(puVar40[0x11],puVar40[0x11]),
                                                  CONCAT44(puVar40[0x10],puVar40[0x10])),
                                         CONCAT88(CONCAT44(puVar15[0x11],puVar15[0x11]),
                                                  CONCAT44(puVar15[0x10],puVar15[0x10])),2,0x20);
                auVar61 = FloatVectorAdd(CONCAT88(CONCAT44(puVar40[0x1d],puVar40[0x1d]),
                                                  CONCAT44(puVar40[0x1c],puVar40[0x1c])),
                                         CONCAT88(CONCAT44(puVar15[0x1d],puVar15[0x1d]),
                                                  CONCAT44(puVar15[0x1c],puVar15[0x1c])),2,0x20);
                auVar63 = FloatVectorAdd(CONCAT88(CONCAT44(puVar40[0x15],puVar40[0x15]),
                                                  CONCAT44(puVar40[0x14],puVar40[0x14])),
                                         CONCAT88(CONCAT44(puVar15[0x15],puVar15[0x15]),
                                                  CONCAT44(puVar15[0x14],puVar15[0x14])),2,0x20);
                auVar62 = FloatVectorAdd(CONCAT88(CONCAT44(puVar40[0x19],puVar40[0x19]),
                                                  CONCAT44(puVar40[0x18],puVar40[0x18])),
                                         CONCAT88(CONCAT44(puVar15[0x19],puVar15[0x19]),
                                                  CONCAT44(puVar15[0x18],puVar15[0x18])),2,0x20);
                *puVar12 = CONCAT44(SUB164(auVar60,0),SUB164(auVar60,0));
                uVar53 = SUB164(auVar60 >> 0x40,0);
                *(ulonglong *)((int)puVar12 + 4) = CONCAT44(uVar53,uVar53);
                puVar12[2] = CONCAT44(SUB164(auVar67,0),SUB164(auVar67,0));
                uVar53 = SUB164(auVar67 >> 0x40,0);
                *(ulonglong *)((int)puVar12 + 0x14) = CONCAT44(uVar53,uVar53);
                puVar12[4] = CONCAT44(SUB164(auVar66,0),SUB164(auVar66,0));
                uVar53 = SUB164(auVar66 >> 0x40,0);
                *(ulonglong *)((int)puVar12 + 0x24) = CONCAT44(uVar53,uVar53);
                puVar12[6] = CONCAT44(SUB164(auVar65,0),SUB164(auVar65,0));
                uVar53 = SUB164(auVar65 >> 0x40,0);
                *(ulonglong *)((int)puVar12 + 0x34) = CONCAT44(uVar53,uVar53);
                puVar12[8] = CONCAT44(SUB164(auVar64,0),SUB164(auVar64,0));
                uVar53 = SUB164(auVar64 >> 0x40,0);
                *(ulonglong *)((int)puVar12 + 0x44) = CONCAT44(uVar53,uVar53);
                puVar12[10] = CONCAT44(SUB164(auVar63,0),SUB164(auVar63,0));
                uVar53 = SUB164(auVar63 >> 0x40,0);
                *(ulonglong *)((int)puVar12 + 0x54) = CONCAT44(uVar53,uVar53);
                puVar12[0xc] = CONCAT44(SUB164(auVar62,0),SUB164(auVar62,0));
                uVar53 = SUB164(auVar62 >> 0x40,0);
                *(ulonglong *)((int)puVar12 + 100) = CONCAT44(uVar53,uVar53);
                puVar12[0xe] = CONCAT44(SUB164(auVar61,0),SUB164(auVar61,0));
                uVar53 = SUB164(auVar61 >> 0x40,0);
                *(ulonglong *)((int)puVar12 + 0x74) = CONCAT44(uVar53,uVar53);
                iVar23 = *(int *)(this + 8);
                puVar40 = puVar40 + 0x20;
                puVar15 = puVar15 + 0x20;
                puVar12 = puVar12 + 0x10;
            } while (iVar10 < iVar23);
        }
    }
    else {
        iVar23 = *(int *)(this + 8);
        if (*(int *)(puVar49 + 0xbc) == 0) {
            if (0 < iVar23) {
                puVar15 = *(undefined4 **)(puVar49 + 0xc0);
                iVar10 = *(int *)(puVar49 + 0xbc);
                puVar18 = *(undefined4 **)(puVar49 + 0xb0);
                puVar40 = *(undefined4 **)(puVar49 + 0x90);
                *(PConvSingle_F32 **)(puVar49 + 0x8c) = this;
                do {
                    puVar37 = puVar15 + 0x20;
                    puVar33 = puVar15 + 0x28;
                    puVar30 = puVar15 + 0x30;
                    *(undefined4 **)(puVar49 + 0x88) = puVar15 + 0x38;
                    *(undefined4 **)(puVar49 + 0xb4) = puVar18 + 0xc;
                    puVar21 = (undefined4 *)0x330;
                    puVar13 = (undefined4 *)0x340;
                    lVar55 = 2;
                    puVar16 = puVar18;
                    puVar22 = puVar37;
                    while( true ) {
                        *puVar21 = *puVar22;
                        puVar22 = puVar22 + 1;
                        *puVar13 = *puVar22;
                        puVar22 = puVar22 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x338;
                    puVar13 = (undefined4 *)0x348;
                    lVar55 = 2;
                    while( true ) {
                        *puVar21 = *puVar22;
                        puVar22 = puVar22 + 1;
                        *puVar13 = *puVar22;
                        puVar22 = puVar22 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    *(longlong *)(puVar49 + 8) = SUB168(in_q3,0);
                    *(longlong *)(puVar49 + 0x10) = SUB168(in_q3 >> 0x40,0);
                    *(longlong *)(puVar49 + 0x18) = SUB168(in_q4,0);
                    *(longlong *)(puVar49 + 0x20) = SUB168(in_q4 >> 0x40,0);
                    puVar12 = (undefined8 *)(puVar49 + 0x28);
                    puVar21 = (undefined4 *)0x330;
                    puVar13 = (undefined4 *)0x340;
                    lVar55 = 2;
                    puVar22 = puVar33;
                    while( true ) {
                        *puVar21 = *puVar22;
                        puVar22 = puVar22 + 1;
                        *puVar13 = *puVar22;
                        puVar22 = puVar22 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x338;
                    puVar13 = (undefined4 *)0x348;
                    lVar55 = 2;
                    while( true ) {
                        *puVar21 = *puVar22;
                        puVar22 = puVar22 + 1;
                        *puVar13 = *puVar22;
                        puVar22 = puVar22 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    *puVar12 = SUB168(in_q3,0);
                    puVar12[1] = SUB168(in_q3 >> 0x40,0);
                    puVar12[2] = SUB168(in_q4,0);
                    puVar12[3] = SUB168(in_q4 >> 0x40,0);
                    puVar12 = (undefined8 *)(puVar49 + 0x48);
                    puVar21 = (undefined4 *)0x330;
                    puVar13 = (undefined4 *)0x340;
                    lVar55 = 2;
                    puVar22 = puVar40;
                    puVar25 = puVar30;
                    while( true ) {
                        *puVar21 = *puVar25;
                        puVar25 = puVar25 + 1;
                        *puVar13 = *puVar25;
                        puVar25 = puVar25 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x338;
                    puVar13 = (undefined4 *)0x348;
                    lVar55 = 2;
                    while( true ) {
                        *puVar21 = *puVar25;
                        puVar25 = puVar25 + 1;
                        *puVar13 = *puVar25;
                        puVar25 = puVar25 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    *puVar12 = SUB168(in_q3,0);
                    puVar12[1] = SUB168(in_q3 >> 0x40,0);
                    puVar12[2] = SUB168(in_q4,0);
                    puVar12[3] = SUB168(in_q4 >> 0x40,0);
                    puVar42 = *(undefined4 **)(puVar49 + 0x88);
                    auVar60 = CONCAT88(CONCAT44(puVar18[1],puVar18[1]),CONCAT44(*puVar18,*puVar18));
                    puVar18 = puVar18 + 4;
                    puVar43 = puVar16 + 8;
                    puVar41 = puVar15 + 0x10;
                    puVar39 = puVar15 + 0x18;
                    auVar61 = CONCAT88(CONCAT44(puVar40[1],puVar40[1]),CONCAT44(*puVar40,*puVar40));
                    puVar40 = puVar40 + 4;
                    iVar10 = iVar10 + 0x20;
                    puVar21 = (undefined4 *)0x330;
                    puVar13 = (undefined4 *)0x340;
                    lVar55 = 2;
                    puVar25 = puVar15;
                    while( true ) {
                        *puVar21 = *puVar42;
                        puVar42 = puVar42 + 1;
                        *puVar13 = *puVar42;
                        puVar42 = puVar42 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x338;
                    puVar13 = (undefined4 *)0x348;
                    lVar55 = 2;
                    while( true ) {
                        *puVar21 = *puVar42;
                        puVar42 = puVar42 + 1;
                        *puVar13 = *puVar42;
                        puVar42 = puVar42 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    *(longlong *)(puVar49 + 0x68) = SUB168(in_q3,0);
                    *(longlong *)(puVar49 + 0x70) = SUB168(in_q3 >> 0x40,0);
                    *(longlong *)(puVar49 + 0x78) = SUB168(in_q4,0);
                    *(longlong *)(puVar49 + 0x80) = SUB168(in_q4 >> 0x40,0);
                    puVar42 = *(undefined4 **)(puVar49 + 0xb4);
                    auVar63 = CONCAT88(CONCAT44(puVar18[1],puVar18[1]),CONCAT44(*puVar18,*puVar18));
                    auVar62 = CONCAT88(CONCAT44(puVar40[1],puVar40[1]),CONCAT44(*puVar40,*puVar40));
                    puVar13 = puVar16 + 0x14;
                    auVar64 = CONCAT88(CONCAT44(puVar16[0x11],puVar16[0x11]),
                                       CONCAT44(puVar16[0x10],puVar16[0x10]));
                    puVar47 = puVar22 + 8;
                    puVar40 = (undefined4 *)0x3e0;
                    puVar18 = (undefined4 *)0x3f0;
                    lVar55 = 2;
                    puVar21 = puVar15;
                    while( true ) {
                        *puVar40 = *puVar21;
                        puVar21 = puVar21 + 1;
                        *puVar18 = *puVar21;
                        puVar21 = puVar21 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar40 = puVar40 + 1;
                        puVar18 = puVar18 + 1;
                    }
                    puVar40 = (undefined4 *)0x3e8;
                    puVar18 = (undefined4 *)0x3f8;
                    lVar55 = 2;
                    while( true ) {
                        *puVar40 = *puVar21;
                        puVar21 = puVar21 + 1;
                        *puVar18 = *puVar21;
                        puVar21 = puVar21 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar40 = puVar40 + 1;
                        puVar18 = puVar18 + 1;
                    }
                    puVar19 = puVar15 + 8;
                    FloatVectorAdd(auVar60,auVar61,2,0x20);
                    auVar60 = CONCAT88(CONCAT44(puVar13[1],puVar13[1]),CONCAT44(*puVar13,*puVar13));
                    puVar13 = puVar22 + 0xc;
                    auVar65 = CONCAT88(CONCAT44(puVar43[1],puVar43[1]),CONCAT44(*puVar43,*puVar43));
                    puVar43 = puVar16 + 0x18;
                    auVar66 = CONCAT88(CONCAT44(puVar47[1],puVar47[1]),CONCAT44(*puVar47,*puVar47));
                    puVar47 = puVar22 + 0x18;
                    auVar61 = CONCAT88(CONCAT44(puVar42[1],puVar42[1]),CONCAT44(*puVar42,*puVar42));
                    puVar42 = puVar16 + 0x1c;
                    puVar18 = puVar16 + 0x20;
                    puVar40 = (undefined4 *)0x3a0;
                    puVar15 = (undefined4 *)0x3b0;
                    lVar55 = 2;
                    puVar21 = puVar41;
                    while( true ) {
                        *puVar40 = *puVar21;
                        puVar21 = puVar21 + 1;
                        *puVar15 = *puVar21;
                        puVar21 = puVar21 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar40 = puVar40 + 1;
                        puVar15 = puVar15 + 1;
                    }
                    puVar40 = (undefined4 *)0x3a8;
                    puVar15 = (undefined4 *)0x3b8;
                    lVar55 = 2;
                    while( true ) {
                        *puVar40 = *puVar21;
                        puVar21 = puVar21 + 1;
                        *puVar15 = *puVar21;
                        puVar21 = puVar21 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar40 = puVar40 + 1;
                        puVar15 = puVar15 + 1;
                    }
                    FloatVectorAdd(auVar65,auVar66,2,0x20);
                    auVar65 = CONCAT88(CONCAT44(puVar13[1],puVar13[1]),CONCAT44(*puVar13,*puVar13));
                    puVar13 = puVar22 + 0x1c;
                    puVar40 = (undefined4 *)0x3c0;
                    puVar15 = (undefined4 *)0x3d0;
                    lVar55 = 2;
                    puVar21 = puVar19;
                    while( true ) {
                        *puVar40 = *puVar21;
                        puVar21 = puVar21 + 1;
                        *puVar15 = *puVar21;
                        puVar21 = puVar21 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar40 = puVar40 + 1;
                        puVar15 = puVar15 + 1;
                    }
                    puVar40 = (undefined4 *)0x3c8;
                    puVar15 = (undefined4 *)0x3d8;
                    lVar55 = 2;
                    while( true ) {
                        *puVar40 = *puVar21;
                        puVar21 = puVar21 + 1;
                        *puVar15 = *puVar21;
                        puVar21 = puVar21 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar40 = puVar40 + 1;
                        puVar15 = puVar15 + 1;
                    }
                    FloatVectorAdd(auVar63,auVar62,2,0x20);
                    puVar40 = (undefined4 *)0x380;
                    puVar15 = (undefined4 *)0x390;
                    lVar55 = 2;
                    puVar21 = puVar39;
                    while( true ) {
                        *puVar40 = *puVar21;
                        puVar21 = puVar21 + 1;
                        *puVar15 = *puVar21;
                        puVar21 = puVar21 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar40 = puVar40 + 1;
                        puVar15 = puVar15 + 1;
                    }
                    puVar40 = (undefined4 *)0x388;
                    puVar15 = (undefined4 *)0x398;
                    lVar55 = 2;
                    while( true ) {
                        *puVar40 = *puVar21;
                        puVar21 = puVar21 + 1;
                        *puVar15 = *puVar21;
                        puVar21 = puVar21 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar40 = puVar40 + 1;
                        puVar15 = puVar15 + 1;
                    }
                    FloatVectorAdd(auVar61,auVar65,2,0x20);
                    uVar1 = *puVar43;
                    uVar53 = puVar43[1];
                    uVar3 = *puVar42;
                    uVar2 = puVar42[1];
                    puVar40 = puVar22 + 0x20;
                    auVar61 = FloatVectorAdd(auVar64,CONCAT88(CONCAT44(puVar22[0x11],puVar22[0x11]),
                                                              CONCAT44(puVar22[0x10],puVar22[0x10])),2,0x20);
                    *(longlong *)(puVar49 + 8) = SUB168(auVar61,0);
                    *(longlong *)(puVar49 + 0x10) = SUB168(auVar61 >> 0x40,0);
                    uVar5 = *puVar13;
                    uVar4 = puVar13[1];
                    auVar60 = FloatVectorAdd(auVar60,CONCAT88(CONCAT44(puVar22[0x15],puVar22[0x15]),
                                                              CONCAT44(puVar22[0x14],puVar22[0x14])),2,0x20);
                    uVar6 = *puVar47;
                    uVar7 = puVar47[1];
                    *(longlong *)(puVar49 + 0x28) = SUB168(auVar60,0);
                    *(longlong *)(puVar49 + 0x30) = SUB168(auVar60 >> 0x40,0);
                    auVar60 = FloatVectorAdd(CONCAT88(CONCAT44(uVar53,uVar53),CONCAT44(uVar1,uVar1)),
                                             CONCAT88(CONCAT44(uVar7,uVar7),CONCAT44(uVar6,uVar6)),2,0x20);
                    *(longlong *)(puVar49 + 0x48) = SUB168(auVar60,0);
                    *(longlong *)(puVar49 + 0x50) = SUB168(auVar60 >> 0x40,0);
                    puVar15 = (undefined4 *)0x3e0;
                    puVar21 = (undefined4 *)0x3f0;
                    lVar55 = 2;
                    puVar13 = puVar25;
                    while( true ) {
                        *puVar13 = *puVar15;
                        puVar13[1] = *puVar21;
                        puVar13 = puVar13 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar15 = puVar15 + 1;
                        puVar21 = puVar21 + 1;
                    }
                    puVar15 = (undefined4 *)0x3e8;
                    puVar21 = (undefined4 *)0x3f8;
                    lVar55 = 2;
                    while( true ) {
                        *puVar13 = *puVar15;
                        puVar13[1] = *puVar21;
                        puVar13 = puVar13 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar15 = puVar15 + 1;
                        puVar21 = puVar21 + 1;
                    }
                    puVar15 = puVar25 + 0x40;
                    puVar21 = (undefined4 *)0x3c0;
                    puVar13 = (undefined4 *)0x3d0;
                    lVar55 = 2;
                    while( true ) {
                        *puVar19 = *puVar21;
                        puVar19[1] = *puVar13;
                        puVar19 = puVar19 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x3c8;
                    puVar13 = (undefined4 *)0x3d8;
                    lVar55 = 2;
                    while( true ) {
                        *puVar19 = *puVar21;
                        puVar19[1] = *puVar13;
                        puVar19 = puVar19 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    auVar60 = FloatVectorAdd(CONCAT88(CONCAT44(uVar2,uVar2),CONCAT44(uVar3,uVar3)),
                                             CONCAT88(CONCAT44(uVar4,uVar4),CONCAT44(uVar5,uVar5)),2,0x20);
                    puVar21 = (undefined4 *)0x3a0;
                    puVar13 = (undefined4 *)0x3b0;
                    lVar55 = 2;
                    while( true ) {
                        *puVar41 = *puVar21;
                        puVar41[1] = *puVar13;
                        puVar41 = puVar41 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x3a8;
                    puVar13 = (undefined4 *)0x3b8;
                    lVar55 = 2;
                    while( true ) {
                        *puVar41 = *puVar21;
                        puVar41[1] = *puVar13;
                        puVar41 = puVar41 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    *(longlong *)(puVar49 + 0x68) = SUB168(auVar60,0);
                    *(longlong *)(puVar49 + 0x70) = SUB168(auVar60 >> 0x40,0);
                    this = *(PConvSingle_F32 **)(puVar49 + 0x8c);
                    puVar21 = (undefined4 *)0x380;
                    puVar13 = (undefined4 *)0x390;
                    lVar55 = 2;
                    while( true ) {
                        *puVar39 = *puVar21;
                        puVar39[1] = *puVar13;
                        puVar39 = puVar39 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x388;
                    puVar13 = (undefined4 *)0x398;
                    lVar55 = 2;
                    while( true ) {
                        *puVar39 = *puVar21;
                        puVar39[1] = *puVar13;
                        puVar39 = puVar39 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x330;
                    puVar13 = (undefined4 *)0x340;
                    lVar55 = 2;
                    while( true ) {
                        *puVar37 = *puVar21;
                        puVar37[1] = *puVar13;
                        puVar37 = puVar37 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x338;
                    puVar13 = (undefined4 *)0x348;
                    lVar55 = 2;
                    while( true ) {
                        *puVar37 = *puVar21;
                        puVar37[1] = *puVar13;
                        puVar37 = puVar37 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x330;
                    puVar13 = (undefined4 *)0x340;
                    lVar55 = 2;
                    while( true ) {
                        *puVar33 = *puVar21;
                        puVar33[1] = *puVar13;
                        puVar33 = puVar33 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x338;
                    puVar13 = (undefined4 *)0x348;
                    lVar55 = 2;
                    while( true ) {
                        *puVar33 = *puVar21;
                        puVar33[1] = *puVar13;
                        puVar33 = puVar33 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x330;
                    puVar13 = (undefined4 *)0x340;
                    lVar55 = 2;
                    while( true ) {
                        *puVar30 = *puVar21;
                        puVar30[1] = *puVar13;
                        puVar30 = puVar30 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x338;
                    puVar13 = (undefined4 *)0x348;
                    lVar55 = 2;
                    while( true ) {
                        *puVar30 = *puVar21;
                        puVar30[1] = *puVar13;
                        puVar30 = puVar30 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    in_q3 = *(undefined (*) [16])(puVar49 + 0x68);
                    in_q4 = *(undefined (*) [16])(puVar49 + 0x78);
                    puVar16 = *(undefined4 **)(puVar49 + 0x88);
                    puVar21 = (undefined4 *)0x330;
                    puVar13 = (undefined4 *)0x340;
                    lVar55 = 2;
                    while( true ) {
                        *puVar16 = *puVar21;
                        puVar16[1] = *puVar13;
                        puVar16 = puVar16 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x338;
                    puVar13 = (undefined4 *)0x348;
                    lVar55 = 2;
                    while( true ) {
                        *puVar16 = *puVar21;
                        puVar16[1] = *puVar13;
                        puVar16 = puVar16 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    iVar23 = *(int *)(this + 8);
                } while (iVar10 < iVar23);
            }
        }
        else {
            if (0 < iVar23) {
                puVar15 = *(undefined4 **)(puVar49 + 0xc0);
                iVar10 = 0;
                puVar18 = *(undefined4 **)(puVar49 + 0xb0);
                puVar40 = *(undefined4 **)(puVar49 + 0x90);
                *(PConvSingle_F32 **)(puVar49 + 0x8c) = this;
                do {
                    puVar37 = puVar15 + 0x20;
                    puVar33 = puVar15 + 0x28;
                    puVar30 = puVar15 + 0x30;
                    *(undefined4 **)(puVar49 + 0x88) = puVar15 + 0x38;
                    *(undefined4 **)(puVar49 + 0xb4) = puVar18 + 0xc;
                    puVar21 = (undefined4 *)0x330;
                    puVar13 = (undefined4 *)0x340;
                    lVar55 = 2;
                    puVar16 = puVar18;
                    puVar22 = puVar37;
                    while( true ) {
                        *puVar21 = *puVar22;
                        puVar22 = puVar22 + 1;
                        *puVar13 = *puVar22;
                        puVar22 = puVar22 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x338;
                    puVar13 = (undefined4 *)0x348;
                    lVar55 = 2;
                    while( true ) {
                        *puVar21 = *puVar22;
                        puVar22 = puVar22 + 1;
                        *puVar13 = *puVar22;
                        puVar22 = puVar22 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    *(longlong *)(puVar49 + 8) = SUB168(in_q3,0);
                    *(longlong *)(puVar49 + 0x10) = SUB168(in_q3 >> 0x40,0);
                    *(longlong *)(puVar49 + 0x18) = SUB168(in_q4,0);
                    *(longlong *)(puVar49 + 0x20) = SUB168(in_q4 >> 0x40,0);
                    puVar12 = (undefined8 *)(puVar49 + 0x28);
                    puVar21 = (undefined4 *)0x330;
                    puVar13 = (undefined4 *)0x340;
                    lVar55 = 2;
                    puVar22 = puVar33;
                    while( true ) {
                        *puVar21 = *puVar22;
                        puVar22 = puVar22 + 1;
                        *puVar13 = *puVar22;
                        puVar22 = puVar22 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x338;
                    puVar13 = (undefined4 *)0x348;
                    lVar55 = 2;
                    while( true ) {
                        *puVar21 = *puVar22;
                        puVar22 = puVar22 + 1;
                        *puVar13 = *puVar22;
                        puVar22 = puVar22 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    *puVar12 = SUB168(in_q3,0);
                    puVar12[1] = SUB168(in_q3 >> 0x40,0);
                    puVar12[2] = SUB168(in_q4,0);
                    puVar12[3] = SUB168(in_q4 >> 0x40,0);
                    puVar12 = (undefined8 *)(puVar49 + 0x48);
                    puVar21 = (undefined4 *)0x330;
                    puVar13 = (undefined4 *)0x340;
                    lVar55 = 2;
                    puVar22 = puVar40;
                    puVar25 = puVar30;
                    while( true ) {
                        *puVar21 = *puVar25;
                        puVar25 = puVar25 + 1;
                        *puVar13 = *puVar25;
                        puVar25 = puVar25 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x338;
                    puVar13 = (undefined4 *)0x348;
                    lVar55 = 2;
                    while( true ) {
                        *puVar21 = *puVar25;
                        puVar25 = puVar25 + 1;
                        *puVar13 = *puVar25;
                        puVar25 = puVar25 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    *puVar12 = SUB168(in_q3,0);
                    puVar12[1] = SUB168(in_q3 >> 0x40,0);
                    puVar12[2] = SUB168(in_q4,0);
                    puVar12[3] = SUB168(in_q4 >> 0x40,0);
                    puVar42 = *(undefined4 **)(puVar49 + 0x88);
                    auVar60 = CONCAT88(CONCAT44(puVar16[1],puVar16[1]),CONCAT44(*puVar16,*puVar16));
                    puVar16 = puVar16 + 4;
                    puVar43 = puVar18 + 8;
                    puVar41 = puVar15 + 0x10;
                    puVar39 = puVar15 + 0x18;
                    auVar61 = CONCAT88(CONCAT44(puVar40[1],puVar40[1]),CONCAT44(*puVar40,*puVar40));
                    puVar40 = puVar40 + 4;
                    iVar10 = iVar10 + 0x20;
                    puVar21 = (undefined4 *)0x330;
                    puVar13 = (undefined4 *)0x340;
                    lVar55 = 2;
                    puVar25 = puVar15;
                    while( true ) {
                        *puVar21 = *puVar42;
                        puVar42 = puVar42 + 1;
                        *puVar13 = *puVar42;
                        puVar42 = puVar42 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x338;
                    puVar13 = (undefined4 *)0x348;
                    lVar55 = 2;
                    while( true ) {
                        *puVar21 = *puVar42;
                        puVar42 = puVar42 + 1;
                        *puVar13 = *puVar42;
                        puVar42 = puVar42 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    *(longlong *)(puVar49 + 0x68) = SUB168(in_q3,0);
                    *(longlong *)(puVar49 + 0x70) = SUB168(in_q3 >> 0x40,0);
                    *(longlong *)(puVar49 + 0x78) = SUB168(in_q4,0);
                    *(longlong *)(puVar49 + 0x80) = SUB168(in_q4 >> 0x40,0);
                    puVar42 = *(undefined4 **)(puVar49 + 0xb4);
                    auVar63 = CONCAT88(CONCAT44(puVar16[1],puVar16[1]),CONCAT44(*puVar16,*puVar16));
                    auVar62 = CONCAT88(CONCAT44(puVar40[1],puVar40[1]),CONCAT44(*puVar40,*puVar40));
                    puVar16 = puVar18 + 0x14;
                    auVar64 = CONCAT88(CONCAT44(puVar18[0x11],puVar18[0x11]),
                                       CONCAT44(puVar18[0x10],puVar18[0x10]));
                    puVar47 = puVar22 + 8;
                    puVar40 = (undefined4 *)0x3e0;
                    puVar21 = (undefined4 *)0x3f0;
                    lVar55 = 2;
                    puVar13 = puVar15;
                    while( true ) {
                        *puVar40 = *puVar13;
                        puVar13 = puVar13 + 1;
                        *puVar21 = *puVar13;
                        puVar13 = puVar13 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar40 = puVar40 + 1;
                        puVar21 = puVar21 + 1;
                    }
                    puVar40 = (undefined4 *)0x3e8;
                    puVar21 = (undefined4 *)0x3f8;
                    lVar55 = 2;
                    while( true ) {
                        *puVar40 = *puVar13;
                        puVar13 = puVar13 + 1;
                        *puVar21 = *puVar13;
                        puVar13 = puVar13 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar40 = puVar40 + 1;
                        puVar21 = puVar21 + 1;
                    }
                    puVar19 = puVar15 + 8;
                    FloatVectorAdd(auVar60,auVar61,2,0x20);
                    auVar60 = CONCAT88(CONCAT44(puVar16[1],puVar16[1]),CONCAT44(*puVar16,*puVar16));
                    puVar13 = puVar22 + 0xc;
                    auVar65 = CONCAT88(CONCAT44(puVar43[1],puVar43[1]),CONCAT44(*puVar43,*puVar43));
                    puVar43 = puVar18 + 0x18;
                    auVar66 = CONCAT88(CONCAT44(puVar47[1],puVar47[1]),CONCAT44(*puVar47,*puVar47));
                    puVar47 = puVar22 + 0x18;
                    auVar61 = CONCAT88(CONCAT44(puVar42[1],puVar42[1]),CONCAT44(*puVar42,*puVar42));
                    puVar16 = puVar18 + 0x1c;
                    puVar18 = puVar18 + 0x20;
                    puVar40 = (undefined4 *)0x3a0;
                    puVar15 = (undefined4 *)0x3b0;
                    lVar55 = 2;
                    puVar21 = puVar41;
                    while( true ) {
                        *puVar40 = *puVar21;
                        puVar21 = puVar21 + 1;
                        *puVar15 = *puVar21;
                        puVar21 = puVar21 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar40 = puVar40 + 1;
                        puVar15 = puVar15 + 1;
                    }
                    puVar40 = (undefined4 *)0x3a8;
                    puVar15 = (undefined4 *)0x3b8;
                    lVar55 = 2;
                    while( true ) {
                        *puVar40 = *puVar21;
                        puVar21 = puVar21 + 1;
                        *puVar15 = *puVar21;
                        puVar21 = puVar21 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar40 = puVar40 + 1;
                        puVar15 = puVar15 + 1;
                    }
                    FloatVectorAdd(auVar65,auVar66,2,0x20);
                    auVar65 = CONCAT88(CONCAT44(puVar13[1],puVar13[1]),CONCAT44(*puVar13,*puVar13));
                    puVar13 = puVar22 + 0x1c;
                    puVar40 = (undefined4 *)0x3c0;
                    puVar15 = (undefined4 *)0x3d0;
                    lVar55 = 2;
                    puVar21 = puVar19;
                    while( true ) {
                        *puVar40 = *puVar21;
                        puVar21 = puVar21 + 1;
                        *puVar15 = *puVar21;
                        puVar21 = puVar21 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar40 = puVar40 + 1;
                        puVar15 = puVar15 + 1;
                    }
                    puVar40 = (undefined4 *)0x3c8;
                    puVar15 = (undefined4 *)0x3d8;
                    lVar55 = 2;
                    while( true ) {
                        *puVar40 = *puVar21;
                        puVar21 = puVar21 + 1;
                        *puVar15 = *puVar21;
                        puVar21 = puVar21 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar40 = puVar40 + 1;
                        puVar15 = puVar15 + 1;
                    }
                    FloatVectorAdd(auVar63,auVar62,2,0x20);
                    puVar40 = (undefined4 *)0x380;
                    puVar15 = (undefined4 *)0x390;
                    lVar55 = 2;
                    puVar21 = puVar39;
                    while( true ) {
                        *puVar40 = *puVar21;
                        puVar21 = puVar21 + 1;
                        *puVar15 = *puVar21;
                        puVar21 = puVar21 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar40 = puVar40 + 1;
                        puVar15 = puVar15 + 1;
                    }
                    puVar40 = (undefined4 *)0x388;
                    puVar15 = (undefined4 *)0x398;
                    lVar55 = 2;
                    while( true ) {
                        *puVar40 = *puVar21;
                        puVar21 = puVar21 + 1;
                        *puVar15 = *puVar21;
                        puVar21 = puVar21 + 1;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar40 = puVar40 + 1;
                        puVar15 = puVar15 + 1;
                    }
                    FloatVectorAdd(auVar61,auVar65,2,0x20);
                    uVar53 = *puVar43;
                    uVar1 = puVar43[1];
                    uVar2 = *puVar16;
                    uVar3 = puVar16[1];
                    puVar40 = puVar22 + 0x20;
                    auVar61 = FloatVectorAdd(auVar64,CONCAT88(CONCAT44(puVar22[0x11],puVar22[0x11]),
                                                              CONCAT44(puVar22[0x10],puVar22[0x10])),2,0x20);
                    *(longlong *)(puVar49 + 0x18) = SUB168(auVar61,0);
                    *(longlong *)(puVar49 + 0x20) = SUB168(auVar61 >> 0x40,0);
                    uVar4 = *puVar13;
                    uVar5 = puVar13[1];
                    auVar60 = FloatVectorAdd(auVar60,CONCAT88(CONCAT44(puVar22[0x15],puVar22[0x15]),
                                                              CONCAT44(puVar22[0x14],puVar22[0x14])),2,0x20);
                    uVar6 = *puVar47;
                    uVar7 = puVar47[1];
                    *(longlong *)(puVar49 + 0x38) = SUB168(auVar60,0);
                    *(longlong *)(puVar49 + 0x40) = SUB168(auVar60 >> 0x40,0);
                    auVar60 = FloatVectorAdd(CONCAT88(CONCAT44(uVar1,uVar1),CONCAT44(uVar53,uVar53)),
                                             CONCAT88(CONCAT44(uVar7,uVar7),CONCAT44(uVar6,uVar6)),2,0x20);
                    *(longlong *)(puVar49 + 0x58) = SUB168(auVar60,0);
                    *(longlong *)(puVar49 + 0x60) = SUB168(auVar60 >> 0x40,0);
                    puVar15 = (undefined4 *)0x3e0;
                    puVar21 = (undefined4 *)0x3f0;
                    lVar55 = 2;
                    puVar13 = puVar25;
                    while( true ) {
                        *puVar13 = *puVar15;
                        puVar13[1] = *puVar21;
                        puVar13 = puVar13 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar15 = puVar15 + 1;
                        puVar21 = puVar21 + 1;
                    }
                    puVar15 = (undefined4 *)0x3e8;
                    puVar21 = (undefined4 *)0x3f8;
                    lVar55 = 2;
                    while( true ) {
                        *puVar13 = *puVar15;
                        puVar13[1] = *puVar21;
                        puVar13 = puVar13 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar15 = puVar15 + 1;
                        puVar21 = puVar21 + 1;
                    }
                    puVar15 = puVar25 + 0x40;
                    puVar21 = (undefined4 *)0x3c0;
                    puVar13 = (undefined4 *)0x3d0;
                    lVar55 = 2;
                    while( true ) {
                        *puVar19 = *puVar21;
                        puVar19[1] = *puVar13;
                        puVar19 = puVar19 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x3c8;
                    puVar13 = (undefined4 *)0x3d8;
                    lVar55 = 2;
                    while( true ) {
                        *puVar19 = *puVar21;
                        puVar19[1] = *puVar13;
                        puVar19 = puVar19 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    auVar60 = FloatVectorAdd(CONCAT88(CONCAT44(uVar3,uVar3),CONCAT44(uVar2,uVar2)),
                                             CONCAT88(CONCAT44(uVar5,uVar5),CONCAT44(uVar4,uVar4)),2,0x20);
                    puVar21 = (undefined4 *)0x3a0;
                    puVar13 = (undefined4 *)0x3b0;
                    lVar55 = 2;
                    while( true ) {
                        *puVar41 = *puVar21;
                        puVar41[1] = *puVar13;
                        puVar41 = puVar41 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x3a8;
                    puVar13 = (undefined4 *)0x3b8;
                    lVar55 = 2;
                    while( true ) {
                        *puVar41 = *puVar21;
                        puVar41[1] = *puVar13;
                        puVar41 = puVar41 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    *(longlong *)(puVar49 + 0x78) = SUB168(auVar60,0);
                    *(longlong *)(puVar49 + 0x80) = SUB168(auVar60 >> 0x40,0);
                    this = *(PConvSingle_F32 **)(puVar49 + 0x8c);
                    puVar21 = (undefined4 *)0x380;
                    puVar13 = (undefined4 *)0x390;
                    lVar55 = 2;
                    while( true ) {
                        *puVar39 = *puVar21;
                        puVar39[1] = *puVar13;
                        puVar39 = puVar39 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x388;
                    puVar13 = (undefined4 *)0x398;
                    lVar55 = 2;
                    while( true ) {
                        *puVar39 = *puVar21;
                        puVar39[1] = *puVar13;
                        puVar39 = puVar39 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x330;
                    puVar13 = (undefined4 *)0x340;
                    lVar55 = 2;
                    while( true ) {
                        *puVar37 = *puVar21;
                        puVar37[1] = *puVar13;
                        puVar37 = puVar37 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x338;
                    puVar13 = (undefined4 *)0x348;
                    lVar55 = 2;
                    while( true ) {
                        *puVar37 = *puVar21;
                        puVar37[1] = *puVar13;
                        puVar37 = puVar37 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x330;
                    puVar13 = (undefined4 *)0x340;
                    lVar55 = 2;
                    while( true ) {
                        *puVar33 = *puVar21;
                        puVar33[1] = *puVar13;
                        puVar33 = puVar33 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x338;
                    puVar13 = (undefined4 *)0x348;
                    lVar55 = 2;
                    while( true ) {
                        *puVar33 = *puVar21;
                        puVar33[1] = *puVar13;
                        puVar33 = puVar33 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x330;
                    puVar13 = (undefined4 *)0x340;
                    lVar55 = 2;
                    while( true ) {
                        *puVar30 = *puVar21;
                        puVar30[1] = *puVar13;
                        puVar30 = puVar30 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x338;
                    puVar13 = (undefined4 *)0x348;
                    lVar55 = 2;
                    while( true ) {
                        *puVar30 = *puVar21;
                        puVar30[1] = *puVar13;
                        puVar30 = puVar30 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    in_q3 = *(undefined (*) [16])(puVar49 + 0x68);
                    in_q4 = *(undefined (*) [16])(puVar49 + 0x78);
                    puVar16 = *(undefined4 **)(puVar49 + 0x88);
                    puVar21 = (undefined4 *)0x330;
                    puVar13 = (undefined4 *)0x340;
                    lVar55 = 2;
                    while( true ) {
                        *puVar16 = *puVar21;
                        puVar16[1] = *puVar13;
                        puVar16 = puVar16 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    puVar21 = (undefined4 *)0x338;
                    puVar13 = (undefined4 *)0x348;
                    lVar55 = 2;
                    while( true ) {
                        *puVar16 = *puVar21;
                        puVar16[1] = *puVar13;
                        puVar16 = puVar16 + 2;
                        lVar55 = lVar55 + -1;
                        if (lVar55 == 0) break;
                        puVar21 = puVar21 + 1;
                        puVar13 = puVar13 + 1;
                    }
                    iVar23 = *(int *)(this + 8);
                } while (iVar10 < iVar23);
            }
        }
    }
    memcpy(*(void **)(puVar49 + 0x90),(void *)(*(int *)(puVar49 + 0xb0) + iVar23 * 4),iVar23 * 4,
           *puVar49);
    iVar10 = *(int *)(this + 0xc);
    __aeabi_idivmod(*(int *)(iVar10 + 8) + 1,*(undefined4 *)(iVar10 + 0xc4));
    *(undefined4 *)(iVar10 + 8) = extraout_r1_01;
    return;
}



// PConvSingle_F32::Reset()

void PConvSingle_F32::Reset() {
    int iVar1;
    undefined4 *puVar2;
    int iVar3;

    if (*this == (PConvSingle_F32)0x0) {
        return;
    }
    puVar2 = *(undefined4 **)(this + 0xc);
    iVar3 = 0;
    *puVar2 = 0;
    puVar2[2] = 0;
    if (0 < (int)puVar2[0x31]) {
        do {
            memset(*(void **)(puVar2[0x38] + iVar3 * 4),0,(*(int *)(this + 8) + 1) * 4);
            iVar1 = iVar3 * 4;
            iVar3 = iVar3 + 1;
            memset(*(void **)(*(int *)(*(int *)(this + 0xc) + 0x100) + iVar1),0,
                   (*(int *)(this + 8) + 1) * 4);
            puVar2 = *(undefined4 **)(this + 0xc);
        } while (iVar3 < (int)puVar2[0x31]);
    }
    memset((void *)puVar2[0x48],0,*(int *)(this + 8) << 2);
    return;
}



// PConvSingle_F32::GetFFTSize()

int PConvSingle_F32::GetFFTSize() {
    return *(int *)(this + 8) << 1;
}



// PConvSingle_F32::GetSegmentSize()

undefined4 PConvSingle_F32::GetSegmentSize() {
    return *(undefined4 *)(this + 8);
}



// PConvSingle_F32::GetSegmentCount()

undefined4 PConvSingle_F32::GetSegmentCount() {
    return *(undefined4 *)(this + 4);
}



// PConvSingle_F32::UnloadKernel()

void PConvSingle_F32::UnloadKernel() {
    *this = (PConvSingle_F32)0x0;
    ReleaseResources(this);
    return;
}



// PConvSingle_F32::LoadKernel(float const*, int, int)

int PConvSingle_F32::LoadKernel(float *param_1,int param_2,int param_3) {
    void *__s;
    int iVar1;

    if (param_1 == nullptr) {
        return 0;
    }
    if (((1 < param_2) && (1 < param_3)) && ((param_3 - 1U & param_3) == 0)) {
        *this = (PConvSingle_F32)0x0;
        ReleaseResources(this);
        __s = valloc(0x140);
        *(void **)(this + 0xc) = __s;
        if (__s != nullptr) {
            memset(__s,0,0x140);
            *(int *)(this + 8) = param_3;
            iVar1 = ProcessKernel(this,param_1,param_2,1);
            if (iVar1 != 0) {
                *this = (PConvSingle_F32)0x1;
                return iVar1;
            }
        }
        ReleaseResources(this);
        return 0;
    }
    return 0;
}



// PConvSingle_F32::LoadKernel(float const*, float, int, int)

int PConvSingle_F32::LoadKernel(float *param_1,float param_2,int param_3,int param_4) {
void *__s;
int iVar1;
float extraout_s0;
uint in_stack_00000000;

if (param_1 == nullptr) {
return 0;
}
if (((1 < param_4) && (1 < (int)in_stack_00000000)) &&
((in_stack_00000000 - 1 & in_stack_00000000) == 0)) {
*this = (PConvSingle_F32)0x0;
ReleaseResources(this);
__s = valloc(0x140);
*(void **)(this + 0xc) = __s;
if (__s != nullptr) {
memset(__s,0,0x140);
*(uint *)(this + 8) = in_stack_00000000;
iVar1 = ProcessKernel(this,param_1,extraout_s0,param_3,param_4);
if (iVar1 != 0) {
*this = (PConvSingle_F32)0x1;
return iVar1;
}
}
ReleaseResources(this);
}
return 0;
}



// PConvSingle_F32::InstanceUsable()

PConvSingle_F32 PConvSingle_F32::InstanceUsable() {
    return *this;
}



// PConvSingle_F32::Convolve(float*)

void PConvSingle_F32::Convolve(float *param_1) {
    ConvSegment(this,param_1,false,0);
    return;
}



// PConvSingle_F32::ConvolveInterleaved(float*, int)

void PConvSingle_F32::ConvolveInterleaved(float *param_1,int param_2) {
    ConvSegment(this,param_1,true,param_2);
    return;
}
