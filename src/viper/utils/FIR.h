#pragma once

#include <cstdint>

class FIR {
public:
    FIR();
    ~FIR();

    void FilterSamples(float *samples, uint32_t size);
    void FilterSamplesInterleaved(float *samples, uint32_t size, uint32_t channels);
    uint32_t GetBlockLength();
    int LoadCoefficients(const float *coeffs, uint32_t coeffsSize, uint32_t blockLength);
    void Reset();

private:
    float *offsetBlock;
    float *coeffs;
    float *block;
    uint32_t coeffsSize;
    uint32_t blockLength;
    bool hasCoefficients;
};


