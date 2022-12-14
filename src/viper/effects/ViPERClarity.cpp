#include "ViPERClarity.h"
#include "../constants.h"

// Iscle: Verified with the latest version at 13/12/2022

ViPERClarity::ViPERClarity() {
    for (auto &highShelf : this->highShelf) {
        highShelf.SetFrequency(12000.0);
        highShelf.SetGain(1.0);
        highShelf.SetSamplingRate(VIPER_DEFAULT_SAMPLING_RATE);
    }

    this->enable = false;
    this->processMode = ClarityMode::NATURAL;
    this->clarityGainPercent = 0.0;
    this->samplingRate = VIPER_DEFAULT_SAMPLING_RATE;
    Reset();
}

void ViPERClarity::Process(float *samples, uint32_t size) {
    if (!this->enable) return;

    switch (this->processMode) {
        case ClarityMode::NATURAL: {
            this->noiseSharpening.Process(samples, size);
            break;
        }
        case ClarityMode::OZONE: {
            for (uint32_t i = 0; i < size * 2; i += 2) {
                samples[i] = (float) this->highShelf[0].Process(samples[i]);
                samples[i + 1] = (float) this->highShelf[1].Process(samples[i + 1]);
            }
            break;
        }
        case ClarityMode::XHIFI: {
            this->hifi.Process(samples, size);
            break;
        }
    }
}

void ViPERClarity::Reset() {
    this->noiseSharpening.SetSamplingRate(this->samplingRate);
    this->noiseSharpening.Reset();
    SetClarityToFilter();
    for (auto &highShelf : this->highShelf) {
        highShelf.SetFrequency(8250.0);
        highShelf.SetSamplingRate(this->samplingRate);
    }
    this->hifi.SetSamplingRate(this->samplingRate);
    this->hifi.Reset();
}

void ViPERClarity::SetClarity(float gainPercent) {
    this->clarityGainPercent = gainPercent;
    if (this->processMode == ClarityMode::OZONE) {
        Reset();
    } else {
        SetClarityToFilter();
    }
}

void ViPERClarity::SetClarityToFilter() {
    this->noiseSharpening.SetGain(this->clarityGainPercent);
    this->highShelf[0].SetGain(this->clarityGainPercent + 1.0f);
    this->highShelf[1].SetGain(this->clarityGainPercent + 1.0f);
    this->hifi.SetClarity(this->clarityGainPercent + 1.0f);
}

void ViPERClarity::SetEnable(bool enable) {
    if (this->enable != enable) {
        if (enable) {
            Reset();
        }
        this->enable = enable;
    }
}

void ViPERClarity::SetProcessMode(ClarityMode processMode) {
    if (this->processMode != processMode) {
        this->processMode = processMode;
        Reset();
    }
}

void ViPERClarity::SetSamplingRate(uint32_t samplingRate) {
    if (this->samplingRate != samplingRate) {
        this->samplingRate = samplingRate;
        Reset();
    }
}
