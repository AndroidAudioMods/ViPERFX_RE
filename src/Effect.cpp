//
// Created by mart on 7/25/21.
//

#include <cstdlib>
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
    switch(cmdCode) {
        case EFFECT_CMD_INIT:
        case EFFECT_CMD_SET_CONFIG:
        case EFFECT_CMD_SET_PARAM:
        case EFFECT_CMD_SET_PARAM_COMMIT:
            *((int*)pReplyData) = 0;
        case EFFECT_CMD_RESET:
        case EFFECT_CMD_SET_PARAM_DEFERRED:
        case EFFECT_CMD_SET_DEVICE:
        case EFFECT_CMD_SET_VOLUME:
        case EFFECT_CMD_SET_AUDIO_MODE:
        case EFFECT_CMD_SET_INPUT_DEVICE:
        case EFFECT_CMD_SET_AUDIO_SOURCE:
            break;
        case EFFECT_CMD_SET_CONFIG_REVERSE:
            *((int*)pReplyData) = -EINVAL;
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

#define ERROR this->configureOk = false;\
return -EINVAL;

int32_t Effect::configure(effect_config_t *newConfig) {
    if (newConfig->inputCfg.samplingRate != newConfig->outputCfg.samplingRate) {
        // __android_log_print(4,"ViPER4Android_v2","ViPER4Android disabled, reason [in.SR = %d, out.SR = %d]",inSamplingRate,outSamplingRate);
        ERROR
    }

    if (newConfig->inputCfg.samplingRate > 48000) {
        // __android_log_print(4,"ViPER4Android_v2","ViPER4Android disabled, reason [SR out of range]");
        ERROR
    }

    if (newConfig->inputCfg.channels != newConfig->outputCfg.channels) {
        // __android_log_print(4,"ViPER4Android_v2","ViPER4Android disabled, reason [in.CH = %d, out.CH = %d]",inChannels,outChannels);
        ERROR
    }

    if (newConfig->inputCfg.channels != AUDIO_CHANNEL_OUT_STEREO) {
        // __android_log_print(4,"ViPER4Android_v2","ViPER4Android disabled, reason [CH != 2]");
        ERROR
    }

//    if (((inFormat & 0x80000) != 0) && ((outFormat & 0x80000) != 0)) {
//        if ((inFormat & 0xfd) != 1) {
//            __android_log_print(4,"ViPER4Android_v2","ViPER4Android disabled, reason [in.FMT = %d]");
//            __android_log_print(4,"ViPER4Android_v2","We only accept s16 and fixed.31 format");
//            this->configureOk = false;
//            return 0xffffffea;
//        }
//        if ((outFormat & 0xfd) != 1) {
//            __android_log_print(4,"ViPER4Android_v2","ViPER4Android disabled, reason [out.FMT = %d]");
//            __android_log_print(4,"ViPER4Android_v2","We only accept s16 and fixed.31 format");
//            this->configureOk = false;
//            return 0xffffffea;
//        }
//    }

    memcpy(&this->config, newConfig, sizeof(effect_config_t));
    this->configureOk = true;
    return 0;
}

