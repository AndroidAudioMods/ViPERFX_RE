#pragma once

#include <cstdint>
#include <vector>

class AdaptiveBuffer {
public:
    AdaptiveBuffer(uint32_t channels, uint32_t length);

    void FlushBuffer();
    uint32_t GetBufferLength() const;
    uint32_t GetBufferOffset() const;
    float *GetBuffer();
    uint32_t GetChannels() const;
    void SetGain(float left, float right);
    int PopFrames(float *frames, uint32_t length);
    int PushFrames(const float *frames, uint32_t length);
    int PushZero(uint32_t length);
    void SetBufferOffset(uint32_t offset);

private:
    std::vector<float> buffer;
    uint32_t length;
    uint32_t offset;
    uint32_t channels;

};


