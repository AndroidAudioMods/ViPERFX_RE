#include "VHE.h"
#include "../constants.h"
#include "VHE_L0.h"
#include "VHE_L1.h"
#include "VHE_L2.h"
#include "VHE_L3.h"
#include "VHE_L4.h"

VHE::VHE() {
    this->enabled = false;
    this->effectLevel = 0;
    this->convSize = 0;
    this->samplingRate = VIPER_DEFAULT_SAMPLING_RATE;

    this->bufA = new WaveBuffer(2, 0x1000);
    this->bufB = new WaveBuffer(2, 0x1000);
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
    this->bufA->Reset();
    this->bufB->Reset();

    this->convLeft.Reset();
    this->convLeft.UnloadKernel();
    this->convRight.Reset();
    this->convRight.UnloadKernel();

    if (this->effectLevel > 4) {
        VIPER_LOGD("Invalid effect level %d", this->effectLevel);
        return;
    }

    if (this->samplingRate != 44100 && this->samplingRate != 48000) {
        VIPER_LOGD("Invalid sampling rate %d", this->samplingRate);
        return;
    }

    const float *arrLeft;
    const float *arrRight;
    uint32_t arrSize;
    float someValue;

    switch (this->effectLevel) {
        case 0: {
            switch (this->samplingRate) {
                case 44100: {
                    arrLeft = VHE_L0_44100_L;
                    arrRight = VHE_L0_44100_R;
                    someValue = 2.94595;
                    break;
                }
                case 48000: {
                    arrLeft = VHE_L0_48000_L;
                    arrRight = VHE_L0_48000_R;
                    someValue = 2.94595;
                    break;
                }
            }
            arrSize = 4096;
            break;
        }
        case 1: {
            switch (this->samplingRate) {
                case 44100: {
                    arrLeft = VHE_L1_44100_L;
                    arrRight = VHE_L1_44100_R;
                    someValue = 0.944061;
                    break;
                }
                case 48000: {
                    arrLeft = VHE_L1_48000_L;
                    arrRight = VHE_L1_48000_R;
                    someValue = 0.944061;
                    break;
                }
            }
            arrSize = 2047;
            break;
        }
        case 2: {
            switch (this->samplingRate) {
                case 44100: {
                    arrLeft = VHE_L2_44100_L;
                    arrRight = VHE_L2_44100_R;
                    someValue = 1.544582;
                    break;
                }
                case 48000: {
                    arrLeft = VHE_L2_48000_L;
                    arrRight = VHE_L2_48000_R;
                    someValue = 1.531516;
                    break;
                }
            }
            arrSize = 4096;
            break;
        }
        case 3: {
            switch (this->samplingRate) {
                case 44100: {
                    arrLeft = VHE_L3_44100_L;
                    arrRight = VHE_L3_44100_R;
                    someValue = 1.584257;
                    break;
                }
                case 48000: {
                    arrLeft = VHE_L3_48000_L;
                    arrRight = VHE_L3_48000_R;
                    someValue = 1.567789;
                    break;
                }
            }
            arrSize = 4096;
            break;
        }
        case 4: {
            switch (this->samplingRate) {
                case 44100: {
                    arrLeft = VHE_L4_44100_L;
                    arrRight = VHE_L4_44100_R;
                    someValue = 1.466681;
                    break;
                }
                case 48000: {
                    arrLeft = VHE_L4_48000_L;
                    arrRight = VHE_L4_48000_R;
                    someValue = 1.487227;
                    break;
                }
            }
            arrSize = 4096;
            break;
        }
    }

    this->convLeft.LoadKernel(arrLeft, someValue, arrSize, 4096);
    this->convRight.LoadKernel(arrRight, someValue, arrSize, 4096);
    this->convSize = 4096;
}

bool VHE::GetEnabled() {
    return enabled;
}

void VHE::SetEffectLevel(uint32_t effectLevel) {
    if (this->effectLevel != effectLevel) {
        if (effectLevel < 5) {
            this->effectLevel = effectLevel;
            Reset();
        }
    }
}

void VHE::SetEnable(bool enabled) {
    if (this->enabled != enabled) {
        this->enabled = enabled;
        if (this->enabled) {
            Reset();
        }
    }
}

void VHE::SetSamplingRate(uint32_t samplingRate) {
    if (this->samplingRate != samplingRate) {
        this->samplingRate = samplingRate;
        Reset();
    }
}
