#include "ViPER.h"
#include <ctime>
#include <cstring>
#include "constants.h"

ViPER::ViPER() {
    VIPER_LOGI("Welcome to ViPER FX");
    VIPER_LOGI("Current version is %s (%d)", VERSION_NAME, VERSION_CODE);

    this->samplingRate = VIPER_DEFAULT_SAMPLING_RATE;

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
    this->reverberation->Reset();

    this->playbackGain = new PlaybackGain();
    this->playbackGain->SetEnable(false);
    this->playbackGain->SetSamplingRate(this->samplingRate);
    this->playbackGain->Reset();

    this->fetCompressor = new FETCompressor();
    this->fetCompressor->SetParameter(FETCompressor::ENABLE, 0.0);
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
    this->tubeSimulator->SetEnable(false);
    this->tubeSimulator->Reset();

    this->analogX = new AnalogX();
    this->analogX->SetEnable(false);
    this->analogX->SetSamplingRate(this->samplingRate);
    this->analogX->SetProcessingModel(0);
    this->analogX->Reset();

    this->speakerCorrection = new SpeakerCorrection();
    this->speakerCorrection->SetEnable(false);
    this->speakerCorrection->SetSamplingRate(this->samplingRate);
    this->speakerCorrection->Reset();

    for (auto &softwareLimiter: this->softwareLimiters) {
        softwareLimiter = new SoftwareLimiter();
        softwareLimiter->Reset();
    }

    this->frameScale = 1.0;
    this->leftPan = 1.0;
    this->rightPan = 1.0;
    this->updateProcessTime = false;
    this->processTimeMs = 0;
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
    if (size == 0) {
        VIPER_LOGD("Buffer size is 0, skip processing");
        return;
    }

    if (this->updateProcessTime) {
        struct timeval time{};
        gettimeofday(&time, nullptr);
        this->processTimeMs = (uint64_t) (time.tv_sec * 1000) + (uint64_t) (time.tv_usec / 1000);
    }

    uint32_t ret;
    float *tmpBuf;
    uint32_t tmpBufSize;

    if (this->convolver->GetEnabled() || this->vhe->GetEnabled()) {
//        VIPER_LOGD("Convolver or VHE is enable, use wave buffer");

        if (!this->waveBuffer->PushSamples(buffer, size)) {
            this->waveBuffer->Reset();
            return;
        }

        float *ptr = this->waveBuffer->GetBuffer();
        ret = this->convolver->Process(ptr, ptr, size);
        ret = this->vhe->Process(ptr, ptr, ret);
        this->waveBuffer->SetBufferOffset(ret);

        if (!this->adaptiveBuffer->PushZero(ret)) {
            this->waveBuffer->Reset();
            this->adaptiveBuffer->FlushBuffer();
            return;
        }

        ptr = this->adaptiveBuffer->GetBuffer();
        ret = this->waveBuffer->PopSamples(ptr, ret, true);
        this->adaptiveBuffer->SetBufferOffset(ret);

        tmpBuf = ptr;
        tmpBufSize = ret;
    } else {
//        VIPER_LOGD("Convolver and VHE are disabled, use adaptive buffer");

        if (this->adaptiveBuffer->PushFrames(buffer, size)) {
            this->adaptiveBuffer->SetBufferOffset(size);

            tmpBuf = this->adaptiveBuffer->GetBuffer();
            tmpBufSize = size;
        } else {
            this->adaptiveBuffer->FlushBuffer();
            return;
        }
    }

//    VIPER_LOGD("Process buffer size: %d", tmpBufSize);
    if (tmpBufSize != 0) {
        this->viperDdc->Process(tmpBuf, size);
        this->spectrumExtend->Process(tmpBuf, size);
        this->iirFilter->Process(tmpBuf, tmpBufSize);
        this->colorfulMusic->Process(tmpBuf, tmpBufSize);
        this->diffSurround->Process(tmpBuf, tmpBufSize);
        this->reverberation->Process(tmpBuf, tmpBufSize);
        this->speakerCorrection->Process(tmpBuf, tmpBufSize);
        this->playbackGain->Process(tmpBuf, tmpBufSize);
        this->fetCompressor->Process(tmpBuf, tmpBufSize); // TODO: enable check
        this->dynamicSystem->Process(tmpBuf, tmpBufSize);
        this->viperBass->Process(tmpBuf, tmpBufSize);
        this->viperClarity->Process(tmpBuf, tmpBufSize);
        this->cure->Process(tmpBuf, tmpBufSize);
        this->tubeSimulator->TubeProcess(tmpBuf, size);
        this->analogX->Process(tmpBuf, tmpBufSize);

        if (this->frameScale != 1.0) {
            this->adaptiveBuffer->ScaleFrames(this->frameScale);
        }

        if (this->leftPan < 1.0 || this->rightPan < 1.0) {
            this->adaptiveBuffer->PanFrames(this->leftPan, this->rightPan);
        }

        for (uint32_t i = 0; i < tmpBufSize * 2; i += 2) {
            tmpBuf[i] = this->softwareLimiters[0]->Process(tmpBuf[i]);
            tmpBuf[i + 1] = this->softwareLimiters[1]->Process(tmpBuf[i + 1]);
        }

        if (!this->adaptiveBuffer->PopFrames(buffer, tmpBufSize)) {
            this->adaptiveBuffer->FlushBuffer();
            return;
        }

        if (size <= tmpBufSize) {
            return;
        }
    }

    memmove(buffer + (size - tmpBufSize) * 2, buffer, tmpBufSize * sizeof(float));
    memset(buffer, 0, (size - tmpBufSize) * sizeof(float));
}

void ViPER::DispatchCommand(int param, int val1, int val2, int val3, int val4, uint32_t arrSize,
                            signed char *arr) {
    VIPER_LOGD("Dispatch command: %d, %d, %d, %d, %d, %d, %p", param, val1, val2, val3, val4, arrSize, arr);
    switch (param) {
        case PARAM_SET_UPDATE_STATUS: {
            this->updateProcessTime = val1 != 0;
            break;
        }
        case PARAM_SET_RESET_STATUS: {
            this->ResetAllEffects();
            break;
        }
        case PARAM_CONVOLUTION_ENABLE: {
//            this->convolver->SetEnabled(val1 != 0);
            break;
        } // 0x10002
        case PARAM_CONVOLUTION_PREPARE_BUFFER: {
            break;
        } // 0x10004
        case PARAM_CONVOLUTION_SET_BUFFER: {
            break;
        } // 0x10005
        case PARAM_CONVOLUTION_COMMIT_BUFFER: {
            break;
        } // 0x10006
        case PARAM_CONVOLUTION_CROSS_CHANNEL: {
            this->convolver->SetCrossChannel((float) val1 / 100.0f);
            break;
        } // 0x10007
        case PARAM_HEADPHONE_SURROUND_ENABLE: {
            this->vhe->SetEnable(val1 != 0);
            break;
        } // 0x10008
        case PARAM_HEADPHONE_SURROUND_STRENGTH: {
            this->vhe->SetEffectLevel(val1);
            break;
        } // 0x10009
        case PARAM_DDC_ENABLE: {
            this->viperDdc->SetEnable(val1 != 0);
            break;
        } // 0x1000A
        case PARAM_DDC_COEFFICIENTS: {
            this->viperDdc->SetCoeffs(arrSize, (float *) arr, (float *) (arr + arrSize * 4));
            break;
        } // 0x1000B
        case PARAM_SPECTRUM_EXTENSION_ENABLE: {
            this->spectrumExtend->SetEnable(val1 != 0);
            break;
        } // 0x1000C
        case PARAM_SPECTRUM_EXTENSION_BARK: {
            this->spectrumExtend->SetReferenceFrequency(val1);
            break;
        } // 0x1000D
        case PARAM_SPECTRUM_EXTENSION_BARK_RECONSTRUCT: {
            this->spectrumExtend->SetExciter((float) val1 / 100.0f);
            break;
        } // 0x1000E
        case PARAM_FIR_EQUALIZER_ENABLE: {
            this->iirFilter->SetEnable(val1 != 0);
            break;
        } // 0x1000F
        case PARAM_FIR_EQUALIZER_BAND_LEVEL: {
            this->iirFilter->SetBandLevel((uint32_t) val1, (float) val2 / 100.0f);
            break;
        } // 0x10010
        case PARAM_FIELD_SURROUND_ENABLE: {
            this->colorfulMusic->SetEnable(val1 != 0);
            break;
        } // 0x10011
        case PARAM_FIELD_SURROUND_WIDENING: {
            this->colorfulMusic->SetWidenValue((float) val1 / 100.0f);
            break;
        } // 0x10012
        case PARAM_FIELD_SURROUND_MID_IMAGE: {
            this->colorfulMusic->SetMidImageValue((float) val1 / 100.0f);
            break;
        } // 0x10013
        case PARAM_FIELD_SURROUND_DEPTH: {
            this->colorfulMusic->SetDepthValue((short) val1);
            break;
        } // 0x10014
        case PARAM_DIFFERENTIAL_SURROUND_ENABLE: {
            this->diffSurround->SetEnable(val1 != 0);
            break;
        } // 0x10015
        case PARAM_DIFFERENTIAL_SURROUND_DELAY: {
            this->diffSurround->SetDelayTime((float) val1 / 100.0f);
            break;
        } // 0x10016
        case PARAM_REVERBERATION_ENABLE: {
            this->reverberation->SetEnable(val1 != 0);
            break;
        } // 0x10017
        case PARAM_REVERBERATION_ROOM_SIZE: {
            this->reverberation->SetRoomSize((float) val1 / 100.0f);
            break;
        } // 0x10018
        case PARAM_REVERBERATION_ROOM_WIDTH: {
            this->reverberation->SetWidth((float) val1 / 100.0f);
            break;
        } // 0x10019
        case PARAM_REVERBERATION_ROOM_DAMPENING: {
            this->reverberation->SetDamp((float) val1 / 100.0f);
            break;
        } // 0x1001A
        case PARAM_REVERBERATION_ROOM_WET_SIGNAL: {
            this->reverberation->SetWet((float) val1 / 100.0f);
            break;
        } // 0x1001B
        case PARAM_REVERBERATION_ROOM_DRY_SIGNAL: {
            this->reverberation->SetDry((float) val1 / 100.0f);
            break;
        } // 0x1001C
        case PARAM_AUTOMATIC_GAIN_CONTROL_ENABLE: {
            this->playbackGain->SetEnable(val1 != 0);
            break;
        } // 0x1001D
        case PARAM_AUTOMATIC_GAIN_CONTROL_RATIO: {
            this->playbackGain->SetRatio((float) val1 / 100.0f);
            break;
        } // 0x1001E
        case PARAM_AUTOMATIC_GAIN_CONTROL_VOLUME: {
            this->playbackGain->SetVolume((float) val1 / 100.0f);
            break;
        } // 0x1001F
        case PARAM_AUTOMATIC_GAIN_CONTROL_MAX_SCALER: {
            this->playbackGain->SetMaxGainFactor((float) val1 / 100.0f);
            break;
        } // 0x10020
        case PARAM_DYNAMIC_SYSTEM_ENABLE: {
            this->dynamicSystem->SetEnable(val1 != 0);
            break;
        } // 0x10021
        case PARAM_DYNAMIC_SYSTEM_X_COEFFICIENTS: {
            this->dynamicSystem->SetXCoeffs(val1, val2);
            break;
        } // 0x10022
        case PARAM_DYNAMIC_SYSTEM_Y_COEFFICIENTS: {
            this->dynamicSystem->SetYCoeffs(val1, val2);
            break;
        } // 0x10023
        case PARAM_DYNAMIC_SYSTEM_SIDE_GAIN: {
            this->dynamicSystem->SetSideGain((float) val1 / 100.0f, (float) val2 / 100.0f);
            break;
        } // 0x10024
        case PARAM_DYNAMIC_SYSTEM_STRENGTH: {
            this->dynamicSystem->SetBassGain((float) val1 / 100.0f);
            break;
        } // 0x10025
        case PARAM_FIDELITY_BASS_ENABLE: {
            this->viperBass->SetEnable(val1 != 0);
            break;
        } // 0x10026
        case PARAM_FIDELITY_BASS_MODE: {
            this->viperBass->SetProcessMode((ViPERBass::ProcessMode) val1);
            break;
        } // 0x10027
        case PARAM_FIDELITY_BASS_FREQUENCY: {
            this->viperBass->SetSpeaker((uint32_t) val1);
            break;
        } // 0x10028
        case PARAM_FIDELITY_BASS_GAIN: {
            this->viperBass->SetBassFactor((float) val1 / 100.0f);
            break;
        } // 0x10029
        case PARAM_FIDELITY_CLARITY_ENABLE: {
            this->viperClarity->SetEnable(val1 != 0);
            break;
        } // 0x1002A
        case PARAM_FIDELITY_CLARITY_MODE: {
            this->viperClarity->SetProcessMode((ViPERClarity::ClarityMode) val1);
            break;
        } // 0x1002B
        case PARAM_FIDELITY_CLARITY_GAIN: {
            this->viperClarity->SetClarity((float) val1 / 100.0f);
            break;
        } // 0x1002C
        case PARAM_CURE_CROSS_FEED_ENABLED: {
            this->cure->SetEnable(val1 != 0);
            break;
        } // 0x1002D
        case PARAM_CURE_CROSS_FEED_STRENGTH: {
            switch (val1) {
                case 0: {
                    // Cure_R::SetPreset(pCVar17,0x5f028a);
                    struct Crossfeed::Preset preset = {
                            .cutoff = 650,
                            .feedback = 95,
                    };
                    this->cure->SetPreset(preset);
                    break;
                }
                case 1: {
                    // Cure_R::SetPreset(pCVar17,0x3c02bc);
                    struct Crossfeed::Preset preset = {
                            .cutoff = 700,
                            .feedback = 60,
                    };
                    this->cure->SetPreset(preset);
                    break;
                }
                case 2: {
                    // Cure_R::SetPreset(pCVar17,0x2d02bc);
                    struct Crossfeed::Preset preset = {
                            .cutoff = 700,
                            .feedback = 45,
                    };
                    this->cure->SetPreset(preset);
                    break;
                }
            }
            break;
        } // 0x1002E
        case PARAM_TUBE_SIMULATOR_ENABLED: {
            this->tubeSimulator->SetEnable(val1 != 0);
            break;
        } // 0x1002F
        case PARAM_ANALOGX_ENABLE: {
            this->analogX->SetEnable(val1 != 0);
            break;
        } // 0x10030
        case PARAM_ANALOGX_MODE: {
            this->analogX->SetProcessingModel(val1);
            break;
        } // 0x10031
        case PARAM_GATE_OUTPUT_VOLUME: {
            this->frameScale = (float) val1 / 100.0f;
            break;
        } // 0x10032
        case PARAM_GATE_CHANNEL_PAN: {
            float tmp = (float) val1 / 100.0f;
            if (tmp < 0.0f) {
                this->leftPan = 1.0f;
                this->rightPan = 1.0f + tmp;
            } else {
                this->leftPan = 1.0f - tmp;
                this->rightPan = 1.0f;
            }
            break;
        } // 0x10033
        case PARAM_GATE_LIMIT: {
            this->softwareLimiters[0]->SetGate((float) val1 / 100.0f);
            this->softwareLimiters[1]->SetGate((float) val1 / 100.0f);
            break;
        } // 0x10034
        case PARAM_SPEAKER_OPTIMIZATION: {
            this->speakerCorrection->SetEnable(val1 != 0);
            break;
        } // 0x10043
        case PARAM_FET_COMPRESSOR_ENABLE: {
            break;
        } // 0x10049
        case PARAM_FET_COMPRESSOR_THRESHOLD: {
            break;
        } // 0x1004A
        case PARAM_FET_COMPRESSOR_RATIO: {
            this->fetCompressor->SetParameter(FETCompressor::THRESHOLD, (float) val1 / 100.0f);
            break;
        } // 0x1004B
        case PARAM_FET_COMPRESSOR_KNEE: {
            break;
        } // 0x1004C
        case PARAM_FET_COMPRESSOR_AUTO_KNEE: {
            break;
        } // 0x1004D
        case PARAM_FET_COMPRESSOR_GAIN: {
            break;
        } // 0x1004E
        case PARAM_FET_COMPRESSOR_AUTO_GAIN: {
            this->fetCompressor->SetParameter(FETCompressor::GAIN, (float) val1 / 100.0f);
            break;
        } // 0x1004F
        case PARAM_FET_COMPRESSOR_ATTACK: {
            break;
        } // 0x10050
        case PARAM_FET_COMPRESSOR_AUTO_ATTACK: {
            break;
        } // 0x10051
        case PARAM_FET_COMPRESSOR_RELEASE: {
            break;
        } // 0x10052
        case PARAM_FET_COMPRESSOR_AUTO_RELEASE: {
            break;
        } // 0x10053
        case PARAM_FET_COMPRESSOR_KNEE_MULTI: {
            break;
        } // 0x10054
        case PARAM_FET_COMPRESSOR_MAX_ATTACK: {
            break;
        } // 0x10055
        case PARAM_FET_COMPRESSOR_MAX_RELEASE: {
            this->fetCompressor->SetParameter(FETCompressor::MAX_ATTACK, (float) val1 / 100.0f);
            break;
        } // 0x10056
        case PARAM_FET_COMPRESSOR_CREST: {
            break;
        } // 0x10057
        case PARAM_FET_COMPRESSOR_ADAPT: {
            break;
        } // 0x10058
        case PARAM_FET_COMPRESSOR_NO_CLIP: {
            this->fetCompressor->SetParameter(FETCompressor::ADAPT, (float) val1 / 100.0f);
            break;
        } // 0x10059
    }
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
            softwareLimiter->Reset();
        }
    }
}
