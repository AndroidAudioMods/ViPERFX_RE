//
// Created by mart on 7/28/21.
//

#include <cmath>
#include "HighShelf.h"

float HighShelf::Process(float sample) {
    float out = sample * this->b0 + this->x_1 * this->b1 + this->x_2 * this->b2 + this->y_1 * this->a1 +
                this->y_2 * this->a2;
    this->y_2 = this->y_1;
    this->y_1 = out;
    this->x_2 = this->x_1;
    this->x_1 = sample;
    return out;
}

void HighShelf::SetFrequency(uint32_t freq) {
    this->frequency = freq;
}

void HighShelf::SetGain(float gain) {
    this->gain = 20.f * log10f(gain);
}

void HighShelf::SetQuality(float q) {
    this->quality = q;
}

void HighShelf::SetSamplingRate(uint32_t samplerate) {
    this->samplerate = samplerate;
}
