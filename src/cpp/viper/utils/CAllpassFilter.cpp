#include "CAllpassFilter.h"
#include <cstring>

CAllpassFilter::CAllpassFilter() {
    this->buffer = nullptr;
    this->feedback = 0.0;
    this->bufferIndex = 0;
    this->bufferSize = 0;
}

float CAllpassFilter::GetFeedback() {
    return this->feedback;
}

void CAllpassFilter::Mute() {
    memset(this->buffer, 0, this->bufferSize * sizeof(float));
}

float CAllpassFilter::Process(float sample) {
    float outSample = this->buffer[this->bufferIndex];
    this->buffer[this->bufferIndex] = sample + outSample * this->feedback;
    this->bufferIndex++;
    if (this->bufferIndex >= this->bufferSize) {
        this->bufferIndex = 0;
    }
    return outSample - sample;
}

void CAllpassFilter::SetBuffer(float *buffer, uint32_t size) {
    this->buffer = buffer;
    this->bufferSize = size;
    this->bufferIndex = 0;
}

void CAllpassFilter::SetFeedback(float feedback) {
    this->feedback = feedback;
}
