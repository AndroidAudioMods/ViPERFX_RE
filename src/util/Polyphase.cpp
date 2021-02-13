//
// Created by mart on 2/12/21.
//

#include "Polyphase.h"

// Polyphase::Polyphase(int)

Polyphase::Polyphase(int param_1) {
    FIR *pFVar1;
    WaveBuffer_I32 *pWVar2;
    void *pvVar3;
    int iVar4;
    int *piVar5;

    *(undefined4 *)(this + 0x18) = 0xac44;
    *(undefined4 *)this = 0;
    *(undefined4 *)(this + 4) = 0;
    *(undefined4 *)(this + 8) = 0;
    *(undefined4 *)(this + 0xc) = 0;
    *(undefined4 *)(this + 0x10) = 0;
    this[0x14] = (Polyphase)0x0;
    if (param_1 - 1U < 2) {
        pFVar1 = (FIR *)operator_new(0x60);
        FIR::FIR(pFVar1);
        *(FIR **)this = pFVar1;
        pFVar1 = (FIR *)operator_new(0x60);
        FIR::FIR(pFVar1);
        *(FIR **)(this + 4) = pFVar1;
        pWVar2 = (WaveBuffer_I32 *)operator_new(0x20);
        WaveBuffer_I32::WaveBuffer_I32(pWVar2,2,0x1000);
        *(WaveBuffer_I32 **)(this + 8) = pWVar2;
        pWVar2 = (WaveBuffer_I32 *)operator_new(0x20);
        WaveBuffer_I32::WaveBuffer_I32(pWVar2,2,0x1000);
        *(WaveBuffer_I32 **)(this + 0xc) = pWVar2;
        pvVar3 = valloc(0x1f80);
        pFVar1 = *(FIR **)this;
        *(void **)(this + 0x10) = pvVar3;
        if ((((pFVar1 != nullptr) && (*(int *)(this + 4) != 0)) && (*(int *)(this + 8) != 0)) &&
            ((*(int *)(this + 0xc) != 0 && (pvVar3 != nullptr)))) {
            if (param_1 == 2) {
                piVar5 = (int *)&DAT_000cea28;
                iVar4 = FIR::LoadCoefficients(pFVar1,(int *)&DAT_000cea28,0x3f,0x3f0);
            }
            else {
                piVar5 = (int *)&DAT_000ce92c;
                iVar4 = FIR::LoadCoefficients(pFVar1,(int *)&DAT_000ce92c,0x3f,0x3f0);
            }
            if ((iVar4 != 0) &&
                (iVar4 = FIR::LoadCoefficients(*(FIR **)(this + 4),piVar5,0x3f,0x3f0), iVar4 != 0)) {
                this[0x14] = (Polyphase)0x1;
            }
        }
    }
    return this;
}



// Polyphase::~Polyphase()

Polyphase::~Polyphase() {
    FIR *pFVar1;
    WaveBuffer_I32 *pWVar2;

    pFVar1 = *(FIR **)this;
    if (pFVar1 != nullptr) {
        FIR::~FIR(pFVar1);
        operator_delete(pFVar1);
    }
    pFVar1 = *(FIR **)(this + 4);
    if (pFVar1 != nullptr) {
        FIR::~FIR(pFVar1);
        operator_delete(pFVar1);
    }
    pWVar2 = *(WaveBuffer_I32 **)(this + 8);
    if (pWVar2 != nullptr) {
        WaveBuffer_I32::~WaveBuffer_I32(pWVar2);
        operator_delete(pWVar2);
    }
    pWVar2 = *(WaveBuffer_I32 **)(this + 0xc);
    if (pWVar2 != nullptr) {
        WaveBuffer_I32::~WaveBuffer_I32(pWVar2);
        operator_delete(pWVar2);
    }
    if (*(void **)(this + 0x10) != nullptr) {
        free(*(void **)(this + 0x10));
    }
    return this;
}



// Polyphase::GetLatency()

undefined4 Polyphase::GetLatency(void) {
    return 0x3f;
}



// Polyphase::Reset()

void Polyphase::Reset() {
    if (*(FIR **)this != nullptr) {
        FIR::Reset(*(FIR **)this);
    }
    if (*(FIR **)(this + 4) != nullptr) {
        FIR::Reset(*(FIR **)(this + 4));
    }
    if (*(WaveBuffer_I32 **)(this + 8) != nullptr) {
        WaveBuffer_I32::Reset(*(WaveBuffer_I32 **)(this + 8));
    }
    if (*(WaveBuffer_I32 **)(this + 0xc) == nullptr) {
        return;
    }
    WaveBuffer_I32::Reset(*(WaveBuffer_I32 **)(this + 0xc));
    return;
}



// Polyphase::SetSamplingRate(int)

void Polyphase::SetSamplingRate(int param_1) {
    if (*(int *)(this + 0x18) != param_1) {
        *(int *)(this + 0x18) = param_1;
    }
    return;
}



// Polyphase::Process(int*, int)

int Polyphase::Process(int *param_1,int param_2) {
    int iVar1;
    uint uVar2;

    if ((this[0x14] != (Polyphase)0x0) &&
        (iVar1 = WaveBuffer_I32::PushSamples(*(WaveBuffer_I32 **)(this + 8),param_1,param_2),
                iVar1 != 0)) {
        while (uVar2 = WaveBuffer_I32::GetBufferOffset(), 0x3ef < uVar2) {
            iVar1 = WaveBuffer_I32::PopSamples
                    (*(WaveBuffer_I32 **)(this + 8),*(int **)(this + 0x10),0x3f0,false);
            if (iVar1 == 0x3f0) {
                FIR::FilterSamplesInterleaved(*(FIR **)this,*(int **)(this + 0x10),0x3f0,2);
                FIR::FilterSamplesInterleaved
                        (*(FIR **)(this + 4),(int *)(*(int *)(this + 0x10) + 4),0x3f0,2);
                WaveBuffer_I32::PushSamples(*(WaveBuffer_I32 **)(this + 0xc),*(int **)(this + 0x10),0x3f0);
            }
        }
        uVar2 = WaveBuffer_I32::GetBufferOffset();
        if (uVar2 < (uint)param_2) {
            return 0;
        }
        WaveBuffer_I32::PopSamples(*(WaveBuffer_I32 **)(this + 0xc),param_1,param_2,true);
    }
    return param_2;
}
