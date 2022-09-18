#pragma once

class MinPhaseIIRCoeffs {
public:
    MinPhaseIIRCoeffs();
    ~MinPhaseIIRCoeffs();

    void Find_F1_F2(double a, double b, double *c, double *d);
    float *GetCoefficients();
    float *GetIndexFrequency();
    int *SolveRoot(double a, double b, double c, double *d);
    int UpdateCoeffs(int a, int samplingRate);
};