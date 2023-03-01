#include <cstring>
#include <cmath>
#include "Crossfeed.h"
#include "../constants.h"

// Basically Bauer-to-Stereophonic Binaural filter
// See: http://bs2b.sourceforge.net/
Crossfeed::Crossfeed() {
    this->a0_lo = 0.f;
    this->b1_lo = 0.f;
    this->a0_hi = 0.f;
    this->a1_hi = 0.f;
    this->b1_hi = 0.f;
    this->gain = 0.f;
    memset(&this->lfs, 0, 6 * sizeof(float));
    this->samplingRate = VIPER_DEFAULT_SAMPLING_RATE;
    this->preset.cutoff = 700;
    this->preset.feedback = 45;
}

#define lo_filter(in, out_1) (this->a0_lo * (in) + this->b1_lo * (out_1))
#define hi_filter(in, in_1, out_1) (this->a0_hi * (in) + this->a1_hi * (in_1) + this->b1_hi * (out_1))

void Crossfeed::FilterSample(float *sample) {
    this->lfs.lo[0] = lo_filter(sample[0], this->lfs.lo[0]);
    this->lfs.lo[1] = lo_filter(sample[1], this->lfs.lo[1]);

    this->lfs.hi[0] = hi_filter(sample[0], this->lfs.asis[0], this->lfs.hi[0]);
    this->lfs.hi[1] = hi_filter(sample[1], this->lfs.asis[1], this->lfs.hi[1]);
    this->lfs.asis[0] = sample[0];
    this->lfs.asis[1] = sample[1];

    sample[0] = (this->lfs.hi[0] + this->lfs.lo[1]) * this->gain;
    sample[1] = (this->lfs.hi[1] + this->lfs.lo[0]) * this->gain;
}

uint16_t Crossfeed::GetCutoff() {
    return this->preset.cutoff;
}

float Crossfeed::GetFeedback() {
    return (float) this->preset.feedback / 10.0f;
}

float Crossfeed::GetLevelDelay() {
    if (this->preset.cutoff <= 1800) { // TODO: Previous version reports <= 2000
        return (float) ((18700.0 / (double) this->preset.cutoff) * 10.0);
    } else {
        return 0.0;
    }
}

struct Crossfeed::Preset Crossfeed::GetPreset() {
    return this->preset;
}

void Crossfeed::ProcessFrames(float *buffer, uint32_t size) {
    for (uint32_t i = 0; i < size * 2; i += 2) {
        FilterSample(buffer + i);
    }
}

void Crossfeed::Reset() {
    uint16_t cutoff = this->preset.cutoff;
    uint16_t level = this->preset.feedback;

    level /= 10.0;

    double GB_lo = level * -5.0 / 6.0 - 3.0;
    double GB_hi = level / 6.0 - 3.0;

    double G_lo = pow(10, GB_lo / 20.0);
    double G_hi = 1.0 - pow(10, GB_hi / 20.0);
    double Fc_hi = cutoff * pow(2.0, (GB_lo - 20.0 * log10(G_hi)) / 12.0);

    double x = exp(-2.0 * M_PI * cutoff / this->samplingRate);
    this->b1_lo = (float) x;
    this->a0_lo = (float) (G_lo * (1.0 - x));

    x = exp(-2.0 * M_PI * Fc_hi / this->samplingRate);
    this->b1_hi = (float) x;
    this->a0_hi = (float) (1.0 - G_hi * (1.0 - x));
    this->a1_hi = (float) -x;

    this->gain = (float) (1.0 / (1.0 - G_hi + G_lo));
    memset(&this->lfs, 0, 6 * sizeof(float));
}

void Crossfeed::SetCutoff(uint16_t cutoff) {
    this->preset.cutoff = cutoff;
    Reset();
}

void Crossfeed::SetFeedback(float feedback) {
    this->preset.feedback = (uint16_t) (feedback * 10.0f);
    Reset();
}

void Crossfeed::SetPreset(struct Crossfeed::Preset preset) {
    this->preset = preset;
    Reset();
}

void Crossfeed::SetSamplingRate(uint32_t samplingRate) {
    if (this->samplingRate != samplingRate) {
        this->samplingRate = samplingRate;
        Reset();
    }
}
