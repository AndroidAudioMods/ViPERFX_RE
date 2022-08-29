#pragma once

#include <cstdint>
#include "../utils/Crossfeed.h"
#include "../utils/PassFilter.h"

class Cure {
public:
    Cure();
    ~Cure();

    void Process(float *buffer, uint32_t size);
    void Reset();
    void SetEnable(bool enabled);
    uint16_t GetCutoff();
    float GetFeedback();
    float GetLevelDelay();
    preset_t GetPreset();
    void SetCutoff(uint16_t cutoff);
    void SetFeedback(float feedback);
    void SetPreset(preset_t preset);
    void SetSamplingRate(uint32_t samplerate);

    Crossfeed crossfeed;
    PassFilter pass;
    bool enabled;
};
