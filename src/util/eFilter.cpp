//
// Created by mart on 2/12/21.
//

#include "eFilter.h"

// eFilter::Mute()

void eFilter::Mute() {
    IIR_1st::Mute((IIR_1st *)this);
    IIR_1st::Mute(&this->field_0x10);
    IIR_1st::Mute(&this->field_0x20);
    IIR_1st::Mute(&this->field_0x30);
    return;
}



// eFilter::setLPF(float)

void eFilter::setLPF(float param_1) {
    IIR_1st *in_r0;
    float in_r1;
    float fVar1;

    in_r0[4].field_0x0 = ROUND(in_r1);
    fVar1 = (float)IIR_1st::setPole(in_r0,param_1);
    IIR_1st::setPole(in_r0 + 1,fVar1);
    return;
}



// eFilter::setHPF(float)

void eFilter::setHPF(float param_1) {
    int in_r0;
    float in_r1;
    float fVar1;

    *(float *)(in_r0 + 0x44) = ROUND(in_r1);
    fVar1 = (float)IIR_1st::setZero((IIR_1st *)(in_r0 + 0x20),param_1);
    IIR_1st::setZero((IIR_1st *)(in_r0 + 0x30),fVar1);
    return;
}



// eFilter::eFilter()

eFilter::eFilter() {
    float fVar1;

    IIR_1st::IIR_1st((IIR_1st *)this);
    IIR_1st::IIR_1st(&this->field_0x10);
    IIR_1st::IIR_1st(&this->field_0x20);
    fVar1 = (float)IIR_1st::IIR_1st(&this->field_0x30);
    fVar1 = (float)setLPF(fVar1);
    setHPF(fVar1);
    Mute(this);
    return this;
}
