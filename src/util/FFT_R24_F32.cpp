//
// Created by mart on 2/12/21.
//

#include "FFT_R24_F32.h"


// FFT_R24_F32::makect(int, int*, float*)

void FFT_R24_F32::makect(int param_1,int *param_2,float *param_3) {
    int iVar1;
    undefined4 uVar2;
    undefined4 extraout_r1;
    int iVar3;
    float *pfVar4;
    float *pfVar5;
    undefined4 in_cr0;
    undefined4 in_cr1;
    undefined4 in_cr7;
    undefined4 in_cr8;
    undefined4 in_cr9;
    undefined4 in_cr10;
    double unaff_d8;
    double dVar6;

    param_2[1] = param_1;
    if (1 < param_1) {
        iVar1 = param_1 >> 1;
        coprocessor_function(10,6,4,in_cr7,in_cr7,in_cr10);
        dVar6 = (double)(longlong)iVar1;
        uVar2 = SUB84(dVar6,0);
        cos(unaff_d8);
        coprocessor_function(10,2,4,in_cr7,in_cr7,in_cr7);
        *param_3 = (float)(double)CONCAT44(extraout_r1,uVar2);
        param_3[iVar1] = 0.5;
        if (iVar1 != 1) {
            pfVar5 = param_3 + param_1;
            iVar3 = 1;
            pfVar4 = param_3 + 1;
            do {
                iVar3 = iVar3 + 1;
                coprocessor_function(10,2,0,in_cr8,in_cr8,in_cr10);
                cos(unaff_d8);
                coprocessor_function(0xb,6,4,in_cr0,in_cr1,in_cr9);
                *pfVar4 = (float)dVar6;
                pfVar4 = pfVar4 + 1;
                sin(unaff_d8);
                coprocessor_function(0xb,6,0,in_cr0,in_cr7,in_cr9);
                pfVar5 = pfVar5 + -1;
                *pfVar5 = (float)dVar6;
            } while (iVar3 != iVar1);
        }
    }
    return;
}



// FFT_R24_F32::bitrv2(int, int*, float*)

void FFT_R24_F32::bitrv2(int param_1,int *param_2,float *param_3) {
    float *pfVar1;
    int iVar2;
    float *pfVar3;
    int *piVar4;
    float *pfVar5;
    int iVar6;
    float *pfVar7;
    float fVar8;
    float fVar9;
    float fVar10;
    int iVar11;
    int *local_48;
    int local_40;
    int *local_3c;
    int *local_34;
    int local_30;
    int local_2c;
    int local_28;
    int local_24;

    *param_2 = 0;
    if (param_1 < 9) {
        if (param_1 != 8) {
            return;
        }
        local_40 = 2;
        local_30 = 1;
    }
    else {
        local_30 = 1;
        do {
            iVar2 = local_30;
            param_1 = param_1 >> 1;
            iVar6 = 0;
            piVar4 = param_2 + -1;
            do {
                piVar4 = piVar4 + 1;
                iVar6 = iVar6 + 1;
                piVar4[iVar2] = *piVar4 + param_1;
            } while (iVar6 < iVar2);
            local_30 = iVar2 << 1;
        } while (iVar2 * 0x10 < param_1);
        local_40 = iVar2 * 4;
        if (iVar2 * 0x10 != param_1) {
            iVar6 = 1;
            local_34 = param_2;
            do {
                local_34 = local_34 + 1;
                iVar2 = 0;
                pfVar1 = param_3 + *local_34 + 1;
                pfVar3 = param_3 + local_40 + *local_34 + 1;
                piVar4 = param_2 + -1;
                do {
                    piVar4 = piVar4 + 1;
                    iVar2 = iVar2 + 1;
                    iVar11 = iVar6 * 2 + *piVar4;
                    fVar9 = pfVar1[-1];
                    fVar8 = *pfVar1;
                    fVar10 = param_3[iVar11 + 1];
                    pfVar1[-1] = param_3[iVar11];
                    *pfVar1 = fVar10;
                    param_3[iVar11] = fVar9;
                    param_3[iVar11 + 1] = fVar8;
                    fVar9 = pfVar3[-1];
                    fVar10 = param_3[iVar11 + local_40 + 1];
                    fVar8 = *pfVar3;
                    pfVar3[-1] = param_3[iVar11 + local_40];
                    *pfVar3 = fVar10;
                    param_3[iVar11 + local_40] = fVar9;
                    param_3[iVar11 + local_40 + 1] = fVar8;
                    pfVar1 = pfVar1 + 2;
                    pfVar3 = pfVar3 + 2;
                } while (iVar2 < iVar6);
                iVar6 = iVar6 + 1;
            } while (local_30 != iVar6);
            return;
        }
    }
    local_28 = *param_2;
    local_24 = local_40;
    local_2c = 0;
    local_3c = param_2;
    while( true ) {
        local_28 = local_24 + local_28;
        local_2c = local_2c + 1;
        fVar9 = param_3[local_28 + local_40 + 1];
        fVar10 = param_3[local_28 + 1];
        fVar8 = param_3[local_28];
        param_3[local_28] = param_3[local_28 + local_40];
        param_3[local_28 + 1] = fVar9;
        param_3[local_28 + local_40] = fVar8;
        param_3[local_28 + local_40 + 1] = fVar10;
        if (local_30 <= local_2c) break;
        local_28 = local_3c[1];
        iVar6 = local_40 + local_28 + local_40;
        local_48 = param_2 + -1;
        pfVar1 = param_3 + local_40 + local_28 + 1;
        pfVar3 = param_3 + local_40 + iVar6 + 1;
        pfVar5 = param_3 + iVar6 + 1;
        pfVar7 = param_3 + local_28 + 1;
        do {
            local_48 = local_48 + 1;
            fVar10 = pfVar7[-1];
            iVar6 = local_2c * 2 + *local_48;
            iVar2 = iVar6 + local_40 * 2;
            fVar8 = param_3[iVar6 + 1];
            iVar11 = iVar2 - local_40;
            fVar9 = *pfVar7;
            pfVar7[-1] = param_3[iVar6];
            *pfVar7 = fVar8;
            param_3[iVar6] = fVar10;
            param_3[iVar6 + 1] = fVar9;
            fVar9 = param_3[iVar2 + 1];
            iVar6 = iVar11 + local_40 * 2;
            fVar8 = pfVar1[-1];
            pfVar1[-1] = param_3[iVar2];
            fVar10 = *pfVar1;
            *pfVar1 = fVar9;
            param_3[iVar2] = fVar8;
            param_3[iVar2 + 1] = fVar10;
            fVar9 = pfVar5[-1];
            fVar8 = *pfVar5;
            fVar10 = param_3[iVar11 + 1];
            pfVar5[-1] = param_3[iVar11];
            *pfVar5 = fVar10;
            param_3[iVar11] = fVar9;
            param_3[iVar11 + 1] = fVar8;
            fVar8 = pfVar3[-1];
            fVar10 = *pfVar3;
            fVar9 = param_3[iVar6 + 1];
            pfVar3[-1] = param_3[iVar6];
            *pfVar3 = fVar9;
            param_3[iVar6] = fVar8;
            param_3[iVar6 + 1] = fVar10;
            pfVar1 = pfVar1 + 2;
            pfVar3 = pfVar3 + 2;
            pfVar5 = pfVar5 + 2;
            pfVar7 = pfVar7 + 2;
        } while (local_3c != local_48);
        local_24 = local_24 + 2;
        local_3c = local_3c + 1;
    }
    return;
}



// FFT_R24_F32::makewt(int, int*, float*)

void FFT_R24_F32::makewt(int param_1,int *param_2,float *param_3) {
    int iVar1;
    undefined4 uVar2;
    undefined4 uVar3;
    undefined4 extraout_r1;
    undefined4 extraout_r1_00;
    undefined4 extraout_r1_01;
    int iVar4;
    int iVar5;
    float *pfVar6;
    float *pfVar7;
    undefined4 in_cr7;
    undefined4 in_cr8;
    undefined4 in_cr9;
    undefined4 unaff_s16;
    undefined4 in_stack_ffffffc8;

    *param_2 = param_1;
    param_2[1] = 1;
    if (2 < param_1) {
        iVar1 = param_1 >> 1;
        *param_3 = 1.0;
        param_3[1] = 0.0;
        coprocessor_function(10,6,5,in_cr7,in_cr7,in_cr9);
        uVar2 = SUB84((double)(longlong)iVar1,0);
        cos((double)CONCAT44(unaff_s16,in_stack_ffffffc8));
        param_3[iVar1] = (float)(double)CONCAT44(extraout_r1,uVar2);
        (param_3 + iVar1)[1] = (float)(double)CONCAT44(extraout_r1,uVar2);
        if (2 < iVar1) {
            iVar4 = 2;
            pfVar6 = param_3 + param_1;
            pfVar7 = param_3 + 3;
            do {
                iVar5 = iVar4 + 2;
                coprocessor_function(10,2,1,in_cr8,in_cr8,in_cr9);
                uVar3 = SUB84((double)(longlong)iVar4,0);
                uVar2 = uVar3;
                cos((double)CONCAT44(unaff_s16,in_stack_ffffffc8));
                sin((double)CONCAT44(unaff_s16,in_stack_ffffffc8));
                pfVar7[-1] = (float)(double)CONCAT44(extraout_r1_00,uVar2);
                *pfVar7 = (float)(double)CONCAT44(extraout_r1_01,uVar3);
                pfVar6[-1] = (float)(double)CONCAT44(extraout_r1_00,uVar2);
                pfVar6[-2] = (float)(double)CONCAT44(extraout_r1_01,uVar3);
                iVar4 = iVar5;
                pfVar6 = pfVar6 + -2;
                pfVar7 = pfVar7 + 2;
            } while (iVar5 < iVar1);
            bitrv2(this,param_1,param_2 + 2,param_3);
            return;
        }
    }
    return;
}



// FFT_R24_F32::cft1st(int, float*, float*)

FFT_R24_F32::cft1st(int param_1,float *param_2,float *param_3) {
    float *pfVar1;
    float *pfVar2;
    float *pfVar3;
    float *pfVar4;
    float *pfVar5;
    float *pfVar6;
    float *pfVar7;
    float *pfVar8;
    float *pfVar9;
    undefined4 in_cr0;
    undefined4 in_cr1;
    undefined4 in_cr2;
    undefined4 in_cr3;
    undefined4 in_cr4;
    undefined4 in_cr5;
    undefined4 in_cr6;
    undefined4 in_cr7;
    undefined4 in_cr8;
    undefined4 in_cr9;
    float fVar10;
    float fVar11;
    float fVar12;
    float fVar13;
    float fVar14;
    float fVar15;
    float fVar16;
    float fVar17;
    float fVar18;
    float fVar19;
    float fVar20;
    float fVar21;
    float fVar22;
    float fVar23;
    float fVar24;
    float fVar25;
    float fVar26;
    float fVar27;
    float *local_4c;
    int local_48;

    fVar26 = param_2[4] + param_2[6];
    fVar14 = param_2[4] - param_2[6];
    fVar16 = param_2[0xd] - param_2[0xf];
    fVar27 = *param_2 + param_2[2];
    fVar25 = param_2[1] + param_2[3];
    fVar24 = param_2[5] + param_2[7];
    fVar10 = *param_2 - param_2[2];
    fVar12 = param_2[1] - param_2[3];
    fVar13 = param_2[0xc] - param_2[0xe];
    fVar18 = param_2[9] - param_2[0xb];
    fVar11 = param_2[5] - param_2[7];
    fVar19 = param_2[8] - param_2[10];
    fVar15 = fVar19 - fVar16;
    fVar17 = fVar18 + fVar13;
    fVar20 = param_2[8] + param_2[10];
    fVar21 = param_2[0xc] + param_2[0xe];
    fVar23 = param_2[9] + param_2[0xb];
    fVar22 = param_2[0xd] + param_2[0xf];
    *param_2 = fVar27 + fVar26;
    param_2[4] = fVar27 - fVar26;
    param_2[1] = fVar25 + fVar24;
    param_2[5] = fVar25 - fVar24;
    param_2[2] = fVar10 - fVar11;
    param_2[6] = fVar10 + fVar11;
    param_2[3] = fVar12 + fVar14;
    param_2[7] = fVar12 - fVar14;
    fVar10 = param_3[2];
    coprocessor_function(10,6,5,in_cr2,in_cr2,in_cr7);
    coprocessor_function(10,2,1,in_cr4,in_cr4,in_cr7);
    coprocessor_function(10,2,1,in_cr3,in_cr3,in_cr7);
    coprocessor_function(10,6,1,in_cr7,in_cr5,in_cr7);
    param_2[8] = fVar20 + fVar21;
    param_2[0xd] = fVar20 - fVar21;
    param_2[9] = fVar23 + fVar22;
    param_2[0xc] = fVar22 - fVar23;
    param_2[10] = fVar15 - fVar17;
    param_2[0xb] = fVar15 + fVar17;
    param_2[0xe] = (fVar13 - fVar18) - (fVar16 + fVar19);
    param_2[0xf] = fVar10;
    if (0x10 < param_1) {
        local_48 = 0x10;
        pfVar1 = param_2 + 0x17;
        pfVar2 = param_2 + 0x15;
        pfVar3 = param_2 + 0x16;
        pfVar4 = param_2 + 0x14;
        pfVar5 = param_2 + 0x13;
        pfVar6 = param_2 + 0x11;
        pfVar7 = param_2 + 0x12;
        pfVar8 = param_2 + 0x10;
        pfVar9 = param_2 + 0x18;
        local_4c = param_3;
        do {
            this = (FFT_R24_F32 *)(param_3 + 4);
            fVar17 = *pfVar4;
            fVar18 = *pfVar5;
            fVar23 = local_4c[3];
            fVar21 = param_3[5];
            fVar13 = *pfVar8 + *pfVar7;
            fVar15 = *pfVar6 + fVar18;
            fVar14 = fVar17 + *pfVar3;
            fVar10 = *pfVar8 - *pfVar7;
            fVar16 = *pfVar2 + *pfVar1;
            fVar22 = *(float *)this;
            local_48 = local_48 + 0x10;
            fVar19 = fVar17 - *pfVar3;
            fVar20 = *pfVar2 - *pfVar1;
            fVar12 = *pfVar6 - fVar18;
            local_4c = local_4c + 2;
            fVar11 = fVar22 - (fVar23 + fVar23) * fVar21;
            coprocessor_function(10,6,0,in_cr3,in_cr7,in_cr9);
            fVar24 = *local_4c;
            coprocessor_function(10,2,1,in_cr4,in_cr7,in_cr9);
            coprocessor_function(10,6,0,in_cr4,in_cr6,in_cr8);
            coprocessor_function(10,2,1,in_cr6,in_cr6,in_cr8);
            coprocessor_function(10,2,4,in_cr5,in_cr5,in_cr1);
            coprocessor_function(10,6,4,in_cr5,in_cr5,in_cr0);
            *pfVar8 = fVar13 + fVar14;
            *pfVar6 = fVar15 + fVar16;
            *pfVar4 = fVar24 * (fVar13 - fVar14) - fVar17;
            *pfVar2 = fVar18 + fVar24 * (fVar15 - fVar16);
            *pfVar7 = fVar22 * (fVar10 - fVar20) - fVar19;
            *pfVar5 = fVar21 + fVar22 * (fVar12 + fVar19);
            *pfVar3 = fVar11 * (fVar10 + fVar20) - fVar20;
            *pfVar1 = (fVar22 * (fVar23 + fVar23) - fVar21) + fVar11 * (fVar12 - fVar19);
            fVar13 = param_2[0x1d] + param_2[0x1f];
            fVar17 = param_2[0x1d] - param_2[0x1f];
            fVar15 = param_2[0x1c] + param_2[0x1e];
            fVar18 = param_2[0x1c] - param_2[0x1e];
            fVar21 = param_3[6];
            fVar12 = param_2[0x19] + param_2[0x1b];
            fVar11 = param_2[0x19] - param_2[0x1b];
            fVar20 = param_3[7];
            fVar16 = param_2[0x1a];
            fVar19 = fVar21 - (fVar24 + fVar24) * fVar20;
            fVar14 = *pfVar9 + fVar16;
            fVar10 = *pfVar9 - fVar16;
            coprocessor_function(10,2,4,in_cr4,in_cr7,in_cr8);
            coprocessor_function(10,6,0,in_cr4,in_cr6,in_cr0);
            coprocessor_function(10,2,5,in_cr5,in_cr5,in_cr1);
            coprocessor_function(10,6,5,in_cr7,in_cr7,in_cr8);
            coprocessor_function(10,2,0,in_cr6,in_cr6,in_cr9);
            coprocessor_function(10,6,5,in_cr5,in_cr5,in_cr0);
            *pfVar9 = fVar14 + fVar15;
            param_2[0x19] = fVar12 + fVar13;
            param_2[0x1c] = (0.0 - fVar23) * (fVar14 - fVar15) - fVar16;
            param_2[0x1d] = fVar24 + (fVar12 - fVar13) * (0.0 - fVar23);
            param_2[0x1a] = fVar21 * (fVar10 - fVar17) - fVar20;
            param_2[0x1b] = fVar17 + fVar21 * (fVar11 + fVar18);
            param_2[0x1e] = fVar19 * (fVar10 + fVar17) - fVar19;
            param_2[0x1f] = (fVar21 * (fVar24 + fVar24) - fVar20) + fVar19 * (fVar11 - fVar18);
            param_3 = (float *)this;
            param_2 = param_2 + 0x10;
            pfVar1 = pfVar1 + 0x10;
            pfVar2 = pfVar2 + 0x10;
            pfVar3 = pfVar3 + 0x10;
            pfVar4 = pfVar4 + 0x10;
            pfVar5 = pfVar5 + 0x10;
            pfVar6 = pfVar6 + 0x10;
            pfVar7 = pfVar7 + 0x10;
            pfVar8 = pfVar8 + 0x10;
            pfVar9 = pfVar9 + 0x10;
        } while (local_48 < param_1);
    }
    return this;
}



// FFT_R24_F32::cftmdl(int, int, float*, float*)

FFT_R24_F32::cftmdl(int param_1,int param_2,float *param_3,float *param_4) {
    int iVar1;
    float *pfVar2;
    float *pfVar3;
    float *pfVar4;
    float *pfVar5;
    float *pfVar6;
    float *pfVar7;
    int iVar8;
    int iVar9;
    int iVar10;
    int iVar11;
    int iVar12;
    undefined4 in_cr0;
    undefined4 in_cr1;
    undefined4 in_cr2;
    undefined4 in_cr3;
    undefined4 in_cr4;
    undefined4 in_cr5;
    undefined4 in_cr6;
    undefined4 in_cr7;
    undefined4 in_cr8;
    undefined4 in_cr9;
    undefined4 in_cr10;
    float fVar13;
    float fVar14;
    float fVar15;
    float fVar16;
    float fVar17;
    float fVar18;
    float fVar19;
    float fVar20;
    float fVar21;
    float fVar22;
    float fVar23;
    float fVar24;
    float fVar25;
    float fVar26;
    float fVar27;
    float fVar28;

    iVar1 = param_2 * 4;
    if (0 < param_2) {
        pfVar2 = param_3 + 1;
        pfVar3 = param_3 + param_2 + 1;
        pfVar4 = param_3 + param_2 * 3 + 1;
        pfVar5 = param_3 + param_2 * 2 + 1;
        do {
            fVar19 = *pfVar5 + *pfVar4;
            fVar17 = *pfVar2 + *pfVar3;
            fVar13 = pfVar2[-1] + pfVar3[-1];
            fVar15 = pfVar5[-1] + pfVar4[-1];
            fVar25 = *pfVar2 - *pfVar3;
            fVar21 = pfVar2[-1] - pfVar3[-1];
            fVar28 = pfVar5[-1] - pfVar4[-1];
            fVar23 = *pfVar5 - *pfVar4;
            pfVar2[-1] = fVar13 + fVar15;
            this = (FFT_R24_F32 *)(pfVar2 + 2);
            *pfVar2 = fVar17 + fVar19;
            pfVar5[-1] = fVar13 - fVar15;
            *pfVar5 = fVar17 - fVar19;
            pfVar3[-1] = fVar21 - fVar23;
            *pfVar3 = fVar25 + fVar28;
            pfVar4[-1] = fVar21 + fVar23;
            *pfVar4 = fVar25 - fVar28;
            pfVar2 = (float *)this;
            pfVar3 = pfVar3 + 2;
            pfVar4 = pfVar4 + 2;
            pfVar5 = pfVar5 + 2;
        } while ((float *)this != param_3 + (param_2 - 1U & 0xfffffffe) + 3);
    }
    if (0 < param_2 != SBORROW4(iVar1,param_2 * 5)) {
        pfVar2 = param_3 + iVar1 + 1;
        pfVar3 = param_3 + param_2 * 6 + 1;
        pfVar4 = param_3 + param_2 * 7 + 1;
        pfVar5 = param_3 + param_2 * 5 + 1;
        do {
            fVar17 = *pfVar3 - *pfVar4;
            fVar13 = pfVar3[-1] - pfVar4[-1];
            fVar19 = pfVar2[-1] - pfVar5[-1];
            fVar21 = *pfVar2 - *pfVar5;
            fVar28 = *pfVar3 + *pfVar4;
            fVar26 = *pfVar2 + *pfVar5;
            fVar25 = pfVar3[-1] + pfVar4[-1];
            fVar15 = fVar19 - fVar17;
            fVar17 = fVar17 + fVar19;
            fVar19 = fVar21 + fVar13;
            fVar23 = pfVar2[-1] + pfVar5[-1];
            fVar13 = fVar13 - fVar21;
            coprocessor_function(10,2,1,in_cr4,in_cr4,in_cr7);
            pfVar2[-1] = fVar23 + fVar25;
            this = (FFT_R24_F32 *)(pfVar2 + 2);
            *pfVar2 = fVar26 + fVar28;
            coprocessor_function(10,6,5,in_cr2,in_cr2,in_cr7);
            coprocessor_function(10,2,1,in_cr5,in_cr5,in_cr7);
            pfVar3[-1] = fVar28 - fVar26;
            *pfVar3 = fVar23 - fVar25;
            coprocessor_function(10,2,1,in_cr3,in_cr3,in_cr7);
            pfVar5[-1] = fVar15 - fVar19;
            *pfVar5 = fVar15 + fVar19;
            pfVar4[-1] = fVar13 - fVar17;
            *pfVar4 = fVar13 + fVar17;
            pfVar2 = (float *)this;
            pfVar3 = pfVar3 + 2;
            pfVar4 = pfVar4 + 2;
            pfVar5 = pfVar5 + 2;
        } while ((float *)this != param_3 + iVar1 + (param_2 - 1U & 0xfffffffe) + 3);
    }
    iVar1 = param_2 * 8;
    if (iVar1 < param_1) {
        iVar9 = param_2 * 0xc;
        iVar11 = param_2 * 9;
        iVar10 = param_2 * 0xd;
        iVar12 = 0;
        iVar8 = iVar1;
        pfVar2 = param_4;
        do {
            fVar19 = pfVar2[3];
            fVar15 = param_4[4];
            fVar13 = pfVar2[2];
            fVar17 = fVar15 - (fVar19 + fVar19) * param_4[5];
            if (iVar8 < iVar11) {
                pfVar3 = (float *)((int)param_3 + iVar12 + param_2 * 0x2c + 4);
                pfVar4 = (float *)((int)param_3 + iVar12 + param_2 * 0x28 + 4);
                pfVar5 = (float *)((int)param_3 + iVar12 + param_2 * 0x24 + 4);
                pfVar7 = (float *)((int)param_3 + iVar12 + param_2 * 0x20 + 4);
                do {
                    fVar16 = pfVar5[-1];
                    fVar18 = pfVar4[-1];
                    fVar20 = *pfVar5;
                    fVar22 = *pfVar4;
                    fVar25 = pfVar7[-1] + fVar16;
                    fVar28 = fVar18 + pfVar3[-1];
                    fVar14 = fVar22 + *pfVar3;
                    fVar26 = *pfVar7 + fVar20;
                    fVar27 = fVar22 - *pfVar3;
                    fVar21 = pfVar7[-1] - fVar16;
                    fVar24 = fVar18 - pfVar3[-1];
                    fVar23 = *pfVar7 - fVar20;
                    coprocessor_function(10,2,4,in_cr5,in_cr10,in_cr8);
                    coprocessor_function(10,6,4,in_cr4,in_cr10,in_cr0);
                    coprocessor_function(10,2,1,in_cr6,in_cr9,in_cr0);
                    coprocessor_function(10,6,0,in_cr5,in_cr9,in_cr1);
                    coprocessor_function(10,2,1,in_cr7,in_cr10,in_cr1);
                    coprocessor_function(10,6,0,in_cr6,in_cr10,in_cr2);
                    pfVar7[-1] = fVar25 + fVar28;
                    pfVar6 = pfVar7 + 2;
                    *pfVar7 = fVar26 + fVar14;
                    pfVar4[-1] = fVar13 * (fVar25 - fVar28) - fVar16;
                    *pfVar4 = fVar18 + fVar13 * (fVar26 - fVar14);
                    pfVar5[-1] = fVar15 * (fVar21 - fVar27) - fVar20;
                    *pfVar5 = fVar22 + fVar15 * (fVar23 + fVar24);
                    pfVar3[-1] = fVar17 * (fVar21 + fVar27) - fVar24;
                    *pfVar3 = fVar27 + fVar17 * (fVar23 - fVar24);
                    pfVar3 = pfVar3 + 2;
                    pfVar4 = pfVar4 + 2;
                    pfVar5 = pfVar5 + 2;
                    pfVar7 = pfVar6;
                } while (pfVar6 != param_3 + 3 + ((iVar11 + -1) - iVar8 & 0xfffffffeU) + iVar8);
            }
            fVar15 = param_4[6];
            fVar13 = fVar15 - (fVar13 + fVar13) * param_4[7];
            if (iVar9 < iVar10) {
                pfVar3 = (float *)((int)param_3 + iVar12 + param_2 * 0x3c + 4);
                pfVar4 = (float *)((int)param_3 + iVar12 + param_2 * 0x38 + 4);
                pfVar5 = (float *)((int)param_3 + iVar12 + param_2 * 0x34 + 4);
                pfVar7 = (float *)((int)param_3 + iVar12 + param_2 * 0x30 + 4);
                do {
                    fVar14 = pfVar5[-1];
                    fVar16 = pfVar4[-1];
                    fVar18 = *pfVar5;
                    fVar20 = *pfVar4;
                    fVar23 = pfVar7[-1] + fVar14;
                    fVar25 = fVar16 + pfVar3[-1];
                    fVar26 = fVar20 + *pfVar3;
                    fVar28 = *pfVar7 + fVar18;
                    fVar24 = fVar20 - *pfVar3;
                    fVar17 = pfVar7[-1] - fVar14;
                    fVar22 = fVar16 - pfVar3[-1];
                    fVar21 = *pfVar7 - fVar18;
                    coprocessor_function(10,2,4,in_cr5,in_cr7,in_cr8);
                    coprocessor_function(10,6,4,in_cr4,in_cr7,in_cr0);
                    coprocessor_function(10,2,1,in_cr6,in_cr9,in_cr0);
                    coprocessor_function(10,6,0,in_cr5,in_cr9,in_cr1);
                    coprocessor_function(10,2,1,in_cr7,in_cr10,in_cr1);
                    coprocessor_function(10,6,0,in_cr6,in_cr10,in_cr2);
                    pfVar7[-1] = fVar23 + fVar25;
                    pfVar6 = pfVar7 + 2;
                    *pfVar7 = fVar28 + fVar26;
                    pfVar4[-1] = (fVar23 - fVar25) * (0.0 - fVar19) - fVar14;
                    *pfVar4 = fVar16 + (fVar28 - fVar26) * (0.0 - fVar19);
                    pfVar5[-1] = fVar15 * (fVar17 - fVar24) - fVar18;
                    *pfVar5 = fVar20 + fVar15 * (fVar21 + fVar22);
                    pfVar3[-1] = fVar13 * (fVar17 + fVar24) - fVar22;
                    *pfVar3 = fVar24 + fVar13 * (fVar21 - fVar22);
                    pfVar3 = pfVar3 + 2;
                    pfVar4 = pfVar4 + 2;
                    pfVar5 = pfVar5 + 2;
                    pfVar7 = pfVar6;
                } while (pfVar6 != param_3 + 3 + iVar9 + ((iVar10 + -1) - iVar9 & 0xfffffffeU));
            }
            iVar8 = iVar8 + iVar1;
            pfVar2 = pfVar2 + 2;
            param_4 = param_4 + 4;
            iVar11 = iVar11 + iVar1;
            iVar9 = iVar9 + iVar1;
            iVar10 = iVar10 + iVar1;
            iVar12 = iVar12 + param_2 * 0x20;
            this = (FFT_R24_F32 *)param_1;
        } while (iVar8 < param_1);
    }
    return this;
}



// FFT_R24_F32::cftfsub(int, float*, float*)

void FFT_R24_F32::cftfsub(int param_1,float *param_2,float *param_3) {
    float *pfVar1;
    float *pfVar2;
    int iVar3;
    int iVar4;
    float *pfVar5;
    float *pfVar6;
    int iVar7;
    float *pfVar8;
    float fVar9;
    float fVar10;
    float fVar11;
    float fVar12;
    float fVar13;
    float fVar14;
    float fVar15;
    float fVar16;

    if (param_1 < 9) {
        iVar4 = 8;
        iVar7 = 2;
    }
    else {
        cft1st(this,param_1,param_2,param_3);
        if (0x20 < param_1) {
            iVar3 = 8;
            iVar4 = 0x20;
            do {
                iVar7 = iVar4;
                cftmdl(this,param_1,iVar3,param_2,param_3);
                iVar4 = iVar7 * 4;
                iVar3 = iVar7;
            } while (param_1 != iVar4 && param_1 + iVar7 * -4 < 0 == SBORROW4(param_1,iVar4));
            if (param_1 == iVar4) goto LAB_0006175c;
            if (iVar7 < 1) {
                return;
            }
            goto LAB_000616ac;
        }
        iVar4 = 0x20;
        iVar7 = 8;
    }
    if (param_1 == iVar4) {
        LAB_0006175c:
        if (iVar7 < 1) {
            return;
        }
        pfVar1 = param_2 + iVar7 * 3 + 1;
        pfVar2 = param_2 + iVar7 * 2 + 1;
        pfVar5 = param_2 + 1;
        pfVar8 = param_2 + iVar7 + 1;
        do {
            fVar15 = *pfVar2 + *pfVar1;
            fVar13 = *pfVar5 + *pfVar8;
            fVar9 = pfVar5[-1] + pfVar8[-1];
            fVar11 = pfVar2[-1] + pfVar1[-1];
            fVar14 = *pfVar5 - *pfVar8;
            fVar10 = pfVar5[-1] - pfVar8[-1];
            fVar16 = pfVar2[-1] - pfVar1[-1];
            fVar12 = *pfVar2 - *pfVar1;
            pfVar5[-1] = fVar9 + fVar11;
            pfVar6 = pfVar5 + 2;
            *pfVar5 = fVar13 + fVar15;
            pfVar2[-1] = fVar9 - fVar11;
            *pfVar2 = fVar13 - fVar15;
            pfVar8[-1] = fVar10 - fVar12;
            *pfVar8 = fVar14 + fVar16;
            pfVar1[-1] = fVar10 + fVar12;
            *pfVar1 = fVar14 - fVar16;
            pfVar1 = pfVar1 + 2;
            pfVar2 = pfVar2 + 2;
            pfVar5 = pfVar6;
            pfVar8 = pfVar8 + 2;
        } while (pfVar6 != param_2 + iVar7 + 1);
        return;
    }
    LAB_000616ac:
    pfVar1 = param_2 + iVar7 + 1;
    pfVar2 = param_2 + 1;
    do {
        fVar11 = pfVar2[-1];
        fVar13 = pfVar1[-1];
        fVar15 = *pfVar2;
        fVar9 = *pfVar1;
        pfVar2[-1] = fVar11 + fVar13;
        pfVar5 = pfVar2 + 2;
        *pfVar2 = fVar15 + *pfVar1;
        pfVar1[-1] = fVar11 - fVar13;
        *pfVar1 = fVar15 - fVar9;
        pfVar1 = pfVar1 + 2;
        pfVar2 = pfVar5;
    } while (pfVar5 != param_2 + iVar7 + 1);
    return;
}



// FFT_R24_F32::cftbsub(int, float*, float*)

void FFT_R24_F32::cftbsub(int param_1,float *param_2,float *param_3) {
    float *pfVar1;
    float *pfVar2;
    int iVar3;
    int iVar4;
    float *pfVar5;
    float *pfVar6;
    int iVar7;
    float *pfVar8;
    float fVar9;
    float fVar10;
    float fVar11;
    float fVar12;
    float fVar13;
    float fVar14;
    float fVar15;
    float fVar16;

    if (param_1 < 9) {
        iVar4 = 8;
        iVar7 = 2;
    }
    else {
        cft1st(this,param_1,param_2,param_3);
        if (0x20 < param_1) {
            iVar3 = 8;
            iVar4 = 0x20;
            do {
                iVar7 = iVar4;
                cftmdl(this,param_1,iVar3,param_2,param_3);
                iVar4 = iVar7 * 4;
                iVar3 = iVar7;
            } while (param_1 != iVar4 && param_1 + iVar7 * -4 < 0 == SBORROW4(param_1,iVar4));
            if (param_1 == iVar4) goto LAB_0006191c;
            if (iVar7 < 1) {
                return;
            }
            goto LAB_00061868;
        }
        iVar4 = 0x20;
        iVar7 = 8;
    }
    if (param_1 == iVar4) {
        LAB_0006191c:
        if (iVar7 < 1) {
            return;
        }
        pfVar1 = param_2 + iVar7 * 3 + 1;
        pfVar2 = param_2 + iVar7 * 2 + 1;
        pfVar5 = param_2 + 1;
        pfVar8 = param_2 + iVar7 + 1;
        do {
            fVar11 = *pfVar2 + *pfVar1;
            fVar9 = (0.0 - *pfVar5) - *pfVar8;
            fVar13 = pfVar5[-1] + pfVar8[-1];
            fVar15 = pfVar2[-1] + pfVar1[-1];
            fVar10 = pfVar5[-1] - pfVar8[-1];
            fVar12 = *pfVar2 - *pfVar1;
            fVar16 = pfVar2[-1] - pfVar1[-1];
            fVar14 = *pfVar8 - *pfVar5;
            pfVar5[-1] = fVar13 + fVar15;
            pfVar6 = pfVar5 + 2;
            *pfVar5 = fVar9 - fVar11;
            pfVar2[-1] = fVar13 - fVar15;
            *pfVar2 = fVar9 + fVar11;
            pfVar8[-1] = fVar10 - fVar12;
            *pfVar8 = fVar14 - fVar16;
            pfVar1[-1] = fVar10 + fVar12;
            *pfVar1 = fVar14 + fVar16;
            pfVar1 = pfVar1 + 2;
            pfVar2 = pfVar2 + 2;
            pfVar5 = pfVar6;
            pfVar8 = pfVar8 + 2;
        } while (pfVar6 != param_2 + iVar7 + 1);
        return;
    }
    LAB_00061868:
    pfVar1 = param_2 + iVar7 + 1;
    pfVar2 = param_2 + 1;
    do {
        fVar11 = pfVar2[-1];
        fVar13 = pfVar1[-1];
        fVar15 = *pfVar2;
        fVar9 = *pfVar1;
        pfVar2[-1] = fVar11 + fVar13;
        pfVar5 = pfVar2 + 2;
        *pfVar2 = (0.0 - fVar15) - *pfVar1;
        pfVar1[-1] = fVar11 - fVar13;
        *pfVar1 = fVar9 - fVar15;
        pfVar1 = pfVar1 + 2;
        pfVar2 = pfVar5;
    } while (pfVar5 != param_2 + iVar7 + 1);
    return;
}



// FFT_R24_F32::rftfsub(int, float*, int, float*)

void FFT_R24_F32::rftfsub(int param_1,float *param_2,int param_3,float *param_4) {
    int iVar1;
    int iVar2;
    float *pfVar3;
    float *pfVar4;
    float *pfVar5;
    float *pfVar6;
    float *pfVar7;
    undefined4 in_cr4;
    undefined4 in_cr5;
    undefined4 in_cr7;
    float fVar8;
    float extraout_s14;
    float fVar9;

    iVar1 = param_1 >> 1;
    iVar2 = __divsi3(param_3 << 1,iVar1,param_2,param_3,param_3);
    if (iVar1 < 3) {
        return;
    }
    pfVar7 = param_4 + (param_3 - iVar2);
    pfVar3 = param_2 + param_1;
    pfVar5 = param_2 + 3;
    fVar9 = extraout_s14;
    do {
        param_4 = param_4 + iVar2;
        pfVar4 = pfVar3 + -2;
        fVar8 = *pfVar7;
        pfVar7 = pfVar7 + -iVar2;
        coprocessor_function(10,2,5,in_cr7,in_cr7,in_cr5);
        coprocessor_function(10,6,5,in_cr7,in_cr7,in_cr4);
        fVar9 = (0.5 - fVar8) * (pfVar5[-1] - *pfVar4) - fVar9;
        fVar8 = *param_4 + (0.5 - fVar8) * (*pfVar5 + pfVar3[-1]);
        pfVar5[-1] = pfVar5[-1] - fVar9;
        pfVar6 = pfVar5 + 2;
        *pfVar5 = *pfVar5 - fVar8;
        fVar9 = *pfVar4 + fVar9;
        *pfVar4 = fVar9;
        pfVar3[-1] = pfVar3[-1] - fVar8;
        pfVar3 = pfVar4;
        pfVar5 = pfVar6;
    } while (pfVar6 != param_2 + (iVar1 - 3U & 0xfffffffe) + 5);
    return;
}



// FFT_R24_F32::rftbsub(int, float*, int, float*)

void FFT_R24_F32::rftbsub(int param_1,float *param_2,int param_3,float *param_4) {
    int iVar1;
    int iVar2;
    float *pfVar3;
    float *pfVar4;
    float *pfVar5;
    float *pfVar6;
    float *pfVar7;
    undefined4 in_cr4;
    undefined4 in_cr5;
    undefined4 in_cr7;
    float fVar8;
    float extraout_s14;
    float fVar9;

    iVar1 = param_1 >> 1;
    param_2[1] = 0.0 - param_2[1];
    iVar2 = __divsi3(param_3 << 1,iVar1);
    if (2 < iVar1) {
        pfVar5 = param_4 + (param_3 - iVar2);
        pfVar3 = param_2 + param_1;
        pfVar6 = param_2 + 3;
        fVar9 = extraout_s14;
        do {
            param_4 = param_4 + iVar2;
            pfVar4 = pfVar3 + -2;
            fVar8 = *pfVar5;
            pfVar5 = pfVar5 + -iVar2;
            coprocessor_function(10,2,5,in_cr7,in_cr7,in_cr5);
            coprocessor_function(10,6,5,in_cr7,in_cr7,in_cr4);
            fVar9 = fVar9 + (0.5 - fVar8) * (pfVar6[-1] - *pfVar4);
            fVar8 = (0.5 - fVar8) * (*pfVar6 + pfVar3[-1]) - *param_4;
            pfVar6[-1] = pfVar6[-1] - fVar9;
            pfVar7 = pfVar6 + 2;
            *pfVar6 = fVar8 - *pfVar6;
            fVar9 = *pfVar4 + fVar9;
            *pfVar4 = fVar9;
            pfVar3[-1] = fVar8 - pfVar3[-1];
            pfVar3 = pfVar4;
            pfVar6 = pfVar7;
        } while (pfVar7 != param_2 + (iVar1 - 3U & 0xfffffffe) + 5);
    }
    param_2[iVar1 + 1] = 0.0 - param_2[iVar1 + 1];
    return;
}



// FFT_R24_F32::rdft(int, int, float*, int*, float*)

void FFT_R24_F32::rdft(int param_1,int param_2,float *param_3,int *param_4,
                       float *param_5) {
    int iVar1;
    int iVar2;
    int iVar3;
    undefined4 in_cr6;
    undefined4 in_cr7;
    float fVar4;

    iVar2 = *param_4;
    iVar1 = param_1 >> 2;
    if (param_1 != iVar2 * 4 && param_1 + iVar2 * -4 < 0 == SBORROW4(param_1,iVar2 * 4)) {
        makewt(this,iVar1,param_4,param_5);
        iVar2 = iVar1;
    }
    iVar3 = param_4[1];
    if (param_1 != iVar3 * 4 && param_1 + iVar3 * -4 < 0 == SBORROW4(param_1,iVar3 * 4)) {
        makect(this,iVar1,param_4,param_5 + iVar2);
        iVar3 = iVar1;
    }
    if (param_2 < 0) {
        fVar4 = *param_3 - param_3[1];
        coprocessor_function(10,6,5,in_cr7,in_cr7,in_cr6);
        param_3[1] = fVar4;
        *param_3 = *param_3 - fVar4;
        if (4 < param_1) {
            rftbsub(this,param_1,param_3,iVar3,param_5 + iVar2);
            bitrv2(this,param_1,param_4 + 2,param_3);
            cftbsub(this,param_1,param_3,param_5);
            return;
        }
        if (param_1 == 4) {
            cftfsub(this,4,param_3,param_5);
            return;
        }
    }
    else {
        if (param_1 < 5) {
            if (param_1 == 4) {
                cftfsub(this,4,param_3,param_5);
            }
        }
        else {
            bitrv2(this,param_1,param_4 + 2,param_3);
            cftfsub(this,param_1,param_3,param_5);
            rftfsub(this,param_1,param_3,iVar3,param_5 + iVar2);
        }
        fVar4 = *param_3;
        *param_3 = fVar4 + param_3[1];
        param_3[1] = fVar4 - param_3[1];
    }
    return;
}



// FFT_R24_F32::FFT_R24_F32(int)

FFT_R24_F32::FFT_R24_F32(int param_1) {
    uint uVar1;
    void *pvVar2;
    undefined4 uVar3;
    undefined4 extraout_r1;
    undefined4 unaff_r4;
    undefined4 unaff_r5;
    uint uVar4;
    bool in_ZR;
    double dVar5;

    dVar5 = SQRT((double)(longlong)param_1);
    if (!in_ZR) {
        uVar3 = SUB84((double)(longlong)param_1,0);
        sqrt((double)CONCAT44(unaff_r5,unaff_r4));
        dVar5 = (double)CONCAT44(extraout_r1,uVar3);
    }
    *(int *)(this + 8) = param_1;
    if ((uint)(param_1 * 2) < 0x1fc00001) {
        uVar1 = param_1 << 3;
    }
    else {
        uVar1 = 0xffffffff;
    }
    uVar4 = SUB84(ROUND(dVar5),0) + 2;
    pvVar2 = operator_new__(uVar1);
    *(void **)this = pvVar2;
    if (uVar4 < 0x1fc00001) {
        uVar1 = uVar4 * 4;
    }
    else {
        uVar1 = 0xffffffff;
    }
    pvVar2 = operator_new__(uVar1);
    *(void **)(this + 4) = pvVar2;
    if ((*(void **)this != nullptr) && (pvVar2 != nullptr)) {
        memset(*(void **)this,0,param_1 << 3);
        memset(*(void **)(this + 4),0,uVar4 * 4);
    }
    return this;
}



// FFT_R24_F32::~FFT_R24_F32()

FFT_R24_F32::~FFT_R24_F32() {
    if (*(void **)this != nullptr) {
        operator_delete__(*(void **)this);
    }
    if (*(void **)(this + 4) != nullptr) {
        operator_delete__(*(void **)(this + 4));
    }
    return this;
}



// FFT_R24_F32::RDFT(float*)

void FFT_R24_F32::RDFT(float *param_1) {
    if ((*(float **)this != nullptr) && (*(int **)(this + 4) != nullptr)) {
        rdft(this,*(int *)(this + 8),1,param_1,*(int **)(this + 4),*(float **)this);
    }
    return;
}



// FFT_R24_F32::IRDFT(float*)

void FFT_R24_F32::IRDFT(float *param_1) {
    if ((*(float **)this != nullptr) && (*(int **)(this + 4) != nullptr)) {
        rdft(this,*(int *)(this + 8),-1,param_1,*(int **)(this + 4),*(float **)this);
    }
    return;
}

