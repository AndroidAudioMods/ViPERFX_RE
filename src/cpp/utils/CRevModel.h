//
// Created by mart on 7/27/21.
//

#pragma once

#include "CCombFilter.h"
#include "CAllpassFilter.h"

class CRevModel {
public:
    CRevModel();
    ~CRevModel();

    void Mute();
    void ProcessReplace(float *bufL, float *bufR, uint32_t size);
    void UpdateCoeffs();
    void Reset();

    void SetRoomSize(float value);
    void SetDamp(float value);
    void SetWet(float value);
    void SetDry(float value);
    void SetWidth(float value);
    void SetMode(int value);
    float GetRoomSize();
    float GetDamp();
    float GetWet();
    float GetDry();
    float GetWidth();
    int GetMode();

    float gain;
    float roomsize;
    float roomsize1;
    float damp;
    float damp1;
    float wet;
    float wet1;
    float wet2;
    float dry;
    float width;
    int mode;

    CCombFilter combL[8];
    CCombFilter combR[8];

    CAllpassFilter allpassL[4];
    CAllpassFilter allpassR[4];

    float* buffers[24];
};



