#include <cstring>
#include "DiffSurround.h"
#include "../constants.h"

DiffSurround::DiffSurround() {
    this->samplerate = DEFAULT_SAMPLERATE;
    this->delayTime = 0.0f;
    this->enabled = false;
    for (auto &buffer : this->buffers) {
        buffer = new WaveBuffer(1, 0x1000);
    }
}

DiffSurround::~DiffSurround() {
    for (auto &buffer : this->buffers) {
        delete buffer;
        buffer = nullptr;
    }
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

        outbufs[0] = this->buffers[0]->GetBuffer();
        outbufs[1] = this->buffers[1]->GetBuffer();

        for (int i = 0; i < size * 2; i++) {
            samples[i] = outbufs[i % 2][i / 2];
        }

        this->buffers[0]->PopSamples(size, false);
        this->buffers[1]->PopSamples(size, false);
    }
}

void DiffSurround::Reset() {
    for (auto &buffer : this->buffers) {
        buffer->Reset();
    }

    this->buffers[1]->PushZeros((uint32_t) (this->delayTime / 1000.0f * (float) this->samplerate));
}

void DiffSurround::SetDelayTime(float delayTime) {
    if (this->delayTime != delayTime) {
        this->delayTime = delayTime;
        this->Reset();
    }
}

void DiffSurround::SetEnable(bool enabled) {
    if (this->enabled != enabled) {
        this->enabled = enabled;
        if (enabled) {
            Reset();
        }
    }
}

void DiffSurround::SetSamplingRate(uint32_t samplerate) {
    if (this->samplerate != samplerate) {
        this->samplerate = samplerate;
        this->Reset();
    }
}
