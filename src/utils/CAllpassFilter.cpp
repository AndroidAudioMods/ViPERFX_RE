//
// Created by mart on 7/26/21.
//

#include <cstring>
#include "CAllpassFilter.h"

CAllpassFilter::CAllpassFilter() {
    this->buffer = nullptr;
    this->bufidx = 0;
    this->bufsize = 0;
    this->feedback = 0;
}

void CAllpassFilter::Mute() {
    memset(this->buffer, 0, this->bufsize * sizeof(float))
}

float CAllpassFilter::Process(float sample) {
    float outSample = this->buffer[this->bufidx];
    this->buffer[this->bufidx] = sample + (outSample * this->feedback);
    this->bufidx++;
    if (this->bufidx >= this->bufsize) {
        this->bufidx = 0;
    }
    return outSample - sample;
}

float CAllpassFilter::GetFeedback() {
    return this->feedback;
}

void CAllpassFilter::SetBuffer(float *buffer, uint32_t size) {
    this->buffer = buffer;
    this->bufsize = size;
}

void CAllpassFilter::SetFeedback(float feedback) {
    this->feedback = feedback;
}
