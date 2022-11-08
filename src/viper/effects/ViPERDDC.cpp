#include "ViPERDDC.h"
#include "../../log.h"
#include <cstring>

ViPERDDC::ViPERDDC() {
    this->enable = false;
    this->samplingRate = 44100;
    this->setCoeffsOk = false;
    this->arrSize = 0;
    this->arrPtr44100 = nullptr;
    this->arrPtr48000 = nullptr;
    this->arr4 = nullptr;
    this->arr3 = nullptr;
    this->arr2 = nullptr;
    this->arr1 = nullptr;
    this->arr8 = nullptr;
    this->arr7 = nullptr;
    this->arr6 = nullptr;
    this->arr5 = nullptr;
}

ViPERDDC::~ViPERDDC() {
    ReleaseResources();
}

void ViPERDDC::Process(float *samples, uint32_t size) {
    if (!this->setCoeffsOk) return;
    if (!this->enable) return;

    switch (this->samplingRate) {
        case 44100: {
            break;
        }
        case 48000: {
            break;
        }
        default: {
            VIPER_LOGD("ViPERDDC::Process() -> Invalid sampling rate: %d", this->samplingRate);
        }
    }
}

void ViPERDDC::ReleaseResources() {
    for (uint32_t i = 0; i < this->arrSize; i++) {
        delete[] this->arrPtr44100[i];
        delete[] this->arrPtr48000[i];
    }

    delete[] this->arrPtr44100;
    this->arrPtr44100 = nullptr;

    delete[] this->arrPtr48000;
    this->arrPtr48000 = nullptr;

    delete[] this->arr1;
    this->arr1 = nullptr;

    delete[] this->arr2;
    this->arr2 = nullptr;

    delete[] this->arr3;
    this->arr3 = nullptr;

    delete[] this->arr4;
    this->arr4 = nullptr;

    delete[] this->arr5;
    this->arr5 = nullptr;

    delete[] this->arr6;
    this->arr6 = nullptr;

    delete[] this->arr7;
    this->arr7 = nullptr;

    delete[] this->arr8;
    this->arr8 = nullptr;

    this->setCoeffsOk = false;
}

void ViPERDDC::Reset() {
    if (!this->setCoeffsOk) return;
    if (this->arrSize == 0) return;

    memset(this->arr1, 0, this->arrSize * 4);
    memset(this->arr2, 0, this->arrSize * 4);
}

void ViPERDDC::SetCoeffs(uint32_t param_1, float *param_2, float *param_3) {
    ReleaseResources();

    if (param_1 == 0) return;

    this->arrSize = param_1 / 5;
    this->arrPtr44100 = new float *[this->arrSize]();
    this->arrPtr48000 = new float *[this->arrSize]();

    for (uint32_t i = 0; i < this->arrSize; i++) {
        this->arrPtr44100[i] = new float[5];
        this->arrPtr44100[i][0] = param_2[i * 5];
        this->arrPtr44100[i][1] = param_2[i * 5 + 1];
        this->arrPtr44100[i][2] = param_2[i * 5 + 2];
        this->arrPtr44100[i][3] = param_2[i * 5 + 3];
        this->arrPtr44100[i][4] = param_2[i * 5 + 4];

        this->arrPtr48000[i] = new float[5];
        this->arrPtr48000[i][0] = param_3[i * 5];
        this->arrPtr48000[i][1] = param_3[i * 5 + 1];
        this->arrPtr48000[i][2] = param_3[i * 5 + 2];
        this->arrPtr48000[i][3] = param_3[i * 5 + 3];
        this->arrPtr48000[i][4] = param_3[i * 5 + 4];
    }

    this->arr1 = new float[this->arrSize]();
    this->arr2 = new float[this->arrSize]();
    this->arr3 = new float[this->arrSize]();
    this->arr4 = new float[this->arrSize]();
    this->arr5 = new float[this->arrSize]();
    this->arr6 = new float[this->arrSize]();
    this->arr7 = new float[this->arrSize]();
    this->arr8 = new float[this->arrSize]();
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
