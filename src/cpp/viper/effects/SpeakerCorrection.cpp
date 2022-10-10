#include "SpeakerCorrection.h"
#include "../constants.h"

SpeakerCorrection::SpeakerCorrection() {
    this->samplingRate = DEFAULT_SAMPLERATE;
    this->enabled = false;
    Reset();
}

void SpeakerCorrection::Process(float *samples, uint32_t size) {
    if (this->enabled) {
        for (int i = 0; i < size * 2; i++) {
            float sample = samples[i];
            int index = i % 2;
            sample = this->lowpass[index].ProcessSample(sample);
            sample = this->highpass[index].ProcessSample(sample);
            float tmp = sample / 2.f;
            samples[i] = tmp + this->bandpass[index].ProcessSample(tmp);
        }
    }
}

void SpeakerCorrection::Reset() {
    this->lowpass[0].Reset();
    this->lowpass[1].Reset();
    this->bandpass[0].Reset();
    this->bandpass[1].Reset();

    this->highpass[0].RefreshFilter(MultiBiquad::FilterType::HIGHPASS, 0.f, 80.f, (float) this->samplingRate, 1.f, false);
    this->highpass[1].RefreshFilter(MultiBiquad::FilterType::HIGHPASS, 0.f, 80.f, (float) this->samplingRate, 1.f, false);
    this->lowpass[0].SetLowPassParameter(13500.f, this->samplingRate, 1.0);
    this->lowpass[1].SetLowPassParameter(13500.f, this->samplingRate, 1.0);
    this->bandpass[0].SetBandPassParameter(420.f, this->samplingRate, 3.88f);
    this->bandpass[1].SetBandPassParameter(420.f, this->samplingRate, 3.88f);
}

void SpeakerCorrection::SetEnable(bool enabled) {
    this->enabled = enabled;
    if (this->enabled) {
        Reset();
    }
}

void SpeakerCorrection::SetSamplingRate(uint32_t samplingRate) {
    this->samplingRate = samplingRate;
    Reset();
}

SpeakerCorrection::~SpeakerCorrection() {

}
