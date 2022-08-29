#pragma once

#include <cstdint>

class AdaptiveBuffer_F32 {
public:
    AdaptiveBuffer_F32(int channels, uint32_t size);
    ~AdaptiveBuffer_F32();

    void FlushBuffer();
    uint32_t GetBufferLength();
    int32_t GetBufferOffset();
    int32_t *GetBufferPointer();
    uint32_t GetChannels();
    void PanFrames(int32_t param_1, int32_t param_2);
    int32_t PopFrames(int16_t param_1, uint32_t param_2);
    int32_t PushFrames(int16_t param_1, uint32_t param_2);
    int32_t PushFrames(int32_t *param_1, uint32_t param_2);
    int32_t PushZero(uint32_t param_1);
    void ScaleFrames(int32_t param_1);
    void SetBufferOffset(uint32_t param_1);
};


