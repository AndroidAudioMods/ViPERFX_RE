#pragma once

#include <cstdint>
#include "../utils/Biquad.h"

class PlaybackGain {
public:
    PlaybackGain();

    float AnalyseWave(float *samples, uint32_t size);
    void Process(float *samples, uint32_t size);
    void Reset();
    void SetEnable(bool enable);
    void SetMaxGainFactor(float maxGainFactor);
    void SetRatio(float ratio);
    void SetSamplingRate(uint32_t samplingRate);
    void SetVolume(float volume);

private:
    float ratio2;
    float unknown1;
    uint32_t counterTo100;
    float ratio1;
    float volume;
    float maxGainFactor;
    float unknown2;
    float unknown3;
    Biquad biquad1;
    Biquad biquad2;
    uint32_t samplingRate;
    bool enable;
};


