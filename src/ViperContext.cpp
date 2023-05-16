#include <cerrno>
#include <cstring>
#include <cmath>
#include <chrono>
#include "ViperContext.h"
#include "log.h"

#define SET(type, ptr, value) (*(type *) (ptr) = (value))

ViperContext::ViperContext() :
        config({}),
        disableReason(DisableReason::NONE),
        buffer(std::vector<float>()),
        bufferFrameCount(0),
        enabled(false) {
    VIPER_LOGI("ViperContext created");
}

void ViperContext::copyBufferConfig(buffer_config_t *dest, buffer_config_t *src) {
    if (src->mask & EFFECT_CONFIG_BUFFER) {
        dest->buffer = src->buffer;
    }

    if (src->mask & EFFECT_CONFIG_SMP_RATE) {
        dest->samplingRate = src->samplingRate;
    }

    if (src->mask & EFFECT_CONFIG_CHANNELS) {
        dest->channels = src->channels;
    }

    if (src->mask & EFFECT_CONFIG_FORMAT) {
        dest->format = src->format;
    }

    if (src->mask & EFFECT_CONFIG_ACC_MODE) {
        dest->accessMode = src->accessMode;
    }

    if (src->mask & EFFECT_CONFIG_PROVIDER) {
        dest->bufferProvider = src->bufferProvider;
    }

    dest->mask |= src->mask;
}

void ViperContext::handleSetConfig(effect_config_t *newConfig) {
    VIPER_LOGI("Checking input and output configuration ...");

    VIPER_LOGI("Input mask: 0x%04X", newConfig->inputCfg.mask);
    VIPER_LOGI("Input buffer frame count: %zu", newConfig->inputCfg.buffer.frameCount);
    VIPER_LOGI("Input sampling rate: %d", newConfig->inputCfg.samplingRate);
    VIPER_LOGI("Input channels: %d", newConfig->inputCfg.channels);
    VIPER_LOGI("Input format: %d", newConfig->inputCfg.format);
    VIPER_LOGI("Input access mode: %d", newConfig->inputCfg.accessMode);
    VIPER_LOGI("Output mask: 0x%04X", newConfig->outputCfg.mask);
    VIPER_LOGI("Output buffer frame count: %zu", newConfig->outputCfg.buffer.frameCount);
    VIPER_LOGI("Output sampling rate: %d", newConfig->outputCfg.samplingRate);
    VIPER_LOGI("Output channels: %d", newConfig->outputCfg.channels);
    VIPER_LOGI("Output format: %d", newConfig->outputCfg.format);
    VIPER_LOGI("Output access mode: %d", newConfig->outputCfg.accessMode);

    setDisableReason(DisableReason::UNKNOWN);

    copyBufferConfig(&config.inputCfg, &newConfig->inputCfg);
    copyBufferConfig(&config.outputCfg, &newConfig->outputCfg);

    if (config.inputCfg.buffer.frameCount != config.outputCfg.buffer.frameCount) {
        VIPER_LOGE("ViPER4Android disabled, reason [in.FC = %ld, out.FC = %ld]",
                   config.inputCfg.buffer.frameCount, config.outputCfg.buffer.frameCount);
        setDisableReason(DisableReason::INVALID_FRAME_COUNT, "Input and output frame count mismatch");
        return;
    }

    if (config.inputCfg.samplingRate != config.outputCfg.samplingRate) {
        VIPER_LOGE("ViPER4Android disabled, reason [in.SR = %d, out.SR = %d]",
                   config.inputCfg.samplingRate, config.outputCfg.samplingRate);
        setDisableReason(DisableReason::INVALID_SAMPLING_RATE, "Input and output sampling rate mismatch");
        return;
    }

//    if (config.inputCfg.samplingRate > 48000) {
//        VIPER_LOGE("ViPER4Android disabled, reason [SR out of range]");
//        setDisableReason(DisableReason::INVALID_SAMPLING_RATE, "Sampling rate out of range: " + std::to_string(config.inputCfg.samplingRate));
//        return;
//    }

    if (config.inputCfg.channels != config.outputCfg.channels) {
        VIPER_LOGE("ViPER4Android disabled, reason [in.CH = %d, out.CH = %d]",
                   config.inputCfg.channels, config.outputCfg.channels);
        setDisableReason(DisableReason::INVALID_CHANNEL_COUNT, "Input and output channel count mismatch");
        return;
    }

    if (config.inputCfg.channels != AUDIO_CHANNEL_OUT_STEREO) {
        VIPER_LOGE("ViPER4Android disabled, reason [CH != 2]");
        setDisableReason(DisableReason::INVALID_CHANNEL_COUNT, "Invalid channel count: " + std::to_string(config.inputCfg.channels));
        return;
    }

    if (config.inputCfg.format != AUDIO_FORMAT_PCM_16_BIT &&
        config.inputCfg.format != AUDIO_FORMAT_PCM_32_BIT &&
        config.inputCfg.format != AUDIO_FORMAT_PCM_FLOAT) {
        VIPER_LOGE("ViPER4Android disabled, reason [in.FMT = %d]", config.inputCfg.format);
        VIPER_LOGE("We only accept AUDIO_FORMAT_PCM_16_BIT, AUDIO_FORMAT_PCM_32_BIT and AUDIO_FORMAT_PCM_FLOAT input format!");
        setDisableReason(DisableReason::INVALID_FORMAT, "Invalid input format: " + std::to_string(config.inputCfg.format));
        return;
    }

    if (config.outputCfg.format != AUDIO_FORMAT_PCM_16_BIT &&
        config.outputCfg.format != AUDIO_FORMAT_PCM_32_BIT &&
        config.outputCfg.format != AUDIO_FORMAT_PCM_FLOAT) {
        VIPER_LOGE("ViPER4Android disabled, reason [out.FMT = %d]", config.outputCfg.format);
        VIPER_LOGE("We only accept AUDIO_FORMAT_PCM_16_BIT, AUDIO_FORMAT_PCM_32_BIT and AUDIO_FORMAT_PCM_FLOAT output format!");
        setDisableReason(DisableReason::INVALID_FORMAT, "Invalid output format: " + std::to_string(config.outputCfg.format));
        return;
    }

    VIPER_LOGI("Input and output configuration checked.");
    setDisableReason(DisableReason::NONE);

    // Processing buffer
    buffer.resize(config.inputCfg.buffer.frameCount * 2);
    bufferFrameCount = config.inputCfg.buffer.frameCount;

    // ViPER
    viper.samplingRate = config.inputCfg.samplingRate;
    viper.resetAllEffects();
}

int32_t ViperContext::handleSetParam(effect_param_t *pCmdParam, void *pReplyData) {
    // The value offset of an effect parameter is computed by rounding up
    // the parameter size to the next 32 bit alignment.
    uint32_t vOffset = ((pCmdParam->psize + sizeof(int32_t) - 1) / sizeof(int32_t)) * sizeof(int32_t);

    *(int *) pReplyData = 0;

    int param = *(int *) (pCmdParam->data);
    int *intValues = (int *) (pCmdParam->data + vOffset);
    switch (pCmdParam->vsize) {
        case sizeof(int): {
            viper.DispatchCommand(param, intValues[0], 0, 0, 0, 0, nullptr);
            return 0;
        }
        case sizeof(int) * 2: {
            viper.DispatchCommand(param, intValues[0], intValues[1], 0, 0, 0, nullptr);
            return 0;
        }
        case sizeof(int) * 3: {
            viper.DispatchCommand(param, intValues[0], intValues[1], intValues[2], 0, 0, nullptr);
            return 0;
        }
        case sizeof(int) * 4: {
            viper.DispatchCommand(param, intValues[0], intValues[1], intValues[2], intValues[3], 0, nullptr);
            return 0;
        }
        case 256:
        case 1024: {
            uint32_t arrSize = *(uint32_t *) (pCmdParam->data + vOffset);
            signed char *arr = (signed char *) (pCmdParam->data + vOffset + sizeof(uint32_t));
            viper.DispatchCommand(param, 0, 0, 0, 0, arrSize, arr);
            return 0;
        }
        case 8192: {
            int value1 = *(int *) (pCmdParam->data + vOffset);
            uint32_t arrSize = *(uint32_t *) (pCmdParam->data + vOffset + sizeof(int));
            signed char *arr = (signed char *) (pCmdParam->data + vOffset + sizeof(int) + sizeof(uint32_t));
            viper.DispatchCommand(param, value1, 0, 0, 0, arrSize, arr);
            return 0;
        }
        default: {
            return -EINVAL;
        }
    }
}

int32_t ViperContext::handleGetParam(effect_param_t *pCmdParam, effect_param_t *pReplyParam, uint32_t *pReplySize) {
    // The value offset of an effect parameter is computed by rounding up
    // the parameter size to the next 32 bit alignment.
    uint32_t vOffset = ((pCmdParam->psize + sizeof(int32_t) - 1) / sizeof(int32_t)) * sizeof(int32_t);

    VIPER_LOGD("handleGetParam() EFFECT_CMD_GET_PARAM called with data = %d, psize = %d, vsize = %d", *(uint32_t *) pCmdParam->data, pCmdParam->psize, pCmdParam->vsize);

    memcpy(pReplyParam, pCmdParam, sizeof(effect_param_t) + pCmdParam->psize);

    switch (*(uint32_t *) pCmdParam->data) {
        case PARAM_GET_ENABLED: {
            pReplyParam->status = 0;
            pReplyParam->vsize = sizeof(int32_t);
            *(int32_t *) (pReplyParam->data + vOffset) = enabled;
            *pReplySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
            return 0;
        }
        case PARAM_GET_CONFIGURE: {
            pReplyParam->status = 0;
            pReplyParam->vsize = sizeof(int32_t);
            *(int32_t *) (pReplyParam->data + vOffset) = disableReason == DisableReason::NONE;
            *pReplySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
            return 0;
        }
        case PARAM_GET_STREAMING: { // Is processing
            auto now = std::chrono::system_clock::now();
            auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);

            uint64_t currentMs = now_ms.time_since_epoch().count();
            uint64_t lastProcessTime = viper.processTimeMs;

            bool isProcessing;
            if (currentMs >= lastProcessTime) {
                isProcessing = currentMs - lastProcessTime < 5000;
            } else {
                isProcessing = false;
            }

            pReplyParam->status = 0;
            pReplyParam->vsize = sizeof(int32_t);
            *(int32_t *) (pReplyParam->data + vOffset) = isProcessing;
            *pReplySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
            return 0;
        }
        case PARAM_GET_SAMPLING_RATE: {
            pReplyParam->status = 0;
            pReplyParam->vsize = sizeof(uint32_t);
            *(uint32_t *) (pReplyParam->data + vOffset) = viper.samplingRate;
            *pReplySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
            return 0;
        }
        case PARAM_GET_CONVOLUTION_KERNEL_ID: {
            pReplyParam->status = 0;
            pReplyParam->vsize = sizeof(uint32_t);
            *(uint32_t *) (pReplyParam->data + vOffset) = viper.convolver.GetKernelID();
            *pReplySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
            return 0;
        }
        case PARAM_GET_DRIVER_VERSION_CODE: {
            pReplyParam->status = 0;
            pReplyParam->vsize = sizeof(uint32_t);
            *(int32_t *) (pReplyParam->data + vOffset) = VERSION_CODE;
            *pReplySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
            return 0;
        }
        case PARAM_GET_DRIVER_VERSION_NAME: {
            pReplyParam->status = 0;
            pReplyParam->vsize = strlen(VERSION_NAME);
            memcpy(pReplyParam->data + vOffset, VERSION_NAME, pReplyParam->vsize);
            *pReplySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
            return 0;
        }
        case PARAM_GET_DISABLE_REASON: {
            pReplyParam->status = 0;
            pReplyParam->vsize = sizeof(int32_t);
            *(int32_t *) (pReplyParam->data + vOffset) = static_cast<int32_t>(disableReason);
            *pReplySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
            return 0;
        }
        case PARAM_GET_DISABLE_REASON_MESSAGE: {
            pReplyParam->status = 0;
            pReplyParam->vsize = disableReasonMessage.size();
            memcpy(pReplyParam->data + vOffset, disableReasonMessage.c_str(), pReplyParam->vsize);
            *pReplySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
            return 0;
        }
        case PARAM_GET_CONFIG: {
            pReplyParam->status = 0;
            pReplyParam->vsize = 40;
            // Input
            SET(uint64_t, pReplyParam->data + vOffset, config.inputCfg.buffer.frameCount);
            SET(uint32_t, pReplyParam->data + vOffset + 8, config.inputCfg.samplingRate);
            SET(uint32_t, pReplyParam->data + vOffset + 12, config.inputCfg.channels);
            SET(uint8_t, pReplyParam->data + vOffset + 16, config.inputCfg.format);
            SET(uint8_t, pReplyParam->data + vOffset + 17, config.inputCfg.accessMode);
            SET(uint16_t, pReplyParam->data + vOffset + 18, config.inputCfg.mask);
            // Output
            SET(uint64_t, pReplyParam->data + vOffset + 20, config.outputCfg.buffer.frameCount);
            SET(uint32_t, pReplyParam->data + vOffset + 28, config.outputCfg.samplingRate);
            SET(uint32_t, pReplyParam->data + vOffset + 32, config.outputCfg.channels);
            SET(uint8_t, pReplyParam->data + vOffset + 36, config.outputCfg.format);
            SET(uint8_t, pReplyParam->data + vOffset + 37, config.outputCfg.accessMode);
            SET(uint16_t, pReplyParam->data + vOffset + 38, config.outputCfg.mask);
            *pReplySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
            return 0;
        }
        default: {
            return -EINVAL;
        }
    }
}

int32_t ViperContext::handleCommand(uint32_t cmdCode, uint32_t cmdSize, void *pCmdData, uint32_t *pReplySize, void *pReplyData) {
    uint32_t replySize = pReplySize == nullptr ? 0 : *pReplySize;
    switch (cmdCode) {
        case EFFECT_CMD_INIT: {
            if (replySize != sizeof(int32_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_INIT called with invalid replySize = %d, pReplyData = %p, expected replySize = %zu", replySize, pReplyData, sizeof(int32_t));
                return -EINVAL;
            }
            SET(int32_t, pReplyData, 0);
            return 0;
        }
        case EFFECT_CMD_SET_CONFIG: {
            if (cmdSize < sizeof(effect_config_t) || pCmdData == nullptr || replySize != sizeof(int32_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_SET_CONFIG called with invalid cmdSize = %d, pCmdData = %p, replySize = %d, pReplyData = %p, expected cmdSize = %zu, replySize = %zu", cmdSize, pCmdData, replySize, pReplyData, sizeof(effect_config_t), sizeof(int32_t));
                return -EINVAL;
            }
            handleSetConfig((effect_config_t *) pCmdData);
            SET(int32_t, pReplyData, 0);
            return 0;
        }
        case EFFECT_CMD_RESET: {
            if (replySize != sizeof(int32_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_RESET called with invalid replySize = %d, pReplyData = %p, expected replySize = %zu", replySize, pReplyData, sizeof(int32_t));
                return -EINVAL;
            }
            viper.resetAllEffects();
            SET(int32_t, pReplyData, 0);
            return 0;
        }
        case EFFECT_CMD_ENABLE: {
            if (replySize != sizeof(int32_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_ENABLE called with invalid replySize = %d, pReplyData = %p, expected replySize = %zu", replySize, pReplyData, sizeof(int32_t));
                return -EINVAL;
            }
            enabled = true;
            SET(int32_t, pReplyData, 0);
            return 0;
        }
        case EFFECT_CMD_DISABLE: {
            if (replySize != sizeof(int32_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_DISABLE called with invalid replySize = %d, pReplyData = %p, expected replySize = %zu", replySize, pReplyData, sizeof(int32_t));
                return -EINVAL;
            }
            enabled = false;
            SET(int32_t, pReplyData, 0);
            return 0;
        }
        case EFFECT_CMD_SET_PARAM: {
            if (cmdSize < sizeof(effect_param_t) || pCmdData == nullptr || replySize != sizeof(int32_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_SET_PARAM called with invalid cmdSize = %d, pCmdData = %p, replySize = %d, pReplyData = %p, expected cmdSize = %zu, replySize = %zu", cmdSize, pCmdData, replySize, pReplyData, sizeof(effect_param_t), sizeof(int32_t));
                return -EINVAL;
            }
            return handleSetParam((effect_param_t *) pCmdData, pReplyData);
        }
        case EFFECT_CMD_GET_PARAM: {
            if (cmdSize < sizeof(effect_param_t) || pCmdData == nullptr || replySize < sizeof(effect_param_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_GET_PARAM called with invalid cmdSize = %d, pCmdData = %p, replySize = %d, pReplyData = %p, expected cmdSize = %zu, replySize = %zu", cmdSize, pCmdData, replySize, pReplyData, sizeof(effect_param_t), sizeof(effect_param_t));
                return -EINVAL;
            }
            return handleGetParam((effect_param_t *) pCmdData, (effect_param_t *) pReplyData, pReplySize);
        }
        case EFFECT_CMD_GET_CONFIG: {
            if (replySize != sizeof(effect_config_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_GET_CONFIG called with invalid replySize = %d, pReplyData = %p, expected replySize = %zu", replySize, pReplyData, sizeof(effect_config_t));
                return -EINVAL;
            }
            *(effect_config_t *) pReplyData = config;
            return 0;
        }
        default: {
            VIPER_LOGE("handleCommand called with unknown command: %d", cmdCode);
            return -EINVAL;
        }
    }
}

static void pcm16ToFloat(float *dst, const int16_t *src, size_t frameCount) {
    for (size_t i = 0; i < frameCount * 2; i++) {
        dst[i] = static_cast<float>(src[i]) / static_cast<float>(1 << 15);
    }
}

static void pcm32ToFloat(float *dst, const int32_t *src, size_t frameCount) {
    for (size_t i = 0; i < frameCount * 2; i++) {
        dst[i] = static_cast<float>(src[i]) / static_cast<float>(1 << 31);
    }
}

static void floatToFloat(float *dst, const float *src, size_t frameCount, bool accumulate) {
    if (accumulate) {
        for (size_t i = 0; i < frameCount * 2; i++) {
            dst[i] += src[i];
        }
    } else {
        memcpy(dst, src, frameCount * 2 * sizeof(float));
    }
}

static void floatToPcm16(int16_t *dst, const float *src, size_t frameCount, bool accumulate) {
    if (accumulate) {
        for (size_t i = 0; i < frameCount * 2; i++) {
            dst[i] += static_cast<int16_t>(std::roundf(src[i] * static_cast<float>(1 << 15)));
        }
    } else {
        for (size_t i = 0; i < frameCount * 2; i++) {
            dst[i] = static_cast<int16_t>(std::roundf(src[i] * static_cast<float>(1 << 15)));
        }
    }
}

static void floatToPcm32(int32_t *dst, const float *src, size_t frameCount, bool accumulate) {
    if (accumulate) {
        for (size_t i = 0; i < frameCount * 2; i++) {
            dst[i] += static_cast<int32_t>(std::roundf(src[i] * static_cast<float>(1 << 31)));
        }
    } else {
        for (size_t i = 0; i < frameCount * 2; i++) {
            dst[i] = static_cast<int32_t>(std::roundf(src[i] * static_cast<float>(1 << 31)));
        }
    }
}

static audio_buffer_t *getBuffer(buffer_config_s *config, audio_buffer_t *buffer) {
    if (buffer != nullptr) return buffer;
    return &config->buffer;
}

int32_t ViperContext::process(audio_buffer_t *inBuffer, audio_buffer_t *outBuffer) {
    if (disableReason != DisableReason::NONE) {
        return -EINVAL;
    }

    if (!enabled) {
        return -ENODATA;
    }
    
    inBuffer = getBuffer(&config.inputCfg, inBuffer);
    outBuffer = getBuffer(&config.outputCfg, outBuffer);
    if (inBuffer == nullptr || outBuffer == nullptr ||
        inBuffer->raw == nullptr || outBuffer->raw == nullptr ||
        inBuffer->frameCount != outBuffer->frameCount ||
        inBuffer->frameCount == 0) {
        return -EINVAL;
    }

    size_t frameCount = inBuffer->frameCount;
    if (frameCount > bufferFrameCount) {
        buffer.resize(frameCount * 2);
        bufferFrameCount = frameCount;
    }

    switch (config.inputCfg.format) {
        case AUDIO_FORMAT_PCM_16_BIT:
            pcm16ToFloat(buffer.data(), inBuffer->s16, frameCount);
            break;
        case AUDIO_FORMAT_PCM_32_BIT:
            pcm32ToFloat(buffer.data(), inBuffer->s32, frameCount);
            break;
        case AUDIO_FORMAT_PCM_FLOAT:
            floatToFloat(buffer.data(), inBuffer->f32, frameCount, false);
            break;
        default:
            return -EINVAL;
    }

    viper.process(buffer, frameCount);

    const bool accumulate = config.outputCfg.accessMode == EFFECT_BUFFER_ACCESS_ACCUMULATE;
    switch (config.outputCfg.format) {
        case AUDIO_FORMAT_PCM_16_BIT:
            floatToPcm16(outBuffer->s16, buffer.data(), frameCount, accumulate);
            break;
        case AUDIO_FORMAT_PCM_32_BIT:
            floatToPcm32(outBuffer->s32, buffer.data(), frameCount, accumulate);
            break;
        case AUDIO_FORMAT_PCM_FLOAT:
            floatToFloat(outBuffer->f32, buffer.data(), frameCount, accumulate);
            break;
        default:
            return -EINVAL;
    }

    return 0;
}

void ViperContext::setDisableReason(DisableReason reason) {
    setDisableReason(reason, "");
}

void ViperContext::setDisableReason(DisableReason reason, std::string message) {
    this->disableReason = reason;
    this->disableReasonMessage = std::move(message);
}
