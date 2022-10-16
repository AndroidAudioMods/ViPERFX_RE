#include "AnalogX.h"
#include <cstring>
#include "../constants.h"

static const float ANALOGX_HARMONICS[] = {
        0.01,
        0.02,
        0.0001,
        0.001,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0
};

AnalogX::AnalogX() {
    this->samplingRate = VIPER_DEFAULT_SAMPLING_RATE;
    this->processingModel = 0;
    this->enable = false;
    Reset();
}

void AnalogX::Process(float *samples, uint32_t size) {
    if (this->enable) {
        for (uint32_t i = 0; i < size * 2; i += 2) {
            double inL = samples[i];
            double outL = this->highPass[0].ProcessSample(inL);
            outL = this->harmonic[0].Process(outL);
            outL = this->lowPass[0].ProcessSample(inL + outL * this->gain);
            outL = this->peak[0].ProcessSample(outL * 0.8);
            samples[i] = (float) outL;

            double inR = samples[i + 1];
            double outR = this->highPass[1].ProcessSample(inR);
            outR = this->harmonic[1].Process(outR);
            outR = this->lowPass[1].ProcessSample(inR + outR * this->gain);
            outR = this->peak[1].ProcessSample(outR * 0.8);
            samples[i + 1] = (float) outR;
        }

        if (this->freqRange < this->samplingRate / 4) {
            this->freqRange += size;
            memset(samples, 0, size * 2 * sizeof(float));
        }
    }
}

void AnalogX::Reset() {
    this->highPass[0].RefreshFilter(MultiBiquad::FilterType::HIGH_PASS, 0.0, 240.0, this->samplingRate, 0.717, false);
    this->highPass[1].RefreshFilter(MultiBiquad::FilterType::HIGH_PASS, 0.0, 240.0, this->samplingRate, 0.717, false);

    this->peak[0].RefreshFilter(MultiBiquad::FilterType::PEAK, 0.58, 633.0, this->samplingRate, 6.28, true);
    this->peak[1].RefreshFilter(MultiBiquad::FilterType::PEAK, 0.58, 633.0, this->samplingRate, 6.28, true);

    this->harmonic[0].Reset();
    this->harmonic[1].Reset();

    switch (this->processingModel) {
        case 0: {
            this->harmonic[0].SetHarmonics(ANALOGX_HARMONICS);
            this->harmonic[1].SetHarmonics(ANALOGX_HARMONICS);

            this->gain = 0.6;

            this->lowPass[0].RefreshFilter(MultiBiquad::FilterType::LOW_PASS, 0.0, 19650.0, this->samplingRate, 0.717, false);
            this->lowPass[1].RefreshFilter(MultiBiquad::FilterType::LOW_PASS, 0.0, 19650.0, this->samplingRate, 0.717, false);
            break;
        }
        case 1: {
            this->harmonic[0].SetHarmonics(ANALOGX_HARMONICS);
            this->harmonic[1].SetHarmonics(ANALOGX_HARMONICS);

            this->gain = 1.2;

            this->lowPass[0].RefreshFilter(MultiBiquad::FilterType::LOW_PASS, 0.0, 18233.0, this->samplingRate, 0.717, false);
            this->lowPass[1].RefreshFilter(MultiBiquad::FilterType::LOW_PASS, 0.0, 18233.0, this->samplingRate, 0.717, false);
            break;
        }
        case 2: {
            this->harmonic[0].SetHarmonics(ANALOGX_HARMONICS);
            this->harmonic[1].SetHarmonics(ANALOGX_HARMONICS);

            this->gain = 2.4;

            this->lowPass[0].RefreshFilter(MultiBiquad::FilterType::LOW_PASS, 0.0, 16307.0, this->samplingRate, 0.717, false);
            this->lowPass[1].RefreshFilter(MultiBiquad::FilterType::LOW_PASS, 0.0, 16307.0, this->samplingRate, 0.717, false);
            break;
        }
    }

    this->freqRange = 0;
}

void AnalogX::SetEnable(bool enable) {
    if (this->enable != enable) {
        if (!this->enable) {
            Reset();
        }
        this->enable = enable;
    }
}

void AnalogX::SetProcessingModel(int processingModel) {
    if (this->processingModel != processingModel) {
        this->processingModel = processingModel;
        Reset();
    }
}

void AnalogX::SetSamplingRate(uint32_t samplingRate) {
    if (this->samplingRate != samplingRate) {
        this->samplingRate = samplingRate;
        Reset();
    }
}
