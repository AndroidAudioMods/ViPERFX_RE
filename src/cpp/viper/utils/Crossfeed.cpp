//
// Created by mart on 7/26/21.
//

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
    this->samplerate = DEFAULT_SAMPLERATE;
    this->preset.cutoff = 700;
    this->preset.feedback = 45;
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

    double x = exp(-2.0 * M_PI * cutoff / this->samplerate);
    this->b1_lo = (float) x;
    this->a0_lo = (float) (G_lo * (1.0 - x));

    x = exp(-2.0 * M_PI * Fc_hi / this->samplerate);
    this->b1_hi = (float) x;
    this->a0_hi = (float) (1.0 - G_hi * (1.0 - x));
    this->a1_hi = (float) -x;

    this->gain = (float) (1.0 / (1.0 - G_hi + G_lo));
    memset(&this->lfs, 0, 6 * sizeof(float));
}

void Crossfeed::ProcessFrames(float *buffer, uint32_t size) {
    for (int x = 0; x < size; x += 2) {
        FilterSample(&buffer[x]);
    }
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
    return (float) this->preset.feedback / 10.f;
}

float Crossfeed::GetLevelDelay() {
    if (this->preset.cutoff <= 1800) {
        return (18700.f / (float) this->preset.cutoff) * 10.f;
    } else {
        return 0.f;
    }
}

preset_t Crossfeed::GetPreset() {
    return this->preset;
}

void Crossfeed::SetCutoff(uint16_t cutoff) {
    this->preset.cutoff = cutoff;
    Reset();
}

void Crossfeed::SetFeedback(float feedback) {
    this->preset.feedback = (uint16_t) (feedback * 10);
    Reset();
}

void Crossfeed::SetPreset(preset_t preset) {
    this->preset = preset;
    Reset();
}

void Crossfeed::SetSamplingRate(uint32_t samplerate) {
    this->samplerate = samplerate;
    Reset();
}
