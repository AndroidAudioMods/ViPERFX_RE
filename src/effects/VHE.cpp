//
// Created by mart on 2/12/21.
//

#include "VHE.h"

// VHE::~VHE()

VHE::~VHE() {
    WaveBuffer_R32 *pWVar1;
    VHE *this_00;

    pWVar1 = *(WaveBuffer_R32 **)&this->field_0x20;
    if (pWVar1 != nullptr) {
        WaveBuffer_R32::~WaveBuffer_R32(pWVar1);
        operator_delete(pWVar1);
    }
    pWVar1 = *(WaveBuffer_R32 **)&this->field_0x24;
    if (pWVar1 != nullptr) {
        WaveBuffer_R32::~WaveBuffer_R32(pWVar1);
        operator_delete(pWVar1);
    }
    this_00 = (VHE *)&this->field_0x20;
    do {
        this_00 = (VHE *)&this_00[-1].field_0x28;
        PConvSingle_F32::~PConvSingle_F32((PConvSingle_F32 *)this_00);
    } while (this != this_00);
    return this;
}



// VHE::GetEnabled()

undefined VHE::GetEnabled() {
    return *(undefined *)&this->field_0x2c;
}



// VHE::Reset()

void VHE::Reset() {
    float *pfVar1;
    int iVar2;
    PConvSingle_F32 *this_00;
    int iVar3;
    int iVar4;
    float *pfVar5;
    int iVar6;
    float fVar7;

    if (*(WaveBuffer_R32 **)&this->field_0x20 != nullptr) {
        WaveBuffer_R32::Reset(*(WaveBuffer_R32 **)&this->field_0x20);
    }
    if (*(WaveBuffer_R32 **)&this->field_0x24 != nullptr) {
        WaveBuffer_R32::Reset(*(WaveBuffer_R32 **)&this->field_0x24);
    }
    this_00 = (PConvSingle_F32 *)&this->field_0x10;
    PConvSingle_F32::Reset((PConvSingle_F32 *)this);
    PConvSingle_F32::UnloadKernel((PConvSingle_F32 *)this);
    PConvSingle_F32::Reset(this_00);
    fVar7 = (float)PConvSingle_F32::UnloadKernel(this_00);
    iVar6 = *(int *)&this->field_0x30;
    iVar2 = *(int *)&this->field_0x28;
    switch(iVar6) {
        case 0:
            if (iVar2 == 0xac44) {
                pfVar1 = (float *)&UNK_000ca550;
            }
            else {
                if (iVar2 != 48000) {
                    return;
                }
                pfVar1 = (float *)&UNK_000c6550;
            }
            iVar4 = 0x1000;
            iVar3 = 0x403c8a72;
            if (iVar2 != 0xac44) {
                pfVar5 = (float *)&UNK_00092560;
                goto joined_r0x00065304;
            }
            pfVar5 = (float *)&UNK_0008a560;
            goto LAB_000651f4;
        case 1:
            if (iVar2 == 0xac44) {
                iVar4 = 0x7ff;
                iVar3 = 0x3f71adfb;
                pfVar1 = (float *)&UNK_000c0554;
            }
            else {
                if (iVar2 != 48000) {
                    return;
                }
                iVar4 = 0x7ff;
                iVar3 = 0x3f71adfb;
                pfVar1 = (float *)&UNK_000ba558;
            }
            break;
        case 2:
            if (iVar2 == 0xac44) {
                iVar4 = 0x1000;
                iVar3 = 0x3fc5b4dd;
                pfVar1 = (float *)&UNK_000b2558;
            }
            else {
                if (iVar2 != 48000) {
                    return;
                }
                iVar4 = 0x1000;
                iVar3 = 0x3fc408b7;
                pfVar1 = (float *)&UNK_000aa558;
            }
            break;
        case 3:
            if (iVar2 == 0xac44) {
                iVar4 = 0x1000;
                iVar3 = 0x3fcac8ef;
                pfVar1 = (float *)&UNK_000b6558;
            }
            else {
                if (iVar2 != 48000) {
                    return;
                }
                iVar4 = 0x1000;
                iVar3 = 0x3fc8ad4f;
                pfVar1 = (float *)&UNK_000c2550;
            }
            break;
        case 4:
            if (iVar2 == 0xac44) {
                iVar4 = 0x1000;
                iVar3 = 0x3fbbbc34;
                pfVar1 = (float *)&DAT_000ae558;
            }
            else {
                if (iVar2 != 48000) {
                    return;
                }
                iVar4 = 0x1000;
                iVar3 = 0x3fbe5d74;
                pfVar1 = (float *)&UNK_000bc554;
            }
            break;
        default:
            goto switchD_00065170_caseD_5;
    }
    if (iVar6 == 1) {
        if (iVar2 == 0xac44) {
            pfVar5 = (float *)&UNK_0009a560;
        }
        else {
            pfVar5 = (float *)&UNK_000a055c;
            joined_r0x00065304:
            if (iVar2 != 48000) {
                return;
            }
        }
    }
    else {
        if (iVar6 == 2) {
            if (iVar2 != 0xac44) {
                pfVar5 = (float *)&UNK_00096560;
                goto joined_r0x00065304;
            }
            pfVar5 = (float *)&UNK_000a6558;
        }
        else {
            if (iVar6 == 3) {
                if (iVar2 != 0xac44) {
                    pfVar5 = (float *)&UNK_00086560;
                    goto joined_r0x00065304;
                }
                pfVar5 = (float *)&UNK_000a2558;
            }
            else {
                if (iVar6 != 4) {
                    return;
                }
                if (iVar2 == 0xac44) {
                    pfVar5 = (float *)&UNK_0009c55c;
                }
                else {
                    if (iVar2 != 48000) {
                        return;
                    }
                    pfVar5 = (float *)&DAT_0008e560;
                }
            }
        }
    }
    LAB_000651f4:
    if (pfVar1 != nullptr) {
        fVar7 = (float)PConvSingle_F32::LoadKernel((PConvSingle_F32 *)this,pfVar1,fVar7,iVar3,iVar4);
        PConvSingle_F32::LoadKernel(this_00,pfVar5,fVar7,iVar3,iVar4);
        *(undefined4 *)&this->field_0x34 = 0x1000;
    }
    switchD_00065170_caseD_5:
    return;
}



// VHE::VHE()

VHE::VHE() {
    WaveBuffer_R32 *pWVar1;

    PConvSingle_F32::PConvSingle_F32((PConvSingle_F32 *)this);
    PConvSingle_F32::PConvSingle_F32((PConvSingle_F32 *)&this->field_0x10);
    *(undefined *)&this->field_0x2c = 0;
    *(undefined4 *)&this->field_0x30 = 0;
    *(undefined4 *)&this->field_0x34 = 0;
    *(undefined4 *)&this->field_0x28 = 0xac44;
    pWVar1 = (WaveBuffer_R32 *)operator_new(0x20);
    WaveBuffer_R32::WaveBuffer_R32(pWVar1,2,0x1000);
    *(WaveBuffer_R32 **)&this->field_0x20 = pWVar1;
    pWVar1 = (WaveBuffer_R32 *)operator_new(0x20);
    WaveBuffer_R32::WaveBuffer_R32(pWVar1,2,0x1000);
    *(WaveBuffer_R32 **)&this->field_0x24 = pWVar1;
    Reset(this);
    return this;
}



// VHE::SetEnable(bool)

undefined4 VHE::SetEnable(bool param_1) {
    char cVar1;

    cVar1 = *(char *)&this->field_0x2c;
    if (cVar1 == '\0') {
        if (param_1 == false) {
            return 0;
        }
        Reset(this);
        cVar1 = *(char *)&this->field_0x2c;
    }
    if (param_1 == (bool)cVar1) {
        return 0;
    }
    *(bool *)&this->field_0x2c = param_1;
    return 1;
}



// VHE::SetSamplingRate(unsigned int)

void VHE::SetSamplingRate(uint param_1) {
    if (*(uint *)&this->field_0x28 == param_1) {
        return;
    }
    *(uint *)&this->field_0x28 = param_1;
    Reset(this);
    return;
}



// VHE::SetEffectLevel(int)

void VHE::SetEffectLevel(int param_1) {
    if (*(int *)&this->field_0x30 == param_1) {
        return;
    }
    if (4 < (uint)param_1) {
        return;
    }
    *(int *)&this->field_0x30 = param_1;
    Reset(this);
    return;
}



// VHE::Process(float*, float*, int)

int VHE::Process(float *param_1,float *param_2,int param_3) {
    int iVar1;
    float *pfVar2;
    uint uVar3;

    if ((((*(char *)&this->field_0x2c != '\0') && (*(int *)&this->field_0x20 != 0)) &&
         (*(int *)&this->field_0x24 != 0)) &&
        (iVar1 = PConvSingle_F32::InstanceUsable((PConvSingle_F32 *)this), iVar1 != 0)) {
        iVar1 = PConvSingle_F32::InstanceUsable((PConvSingle_F32 *)&this->field_0x10);
        if ((iVar1 != 0) &&
            (iVar1 = WaveBuffer_R32::PushSamples(*(WaveBuffer_R32 **)&this->field_0x20,param_1,param_3),
                    iVar1 != 0)) {
            while (uVar3 = WaveBuffer_R32::GetBufferOffset(), *(uint *)&this->field_0x34 <= uVar3) {
                pfVar2 = (float *)WaveBuffer_R32::GetCurrentBufferR32Ptr
                        (*(WaveBuffer_R32 **)&this->field_0x20);
                PConvSingle_F32::ConvolveInterleaved((PConvSingle_F32 *)this,pfVar2,0);
                PConvSingle_F32::ConvolveInterleaved((PConvSingle_F32 *)&this->field_0x10,pfVar2,1);
                WaveBuffer_R32::PushSamples
                        (*(WaveBuffer_R32 **)&this->field_0x24,pfVar2,*(uint *)&this->field_0x34);
                WaveBuffer_R32::PopSamples
                        (*(WaveBuffer_R32 **)&this->field_0x20,*(uint *)&this->field_0x34,true);
            }
            iVar1 = WaveBuffer_R32::PopSamples
                    (*(WaveBuffer_R32 **)&this->field_0x24,param_2,param_3,false);
            return iVar1;
        }
    }
    return param_3;
}
