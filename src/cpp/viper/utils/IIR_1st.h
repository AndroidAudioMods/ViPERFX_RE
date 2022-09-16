#pragma once

#include <cstdint>

class IIR_1st {
public:
    IIR_1st();

    void Mute();

    void SetCoefficients(float b0, float b1, float a1);

    void setHPF_A(float frequency, uint32_t samplerate);

    void setHPF_BW(float frequency, uint32_t samplerate);

    void setHPF_C(float frequency, uint32_t samplerate);

    void setHPFwLPS_A(float frequency, uint32_t samplerate);

    void setHSF_A(float f1, float f2, uint32_t samplerate);

    void setLPF_A(float frequency, uint32_t samplerate);

    void setLPF_BW(float frequency, uint32_t samplerate);

    void setLPF_C(float frequency, uint32_t samplerate);

    void setLSF_A(float f1, float f2, uint32_t samplerate);

    void setPole(float a1);

    void setPoleHPF(float frequency, uint32_t samplerate);

    void setPoleLPF(float frequency, uint32_t samplerate);

    void setZero(float b1);

    void setZeroHPF(float frequency, uint32_t samplerate);

    void setZeroLPF(float frequency, uint32_t samplerate);

    float b0, b1, a1;
    float prevSample;
};

inline float do_filter(IIR_1st *filter, float sample) {
    float hist = sample * filter->b1;
    sample = filter->prevSample + sample * filter->b0;
    filter->prevSample = sample * filter->a1 + hist;
    return sample;
}