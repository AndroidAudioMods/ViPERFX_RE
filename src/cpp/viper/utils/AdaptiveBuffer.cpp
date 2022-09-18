#include <cstring>
#include "AdaptiveBuffer.h"

FIREqualizer::FIREqualizer(uint32_t channels, uint32_t length) {
    this->channels = channels;
    this->buffer = nullptr;
    this->length = 0;
    this->offset = 0;
    if (channels != 0) {
        this->buffer = new float[channels * length];
        this->length = length;
    }
}

FIREqualizer::~FIREqualizer() {
    delete this->buffer;
    this->buffer = nullptr;
}

void FIREqualizer::FlushBuffer() {
    this->offset = 0;
}

uint32_t FIREqualizer::GetBufferLength() const {
    return this->length;
}

uint32_t FIREqualizer::GetBufferOffset() const {
    return this->offset;
}

float *FIREqualizer::GetBufferPointer() const {
    return this->buffer;
}

uint32_t FIREqualizer::GetChannels() const {
    return this->channels;
}

void FIREqualizer::PanFrames(float left, float right) {
    if (this->buffer != nullptr && this->channels == 2) {
        for (int i = 0; i < this->offset * this->channels; i++) {
            if (i % 2 == 0) {
                this->buffer[i] = this->buffer[i] * left;
            } else {
                this->buffer[i] = this->buffer[i] * right;
            }
        }
    }
}

int FIREqualizer::PopFrames(float *frames, uint32_t length) {
    if (this->buffer == nullptr || this->offset < length) {
        return 0;
    }

    if (length != 0) {
        memcpy(frames, this->buffer, length * this->channels * sizeof(*frames));
        this->offset = this->offset - length;
        if (this->offset != 0) {
            memmove(this->buffer, &this->buffer[length * this->channels], this->offset * this->channels * sizeof(float));
        }
    }

    return 1;
}

int FIREqualizer::PushFrames(const float *frames, uint32_t length) {
    if (this->buffer == nullptr) {
        return 0;
    }

    if (length != 0) {
        if (this->offset + length > this->length) {
            auto tmp = new float[(this->offset + length) * this->channels];
            memcpy(tmp, this->buffer, this->offset * this->channels * sizeof(float));
            delete this->buffer;
            this->buffer = tmp;
            this->length = this->offset + length;
        }

        memcpy(&this->buffer[this->offset * this->channels], frames, length * this->channels * sizeof(float));
        this->offset = this->offset + length;
    }

    return 1;
}

int FIREqualizer::PushZero(uint32_t length) {
    if (this->buffer == nullptr) {
        return 0;
    }

    if (this->offset + length > this->length) {
        auto tmp = new float[(this->offset + length) * this->channels];
        memcpy(tmp, this->buffer, this->offset * this->channels * sizeof(float));
        delete this->buffer;
        this->buffer = tmp;
        this->length = this->offset + length;
    }

    memset(&this->buffer[this->offset * this->channels], 0, length * this->channels * sizeof(float));
    this->offset = this->offset + length;

    return 1;
}

void FIREqualizer::ScaleFrames(float scale) {
    if (this->buffer != nullptr) {
        for (uint32_t i = 0; i < this->offset * this->channels; i++) {
            this->buffer[i] = this->buffer[i] * scale;
        }
    }
}

void FIREqualizer::SetBufferOffset(uint32_t offset) {
    this->offset = offset;
}
