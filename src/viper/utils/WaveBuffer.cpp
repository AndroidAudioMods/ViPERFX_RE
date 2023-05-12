#include "WaveBuffer.h"
#include <cstring>

WaveBuffer::WaveBuffer(uint32_t channels, uint32_t length) {
    this->channels = channels;
    this->index = 0;
    this->buffer = std::vector<float>(length * channels);
}

uint32_t WaveBuffer::GetBufferOffset() {
    return this->index / this->channels;
}

uint32_t WaveBuffer::GetBufferSize() {
    return this->buffer.size() / this->channels;
}

float *WaveBuffer::GetBuffer() {
    return this->buffer.data();
}

uint32_t WaveBuffer::PopSamples(uint32_t size, bool resetIndex) {
    if (this->buffer.empty()) {
        return 0;
    }

    if (this->channels * size <= this->index) {
        this->index -= this->channels * size;
        memmove(this->buffer.data(), this->buffer.data() + this->channels * size, this->index * sizeof(float));
        return size;
    }

    if (resetIndex) {
        uint32_t ret = this->index / this->channels;
        this->index = 0;
        return ret;
    }

    return 0;
}

uint32_t WaveBuffer::PopSamples(float *dest, uint32_t size, bool resetIndex) {
    if (this->buffer.empty() || dest == nullptr) {
        return 0;
    }

    if (this->channels * size <= this->index) {
        memcpy(dest, this->buffer.data(), this->channels * size * sizeof(float));
        this->index -= this->channels * size;
        memmove(this->buffer.data(), this->buffer.data() + this->channels * size, this->index * sizeof(float));
        return size;
    }

    if (resetIndex) {
        uint32_t ret = this->index / this->channels;
        memcpy(dest, this->buffer.data(), this->index * sizeof(float));
        this->index = 0;
        return ret;
    }

    return 0;
}

int WaveBuffer::PushSamples(float *source, uint32_t size) {
    if (size > 0) {
        uint32_t requiredSize = this->channels * size + this->index;
        if (requiredSize > this->buffer.size()) {
            this->buffer.resize(requiredSize);
        }
        memcpy(this->buffer.data() + this->index, source, this->channels * size * sizeof(float));
        this->index += this->channels * size;
    }

    return 1;
}

int WaveBuffer::PushZeros(uint32_t size) {
    if (size > 0) {
        uint32_t requiredSize = this->channels * size + this->index;
        if (requiredSize > this->buffer.size()) {
            this->buffer.resize(requiredSize);
        }
        memset(this->buffer.data() + this->index, 0, this->channels * size * sizeof(float));
        this->index += this->channels * size;
    }

    return 1;
}

float *WaveBuffer::PushZerosGetBuffer(uint32_t size) {
    uint32_t oldIndex = this->index;

    if (size > 0) {
        uint32_t requiredSize = this->channels * size + this->index;
        if (requiredSize > this->buffer.size()) {
            this->buffer.resize(requiredSize);
        }
        memset(this->buffer.data() + this->index, 0, this->channels * size * sizeof(float));
        this->index += this->channels * size;
    }

    return this->buffer.data() + oldIndex;
}

void WaveBuffer::Reset() {
    this->index = 0;
}

void WaveBuffer::SetBufferOffset(uint32_t offset) {
    uint32_t maxOffset = this->buffer.size() / this->channels;
    if (offset <= maxOffset) {
        this->index = offset * this->channels;
    }
}
