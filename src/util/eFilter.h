//
// Created by mart on 2/12/21.
//

#ifndef VIPER_EFILTER_H
#define VIPER_EFILTER_H


class eFilter {
    struct IIR_1st field_0x0;
    struct IIR_1st field_0x10;
    struct IIR_1st field_0x20;
    struct IIR_1st field_0x30;

public:
    void Mute();
    void setLPF(float param_1);
    void setHPF(float param_1);
    eFilter();
};


#endif //VIPER_EFILTER_H
