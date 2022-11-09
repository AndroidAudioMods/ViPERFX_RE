#include "ViPERDDC.h"
#include "../../log.h"
#include <cstring>

ViPERDDC::ViPERDDC() {
    this->enable = false;
    this->samplingRate = 44100;
    this->setCoeffsOk = false;
    this->arrSize = 0;
    this->coeffsArr44100 = nullptr;
    this->coeffsArr48000 = nullptr;
    this->x2R = nullptr;
    this->x2L = nullptr;
    this->x1R = nullptr;
    this->x1L = nullptr;
    this->y2R = nullptr;
    this->y2L = nullptr;
    this->y1R = nullptr;
    this->y1L = nullptr;
}

ViPERDDC::~ViPERDDC() {
    ReleaseResources();
}

void ViPERDDC::Process(float *samples, uint32_t size) {
    if (!this->setCoeffsOk) return;
    if (!this->enable) return;

    float **coeffsArr;

    switch (this->samplingRate) {
        case 44100: {
            coeffsArr = this->coeffsArr44100;
            break;
        }
        case 48000: {
            coeffsArr = this->coeffsArr48000;
            break;
        }
        default: {
            VIPER_LOGD("ViPERDDC::Process() -> Invalid sampling rate: %d", this->samplingRate);
            return;
        }
    }

    for (uint32_t i = 0; i < size * 2; i += 2) {
        if (this->arrSize == 0) {
            samples[i] = 0.0;
            samples[i + 1] = 0.0;
        } else {
            float sample = samples[i];
            for (uint32_t j = 0; j < this->arrSize; j++) {
                float *coeffs = coeffsArr[j];

                float b0 = coeffs[0];
                float b1 = coeffs[1];
                float b2 = coeffs[2];
                float a1 = coeffs[3];
                float a2 = coeffs[4];

                float out =
                        sample * b0 +
                        x1L[j] * b1 +
                        x2L[j] * b2 +
                        y1L[j] * a1 +
                        y2L[j] * a2;

                x2L[j] = x1L[j];
                x1L[j] = sample;
                y2L[j] = y1L[j];
                y1L[j] = out;

                sample = out;
            }
            samples[i] = sample;

            sample = samples[i + 1];
            for (uint32_t j = 0; j < this->arrSize; j++) {
                float *coeffs = coeffsArr[j];

                float b0 = coeffs[0];
                float b1 = coeffs[1];
                float b2 = coeffs[2];
                float a1 = coeffs[3];
                float a2 = coeffs[4];

                float out =
                        sample * b0 +
                        x1R[j] * b1 +
                        x2R[j] * b2 +
                        y1R[j] * a1 +
                        y2R[j] * a2;

                x2R[j] = x1R[j];
                x1R[j] = sample;
                y2R[j] = y1R[j];
                y1R[j] = out;

                sample = out;
            }
            samples[i + 1] = sample;
        }
    }
}

void ViPERDDC::ReleaseResources() {
    for (uint32_t i = 0; i < this->arrSize; i++) {
        delete[] this->coeffsArr44100[i];
        delete[] this->coeffsArr48000[i];
    }

    delete[] this->coeffsArr44100;
    this->coeffsArr44100 = nullptr;

    delete[] this->coeffsArr48000;
    this->coeffsArr48000 = nullptr;

    delete[] this->x1L;
    this->x1L = nullptr;

    delete[] this->x1R;
    this->x1R = nullptr;

    delete[] this->x2L;
    this->x2L = nullptr;

    delete[] this->x2R;
    this->x2R = nullptr;

    delete[] this->y1L;
    this->y1L = nullptr;

    delete[] this->y1R;
    this->y1R = nullptr;

    delete[] this->y2L;
    this->y2L = nullptr;

    delete[] this->y2R;
    this->y2R = nullptr;

    this->setCoeffsOk = false;
}

void ViPERDDC::Reset() {
    if (!this->setCoeffsOk) return;
    if (this->arrSize == 0) return;

    memset(this->x1L, 0, this->arrSize * 4);
    memset(this->x1R, 0, this->arrSize * 4);
}

void ViPERDDC::SetCoeffs(uint32_t param_1, float *param_2, float *param_3) {
    ReleaseResources();

    if (param_1 == 0) return;

    this->arrSize = param_1 / 5;
    this->coeffsArr44100 = new float *[this->arrSize]();
    this->coeffsArr48000 = new float *[this->arrSize]();

    for (uint32_t i = 0; i < this->arrSize; i++) {
        this->coeffsArr44100[i] = new float[5];
        this->coeffsArr44100[i][0] = param_2[i * 5];
        this->coeffsArr44100[i][1] = param_2[i * 5 + 1];
        this->coeffsArr44100[i][2] = param_2[i * 5 + 2];
        this->coeffsArr44100[i][3] = param_2[i * 5 + 3];
        this->coeffsArr44100[i][4] = param_2[i * 5 + 4];

        this->coeffsArr48000[i] = new float[5];
        this->coeffsArr48000[i][0] = param_3[i * 5];
        this->coeffsArr48000[i][1] = param_3[i * 5 + 1];
        this->coeffsArr48000[i][2] = param_3[i * 5 + 2];
        this->coeffsArr48000[i][3] = param_3[i * 5 + 3];
        this->coeffsArr48000[i][4] = param_3[i * 5 + 4];
    }

    this->x1L = new float[this->arrSize]();
    this->x1R = new float[this->arrSize]();
    this->x2L = new float[this->arrSize]();
    this->x2R = new float[this->arrSize]();
    this->y1L = new float[this->arrSize]();
    this->y1R = new float[this->arrSize]();
    this->y2L = new float[this->arrSize]();
    this->y2R = new float[this->arrSize]();
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
