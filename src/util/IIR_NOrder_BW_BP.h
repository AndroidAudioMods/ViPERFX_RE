//
// Created by mart on 2/12/21.
//

#ifndef VIPER_IIR_NORDER_BW_BP_H
#define VIPER_IIR_NORDER_BW_BP_H


class IIR_NOrder_BW_BP {
    struct IIR_1st* field_0x0;
    struct IIR_1st* field_0x4;
    undefined4 field_0x8;

public:
    IIR_NOrder_BW_BP(int param_1);
    ~IIR_NOrder_BW_BP();
    void Mute();
    void setBPF(float param_1,float param_2,float param_3);
};


#endif //VIPER_IIR_NORDER_BW_BP_H
