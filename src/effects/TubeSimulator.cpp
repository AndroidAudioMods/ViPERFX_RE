//
// Created by mart on 2/12/21.
//

#include "TubeSimulator.h"

// TubeSimulator::TubeSimulator()

TubeSimulator::TubeSimulator() {
    *(undefined4 *)this = 0;
    *(undefined4 *)&this->field_0x4 = 0;
    this->field_0x8 = false;
    return;
}



// TubeSimulator::TubeProcess(int*, int)

void TubeSimulator::TubeProcess(int *param_1,int param_2) {
    int iVar1;
    int iVar2;
    int *piVar3;
    int iVar4;
    int *piVar5;

    if ((this->field_0x8 != false) && (0 < param_2)) {
        iVar2 = param_2 + -1;
        piVar3 = param_1 + 2;
        piVar5 = param_1 + 2;
        do {
            iVar4 = param_1[1];
            iVar2 = iVar2 + -1;
            iVar1 = *(int *)this + piVar3[-2] >> 1;
            *(int *)this = iVar1;
            *(int *)&this->field_0x4 = iVar4 + *(int *)&this->field_0x4 >> 1;
            piVar3[-2] = iVar1;
            param_1[1] = *(int *)&this->field_0x4;
            param_1 = piVar5;
            piVar3 = piVar3 + 2;
            piVar5 = piVar5 + 2;
        } while (iVar2 != -1);
    }
    return;
}



// TubeSimulator::Reset()

void TubeSimulator::Reset() {
    *(undefined4 *)this = 0;
    *(undefined4 *)&this->field_0x4 = 0;
    this->field_0x8 = false;
    return;
}
