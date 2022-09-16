//
// Created by mart on 7/27/21.
//

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
    float filterstore;
    float damp;
    float damp2;
    float *buffer;
    uint32_t size;
    uint32_t bufidx;
};



