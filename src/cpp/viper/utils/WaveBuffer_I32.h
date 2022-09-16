#pragma once


#include <cstdint>

class WaveBuffer_I32 {
public:
    WaveBuffer_I32(int channels, uint32_t size);

    ~WaveBuffer_I32();

    void Reset();

    uint32_t GetBufferOffset();

    uint32_t GetBufferSize();

    float *GetCurrentBufferI32Ptr();

    uint32_t PopSamples(uint32_t size, bool resetIndex);

    uint32_t PopSamples(float *dest, uint32_t size, bool resetIndex);

    int PushSamples(float *source, uint32_t size);

    int PushZeros(uint32_t size);

    float *PushZerosGetBuffer(uint32_t size);

    void SetBufferOffset(uint32_t offset);

    float *buffer;
    uint32_t size;
    uint32_t index;
    int channels;
};


