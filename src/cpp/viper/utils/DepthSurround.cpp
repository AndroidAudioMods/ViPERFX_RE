//
// Created by mart on 7/28/21.
//

#include "DepthSurround.h"
#include <cstring>
#include <cmath>
#include "../constants.h"

DepthSurround::DepthSurround() {
    this->strength = 0;
    this->enabled = false;
    this->strengthAtLeast500 = false;
    this->gain = 0;
    for (auto &prev : this->prev) {
        prev = 0.0f;
    }
    this->SetSamplingRate(DEFAULT_SAMPLERATE);
    this->RefreshStrength(this->strength);
}

void DepthSurround::Process(float *samples, uint32_t size) {
    if (this->enabled) {
        if (!this->strengthAtLeast500) {
            for (int i = 0; i < size; i++) {
                float sampleLeft = samples[2 * i];
                float sampleRight = samples[2 * i + 1];

                this->prev[0] = this->gain * this->delay[0].ProcessSample(sampleLeft + this->prev[1]);
                this->prev[1] = this->gain * this->delay[1].ProcessSample(sampleRight + this->prev[0]);

                float l = this->prev[0] + sampleLeft;
                float r = this->prev[1] + sampleRight;

                float diff = (l - r) / 2.f;
                float avg = (l + r) / 2.f;
                float avgOut = this->highpass.ProcessSample(diff);
                samples[2 * i] = avg + (diff - avgOut);
                samples[2 * i + 1] = avg - (diff - avgOut);
            }
        } else {
            for (int i = 0; i < size; i++) {
                float sampleLeft = samples[2 * i];
                float sampleRight = samples[2 * i + 1];

                this->prev[0] = this->gain * this->delay[0].ProcessSample(sampleLeft + this->prev[1]);
                this->prev[1] = -this->gain * this->delay[1].ProcessSample(sampleRight + this->prev[0]);

                float l = this->prev[0] + sampleLeft;
                float r = this->prev[1] + sampleRight;

                float diff = (l - r) / 2.f;
                float avg = (l + r) / 2.f;
                float avgOut = this->highpass.ProcessSample(diff);
                samples[2 * i] = avg + (diff - avgOut);
                samples[2 * i + 1] = avg - (diff - avgOut);
            }
        }
    }
}

void DepthSurround::RefreshStrength(short strength) {
    this->strengthAtLeast500 = strength >= 500;
    this->enabled = strength != 0;
    if (strength != 0) {
        float gain = powf(10.0f, ((strength / 1000.0f) * 10.0f - 15.0f) / 20.0f);
        if (fabsf(gain) > 1.0f) {
            gain = 1.0f;
        }
        this->gain = gain;
    } else {
        this->gain = 0;
    }
}

void DepthSurround::SetSamplingRate(uint32_t samplerate) {
    this->delay[0].SetParameters(samplerate, 0.02);
    this->delay[1].SetParameters(samplerate, 0.014);
    this->highpass.SetHighPassParameter(800.0f, samplerate, -11.0f, 0.72f, 0);
    for (auto &prev : this->prev) {
        prev = 0.0f;
    }
}

void DepthSurround::SetStrength(short strength) {
    this->strength = strength;
    this->RefreshStrength(strength);
}