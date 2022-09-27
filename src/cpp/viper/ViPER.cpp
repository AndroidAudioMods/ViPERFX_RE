#include "ViPER.h"
#include <ctime>
#include "constants.h"

ViPER::ViPER() {
    VIPER_LOGI("Welcome to ViPER FX");
    VIPER_LOGI("Current version is %s %s", VERSION_STRING, VERSION_CODENAME);

    this->adaptiveBuffer = new AdaptiveBuffer(2, 4096);
    this->waveBuffer = new WaveBuffer(2, 4096);

    this->convolver = new Convolver();
    this->convolver->SetEnable(false);
    this->convolver->SetSamplingRate(this->samplingRate);
    this->convolver->Reset();

    this->vhe = new VHE();
    this->vhe->SetEnable(false);
    this->vhe->SetSamplingRate(this->samplingRate);
    this->vhe->Reset();

    this->viperDdc = new ViPERDDC();
    this->viperDdc->SetEnable(false);
    this->viperDdc->SetSamplingRate(this->samplingRate);
    this->viperDdc->Reset();

    this->spectrumExtend = new SpectrumExtend();
    this->spectrumExtend->SetEnable(false);
    this->spectrumExtend->SetSamplingRate(this->samplingRate);
    this->spectrumExtend->SetReferenceFrequency(7600);
    this->spectrumExtend->SetExciter(0);
    this->spectrumExtend->Reset();

    this->iirFilter = new IIRFilter(10);
    this->iirFilter->SetEnable(false);
    this->iirFilter->SetSamplingRate(this->samplingRate);
    this->iirFilter->Reset();

    this->colorfulMusic = new ColorfulMusic();
    this->colorfulMusic->SetEnable(false);
    this->colorfulMusic->SetSamplingRate(this->samplingRate);
    this->colorfulMusic->Reset();

    this->reverberation = new Reverberation();
    this->reverberation->SetEnable(false);
    this->reverberation->SetSamplingRate(this->samplingRate);
    this->reverberation->Reset();

    this->playbackGain = new PlaybackGain();
    this->playbackGain->SetEnable(false);
    this->playbackGain->SetSamplingRate(this->samplingRate);
    this->playbackGain->Reset();

    this->fetCompressor = new FETCompressor();
    this->fetCompressor->SetParameter(0, 0.0);
    this->fetCompressor->SetSamplingRate(this->samplingRate);
    this->fetCompressor->Reset();

    this->dynamicSystem = new DynamicSystem();
    this->dynamicSystem->SetEnable(false);
    this->dynamicSystem->SetSamplingRate(this->samplingRate);
    this->dynamicSystem->Reset();

    this->viperBass = new ViPERBass();
    this->viperBass->SetSamplingRate(this->samplingRate);
    this->viperBass->Reset();

    this->viperClarity = new ViPERClarity();
    this->viperClarity->SetSamplingRate(this->samplingRate);
    this->viperClarity->Reset();

    this->diffSurround = new DiffSurround();
    this->diffSurround->SetEnable(false);
    this->diffSurround->SetSamplingRate(this->samplingRate);
    this->diffSurround->Reset();

    this->cure = new Cure();
    this->cure->SetEnable(false);
    this->cure->SetSamplingRate(this->samplingRate);
    this->cure->Reset();

    this->tubeSimulator = new TubeSimulator();
    this->tubeSimulator->enabled = false; //SetEnable(false);
    this->tubeSimulator->Reset();

    this->analogX = new AnalogX();
//    this->analogX->SetEnable(false);
    this->analogX->SetSamplingRate(this->samplingRate);
    this->analogX->SetProcessingModel(0);
    this->analogX->Reset();

    this->speakerCorrection = new SpeakerCorrection();
    this->speakerCorrection->SetEnable(false);
    this->speakerCorrection->SetSamplingRate(this->samplingRate);
    this->speakerCorrection->Reset();

    for (auto &softwareLimiter: this->softwareLimiters) {
        softwareLimiter = new SoftwareLimiter();
        softwareLimiter->ResetLimiter();
    }

    this->fetcomp_enabled = false;
    this->init_ok = true;
    this->frame_scale = 1.0;
    this->left_pan = 1.0;
    this->process_time_ms = 0;
    this->right_pan = 1.0;
    this->enabled = false;
    this->force_enabled = false;
    this->update_status = false;
}

ViPER::~ViPER() {
    delete this->adaptiveBuffer;
    delete this->waveBuffer;
    delete this->convolver;
    delete this->vhe;
    delete this->viperDdc;
    delete this->spectrumExtend;
    delete this->iirFilter;
    delete this->colorfulMusic;
    delete this->reverberation;
    delete this->playbackGain;
    delete this->fetCompressor;
    delete this->dynamicSystem;
    delete this->viperBass;
    delete this->viperClarity;
    delete this->diffSurround;
    delete this->cure;
    delete this->tubeSimulator;
    delete this->analogX;
    delete this->speakerCorrection;
    for (auto &softwareLimiter: this->softwareLimiters) {
        delete softwareLimiter;
    }
}

// TODO: Return int
void ViPER::processBuffer(float *buffer, uint32_t size) {
    if (!this->enabled) return;
    if (size == 0) return;
    if (!this->init_ok) return;

    if (this->update_status) {
        struct timeval time{};
        gettimeofday(&time, nullptr);
        this->process_time_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
    }

    uint32_t ret;

    // if convolver is enabled
    ret = this->waveBuffer->PushSamples(buffer, size);
    if (ret == 0) {
        this->waveBuffer->Reset();
        return;
    }

    auto pWaveBuffer = this->waveBuffer->GetBuffer();
    this->convolver->Process(pWaveBuffer, pWaveBuffer, size);
    this->vhe->Process(pWaveBuffer, pWaveBuffer, size);
    this->waveBuffer->SetBufferOffset(size);

    ret = this->adaptiveBuffer->PushZero(size);
    if (ret == 0) {
        this->waveBuffer->Reset();
        this->adaptiveBuffer->FlushBuffer();
        return;
    }

    auto pAdaptiveBuffer = this->adaptiveBuffer->GetBufferPointer();
    ret = this->waveBuffer->PopSamples((float *) pAdaptiveBuffer, size, true);
    this->adaptiveBuffer->SetBufferOffset(ret);

    pAdaptiveBuffer = this->adaptiveBuffer->GetBufferPointer();
    if (ret != 0) {
        this->viperDdc->Process(pAdaptiveBuffer, size);
        this->spectrumExtend->Process(pAdaptiveBuffer, size);
        this->iirFilter->Process(pAdaptiveBuffer, ret);
        this->colorfulMusic->Process(pAdaptiveBuffer, ret);
        this->diffSurround->Process(pAdaptiveBuffer, ret);
        this->reverberation->Process(pAdaptiveBuffer, ret);
        this->speakerCorrection->Process(pAdaptiveBuffer, ret);
        this->playbackGain->Process(pAdaptiveBuffer, ret);
        this->fetCompressor->Process(pAdaptiveBuffer, ret);
        this->dynamicSystem->Process(pAdaptiveBuffer, ret);
        this->viperBass->Process(pAdaptiveBuffer, ret);
        this->viperClarity->Process(pAdaptiveBuffer, ret);
        this->cure->Process(pAdaptiveBuffer, ret);
        this->tubeSimulator->TubeProcess(pAdaptiveBuffer, size);
        this->analogX->Process(pAdaptiveBuffer, ret);
    }

    if (this->frame_scale != 1.0) {
        this->adaptiveBuffer->ScaleFrames(this->frame_scale);
    }
    if (this->left_pan < 1.0 || this->right_pan < 1.0) {
        this->adaptiveBuffer->PanFrames(this->left_pan, this->right_pan);
    }

    if (ret << 1 != 0) {

    }

}

void ViPER::DispatchCommand(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6,
                            int param_7) {
    // TODO
}

void ViPER::ResetAllEffects() {
    if (this->adaptiveBuffer != nullptr) {
        this->adaptiveBuffer->FlushBuffer();
    }
    if (this->waveBuffer != nullptr) {
        this->waveBuffer->Reset();
    }
    if (this->convolver != nullptr) {
        this->convolver->SetSamplingRate(this->samplingRate);
        this->convolver->Reset();
    }
    if (this->vhe != nullptr) {
        this->vhe->SetSamplingRate(this->samplingRate);
        this->vhe->Reset();
    }
    if (this->viperDdc != nullptr) {
        this->viperDdc->SetSamplingRate(this->samplingRate);
        this->viperDdc->Reset();
    }
    if (this->spectrumExtend != nullptr) {
        this->spectrumExtend->SetSamplingRate(this->samplingRate);
        this->spectrumExtend->Reset();
    }
    if (this->iirFilter != nullptr) {
        this->iirFilter->SetSamplingRate(this->samplingRate);
        this->iirFilter->Reset();
    }
    if (this->colorfulMusic != nullptr) {
        this->colorfulMusic->SetSamplingRate(this->samplingRate);
        this->colorfulMusic->Reset();
    }
    if (this->reverberation != nullptr) {
        this->reverberation->SetSamplingRate(this->samplingRate);
        this->reverberation->Reset();
    }
    if (this->playbackGain != nullptr) {
        this->playbackGain->SetSamplingRate(this->samplingRate);
        this->playbackGain->Reset();
    }
    if (this->fetCompressor != nullptr) {
        this->fetCompressor->SetSamplingRate(this->samplingRate);
        this->fetCompressor->Reset();
    }
    if (this->dynamicSystem != nullptr) {
        this->dynamicSystem->SetSamplingRate(this->samplingRate);
        this->dynamicSystem->Reset();
    }
    if (this->viperBass != nullptr) {
        this->viperBass->SetSamplingRate(this->samplingRate);
        this->viperBass->Reset();
    }
    if (this->viperClarity != nullptr) {
        this->viperClarity->SetSamplingRate(this->samplingRate);
        this->viperClarity->Reset();
    }
    if (this->diffSurround != nullptr) {
        this->diffSurround->SetSamplingRate(this->samplingRate);
        this->diffSurround->Reset();
    }
    if (this->cure != nullptr) {
        this->cure->SetSamplingRate(this->samplingRate);
        this->cure->Reset();
    }
    if (this->tubeSimulator != nullptr) {
        this->tubeSimulator->Reset();
    }
    if (this->analogX != nullptr) {
        this->analogX->SetSamplingRate(this->samplingRate);
        this->analogX->Reset();
    }
    if (this->speakerCorrection != nullptr) {
        this->speakerCorrection->SetSamplingRate(this->samplingRate);
        this->speakerCorrection->Reset();
    }
    for (auto &softwareLimiter: softwareLimiters) {
        if (softwareLimiter != nullptr) {
            softwareLimiter->ResetLimiter();
        }
    }
}
