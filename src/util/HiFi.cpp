//
// Created by mart on 2/13/21.
//

#include "HiFi.h"

// HiFi::~HiFi()

HiFi::~HiFi() {
    IIR_NOrder_BW_LH *pIVar1;
    IIR_NOrder_BW_BP *pIVar2;
    WaveBuffer_I32 *pWVar3;

    pIVar1 = *(IIR_NOrder_BW_LH **)(this + 8);
    if (pIVar1 != nullptr) {
        IIR_NOrder_BW_LH::~IIR_NOrder_BW_LH(pIVar1);
        operator_delete(pIVar1);
    }
    pIVar1 = *(IIR_NOrder_BW_LH **)(this + 0xc);
    if (pIVar1 != nullptr) {
        IIR_NOrder_BW_LH::~IIR_NOrder_BW_LH(pIVar1);
        operator_delete(pIVar1);
    }
    pIVar2 = *(IIR_NOrder_BW_BP **)(this + 0x10);
    if (pIVar2 != nullptr) {
        IIR_NOrder_BW_BP::~IIR_NOrder_BW_BP(pIVar2);
        operator_delete(pIVar2);
    }
    pIVar1 = *(IIR_NOrder_BW_LH **)(this + 0x14);
    if (pIVar1 != nullptr) {
        IIR_NOrder_BW_LH::~IIR_NOrder_BW_LH(pIVar1);
        operator_delete(pIVar1);
    }
    pIVar1 = *(IIR_NOrder_BW_LH **)(this + 0x18);
    if (pIVar1 != nullptr) {
        IIR_NOrder_BW_LH::~IIR_NOrder_BW_LH(pIVar1);
        operator_delete(pIVar1);
    }
    pIVar2 = *(IIR_NOrder_BW_BP **)(this + 0x1c);
    if (pIVar2 != nullptr) {
        IIR_NOrder_BW_BP::~IIR_NOrder_BW_BP(pIVar2);
        operator_delete(pIVar2);
    }
    pWVar3 = *(WaveBuffer_I32 **)this;
    if (pWVar3 != nullptr) {
        WaveBuffer_I32::~WaveBuffer_I32(pWVar3);
        operator_delete(pWVar3);
    }
    pWVar3 = *(WaveBuffer_I32 **)(this + 4);
    if (pWVar3 != nullptr) {
        WaveBuffer_I32::~WaveBuffer_I32(pWVar3);
        operator_delete(pWVar3);
    }
    return this;
}



// HiFi::Reset()

void HiFi::Reset(void) {
    WaveBuffer_I32 **in_r0;
    undefined4 in_cr0;
    undefined4 in_cr1;
    float in_s0;
    float in_s1;
    undefined8 uVar1;
    float in_s2;
    float extraout_s2;
    float extraout_s2_00;
    float extraout_s2_01;
    float extraout_s2_02;
    float extraout_s2_03;
    WaveBuffer_I32 *pWVar2;

    uVar1 = CONCAT44(in_s1,in_s0);
    if ((IIR_NOrder_BW_LH *)in_r0[2] != nullptr) {
        IIR_NOrder_BW_LH::setLPF((IIR_NOrder_BW_LH *)in_r0[2],in_s0,in_s1);
        uVar1 = IIR_NOrder_BW_LH::Mute((IIR_NOrder_BW_LH *)in_r0[2]);
        in_s2 = extraout_s2;
    }
    if ((IIR_NOrder_BW_LH *)in_r0[3] != nullptr) {
        IIR_NOrder_BW_LH::setHPF
                ((IIR_NOrder_BW_LH *)in_r0[3],(float)uVar1,(float)((ulonglong)uVar1 >> 0x20));
        uVar1 = IIR_NOrder_BW_LH::Mute((IIR_NOrder_BW_LH *)in_r0[3]);
        in_s2 = extraout_s2_00;
    }
    if (in_r0[4] != nullptr) {
        IIR_NOrder_BW_BP::setBPF((float)uVar1,(float)((ulonglong)uVar1 >> 0x20),in_s2);
        uVar1 = IIR_NOrder_BW_BP::Mute((IIR_NOrder_BW_BP *)in_r0[4]);
        in_s2 = extraout_s2_01;
    }
    if ((IIR_NOrder_BW_LH *)in_r0[5] != nullptr) {
        IIR_NOrder_BW_LH::setLPF
                ((IIR_NOrder_BW_LH *)in_r0[5],(float)uVar1,(float)((ulonglong)uVar1 >> 0x20));
        uVar1 = IIR_NOrder_BW_LH::Mute((IIR_NOrder_BW_LH *)in_r0[5]);
        in_s2 = extraout_s2_02;
    }
    if ((IIR_NOrder_BW_LH *)in_r0[6] != nullptr) {
        IIR_NOrder_BW_LH::setHPF
                ((IIR_NOrder_BW_LH *)in_r0[6],(float)uVar1,(float)((ulonglong)uVar1 >> 0x20));
        uVar1 = IIR_NOrder_BW_LH::Mute((IIR_NOrder_BW_LH *)in_r0[6]);
        in_s2 = extraout_s2_03;
    }
    if (in_r0[7] != nullptr) {
        IIR_NOrder_BW_BP::setBPF((float)uVar1,(float)((ulonglong)uVar1 >> 0x20),in_s2);
        IIR_NOrder_BW_BP::Mute((IIR_NOrder_BW_BP *)in_r0[7]);
    }
    if (*in_r0 != nullptr) {
        pWVar2 = in_r0[9];
        coprocessor_function(0xb,6,5,in_cr0,in_cr0,in_cr1);
        WaveBuffer_I32::Reset(*in_r0);
        WaveBuffer_I32::PushZeros(*in_r0,SUB84(ROUND((double)(longlong)(int)pWVar2 / 1000000000.0),0));
    }
    if (in_r0[1] != nullptr) {
        pWVar2 = in_r0[9];
        coprocessor_function(0xb,6,5,in_cr0,in_cr0,in_cr1);
        WaveBuffer_I32::Reset(in_r0[1]);
        WaveBuffer_I32::PushZeros(in_r0[1],SUB84(ROUND((double)(longlong)(int)pWVar2 / 1000000000.0),0))
        ;
        return;
    }
    return;
}



// HiFi::HiFi()

HiFi::HiFi() {
    WaveBuffer_I32 *pWVar1;
    IIR_NOrder_BW_LH *pIVar2;
    IIR_NOrder_BW_BP *pIVar3;

    *(undefined4 *)(this + 0x20) = 0x2000000;
    *(undefined4 *)(this + 0x24) = 0xac44;
    pWVar1 = (WaveBuffer_I32 *)operator_new(0x20);
    WaveBuffer_I32::WaveBuffer_I32(pWVar1,2,0x800);
    *(WaveBuffer_I32 **)this = pWVar1;
    pWVar1 = (WaveBuffer_I32 *)operator_new(0x20);
    WaveBuffer_I32::WaveBuffer_I32(pWVar1,2,0x800);
    *(WaveBuffer_I32 **)(this + 4) = pWVar1;
    pIVar2 = (IIR_NOrder_BW_LH *)operator_new(8);
    IIR_NOrder_BW_LH::IIR_NOrder_BW_LH(pIVar2,1);
    *(IIR_NOrder_BW_LH **)(this + 8) = pIVar2;
    pIVar2 = (IIR_NOrder_BW_LH *)operator_new(8);
    IIR_NOrder_BW_LH::IIR_NOrder_BW_LH(pIVar2,3);
    *(IIR_NOrder_BW_LH **)(this + 0xc) = pIVar2;
    pIVar3 = (IIR_NOrder_BW_BP *)operator_new(0xc);
    IIR_NOrder_BW_BP::IIR_NOrder_BW_BP(pIVar3,3);
    *(IIR_NOrder_BW_BP **)(this + 0x10) = pIVar3;
    pIVar2 = (IIR_NOrder_BW_LH *)operator_new(8);
    IIR_NOrder_BW_LH::IIR_NOrder_BW_LH(pIVar2,1);
    *(IIR_NOrder_BW_LH **)(this + 0x14) = pIVar2;
    pIVar2 = (IIR_NOrder_BW_LH *)operator_new(8);
    IIR_NOrder_BW_LH::IIR_NOrder_BW_LH(pIVar2,3);
    *(IIR_NOrder_BW_LH **)(this + 0x18) = pIVar2;
    pIVar3 = (IIR_NOrder_BW_BP *)operator_new(0xc);
    IIR_NOrder_BW_BP::IIR_NOrder_BW_BP(pIVar3,3);
    *(IIR_NOrder_BW_BP **)(this + 0x1c) = pIVar3;
    Reset();
    return this;
}



// HiFi::SetSamplingRate(int)

void HiFi::SetSamplingRate(int param_1) {
    *(int *)(this + 0x24) = param_1;
    Reset();
    return;
}



// HiFi::SetClarity(float)

void HiFi::SetClarity(float param_1) {
    float in_r1;

    *(float *)(this + 0x20) = ROUND(in_r1 * 3.355443e+07 + 0.5);
    return;
}



// HiFi::Process(int*, int)

int HiFi::Process(int *param_1,int param_2) {
    longlong lVar1;
    longlong lVar2;
    longlong lVar3;
    int iVar4;
    int iVar5;
    int **ppiVar6;
    int *piVar7;
    int **ppiVar8;
    int *piVar9;
    int **ppiVar10;
    int *piVar11;
    int *piVar12;
    int *piVar13;
    int *piVar14;
    int **ppiVar15;
    int *piVar16;
    int iVar17;
    int **ppiVar18;
    int *piVar19;
    int **ppiVar20;
    int *piVar21;
    int *piVar22;
    int *piVar23;
    int *piVar24;
    int iVar25;
    int *piVar26;
    int iVar27;
    int *local_78;

    if (0 < param_2) {
        iVar4 = WaveBuffer_I32::PushZerosGetBuffer(*(WaveBuffer_I32 **)this,param_2);
        iVar5 = WaveBuffer_I32::PushZerosGetBuffer(*(WaveBuffer_I32 **)(this + 4),param_2);
        if (iVar4 == 0 || iVar5 == 0) {
            Reset();
            return param_2;
        }
        ppiVar20 = *(int ***)(this + 0x10);
        ppiVar15 = *(int ***)(this + 8);
        ppiVar18 = *(int ***)(this + 0xc);
        ppiVar6 = *(int ***)(this + 0x14);
        piVar14 = *ppiVar18;
        piVar12 = *ppiVar15;
        ppiVar8 = *(int ***)(this + 0x18);
        ppiVar10 = *(int ***)(this + 0x1c);
        piVar16 = *ppiVar20;
        piVar19 = ppiVar20[1];
        piVar7 = *ppiVar6;
        piVar9 = *ppiVar8;
        piVar11 = *ppiVar10;
        piVar13 = ppiVar10[1];
        piVar21 = param_1 + 1;
        piVar22 = (int *)(iVar5 + 4);
        local_78 = (int *)(iVar4 + 4);
        do {
            iVar4 = piVar21[-1];
            iVar5 = iVar4;
            if ((piVar12 != nullptr) && (piVar26 = ppiVar15[1], 0 < (int)piVar26)) {
                piVar24 = piVar12;
                do {
                    piVar23 = piVar24 + 4;
                    lVar1 = (longlong)iVar5 * (longlong)piVar24[1] + 0x1000000;
                    lVar2 = (longlong)iVar5 * (longlong)piVar24[2] + 0x1000000;
                    iVar5 = piVar24[3] + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
                    lVar1 = (longlong)iVar5 * (longlong)*piVar24 + 0x1000000;
                    piVar24[3] = ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) +
                                 ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
                    piVar24 = piVar23;
                } while (piVar23 != piVar12 + (int)piVar26 * 4);
                iVar4 = piVar21[-1];
            }
            iVar27 = iVar4;
            if ((piVar14 != nullptr) && (piVar26 = ppiVar18[1], 0 < (int)piVar26)) {
                piVar24 = piVar14;
                do {
                    piVar23 = piVar24 + 4;
                    lVar1 = (longlong)iVar27 * (longlong)piVar24[1] + 0x1000000;
                    lVar2 = (longlong)iVar27 * (longlong)piVar24[2] + 0x1000000;
                    iVar27 = piVar24[3] + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
                    lVar1 = (longlong)iVar27 * (longlong)*piVar24 + 0x1000000;
                    piVar24[3] = ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) +
                                 ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
                    piVar24 = piVar23;
                } while (piVar23 != piVar14 + (int)piVar26 * 4);
                iVar4 = piVar21[-1];
            }
            if ((piVar16 != nullptr) && (piVar26 = ppiVar20[2], 0 < (int)piVar26)) {
                piVar24 = piVar16;
                do {
                    piVar23 = piVar24 + 4;
                    lVar1 = (longlong)iVar4 * (longlong)piVar24[1] + 0x1000000;
                    lVar2 = (longlong)iVar4 * (longlong)piVar24[2] + 0x1000000;
                    iVar4 = piVar24[3] + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
                    lVar1 = (longlong)iVar4 * (longlong)*piVar24 + 0x1000000;
                    piVar24[3] = ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) +
                                 ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
                    piVar24 = piVar23;
                } while (piVar23 != piVar16 + (int)piVar26 * 4);
            }
            if ((piVar19 != nullptr) && (piVar26 = ppiVar20[2], 0 < (int)piVar26)) {
                piVar24 = piVar19;
                do {
                    piVar23 = piVar24 + 4;
                    lVar1 = (longlong)iVar4 * (longlong)piVar24[1] + 0x1000000;
                    lVar2 = (longlong)iVar4 * (longlong)piVar24[2] + 0x1000000;
                    iVar4 = piVar24[3] + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
                    lVar1 = (longlong)iVar4 * (longlong)*piVar24 + 0x1000000;
                    piVar24[3] = ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) +
                                 ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
                    piVar24 = piVar23;
                } while (piVar23 != piVar19 + (int)piVar26 * 4);
            }
            piVar21[-1] = iVar27;
            piVar22[-1] = iVar5;
            local_78[-1] = iVar4;
            iVar4 = *piVar21;
            iVar5 = iVar4;
            if ((piVar7 != nullptr) && (piVar26 = ppiVar6[1], 0 < (int)piVar26)) {
                piVar24 = piVar7;
                do {
                    piVar23 = piVar24 + 4;
                    lVar1 = (longlong)iVar5 * (longlong)piVar24[1] + 0x1000000;
                    lVar2 = (longlong)iVar5 * (longlong)piVar24[2] + 0x1000000;
                    iVar5 = piVar24[3] + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
                    lVar1 = (longlong)iVar5 * (longlong)*piVar24 + 0x1000000;
                    piVar24[3] = ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) +
                                 ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
                    piVar24 = piVar23;
                } while (piVar23 != piVar7 + (int)piVar26 * 4);
                iVar4 = *piVar21;
            }
            iVar27 = iVar4;
            if ((piVar9 != nullptr) && (piVar26 = ppiVar8[1], 0 < (int)piVar26)) {
                piVar24 = piVar9;
                do {
                    piVar23 = piVar24 + 4;
                    lVar1 = (longlong)iVar27 * (longlong)piVar24[1] + 0x1000000;
                    lVar2 = (longlong)iVar27 * (longlong)piVar24[2] + 0x1000000;
                    iVar27 = piVar24[3] + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
                    lVar1 = (longlong)iVar27 * (longlong)*piVar24 + 0x1000000;
                    piVar24[3] = ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) +
                                 ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
                    piVar24 = piVar23;
                } while (piVar23 != piVar9 + (int)piVar26 * 4);
                iVar4 = *piVar21;
            }
            if ((piVar11 != nullptr) && (piVar26 = ppiVar10[2], 0 < (int)piVar26)) {
                piVar24 = piVar11;
                do {
                    piVar23 = piVar24 + 4;
                    lVar1 = (longlong)iVar4 * (longlong)piVar24[1] + 0x1000000;
                    lVar2 = (longlong)iVar4 * (longlong)piVar24[2] + 0x1000000;
                    iVar4 = piVar24[3] + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
                    lVar1 = (longlong)iVar4 * (longlong)*piVar24 + 0x1000000;
                    piVar24[3] = ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) +
                                 ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
                    piVar24 = piVar23;
                } while (piVar23 != piVar11 + (int)piVar26 * 4);
            }
            if ((piVar13 != nullptr) && (piVar26 = ppiVar10[2], 0 < (int)piVar26)) {
                piVar24 = piVar13;
                do {
                    piVar23 = piVar24 + 4;
                    lVar1 = (longlong)iVar4 * (longlong)piVar24[1] + 0x1000000;
                    lVar2 = (longlong)iVar4 * (longlong)piVar24[2] + 0x1000000;
                    iVar4 = piVar24[3] + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
                    lVar1 = (longlong)iVar4 * (longlong)*piVar24 + 0x1000000;
                    piVar24[3] = ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) +
                                 ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
                    piVar24 = piVar23;
                } while (piVar23 != piVar13 + (int)piVar26 * 4);
            }
            piVar26 = piVar21 + 2;
            *piVar21 = iVar27;
            *piVar22 = iVar5;
            *local_78 = iVar4;
            piVar21 = piVar26;
            piVar22 = piVar22 + 2;
            local_78 = local_78 + 2;
        } while (piVar26 != param_1 + param_2 * 2 + 1);
        iVar17 = *(int *)(this + 0x20);
        lVar1 = (longlong)iVar17 * 0x2666666 + 0x1000000;
        iVar4 = WaveBuffer_I32::GetCurrentBufferI32Ptr(*(WaveBuffer_I32 **)this);
        iVar5 = WaveBuffer_I32::GetCurrentBufferI32Ptr(*(WaveBuffer_I32 **)(this + 4));
        iVar27 = 0;
        iVar25 = 0;
        do {
            iVar25 = iVar25 + 1;
            lVar2 = (longlong)*(int *)((int)param_1 + iVar27) *
                    (longlong)(int)((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) +
                    0x1000000;
            lVar3 = (longlong)iVar17 * (longlong)*(int *)(iVar4 + iVar27) + 0x1000000;
            *(uint *)((int)param_1 + iVar27) =
                    ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7) +
                    ((uint)lVar3 >> 0x19 | (int)((ulonglong)lVar3 >> 0x20) << 7) + *(int *)(iVar5 + iVar27);
            iVar27 = iVar27 + 4;
        } while (iVar25 < param_2 * 2);
        WaveBuffer_I32::PopSamples(*(WaveBuffer_I32 **)this,param_2,false);
        WaveBuffer_I32::PopSamples(*(WaveBuffer_I32 **)(this + 4),param_2,false);
    }
    return param_2;
}
