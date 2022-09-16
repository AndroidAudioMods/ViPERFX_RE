#include "SpectrumExtend.h"
#include "../constants.h"

static float SPECTRUM_HARMONICS[10] = {
        0.02f,
        0.f,
        0.02f,
        0.f,
        0.02f,
        0.f,
        0.02f,
        0.f,
        0.02f,
        0.f,
};

SpectrumExtend::SpectrumExtend() {
    this->samplerate = DEFAULT_SAMPLERATE;
    this->referenceFreq = 7600;
    this->enabled = false;
    this->exciter = 0.f;
    Reset();
}

SpectrumExtend::~SpectrumExtend() {
    // empty?
}

void SpectrumExtend::Process(float *samples, uint32_t size) {
    for (int i = 0; i < size * 2; i++) {
        float sample = samples[i];
        int index = i % 2;
        float tmp = this->highpass[index].ProcessSample(sample);
        tmp = this->harmonics[index].Process(tmp);
        tmp = this->lowpass[index].ProcessSample(tmp * this->exciter);
        samples[i] = samples[i] + tmp;
    }
}

void SpectrumExtend::Reset() {
    this->highpass[0].RefreshFilter(FilterType::HIGHPASS, 0.0, (float) this->referenceFreq, (float) this->samplerate,
                                    0.717, false);
    this->highpass[1].RefreshFilter(FilterType::HIGHPASS, 0.0, (float) this->referenceFreq, (float) this->samplerate,
                                    0.717, false);

    this->lowpass[0].RefreshFilter(FilterType::LOWPASS, 0.0, (float) this->referenceFreq / 2.f - 2000.f,
                                   (float) this->referenceFreq, 0.717, false);
    this->lowpass[1].RefreshFilter(FilterType::LOWPASS, 0.0, (float) this->referenceFreq / 2.f - 2000.f,
                                   (float) this->referenceFreq, 0.717, false);

    this->harmonics[0].Reset();
    this->harmonics[1].Reset();

    this->harmonics[0].SetHarmonics(SPECTRUM_HARMONICS);
    this->harmonics[1].SetHarmonics(SPECTRUM_HARMONICS);
}

void SpectrumExtend::SetEnable(bool enable) {
    this->enabled = enable;
}

void SpectrumExtend::SetExciter(float value) {
    this->exciter = value;
}

void SpectrumExtend::SetReferenceFrequency(uint32_t freq) {
    if (this->samplerate / 2 - 100 < freq) {
        freq = this->samplerate / 2 - 100;
    }
    this->referenceFreq = freq;
    Reset();
}

void SpectrumExtend::SetSamplingRate(uint32_t samplerate) {
    this->samplerate = samplerate;
    if (this->samplerate / 2 - 100 < this->referenceFreq) {
        this->referenceFreq = this->samplerate / 2 - 100;
    }
    Reset();
}
