#include "Subwoofer.h"
#include "../constants.h"
#include <cmath>

Subwoofer::Subwoofer() {
    uint32_t samplingRate = DEFAULT_SAMPLERATE;
    this->peak[0].RefreshFilter(FilterType::PEAK, 0.0, 37.0, samplingRate, 1.0, false);
    this->peak[1].RefreshFilter(FilterType::PEAK, 0.0, 37.0, samplingRate, 1.0, false);
    this->peakLow[0].RefreshFilter(FilterType::PEAK, 0.0, 75.0, samplingRate, 1.0, false);
    this->peakLow[1].RefreshFilter(FilterType::PEAK, 0.0, 75.0, samplingRate, 1.0, false);
    this->lowpass[0].RefreshFilter(FilterType::LOWPASS, 0.0, 200.0, samplingRate, 1.0, false);
    this->lowpass[1].RefreshFilter(FilterType::LOWPASS, 0.0, 200.0, samplingRate, 1.0, false);
}

void Subwoofer::Process(float *samples, uint32_t size) {
    for (int i = 0; i < size * 2; i++) {
        auto sample = (double) samples[i];
        int index = i % 2;
        double tmp = this->peak[index].ProcessSample(sample);
        tmp = this->peakLow[index].ProcessSample(tmp);
        tmp = this->lowpass[index].ProcessSample(tmp - sample);
        samples[i] = (float) ((sample / 2.0) + (tmp * 0.6));
    }
}

void Subwoofer::SetBassGain(uint32_t samplingRate, float gainDb) {
    float gain = 20.0f * log10( gainDb);
    float gainLower = 20.0f * log10( gainDb / 8.0f);

    this->peak[0].RefreshFilter(FilterType::PEAK, gain, 44.0, samplingRate, 0.75, true);
    this->peak[1].RefreshFilter(FilterType::PEAK, gain, 44.0, samplingRate, 0.75, true);
    this->peakLow[0].RefreshFilter(FilterType::PEAK, gainLower, 80.0, samplingRate, 0.2, true);
    this->peakLow[1].RefreshFilter(FilterType::PEAK, gainLower, 80.0, samplingRate, 0.2, true);
    this->lowpass[0].RefreshFilter(FilterType::LOWPASS, 0.0, 380.0, samplingRate, 0.6, false);
    this->lowpass[1].RefreshFilter(FilterType::LOWPASS, 0.0, 380.0, samplingRate, 0.6, false);
}
