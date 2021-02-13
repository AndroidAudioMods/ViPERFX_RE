//
// Created by mart on 2/13/21.
//

#include "PassFilter.h"

// PassFilter::~PassFilter()

PassFilter::~PassFilter() {
    IIR_NOrder_BW_LH *pIVar1;

    pIVar1 = this->field_0x0;
    if (pIVar1 != nullptr) {
        IIR_NOrder_BW_LH::~IIR_NOrder_BW_LH(pIVar1);
        operator_delete(pIVar1);
    }
    pIVar1 = this->field_0x4;
    if (pIVar1 != nullptr) {
        IIR_NOrder_BW_LH::~IIR_NOrder_BW_LH(pIVar1);
        operator_delete(pIVar1);
    }
    pIVar1 = this->field_0x8;
    if (pIVar1 != nullptr) {
        IIR_NOrder_BW_LH::~IIR_NOrder_BW_LH(pIVar1);
        operator_delete(pIVar1);
    }
    pIVar1 = this->field_0xc;
    if (pIVar1 != nullptr) {
        IIR_NOrder_BW_LH::~IIR_NOrder_BW_LH(pIVar1);
        operator_delete(pIVar1);
    }
    return this;
}



// PassFilter::Reset()

void PassFilter::Reset(void) {
    IIR_NOrder_BW_LH **in_r0;
    float in_s0;
    float in_s1;
    undefined8 uVar1;

    uVar1 = CONCAT44(in_s1,in_s0);
    if ((*in_r0 != nullptr) && (in_r0[1] != nullptr)) {
        if ((int)in_r0[4] < 0xac44) {
            FixedToFP(&in_r0[4][-0xd].field_0x4,0x20,0x20,1,0,0);
        }
        uVar1 = IIR_NOrder_BW_LH::setLPF(*in_r0,in_s0,in_s1);
        IIR_NOrder_BW_LH::setLPF(in_r0[1],(float)uVar1,(float)((ulonglong)uVar1 >> 0x20));
        IIR_NOrder_BW_LH::Mute(*in_r0);
        uVar1 = IIR_NOrder_BW_LH::Mute(in_r0[1]);
    }
    if ((in_r0[2] != nullptr) && (in_r0[3] != nullptr)) {
        uVar1 = IIR_NOrder_BW_LH::setHPF(in_r0[2],(float)uVar1,(float)((ulonglong)uVar1 >> 0x20));
        IIR_NOrder_BW_LH::setHPF(in_r0[3],(float)uVar1,(float)((ulonglong)uVar1 >> 0x20));
        IIR_NOrder_BW_LH::Mute(in_r0[2]);
        IIR_NOrder_BW_LH::Mute(in_r0[3]);
        return;
    }
    return;
}



// PassFilter::PassFilter()

PassFilter::PassFilter() {
    IIR_NOrder_BW_LH *pIVar1;

    pIVar1 = (IIR_NOrder_BW_LH *)operator_new(8);
    IIR_NOrder_BW_LH::IIR_NOrder_BW_LH(pIVar1,3);
    this->field_0x0 = pIVar1;
    pIVar1 = (IIR_NOrder_BW_LH *)operator_new(8);
    IIR_NOrder_BW_LH::IIR_NOrder_BW_LH(pIVar1,3);
    this->field_0x4 = pIVar1;
    pIVar1 = (IIR_NOrder_BW_LH *)operator_new(8);
    IIR_NOrder_BW_LH::IIR_NOrder_BW_LH(pIVar1,1);
    this->field_0x8 = pIVar1;
    pIVar1 = (IIR_NOrder_BW_LH *)operator_new(8);
    IIR_NOrder_BW_LH::IIR_NOrder_BW_LH(pIVar1,1);
    this->field_0xc = pIVar1;
    this->samplerate = 0xac44;
    Reset();
    return this;
}



// PassFilter::SetSamplingRate(int)

void PassFilter::SetSamplingRate(int param_1) {
    if (this->samplerate == param_1) {
        return;
    }
    this->samplerate = param_1;
    Reset();
    return;
}



// PassFilter::ProcessFrames(int*, int)

void PassFilter::ProcessFrames(int *param_1,int param_2) {
    longlong lVar1;
    longlong lVar2;
    IIR_NOrder_BW_LH *pIVar3;
    IIR_NOrder_BW_LH *pIVar4;
    IIR_1st *pIVar5;
    IIR_NOrder_BW_LH *pIVar6;
    IIR_1st *pIVar7;
    int iVar8;
    IIR_NOrder_BW_LH *pIVar9;
    IIR_1st *pIVar10;
    int iVar11;
    IIR_1st *pIVar12;
    int iVar13;
    int *piVar14;
    IIR_1st *pIVar15;
    IIR_1st *pIVar16;
    int local_4c;
    int *local_48;
    int *local_44;

    if ((((0 < param_2) && (pIVar4 = this->field_0x0, pIVar4 != nullptr)) &&
         (pIVar6 = this->field_0x4, pIVar6 != nullptr)) &&
        ((pIVar9 = this->field_0x8, pIVar9 != nullptr && (pIVar3 = this->field_0xc, pIVar3 != nullptr)))) {
        pIVar12 = pIVar9->field_0x0;
        local_44 = param_1 + 2;
        pIVar5 = pIVar4->field_0x0;
        pIVar7 = pIVar3->field_0x0;
        pIVar10 = pIVar6->field_0x0;
        local_4c = param_2 + -1;
        piVar14 = local_44;
        local_48 = param_1;
        while( true ) {
            iVar8 = piVar14[-2];
            iVar13 = local_48[1];
            if ((pIVar12 != nullptr) && (iVar11 = pIVar9->field_0x4, 0 < iVar11)) {
                pIVar16 = pIVar12;
                do {
                    lVar1 = (longlong)iVar8 * (longlong)(int)pIVar16->field_0x4 + 0x1000000;
                    pIVar15 = pIVar16 + 1;
                    lVar2 = (longlong)iVar8 * (longlong)(int)pIVar16->field_0x8 + 0x1000000;
                    iVar8 = pIVar16->field_0xc + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
                    lVar1 = (longlong)iVar8 * (longlong)(int)pIVar16->field_0x0 + 0x1000000;
                    pIVar16->field_0xc =
                            ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) +
                            ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
                    pIVar16 = pIVar15;
                } while (pIVar15 != pIVar12 + iVar11);
            }
            if ((pIVar5 != nullptr) && (iVar11 = pIVar4->field_0x4, 0 < iVar11)) {
                pIVar16 = pIVar5;
                do {
                    pIVar15 = pIVar16 + 1;
                    lVar1 = (longlong)iVar8 * (longlong)(int)pIVar16->field_0x4 + 0x1000000;
                    lVar2 = (longlong)iVar8 * (longlong)(int)pIVar16->field_0x8 + 0x1000000;
                    iVar8 = pIVar16->field_0xc + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
                    lVar1 = (longlong)iVar8 * (longlong)(int)pIVar16->field_0x0 + 0x1000000;
                    pIVar16->field_0xc =
                            ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) +
                            ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
                    pIVar16 = pIVar15;
                } while (pIVar15 != pIVar5 + iVar11);
            }
            if ((pIVar7 != nullptr) && (iVar11 = pIVar3->field_0x4, 0 < iVar11)) {
                pIVar16 = pIVar7;
                do {
                    pIVar15 = pIVar16 + 1;
                    lVar1 = (longlong)iVar13 * (longlong)(int)pIVar16->field_0x4 + 0x1000000;
                    lVar2 = (longlong)iVar13 * (longlong)(int)pIVar16->field_0x8 + 0x1000000;
                    iVar13 = pIVar16->field_0xc + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7)
                            ;
                    lVar1 = (longlong)iVar13 * (longlong)(int)pIVar16->field_0x0 + 0x1000000;
                    pIVar16->field_0xc =
                            ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) +
                            ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
                    pIVar16 = pIVar15;
                } while (pIVar15 != pIVar7 + iVar11);
            }
            if ((pIVar10 != nullptr) && (iVar11 = pIVar6->field_0x4, 0 < iVar11)) {
                pIVar16 = pIVar10;
                do {
                    pIVar15 = pIVar16 + 1;
                    lVar1 = (longlong)iVar13 * (longlong)(int)pIVar16->field_0x4 + 0x1000000;
                    lVar2 = (longlong)iVar13 * (longlong)(int)pIVar16->field_0x8 + 0x1000000;
                    iVar13 = pIVar16->field_0xc + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7)
                            ;
                    lVar1 = (longlong)iVar13 * (longlong)(int)pIVar16->field_0x0 + 0x1000000;
                    pIVar16->field_0xc =
                            ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) +
                            ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7);
                    pIVar16 = pIVar15;
                } while (pIVar15 != pIVar10 + iVar11);
            }
            local_4c = local_4c + -1;
            piVar14[-2] = iVar8;
            local_48[1] = iVar13;
            local_48 = local_44;
            if (local_4c == -1) break;
            local_44 = local_44 + 2;
            piVar14 = piVar14 + 2;
        }
    }
    return;
}
