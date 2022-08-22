//
// Created by mart on 7/25/21.
//

#include <cstdlib>
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
    if (this->buffer != nullptr) {
        free(this->buffer);
    }
}

int32_t Effect::process(audio_buffer_s *in, audio_buffer_s *out) {
    // TODO
    return -1;
}

int32_t Effect::command(uint32_t cmdCode, uint32_t cmdSize, void *pCmdData, uint32_t *replySize, void *pReplyData) {
    switch (cmdCode) {
        case EFFECT_CMD_INIT:
        case EFFECT_CMD_SET_CONFIG:
        case EFFECT_CMD_SET_PARAM:
        case EFFECT_CMD_SET_PARAM_COMMIT:
            *((int *) pReplyData) = 0;
        case EFFECT_CMD_RESET:
        case EFFECT_CMD_SET_PARAM_DEFERRED:
        case EFFECT_CMD_SET_DEVICE:
        case EFFECT_CMD_SET_VOLUME:
        case EFFECT_CMD_SET_AUDIO_MODE:
        case EFFECT_CMD_SET_INPUT_DEVICE:
        case EFFECT_CMD_SET_AUDIO_SOURCE:
            break;
        case EFFECT_CMD_SET_CONFIG_REVERSE:
            *((int *) pReplyData) = -EINVAL;
        default:
            return -EINVAL;
        case EFFECT_CMD_GET_CONFIG:
            memcpy(pReplyData, &this->config, sizeof(effect_config_t));
            break;
        case EFFECT_CMD_OFFLOAD:
            // TODO: Figure this out
            return -1;
    }
    return 0;
}

#define DO_ERROR() this->configureOk = false;\
return -EINVAL

int32_t Effect::configure(effect_config_t *newConfig) {
    v4a_print(ANDROID_LOG_INFO, "Begin audio configure ...");
    v4a_print(ANDROID_LOG_INFO, "Checking input and output configuration ...");

    if (newConfig->inputCfg.samplingRate != newConfig->outputCfg.samplingRate) {
        v4a_printf(ANDROID_LOG_ERROR, "ViPER4Android disabled, reason [in.SR = %d, out.SR = %d]",
                   newConfig->inputCfg.samplingRate, newConfig->outputCfg.samplingRate);
        DO_ERROR();
    }

    if (newConfig->inputCfg.samplingRate > 48000) {
        v4a_print(ANDROID_LOG_ERROR, "ViPER4Android disabled, reason [SR out of range]");
        DO_ERROR();
    }

    if (newConfig->inputCfg.channels != newConfig->outputCfg.channels) {
        v4a_printf(ANDROID_LOG_ERROR, "ViPER4Android disabled, reason [in.CH = %d, out.CH = %d]",
                   newConfig->inputCfg.channels, newConfig->outputCfg.channels);
        DO_ERROR();
    }

    if (newConfig->inputCfg.channels != AUDIO_CHANNEL_OUT_STEREO) {
        v4a_print(ANDROID_LOG_ERROR, "ViPER4Android disabled, reason [CH != 2]");
        DO_ERROR();
    }

    // TODO: Allow multiple formats by converting before/after processing

    if (newConfig->inputCfg.format != AUDIO_FORMAT_PCM_FLOAT) {
        v4a_printf(ANDROID_LOG_ERROR, "ViPER4Android disabled, reason [in.FMT = %d]", newConfig->inputCfg.format);
        v4a_print(ANDROID_LOG_ERROR, "We only accept f32 format");
        DO_ERROR();
    }

    if (newConfig->outputCfg.format != AUDIO_FORMAT_PCM_FLOAT) {
        v4a_printf(ANDROID_LOG_ERROR, "ViPER4Android disabled, reason [out.FMT = %d]", newConfig->outputCfg.format);
        v4a_print(ANDROID_LOG_ERROR, "We only accept f32 format");
        DO_ERROR();
    }

    v4a_print(ANDROID_LOG_INFO, "Input and output configuration checked.");

    memcpy(&this->config, newConfig, sizeof(effect_config_t));
    this->configureOk = true;

    v4a_print(ANDROID_LOG_INFO, "Audio configure finished");

    return 0;
}

