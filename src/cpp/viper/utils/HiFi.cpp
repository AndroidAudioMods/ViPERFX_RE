#include "HiFi.h"
#include "../constants.h"

HiFi::HiFi() {
    this->gain = 1.f;
    this->samplingRate = VIPER_DEFAULT_SAMPLING_RATE;
    for (int i = 0; i < 2; i++) {
        this->buffers[i] = new WaveBuffer(2, 0x800);
        this->filters[i].lowpass = new IIR_NOrder_BW_LH(1);
        this->filters[i].highpass = new IIR_NOrder_BW_LH(3);
        this->filters[i].bandpass = new IIR_NOrder_BW_BP(3);
    }
    Reset();
}

HiFi::~HiFi() {
    for (int i = 0; i < 2; i++) {
        delete this->buffers[i];
        delete this->filters[i].lowpass;
        delete this->filters[i].highpass;
        delete this->filters[i].bandpass;
    }
}

void HiFi::Process(float *samples, uint32_t size) {
    if (size > 0) {
        float *bpBuf = this->buffers[0]->PushZerosGetBuffer(size);
        float *lpBuf = this->buffers[1]->PushZerosGetBuffer(size);
        if (bpBuf == nullptr || lpBuf == nullptr) {
            Reset();
            return;
        }

        for (int i = 0; i < size * 2; i++) {
            int index = i % 2;
            float out1 = do_filter_lh(this->filters[index].lowpass, samples[i]);
            float out2 = do_filter_lh(this->filters[index].highpass, samples[i]);
            float out3 = do_filter_bp(this->filters[index].bandpass, samples[i]);
            samples[i] = out2;
            lpBuf[i] = out1;
            bpBuf[i] = out3;
        }
        float *bpOut = this->buffers[0]->GetBuffer();
        float *lpOut = this->buffers[1]->GetBuffer();
        for (int i = 0; i < size * 2; i++) {
            float hp = samples[i] * this->gain * 1.2f;
            float bp = bpOut[i] * this->gain;
            samples[i] = hp + bp + lpOut[i];
        }
        this->buffers[0]->PopSamples(size, false);
        this->buffers[1]->PopSamples(size, false);
    }
}

void HiFi::Reset() {
    for (int i = 0; i < 2; i++) {
        this->filters[i].lowpass->setLPF(120.0, this->samplingRate);
        this->filters[i].lowpass->Mute();
        this->filters[i].highpass->setHPF(1200.0, this->samplingRate);
        this->filters[i].highpass->Mute();
        this->filters[i].bandpass->setBPF(120.f, 1200.f, this->samplingRate);
        this->filters[i].bandpass->Mute();
    }
    this->buffers[0]->Reset();
    this->buffers[0]->PushZeros(this->samplingRate / 400);
    this->buffers[1]->Reset();
    this->buffers[1]->PushZeros(this->samplingRate / 200);

}

void HiFi::SetClarity(float value) {
    this->gain = value;
}

void HiFi::SetSamplingRate(uint32_t samplingRate) {
    this->samplingRate = samplingRate;
    Reset();
}
