//
// Created by mart on 2/12/21.
//

#include "ViPERBass.h"

// ViPERBass::~ViPERBass()

ViPERBass::~ViPERBass() {
    Polyphase *this_00;
    WaveBuffer_I32 *this_01;

    this_00 = *(Polyphase **)this;
    if (this_00 != nullptr) {
        Polyphase::~Polyphase(this_00);
        operator_delete(this_00);
    }
    if (*(void **)&this->field_0x4 != nullptr) {
        operator_delete(*(void **)&this->field_0x4);
    }
    if (*(void **)&this->field_0x8 != nullptr) {
        operator_delete(*(void **)&this->field_0x8);
    }
    this_01 = *(WaveBuffer_I32 **)&this->field_0xc;
    if (this_01 != nullptr) {
        WaveBuffer_I32::~WaveBuffer_I32(this_01);
        operator_delete(this_01);
    }
    return this;
}



// ViPERBass::Reset()

void ViPERBass::Reset(void) {
    Polyphase **in_r0;
    uint uVar1;
    Polyphase *pPVar2;
    WaveBuffer_I32 *this;
    undefined4 in_cr7;
    undefined4 in_s0;
    undefined4 in_s1;
    undefined8 uVar3;
    float in_s2;
    float extraout_s2;
    float extraout_s2_00;
    float extraout_s2_01;

    uVar3 = CONCAT44(in_s1,in_s0);
    if (*in_r0 != nullptr) {
        Polyphase::SetSamplingRate(*in_r0,(int)in_r0[6]);
        uVar3 = Polyphase::Reset(*in_r0);
        in_s2 = extraout_s2;
    }
    if ((WaveBuffer_I32 *)in_r0[3] != nullptr) {
        WaveBuffer_I32::Reset((WaveBuffer_I32 *)in_r0[3]);
        this = (WaveBuffer_I32 *)in_r0[3];
        uVar1 = Polyphase::GetLatency();
        uVar3 = WaveBuffer_I32::PushZeros(this,uVar1);
        in_s2 = extraout_s2_00;
    }
    if (in_r0[2] != nullptr) {
        FixedToFP(in_r0[10],0x20,0x20,0x19,0,0);
        coprocessor_function(10,6,1,in_cr7,in_cr7,in_cr7);
        uVar3 = Subwoofer::SetBassGain((int)in_r0[2],(float)uVar3);
        in_s2 = extraout_s2_01;
    }
    if ((FixedBiquad *)in_r0[1] != nullptr) {
        FixedBiquad::SetLowPassParameter
                ((FixedBiquad *)in_r0[1],(float)uVar3,(float)((ulonglong)uVar3 >> 0x20),in_s2);
    }
    pPVar2 = (Polyphase *)__divsi3(0x2000000,in_r0[6]);
    in_r0[7] = pPVar2;
    in_r0[8] = nullptr;
    return;
}



// ViPERBass::ViPERBass()

ViPERBass::ViPERBass() {
    Polyphase *this_00;
    FixedBiquad *this_01;
    Subwoofer *this_02;
    WaveBuffer_I32 *this_03;
    float fVar1;
    float extraout_s0;
    undefined8 uVar2;
    float extraout_s2;

    *(undefined4 *)&this->field_0x24 = 0x3c;
    *(undefined *)&this->field_0x10 = 0;
    *(undefined *)&this->field_0x11 = 0;
    *(undefined4 *)&this->field_0x14 = 0;
    *(undefined4 *)&this->field_0x20 = 0;
    *(undefined4 *)&this->field_0x28 = 0;
    *(undefined4 *)&this->field_0x18 = 0xac44;
    *(undefined4 *)&this->field_0x1c = 0x2f8;
    this_00 = (Polyphase *)operator_new(0x1c);
    Polyphase::Polyphase(this_00,2);
    *(Polyphase **)this = this_00;
    this_01 = (FixedBiquad *)operator_new(0x24);
    FixedBiquad::FixedBiquad(this_01);
    *(FixedBiquad **)&this->field_0x4 = this_01;
    this_02 = (Subwoofer *)operator_new(0xd8);
    Subwoofer::Subwoofer(this_02);
    *(Subwoofer **)&this->field_0x8 = this_02;
    this_03 = (WaveBuffer_I32 *)operator_new(0x20);
    fVar1 = (float)WaveBuffer_I32::WaveBuffer_I32(this_03,1,0x1000);
    *(WaveBuffer_I32 **)&this->field_0xc = this_03;
    if (*(FixedBiquad **)&this->field_0x4 != nullptr) {
        uVar2 = FixedBiquad::Reset(*(FixedBiquad **)&this->field_0x4);
        FixedBiquad::SetLowPassParameter
                (*(FixedBiquad **)&this->field_0x4,(float)uVar2,(float)((ulonglong)uVar2 >> 0x20),
                 extraout_s2);
        fVar1 = extraout_s0;
    }
    if (*(int *)&this->field_0x8 != 0) {
        Subwoofer::SetBassGain(*(int *)&this->field_0x8,fVar1);
    }
    if ((((*(int *)this != 0) && (*(int *)&this->field_0x4 != 0)) && (*(int *)&this->field_0x8 != 0))
        && (*(int *)&this->field_0xc != 0)) {
        *(undefined *)&this->field_0x11 = 1;
    }
    Reset();
    return this;
}



// ViPERBass::SetEnable(bool)

undefined4 ViPERBass::SetEnable(bool param_1) {
    char cVar1;

    cVar1 = *(char *)&this->field_0x10;
    if (cVar1 == '\0') {
        if (param_1 == false) {
            return 0;
        }
        Reset();
        cVar1 = *(char *)&this->field_0x10;
    }
    if (param_1 == (bool)cVar1) {
        return 0;
    }
    *(bool *)&this->field_0x10 = param_1;
    return 1;
}



// ViPERBass::SetSamplingRate(int)

void ViPERBass::SetSamplingRate(int param_1) {
    undefined4 uVar1;
    undefined4 in_cr7;
    undefined8 extraout_d0;
    undefined8 uVar2;
    undefined8 extraout_d0_00;
    float extraout_s2;
    float extraout_s2_00;
    float fVar3;

    if (*(int *)&this->field_0x18 == param_1) {
        return;
    }
    *(int *)&this->field_0x18 = param_1;
    uVar1 = __divsi3(0x2000000);
    *(undefined4 *)&this->field_0x1c = uVar1;
    fVar3 = extraout_s2;
    uVar2 = extraout_d0;
    if (*(Polyphase **)this != nullptr) {
        uVar2 = Polyphase::SetSamplingRate(*(Polyphase **)this,param_1);
        fVar3 = extraout_s2_00;
    }
    if (*(FixedBiquad **)&this->field_0x4 != nullptr) {
        FixedBiquad::SetLowPassParameter
                (*(FixedBiquad **)&this->field_0x4,(float)uVar2,(float)((ulonglong)uVar2 >> 0x20),
                 fVar3);
        uVar2 = extraout_d0_00;
    }
    if (*(int *)&this->field_0x8 == 0) {
        return;
    }
    FixedToFP(*(undefined4 *)&this->field_0x28,0x20,0x20,0x19,0,0);
    coprocessor_function(10,6,1,in_cr7,in_cr7,in_cr7);
    Subwoofer::SetBassGain(*(int *)&this->field_0x8,(float)uVar2);
    return;
}



// ViPERBass::SetProcessMode(int)

void ViPERBass::SetProcessMode(int param_1) {
    if (2 < (uint)param_1) {
        return;
    }
    if (*(int *)&this->field_0x14 == param_1) {
        return;
    }
    *(int *)&this->field_0x14 = param_1;
    Reset();
    return;
}



// ViPERBass::SetSpeaker(int)

void ViPERBass::SetSpeaker(int param_1) {
    int in_r1;
    float in_s0;
    float in_s1;
    float in_s2;

    if (*(int *)(param_1 + 0x24) == in_r1) {
        return;
    }
    *(int *)(param_1 + 0x24) = in_r1;
    if (*(FixedBiquad **)(param_1 + 4) == nullptr) {
        return;
    }
    FixedBiquad::SetLowPassParameter(*(FixedBiquad **)(param_1 + 4),in_s0,in_s1,in_s2);
    return;
}



// ViPERBass::SetBassFactor(float)

void ViPERBass::SetBassFactor(float param_1) {
    int in_r0;
    float in_r1;
    char in_NG;
    bool in_ZR;
    char in_OV;
    undefined4 in_cr6;
    undefined4 in_cr7;

    if (in_ZR || in_NG != in_OV) {
        return;
    }
    *(float *)(in_r0 + 0x28) = ROUND(in_r1 * 3.355443e+07 + 0.5);
    if (*(int *)(in_r0 + 8) == 0) {
        return;
    }
    coprocessor_function(10,2,4,in_cr7,in_cr6,in_cr7);
    coprocessor_function(10,6,1,in_cr7,in_cr7,in_cr7);
    Subwoofer::SetBassGain(*(int *)(in_r0 + 8),param_1);
    return;
}



// ViPERBass::Process(int*, int)

int ViPERBass::Process(int *param_1,int param_2) {
    longlong lVar1;
    ulonglong uVar2;
    int iVar3;
    int iVar4;
    undefined4 uVar5;
    int *piVar6;
    int *piVar7;
    int iVar8;
    uint uVar9;
    int iVar10;
    undefined4 *puVar11;
    int *piVar12;
    int *piVar13;
    undefined8 uVar14;
    int local_30;

    if ((*(char *)&this->field_0x10 != '\0') && (*(char *)&this->field_0x11 != '\0')) {
        iVar8 = *(int *)&this->field_0x20;
        if ((iVar8 != 0x2000000) && (0 < param_2 * 2)) {
            piVar6 = param_1 + 1;
            piVar7 = param_1;
            do {
                piVar12 = piVar7 + 2;
                lVar1 = (longlong)piVar6[-1] * (longlong)iVar8 + 0x1000000;
                piVar6[-1] = (uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7;
                lVar1 = (longlong)piVar7[1] * (longlong)*(int *)&this->field_0x20 + 0x1000000;
                piVar7[1] = (uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7;
                iVar8 = *(int *)&this->field_0x20 + *(int *)&this->field_0x1c;
                if (0x2000000 < iVar8) {
                    iVar8 = 0x2000000;
                }
                *(int *)&this->field_0x20 = iVar8;
                piVar6 = piVar6 + 2;
                piVar7 = piVar12;
            } while (piVar12 != param_1 + param_2 * 2);
        }
        iVar8 = *(int *)&this->field_0x14;
        if (iVar8 == 0) {
            if (0 < param_2 * 2) {
                piVar6 = param_1 + 1;
                do {
                    iVar8 = iVar8 + 2;
                    uVar2 = (longlong)(piVar6[-1] + param_1[1]) * 0x1000000 + 0x1000000;
                    uVar14 = VectorShiftRight((uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff),0x19);
                    local_30 = (int)uVar14;
                    iVar3 = FixedBiquad::ProcessSample(*(FixedBiquad **)&this->field_0x4,local_30);
                    lVar1 = (longlong)iVar3 * (longlong)*(int *)&this->field_0x28 + 0x1000000;
                    uVar9 = (uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7;
                    piVar6[-1] = piVar6[-1] + uVar9;
                    param_1[1] = param_1[1] + uVar9;
                    piVar6 = piVar6 + 2;
                    param_1 = param_1 + 2;
                } while (iVar8 + param_2 * -2 < 0 != SBORROW4(iVar8,param_2 * 2));
            }
        }
        else {
            if (iVar8 != 1) {
                Subwoofer::Process(*(Subwoofer **)&this->field_0x8,param_1,param_2);
                return param_2;
            }
            iVar8 = WaveBuffer_I32::PushSamples(*(WaveBuffer_I32 **)&this->field_0xc,param_1,param_2);
            if (iVar8 != 0) {
                iVar8 = param_2 * 2;
                iVar3 = WaveBuffer_I32::GetCurrentBufferI32Ptr(*(WaveBuffer_I32 **)&this->field_0xc);
                iVar4 = WaveBuffer_I32::GetBufferOffset();
                if (0 < iVar8) {
                    iVar10 = 0;
                    puVar11 = (undefined4 *)(iVar3 + (iVar4 - param_2) * 4 + -4);
                    piVar6 = param_1;
                    do {
                        iVar3 = *piVar6;
                        piVar7 = piVar6 + 1;
                        iVar10 = iVar10 + 2;
                        piVar6 = piVar6 + 2;
                        lVar1 = (longlong)(iVar3 + *piVar7) * 0x1000000 + 0x1000000;
                        uVar5 = FixedBiquad::ProcessSample
                                (*(FixedBiquad **)&this->field_0x4,
                                 (uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
                        puVar11 = puVar11 + 1;
                        *puVar11 = uVar5;
                    } while (iVar10 + param_2 * -2 < 0 != SBORROW4(iVar10,iVar8));
                }
                iVar3 = Polyphase::Process(*(Polyphase **)this,param_1,param_2);
                if (iVar3 == param_2) {
                    piVar6 = (int *)WaveBuffer_I32::GetCurrentBufferI32Ptr
                            (*(WaveBuffer_I32 **)&this->field_0xc);
                    if (0 < iVar8) {
                        piVar7 = param_1 + 1;
                        piVar12 = param_1;
                        do {
                            piVar13 = piVar12 + 2;
                            lVar1 = (longlong)*piVar6 * (longlong)*(int *)&this->field_0x28 + 0x1000000;
                            piVar7[-1] = piVar7[-1] + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7)
                                    ;
                            lVar1 = (longlong)*piVar6 * (longlong)*(int *)&this->field_0x28 + 0x1000000;
                            piVar12[1] = piVar12[1] + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7)
                                    ;
                            piVar6 = piVar6 + 1;
                            piVar7 = piVar7 + 2;
                            piVar12 = piVar13;
                        } while (piVar13 != param_1 + param_2 * 2);
                    }
                    WaveBuffer_I32::PopSamples(*(WaveBuffer_I32 **)&this->field_0xc,param_2,true);
                }
            }
        }
    }
    return param_2;
}
