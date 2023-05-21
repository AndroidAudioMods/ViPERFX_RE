#include "ViPERDDC.h"
#include "../../log.h"
#include "../constants.h"
#include <cstring>

ViPERDDC::ViPERDDC() :
    enable(false),
    setCoeffsOk(false),
    samplingRate(VIPER_DEFAULT_SAMPLING_RATE),
    arrSize(0) {}

void ViPERDDC::Process(float *samples, uint32_t size) {
    if (!this->setCoeffsOk || this->arrSize == 0) return;
    if (!this->enable) return;

    std::vector<std::array<float, 5>> *coeffsArr;

    switch (this->samplingRate) {
        case 44100: {
            coeffsArr = &this->coeffsArr44100;
            break;
        }
        case 48000: {
            coeffsArr = &this->coeffsArr48000;
            break;
        }
        default: {
            VIPER_LOGD("ViPERDDC::Process() -> Invalid sampling rate: %d", this->samplingRate);
            return;
        }
    }

    for (uint32_t i = 0; i < size * 2; i += 2) {
        float sampleL = samples[i];
        float sampleR = samples[i + 1];

        for (uint32_t j = 0; j < this->arrSize; j++) {
            std::array<float, 5> *coeffs = &(*coeffsArr)[j];

            float b0 = (*coeffs)[0];
            float b1 = (*coeffs)[1];
            float b2 = (*coeffs)[2];
            float a1 = (*coeffs)[3];
            float a2 = (*coeffs)[4];

            float outL =
                    sampleL * b0 +
                    x1L[j] * b1 +
                    x2L[j] * b2 +
                    y1L[j] * a1 +
                    y2L[j] * a2;

            x2L[j] = x1L[j];
            x1L[j] = sampleL;
            y2L[j] = y1L[j];
            y1L[j] = outL;

            sampleL = outL;

            float outR =
                    sampleR * b0 +
                    x1R[j] * b1 +
                    x2R[j] * b2 +
                    y1R[j] * a1 +
                    y2R[j] * a2;

            x2R[j] = x1R[j];
            x1R[j] = sampleR;
            y2R[j] = y1R[j];
            y1R[j] = outR;

            sampleR = outR;
        }

        samples[i] = sampleL;
        samples[i + 1] = sampleR;
    }
}

void ViPERDDC::ReleaseResources() {
    this->setCoeffsOk = false;

    this->coeffsArr44100.resize(0);
    this->coeffsArr48000.resize(0);

    this->x1L.resize(0);
    this->x1R.resize(0);
    this->x2L.resize(0);
    this->x2R.resize(0);
    this->y1L.resize(0);
    this->y1R.resize(0);
    this->y2L.resize(0);
    this->y2R.resize(0);
}

void ViPERDDC::Reset() {
    if (!this->setCoeffsOk) return;
    if (this->arrSize == 0) return;

    memset(this->x1L.data(), 0, this->arrSize * sizeof(float));
    memset(this->x1R.data(), 0, this->arrSize * sizeof(float));
}

void ViPERDDC::SetCoeffs(uint32_t newCoeffsSize, float *newCoeffs44100, float *newCoeffs48000) {
    ReleaseResources();

    if (newCoeffsSize == 0) return;

    this->arrSize = newCoeffsSize / 5;
    this->coeffsArr44100.resize(this->arrSize);
    this->coeffsArr48000.resize(this->arrSize);

    for (uint32_t i = 0; i < this->arrSize; i++) {
        this->coeffsArr44100[i][0] = newCoeffs44100[i * 5];
        this->coeffsArr44100[i][1] = newCoeffs44100[i * 5 + 1];
        this->coeffsArr44100[i][2] = newCoeffs44100[i * 5 + 2];
        this->coeffsArr44100[i][3] = newCoeffs44100[i * 5 + 3];
        this->coeffsArr44100[i][4] = newCoeffs44100[i * 5 + 4];

        this->coeffsArr48000[i][0] = newCoeffs48000[i * 5];
        this->coeffsArr48000[i][1] = newCoeffs48000[i * 5 + 1];
        this->coeffsArr48000[i][2] = newCoeffs48000[i * 5 + 2];
        this->coeffsArr48000[i][3] = newCoeffs48000[i * 5 + 3];
        this->coeffsArr48000[i][4] = newCoeffs48000[i * 5 + 4];
    }

    this->x1L.resize(this->arrSize);
    this->x1R.resize(this->arrSize);
    this->x2L.resize(this->arrSize);
    this->x2R.resize(this->arrSize);
    this->y1L.resize(this->arrSize);
    this->y1R.resize(this->arrSize);
    this->y2L.resize(this->arrSize);
    this->y2R.resize(this->arrSize);

    this->setCoeffsOk = true;
}

void ViPERDDC::SetEnable(bool enable) {
    if (this->enable != enable) {
        this->enable = enable;
        if (enable) {
            Reset();
        }
    }
}

void ViPERDDC::SetSamplingRate(uint32_t samplingRate) {
    if (this->samplingRate != samplingRate) {
        this->samplingRate = samplingRate;
        Reset();
    }
}
