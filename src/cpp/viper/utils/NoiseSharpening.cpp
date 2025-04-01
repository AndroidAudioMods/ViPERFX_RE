#include "NoiseSharpening.h"
#include "../constants.h"

NoiseSharpening::NoiseSharpening() {
    this->samplingRate = VIPER_DEFAULT_SAMPLING_RATE;
    this->gain = 0.0;
    Reset();
}

void NoiseSharpening::Process(float *buffer, uint32_t size) {
    for (uint32_t i = 0; i < size; i++) {
        float sampleLeft = buffer[i * 2];
        float sampleRight = buffer[i * 2 + 1];
        float prevLeft = this->in[0];
        float prevRight = this->in[1];
        this->in[0] = sampleLeft;
        this->in[1] = sampleRight;
        float diffLeft = (sampleLeft - prevLeft) * this->gain;
        float diffRight = (sampleRight - prevRight) * this->gain;

        float sampleLeftIn = sampleLeft + diffLeft;
        float sampleRightIn = sampleRight + diffRight;

        float hist = (sampleLeftIn) * this->filters[0].b1;
        float left = this->filters[0].prevSample + (sampleLeftIn) * this->filters[0].b0;
        this->filters[0].prevSample = (sampleLeftIn) * this->filters[0].a1 + hist;

        hist = (sampleRightIn) * this->filters[1].b1;
        float right = this->filters[1].prevSample + (sampleRightIn) * this->filters[1].b0;
        this->filters[1].prevSample = (sampleRightIn) * this->filters[1].a1 + hist;

        buffer[i * 2] = left;
        buffer[i * 2 + 1] = right;
    }
}

void NoiseSharpening::Reset() {
    for (int i = 0; i < 2; i++) {
        this->filters[i].setLPF_BW((float) ((double) this->samplingRate / 2.0 - 1000.0), this->samplingRate);
        this->filters[i].Mute();
        this->in[i] = 0.0;
    }
}

void NoiseSharpening::SetGain(float gain) {
    this->gain = gain;
}

void NoiseSharpening::SetSamplingRate(uint32_t samplingRate) {
    this->samplingRate = samplingRate;
    Reset();
}
