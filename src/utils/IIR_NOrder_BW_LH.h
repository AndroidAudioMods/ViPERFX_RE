//
// Created by mart on 7/26/21.
//

#pragma once

#include "IIR_1st.h"

class IIR_NOrder_BW_LH {
public:
    explicit IIR_NOrder_BW_LH(uint32_t order);
    ~IIR_NOrder_BW_LH();

    void Mute();
    void setLPF(float frequency, uint32_t samplerate);
    void setHPF(float frequency, uint32_t samplerate);

    IIR_1st* filters;
    uint32_t order;
};
