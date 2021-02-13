//
// Created by mart on 2/12/21.
//

#ifndef VIPER_IIR_1ST_H
#define VIPER_IIR_1ST_H


class IIR_1st {
    float field_0x0;
    float field_0x4;
    float field_0x8;
    undefined4 field_0xc;

public:
    void Mute();
    IIR_1st();
    void setCoefficients(int param_1,int param_2,int param_3);
    void setLPF_BW(float param_1,float param_2);
    void setHPF_BW(float param_1,float param_2);
    void setLPF_A(float param_1,float param_2);
    void setHPF_A(float param_1,float param_2);
    void setLSF_A(float param_1,float param_2,float param_3);
    void setHSF_A(float param_1,float param_2,float param_3);
    void setHPFwLFS_A(float param_1,float param_2);
    void setLPF_C(float param_1,float param_2);
    void setHPF_C(float param_1,float param_2);
    void setPole(float param_1);
    void setZero(float param_1);
    void setPoleLPF(float param_1,float param_2);
    void setPoleHPF(float param_1,float param_2);
    void setZeroLPF(float param_1,float param_2);
    void setZeroHPF(float param_1,float param_2);
};


#endif //VIPER_IIR_1ST_H
