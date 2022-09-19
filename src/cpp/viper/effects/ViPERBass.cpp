#include "ViPERBass.h"
#include "../constants.h"

ViPERBass::ViPERBass() {
    this->samplingRate = DEFAULT_SAMPLERATE;
    this->speaker = 60;
    this->invertedSamplingRate = 1.0f / DEFAULT_SAMPLERATE;
    this->antiPop = 0.0;
    this->processMode = ProcessMode::NATURAL_BASS;
    this->bassFactor = 0.0f;
    this->polyphase = new Polyphase(2);
    this->biquad = new Biquad();
    this->subwoofer = new Subwoofer();
    this->waveBuffer = new WaveBuffer(1, 0x1000);

    this->biquad->Reset();
    this->biquad->SetLowPassParameter(this->speaker, this->samplingRate, 0.53);
    this->subwoofer->SetBassGain(this->samplingRate, 0.0);
    this->Reset();
}

ViPERBass::~ViPERBass() {
    delete this->polyphase;
    this->polyphase = nullptr;

    delete this->biquad;
    this->biquad = nullptr;

    delete this->subwoofer;
    this->subwoofer = nullptr;

    delete this->waveBuffer;
    this->waveBuffer = nullptr;
}

void ViPERBass::Process(float *samples, uint32_t size) {
    if (size == 0) {
        return;
    }

    if (this->antiPop < 1.0) {
        for (uint32_t i = 0; i < size * 2; i += 2) {
            samples[i] *= this->antiPop;
            samples[i + 1] *= this->antiPop;
            
            float x = this->antiPop + this->invertedSamplingRate;
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
                auto x = (float) this->biquad->ProcessSample(sample);
                samples[i] += x;
                samples[i + 1] += x;
            }
            break;
        }
        case ProcessMode::PURE_BASS_PLUS: {
            if (this->waveBuffer->PushSamples(samples, size) != 0) {
                float *buffer = this->waveBuffer->GetBuffer();
                uint32_t bufferOffset = this->waveBuffer->GetBufferOffset();

                for (uint32_t i = 0; i < size * 2; i += 2) {
                    double sample = ((double) samples[i] + (double) samples[i + 1]) / 2.0;
                    auto x = (float) this->biquad->ProcessSample(sample);
                    buffer[bufferOffset - size + i / 2] = x;
                }

                if (this->polyphase->Process(samples, size) == size) {
                    for (uint32_t i = 0; i < size * 2; i += 2) {
                        samples[i] += buffer[i / 2] * this->bassFactor;
                        samples[i + 1] += buffer[i / 2] * this->bassFactor;
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
    this->biquad->SetLowPassParameter(this->speaker, this->samplingRate, 0.53);
    this->antiPop = 0.0f;
    this->invertedSamplingRate = 1.0f / (float) this->samplingRate;
}

void ViPERBass::SetBassFactor(float bassFactor) {
    if (this->bassFactor != bassFactor) {
        this->bassFactor = bassFactor;
        this->subwoofer->SetBassGain(this->samplingRate, this->bassFactor * 2.5f);
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
        this->invertedSamplingRate = 1.0f / (float) samplingRate;
        this->polyphase->SetSamplingRate(samplingRate);
        this->biquad->SetLowPassParameter(this->speaker, samplingRate, 0.53);
        this->subwoofer->SetBassGain(samplingRate, this->bassFactor * 2.5);
    }
}

void ViPERBass::SetSpeaker(uint32_t speaker) {
    if (this->speaker != speaker) {
        this->speaker = speaker;
        this->biquad->SetLowPassParameter(this->speaker, this->samplingRate, 0.53);
    }
}
