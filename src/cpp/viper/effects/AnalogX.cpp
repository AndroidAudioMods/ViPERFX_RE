#include "AnalogX.h"
#include <cstring>
#include "../constants.h"

static float ANALOGX_HARMONICS[10] = {
        0.01f,
        0.02f,
        0.0001f,
        0.001f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f
};

AnalogX::AnalogX() {
    this->samplingRate = DEFAULT_SAMPLERATE;
    this->processingModel = 0;
    this->enabled = false;
    Reset();
}

AnalogX::~AnalogX() {

}

void AnalogX::Process(float *samples, uint32_t size) {
    for (int i = 0; i < 2 * size; i++) {
        float sample = samples[i];
        int index = i % 2;

        float tmp = this->highpass[index].ProcessSample(sample);
        tmp = this->harmonic[index].Process(tmp);

        tmp = this->lowpass[index].ProcessSample(sample + tmp * this->gain);
        tmp = this->peak->ProcessSample(tmp * 0.8f);

        samples[i] = tmp;
    }

    if (this->freqRange < this->samplingRate / 4) {
        this->freqRange += size;
        memset(samples, 0, 2 * size * sizeof(float));
    }
}

void AnalogX::Reset() {
    for (auto &highpass : this->highpass) {
        highpass.RefreshFilter(MultiBiquad::FilterType::HIGHPASS, 0.0f, 240.0f, (float) this->samplingRate, 0.717f, false);
    }

    for (auto &peak : this->peak) {
        peak.RefreshFilter(MultiBiquad::FilterType::PEAK, 0.58f, 633.0f, (float) this->samplingRate, 6.28f, true);
    }

    for (auto &harmonic : this->harmonic) {
        harmonic.Reset();
    }

    if (this->processingModel == 0) {
        for (auto &harmonic : this->harmonic) {
            harmonic.SetHarmonics(ANALOGX_HARMONICS);
        }

        this->gain = 0.6f;

        for (auto &lowpass : this->lowpass) {
            lowpass.RefreshFilter(MultiBiquad::FilterType::LOWPASS, 0.0f, 19650.0f, (float) this->samplingRate, 0.717f, false);
        }
    } else if (this->processingModel == 1) {
        for (auto &harmonic : this->harmonic) {
            harmonic.SetHarmonics(ANALOGX_HARMONICS);
        }

        this->gain = 1.2f;

        for (auto &lowpass : this->lowpass) {
            lowpass.RefreshFilter(MultiBiquad::FilterType::LOWPASS, 0.0f, 18233.0f, (float) this->samplingRate, 0.717f, false);
        }
    } else if (this->processingModel == 2) {
        for (auto &harmonic : this->harmonic) {
            harmonic.SetHarmonics(ANALOGX_HARMONICS);
        }

        this->gain = 2.4f;

        for (auto &lowpass : this->lowpass) {
            lowpass.RefreshFilter(MultiBiquad::FilterType::LOWPASS, 0.0f, 16307.0f, (float) this->samplingRate, 0.717f, false);
        }
    }

    this->freqRange = 0;
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
