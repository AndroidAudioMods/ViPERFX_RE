//
// Created by mart on 7/31/21.
//

#include <cstring>
#include "DiffSurround.h"
#include "../constants.h"

DiffSurround::DiffSurround() {
    this->samplerate = DEFAULT_SAMPLERATE;
    this->delayTime = 0.f;
    this->enabled = false;
    this->buffers[0] = new WaveBuffer_I32(1, 0x1000);
    this->buffers[1] = new WaveBuffer_I32(1, 0x1000);
}

DiffSurround::~DiffSurround() {
    delete this->buffers[0];
    delete this->buffers[1];
}

void DiffSurround::Process(float *samples, uint32_t size) {
    float *bufs[2];
    float *outbufs[2];

    if (this->enabled) {
        bufs[0] = this->buffers[0]->PushZerosGetBuffer(size);
        bufs[1] = this->buffers[1]->PushZerosGetBuffer(size);

        for (int i = 0; i < size * 2; i++) {
            bufs[i % 2][i / 2] = samples[i];
        }

        outbufs[0] = this->buffers[0]->GetCurrentBufferI32Ptr();
        outbufs[1] = this->buffers[1]->GetCurrentBufferI32Ptr();

        for (int i = 0; i < size * 2; i++) {
            samples[i] = outbufs[i % 2][i / 2];
        }

        this->buffers[0]->PopSamples(size, false);
        this->buffers[1]->PopSamples(size, false);
    }
}

void DiffSurround::Reset() {
    this->buffers[0]->Reset();
    this->buffers[1]->Reset();

    this->buffers[1]->PushZeros((uint32_t) (this->delayTime / 1000.f * (float) this->samplerate));
}

void DiffSurround::SetDelayTime(float value) {
    this->delayTime = value;
    Reset();
}

void DiffSurround::SetEnable(bool enabled) {
    this->enabled = enabled;
    if (this->enabled) {
        Reset();
    }
}

void DiffSurround::SetSamplingRate(uint32_t samplerate) {
    this->samplerate = samplerate;
    Reset();
}
