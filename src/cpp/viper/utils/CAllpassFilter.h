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
    float *buffer;
    uint32_t bufidx;
    uint32_t bufsize;
    float feedback;
};
