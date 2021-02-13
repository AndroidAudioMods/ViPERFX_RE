//
// Created by mart on 2/12/21.
//

#include "MultiBiquad.h"


// MultiBiquad::MultiBiquad()

MultiBiquad::MultiBiquad() {
    this->field_0x0 = 0;
    this->field_0x4 = 0;
    this->field_0x8 = 0;
    this->field_0xc = 0;
    this->field_0x10 = 0;
    this->field_0x18 = 0;
    this->field_0x14 = 0;
    this->field_0x20 = 0;
    this->field_0x1c = 0;
    return;
}



// MultiBiquad::RefreshFilter(MultiBiquad::FilterType( float, float, float, float, bool)

void MultiBiquad::RefreshFilter(dword param_1,float param_2,float param_3,float param_4,
                                float param_5,bool param_6) {
    undefined4 uVar1;
    undefined4 uVar2;
    undefined4 extraout_r1;
    undefined4 extraout_r1_00;
    undefined4 extraout_r1_01;
    undefined4 extraout_r1_02;
    undefined4 extraout_r1_03;
    undefined uVar3;
    undefined4 in_cr0;
    undefined4 in_cr1;
    undefined4 in_cr2;
    undefined4 in_cr3;
    undefined4 in_cr4;
    undefined4 in_cr9;
    undefined4 in_cr10;
    undefined4 in_cr11;
    undefined4 in_cr12;
    undefined4 in_cr13;
    undefined4 in_cr14;
    undefined4 in_cr15;
    double unaff_d8;
    double dVar4;
    double dVar5;
    double unaff_d12;
    double dVar6;
    double unaff_d14;
    double unaff_d15;
    double dVar7;
    double in_d18;
    double in_d19;
    float in_stack_00000000;
    float in_stack_00000004;
    char in_stack_00000008;
    double in_stack_ffffffa0;
    double in_stack_ffffffa8;

    if (param_1 - 5 < 3) {
        uVar1 = 0;
        in_d18 = (double)(float)(uint)param_6 / 40.0;
        pow(in_stack_ffffffa0,in_stack_ffffffa8);
        dVar4 = (double)CONCAT44(extraout_r1,uVar1);
    }
    else {
        uVar1 = 0;
        in_d19 = (double)(float)(uint)param_6 / 20.0;
        pow(in_stack_ffffffa0,in_stack_ffffffa8);
        dVar4 = (double)CONCAT44(extraout_r1_02,uVar1);
    }
    coprocessor_function(0xb,6,5,in_cr0,in_cr1,in_cr0);
    uVar2 = SUB84(6.283185307179586 / (double)in_stack_00000000,0);
    uVar1 = uVar2;
    sin(in_stack_ffffffa0);
    dVar6 = (double)CONCAT44(extraout_r1_00,uVar1);
    cos(in_stack_ffffffa0);
    dVar5 = (double)CONCAT44(extraout_r1_01,uVar2);
    uVar3 = param_1 - 6 == 1;
    if (param_1 - 6 < 2) {
        in_d19 = 1.0 / (double)in_stack_00000004;
        if (!(bool)uVar3) {
            sqrt(in_stack_ffffffa0);
        }
        dVar7 = SQRT(dVar4);
        in_d18 = 0.5;
        coprocessor_function(0xb,2,1,in_cr13,in_cr13,in_cr2);
        coprocessor_function(0xb,2,1,in_cr13,in_cr13,in_cr1);
        if (!(bool)uVar3) {
            uVar1 = SUB84(dVar4,0);
            sqrt(in_stack_ffffffa0);
            dVar7 = (double)CONCAT44(extraout_r1_03,uVar1);
        }
        dVar7 = dVar7 + dVar7;
        coprocessor_function(0xb,6,4,in_cr0,in_cr0,in_cr13);
    }
    else {
        if (in_stack_00000008 == '\0') {
            dVar7 = -1.0;
            dVar6 = dVar6 / ((double)in_stack_00000004 + (double)in_stack_00000004);
        }
        else {
            coprocessor_function(0xb,6,5,in_cr0,in_cr1,in_cr0);
            coprocessor_function(0xb,2,4,in_cr9,in_cr0,in_cr9);
            sinh(in_stack_ffffffa0);
            dVar7 = -1.0;
            coprocessor_function(0xb,2,4,in_cr13,in_cr1,in_cr13);
        }
    }
    switch(param_1) {
        case 0:
            unaff_d12 = 1.0 - dVar5;
            coprocessor_function(0xb,2,0,in_cr14,in_cr12,in_cr14);
            goto LAB_00066c34;
        case 1:
            coprocessor_function(0xb,2,0,in_cr14,in_cr12,in_cr14);
            unaff_d12 = 0.0 - (dVar5 + 1.0);
        LAB_00066c34:
            unaff_d8 = dVar6 + 1.0;
            unaff_d14 = 0.5;
            coprocessor_function(0xb,6,1,in_cr3,in_cr11,in_cr1);
            in_stack_ffffffa8 = 1.0 - dVar6;
            unaff_d15 = 0.5;
            in_stack_ffffffa0 = in_d19;
            break;
        case 2:
            coprocessor_function(0xb,6,1,in_cr2,in_cr11,in_cr1);
            in_stack_ffffffa8 = 1.0 - dVar6;
            unaff_d8 = dVar6 + 1.0;
            unaff_d15 = 0.0 - dVar6;
            unaff_d12 = 0.0;
            unaff_d14 = dVar6;
            in_stack_ffffffa0 = in_d18;
            break;
        case 3:
            unaff_d12 = -2.0;
            unaff_d15 = 1.0;
            coprocessor_function(0xb,2,0,in_cr12,in_cr11,in_cr12);
            in_stack_ffffffa8 = 1.0 - dVar6;
            unaff_d8 = dVar6 + 1.0;
            unaff_d14 = unaff_d15;
            in_stack_ffffffa0 = -2.0;
            break;
        case 4:
            unaff_d12 = -2.0;
            coprocessor_function(0xb,2,0,in_cr12,in_cr11,in_cr12);
            in_stack_ffffffa8 = 1.0 - dVar6;
            unaff_d8 = dVar6 + 1.0;
            unaff_d14 = in_stack_ffffffa8;
            unaff_d15 = unaff_d8;
            in_stack_ffffffa0 = -2.0;
            break;
        case 5:
            unaff_d12 = -2.0;
            coprocessor_function(0xb,2,0,in_cr13,in_cr13,in_cr10);
            coprocessor_function(0xb,2,0,in_cr12,in_cr11,in_cr12);
            in_stack_ffffffa8 = 1.0 - dVar6 / dVar4;
            unaff_d8 = dVar6 / dVar4 + 1.0;
            unaff_d14 = dVar6 + 1.0;
            unaff_d15 = 1.0 - dVar6;
            in_stack_ffffffa0 = -2.0;
            break;
        case 6:
            unaff_d12 = dVar4 + dVar4;
            coprocessor_function(0xb,6,4,in_cr3,in_cr1,in_cr11);
            coprocessor_function(0xb,2,1,in_cr11,in_cr11,in_cr2);
            dVar5 = (dVar4 + 1.0) - in_d19;
            in_d19 = dVar4 + 1.0 + in_d19;
            unaff_d8 = in_d19 + dVar7;
            coprocessor_function(0xb,2,1,in_cr12,in_cr12,in_cr3);
            in_stack_ffffffa8 = in_d19 - dVar7;
            coprocessor_function(0xb,6,1,in_cr0,in_cr11,in_cr4);
            coprocessor_function(0xb,2,0,in_cr14,in_cr14,in_cr10);
            coprocessor_function(0xb,2,0,in_cr15,in_cr15,in_cr10);
            unaff_d14 = dVar5 + dVar7;
            unaff_d15 = dVar5 - dVar7;
            in_stack_ffffffa0 = dVar7;
            break;
        case 7:
            unaff_d12 = -2.0;
            coprocessor_function(0xb,6,4,in_cr3,in_cr1,in_cr11);
            coprocessor_function(0xb,2,1,in_cr11,in_cr11,in_cr2);
            coprocessor_function(0xb,2,0,in_cr12,in_cr10,in_cr12);
            dVar6 = dVar4 + 1.0 + in_d19;
            in_d19 = (dVar4 + 1.0) - in_d19;
            dVar5 = (dVar4 - 1.0) - dVar5;
            unaff_d8 = in_d19 + dVar7;
            coprocessor_function(0xb,2,1,in_cr12,in_cr12,in_cr3);
            in_stack_ffffffa8 = in_d19 - dVar7;
            coprocessor_function(0xb,2,0,in_cr14,in_cr14,in_cr10);
            coprocessor_function(0xb,2,0,in_cr15,in_cr15,in_cr10);
            unaff_d14 = dVar6 + dVar7;
            unaff_d15 = dVar6 - dVar7;
            in_stack_ffffffa0 = dVar5 + dVar5;
    }
    this->field_0x14 = 0;
    this->field_0x18 = 0;
    this->field_0x1c = 0;
    this->field_0x20 = 0;
    this->field_0x8 = SUB84(ROUND(((0.0 - in_stack_ffffffa0) / unaff_d8) * 33554432.0 + 0.5),0);
    this->field_0xc = SUB84(ROUND(((0.0 - in_stack_ffffffa8) / unaff_d8) * 33554432.0 + 0.5),0);
    this->field_0x10 = SUB84(ROUND((unaff_d14 / unaff_d8) * 33554432.0 + 0.5),0);
    this->field_0x0 = SUB84(ROUND((unaff_d12 / unaff_d8) * 33554432.0 + 0.5),0);
    this->field_0x4 = SUB84(ROUND((unaff_d15 / unaff_d8) * 33554432.0 + 0.5),0);
    return;
}



// MultiBiquad::ProcessSample(int)

uint MultiBiquad::ProcessSample(int param_1) {
    longlong lVar1;
    uint uVar2;
    int iVar3;
    int iVar4;
    int iVar5;

    iVar3 = this->field_0x14;
    iVar5 = this->field_0x18;
    iVar4 = this->field_0x20;
    this->field_0x18 = iVar3;
    this->field_0x14 = param_1;
    this->field_0x20 = this->field_0x1c;
    lVar1 = (longlong)(int)this->field_0xc * (longlong)iVar4 +
                           (longlong)(int)this->field_0x8 * (longlong)(int)this->field_0x1c +
                                                                           (longlong)(int)this->field_0x4 * (longlong)iVar5 +
                                                                                          (longlong)(int)this->field_0x10 * (longlong)param_1 +
                                                                                                         (longlong)(int)this->field_0x0 * (longlong)iVar3;
    uVar2 = (uint)lVar1;
    uVar2 = uVar2 + 0x1000000 >> 0x19 |
            ((int)((ulonglong)lVar1 >> 0x20) + (uint)(0xfeffffff < uVar2)) * 0x80;
    this->field_0x1c = uVar2;
    return uVar2;
}
