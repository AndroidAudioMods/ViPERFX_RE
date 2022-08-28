//
// Created by mart on 7/30/21.
//

#include <cstring>
#include "AnalogX.h"
#include "../constants.h"

static float ANALOGX_HARMONICS[10] = {
        0.01f,
        0.02f,
        0.0001f,
        0.001f,
        0.f,
        0.f,
        0.f,
        0.f,
        0.f,
        0.f
};

AnalogX::AnalogX() {
    this->samplerate = DEFAULT_SAMPLERATE;
    this->processingModel = 0;
    this->enabled = false;
    Reset();
}

void AnalogX::Process(float *samples, uint32_t size) {
    for (int i = 0; i < 2 * size; i++) {
        float sample = samples[i];
        int index = i % 2;

        float tmp = this->highpass[index].ProcessSample(sample);
        tmp = this->harmonics[index].Process(tmp);

        tmp = this->lowpass[index].ProcessSample(sample + tmp * this->gain);
        tmp = this->peak->ProcessSample(tmp * 0.8f);

        samples[i] = tmp;
    }

    if (this->freqRange < this->samplerate / 4) {
        this->freqRange += size;
        memset(samples, 0, 2 * size * sizeof(float));
    }
}

void AnalogX::Reset() {
    this->highpass[0].RefreshFilter(FilterType::HIGHPASS, 0.f, 240.f, (float) this->samplerate, 0.717, false);
    this->highpass[1].RefreshFilter(FilterType::HIGHPASS, 0.f, 240.f, (float) this->samplerate, 0.717, false);

    this->peak[0].RefreshFilter(FilterType::PEAK, 0.58f, 633.f, (float) this->samplerate, 6.28, true);
    this->peak[1].RefreshFilter(FilterType::PEAK, 0.58f, 633.f, (float) this->samplerate, 6.28, true);

    this->harmonics[0].Reset();
    this->harmonics[1].Reset();

    if (this->processingModel == 0) {
        this->harmonics[0].SetHarmonics(ANALOGX_HARMONICS);
        this->harmonics[1].SetHarmonics(ANALOGX_HARMONICS);
        this->gain = 0.6f;
        this->lowpass[0].RefreshFilter(FilterType::LOWPASS, 0.0, 18233.f, (float) this->samplerate, 0.717f, false);
        this->lowpass[1].RefreshFilter(FilterType::LOWPASS, 0.0, 18233.f, (float) this->samplerate, 0.717f, false);
    } else if (this->processingModel == 1) {
        this->harmonics[0].SetHarmonics(ANALOGX_HARMONICS);
        this->harmonics[1].SetHarmonics(ANALOGX_HARMONICS);
        this->gain = 1.2f;
        this->lowpass[0].RefreshFilter(FilterType::LOWPASS, 0.0, 19650.f, (float) this->samplerate, 0.717f, false);
        this->lowpass[1].RefreshFilter(FilterType::LOWPASS, 0.0, 19650.f, (float) this->samplerate, 0.717f, false);
    } else if (this->processingModel == 2) {
        this->harmonics[0].SetHarmonics(ANALOGX_HARMONICS);
        this->harmonics[1].SetHarmonics(ANALOGX_HARMONICS);
        this->gain = 2.4f;
        this->lowpass[0].RefreshFilter(FilterType::LOWPASS, 0.0, 16307.f, (float) this->samplerate, 0.717f, false);
        this->lowpass[1].RefreshFilter(FilterType::LOWPASS, 0.0, 16307.f, (float) this->samplerate, 0.717f, false);
    }

    this->freqRange = 0;
}

void AnalogX::SetProcessingModel(int model) {
    this->processingModel = model;
    Reset();
}

void AnalogX::SetSamplingRate(uint32_t samplerate) {
    this->samplerate = samplerate;
    Reset();
}
