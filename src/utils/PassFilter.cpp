//
// Created by mart on 7/26/21.
//

#include "PassFilter.h"
#include "../constants.h"

PassFilter::PassFilter() {
    this->filters[0] = new IIR_NOrder_BW_LH(3);
    this->filters[1] = new IIR_NOrder_BW_LH(3);
    this->filters[2] = new IIR_NOrder_BW_LH(1);
    this->filters[3] = new IIR_NOrder_BW_LH(1);
    this->samplerate = DEFAULT_SAMPLERATE;
    Reset();
}

PassFilter::~PassFilter() {
    delete this->filters[0];
    delete this->filters[1];
    delete this->filters[2];
    delete this->filters[3];
}

void PassFilter::Reset() {
    uint32_t cutoff;
    if (this->samplerate < 44100) {
        cutoff = this->samplerate - 100;
    } else {
        cutoff = 18000;
    }

    this->filters[0]->setLPF((float)cutoff, this->samplerate);
    this->filters[1]->setLPF((float)cutoff, this->samplerate);
    this->filters[2]->setLPF(10.f, cutoff);
    this->filters[3]->setLPF(10.f, cutoff);

    this->filters[0]->Mute();
    this->filters[1]->Mute();
    this->filters[2]->Mute();
    this->filters[3]->Mute();
}

#define do_filter(filt, sample) \
for (int idx = 0; idx < (filt)->order; idx++) {\
    IIR_1st filter = this->filters[2]->filters[idx];\
    float hist = (sample) * filter.b1;\
    left = filter.prevSample + (sample) * filter.b0;\
    filter.prevSample = (sample) * filter.a1 + hist;\
}

void PassFilter::ProcessFrames(float *buffer, uint32_t size) {
    for (int x = 0; x < size; x++) {
        float left = buffer[2*x];
        float right = buffer[2*x+1];

        do_filter(this->filters[2], left)
        do_filter(this->filters[0], left)
        do_filter(this->filters[3], right)
        do_filter(this->filters[1], right)

        buffer[2*x] = left;
        buffer[2*x+1] = right;
    }
}

void PassFilter::SetSamplingRate(uint32_t samplerate) {
    this->samplerate = samplerate;
    Reset();
}
