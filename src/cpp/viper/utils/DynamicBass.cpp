#include "DynamicBass.h"
#include "../constants.h"

DynamicBass::DynamicBass() {
    this->qPeak = 0;
    SetSamplingRate(VIPER_DEFAULT_SAMPLING_RATE);
    this->bassGain = 1.f;
    this->sideGainX = 1.f;
    this->sideGainY = 1.f;
    this->lowFreqX = 120;
    this->highFreqX = 80;
    this->lowFreqY = 40;
    this->highFreqY = (uint32_t) ((float) this->samplingRate / 4.0f);

    this->filterX.SetPassFilter(this->lowFreqX, this->highFreqX);
    this->filterY.SetPassFilter(this->lowFreqY, this->highFreqY);
    this->lowPass.SetLowPassParameter(55.f, this->samplingRate, this->qPeak / 666.f + 0.5f);
}

void DynamicBass::FilterSamples(float *samples, uint32_t size) {
    if (this->lowFreqX <= 120) {
        for (int i = 0; i < size; i++) {
            float left = samples[2 * i];
            float right = samples[2 * i + 1];
            float avg = (float) this->lowPass.ProcessSample(left + right);
            samples[2 * i] = left + avg;
            samples[2 * i + 1] = right + avg;
        }
    } else {
        for (int i = 0; i < size; i++) {
            float x1, x2, x3, x4, x5, x6, y1, y2, y3, y4, y5, y6;

            this->filterX.DoFilterLeft(samples[2 * i], &x1, &x2, &x3);
            this->filterX.DoFilterRight(samples[2 * i + 1], &x4, &x5, &x6);
            this->filterY.DoFilterLeft(this->bassGain * x1, &y1, &y2, &y3);
            this->filterY.DoFilterRight(this->bassGain * x4, &y4, &y5, &y6);

            samples[2 * i] = x2 + y3 + this->sideGainX * y2 + this->sideGainY * y1 + x3;
            samples[2 * i + 1] = x5 + y6 + this->sideGainX * y5 + this->sideGainY * y4 + x6;
        }
    }
}

void DynamicBass::Reset() {
    this->filterX.Reset();
    this->filterY.Reset();
    this->lowPass.SetLowPassParameter(55.0, this->samplingRate, this->qPeak / 666.0f + 0.5f);
}

void DynamicBass::SetBassGain(float gain) {
    this->bassGain = gain;

    double x = ((gain - 1.0) / 20.0) * 1600.0;
    if (x > 1600.0) {
        x = 1600.0;
    }
    this->qPeak = (float) x;

    this->lowPass.SetLowPassParameter(55.0, this->samplingRate, this->qPeak / 666.0f + 0.5f);
}

void DynamicBass::SetFilterXPassFrequency(uint32_t low, uint32_t high) {
    this->lowFreqX = low;
    this->highFreqX = high;

    this->filterX.SetPassFilter(low, high);
    this->filterX.SetSamplingRate(this->samplingRate);
    this->lowPass.SetLowPassParameter(55.0, this->samplingRate, this->qPeak / 666.0f + 0.5f);
}

void DynamicBass::SetFilterYPassFrequency(uint32_t low, uint32_t high) {
    this->lowFreqY = low;
    this->highFreqY = high;

    this->filterY.SetPassFilter(low, high);
    this->filterY.SetSamplingRate(this->samplingRate);
    this->lowPass.SetLowPassParameter(55.0, this->samplingRate, this->qPeak / 666.0f + 0.5f);
}

void DynamicBass::SetSamplingRate(uint32_t samplingRate) {
    this->samplingRate = samplingRate;
    this->filterX.SetSamplingRate(samplingRate);
    this->filterY.SetSamplingRate(samplingRate);
    this->lowPass.SetLowPassParameter(55.0, samplingRate, this->qPeak / 666.0f + 0.5f);
}

void DynamicBass::SetSideGain(float gainX, float gainY) {
    this->sideGainX = gainX;
    this->sideGainY = gainY;
}
