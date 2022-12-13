#include "DynamicSystem.h"
#include "../constants.h"

DynamicSystem::DynamicSystem() {
    this->samplingRate = VIPER_DEFAULT_SAMPLING_RATE;
    this->enable = false;
    this->dynamicBass.SetSamplingRate(this->samplingRate);
    this->dynamicBass.Reset();
}

void DynamicSystem::Process(float *samples, uint32_t size) {
    if (!this->enable) return;

    this->dynamicBass.FilterSamples(samples, size);
}

void DynamicSystem::Reset() {
    this->dynamicBass.SetSamplingRate(this->samplingRate);
    this->dynamicBass.Reset();
}

void DynamicSystem::SetBassGain(float gain) {
    this->dynamicBass.SetBassGain(gain);
}

void DynamicSystem::SetEnable(bool enable) {
    if (this->enable != enable) {
        if (enable) {
            Reset();
        }
        this->enable = enable;
    }
}

void DynamicSystem::SetSamplingRate(uint32_t samplingRate) {
    if (this->samplingRate != samplingRate) {
        this->samplingRate = samplingRate;
        this->dynamicBass.SetSamplingRate(samplingRate);
    }
}

void DynamicSystem::SetSideGain(float gainX, float gainY) {
    this->dynamicBass.SetSideGain(gainX, gainY);
}

void DynamicSystem::SetXCoeffs(uint32_t low, uint32_t high) {
    this->dynamicBass.SetFilterXPassFrequency(low, high);
}

void DynamicSystem::SetYCoeffs(uint32_t low, uint32_t high) {
    this->dynamicBass.SetFilterYPassFrequency(low, high);
}
