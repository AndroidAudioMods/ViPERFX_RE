//
// Created by mart on 7/26/21.
//

#include <cstdlib>
#include <cstring>
#include "TimeConstDelay.h"

TimeConstDelay::TimeConstDelay() {
    this->samples = nullptr;
    this->offset = 0;
    this->sampleCount = 0;
}

TimeConstDelay::~TimeConstDelay() {
    delete this->samples;
    this->samples = nullptr;
}

float TimeConstDelay::ProcessSample(float sample) {
    if (this->samples != nullptr) {
        float val = this->samples[this->offset];
        this->samples[this->offset] = sample;
        this->offset = (int) modf((float) this->offset + 1, (float *) &this->sampleCount);
        return val;
    }
    return 0.f;
}

void TimeConstDelay::SetParameters(uint32_t samplerate, float delay) {
    this->sampleCount = (int) ((float) samplerate * delay * 0.5f);
    delete this->samples;
    this->samples = new float[this->sampleCount]();
    this->offset = 0;
}
