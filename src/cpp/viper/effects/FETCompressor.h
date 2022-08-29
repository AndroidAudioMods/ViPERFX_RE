#pragma once

#include <cstdint>

class FETCompressor {
public:
    FETCompressor();
    ~FETCompressor();

    void GetMeter();
    void GetParameter();
    void GetParamterDefault();
    void Process();
    void ProcessSidechain();
    void Reset();
    void SetParameter(int32_t param_1, float param_2);
    void SetSamplingRate(uint32_t samplingRate);
};


