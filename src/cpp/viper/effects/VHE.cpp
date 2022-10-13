#include "VHE.h"
#include "../constants.h"

VHE::VHE() {
    enabled = false;
    effectLevel = 0;
    convSize = 0;
    samplingRate = VIPER_DEFAULT_SAMPLING_RATE;

    bufA = new WaveBuffer(2, 0x1000);
    bufB = new WaveBuffer(2, 0x1000);
    Reset();
}

VHE::~VHE() {
    delete bufA;
    delete bufB;
}

uint32_t VHE::Process(float *source, float *dest, uint32_t frameSize) {
    if (enabled && convLeft.InstanceUsable() && convRight.InstanceUsable()) {
        if (bufA->PushSamples(source, frameSize) != 0) {
            while (bufA->GetBufferOffset() > convSize) {
                float *buffer = bufA->GetBuffer();
                convLeft.ConvolveInterleaved(buffer, 0);
                convRight.ConvolveInterleaved(buffer, 1);
                bufB->PushSamples(buffer, convSize);
                bufA->PopSamples(convSize, true);
            }
            return bufB->PopSamples(dest, frameSize, false);
        }
    }
    return frameSize;
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
    this->samplingRate = srate;
    Reset();
}
