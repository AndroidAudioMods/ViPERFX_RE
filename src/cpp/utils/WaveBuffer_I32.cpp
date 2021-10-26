//
// Created by mart on 7/31/21.
//

#include <cstdlib>
#include <cstring>
#include "WaveBuffer_I32.h"

WaveBuffer_I32::WaveBuffer_I32(int channels, uint32_t size) {
    this->channels = channels;
    this->size = size * channels;
    this->index = 0;
    this->buffer = (float*)malloc(this->size * sizeof(float));
}

WaveBuffer_I32::~WaveBuffer_I32() {
    free(this->buffer);
}

void WaveBuffer_I32::Reset() {
    this->index = 0;
}

uint32_t WaveBuffer_I32::GetBufferOffset() {
    return this->index / this->channels;
}

uint32_t WaveBuffer_I32::GetBufferSize() {
    return this->size / this->channels;
}

float *WaveBuffer_I32::GetCurrentBufferI32Ptr() {
    return this->buffer;
}

uint32_t WaveBuffer_I32::PopSamples(uint32_t size, bool resetIndex) {
    if (this->buffer == nullptr || this->size == 0) {
        return 0;
    }

    if (this->channels * size <= this->index) {
        this->index -= this->channels * size;
        memmove(this->buffer, &this->buffer[this->channels*size], this->index * sizeof(float));
        return size;
    }

    if (resetIndex) {
        uint32_t idx = this->index;
        this->index = 0;
        return idx / this->channels;
    }

    return 0;
}

uint32_t WaveBuffer_I32::PopSamples(float *dest, uint32_t size, bool resetIndex) {
    if (this->buffer == nullptr || this->size == 0 || dest == nullptr) {
        return 0;
    }

    if (this->channels * size <= this->index) {
        memcpy(dest, this->buffer, this->index * sizeof(float));
        this->index -= this->channels * size;
        memmove(this->buffer, &this->buffer[this->channels*size], this->index * sizeof(float));
        return size;
    }

    if (resetIndex) {
        uint32_t idx = this->index;
        memcpy(dest, this->buffer, this->index * sizeof(float));
        this->index = 0;
        return idx / this->channels;
    }

    return 0;
}

int WaveBuffer_I32::PushSamples(float *source, uint32_t size) {
    if (this->buffer == nullptr) {
        return 0;
    }

    if (size > 0) {
        if (this->size < this->channels * size + this->index) {
            float* buf = (float*)malloc((this->channels * size + this->index) * sizeof(float));
            if (buf == nullptr) {
                return 0;
            }
            memcpy(buf, this->buffer, this->index * sizeof(float));
            free(this->buffer);
            this->buffer = buf;
            this->size = this->channels * size + this->index;
        }
        memcpy(&this->buffer[this->index], source, this->channels * size * sizeof(float));
        this->index += this->channels * size;
    }

    return 1;
}

int WaveBuffer_I32::PushZeros(uint32_t size) {
    if (this->buffer == nullptr) {
        return 0;
    }

    if (size > 0) {
        if (this->size < this->channels * size + this->index) {
            float* buf = (float*)malloc((this->channels * size + this->index) * sizeof(float));
            if (buf == nullptr) {
                return 0;
            }
            memcpy(buf, this->buffer, this->index * sizeof(float));
            free(this->buffer);
            this->buffer = buf;
            this->size = this->channels * size + this->index;
        }
        memset(&this->buffer[this->index], 0, this->channels * size * sizeof(float));
        this->index += this->channels * size;
    }

    return 1;
}

float *WaveBuffer_I32::PushZerosGetBuffer(uint32_t size) {
    if (this->buffer == nullptr) {
        return nullptr;
    }

    if (size > 0) {
        if (this->size < this->channels * size + this->index) {
            float* buf = (float*)malloc((this->channels * size + this->index) * sizeof(float));
            if (buf == nullptr) {
                return nullptr;
            }
            memcpy(buf, this->buffer, this->index * sizeof(float));
            free(this->buffer);
            this->buffer = buf;
            this->size = this->channels * size + this->index;
        }
        memset(&this->buffer[this->index], 0, this->channels * size * sizeof(float));
        this->index += this->channels * size;
    }

    return &this->buffer[this->index];
}

void WaveBuffer_I32::SetBufferOffset(uint32_t offset) {
    this->index = offset;
}
