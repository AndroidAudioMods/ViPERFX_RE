#pragma once

#include <cstdint>

class PlaybackGain {
public:
    PlaybackGain();
    ~PlaybackGain();

    void AnalyseWave();
    void Process(float *samples, uint32_t size);
    void Reset();
    void SetEnable(bool enable);
    void SetMaxGainFactor();
    void SetRatio();
    void SetSamplingRate(uint32_t samplingRate);
    void SetVolume();
};


