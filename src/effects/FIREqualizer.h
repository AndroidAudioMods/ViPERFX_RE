//
// Created by mart on 2/12/21.
//

#ifndef VIPER_FIREQUALIZER_H
#define VIPER_FIREQUALIZER_H


class FIREqualizer {
    int* field_0x0;
    uint samplerate;
    bool enabled;
    
public:
    ~FIREqualizer();
    void SetBandLevel(uint param_1,float param_2);
    void Reset();
    undefined4 SetEnable(bool param_1);
    void SetSamplingRate(uint param_1);
    FIREqualizer();
    void Process(int *param_1,int param_2);
};


#endif //VIPER_FIREQUALIZER_H
