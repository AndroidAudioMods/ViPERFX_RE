#include "WaveBuffer.h"
#include <cstring>

WaveBuffer::WaveBuffer(int channels, uint32_t size) {
    this->channels = channels;
    this->size = size * channels;
    this->index = 0;
    this->buffer = new float[this->size];
}

WaveBuffer::~WaveBuffer() {
    delete this->buffer;
}

uint32_t WaveBuffer::GetBufferOffset() {
    return this->index / this->channels;
}

uint32_t WaveBuffer::GetBufferSize() {
    return this->size / this->channels;
}

float *WaveBuffer::GetBuffer() {
    return this->buffer;
}

uint32_t WaveBuffer::PopSamples(uint32_t size, bool resetIndex) {
    if (this->buffer == nullptr || this->size == 0) {
        return 0;
    }

    if (this->channels * size <= this->index) {
        this->index -= this->channels * size;
        memmove(this->buffer, &this->buffer[this->channels * size], this->index * sizeof(float));
        return size;
    }

    if (resetIndex) {
        uint32_t idx = this->index;
        this->index = 0;
        return idx / this->channels;
    }

    return 0;
}

uint32_t WaveBuffer::PopSamples(float *dest, uint32_t size, bool resetIndex) {
    if (this->buffer == nullptr || this->size == 0 || dest == nullptr) {
        return 0;
    }

    if (this->channels * size <= this->index) {
        memcpy(dest, this->buffer, this->channels * size * sizeof(float));
        this->index -= this->channels * size;
        memmove(this->buffer, &this->buffer[this->channels * size], this->index * sizeof(float));
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

int WaveBuffer::PushSamples(float *source, uint32_t size) {
    if (this->buffer == nullptr) {
        return 0;
    }

    if (size > 0) {
        uint32_t requiredSize = this->channels * size + this->index;
        if (this->size < requiredSize) {
            auto *buf = new float[requiredSize];
            memcpy(buf, this->buffer, this->index * sizeof(float));
            delete this->buffer;
            this->buffer = buf;
            this->size = requiredSize;
        }
        memcpy(&this->buffer[this->index], source, this->channels * size * sizeof(float));
        this->index += this->channels * size;
    }

    return 1;
}

int WaveBuffer::PushZeros(uint32_t size) {
    if (this->buffer == nullptr) {
        return 0;
    }

    if (size > 0) {
        uint32_t requiredSize = this->channels * size + this->index;
        if (this->size < requiredSize) {
            auto *buf = new float[requiredSize];
            memcpy(buf, this->buffer, this->index * sizeof(float));
            delete this->buffer;
            this->buffer = buf;
            this->size = requiredSize;
        }
        memset(&this->buffer[this->index], 0, this->channels * size * sizeof(float));
        this->index += this->channels * size;
    }

    return 1;
}

float *WaveBuffer::PushZerosGetBuffer(uint32_t size) {
    uint32_t oldIndex = this->index;

    if (this->buffer == nullptr) {
        return nullptr;
    }

    if (size > 0) {
        uint32_t requiredSize = this->channels * size + this->index;
        if (this->size < requiredSize) {
            auto *buf = new float[requiredSize];
            memcpy(buf, this->buffer, this->index * sizeof(float));
            delete this->buffer;
            this->buffer = buf;
            this->size = requiredSize;
        }
        memset(&this->buffer[this->index], 0, this->channels * size * sizeof(float));
        this->index += this->channels * size;
    }

    return &this->buffer[oldIndex];
}

void WaveBuffer::Reset() {
    this->index = 0;
}

void WaveBuffer::SetBufferOffset(uint32_t offset) {
    uint32_t maxOffset = this->size / this->channels;
    if (offset <= maxOffset) {
        this->index = offset * this->channels;
    }
}
