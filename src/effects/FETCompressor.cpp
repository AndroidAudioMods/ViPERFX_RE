//
// Created by mart on 2/12/21.
//

#include "FETCompressor.h"

// FETCompressor::~FETCompressor()

FETCompressor::~FETCompressor() {
    return;
}



// FETCompressor::SetParameter(int, float)

void FETCompressor::SetParameter(int param_1,float param_2) {
    undefined4 uVar1;
    int in_r1;
    float in_r2;
    undefined uVar2;
    int iVar3;
    char cVar4;
    bool bVar5;
    char cVar6;
    undefined4 in_cr6;
    undefined4 in_cr7;
    float in_s1;
    float fVar7;

    iVar3 = param_1 + in_r1 * 4;
    *(float *)(iVar3 + 4) = in_r2;
    cVar6 = SBORROW4(in_r1,0x10);
    cVar4 = in_r1 + -0x10 < 0;
    bVar5 = in_r1 == 0x10;
    switch(in_r1) {
        case 0:
            if (in_r1 < 0x10) {
                iVar3 = 0;
            }
            uVar2 = (undefined)iVar3;
            if (0xf < in_r1) {
                uVar2 = 1;
            }
            *(undefined *)(param_1 + 0x4c) = uVar2;
            return;
        case 1:
            uVar1 = 0x41200000;
            coprocessor_function(10,6,5,in_cr7,in_cr7,in_cr6);
            fVar7 = powf(param_2,in_s1);
            logf(fVar7);
            *(undefined4 *)(param_1 + 100) = uVar1;
            return;
        case 2:
            *(float *)(param_1 + 0x74) = 0.0 - in_r2;
            return;
        case 3:
            uVar1 = 0x41200000;
            coprocessor_function(10,6,5,in_cr7,in_cr7,in_cr6);
            fVar7 = powf(param_2,in_s1);
            logf(fVar7);
            *(undefined4 *)(param_1 + 0x68) = uVar1;
            return;
        case 4:
            if (in_r1 < 0x10) {
                iVar3 = 0;
            }
            uVar2 = (undefined)iVar3;
            if (0xf < in_r1) {
                uVar2 = 1;
            }
            *(undefined *)(param_1 + 0x4d) = uVar2;
            return;
        case 5:
            uVar1 = 0x41200000;
            coprocessor_function(10,6,5,in_cr7,in_cr7,in_cr6);
            fVar7 = powf(param_2,in_s1);
            logf(fVar7);
            *(undefined4 *)(param_1 + 0x70) = uVar1;
            return;
        case 6:
            if (in_r1 < 0x10) {
                iVar3 = 0;
            }
            uVar2 = (undefined)iVar3;
            if (0xf < in_r1) {
                uVar2 = 1;
            }
            *(undefined *)(param_1 + 0x4e) = uVar2;
            return;
        case 7:
            fVar7 = in_r2 * 7.600903 - 9.21034;
            expf(param_2);
            iVar3 = *(int *)param_1;
            *(float *)(param_1 + 0x80) = fVar7;
            if (bVar5 || cVar4 != cVar6) {
                iVar3 = 0x3f800000;
            }
            if (!bVar5 && cVar4 == cVar6) {
                iVar3 = FUN_00067ef8((float)(longlong)iVar3);
            }
            *(int *)(param_1 + 0x84) = iVar3;
            return;
        case 8:
            if (in_r1 < 0x10) {
                iVar3 = 0;
            }
            uVar2 = (undefined)iVar3;
            if (0xf < in_r1) {
                uVar2 = 1;
            }
            *(undefined *)(param_1 + 0x4f) = uVar2;
            return;
        case 9:
            fVar7 = in_r2 * 5.991465 - 5.298317;
            expf(param_2);
            iVar3 = *(int *)param_1;
            *(float *)(param_1 + 0x88) = fVar7;
            if (bVar5 || cVar4 != cVar6) {
                iVar3 = 0x3f800000;
            }
            if (!bVar5 && cVar4 == cVar6) {
                iVar3 = FUN_00067ef8((float)(longlong)iVar3);
            }
            *(int *)(param_1 + 0x8c) = iVar3;
            return;
        case 10:
            if (in_r1 < 0x10) {
                iVar3 = 0;
            }
            uVar2 = (undefined)iVar3;
            if (0xf < in_r1) {
                uVar2 = 1;
            }
            *(undefined *)(param_1 + 0x50) = uVar2;
            return;
        case 0xb:
            *(float *)(param_1 + 0x90) = in_r2 * 4.0 + 0.0;
            return;
        case 0xc:
            fVar7 = in_r2 * 7.600903 - 9.21034;
            expf(param_2);
            *(float *)(param_1 + 0x94) = fVar7;
            return;
        case 0xd:
            fVar7 = in_r2 * 5.991465 - 5.298317;
            expf(param_2);
            *(float *)(param_1 + 0x98) = fVar7;
            return;
        case 0xe:
            fVar7 = in_r2 * 5.991465 - 5.298317;
            expf(param_2);
            iVar3 = *(int *)param_1;
            *(float *)(param_1 + 0x9c) = fVar7;
            if (bVar5 || cVar4 != cVar6) {
                iVar3 = 0x3f800000;
            }
            if (!bVar5 && cVar4 == cVar6) {
                iVar3 = FUN_00067ef8((float)(longlong)iVar3);
            }
            *(int *)(param_1 + 0xa0) = iVar3;
            return;
        case 0xf:
            fVar7 = in_r2 * 1.386294 + 0.0;
            expf(param_2);
            iVar3 = *(int *)param_1;
            *(float *)(param_1 + 0xa4) = fVar7;
            if (bVar5 || cVar4 != cVar6) {
                iVar3 = 0x3f800000;
            }
            if (!bVar5 && cVar4 == cVar6) {
                iVar3 = FUN_00067ef8((float)(longlong)iVar3);
            }
            *(int *)(param_1 + 0xa8) = iVar3;
            return;
        case 0x10:
            if (in_r1 < 0x10) {
                iVar3 = 0;
            }
            uVar2 = (undefined)iVar3;
            if (0xf < in_r1) {
                uVar2 = 1;
            }
            *(undefined *)(param_1 + 0xac) = uVar2;
    }
    return;
}



// FETCompressor::GetParameter(int)

float FETCompressor::GetParameter(int param_1) {
    return this->parameters[param_1];
}



// FETCompressor::GetParameterDefault(int)

float FETCompressor::GetParameterDefault(int param_1) {
    if ((uint)param_1 < 0x11) {
        return FLOAT_ARRAY_000ce870[param_1];
    }
    return 0.0;
}



// WARNING: Removing unreachable block (ram,0x000682cc)
// FETCompressor::GetMeter(int)

float FETCompressor::GetMeter(int param_1) {
    bool bVar1;

    if (param_1 != 0) {
        return 0.0;
    }
    bVar1 = this->field_0x4c == '\0';
    if ((!bVar1) && (bVar1)) {
        return ((0.0 - (float)this->field_0x58) - DAT_000d5894) / (0.0 - DAT_000d5894);
    }
    return 1.0;
}



// FETCompressor::Reset()

void FETCompressor::Reset() {
    undefined4 uVar1;

    uVar1 = FUN_00067ef8((float)(longlong)this->samplerate,0x3d4ccccd);
    this->field_0x48 = uVar1;
    this->field_0x60 = this->field_0x64;
    this->field_0x6c = this->field_0x70;
    this->field_0x78 = 0x358637bd;
    this->field_0x7c = 0x358637bd;
    this->field_0x54 = 0;
    this->field_0x58 = 0;
    this->field_0x5c = 0;
    return;
}



// FETCompressor::FETCompressor()

FETCompressor::FETCompressor() {
    int iVar1;
    float fVar2;

    iVar1 = 0;
    this->samplerate = 0xac44;
    do {
        fVar2 = (float)GetParameterDefault(this,iVar1);
        iVar1 = iVar1 + 1;
        SetParameter((int)this,fVar2);
    } while (iVar1 != 0x11);
    Reset(this);
    return this;
}



// FETCompressor::SetSamplingRate(int)

void FETCompressor::SetSamplingRate(int param_1) {
    int iVar1;
    float fVar2;

    iVar1 = 0;
    this->samplerate = param_1;
    do {
        fVar2 = (float)GetParameter(this,iVar1);
        iVar1 = iVar1 + 1;
        SetParameter((int)this,fVar2);
    } while (iVar1 != 0x11);
    Reset(this);
    return;
}



// WARNING: Removing unreachable block (ram,0x0006850c)
// WARNING: Removing unreachable block (ram,0x00068520)
// WARNING: Removing unreachable block (ram,0x00068624)
// WARNING: Removing unreachable block (ram,0x0006852c)
// FETCompressor::ProcessSidechain(float)

void FETCompressor::ProcessSidechain(float param_1) {
    void *pFVar1;
    FETCompressor *in_r1;
    bool in_NG;
    bool in_ZR;
    char in_OV;
    char cVar1;
    char cVar2;
    bool bVar3;
    undefined uVar4;
    undefined4 in_cr4;
    undefined4 in_cr5;
    undefined4 in_cr6;
    undefined4 in_cr7;
    undefined4 in_cr8;
    float extraout_s0;
    float extraout_s0_00;
    float fVar5;
    float fVar6;
    float in_s15;
    float fVar7;
    float fVar8;
    float fVar9;
    float fVar10;

    coprocessor_function(10,6,0,in_cr7,in_cr8,in_cr8);
    if (in_ZR || in_NG != (bool)in_OV) {
        in_s15 = 1e-06;
    }
    fVar8 = (float)this->field_0x84;
    fVar5 = (float)this->field_0x7c + (in_s15 - (float)this->field_0x7c) * (float)this->field_0xa0;
    fVar9 = this->field_0x80;
    if (in_NG) {
        in_s15 = (float)this->field_0x78 + (float)this->field_0xa0 * (in_s15 - (float)this->field_0x78);
    }
    bVar3 = *(char *)&this->field_0x4f != '\0';
    this->field_0x7c = fVar5;
    this->field_0x78 = in_s15;
    fVar5 = in_s15 / fVar5;
    pFVar1 = this;
    if (bVar3) {
        param_1 = (float)this->samplerate;
        fVar9 = (this->field_0x94 + this->field_0x94) / fVar5;
        if (bVar3) {
            pFVar1 = (void *)FUN_00067ef8((float)(longlong)(int)param_1,fVar9);
            param_1 = extraout_s0;
            fVar8 = extraout_s0;
        }
        else {
            fVar8 = 1.0;
        }
    }
    fVar10 = (float)this->field_0x8c;
    cVar2 = '\0';
    uVar4 = *(char *)&this->field_0x50 == '\0';
    cVar1 = '\0';
    if (!(bool)uVar4) {
        param_1 = (float)this->samplerate;
        if ((bool)uVar4) {
            fVar10 = 1.0;
        }
        else {
            pFVar1 = (void *)FUN_00067ef8((float)(longlong)(int)param_1,
                    (this->field_0x98 + this->field_0x98) / fVar5 - fVar9);
            param_1 = extraout_s0_00;
            fVar10 = extraout_s0_00;
        }
    }
    if ((bool)uVar4 || cVar2 != cVar1) {
        pFVar1 = (FETCompressor *)0x358637bd;
    }
    if (!(bool)uVar4 && cVar2 == cVar1) {
        pFVar1 = in_r1;
    }
    fVar5 = logf(param_1);
    fVar9 = (float)this->field_0x60;
    bVar3 = *(char *)&this->field_0x4d == '\0';
    if (bVar3) {
        coprocessor_function(10,6,4,in_cr6,in_cr6,in_cr5);
        fVar6 = (float)this->field_0x5c;
        coprocessor_function(10,6,0,in_cr5,in_cr6,in_cr4);
        coprocessor_function(10,6,4,in_cr6,in_cr6,in_cr4);
    }
    else {
        fVar6 = (float)this->field_0x5c;
        coprocessor_function(10,6,5,in_cr6,in_cr6,in_cr5);
        if (!bVar3) {
            coprocessor_function(10,6,1,in_cr5,in_cr6,in_cr5);
        }
    }
    coprocessor_function(10,6,4,in_cr7,in_cr7,in_cr5);
    fVar7 = (float)pFVar1 - fVar9;
    if (bVar3) {
        fVar7 = (float)this->field_0x54 + (((float)pFVar1 - fVar9) - (float)this->field_0x54) * fVar10;
    }
    this->field_0x54 = fVar7;
    fVar8 = (float)this->field_0x58 + (fVar7 - (float)this->field_0x58) * fVar8;
    this->field_0x58 = fVar8;
    this->field_0x5c = fVar6 + (((0.0 - fVar8) - fVar9) - fVar6) * (float)this->field_0xa8;
    if (*(char *)&this->field_0x4e != '\0') {
        bVar3 = *(char *)&this->field_0xac != '\0';
        if (bVar3) {
            fVar8 = (float)pFVar1 - fVar8;
            if (bVar3) {
                fVar8 = (fVar8 - fVar9) + 0.00115127;
            }
            if (bVar3) {
                this->field_0x5c = fVar8;
            }
        }
        expf(fVar5);
        return;
    }
    expf(fVar5);
    return;
}



// FETCompressor::Process(int*, int)

void FETCompressor::Process(int *param_1,int param_2) {
    longlong lVar1;
    FETCompressor *pFVar2;
    int *piVar3;
    int iVar4;
    undefined4 in_cr7;
    undefined4 in_cr8;
    float in_s0;
    float extraout_s0;
    float fVar5;
    float fVar6;

    if (param_2 * 2 < 1) {
        fVar5 = (float)this->field_0x60;
        fVar6 = (float)this->field_0x6c;
    }
    else {
        piVar3 = param_1 + 1;
        iVar4 = 0;
        do {
            coprocessor_function(10,6,4,in_cr7,in_cr7,in_cr8);
            coprocessor_function(10,2,0,in_cr7,in_cr7,in_cr8);
            pFVar2 = this;
            ProcessSidechain(this,in_s0);
            if (this->field_0x4c != '\0') {
                fVar5 = ROUND((float)pFVar2 * 3.355443e+07 + 0.5);
                lVar1 = (longlong)piVar3[-1] * (longlong)(int)fVar5 + 0x1000000;
                piVar3[-1] = (uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7;
                lVar1 = (longlong)(int)fVar5 * (longlong)param_1[1] + 0x1000000;
                param_1[1] = (uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7;
            }
            iVar4 = iVar4 + 2;
            param_1 = param_1 + 2;
            piVar3 = piVar3 + 2;
            fVar5 = (float)this->field_0x60 +
                    ((float)this->field_0x64 - (float)this->field_0x60) * (float)this->field_0x48;
            fVar6 = (float)this->field_0x6c +
                    (float)this->field_0x48 * ((float)this->field_0x70 - (float)this->field_0x6c);
            this->field_0x60 = fVar5;
            this->field_0x6c = fVar6;
            in_s0 = extraout_s0;
        } while (iVar4 + param_2 * -2 < 0 != SBORROW4(iVar4,param_2 * 2));
    }
    this->field_0x58 = ((float)this->field_0x58 + 9.999999e-19) - 9.999999e-19;
    this->field_0x54 = ((float)this->field_0x54 + 9.999999e-19) - 9.999999e-19;
    this->field_0x5c = ((float)this->field_0x5c + 9.999999e-19) - 9.999999e-19;
    this->field_0x7c = ((float)this->field_0x7c + 9.999999e-19) - 9.999999e-19;
    this->field_0x78 = ((float)this->field_0x78 + 9.999999e-19) - 9.999999e-19;
    this->field_0x60 = (fVar5 + 9.999999e-19) - 9.999999e-19;
    this->field_0x6c = (fVar6 + 9.999999e-19) - 9.999999e-19;
    return;
}
