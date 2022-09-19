#include "Polyphase.h"

Polyphase::Polyphase(int unknown1) {

}

Polyphase::~Polyphase() {

}

uint32_t Polyphase::GetLatency() {
    return 63;
}

uint32_t Polyphase::Process(float *samples, uint32_t size) {
    return 0;
}

void Polyphase::Reset() {

}

void Polyphase::SetSamplingRate(uint32_t samplingRate) {

}

