#include "Subwoofer.h"
#include "../constants.h"
#include <cmath>

Subwoofer::Subwoofer() {
    float samplerate = (float) DEFAULT_SAMPLERATE;
    this->peak[0].RefreshFilter(FilterType::PEAK, 0.f, 37.f, samplerate, 1.f, false);
    this->peak[1].RefreshFilter(FilterType::PEAK, 0.f, 37.f, samplerate, 1.f, false);
    this->peakLow[0].RefreshFilter(FilterType::PEAK, 0.f, 75.f, samplerate, 1.f, false);
    this->peakLow[1].RefreshFilter(FilterType::PEAK, 0.f, 75.f, samplerate, 1.f, false);
    this->lowpass[0].RefreshFilter(FilterType::LOWPASS, 0.f, 200.f, samplerate, 1.f, false);
    this->lowpass[1].RefreshFilter(FilterType::LOWPASS, 0.f, 200.f, samplerate, 1.f, false);
}

void Subwoofer::Process(float *samples, uint32_t size) {
    for (int i = 0; i < size * 2; i++) {
        float sample = samples[i];
        int index = i % 2;
        float tmp = this->peak[index].ProcessSample(sample);
        tmp = this->peakLow[index].ProcessSample(tmp);
        tmp = this->lowpass[index].ProcessSample(tmp - sample);
        samples[i] = (sample / 2.f) + (tmp * 0.6f);
    }
}

void Subwoofer::SetBassGain(uint32_t samplerate, float gainDb) {
    float gain = 20.f * log10f(gainDb);
    float gainLower = 20.f * log10f(gainDb / 8.f);

    this->peak[0].RefreshFilter(FilterType::PEAK, gain, 44.f, (float) samplerate, 0.75, true);
    this->peak[1].RefreshFilter(FilterType::PEAK, gain, 44.f, (float) samplerate, 0.75, true);
    this->peakLow[0].RefreshFilter(FilterType::PEAK, gainLower, 80.f, (float) samplerate, 0.2, true);
    this->peakLow[1].RefreshFilter(FilterType::PEAK, gainLower, 80.f, (float) samplerate, 0.2, true);
    this->lowpass[0].RefreshFilter(FilterType::LOWPASS, 0.f, 380.f, (float) samplerate, 0.6, false);
    this->lowpass[1].RefreshFilter(FilterType::LOWPASS, 0.f, 380.f, (float) samplerate, 0.6, false);
}
