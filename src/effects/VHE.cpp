//
// Created by mart on 9/18/21.
//

#include "VHE.h"
#include "../constants.h"

VHE::VHE() {
    enabled = false;
    effectLevel = 0;
    convSize = 0;
    samplerate = DEFAULT_SAMPLERATE;

    bufA = new WaveBuffer_I32(2, 0x1000);
    bufB = new WaveBuffer_I32(2, 0x1000);
    Reset();
}

VHE::~VHE() {
    delete bufA;
    delete bufB;
}

void VHE::Process(float *source, float *dest, int frameSize) {
    if (enabled && convLeft.InstanceUsable() && convRight.InstanceUsable()) {
        if (bufA->PushSamples(source, frameSize) != 0) {
            while (bufA->GetBufferOffset() > convSize) {
                float *buffer = bufA->GetCurrentBufferI32Ptr();
                convLeft.ConvolveInterleaved(buffer, 0);
                convRight.ConvolveInterleaved(buffer, 1);
                bufB->PushSamples(buffer, convSize);
                bufA->PopSamples(convSize, true);
            }
            bufB->PopSamples(dest, frameSize, false);
        }
    }
}

void VHE::Reset() {
    // TODO
}

bool VHE::GetEnabled() {
    return enabled;
}

void VHE::SetEffectLevel(uint32_t level) {
    if (level < 5) {
        this->effectLevel = level;
        Reset();
    }
}

void VHE::SetEnable(bool enabled) {
    this->enabled = enabled;
    if (enabled) {
        Reset();
    }
}

void VHE::SetSamplingRate(uint32_t srate) {
    this->samplerate = srate;
    Reset();
}
