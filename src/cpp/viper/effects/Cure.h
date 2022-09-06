#pragma once

#include <cstdint>
#include "../utils/Crossfeed.h"
#include "../utils/PassFilter.h"

class Cure {
public:
    Cure();
    ~Cure();

    uint16_t GetCutoff();
    float GetFeedback();
    float GetLevelDelay();
    preset_t GetPreset();
    void Process(float *buffer, uint32_t size);
    void Reset();
    void SetCutoff(uint16_t cutoff);
    void SetEnable(bool enabled);
    void SetFeedback(float feedback);
    void SetPreset(preset_t preset);
    void SetSamplingRate(uint32_t samplerate);

    Crossfeed crossfeed;
    PassFilter pass;
    bool enabled;
};
