#include <cmath>
#include <cstring>
#include "IIRFilter.h"
#include "../constants.h"

IIRFilter::IIRFilter(uint32_t bands) {
    this->enable = false;
    this->samplingRate = DEFAULT_SAMPLERATE;
    if (bands == 10 || bands == 15 || bands == 25 || bands == 31) {
        this->bands = bands;
        this->coeffs.UpdateCoeffs(bands,this->samplingRate);
    } else {
        this->bands = 0;
    }

    for (auto &bandLevelWithQ : this->bandLevelsWithQ) {
        bandLevelWithQ = 0.636;
    }

    this->Reset();
}

IIRFilter::~IIRFilter() {

}

void IIRFilter::Process(float *samples, uint32_t size) {

}

void IIRFilter::Reset() {
    memset(this->buf,0,0x7c0);
//    this->unknown3 = 1;
//    this->unknown2 = 2;
//    this->unknown4 = 0;
}

void IIRFilter::SetBandLevel(uint32_t band, float level) {
    this->bandLevelsWithQ[band] = (float) (pow(10.0, level / 20.0) * 0.636);
}

void IIRFilter::SetEnable(bool enable) {
    this->enable = enable;
    if (enable) {
        Reset();
    }
}

void IIRFilter::SetSamplingRate(uint32_t samplingRate) {
    this->samplingRate = samplingRate;
    if (this->bands != 0) {
        this->coeffs->UpdateCoeffs(bands, samplingRate);
    }
    this->Reset();
}
