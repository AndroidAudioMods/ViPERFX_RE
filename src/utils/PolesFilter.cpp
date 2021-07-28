//
// Created by mart on 7/28/21.
//

#include "PolesFilter.h"
#include "../constants.h"
#include <cstring>
#include <cmath>

PolesFilter::PolesFilter() {
    this->samplerate = DEFAULT_SAMPLERATE;
    this->lower_freq = 160;
    this->upper_freq = 8000;
    UpdateCoeff();
}

void PolesFilter::Reset() {
    UpdateCoeff();
}

void PolesFilter::UpdateCoeff() {
    memset(&this->channels[0], 0, sizeof(channel));
    memset(&this->channels[1], 0, sizeof(channel));

    this->channels[0].lower_angle = ((float)this->lower_freq * M_PI / (float)this->samplerate);
    this->channels[1].lower_angle = ((float)this->lower_freq * M_PI / (float)this->samplerate);
    this->channels[0].upper_angle = ((float)this->upper_freq * M_PI / (float)this->samplerate);
    this->channels[1].upper_angle = ((float)this->upper_freq * M_PI / (float)this->samplerate);
}

inline void DoFilterSide(channel* side, float sample, float* out1, float* out2, float* out3) {
    float oldestSampleIn = this->in[2];
    this->in[2] = this->in[1];
    this->in[1] = this->in[0];
    this->in[0] = sample;

    channel->x[0] += channel->lower_angle * (sample - channel->x[0]);
    channel->x[1] += channel->lower_angle * (channel->x[0] - channel->x[1]);
    channel->x[2] += channel->lower_angle * (channel->x[1] - channel->x[2]);
    channel->x[3] += channel->lower_angle * (channel->x[2] - channel->x[3]);

    channel->y[0] += channel->upper_angle * (sample - channel->y[0]);
    channel->y[1] += channel->upper_angle * (channel->y[0] - channel->y[1]);
    channel->y[2] += channel->upper_angle * (channel->y[1] - channel->y[2]);
    channel->y[3] += channel->upper_angle * (channel->y[2] - channel->y[3]);

    *out1 = channel->x[3];
    *out2 = oldestSampleIn - channel->y[3];
    *out3 = channel->y[3] - channel->x[3];
}

void PolesFilter::DoFilterLeft(float sample, float *out1, float *out2, float *out3) {
    DoFilterSide(&this->channels[0], sample, out1, out2, out3);
}

void PolesFilter::DoFilterRight(float sample, float *out1, float *out2, float *out3) {
    DoFilterSide(&this->channels[1], sample, out1, out2, out3);
}

void PolesFilter::SetPassFilter(uint32_t lower_freq, uint32_t upper_freq) {
    this->lower_freq = lower_freq;
    this->upper_freq = upper_freq;
    UpdateCoeff();
}

void PolesFilter::SetSamplingRate(uint32_t samplerate) {
    this->samplerate = samplerate;
    UpdateCoeff();
}