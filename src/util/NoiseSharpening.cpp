//
// Created by mart on 2/13/21.
//

#include "NoiseSharpening.h"

// NoiseSharpening::Reset()

void NoiseSharpening::Reset(void) {
    IIR_1st *in_r0;
    float in_s0;
    float in_s1;
    undefined8 uVar1;

    IIR_1st::setLPF_BW(in_r0,in_s0,in_s1);
    uVar1 = IIR_1st::Mute(in_r0);
    IIR_1st::setLPF_BW(in_r0 + 1,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20));
    IIR_1st::Mute(in_r0 + 1);
    in_r0[2].field_0x0 = 0.0;
    in_r0[2].field_0x4 = 0.0;
    return;
}



// NoiseSharpening::NoiseSharpening()

NoiseSharpening::NoiseSharpening() {
    IIR_1st::IIR_1st((IIR_1st *)this);
    IIR_1st::IIR_1st((IIR_1st *)(this + 0x10));
    *(undefined4 *)(this + 0x2c) = 0xac44;
    *(undefined4 *)(this + 0x28) = 0;
    Reset();
    return this;
}



// NoiseSharpening::SetSamplingRate(int)

void NoiseSharpening::SetSamplingRate(int param_1) {
    if (*(int *)(this + 0x2c) == param_1) {
        return;
    }
    *(int *)(this + 0x2c) = param_1;
    Reset();
    return;
}



// NoiseSharpening::SetGain(float)

void NoiseSharpening::SetGain(float param_1) {
    float in_r1;

    *(float *)(this + 0x28) = ROUND(in_r1 * 3.355443e+07 + 0.5);
    return;
}



// NoiseSharpening::Process(int*, int)

void NoiseSharpening::Process(int *param_1,int param_2) {
    longlong lVar1;
    int iVar2;
    int *piVar3;
    int iVar4;
    int iVar5;
    int *piVar6;
    int *piVar7;
    bool bVar8;
    undefined8 uVar9;
    int local_28;

    if (0 < param_2) {
        iVar4 = *param_1;
        iVar2 = *(int *)(this + 0x20);
        *(int *)(this + 0x20) = iVar4;
        iVar5 = param_1[1];
        lVar1 = (longlong)(iVar4 - iVar2) * (longlong)*(int *)(this + 0x28) + 0x1000000;
        bVar8 = param_2 * 2 != 2;
        *param_1 = *param_1 + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
        iVar2 = *(int *)(this + 0x24);
        *(int *)(this + 0x24) = iVar5;
        piVar6 = (int *)(iVar5 - iVar2);
        piVar3 = (int *)param_1[1];
        lVar1 = (longlong)(int)piVar6 * (longlong)*(int *)(this + 0x28) + 0x1000000;
        if (bVar8) {
            piVar6 = param_1;
        }
        iVar2 = (int)piVar3 + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
        if (bVar8) {
            piVar3 = param_1 + param_2 * 2;
        }
        param_1[1] = iVar2;
        if (bVar8) {
            do {
                iVar2 = piVar6[2];
                iVar4 = *(int *)(this + 0x20);
                piVar7 = piVar6 + 2;
                *(int *)(this + 0x20) = iVar2;
                iVar5 = piVar6[3];
                lVar1 = (longlong)(iVar2 - iVar4) * (longlong)*(int *)(this + 0x28) + 0x1000000;
                *piVar7 = *piVar7 + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
                iVar2 = *(int *)(this + 0x24);
                *(int *)(this + 0x24) = iVar5;
                lVar1 = (longlong)(iVar5 - iVar2) * (longlong)*(int *)(this + 0x28) + 0x1000000;
                piVar6[3] = piVar6[3] + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
                piVar6 = piVar7;
            } while (piVar7 != piVar3 + -2);
        }
        iVar2 = 0;
        piVar6 = param_1 + 1;
        do {
            iVar2 = iVar2 + 2;
            lVar1 = (longlong)piVar6[-1] * (longlong)*(int *)(this + 4) + 0x1000000;
            iVar4 = *(int *)(this + 0xc) + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
            lVar1 = (longlong)iVar4 * (longlong)*(int *)this + 0x1000000;
            uVar9 = VectorShiftRight((longlong)piVar6[-1] * (longlong)*(int *)(this + 8) + 0x1000000,0x19)
                    ;
            local_28 = (int)uVar9;
            *(uint *)(this + 0xc) =
                    ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) + local_28;
            piVar6[-1] = iVar4;
            lVar1 = (longlong)param_1[1] * (longlong)*(int *)(this + 0x14) + 0x1000000;
            iVar4 = *(int *)(this + 0x1c) + ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7);
            lVar1 = (longlong)iVar4 * (longlong)*(int *)(this + 0x10) + 0x1000000;
            uVar9 = VectorShiftRight((longlong)param_1[1] * (longlong)*(int *)(this + 0x18) + 0x1000000,
                                     0x19);
            local_28 = (int)uVar9;
            *(uint *)(this + 0x1c) =
                    ((uint)lVar1 >> 0x19 | (int)((ulonglong)lVar1 >> 0x20) << 7) + local_28;
            param_1[1] = iVar4;
            param_1 = param_1 + 2;
            piVar6 = piVar6 + 2;
        } while (iVar2 + param_2 * -2 < 0 != SBORROW4(iVar2,param_2 * 2));
    }
    return;
}
