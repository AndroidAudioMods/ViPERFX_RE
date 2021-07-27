//
// Created by mart on 7/26/21.
//

#include "Cure.h"

Cure::Cure() {
    this->enabled = false;
    Reset();
}

void Cure::Process(float *buffer, uint32_t size) {
    if (this->enabled) {
        Crossfeed::ProcessFrames(buffer, size);
        this->pass.ProcessFrames(buffer, size);
    }
}

void Cure::Reset() {
    Crossfeed::Reset();
    this->pass.Reset();
}

void Cure::SetSamplingRate(uint32_t samplerate) {
    Crossfeed::SetSamplingRate(samplerate);
    this->pass.SetSamplingRate(samplerate);
}
