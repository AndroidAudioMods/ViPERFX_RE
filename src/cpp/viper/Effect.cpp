//
// Created by mart on 7/25/21.
//

#include <cstring>
#include "Effect.h"
#include "constants.h"

Effect::Effect() {
    this->enabled = false;
    this->configureOk = false;
    this->sampleRate = DEFAULT_SAMPLERATE;

    memset(&this->config, 0, sizeof(effect_config_t));

    this->config.inputCfg.accessMode = EFFECT_BUFFER_ACCESS_READ;
    this->config.inputCfg.format = AUDIO_FORMAT_PCM_16_BIT;  // TODO: Try to use PCM_FLOAT instead
    this->config.inputCfg.samplingRate = DEFAULT_SAMPLERATE;
    this->config.inputCfg.channels = AUDIO_CHANNEL_OUT_STEREO;
    this->config.inputCfg.mask = AUDIO_PORT_CONFIG_ALL;

    this->config.outputCfg.accessMode = EFFECT_BUFFER_ACCESS_WRITE;
    this->config.outputCfg.format = AUDIO_FORMAT_PCM_16_BIT;  // TODO: Try to use PCM_FLOAT instead
    this->config.outputCfg.samplingRate = DEFAULT_SAMPLERATE;
    this->config.outputCfg.channels = AUDIO_CHANNEL_OUT_STEREO;
    this->config.outputCfg.mask = AUDIO_PORT_CONFIG_ALL;

    this->buffer = nullptr;
    this->bufferSize = 0;
    this->instance = nullptr;
}

Effect::~Effect() {
    delete this->buffer;
    this->buffer = nullptr;
}

int32_t Effect::process(audio_buffer_s *in, audio_buffer_s *out) {
    // TODO
    return -1;
}

int32_t Effect::command(uint32_t cmdCode, uint32_t cmdSize, void *pCmdData, uint32_t *replySize, void *pReplyData) {
    switch (cmdCode) {
        case EFFECT_CMD_INIT:
        case EFFECT_CMD_SET_CONFIG: // receives effect_config_t
        case EFFECT_CMD_SET_PARAM:
        case EFFECT_CMD_SET_PARAM_COMMIT:
            *((int *) pReplyData) = 0;
        case EFFECT_CMD_RESET:
        case EFFECT_CMD_SET_PARAM_DEFERRED:
            break;
        case EFFECT_CMD_SET_CONFIG_REVERSE:
            *((int *) pReplyData) = -EINVAL;
        default:
            return -EINVAL;
        case EFFECT_CMD_GET_CONFIG:
            memcpy(pReplyData, &this->config, sizeof(effect_config_t));
            break;
    }
    return 0;
}

#define DO_ERROR() this->configureOk = false;\
return -EINVAL

int32_t Effect::configure(effect_config_t *newConfig) {
    VIPER_LOGI("Begin audio configure ...");
    VIPER_LOGI("Checking input and output configuration ...");

    if (newConfig->inputCfg.samplingRate != newConfig->outputCfg.samplingRate) {
        VIPER_LOGE("ViPER4Android disabled, reason [in.SR = %d, out.SR = %d]",
                   newConfig->inputCfg.samplingRate, newConfig->outputCfg.samplingRate);
        DO_ERROR();
    }

    if (newConfig->inputCfg.samplingRate > 48000) {
        VIPER_LOGE("ViPER4Android disabled, reason [SR out of range]");
        DO_ERROR();
    }

    if (newConfig->inputCfg.channels != newConfig->outputCfg.channels) {
        VIPER_LOGE("ViPER4Android disabled, reason [in.CH = %d, out.CH = %d]",
                   newConfig->inputCfg.channels, newConfig->outputCfg.channels);
        DO_ERROR();
    }

    if (newConfig->inputCfg.channels != AUDIO_CHANNEL_OUT_STEREO) {
        VIPER_LOGE("ViPER4Android disabled, reason [CH != 2]");
        DO_ERROR();
    }

    // TODO: Allow multiple formats by converting before/after processing

    if (newConfig->inputCfg.format != AUDIO_FORMAT_PCM_FLOAT) {
        VIPER_LOGE("ViPER4Android disabled, reason [in.FMT = %d]", newConfig->inputCfg.format);
        VIPER_LOGE("We only accept f32 format");
        DO_ERROR();
    }

    if (newConfig->outputCfg.format != AUDIO_FORMAT_PCM_FLOAT) {
        VIPER_LOGE("ViPER4Android disabled, reason [out.FMT = %d]", newConfig->outputCfg.format);
        VIPER_LOGE("We only accept f32 format");
        DO_ERROR();
    }

    VIPER_LOGI("Input and output configuration checked.");

    memcpy(&this->config, newConfig, sizeof(effect_config_t));
    this->configureOk = true;

    VIPER_LOGI("Audio configure finished");

    return 0;
}

