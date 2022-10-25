#pragma once

#include <cstdint>

class CCombFilter {
public:
    CCombFilter();

    float GetDamp();
    float GetFeedback();
    void Mute();
    float Process(float sample);
    void SetBuffer(float *buffer, uint32_t size);
    void SetDamp(float damp);
    void SetFeedback(float feedback);

private:
    float feedback;
    float filterStore;
    float damp;
    float damp2;
    float *buffer;
    uint32_t bufferSize;
    uint32_t bufferIndex;
};



