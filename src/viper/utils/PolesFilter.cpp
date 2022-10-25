#include "PolesFilter.h"
#include "../constants.h"
#include <cstring>
#include <cmath>

PolesFilter::PolesFilter() {
    this->samplingRate = VIPER_DEFAULT_SAMPLING_RATE;
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

    this->channels[0].lower_angle = (float) this->lower_freq * (float) M_PI / (float) this->samplingRate;
    this->channels[1].lower_angle = (float) this->lower_freq * (float) M_PI / (float) this->samplingRate;
    this->channels[0].upper_angle = (float) this->upper_freq * (float) M_PI / (float) this->samplingRate;
    this->channels[1].upper_angle = (float) this->upper_freq * (float) M_PI / (float) this->samplingRate;
}

static inline void DoFilterSide(channel *side, float sample, float *out1, float *out2, float *out3) {
    float oldestSampleIn = side->in[2];
    side->in[2] = side->in[1];
    side->in[1] = side->in[0];
    side->in[0] = sample;

    side->x[0] += side->lower_angle * (sample - side->x[0]);
    side->x[1] += side->lower_angle * (side->x[0] - side->x[1]);
    side->x[2] += side->lower_angle * (side->x[1] - side->x[2]);
    side->x[3] += side->lower_angle * (side->x[2] - side->x[3]);

    side->y[0] += side->upper_angle * (sample - side->y[0]);
    side->y[1] += side->upper_angle * (side->y[0] - side->y[1]);
    side->y[2] += side->upper_angle * (side->y[1] - side->y[2]);
    side->y[3] += side->upper_angle * (side->y[2] - side->y[3]);

    *out1 = side->x[3];
    *out2 = oldestSampleIn - side->y[3];
    *out3 = side->y[3] - side->x[3];
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

void PolesFilter::SetSamplingRate(uint32_t samplingRate) {
    this->samplingRate = samplingRate;
    UpdateCoeff();
}