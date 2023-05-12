#include <cstring>
#include "AdaptiveBuffer.h"

AdaptiveBuffer::AdaptiveBuffer(uint32_t channels, uint32_t length) {
    this->channels = channels;
    this->length = length;
    this->buffer = std::vector<float>(channels * length);
    this->offset = 0;
}

void AdaptiveBuffer::FlushBuffer() {
    this->offset = 0;
}

uint32_t AdaptiveBuffer::GetBufferLength() const {
    return this->length;
}

uint32_t AdaptiveBuffer::GetBufferOffset() const {
    return this->offset;
}

float *AdaptiveBuffer::GetBuffer() {
    return this->buffer.data();
}

uint32_t AdaptiveBuffer::GetChannels() const {
    return this->channels;
}

void AdaptiveBuffer::PanFrames(float left, float right) {
    if (this->channels == 2) {
        for (uint32_t i = 0; i < this->offset * this->channels; i++) {
            if (i % 2 == 0) {
                this->buffer[i] = this->buffer[i] * left;
            } else {
                this->buffer[i] = this->buffer[i] * right;
            }
        }
    }
}

int AdaptiveBuffer::PopFrames(float *frames, uint32_t length) {
    if (this->offset < length) {
        return 0;
    }

    if (length != 0) {
        memcpy(frames, this->buffer.data(), length * this->channels * sizeof(float));
        this->offset = this->offset - length;
        if (this->offset != 0) {
            memmove(this->buffer.data(), this->buffer.data() + (length * this->channels), this->offset * this->channels * sizeof(float));
        }
    }

    return 1;
}

int AdaptiveBuffer::PushFrames(const float *frames, uint32_t length) {
    if (length != 0) {
        if (this->offset + length > this->length) {
            buffer.resize((this->offset + length) * this->channels);
            this->length = this->offset + length;
        }

        memcpy(this->buffer.data() + (this->offset * this->channels), frames, length * this->channels * sizeof(float));
        this->offset = this->offset + length;
    }

    return 1;
}

int AdaptiveBuffer::PushZero(uint32_t length) {
    if (this->offset + length > this->length) {
        buffer.resize((this->offset + length) * this->channels);
        this->length = this->offset + length;
    }

    memset(this->buffer.data() + (this->offset * this->channels), 0, length * this->channels * sizeof(float));
    this->offset = this->offset + length;

    return 1;
}

void AdaptiveBuffer::ScaleFrames(float scale) {
    for (uint32_t i = 0; i < this->offset * this->channels; i++) {
        this->buffer[i] = this->buffer[i] * scale;
    }
}

void AdaptiveBuffer::SetBufferOffset(uint32_t offset) {
    this->offset = offset;
}
