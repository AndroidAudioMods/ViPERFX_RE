#pragma once

#include <cstdint>

typedef struct {
    float lower_angle;
    float upper_angle;

    float in[3];
    float x[4];
    float y[4];
} channel;


class PolesFilter {
public:
    PolesFilter();

    void Reset();

    void UpdateCoeff();

    void DoFilterLeft(float sample, float *out1, float *out2, float *out3);

    void DoFilterRight(float sample, float *out1, float *out2, float *out3);

    void SetPassFilter(uint32_t lower_freq, uint32_t upper_freq);

    void SetSamplingRate(uint32_t samplingRate);

    channel channels[2];
    uint32_t lower_freq;
    uint32_t upper_freq;
    uint32_t samplingRate;
};


