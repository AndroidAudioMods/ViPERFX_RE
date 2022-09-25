#pragma once

#include <cstdint>

class MinPhaseIIRCoeffs {
public:
    MinPhaseIIRCoeffs();
    ~MinPhaseIIRCoeffs();

    void Find_F1_F2(double param_2, double param_3, double *param_4, double *param_5);
    float *GetCoefficients();
    float GetIndexFrequency(uint32_t param_1);
    int SolveRoot(double param_2, double param_3, double param_4, double *param_5);
    int UpdateCoeffs(uint32_t bands, uint32_t samplingRate);

private:
    float *coeffs;
    uint32_t samplingRate;
    uint32_t bands;
};