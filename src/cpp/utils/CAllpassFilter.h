//
// Created by mart on 7/26/21.
//

#pragma once

#include <cstdint>

class CAllpassFilter {
public:
    CAllpassFilter();

    void Mute();

    float Process(float sample);

    float GetFeedback();

    void SetBuffer(float *buffer, uint32_t size);

    void SetFeedback(float feedback);

    float *buffer;
    uint32_t bufidx;
    uint32_t bufsize;
    float feedback;
};
