//
// Created by mart on 7/30/21.
//

#include "SpeakerCorrection.h"
#include "../constants.h"

SpeakerCorrection::SpeakerCorrection() {
    this->samplerate = DEFAULT_SAMPLERATE;
    this->enabled = false;
    Reset();
}

void SpeakerCorrection::Process(float *samples, uint32_t size) {
    for (int i = 0; i < size * 2; i++) {
        float sample = samples[i];
        int index = i % 2;
        sample = this->lowpass[index].ProcessSample(sample);
        sample = this->highpass[index].ProcessSample(sample);
        float tmp = sample / 2.f;
        samples[i] = tmp + this->bandpass[index].ProcessSample(tmp);
    }
}

void SpeakerCorrection::Reset() {
    this->lowpass[0].Reset();
    this->lowpass[1].Reset();
    this->bandpass[0].Reset();
    this->bandpass[1].Reset();

    this->highpass[0].RefreshFilter(FilterType::HIGHPASS, 0.f, 80.f, (float)this->samplerate, 1.f, false);
    this->highpass[1].RefreshFilter(FilterType::HIGHPASS, 0.f, 80.f, (float)this->samplerate, 1.f, false);
    this->lowpass[0].SetLowPassParameter(13500.f, this->samplerate, 1.0);
    this->lowpass[1].SetLowPassParameter(13500.f, this->samplerate, 1.0);
    this->bandpass[0].SetBandPassParameter(420.f, this->samplerate, 3.88f);
    this->bandpass[1].SetBandPassParameter(420.f, this->samplerate, 3.88f);
}

void SpeakerCorrection::SetEnable(bool enabled) {
    this->enabled = enabled;
    Reset();
}

void SpeakerCorrection::SetSamplingRate(uint32_t samplerate) {
    this->samplerate = samplerate;
    Reset();
}
