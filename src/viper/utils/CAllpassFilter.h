#pragma once

#include <cstdint>

class CAllpassFilter {
public:
    CAllpassFilter();

    float GetFeedback();
    void Mute();
    float Process(float sample);
    void SetBuffer(float *buffer, uint32_t size);
    void SetFeedback(float feedback);

private:
    float feedback;
    float *buffer;
    uint32_t bufferSize;
    uint32_t bufferIndex;
};
