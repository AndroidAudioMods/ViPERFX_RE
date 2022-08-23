//
// Created by mart on 7/25/21.
//

#include "ProcessUnit_FX.h"
#include "Effect.h"
#include "constants.h"

ProcessUnit_FX::ProcessUnit_FX() {
    v4a_print(ANDROID_LOG_INFO, "Welcome to ViPER4Android Reworked driver[SQ]");
    v4a_printf(ANDROID_LOG_INFO, "Current version is %s %s", VERSION_STRING, VERSION_CODENAME);

    this->adaptiveBuffer = new AdaptiveBuffer_F32(2, 4096);
    this->waveBuffer = new WaveBuffer_I32(2, 4096);

    this->convolver = new Convolver();
//    this->convolver->SetEnable(false);
//    this->convolver->SetSamplingRate(this->sampleRate);
//    this->convolver->Reset();

    this->vhe = new VHE();
    this->vhe->SetEnable(false);
    this->vhe->SetSamplingRate(this->sampleRate);
    this->vhe->Reset();

    this->viperDdc = new ViPERDDC();
//    this->viperDdc->SetEnable(false);
//    this->viperDdc->SetSamplingRate(this->sampleRate);
//    this->viperDdc->Reset();

    this->spectrumExtend = new SpectrumExtend();
    this->spectrumExtend->SetEnable(false);
    this->spectrumExtend->SetSamplingRate(this->sampleRate);
    this->spectrumExtend->SetReferenceFrequency(7600);
    this->spectrumExtend->SetExciter(0);
    this->spectrumExtend->Reset();

    this->iirFilter = new IIRFilter();
//    this->iirFilter->SetEnable(false);
//    this->iirFilter->SetSamplingRate(this->sampleRate);
//    this->iirFilter->Reset();

    this->colorfulMusic = new ColorfulMusic();
//    this->colorfulMusic->SetEnable(false);
//    this->colorfulMusic->SetSamplingRate(this->sampleRate);
//    this->colorfulMusic->Reset();

    this->reverberation = new Reverberation();
    this->reverberation->SetEnable(false);
    this->reverberation->SetSamplingRate(this->sampleRate);
    this->reverberation->Reset();

    this->playbackGain = new PlaybackGain();
//    this->playbackGain->SetEnable(false);
//    this->playbackGain->SetSamplingRate(this->sampleRate);
//    this->playbackGain->Reset();

    this->fetCompressor = new FETCompressor();
//    this->fetCompressor->SetEnable(false);
//    this->fetCompressor->SetSamplingRate(this->sampleRate);
//    this->fetCompressor->Reset();

    this->dynamicSystem = new DynamicSystem();
    this->dynamicSystem->SetEnable(false);
    this->dynamicSystem->SetSamplingRate(this->sampleRate);
    this->dynamicSystem->Reset();

    this->viperBass = new ViPERBass();
//    this->viperBass->SetEnable(false);
//    this->viperBass->SetSamplingRate(this->sampleRate);
//    this->viperBass->Reset();

    this->viperClarity = new ViPERClarity();
    this->viperClarity->SetEnable(false);
    this->viperClarity->SetSamplingRate(this->sampleRate);
    this->viperClarity->Reset();

    this->diffSurround = new DiffSurround();
    this->diffSurround->SetEnable(false);
    this->diffSurround->SetSamplingRate(this->sampleRate);
    this->diffSurround->Reset();

    this->cure = new Cure();
    this->cure->SetEnable(false);
    this->cure->SetSamplingRate(this->sampleRate);
    this->cure->Reset();

    this->tubeSimulator = new TubeSimulator();
//    this->tubeSimulator->SetEnable(false);
//    this->tubeSimulator->SetSamplingRate(this->sampleRate);
    this->tubeSimulator->Reset();

    this->analogX = new AnalogX();
//    this->analogX->SetEnable(false);
    this->analogX->SetSamplingRate(this->sampleRate);
    this->analogX->SetProcessingModel(0);
    this->analogX->Reset();

    this->speakerCorrection = new SpeakerCorrection();
    this->speakerCorrection->SetEnable(false);
    this->speakerCorrection->SetSamplingRate(this->sampleRate);
    this->speakerCorrection->Reset();

    for (int i = 0; i < sizeof(softwareLimiters); i++) {
        this->softwareLimiters[i] = new SoftwareLimiter();
//        this->softwareLimiters[i]->ResetLimiter();
    }

    this->init_ok = true;

    this->enabled = false;
    this->force_enabled = false;
    this->mode = ViPER_FX_TYPE_NONE; // 0
}

ProcessUnit_FX::~ProcessUnit_FX() {
    if (this->adaptiveBuffer != nullptr) {
        delete this->adaptiveBuffer;
        this->adaptiveBuffer = nullptr;
    }
    if (this->waveBuffer != nullptr) {
        delete this->waveBuffer;
        this->waveBuffer = nullptr;
    }
    if (this->convolver != nullptr) {
        delete this->convolver;
        this->convolver = nullptr;
    }
    if (this->vhe != nullptr) {
        delete this->vhe;
        this->vhe = nullptr;
    }
    if (this->viperDdc != nullptr) {
        delete this->viperDdc;
        this->viperDdc = nullptr;
    }
    if (this->spectrumExtend != nullptr) {
        delete this->spectrumExtend;
        this->spectrumExtend = nullptr;
    }
    if (this->iirFilter != nullptr) {
        delete this->iirFilter;
        this->iirFilter = nullptr;
    }
    if (this->colorfulMusic != nullptr) {
        delete this->colorfulMusic;
        this->colorfulMusic = nullptr;
    }
    if (this->reverberation != nullptr) {
        delete this->reverberation;
        this->reverberation = nullptr;
    }
    if (this->playbackGain != nullptr) {
        delete this->playbackGain;
        this->playbackGain = nullptr;
    }
    if (this->fetCompressor != nullptr) {
        delete this->fetCompressor;
        this->fetCompressor = nullptr;
    }
    if (this->dynamicSystem != nullptr) {
        delete this->dynamicSystem;
        this->dynamicSystem = nullptr;
    }
    if (this->viperBass != nullptr) {
        delete this->viperBass;
        this->viperBass = nullptr;
    }
    if (this->viperClarity != nullptr) {
        delete this->viperClarity;
        this->viperClarity = nullptr;
    }
    if (this->diffSurround != nullptr) {
        delete this->diffSurround;
        this->diffSurround = nullptr;
    }
    if (this->cure != nullptr) {
        delete this->cure;
        this->cure = nullptr;
    }
    if (this->tubeSimulator != nullptr) {
        delete this->tubeSimulator;
        this->tubeSimulator = nullptr;
    }
    if (this->analogX != nullptr) {
        delete this->analogX;
        this->analogX = nullptr;
    }
    if (this->speakerCorrection != nullptr) {
        delete this->speakerCorrection;
        this->speakerCorrection = nullptr;
    }
    for (int i = 0; i < sizeof(softwareLimiters); i++) {
        if (softwareLimiters[i] != nullptr) {
            delete softwareLimiters[i];
            softwareLimiters[i] = nullptr;
        }
    }
}

int32_t
ProcessUnit_FX::command(uint32_t cmdCode, uint32_t cmdSize, void *pCmdData, uint32_t *replySize, void *pReplyData) {
    // TODO
    return -1;
}

void ProcessUnit_FX::processBuffer(float *buffer, int frameSize) {
    // TODO
}

void ProcessUnit_FX::DispatchCommand(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6,
                                     int param_7) {
    // TODO
}

void ProcessUnit_FX::ResetAllEffects() {
    if (this->adaptiveBuffer != nullptr) {
//        this->adaptiveBuffer->FlushBuffer();
    }
    if (this->waveBuffer != nullptr) {
        this->waveBuffer->Reset();
    }
    if (this->convolver != nullptr) {
//        this->convolver->SetSamplingRate(this->sampleRate);
//        this->convolver->Reset();
    }
    if (this->vhe != nullptr) {
        this->vhe->SetSamplingRate(this->sampleRate);
        this->vhe->Reset();
    }
    if (this->viperDdc != nullptr) {
//        this->viperDdc->SetSamplingRate(this->sampleRate);
//        this->viperDdc->Reset();
    }
    if (this->spectrumExtend != nullptr) {
        this->spectrumExtend->SetSamplingRate(this->sampleRate);
        this->spectrumExtend->Reset();
    }
    if (this->iirFilter != nullptr) {
//        this->iirFilter->SetSamplingRate(this->sampleRate);
//        this->iirFilter->Reset();
    }
    if (this->colorfulMusic != nullptr) {
//        this->colorfulMusic->SetSamplingRate(this->sampleRate);
//        this->colorfulMusic->Reset();
    }
    if (this->reverberation != nullptr) {
        this->reverberation->SetSamplingRate(this->sampleRate);
        this->reverberation->Reset();
    }
    if (this->playbackGain != nullptr) {
//        this->playbackGain->SetSamplingRate(this->sampleRate);
//        this->playbackGain->Reset();
    }
    if (this->fetCompressor != nullptr) {
//        this->fetCompressor->SetSamplingRate(this->sampleRate);
//        this->fetCompressor->Reset();
    }
    if (this->dynamicSystem != nullptr) {
        this->dynamicSystem->SetSamplingRate(this->sampleRate);
        this->dynamicSystem->Reset();
    }
    if (this->viperBass != nullptr) {
//        this->viperBass->SetSamplingRate(this->sampleRate);
//        this->viperBass->Reset();
    }
    if (this->viperClarity != nullptr) {
        this->viperClarity->SetSamplingRate(this->sampleRate);
        this->viperClarity->Reset();
    }
    if (this->diffSurround != nullptr) {
        this->diffSurround->SetSamplingRate(this->sampleRate);
        this->diffSurround->Reset();
    }
    if (this->cure != nullptr) {
        this->cure->SetSamplingRate(this->sampleRate);
        this->cure->Reset();
    }
    if (this->tubeSimulator != nullptr) {
//        this->tubeSimulator->Reset();
    }
    if (this->analogX != nullptr) {
        this->analogX->SetSamplingRate(this->sampleRate);
        this->analogX->Reset();
    }
    if (this->speakerCorrection != nullptr) {
        this->speakerCorrection->SetSamplingRate(this->sampleRate);
        this->speakerCorrection->Reset();
    }
    for (int i = 0; i < sizeof(softwareLimiters); i++) {
        if (softwareLimiters[i] != nullptr) {
//            softwareLimiters[i]->Reset();
        }
    }
}
