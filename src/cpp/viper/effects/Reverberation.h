#pragma once

#include <cstdint>
#include "../utils/CRevModel.h"

class Reverberation {
public:
    Reverberation();
    ~Reverberation();

    void Process(float *buffer, uint32_t size);
    void Reset();
    void SetDamp(float value);
    void SetDry(float value);
    void SetEnable(bool enable);
    void SetRoomSize(float value);
    void SetSamplingRate(uint32_t value);
    void SetWet(float value);
    void SetWidth(float value);

    float roomsize;
    float width;
    float damp;
    float wet;
    float dry;
    CRevModel model;
    uint32_t samplerate;
    bool enabled;
};



