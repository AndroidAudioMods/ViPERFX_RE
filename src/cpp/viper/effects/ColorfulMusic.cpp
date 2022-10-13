#include "ColorfulMusic.h"
#include "../constants.h"

ColorfulMusic::ColorfulMusic() {
    this->samplingRate = VIPER_DEFAULT_SAMPLING_RATE;
    this->enabled = false;
    this->stereo3DSurround.SetStereoWiden(0.0f);
    this->depthSurround.SetSamplingRate(this->samplingRate);
    this->depthSurround.SetStrength(0);
}

void ColorfulMusic::Process(float *samples, uint32_t size) {
    if (!this->enabled) {
        return;
    }

    this->depthSurround.Process(samples, size);
    this->stereo3DSurround.Process(samples, size);
}

void ColorfulMusic::Reset() {
    this->depthSurround.SetSamplingRate(this->samplingRate);
}

void ColorfulMusic::SetDepthValue(short depthValue) {
    this->depthSurround.SetStrength(depthValue);
}

void ColorfulMusic::SetEnable(bool enable) {
    if (this->enabled != enable) {
        this->enabled = enable;
        if (enable) {
            Reset();
        }
    }
}

void ColorfulMusic::SetMidImageValue(float midImageValue) {
    this->stereo3DSurround.SetMiddleImage(midImageValue);
}

void ColorfulMusic::SetSamplingRate(uint32_t samplingRate) {
    if (this->samplingRate != samplingRate) {
        this->samplingRate = samplingRate;
        this->depthSurround.SetSamplingRate(this->samplingRate);
    }
}

void ColorfulMusic::SetWidenValue(float widenValue) {
    this->stereo3DSurround.SetStereoWiden(widenValue);
}
