#include "Cure.h"

Cure::Cure() {
    this->enabled = false;
    Reset();
}

uint16_t Cure::GetCutoff() {
    return this->crossfeed.GetCutoff();
}

float Cure::GetFeedback() {
    return this->crossfeed.GetFeedback();
}

float Cure::GetLevelDelay() {
    return this->crossfeed.GetLevelDelay();
}

struct Crossfeed::Preset Cure::GetPreset() {
    return this->crossfeed.GetPreset();
}

void Cure::Process(float *buffer, uint32_t size) {
    if (this->enabled) {
        this->crossfeed.ProcessFrames(buffer, size);
        this->passFilter.ProcessFrames(buffer, size);
    }
}

void Cure::Reset() {
    this->crossfeed.Reset();
    this->passFilter.Reset();
}

void Cure::SetCutoff(uint16_t cutoff) {
    this->crossfeed.SetCutoff(cutoff);
}

void Cure::SetEnable(bool enabled) {
    if (this->enabled != enabled) {
        this->enabled = enabled;
        if (enabled) {
            Reset();
        }
    }
}

void Cure::SetFeedback(float feedback) {
    this->crossfeed.SetFeedback(feedback);
}

void Cure::SetPreset(struct Crossfeed::Preset preset) {
    this->crossfeed.SetPreset(preset);
}

void Cure::SetSamplingRate(uint32_t samplingRate) {
    this->crossfeed.SetSamplingRate(samplingRate);
    this->passFilter.SetSamplingRate(samplingRate);
}
