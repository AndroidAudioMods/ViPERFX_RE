#pragma once

#include <cstdint>

class SoftwareLimiter {
public:
    SoftwareLimiter();

    float Process(float sample);
    void ResetLimiter();
    void SetGate(float gate);

private:
    float gate;
    float unknown1;
    float unknown2;
    float unknown3;
    float arr256[256];
    float arr512[512];
    uint32_t unknown4;
    bool ready;
};


