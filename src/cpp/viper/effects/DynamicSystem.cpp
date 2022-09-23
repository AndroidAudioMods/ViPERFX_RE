#include "DynamicSystem.h"
#include "../constants.h"

DynamicSystem::DynamicSystem() {
    this->enabled = false;
    this->samplingRate = DEFAULT_SAMPLERATE;
    this->bass.SetSamplingRate(this->samplingRate);
    this->bass.Reset();
}

void DynamicSystem::Process(float *samples, uint32_t size) {
    if (this->enabled) {
        this->bass.FilterSamples(samples, size);
    }
}

void DynamicSystem::Reset() {
    this->bass.SetSamplingRate(this->samplingRate);
    this->bass.Reset();
}

void DynamicSystem::SetBassGain(float gain) {
    this->bass.SetBassGain(gain);
}

void DynamicSystem::SetEnable(bool enable) {
    if (this->enabled != enable) {
        this->enabled = enable;
        if (enable) {
            Reset();
        }
    }
}

void DynamicSystem::SetSideGain(float gainX, float gainY) {
    this->bass.SetSideGain(gainX, gainY);
}

void DynamicSystem::SetXCoeffs(uint32_t low, uint32_t high) {
    this->bass.SetFilterXPassFrequency(low, high);
}

void DynamicSystem::SetYCoeffs(uint32_t low, uint32_t high) {
    this->bass.SetFilterYPassFrequency(low, high);
}

void DynamicSystem::SetSamplingRate(uint32_t samplingRate) {
    if (this->samplingRate != samplingRate) {
        this->samplingRate = samplingRate;
        this->bass.SetSamplingRate(samplingRate);
    }
}

DynamicSystem::~DynamicSystem() {

}
