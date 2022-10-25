#include "IIR_NOrder_BW_BP.h"

IIR_NOrder_BW_BP::IIR_NOrder_BW_BP(uint32_t order) {
    this->lowpass = new IIR_1st[order];
    this->highpass = new IIR_1st[order];
    this->order = order;

    for (uint32_t x = 0; x < order; x++) {
        this->lowpass[x].Mute();
        this->highpass[x].Mute();
    }
}

IIR_NOrder_BW_BP::~IIR_NOrder_BW_BP() {
    delete[] this->lowpass;
    delete[] this->highpass;
}

void IIR_NOrder_BW_BP::Mute() {
    for (uint32_t x = 0; x < this->order; x++) {
        this->lowpass[x].Mute();
        this->highpass[x].Mute();
    }
}

void IIR_NOrder_BW_BP::setBPF(float highCut, float lowCut, uint32_t samplingRate) {
    for (uint32_t x = 0; x < this->order; x++) {
        this->lowpass[x].setLPF_BW(lowCut, samplingRate);
        this->highpass[x].setHPF_BW(highCut, samplingRate);
    }
}
