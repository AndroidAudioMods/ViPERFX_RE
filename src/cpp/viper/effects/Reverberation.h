#pragma once

#include <cstdint>
#include "../utils/CRevModel.h"

class Reverberation {
public:
    Reverberation();

    void Process(float *buffer, uint32_t size);
    void Reset();
    void SetDamp(float value);
    void SetDry(float value);
    void SetEnable(bool enable);
    void SetRoomSize(float value);
    void SetWet(float value);
    void SetWidth(float value);

private:
    CRevModel model;
    bool enable;
};



