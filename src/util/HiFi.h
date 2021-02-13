//
// Created by mart on 2/13/21.
//

#ifndef VIPER_HIFI_H
#define VIPER_HIFI_H


class HiFi {
    struct WaveBuffer_I32* field_0x0;
    struct WaveBuffer_I32* field_0x4;
    struct IIR_NOrder_BW_LH* field_0x8;
    struct IIR_NOrder_BW_LH* field_0xc;
    struct IIR_NOrder_BW_BP* field_0x10;
    struct IIR_NOrder_BW_LH* field_0x14;
    struct IIR_NOrder_BW_LH* field_0x18;
    struct IIR_NOrder_BW_BP* field_0x1c;
    int field_0x20;
    int field_0x24;

public:
    ~HiFi();
    void Reset();
    HiFi();
    void SetSamplingRate(int param_1);
    void SetClarity(float param_1);
    int Process(int *param_1,int param_2);
};


#endif //VIPER_HIFI_H
