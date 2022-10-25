#pragma once

#include <cstdint>

class AdaptiveBuffer {
public:
    AdaptiveBuffer(uint32_t channels, uint32_t length);
    ~AdaptiveBuffer();

    void FlushBuffer();
    uint32_t GetBufferLength() const;
    uint32_t GetBufferOffset() const;
    float *GetBuffer() const;
    uint32_t GetChannels() const;
    void PanFrames(float left, float right);
    int PopFrames(float *frames, uint32_t length);
    int PushFrames(const float *frames, uint32_t length);
    int PushZero(uint32_t length);
    void ScaleFrames(float scale);
    void SetBufferOffset(uint32_t offset);

private:
    float *buffer;
    uint32_t length;
    uint32_t offset;
    uint32_t channels;

};


