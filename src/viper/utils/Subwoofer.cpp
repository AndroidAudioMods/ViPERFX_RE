#include "Subwoofer.h"
#include "../constants.h"
#include <cmath>

Subwoofer::Subwoofer() {
    uint32_t samplingRate = VIPER_DEFAULT_SAMPLING_RATE;
    this->peak[0].RefreshFilter(MultiBiquad::FilterType::PEAK, 0.0, 37.0, samplingRate, 1.0, false);
    this->peak[1].RefreshFilter(MultiBiquad::FilterType::PEAK, 0.0, 37.0, samplingRate, 1.0, false);
    this->peakLow[0].RefreshFilter(MultiBiquad::FilterType::PEAK, 0.0, 75.0, samplingRate, 1.0, false);
    this->peakLow[1].RefreshFilter(MultiBiquad::FilterType::PEAK, 0.0, 75.0, samplingRate, 1.0, false);
    this->lowpass[0].RefreshFilter(MultiBiquad::FilterType::LOW_PASS, 0.0, 200.0, samplingRate, 1.0, false);
    this->lowpass[1].RefreshFilter(MultiBiquad::FilterType::LOW_PASS, 0.0, 200.0, samplingRate, 1.0, false);
}

void Subwoofer::Process(float *samples, uint32_t size) {
    for (uint32_t i = 0; i < size * 2; i += 2) {
        double tmp;

        tmp = this->peak[0].ProcessSample(samples[i]);
        tmp = this->peakLow[0].ProcessSample(tmp);
        tmp = this->lowpass[0].ProcessSample(tmp - samples[i]);
        samples[i] = (samples[i] * 0.5f) + ((float) tmp * 0.6f);

        tmp = this->peak[1].ProcessSample(samples[i + 1]);
        tmp = this->peakLow[1].ProcessSample(tmp);
        tmp = this->lowpass[1].ProcessSample(tmp - samples[i + 1]);
        samples[i + 1] = (samples[i + 1] * 0.5f) + ((float) tmp * 0.6f);
    }
}

void Subwoofer::SetBassGain(uint32_t samplingRate, float gainDb) {
    float gain = 20.0f * log10( gainDb);
    float gainLower = 20.0f * log10( gainDb / 8.0f);

    this->peak[0].RefreshFilter(MultiBiquad::FilterType::PEAK, gain, 44.0, samplingRate, 0.75, true);
    this->peak[1].RefreshFilter(MultiBiquad::FilterType::PEAK, gain, 44.0, samplingRate, 0.75, true);
    this->peakLow[0].RefreshFilter(MultiBiquad::FilterType::PEAK, gainLower, 80.0, samplingRate, 0.2, true);
    this->peakLow[1].RefreshFilter(MultiBiquad::FilterType::PEAK, gainLower, 80.0, samplingRate, 0.2, true);
    this->lowpass[0].RefreshFilter(MultiBiquad::FilterType::LOW_PASS, 0.0, 380.0, samplingRate, 0.6, false);
    this->lowpass[1].RefreshFilter(MultiBiquad::FilterType::LOW_PASS, 0.0, 380.0, samplingRate, 0.6, false);
}
