#pragma once

#include <cstdint>

class PlaybackGain {
public:
    PlaybackGain();
    ~PlaybackGain();

    void AnalyseWave();
    void Process();
    void Reset();
    void SetEnable(bool enable);
    void SetMaxGainFactor();
    void SetRatio();
    void SetSamplingRate(uint32_t samplingRate);
    void SetVolume();
};


