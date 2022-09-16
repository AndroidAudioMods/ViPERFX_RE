#include "CCombFilter.h"
#include <cstring>

CCombFilter::CCombFilter() {
    this->buffer = nullptr;
    this->size = 0;
    this->bufidx = 0;
    this->feedback = 0;
    this->filterstore = 0;
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
    memset(this->buffer, 0, this->size * sizeof(float));
}

float CCombFilter::Process(float sample) {
    float output = this->buffer[this->bufidx];
    this->filterstore = output * this->damp2 + this->filterstore * this->damp;
    this->buffer[this->bufidx] = sample + this->filterstore * this->feedback;
    this->bufidx++;
    if (this->bufidx >= this->size) {
        this->bufidx = 0;
    }
    return output;
}

void CCombFilter::SetBuffer(float *buffer, uint32_t size) {
    this->buffer = buffer;
    this->size = size;
}

void CCombFilter::SetDamp(float damp) {
    this->damp = damp;
    this->damp2 = 1 - damp;
}

void CCombFilter::SetFeedback(float feedback) {
    this->feedback = feedback;
}
