//
// Created by mart on 7/28/21.
//

#include "DynamicBass.h"
#include "../constants.h"

DynamicBass::DynamicBass() {
    this->qPeak = 0;
    SetSamplingRate(DEFAULT_SAMPLERATE);
    this->bassGain = 1.f;
    this->sideGainX = 1.f;
    this->sideGainY = 1.f;
    this->lowFreqX = 120;
    this->highFreqX = 80;
    this->lowFreqY = 40;
    this->highFreqY = (float)this->samplerate / 4.f;

    this->filterX.SetPassFilter(this->lowFreqX, this->highFreqX);
    this->filterY.SetPassFilter(this->lowFreqY, this->highFreqY);
    this->lowPass.SetLowPassParameter(55.f, this->samplerate, this->qPeak / 666.f + 0.5f);
}

void DynamicBass::Reset() {
    this->filterX.Reset();
    this->filterY.Reset();
    this->lowPass.SetLowPassParameter(55.f, this->samplerate, this->qPeak / 666.f + 0.5f);
}

void DynamicBass::FilterSamples(float *samples, uint32_t size) {
    if (this->lowFreqX <= 120) {
        for (int i = 0; i < size; i++) {
            float left = samples[2*i];
            float right = samples[2*i+1];
            float avg = this->lowPass.ProcessSample(left + right);
            samples[2*i] = left + avg;
            samples[2*i+1] = right + avg;
        }
    } else {
        for (int i = 0; i < size; i++) {
            float x1, x2, x3, x4, x5, x6, y1, y2, y3, y4, y5, y6;

            this->filterX.DoFilterLeft(samples[2*i], &x1, &x2, &x3);
            this->filterX.DoFilterRight(samples[2*i+1], &x4, &x5, &x6);
            this->filterY.DoFilterLeft(this->bassGain * x1, &y1, &y2, &y3);
            this->filterY.DoFilterRight(this->bassGain * x4, &y4, &y5, &y6);

            samples[2*i] = x2 + y3 + this->sideGainX * y2 + this->sideGainY * y1 + x3;
            samples[2*i+1] = x5 + y6 + this->sideGainX * y5 + this->sideGainY * y4 + x6;
        }
    }
}

void DynamicBass::SetBassGain(float gain) {
    this->bassGain = gain;
    this->qPeak = (gain - 1.f) / 20.f * 1600.f;
    if (this->qPeak > 1600.f) {
        this->qPeak = 1600.f;
    }
    this->lowPass.SetLowPassParameter(55.f, this->samplerate, this->qPeak / 666.f + 0.5f);
}

void DynamicBass::SetSideGain(float gainX, float gainY) {
    this->sideGainX = gainX;
    this->sideGainY = gainY;
}

void DynamicBass::SetFilterXPassFrequency(uint32_t low, uint32_t high) {
    this->lowFreqX = low;
    this->highFreqX = high;

    this->filterX.SetPassFilter(low, high);
    this->filterX.SetSamplingRate(this->samplerate);
    this->lowPass.SetLowPassParameter(55.f, this->samplerate, this->qPeak / 666.f + 0.5f);
}

void DynamicBass::SetFilterYPassFrequency(uint32_t low, uint32_t high) {
    this->lowFreqY = low;
    this->highFreqY = high;

    this->filterY.SetPassFilter(low, high);
    this->filterY.SetSamplingRate(this->samplerate);
    this->lowPass.SetLowPassParameter(55.f, this->samplerate, this->qPeak / 666.f + 0.5f);
}

void DynamicBass::SetSamplingRate(uint32_t samplerate) {
    this->samplerate = samplerate;
    this->filterX.SetSamplingRate(samplerate);
    this->filterY.SetSamplingRate(samplerate);
    this->lowPass.SetLowPassParameter(55.f, samplerate, this->qPeak / 666.f + 0.5f);
}
