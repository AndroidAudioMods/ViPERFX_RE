//
// Created by mart on 7/26/21.
//

#include "Cure.h"

Cure::Cure() {
    this->enabled = false;
    Reset();
}

Cure::~Cure() {

}

void Cure::Process(float *buffer, uint32_t size) {
    if (this->enabled) {
        this->crossfeed.ProcessFrames(buffer, size);
        this->pass.ProcessFrames(buffer, size);
    }
}

void Cure::Reset() {
    this->crossfeed.Reset();
    this->pass.Reset();
}

void Cure::SetEnable(bool enabled) {
    Reset();
    this->enabled = enabled;
}

void Cure::SetSamplingRate(uint32_t samplerate) {
    this->crossfeed.SetSamplingRate(samplerate);
    this->pass.SetSamplingRate(samplerate);
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

preset_t Cure::GetPreset() {
    return this->crossfeed.GetPreset();
}

void Cure::SetCutoff(uint16_t cutoff) {
    this->crossfeed.SetCutoff(cutoff);

}

void Cure::SetFeedback(float feedback) {
    this->crossfeed.SetFeedback(feedback);
}

void Cure::SetPreset(preset_t preset) {
    this->crossfeed.SetPreset(preset);
}

