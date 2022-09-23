#include "CCombFilter.h"
#include <cstring>

CCombFilter::CCombFilter() {
    this->feedback = 0.0;
    this->buffer = nullptr;
    this->bufferSize = 0;
    this->bufferIndex = 0;
    this->filterStore = 0.0;
    this->damp = 0;
    this->damp2 = 0;
}

float CCombFilter::GetDamp() {
    return this->damp;
}

float CCombFilter::GetFeedback() {
    return this->feedback;
}

void CCombFilter::Mute() {
    memset(this->buffer, 0, this->bufferSize * sizeof(float));
}

float CCombFilter::Process(float sample) {
    float output = this->buffer[this->bufferIndex];
    this->filterStore = output * this->damp2 + this->filterStore * this->damp;
    this->buffer[this->bufferIndex] = sample + this->filterStore * this->feedback;
    this->bufferIndex++;
    if (this->bufferIndex >= this->bufferSize) {
        this->bufferIndex = 0;
    }
    return output;
}

void CCombFilter::SetBuffer(float *buffer, uint32_t size) {
    this->buffer = buffer;
    this->bufferSize = size;
    this->bufferIndex = 0;
}

void CCombFilter::SetDamp(float damp) {
    this->damp = damp;
    this->damp2 = 1 - damp;
}

void CCombFilter::SetFeedback(float feedback) {
    this->feedback = feedback;
}
