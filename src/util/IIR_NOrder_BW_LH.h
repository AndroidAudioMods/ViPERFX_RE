//
// Created by mart on 2/12/21.
//

#ifndef VIPER_IIR_NORDER_BW_LH_H
#define VIPER_IIR_NORDER_BW_LH_H


class IIR_NOrder_BW_LH {
    struct IIR_1st * field_0x0;
    int field_0x4;

public:
    IIR_NOrder_BW_LH(int param_1);
    ~IIR_NOrder_BW_LH();
    void Mute();
    void setLPF(float param_1,float param_2);
    void setHPF(float param_1,float param_2);
};


#endif //VIPER_IIR_NORDER_BW_LH_H
