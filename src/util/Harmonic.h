//
// Created by mart on 2/12/21.
//

#ifndef VIPER_HARMONIC_H
#define VIPER_HARMONIC_H


#include "misc.h"

class Harmonic {
    float field_0x0[11];
    undefined4 field_0x2c;
    undefined4 field_0x30;
    float field_0x34;
    undefined4 field_0x38;
    
public:
    ~Harmonic();
    void UpdateCoeffs(float *param_1);
    void Reset();
    Harmonic();
    void SetHarmonics(float *param_1);
    int Process(int param_1);
};


#endif //VIPER_HARMONIC_H
