//
// Created by mart on 7/26/21.
//

#pragma once

#include "IIR_1st.h"

class IIR_NOrder_BW_BP {
public:
    explicit IIR_NOrder_BW_BP(uint32_t order);
    ~IIR_NOrder_BW_BP();

    void Mute();
    void setBPF(float highCut, float lowCut, uint32_t samplerate);

    IIR_1st* lowpass;
    IIR_1st* highpass;
    uint32_t order;
};

