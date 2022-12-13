#pragma once

#include <cstdint>

// Iscle: Verified with latest version at 13/12/2022

class MinPhaseIIRCoeffs {
public:
    MinPhaseIIRCoeffs();
    ~MinPhaseIIRCoeffs();

    double *GetCoefficients();
    float GetIndexFrequency(uint32_t param_1);
    int UpdateCoeffs(uint32_t bands, uint32_t samplingRate);

private:
    void Find_F1_F2(double param_2, double param_3, double *param_4, double *param_5);
    int SolveRoot(double param_2, double param_3, double param_4, double *param_5);

    double *coeffs;
    uint32_t samplingRate;
    uint32_t bands;
};