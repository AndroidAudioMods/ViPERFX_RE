#pragma once

#include <cstdint>
#include <vector>

class FIR {
public:
    FIR();

    void FilterSamples(float *samples, uint32_t size);
    void FilterSamplesInterleaved(float *samples, uint32_t size, uint32_t channels);
    uint32_t GetBlockLength();
    int LoadCoefficients(const float *coeffs, uint32_t coeffsSize, uint32_t blockLength);
    void Reset();

private:
    std::vector<float> offsetBlock;
    std::vector<float> coeffs;
    std::vector<float> block;
    uint32_t coeffsSize;
    uint32_t blockLength;
    bool hasCoefficients;
};


