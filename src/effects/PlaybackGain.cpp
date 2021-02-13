//
// Created by mart on 2/12/21.
//

#include "PlaybackGain.h"

// PlaybackGain::PlaybackGain()

PlaybackGain::PlaybackGain() {
    FixedBiquad::FixedBiquad(&this->field_0x28);
    FixedBiquad::FixedBiquad(&this->field_0x4c);
    this->field_0x8 = 0;
    this->field_0xc = 0x3cd00000;
    this->field_0x4 = 0x3ede5bd8;
    *(undefined *)&this->field_0x74 = 0;
    this->field_0x14 = 0;
    this->field_0x18 = 0x2000000;
    this->field_0x1c = 0x2000000;
    this->field_0x20 = 0x2000000;
    this->field_0x24 = 0x2000000;
    this->samplerate = 0xac44;
    this->field_0x10 = 0x40000000;
    this->field_0x0 = 0x3f000000;
    FixedBiquad::SetBandPassParameter(&this->field_0x28,0x45098000,0x472c4400,0x3ea8f5c3);
    FixedBiquad::SetBandPassParameter
    (&this->field_0x4c,0x45098000,(int)(float)(ulonglong)this->samplerate,0x3ea8f5c3);
    return this;
}



// PlaybackGain::AnalyseWave(int*, int)

void PlaybackGain::AnalyseWave(int *param_1,int param_2) {
    int *piVar1;
    longlong lVar2;
    int iVar3;
    uint uVar4;
    uint uVar5;
    uint uVar6;
    uint uVar7;
    int iVar8;
    bool bVar9;

    if (param_2 * 2 < 1) {
        uVar6 = 0;
        uVar7 = 0;
    }
    else {
        uVar4 = 0;
        uVar5 = 0;
        iVar8 = 0;
        uVar6 = 0;
        uVar7 = 0;
        do {
            iVar3 = FixedBiquad::ProcessSample(&this->field_0x28,*param_1);
            iVar8 = iVar8 + 2;
            piVar1 = param_1 + 1;
            lVar2 = (longlong)iVar3 * (longlong)iVar3 + CONCAT44(uVar7,uVar6);
            uVar6 = (uint)lVar2;
            uVar7 = (uint)((ulonglong)lVar2 >> 0x20);
            param_1 = param_1 + 2;
            iVar3 = FixedBiquad::ProcessSample(&this->field_0x4c,*piVar1);
            lVar2 = (longlong)iVar3 * (longlong)iVar3 + CONCAT44(uVar5,uVar4);
            uVar4 = (uint)lVar2;
            uVar5 = (uint)((ulonglong)lVar2 >> 0x20);
        } while (iVar8 + param_2 * -2 < 0 != SBORROW4(iVar8,param_2 * 2));
        bVar9 = uVar5 <= uVar7;
        if (uVar7 == uVar5) {
            bVar9 = uVar4 <= uVar6;
        }
        if (!bVar9) {
            uVar6 = uVar4;
            uVar7 = uVar5;
        }
    }
    __aeabi_uldivmod(uVar6,uVar7,param_2,param_2 >> 0x1f);
    return;
}



// PlaybackGain::SetRatio(float)

void PlaybackGain::SetRatio(float param_1) {
    float in_r1;

    this->field_0x10 = in_r1 + 1.0;
    this->field_0x0 = 1.0 / (in_r1 + 1.0);
    return;
}



// PlaybackGain::SetVolume(float)

void PlaybackGain::SetVolume(float param_1) {
    float in_r1;

    this->field_0x18 = ROUND(in_r1 * 3.355443e+07 + 0.5);
    return;
}



// PlaybackGain::SetMaxGainFactor(float)

void PlaybackGain::SetMaxGainFactor(float param_1) {
    float in_r1;

    this->field_0x1c = ROUND(in_r1 * 3.355443e+07 + 0.5);
    return;
}



// PlaybackGain::Reset()

void PlaybackGain::Reset() {
    FixedBiquad::SetBandPassParameter
    (&this->field_0x28,0x45098000,(int)(float)(ulonglong)this->samplerate,0x3ea8f5c3);
    FixedBiquad::SetBandPassParameter
    (&this->field_0x4c,0x45098000,(int)(float)(ulonglong)this->samplerate,0x3ea8f5c3);
    this->field_0x14 = 0;
    this->field_0x20 = 0x2000000;
    this->field_0x24 = 0x2000000;
    return;
}



// PlaybackGain::SetEnable(bool)

undefined4 PlaybackGain::SetEnable(bool param_1) {
    undefined4 uVar1;

    if ((bool)*(char *)&this->field_0x74 == param_1) {
        uVar1 = 0;
    }
    else {
        if ((*(char *)&this->field_0x74 == '\0') && (param_1 != false)) {
            Reset(this);
        }
        uVar1 = 1;
        *(bool *)&this->field_0x74 = param_1;
    }
    return uVar1;
}



// PlaybackGain::SetSamplingRate(unsigned int)

void PlaybackGain::SetSamplingRate(uint param_1) {
    if (this->samplerate == param_1) {
        return;
    }
    this->samplerate = param_1;
    Reset(this);
    return;
}



// PlaybackGain::Process(int*, int)

void PlaybackGain::Process(int *param_1,int param_2) {
    longlong lVar1;
    uint uVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    int iVar6;
    uint uVar7;
    PlaybackGain *pPVar8;
    undefined4 in_cr0;
    undefined4 in_cr1;
    undefined4 in_cr2;
    undefined4 in_cr5;
    undefined4 in_cr6;
    undefined4 in_cr7;
    float fVar9;
    float __y;
    undefined8 uVar10;
    undefined4 in_d18;
    undefined4 in_register_00000394;
    longlong lVar11;

    if (*(char *)&this->field_0x74 == '\0') {
        return;
    }
    AnalyseWave(this,param_1,param_2);
    fVar9 = (float)__floatundidf();
    coprocessor_function(0xb,6,5,in_cr0,in_cr1,in_cr0);
    fVar9 = logf(fVar9);
    coprocessor_function(10,2,0,in_cr6,in_cr7,in_cr6);
    if ((int)this->field_0x14 < 100) {
        this->field_0x14 = this->field_0x14 + 1;
    }
    coprocessor_function(10,6,5,in_cr7,in_cr5,in_cr7);
    coprocessor_function(10,2,0,in_cr7,in_cr7,in_cr7);
    powf(fVar9,__y);
    coprocessor_function(0xb,6,5,in_cr2,in_cr1,in_cr0);
    lVar11 = __fixdfdi(in_d18,in_register_00000394);
    uVar2 = this->samplerate / 0x28;
    if ((int)uVar2 < param_2) {
        uVar2 = param_2;
    }
    uVar10 = VectorShiftRight(CONCAT44(uVar2,uVar2),0x20);
    pPVar8 = this;
    do {
        uVar7 = pPVar8->field_0x20;
        lVar1 = lVar11 * (int)this->field_0x18 + 0x1000000;
        iVar3 = (int)((ulonglong)lVar1 >> 0x20);
        uVar2 = (uint)lVar1 >> 0x19 | iVar3 * 0x80;
        iVar3 = __aeabi_ldivmod(uVar2 - uVar7,
                                (iVar3 >> 0x19) - (((int)uVar7 >> 0x1f) + (uint)(uVar2 < uVar7)),
                                (int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
        if (0 < iVar3) {
            iVar3 = iVar3 >> 4;
        }
        if (param_2 != 0) {
            iVar4 = 0;
            while( true ) {
                lVar1 = (longlong)*(int *)((int)param_1 + iVar4) * (longlong)(int)uVar7 + 0x1000000;
                *(uint *)((int)param_1 + iVar4) = (uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7
                        ;
                iVar6 = this->field_0x1c;
                iVar5 = iVar3 + pPVar8->field_0x20;
                if (iVar6 < iVar5) {
                    pPVar8->field_0x20 = iVar6;
                }
                else {
                    if (-iVar6 < iVar5) {
                        pPVar8->field_0x20 = iVar5;
                    }
                    else {
                        pPVar8->field_0x20 = -iVar6;
                    }
                }
                iVar4 = iVar4 + 8;
                if (iVar4 == param_2 * 8) break;
                uVar7 = pPVar8->field_0x20;
            }
        }
        pPVar8 = (PlaybackGain *)&pPVar8->field_0x4;
        param_1 = param_1 + 1;
    } while (pPVar8 != (PlaybackGain *)&this->field_0x8);
    return;
}
