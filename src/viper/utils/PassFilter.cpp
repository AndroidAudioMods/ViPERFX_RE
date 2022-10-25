#include "PassFilter.h"
#include "../constants.h"

PassFilter::PassFilter() {
    this->filters[0] = new IIR_NOrder_BW_LH(3);
    this->filters[1] = new IIR_NOrder_BW_LH(3);
    this->filters[2] = new IIR_NOrder_BW_LH(1);
    this->filters[3] = new IIR_NOrder_BW_LH(1);
    this->samplingRate = VIPER_DEFAULT_SAMPLING_RATE;
    Reset();
}

PassFilter::~PassFilter() {
    delete this->filters[0];
    delete this->filters[1];
    delete this->filters[2];
    delete this->filters[3];
}

void PassFilter::ProcessFrames(float *buffer, uint32_t size) {
    for (uint32_t x = 0; x < size; x++) {
        float left = buffer[2 * x];
        float right = buffer[2 * x + 1];

        left = do_filter_lh(this->filters[2], left);
        left = do_filter_lh(this->filters[0], left);
        right = do_filter_lh(this->filters[3], right);
        right = do_filter_lh(this->filters[1], right);

        buffer[2 * x] = left;
        buffer[2 * x + 1] = right;
    }
}

void PassFilter::Reset() {
    float cutoff;
    if (this->samplingRate < 44100) {
        cutoff = (float) this->samplingRate - 100.0f;
    } else {
        cutoff = 18000.0;
    }

    this->filters[0]->setLPF(cutoff, this->samplingRate);
    this->filters[1]->setLPF(cutoff, this->samplingRate);
    this->filters[2]->setHPF(10.0, this->samplingRate);
    this->filters[3]->setHPF(10.0, this->samplingRate);

    this->filters[0]->Mute();
    this->filters[1]->Mute();
    this->filters[2]->Mute();
    this->filters[3]->Mute();
}

void PassFilter::SetSamplingRate(uint32_t samplingRate) {
    if (this->samplingRate != samplingRate) {
        this->samplingRate = samplingRate;
        Reset();
    }
}
