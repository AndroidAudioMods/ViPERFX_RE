#include <cmath>
#include "PlaybackGain.h"
#include "../constants.h"

PlaybackGain::PlaybackGain() {
    this->enable = false;
    this->samplingRate = VIPER_DEFAULT_SAMPLING_RATE;
    this->unknown1 = 0.4342945;
    this->counterTo100 = 0;
    this->ratio1 = 2.0;
    this->ratio2 = 0.5;
    this->volume = 1.0;
    this->maxGainFactor = 1.0;
    this->unknown2 = 1.0;
    this->unknown3 = 1.0;
    this->biquad1.SetBandPassParameter(2200.0,this->samplingRate,0.33);
    this->biquad2.SetBandPassParameter(2200.0,this->samplingRate,0.33);
}

float PlaybackGain::AnalyseWave(float *samples, uint32_t size) {
    if (size == 0) return 0.0;

    double tmpL = 0.0;
    double tmpR = 0.0;

    for (uint32_t i = 0; i < size * 2; i += 2) {
        double tmpL2 = this->biquad1.ProcessSample(samples[i]);
        tmpL += tmpL2 * tmpL2;

        double tmpR2 = this->biquad2.ProcessSample(samples[i + 1]);
        tmpR += tmpR2 * tmpR2;
    }

    float tmp = tmpL;

    return tmp / (float) size;
}

void PlaybackGain::Process(float *samples, uint32_t size) {

}

void PlaybackGain::Reset() {
    this->biquad1.SetBandPassParameter(2200.0,this->samplingRate,0.33);
    this->biquad2.SetBandPassParameter(2200.0,this->samplingRate,0.33);
    this->unknown2 = 1.0;
    this->counterTo100 = 0;
    this->unknown3 = 1.0;
}

void PlaybackGain::SetEnable(bool enable) {
    if (this->enable != enable) {
        this->enable = enable;
        if (enable) {
            Reset();
        }
    }
}

void PlaybackGain::SetMaxGainFactor(float maxGainFactor) {
    this->maxGainFactor = maxGainFactor;
}

void PlaybackGain::SetRatio(float ratio) {
    this->ratio1 = ratio + 1.0f;
    this->ratio2 = 1.0f / this->ratio1;
}

void PlaybackGain::SetSamplingRate(uint32_t samplingRate) {
    if (this->samplingRate != samplingRate) {
        this->samplingRate = samplingRate;
        Reset();
    }
}

void PlaybackGain::SetVolume(float volume) {
    this->volume = volume;
}
