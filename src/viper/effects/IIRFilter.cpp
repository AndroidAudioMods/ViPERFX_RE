#include <cmath>
#include <cstring>
#include "IIRFilter.h"
#include "../constants.h"

// Iscle: Verified with latest version at 13/12/2022

IIRFilter::IIRFilter(uint32_t bands) {
    this->enable = false;
    this->samplingRate = VIPER_DEFAULT_SAMPLING_RATE;
    if (bands == 10 || bands == 15 || bands == 25 || bands == 31) {
        this->bands = bands;
        this->minPhaseIirCoeffs.UpdateCoeffs(this->bands, this->samplingRate);
    } else {
        this->bands = 0;
    }

    for (auto &bandLevelWithQ : this->bandLevelsWithQ) {
        bandLevelWithQ = 0.636;
    }

    Reset();
}

void IIRFilter::Process(float *samples, uint32_t size) {
    if (!this->enable) return;

    double *coeffs = this->minPhaseIirCoeffs.GetCoefficients();
    if (coeffs == nullptr || size == 0) return;

    for (uint32_t i = 0; i < size; i++) {
        for (uint32_t j = 0; j < 2; j++) {
            double sample = samples[i * 2 + j];
            double accumulated = 0.0;

            for (uint32_t k = 0; k < this->bands; k++) {
                uint32_t bufIdx = this->unknown2 + j * 8 + k * 16;
                this->buf[bufIdx] = sample;

                double coeff1 = coeffs[k * 4];
                double coeff2 = coeffs[k * 4 + 1];
                double coeff3 = coeffs[k * 4 + 2];

                double a = coeff3 * this->buf[bufIdx + ((this->unknown3 + 3) - this->unknown2)];
                double b = coeff2 * (sample - this->buf[bufIdx + (this->unknown4 - this->unknown2)]);
                double c = coeff1 * this->buf[bufIdx + ((this->unknown4 - this->unknown2) + 3)];

                double tmp = (a + b) - c;

                this->buf[bufIdx + 3] = tmp;
                accumulated += tmp * this->bandLevelsWithQ[k];
            }

            samples[i * 2 + j] = (float) accumulated;
        }

        this->unknown2 = (this->unknown2 + 1) % 3;
        this->unknown3 = (this->unknown3 + 1) % 3;
        this->unknown4 = (this->unknown4 + 1) % 3;
    }
}

void IIRFilter::Reset() {
    memset(this->buf,0,sizeof(buf));
    this->unknown2 = 2;
    this->unknown3 = 1;
    this->unknown4 = 0;
}

void IIRFilter::SetBandLevel(uint32_t band, float level) {
    if (band > 30) return;
    double bandLevel = pow(10.0, (double) level / 20.0);
    this->bandLevelsWithQ[band] = (float) (bandLevel * 0.636);
}

void IIRFilter::SetEnable(bool enable) {
    if (this->enable != enable) {
        this->enable = enable;
        if (enable) {
            Reset();
        }
    }
}

void IIRFilter::SetSamplingRate(uint32_t samplingRate) {
    if (this->samplingRate != samplingRate) {
        this->samplingRate = samplingRate;
        if (this->bands != 0) {
            this->minPhaseIirCoeffs.UpdateCoeffs(this->bands, samplingRate);
        }
        Reset();
    }
}
