//
// Created by mart on 7/26/21.
//

#pragma once


#include <cstdint>

typedef struct {
    uint16_t cutoff;
    uint16_t feedback;
} preset_t;

class Crossfeed {
public:
    Crossfeed();

    void Reset();
    void ProcessFrames(float* buffer, uint32_t size);
    void FilterSample(float* sample);

    uint16_t GetCutoff();
    float GetFeedback();
    float GetLevelDelay();
    preset_t GetPreset();
    void SetCutoff(uint16_t cutoff);
    void SetFeedback(float feedback);
    void SetPreset(preset_t preset);
    void SetSamplingRate(uint32_t samplerate);

    uint32_t samplerate;
    float a0_lo, b1_lo;
    float a0_hi, b1_hi, a1_hi;
    float gain;
    struct {
        float asis[2], lo[2], hi[2];
    } lfs;
    preset_t preset;
};
