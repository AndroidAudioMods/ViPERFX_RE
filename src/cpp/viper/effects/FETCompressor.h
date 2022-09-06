#pragma once

#include <cstdint>

class FETCompressor {
public:
    FETCompressor();
    ~FETCompressor();

    void GetMeter();
    void GetParameter();
    void GetParameterDefault();
    void Process(float *samples, uint32_t size);
    void ProcessSidechain();
    void Reset();
    void SetParameter(int32_t param_1, float param_2);
    void SetSamplingRate(uint32_t samplingRate);
};


