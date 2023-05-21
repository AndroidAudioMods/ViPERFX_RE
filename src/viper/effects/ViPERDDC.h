#pragma once

#include <cstdint>
#include <vector>
#include <array>

class ViPERDDC {
public:
    ViPERDDC();

    void Process(float *samples, uint32_t size);
    void Reset();
    void SetCoeffs(uint32_t newCoeffsSize, float *newCoeffs44100, float *newCoeffs48000);
    void SetEnable(bool enable);
    void SetSamplingRate(uint32_t samplingRate);

private:
    bool enable;
    bool setCoeffsOk;
    uint32_t samplingRate;
    uint32_t arrSize;
    std::vector<std::array<float, 5>> coeffsArr44100;
    std::vector<std::array<float, 5>> coeffsArr48000;
    std::vector<float> x1L;
    std::vector<float> x1R;
    std::vector<float> x2L;
    std::vector<float> x2R;
    std::vector<float> y1L;
    std::vector<float> y1R;
    std::vector<float> y2L;
    std::vector<float> y2R;

    void ReleaseResources();
};


