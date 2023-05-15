#pragma once

#include <cstdint>
#include "../utils/Harmonic.h"
#include "../utils/MultiBiquad.h"
#include <array>

class AnalogX {
public:
    AnalogX();

    void Process(float *samples, uint32_t size);
    void Reset();
    void SetEnable(bool enable);
    void SetProcessingModel(int processingModel);
    void SetSamplingRate(uint32_t samplingRate);

private:
    std::array<MultiBiquad, 2> highPass;
    std::array<Harmonic, 2> harmonic;
    std::array<MultiBiquad, 2> lowPass;
    std::array<MultiBiquad, 2> peak;

    float gain;
    uint32_t freqRange;
    int processingModel;
    uint32_t samplingRate;
    bool enable;
};


