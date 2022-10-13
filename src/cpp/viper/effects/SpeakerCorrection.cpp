#include "SpeakerCorrection.h"
#include "../constants.h"

SpeakerCorrection::SpeakerCorrection() {
    this->samplingRate = VIPER_DEFAULT_SAMPLING_RATE;
    this->enable = false;
    Reset();
}

void SpeakerCorrection::Process(float *samples, uint32_t size) {
    if (!this->enable) return;

    for (int i = 0; i < size * 2; i += 2) {
        double outL = samples[i];
        outL = this->lowPass[0].ProcessSample(outL);
        outL = this->highPass[0].ProcessSample(outL);
        outL /= 2.0;
        outL += this->bandPass[0].ProcessSample(outL);
        samples[i] = (float) outL;

        double outR = samples[i + 1];
        outR = this->lowPass[1].ProcessSample(outR);
        outR = this->highPass[1].ProcessSample(outR);
        outR /= 2.0;
        outR += this->bandPass[1].ProcessSample(outR);
        samples[i + 1] = (float) outR;
    }
}

void SpeakerCorrection::Reset() {
    this->lowPass[0].Reset();
    this->lowPass[1].Reset();
    this->bandPass[0].Reset();
    this->bandPass[1].Reset();

    this->highPass[0].RefreshFilter(MultiBiquad::FilterType::HIGHPASS, 0.0, 80.0, this->samplingRate, 1.0, false);
    this->highPass[1].RefreshFilter(MultiBiquad::FilterType::HIGHPASS, 0.0, 80.0, this->samplingRate, 1.0, false);
    this->lowPass[0].SetLowPassParameter(13500.0, this->samplingRate, 1.0);
    this->lowPass[1].SetLowPassParameter(13500.0, this->samplingRate, 1.0);
    this->bandPass[0].SetBandPassParameter(420.0, this->samplingRate, 3.88);
    this->bandPass[1].SetBandPassParameter(420.0, this->samplingRate, 3.88);
}

void SpeakerCorrection::SetEnable(bool enable) {
    if (this->enable != enable) {
        if (!this->enable) {
            Reset();
        }
        this->enable = enable;
    }
}

void SpeakerCorrection::SetSamplingRate(uint32_t samplingRate) {
    if (this->samplingRate != samplingRate) {
        this->samplingRate = samplingRate;
        Reset();
    }
}
