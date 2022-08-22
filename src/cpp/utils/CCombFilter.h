//
// Created by mart on 7/27/21.
//

#pragma once

#include <cstdint>

class CCombFilter {
public:
    CCombFilter();

    float Process(float sample);

    void Mute();

    float GetDamp();

    float GetFeedback();

    void SetDamp(float damp);

    void SetFeedback(float feedback);

    void SetBuffer(float *buffer, uint32_t size);

    float feedback;
    float filterstore;
    float damp;
    float damp2;
    float *buffer;
    uint32_t size;
    uint32_t bufidx;
};



