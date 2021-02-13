//
// Created by mart on 2/12/21.
//

#ifndef VIPER_FFT_R24_F32_H
#define VIPER_FFT_R24_F32_H


class FFT_R24_F32 {
    void* field_0x0;
    void* field_0x4;
    int field_0x8;

public:
    void makect(int param_1,int *param_2,float *param_3);
    void bitrv2(int param_1,int *param_2,float *param_3);
    void makewt(int param_1,int *param_2,float *param_3);
    cft1st(int param_1,float *param_2,float *param_3);
    cftmdl(int param_1,int param_2,float *param_3,float *param_4);
    void cftfsub(int param_1,float *param_2,float *param_3);
    void cftbsub(int param_1,float *param_2,float *param_3);
    void rftfsub(int param_1,float *param_2,int param_3,float *param_4);
    void rftbsub(int param_1,float *param_2,int param_3,float *param_4);
    void rdft(int param_1,int param_2,float *param_3,int *param_4,float *param_5);
    FFT_R24_F32(int param_1);
    ~FFT_R24_F32();
    void RDFT(float *param_1);
    void IRDFT(float *param_1);
};


#endif //VIPER_FFT_R24_F32_H
