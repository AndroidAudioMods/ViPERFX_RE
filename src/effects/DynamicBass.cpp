//
// Created by mart on 2/12/21.
//

#include "DynamicBass.h"


// DynamicBass::SetSamplingRate(unsigned int)

void DynamicBass::SetSamplingRate(uint param_1) {
    undefined8 uVar1;
    float extraout_s2;

    this->field_0x10 = param_1;
    PolesFilter::SetSamplingRate(&this->field_0x24,param_1);
    uVar1 = PolesFilter::SetSamplingRate(&this->field_0x98,param_1);
    FixedBiquad::SetLowPassParameter
            (&this->field_0x10c,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20),extraout_s2);
    return;
}



// DynamicBass::SetFilterXPassFrequency(int, int)

void DynamicBass::SetFilterXPassFrequency(int param_1,int param_2) {
    undefined8 uVar1;
    float extraout_s2;

    this->field_0x0 = param_1;
    this->field_0x4 = param_2;
    PolesFilter::SetPassFilter(&this->field_0x24,param_1,param_2);
    uVar1 = PolesFilter::SetSamplingRate(&this->field_0x24,this->field_0x10);
    FixedBiquad::SetLowPassParameter
            (&this->field_0x10c,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20),extraout_s2);
    return;
}



// DynamicBass::SetFilterYPassFrequency(int, int)

void DynamicBass::SetFilterYPassFrequency(int param_1,int param_2) {
    this->field_0x8 = param_1;
    this->field_0xc = param_2;
    PolesFilter::SetPassFilter(&this->field_0x98,param_1,param_2);
    PolesFilter::SetSamplingRate(&this->field_0x98,this->field_0x10);
    return;
}



// DynamicBass::SetSideGain(float, float)

void DynamicBass::SetSideGain(int param_1,int param_2) {
    this->field_0x20 = ROUND((float)param_1 * 3.355443e+07 + 0.5);
    this->field_0x1c = ROUND((float)param_2 * 3.355443e+07 + 0.5);
    return;
}



// DynamicBass::SetBassGain(float)

void DynamicBass::SetBassGain(int param_1) {
    int iVar1;
    undefined4 in_cr6;
    undefined4 in_cr7;
    float in_s0;
    float in_s1;
    float in_s2;
    float fVar2;

    fVar2 = ROUND((float)param_1 * 3.355443e+07 + 0.5);
    coprocessor_function(10,6,1,in_cr7,in_cr6,in_cr6);
    this->field_0x18 = fVar2;
    iVar1 = (int)SUB42(ROUND(fVar2),0);
    if (iVar1 < 0x641) {
        this->field_0x14 = iVar1;
    }
    else {
        this->field_0x14 = 0x640;
    }
    FixedBiquad::SetLowPassParameter(&this->field_0x10c,in_s0,in_s1,in_s2);
    return;
}



// DynamicBass::Reset()

void DynamicBass::Reset() {
    undefined8 uVar1;
    float extraout_s2;

    PolesFilter::~ZN11PolesFilter5ResetEv(&this->field_0x24);
    uVar1 = PolesFilter::~ZN11PolesFilter5ResetEv(&this->field_0x98);
    FixedBiquad::SetLowPassParameter
            (&this->field_0x10c,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20),extraout_s2);
    return;
}



// DynamicBass::DynamicBass()

DynamicBass::DynamicBass() {
    uint uVar1;
    undefined8 uVar2;
    float extraout_s2;

    PolesFilter::PolesFilter(&this->field_0x24);
    PolesFilter::PolesFilter(&this->field_0x98);
    FixedBiquad::FixedBiquad(&this->field_0x10c);
    this->field_0x14 = 0;
    SetSamplingRate(this,0xac44);
    uVar1 = this->field_0x10;
    this->field_0xc = 0x50;
    if ((int)uVar1 < 0) {
        uVar1 = uVar1 + 3;
    }
    this->field_0x18 = 0x2000000;
    this->field_0x1c = 0x2000000;
    this->field_0x20 = 0x2000000;
    this->field_0x0 = 0x78;
    this->field_0x4 = (int)uVar1 >> 2;
    this->field_0x8 = 0x28;
    PolesFilter::SetPassFilter(&this->field_0x24,0x78,(int)uVar1 >> 2);
    uVar2 = PolesFilter::SetPassFilter(&this->field_0x98,this->field_0x8,this->field_0xc);
    FixedBiquad::SetLowPassParameter
            (&this->field_0x10c,(float)uVar2,(float)((ulonglong)uVar2 >> 0x20),extraout_s2);
    Reset(this);
    return this;
}



// DynamicBass::FilterSamples(int*, int)

void DynamicBass::FilterSamples(int *param_1,int param_2) {
    longlong lVar1;
    longlong lVar2;
    longlong lVar3;
    longlong lVar4;
    int iVar5;
    int *piVar6;
    int iVar7;
    int iVar8;
    int iVar9;
    int local_98;
    uint local_58;
    uint local_54;
    int local_50;
    int local_4c;
    int local_48;
    int local_44;
    int local_40;
    int local_3c;
    int local_38;
    int local_34;
    int local_30;
    int local_2c [2];

    if ((int)this->field_0x0 < 0x79) {
        if (0 < param_2 * 2) {
            iVar7 = 0;
            piVar6 = param_1 + 1;
            do {
                iVar9 = piVar6[-1];
                iVar7 = iVar7 + 2;
                iVar8 = param_1[1];
                iVar5 = FixedBiquad::ProcessSample(&this->field_0x10c,iVar9 + iVar8);
                piVar6[-1] = iVar9 + iVar5;
                param_1[1] = iVar8 + iVar5;
                piVar6 = piVar6 + 2;
                param_1 = param_1 + 2;
            } while (iVar7 + param_2 * -2 < 0 != SBORROW4(iVar7,param_2 * 2));
            return;
        }
    }
    else {
        if (0 < param_2 * 2) {
            local_98 = 0;
            piVar6 = param_1 + 1;
            do {
                local_98 = local_98 + 2;
                PolesFilter::DoFilterLeft(&this->field_0x24,piVar6[-1],(int *)&local_58,&local_50,&local_48)
                        ;
                PolesFilter::DoFilterRight
                        (&this->field_0x24,param_1[1],(int *)&local_54,&local_4c,&local_44);
                lVar1 = (longlong)(int)local_58 * (longlong)(int)this->field_0x18 + 0x1000000;
                lVar2 = (longlong)(int)this->field_0x18 * (longlong)(int)local_54 + 0x1000000;
                local_58 = (uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7;
                local_54 = (uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7;
                PolesFilter::DoFilterLeft(&this->field_0x98,local_58,&local_40,&local_38,&local_30);
                PolesFilter::DoFilterRight(&this->field_0x98,local_54,&local_3c,&local_34,local_2c);
                lVar1 = (longlong)local_38 * (longlong)(int)this->field_0x20 + 0x1000000;
                lVar2 = (longlong)(int)this->field_0x20 * (longlong)local_34 + 0x1000000;
                lVar3 = (longlong)local_40 * (longlong)(int)this->field_0x1c + 0x1000000;
                lVar4 = (longlong)(int)this->field_0x1c * (longlong)local_3c + 0x1000000;
                piVar6[-1] = local_50 +
                             local_30 + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) +
                             ((uint)lVar3 >> 0x19 | (int)((ulonglong)lVar3 >> 0x20) << 7) + local_48;
                param_1[1] = local_4c +
                             local_2c[0] + ((uint)lVar2 >> 0x19 | (int)((ulonglong)lVar2 >> 0x20) << 7) +
                             ((uint)lVar4 >> 0x19 | (int)((ulonglong)lVar4 >> 0x20) << 7) + local_44;
                param_1 = param_1 + 2;
                piVar6 = piVar6 + 2;
            } while (local_98 < param_2 * 2);
        }
    }
    return;
}

