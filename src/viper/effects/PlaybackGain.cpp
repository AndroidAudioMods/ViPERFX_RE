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

PlaybackGain::~PlaybackGain() {

}

void PlaybackGain::AnalyseWave() {

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
    this->enable = enable;
    if (enable) {
        Reset();
    }
}

void PlaybackGain::SetMaxGainFactor(float maxGainFactor) {
    this->maxGainFactor = maxGainFactor;
}

void PlaybackGain::SetRatio(float ratio) {
    this->ratio1 = ratio + 1.0f;
    this->ratio2 = 1.0f / (ratio + 1.0f);
}

void PlaybackGain::SetSamplingRate(uint32_t samplingRate) {
    this->samplingRate = samplingRate;
    Reset();
}

void PlaybackGain::SetVolume(float volume) {
    this->volume = volume;
}
