//
// Created by mart on 7/31/21.
//

#include "ViPERClarity.h"
#include "../constants.h"

ViPERClarity::ViPERClarity() {
    for (int i = 0; i < 2; i++) {
        this->hiShelf[i].SetFrequency(12000.f);
        this->hiShelf[i].SetQuality(100.f);
        this->hiShelf[i].SetGain(1.f);
        this->hiShelf[i].SetSamplingRate(DEFAULT_SAMPLERATE);
    }

    this->enabled = false;
    this->processMode = ClarityMode::NATURAL;
    this->clarityGainPercent = 0.f;
    this->samplerate = DEFAULT_SAMPLERATE;
    Reset();
}

void ViPERClarity::Process(float *samples, uint32_t size) {
    if (this->enabled) {
        switch (this->processMode) {
            case ClarityMode::NATURAL: {
                this->sharp.Process(samples, size);
                break;
            }
            case ClarityMode::OZONE: {
                for (int i = 0; i < size * 2; i++) {
                    samples[i] = this->hiShelf[i % 2].Process(samples[i]);
                }
                break;
            }
            case ClarityMode::XHIFI: {
                this->hifi.Process(samples, size);
                break;
            }
        }
    }
}

void ViPERClarity::Reset() {
    this->sharp.SetSamplingRate(this->samplerate);
    this->sharp.Reset();
    SetClarityToFilter();
    for (int i = 0; i < 2; i++) {
        this->hiShelf[i].SetFrequency(8250.f);
        this->hiShelf[i].SetQuality(100.f);
        this->hiShelf[i].SetSamplingRate(DEFAULT_SAMPLERATE);
    }
    this->hifi.SetSamplingRate(this->samplerate);
    this->hifi.Reset();
}

void ViPERClarity::SetClarity(float gainPercent) {
    this->clarityGainPercent = gainPercent;
    if (this->processMode != ClarityMode::OZONE) {
        SetClarityToFilter();
    } else {
        Reset();
    }
}

void ViPERClarity::SetClarityToFilter() {
    this->sharp.SetGain(this->clarityGainPercent);
    this->hiShelf[0].SetGain(this->clarityGainPercent + 1.f);
    this->hiShelf[1].SetGain(this->clarityGainPercent + 1.f);
    this->hifi.SetClarity(this->clarityGainPercent + 1.f);
}

void ViPERClarity::SetEnable(bool enabled) {
    this->enabled = enabled;
    if (this->enabled) {
        Reset();
    }
}

void ViPERClarity::SetProcessMode(ClarityMode mode) {
    this->processMode = mode;
    Reset();
}

void ViPERClarity::SetSamplingRate(uint32_t samplerate) {
    this->samplerate = samplerate;
    Reset();
}

ViPERClarity::~ViPERClarity() {

}
