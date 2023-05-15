#include "TimeConstDelay.h"
#include <cmath>

TimeConstDelay::TimeConstDelay() {
    this->offset = 0;
    this->sampleCount = 0;
}

float TimeConstDelay::ProcessSample(float sample) {
    float val = this->samples[this->offset];
    this->samples[this->offset] = sample;
    this->offset = (uint32_t) modff((float) this->offset + 1, (float *) &this->sampleCount); // TODO: check if this is correct
    return val;
}

void TimeConstDelay::SetParameters(uint32_t samplingRate, float delay) {
    this->sampleCount = (uint32_t) ((float) samplingRate * delay);
    this->samples.resize(this->sampleCount);
    this->offset = 0;
}
