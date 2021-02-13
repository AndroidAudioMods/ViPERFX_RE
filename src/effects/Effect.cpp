//
// Created by mart on 2/12/21.
//

#include <cstring>
#include <malloc.h>
#include "../libv4a_fx.so.h"
#include "Effect.h"


// Effect::Effect()

Effect::Effect() {
    *(undefined *)&this->field_0x4 = 0;
    *(undefined *)&this->field_0x5 = 1;
    this->samplerate = 0xac44;
    memset(&this->field_0xc,0,0x40);
    *(undefined *)&this->field_0x29 = 1;
    this->field_0x28 = '\x01';
    this->field_0x14 = 0xac44;
    *(undefined *)&this->field_0x49 = 0;
    this->field_0x48 = '\x01';
    this->samplerate = 0xac44;
    this->field_0x60 = nullptr;
    this->field_0x64 = nullptr;
    this->field_0x68 = nullptr;
    this->field_0x18 = (int *)0x3;
    this->field_0x38 = 3;
    this->field_0x2a = 0x3f;
    this->field_0x4a = 0x3f;
}



// Effect::~Effect()

Effect::~Effect() {
    if (this->field_0x60 != nullptr) {
        free(this->field_0x60);
    }
    this->field_0x60 = nullptr;
    this->field_0x64 = nullptr;
    this->field_0x68 = nullptr;
}



// Effect::configure(void*)

int Effect::configure(effect_config_t *param_1) {
    int *piVar1;
    int *piVar2;
    int *piVar3;
    int *piVar4;
    int *piVar5;
    int *piVar6;
    int *piVar7;
    int *piVar8;
    int *piVar9;
    void *pvVar10;
    int *piVar11;
    void *pvVar12;
    int *piVar13;
    uint uVar14;
    int *piVar15;
    uint uVar16;
    undefined local_4b;
    undefined local_2b;

    piVar1 = (int *)(param_1->inputCfg).buffer.frameCount;
    piVar5 = (int *)(param_1->inputCfg).buffer.buffer;
    piVar9 = (int *)(param_1->inputCfg).samplingRate;
    piVar13 = (int *)(param_1->inputCfg).channels;
    piVar2 = (int *)(param_1->inputCfg).bufferProvider.getBuffer;
    piVar6 = (int *)(param_1->inputCfg).bufferProvider.releaseBuffer;
    pvVar10 = (param_1->inputCfg).bufferProvider.cookie;
    uVar14 = *(uint *)&(param_1->inputCfg).format;
    piVar3 = (int *)(param_1->outputCfg).buffer.frameCount;
    piVar7 = (int *)(param_1->outputCfg).buffer.buffer;
    piVar11 = (int *)(param_1->outputCfg).samplingRate;
    piVar15 = (int *)(param_1->outputCfg).channels;
    piVar4 = (int *)(param_1->outputCfg).bufferProvider.getBuffer;
    piVar8 = (int *)(param_1->outputCfg).bufferProvider.releaseBuffer;
    pvVar12 = (param_1->outputCfg).bufferProvider.cookie;
    uVar16 = *(uint *)&(param_1->outputCfg).format;
    __android_log_print(4,"ViPER4Android_v2","Begin audio configure ...");
    __android_log_print(4,"ViPER4Android_v2","Checking input and output configuration ...");
    if (((uVar14 & 0x20000) != 0) && ((uVar16 & 0x20000) != 0)) {
        if (piVar11 != piVar9) {
            __android_log_print(4,"ViPER4Android_v2",
                                "ViPER4Android disabled, reason [in.SR = %d, out.SR = %d]",piVar9,piVar11)
                    ;
            *(undefined *)&this->field_0x5 = 0;
            return EINVAL;
        }
        if ((int *)0xf3c < piVar11 + -0x2b11) {
            __android_log_print(4,"ViPER4Android_v2","ViPER4Android disabled, reason [SR out of range]");
            *(undefined *)&this->field_0x5 = 0;
            return EINVAL;
        }
        this->samplerate = piVar11;
    }
    if (((uVar14 & 0x40000) != 0) && ((uVar16 & 0x40000) != 0)) {
        if (piVar13 != piVar15) {
            __android_log_print(4,"ViPER4Android_v2",
                                "ViPER4Android disabled, reason [in.CH = %d, out.CH = %d]",piVar13,piVar15
            );
            *(undefined *)&this->field_0x5 = 0;
            return EINVAL;
        }
        if (piVar13 != (int *)0x3) {
            __android_log_print(4,"ViPER4Android_v2","ViPER4Android disabled, reason [CH != 2]");
            *(undefined *)&this->field_0x5 = 0;
            return EINVAL;
        }
    }
    if (((uVar14 & 0x80000) != 0) && ((uVar16 & 0x80000) != 0)) {
        if ((uVar14 & 0xfd) != 1) {
            __android_log_print(4,"ViPER4Android_v2","ViPER4Android disabled, reason [in.FMT = %d]");
            __android_log_print(4,"ViPER4Android_v2","We only accept s16 and fixed.31 format");
            *(undefined *)&this->field_0x5 = 0;
            return EINVAL;
        }
        if ((uVar16 & 0xfd) != 1) {
            __android_log_print(4,"ViPER4Android_v2","ViPER4Android disabled, reason [out.FMT = %d]");
            __android_log_print(4,"ViPER4Android_v2","We only accept s16 and fixed.31 format");
            *(undefined *)&this->field_0x5 = 0;
            return EINVAL;
        }
    }
    __android_log_print(4,"ViPER4Android_v2","Input and output configuration checked.");
    if ((uVar14 & 0x10000) != 0) {
        this->field_0xc = piVar1;
        this->field_0x10 = piVar5;
    }
    if ((uVar14 & 0x200000) != 0) {
        this->field_0x1c = piVar2;
        this->field_0x20 = piVar6;
        this->field_0x24 = pvVar10;
    }
    if ((uVar14 & 0x20000) != 0) {
        this->field_0x14 = piVar9;
    }
    if ((uVar14 & 0x40000) != 0) {
        this->field_0x18 = piVar13;
    }
    if ((uVar14 & 0x80000) != 0) {
        this->field_0x28 = (char)uVar14;
    }
    if ((uVar14 & 0x100000) != 0) {
        local_4b = (undefined)(uVar14 >> 8);
        *(undefined *)&this->field_0x29 = local_4b;
    }
    if ((uVar16 & 0x10000) != 0) {
        this->field_0x2c = piVar3;
        this->field_0x30 = piVar7;
    }
    if ((uVar16 & 0x200000) != 0) {
        this->field_0x3c = piVar4;
        this->field_0x40 = piVar8;
        this->field_0x44 = pvVar12;
    }
    if ((uVar16 & 0x20000) != 0) {
        this->samplerate = piVar11;
    }
    if ((uVar16 & 0x40000) != 0) {
        this->field_0x38 = piVar15;
    }
    if ((uVar16 & 0x80000) != 0) {
        this->field_0x48 = (char)uVar16;
    }
    if ((uVar16 & 0x100000) != 0) {
        local_2b = (undefined)(uVar16 >> 8);
        *(undefined *)&this->field_0x49 = local_2b;
    }
    __android_log_print(4,"ViPER4Android_v2","Audio configure finished");
    *(undefined *)&this->field_0x5 = 1;
    return OK;
}



// Effect::command(unsigned int, unsigned int, void*, unsigned int*, void*)

int Effect::command(uint param_1,uint param_2,void *param_3,uint *param_4,void *param_5) {
    int *piVar1;
    int **ppiVar2;
    int **ppiVar3;
    char *pcVar4;
    int *piVar5;
    int *piVar6;

    switch(param_1) {
        case 0:
            *(undefined4 *)param_5 = 0;
            return OK;
        case 1:
            goto LAB_0006f49c;
        case 2:
            break;
        case 3:
            *(undefined *)&this->field_0x4 = 1;
            *(undefined4 *)param_5 = 0;
            return OK;
        case 4:
            *(undefined *)&this->field_0x4 = 0;
            *(undefined4 *)param_5 = 0;
            return OK;
        case 5:
        LAB_0006f49c:
            *(undefined4 *)param_5 = 0;
            return OK;
        case 6:
            break;
        case 7:
            *(undefined4 *)param_5 = 0;
            return OK;
        case 8:
            *(undefined4 *)param_5 = 0xffffffea;
            *(undefined4 *)((int)param_5 + 8) = 0;
            *param_4 = 0xc;
            return OK;
        case 9:
            break;
        case 10:
            break;
        case 0xb:
            break;
        case 0xc:
            *(undefined4 *)param_5 = 0xffffffea;
            return EINVAL;
        case 0xd:
            break;
        case 0xe:
            if (param_5 == nullptr) {
                return EINVAL;
            }
            if (*param_4 != 0x40) {
                return EINVAL;
            }
            ppiVar2 = &this->field_0xc;
            do {
                ppiVar3 = ppiVar2 + 4;
                piVar5 = ppiVar2[1];
                piVar6 = ppiVar2[2];
                piVar1 = ppiVar2[3];
                *(int **)param_5 = *ppiVar2;
                *(int **)((int)param_5 + 4) = piVar5;
                *(int **)((int)param_5 + 8) = piVar6;
                *(int **)((int)param_5 + 0xc) = piVar1;
                param_5 = (int **)((int)param_5 + 0x10);
                ppiVar2 = ppiVar3;
            } while (ppiVar3 != (int **)&this->field_0x4c);
            break;
        case 0xf:
            return EINVAL;
        case 0x10:
            return EINVAL;
        case 0x11:
            return EINVAL;
        case 0x12:
            return EINVAL;
        case 0x13:
            break;
        case 0x14:
            if ((param_3 == nullptr) && (param_2 == 8)) {
                if (cRam00000000 == '\0') {
                    pcVar4 = "false";
                }
                else {
                    pcVar4 = "true";
                }
                __android_log_print(4,"ViPER4Android_v2","Effect offload status = %s",pcVar4,0);
                return EINVAL;
            }
        default:
            return EINVAL;
    }
    return OK;
}



// Effect::process(audio_buffer_s*, audio_buffer_s*)

int Effect::process(audio_buffer_s *param_1,audio_buffer_s *param_2) {
    char cVar1;
    char cVar2;
    int *piVar3;
    void *pvVar4;
    int EVar5;
    short *psVar6;
    int *piVar7;
    short *psVar8;
    short *psVar9;
    int *piVar10;
    int *piVar11;
    int *piVar12;
    int *piVar13;
    int *piVar14;
    int *piVar15;
    undefined4 uVar16;
    undefined4 uVar17;
    ProcessUnit_FX *pPVar18;
    int *piVar19;
    uint uVar20;
    int *local_38;
    int *local_34;
    int *local_30;
    int *local_2c;

    if (*(char *)&this->field_0x5 == '\0') {
        return EINVAL;
    }
    uVar16 = this->field_0x24;
    piVar12 = this->field_0x20;
    uVar17 = this->field_0x44;
    local_38 = nullptr;
    local_34 = nullptr;
    piVar15 = this->field_0x2c;
    piVar14 = this->field_0x30;
    piVar10 = this->field_0x1c;
    piVar19 = this->field_0x3c;
    piVar13 = this->field_0x40;
    cVar1 = this->field_0x28;
    cVar2 = this->field_0x48;
    if (param_1 == nullptr) {
        piVar11 = (int *)param_1;
        piVar7 = this->field_0xc;
        piVar3 = this->field_0x10;
        if ((((this->field_0x10 == nullptr) &&
              (piVar11 = piVar10, piVar7 = local_38, piVar3 = local_34, piVar10 != nullptr)) &&
             (piVar11 = piVar12, piVar12 != nullptr)) &&
            ((*(code *)piVar10)(uVar16,&local_38), piVar11 = local_34, piVar7 = local_38,
                                                   piVar3 = local_34, local_34 != nullptr)) {
            piVar11 = (int *)0x1;
        }
    }
    else {
        piVar11 = nullptr;
        piVar7 = *(int **)param_1;
        piVar3 = *(int **)(param_1 + 4);
    }
    local_34 = piVar3;
    local_38 = piVar7;
    local_30 = nullptr;
    local_2c = nullptr;
    if (param_2 == nullptr) {
        piVar10 = (int *)param_2;
        piVar7 = piVar15;
        if (((piVar14 == nullptr) &&
             (piVar10 = piVar19, piVar15 = piVar19, piVar7 = local_30, piVar14 = local_2c,
                     piVar19 != nullptr)) &&
            ((piVar10 = piVar13, piVar15 = piVar13, piVar13 != nullptr &&
                                                    ((*(code *)piVar19)(uVar17,&local_30), piVar10 = local_2c, piVar15 = local_30,
                                                                                           piVar7 = local_30, piVar14 = local_2c, local_2c != nullptr)))) {
            piVar10 = (int *)0x1;
        }
    }
    else {
        piVar10 = nullptr;
        piVar15 = *(int **)param_2;
        piVar7 = *(int **)param_2;
        piVar14 = *(int **)(param_2 + 4);
    }
    local_2c = piVar14;
    local_30 = piVar7;
    piVar14 = local_38;
    if (local_38 != piVar15) {
        LAB_0006f694:
        if (piVar11 != nullptr) {
            (*(code *)piVar12)(uVar16,&local_38);
        }
        LAB_0006f69c:
        if (piVar10 != nullptr) {
            (*(code *)piVar13)(uVar17,&local_30);
        }
        return EINVAL;
    }
    if (piVar15 == nullptr) {
        joined_r0x0006f6bc:
        if (piVar11 != nullptr) {
            (*(code *)piVar12)(uVar16,&local_38);
        }
        LAB_0006f6c0:
        if (piVar10 != nullptr) {
            (*(code *)piVar13)(uVar17,&local_30);
        }
        return OK;
    }
    if ((local_34 == nullptr) || (local_2c == nullptr)) goto LAB_0006f694;
    if (cVar2 == '\x01' && cVar1 == '\x01') {
        if (local_34 != local_2c) {
            memcpy(local_2c,local_34,(int)piVar15 << 2);
        }
        if (this->field_0x68 != nullptr) {
            EVar5 = ProcessUnit_FX::processBuffer(this->field_0x68,(short *)local_2c,(int)piVar15);
            goto LAB_0006f868;
        }
    }
    else {
        uVar20 = (uint)(cVar2 == '\x03' && cVar1 == '\x03');
        if (uVar20 == 0) {
            if (cVar2 != '\x03' || cVar1 != '\x01') {
                if (cVar1 != '\x03' || cVar2 != '\x01') {
                    if (piVar11 != nullptr) {
                        (*(code *)piVar12)(uVar16,&local_38);
                    }
                    goto LAB_0006f69c;
                }
                if ((local_34 != local_2c) && (0 < (int)piVar15 * 2)) {
                    piVar19 = local_34 + -1;
                    piVar14 = local_2c;
                    do {
                        piVar19 = piVar19 + 1;
                        piVar7 = (int *)((int)piVar14 + 2);
                        *(short *)piVar14 = (short)((uint)*piVar19 >> 0x10);
                        piVar14 = piVar7;
                    } while (piVar7 != local_2c + (int)piVar15);
                }
                if (this->field_0x68 != nullptr) {
                    EVar5 = ProcessUnit_FX::processBuffer(this->field_0x68,(short *)local_2c,(int)piVar15);
                    goto LAB_0006f868;
                }
                goto LAB_0006f9a8;
            }
            if ((local_34 != local_2c) && (0 < (int)piVar15 * 2)) {
                do {
                    *(int *)((int)local_2c + uVar20 * 2) = (int)*(short *)((int)local_34 + uVar20) << 0x10;
                    uVar20 = uVar20 + 2;
                } while (uVar20 != (int)piVar15 * 4);
            }
            if ((int)this->field_0x64 < (int)piVar15) {
                if (this->field_0x60 != nullptr) {
                    free(this->field_0x60);
                }
                this->field_0x60 = nullptr;
                LAB_0006f93c:
                pvVar4 = valloc((int)piVar14 << 2);
                this->field_0x60 = pvVar4;
                this->field_0x64 = piVar15;
                if (pvVar4 == nullptr) {
                    this->field_0x64 = nullptr;
                    if (piVar11 != nullptr) {
                        (*(code *)piVar12)(uVar16,&local_38);
                    }
                    goto LAB_0006f6c0;
                }
            }
            else {
                if (this->field_0x60 == nullptr) goto LAB_0006f93c;
            }
            pPVar18 = this->field_0x68;
            if (pPVar18 != nullptr) {
                memcpy(this->field_0x60,local_34,(int)piVar14 << 2);
                EVar5 = ProcessUnit_FX::processBuffer(pPVar18,(short *)this->field_0x60,(int)piVar15);
                psVar6 = (short *)this->field_0x60;
                piVar14 = local_2c;
                psVar9 = psVar6;
                do {
                    psVar8 = psVar9 + 1;
                    *piVar14 = (int)*psVar9 << 0x10;
                    piVar14 = piVar14 + 1;
                    psVar9 = psVar8;
                } while (psVar8 != psVar6 + (int)piVar15 * 2);
                goto LAB_0006f868;
            }
        }
        else {
            if (local_34 != local_2c) {
                memcpy(local_2c,local_34,(int)piVar15 << 3);
            }
            if ((int)this->field_0x64 < (int)piVar15) {
                if (this->field_0x60 != nullptr) {
                    free(this->field_0x60);
                }
                this->field_0x60 = nullptr;
                LAB_0006f788:
                pvVar4 = valloc((int)piVar14 << 2);
                this->field_0x60 = pvVar4;
                this->field_0x64 = piVar15;
                if (pvVar4 == nullptr) {
                    this->field_0x64 = nullptr;
                    goto joined_r0x0006f6bc;
                }
            }
            else {
                if (this->field_0x60 == nullptr) goto LAB_0006f788;
            }
            pPVar18 = this->field_0x68;
            if (pPVar18 != nullptr) {
                psVar6 = (short *)this->field_0x60;
                piVar14 = local_2c;
                psVar9 = psVar6;
                do {
                    psVar8 = psVar9 + 1;
                    *psVar9 = (short)((uint)*piVar14 >> 0x10);
                    piVar14 = piVar14 + 1;
                    psVar9 = psVar8;
                } while (psVar8 != psVar6 + (int)piVar15 * 2);
                EVar5 = ProcessUnit_FX::processBuffer(pPVar18,psVar6,(int)piVar15);
                psVar6 = (short *)this->field_0x60;
                piVar14 = local_2c;
                psVar9 = psVar6;
                do {
                    psVar8 = psVar9 + 1;
                    *piVar14 = (int)*psVar9 << 0x10;
                    piVar14 = piVar14 + 1;
                    psVar9 = psVar8;
                } while (psVar8 != psVar6 + (int)piVar15 * 2);
                goto LAB_0006f868;
            }
        }
    }
    LAB_0006f9a8:
    EVar5 = OK;
    LAB_0006f868:
    if (piVar11 != nullptr) {
        (*(code *)piVar12)(uVar16,&local_38);
    }
    if (piVar10 != nullptr) {
        (*(code *)piVar13)(uVar17,&local_30);
        return EVar5;
    }
    return EVar5;
}

