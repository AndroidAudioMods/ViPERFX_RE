#include "ViPERBass.h"
#include "../constants.h"

ViPERBass::ViPERBass() {
    this->enable = false;
    this->samplingRate = DEFAULT_SAMPLERATE;
    this->speaker = 60;
    this->samplingRatePeriod = 1.0 / DEFAULT_SAMPLERATE;
    this->antiPop = 0.0;
    this->processMode = ProcessMode::NATURAL_BASS;
    this->bassFactor = 0.0;
    this->polyphase = new Polyphase(2);
    this->biquad = new Biquad();
    this->subwoofer = new Subwoofer();
    this->waveBuffer = new WaveBuffer(1, 0x1000);

    this->biquad->Reset();
    this->biquad->SetLowPassParameter((float) this->speaker, this->samplingRate, 0.53);
    this->subwoofer->SetBassGain(this->samplingRate, 0.0);
    this->Reset();
}

ViPERBass::~ViPERBass() {
    delete this->polyphase;
    delete this->biquad;
    delete this->subwoofer;
    delete this->waveBuffer;
}

void ViPERBass::Process(float *samples, uint32_t size) {
    if (!this->enable) {
        return;
    }

    if (size == 0) {
        return;
    }

    if (this->antiPop < 1.0) {
        for (uint32_t i = 0; i < size * 2; i += 2) {
            samples[i] *= this->antiPop;
            samples[i + 1] *= this->antiPop;
            
            float x = this->antiPop + this->samplingRatePeriod;
            if (x > 1.0) {
                x = 1.0;
            }
            this->antiPop = x;
        }
    }

    switch (this->processMode) {
        case ProcessMode::NATURAL_BASS: {
            for (uint32_t i = 0; i < size * 2; i += 2) {
                double sample = ((double) samples[i] + (double) samples[i + 1]) / 2.0;
                float x = (float) this->biquad->ProcessSample(sample) * this->bassFactor;
                samples[i] += x;
                samples[i + 1] += x;
            }
            break;
        }
        case ProcessMode::PURE_BASS_PLUS: {
            if (this->waveBuffer->PushSamples(samples, size)) {
                float *buffer = this->waveBuffer->GetBuffer();
                uint32_t bufferOffset = this->waveBuffer->GetBufferOffset();

                for (uint32_t i = 0; i < size * 2; i += 2) {
                    double sample = ((double) samples[i] + (double) samples[i + 1]) / 2.0;
                    auto x = (float) this->biquad->ProcessSample(sample);
                    buffer[bufferOffset - size + i / 2] = x;
                }

                if (this->polyphase->Process(samples, size) == size) {
                    for (uint32_t i = 0; i < size * 2; i += 2) {
                        float x = buffer[i / 2] * this->bassFactor;
                        samples[i] += x;
                        samples[i + 1] += x;
                    }
                    this->waveBuffer->PopSamples(size, true);
                }
            }
            break;
        }
        case ProcessMode::SUBWOOFER: {
            this->subwoofer->Process(samples, size);
            break;
        }
    }
}

void ViPERBass::Reset() {
    this->polyphase->SetSamplingRate(this->samplingRate);
    this->polyphase->Reset();
    this->waveBuffer->Reset();
    this->waveBuffer->PushZeros(this->polyphase->GetLatency());
    this->subwoofer->SetBassGain(this->samplingRate, this->bassFactor * 2.5f);
    this->biquad->SetLowPassParameter((float) this->speaker, this->samplingRate, 0.53);
    this->samplingRatePeriod = 1.0f / (float) this->samplingRate;
    this->antiPop = 0.0f;
}

void ViPERBass::SetBassFactor(float bassFactor) {
    if (this->bassFactor != bassFactor) {
        this->bassFactor = bassFactor;
        this->subwoofer->SetBassGain(this->samplingRate, this->bassFactor * 2.5f);
    }
}

void ViPERBass::SetEnable(bool enable) {
    if (this->enable != enable) {
        if (!this->enable) {
            Reset();
        }
        this->enable = enable;
    }
}

void ViPERBass::SetProcessMode(ProcessMode processMode) {
    if (this->processMode != processMode) {
        this->processMode = processMode;
        this->Reset();
    }
}

void ViPERBass::SetSamplingRate(uint32_t samplingRate) {
    if (this->samplingRate != samplingRate) {
        this->samplingRate = samplingRate;
        this->samplingRatePeriod = 1.0f / (float) samplingRate;
        this->polyphase->SetSamplingRate(this->samplingRate);
        this->biquad->SetLowPassParameter((float) this->speaker, this->samplingRate, 0.53);
        this->subwoofer->SetBassGain(this->samplingRate, this->bassFactor * 2.5f);
    }
}

void ViPERBass::SetSpeaker(uint32_t speaker) {
    if (this->speaker != speaker) {
        this->speaker = speaker;
        this->biquad->SetLowPassParameter((float) this->speaker, this->samplingRate, 0.53);
    }
}
