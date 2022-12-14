#pragma once

#include <cstdint>
#include "../utils/Crossfeed.h"
#include "../utils/PassFilter.h"

// Iscle: Verified with the latest version at 13/12/2022

class Cure {
public:
    Cure();

    uint16_t GetCutoff();
    float GetFeedback();
    float GetLevelDelay();
    struct Crossfeed::Preset GetPreset(); // TODO: Fix with crossfeed
    void Process(float *buffer, uint32_t size);
    void Reset();
    void SetCutoff(uint16_t cutoff);
    void SetEnable(bool enabled);
    void SetFeedback(float feedback);
    void SetPreset(struct Crossfeed::Preset preset);
    void SetSamplingRate(uint32_t samplingRate);

private:
    Crossfeed crossfeed;
    PassFilter passFilter;
    bool enabled;
};
