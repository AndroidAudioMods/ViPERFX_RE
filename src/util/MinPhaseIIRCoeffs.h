//
// Created by mart on 2/12/21.
//

#ifndef VIPER_MINPHASEIIRCOEFFS_H
#define VIPER_MINPHASEIIRCOEFFS_H


class MinPhaseIIRCoeffs {
    void * coefficients;
    int samplerate;
    int field_0x8;

public:
    MinPhaseIIRCoeffs();
    ~MinPhaseIIRCoeffs();
    void Find_F1_F2(double param_1,double param_2,double *param_3,double *param_4);
    double * SolveRoot(double param_1,double param_2,double param_3,double *param_4);
    undefined4 UpdateCoeffs(int param_1,int samplerate);
    void * GetCoefficients();
    undefined8 GetIndexFrequency(int param_1);
};


#endif //VIPER_MINPHASEIIRCOEFFS_H
