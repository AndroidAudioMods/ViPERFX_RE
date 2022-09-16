#pragma once

#include <cstdint>

class FIR {
public:
    FIR();
    ~FIR();

    void FilterSamples(int *samples, uint32_t size);
    void FilterSamplesInterleaved(int *samples, uint32_t size, uint32_t channels);
    int GetBlockLength();
    int LoadCoefficients(float *coeffs, uint32_t coeffsize, int blockLength);
    void Reset();

private:
    int *offsetBlock;
    float *coeffs;
    float *block;
    int coeffsize;
    int blockLength;
    bool enabled;

};


