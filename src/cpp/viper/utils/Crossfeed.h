#pragma once

#include <cstdint>

class Crossfeed {
public:
    struct Preset {
        uint16_t cutoff;
        uint16_t feedback;
    };

    Crossfeed();

    void Reset();
    void ProcessFrames(float *buffer, uint32_t size);
    void FilterSample(float *sample);
    uint16_t GetCutoff();
    float GetFeedback();
    float GetLevelDelay();
    struct Preset GetPreset();
    void SetCutoff(uint16_t cutoff);
    void SetFeedback(float feedback);
    void SetPreset(struct Preset preset);
    void SetSamplingRate(uint32_t samplingRate);

private:
    uint32_t samplingRate;
    float a0_lo, b1_lo;
    float a0_hi, b1_hi, a1_hi;
    float gain;
    struct {
        float asis[2], lo[2], hi[2];
    } lfs;
    struct Preset preset;
};
