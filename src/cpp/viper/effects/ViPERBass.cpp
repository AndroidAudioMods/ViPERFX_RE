#include <cmath>
#include "ViPERBass.h"

ViPERBass::ViPERBass() {

}

ViPERBass::~ViPERBass() {

}

void ViPERBass::Process(float *samples, uint32_t size) {

}

void ViPERBass::Reset() {
    this->polyphase->SetSamplingRate(this->samplingRate);
    this->polyphase->Reset();
    this->waveBuffer->Reset();
    this->waveBuffer->PushZeros(this->polyphase->GetLatency());
    this->subwoofer->SetBassGain(this->samplingRate, this->bassFactor * 2.5f);
    this->fixedBiquad->SetLowPassParameter(this->speaker, this->samplingRate, 0.53);
    this->unknown1 = 0.0f;
}

void ViPERBass::SetBassFactor(float bassFactor) {
    if (abs(this->bassFactor - bassFactor) <= 0.01) {
        return;
    }

    this->bassFactor = bassFactor;
    this->subwoofer->SetBassGain(this->samplingRate, bassFactor * 2.5f);
}

void ViPERBass::SetEnable(bool enable) {

}

void ViPERBass::SetProcessMode(int processMode) {

}

void ViPERBass::SetSamplingRate(uint32_t samplingRate) {

}

void ViPERBass::SetSpeaker(float speaker) {
    if (this->speaker != speaker) {
        this->speaker = speaker;
        Reset();
    }

}
