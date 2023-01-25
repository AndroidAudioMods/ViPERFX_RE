#include <cstring>
#include <ctime>
#include <cstdlib>
#include "viper/ViPER.h"
#include "essential.h"
#include "log.h"
#include "viper/constants.h"

#define VIPER_EFFECT_NAME "ViPER4Android"

static effect_descriptor_t viper_descriptor = {
        .type = EFFECT_UUID_INITIALIZER,
        .uuid = {0x90380da3, 0x8536, 0x4744, 0xa6a3, {0x57, 0x31, 0x97, 0x0e, 0x64, 0x0f}},
        .apiVersion = EFFECT_CONTROL_API_VERSION,
        .flags = EFFECT_FLAG_OUTPUT_DIRECT | EFFECT_FLAG_INPUT_DIRECT | EFFECT_FLAG_INSERT_LAST | EFFECT_FLAG_TYPE_INSERT,
        .cpuLoad = 8, // In 0.1 MIPS units as estimated on an ARM9E core (ARMv5TE) with 0 WS
        .memoryUsage = 1, // In KB and includes only dynamically allocated memory
        .name = VIPER_EFFECT_NAME,
        .implementor = VIPER_AUTHORS
};

extern "C" {
struct ViperContext {
    const struct effect_interface_s *interface; // Should always be the first struct member
    effect_config_t config;
    bool isConfigValid;
    ViPER *viper;
};

static void pcm16ToFloat(float *dst, const int16_t *src, size_t frameCount) {
    for (size_t i = 0; i < frameCount * 2; i++) {
        dst[i] = (float) src[i] / (float) (1 << 15);
    }
}

static void pcm32ToFloat(float *dst, const int32_t *src, size_t frameCount) {
    for (size_t i = 0; i < frameCount * 2; i++) {
        dst[i] = (float) src[i] / (float) (1 << 31);
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
            dst[i] += (int16_t) round(src[i] * (float) (1 << 15));
        }
    } else {
        for (size_t i = 0; i < frameCount * 2; i++) {
            dst[i] = (int16_t) round(src[i] * (float) (1 << 15));
        }
    }
}

static void floatToPcm32(int32_t *dst, const float *src, size_t frameCount, bool accumulate) {
    if (accumulate) {
        for (size_t i = 0; i < frameCount * 2; i++) {
            dst[i] += (int32_t) round(src[i] * (float) (1 << 31));
        }
    } else {
        for (size_t i = 0; i < frameCount * 2; i++) {
            dst[i] = (int32_t) round(src[i] * (float) (1 << 31));
        }
    }
}

static int32_t Viper_IProcess(effect_handle_t self, audio_buffer_t *inBuffer, audio_buffer_t *outBuffer) {
    auto pContext = reinterpret_cast<ViperContext *>(self);

    if (pContext == nullptr ||
        inBuffer == nullptr || outBuffer == nullptr ||
        inBuffer->raw == nullptr || outBuffer->raw == nullptr ||
        inBuffer->frameCount != outBuffer->frameCount ||
        inBuffer->frameCount == 0) {
        return -EINVAL;
    }

    float *buffer = new float[outBuffer->frameCount * 2];
    size_t frameCount = outBuffer->frameCount;

    switch (pContext->config.inputCfg.format) {
        case AUDIO_FORMAT_PCM_16_BIT:
            pcm16ToFloat(buffer, inBuffer->s16, frameCount);
            break;
        case AUDIO_FORMAT_PCM_32_BIT:
            pcm32ToFloat(buffer, inBuffer->s32, frameCount);
            break;
        case AUDIO_FORMAT_PCM_FLOAT:
            floatToFloat(buffer, inBuffer->f32, frameCount, false);
            break;
        default:
            delete[] buffer;
            return -EINVAL;
    }

    pContext->viper->processBuffer(buffer, frameCount);

    const bool accumulate = pContext->config.outputCfg.accessMode == EFFECT_BUFFER_ACCESS_ACCUMULATE;
    switch (pContext->config.outputCfg.format) {
        case AUDIO_FORMAT_PCM_16_BIT:
            floatToPcm16(outBuffer->s16, buffer, frameCount, accumulate);
            delete[] buffer;
            break;
        case AUDIO_FORMAT_PCM_32_BIT:
            floatToPcm32(outBuffer->s32, buffer, frameCount, accumulate);
            delete[] buffer;
            break;
        case AUDIO_FORMAT_PCM_FLOAT:
            floatToFloat(outBuffer->f32, buffer, frameCount, accumulate);
            delete[] buffer;
            break;
        default:
            delete[] buffer;
            return -EINVAL;
    }

    return 0;
}

static int handleSetConfig(ViperContext *pContext, effect_config_t *newConfig) {
    VIPER_LOGD("Begin handleSetConfig ...");
    VIPER_LOGI("Checking input and output configuration ...");

    VIPER_LOGI("Input sampling rate: %d", newConfig->inputCfg.samplingRate);
    VIPER_LOGI("Input channels: %d", newConfig->inputCfg.channels);
    VIPER_LOGI("Input format: %d", newConfig->inputCfg.format);
    VIPER_LOGI("Input access mode: %d", newConfig->inputCfg.accessMode);
    VIPER_LOGI("Output sampling rate: %d", newConfig->outputCfg.samplingRate);
    VIPER_LOGI("Output channels: %d", newConfig->outputCfg.channels);
    VIPER_LOGI("Output format: %d", newConfig->outputCfg.format);
    VIPER_LOGI("Output access mode: %d", newConfig->outputCfg.accessMode);

    pContext->isConfigValid = false;

    if (newConfig->inputCfg.samplingRate != newConfig->outputCfg.samplingRate) {
        VIPER_LOGE("ViPER4Android disabled, reason [in.SR = %d, out.SR = %d]",
                   newConfig->inputCfg.samplingRate, newConfig->outputCfg.samplingRate);
        return -EINVAL;
    }

    if (newConfig->inputCfg.samplingRate > 48000) {
        VIPER_LOGE("ViPER4Android disabled, reason [SR out of range]");
        return -EINVAL;
    }

    if (newConfig->inputCfg.channels != newConfig->outputCfg.channels) {
        VIPER_LOGE("ViPER4Android disabled, reason [in.CH = %d, out.CH = %d]",
                   newConfig->inputCfg.channels, newConfig->outputCfg.channels);
        return -EINVAL;
    }

    if (newConfig->inputCfg.channels != AUDIO_CHANNEL_OUT_STEREO) {
        VIPER_LOGE("ViPER4Android disabled, reason [CH != 2]");
        return -EINVAL;
    }

    if (newConfig->inputCfg.format != AUDIO_FORMAT_PCM_16_BIT &&
        newConfig->inputCfg.format != AUDIO_FORMAT_PCM_32_BIT &&
        newConfig->inputCfg.format != AUDIO_FORMAT_PCM_FLOAT) {
        VIPER_LOGE("ViPER4Android disabled, reason [in.FMT = %d]", newConfig->inputCfg.format);
        VIPER_LOGE("We only accept AUDIO_FORMAT_PCM_16_BIT, AUDIO_FORMAT_PCM_32_BIT and AUDIO_FORMAT_PCM_FLOAT input format!");
        return -EINVAL;
    }

    if (newConfig->outputCfg.format != AUDIO_FORMAT_PCM_16_BIT &&
        newConfig->outputCfg.format != AUDIO_FORMAT_PCM_32_BIT &&
        newConfig->outputCfg.format != AUDIO_FORMAT_PCM_FLOAT) {
        VIPER_LOGE("ViPER4Android disabled, reason [out.FMT = %d]", newConfig->outputCfg.format);
        VIPER_LOGE("We only accept AUDIO_FORMAT_PCM_16_BIT, AUDIO_FORMAT_PCM_32_BIT and AUDIO_FORMAT_PCM_FLOAT output format!");
        return -EINVAL;
    }

    VIPER_LOGI("Input and output configuration checked.");

    pContext->config = *newConfig;
    pContext->viper->samplingRate = newConfig->inputCfg.samplingRate;
    pContext->viper->ResetAllEffects();
    pContext->isConfigValid = true;

    VIPER_LOGD("Audio handleSetConfig finished");

    return 0;
}

static int32_t handleSetParam(ViperContext *pContext, effect_param_t *pCmdParam, void *pReplyData) {
    // The value offset of an effect parameter is computed by rounding up
    // the parameter size to the next 32 bit alignment.
    uint32_t vOffset = ((pCmdParam->psize + sizeof(int32_t) - 1) / sizeof(int32_t)) * sizeof(int32_t);

    *(int *) pReplyData = 0;

    int param = *(int *) (pCmdParam->data);
    int *intValues = (int *) (pCmdParam->data + vOffset);
    if (pCmdParam->vsize == sizeof(int)) {
        pContext->viper->DispatchCommand(param, intValues[0], 0, 0, 0, 0, nullptr);
        return 0;
    } else if (pCmdParam->vsize == sizeof(int) * 2) {
        pContext->viper->DispatchCommand(param, intValues[0], intValues[1], 0, 0, 0, nullptr);
        return 0;
    } else if (pCmdParam->vsize == sizeof(int) * 3) {
        pContext->viper->DispatchCommand(param, intValues[0], intValues[1], intValues[2], 0, 0, nullptr);
        return 0;
    } else if (pCmdParam->vsize == sizeof(int) * 4) {
        pContext->viper->DispatchCommand(param, intValues[0], intValues[1], intValues[2], intValues[3], 0, nullptr);
        return 0;
    } else if (pCmdParam->vsize == 256 || pCmdParam->vsize == 1024) {
        uint32_t arrSize = *(uint32_t *) (pCmdParam->data + vOffset);
        signed char *arr = (signed char *) (pCmdParam->data + vOffset + sizeof(uint32_t));
        pContext->viper->DispatchCommand(param, 0, 0, 0, 0, arrSize, arr);
        return 0;
    } else if (pCmdParam->vsize == 8192) {
        int value1 = *(int *) (pCmdParam->data + vOffset);
        uint32_t arrSize = *(uint32_t *) (pCmdParam->data + vOffset + sizeof(int));
        signed char *arr = (signed char *) (pCmdParam->data + vOffset + sizeof(int) + sizeof(uint32_t));
        pContext->viper->DispatchCommand(param, value1, 0, 0, 0, arrSize, arr);
        return 0;
    }

    return -EINVAL;
}

static int32_t handleGetParam(ViperContext *pContext, effect_param_t *pCmdParam, effect_param_t *pReplyParam, uint32_t *pReplySize) {
    // The value offset of an effect parameter is computed by rounding up
    // the parameter size to the next 32 bit alignment.
    uint32_t vOffset = ((pCmdParam->psize + sizeof(int32_t) - 1) / sizeof(int32_t)) * sizeof(int32_t);

    VIPER_LOGD("Viper_ICommand() EFFECT_CMD_GET_PARAM called with data = %d, psize = %d, vsize = %d", *(uint32_t *) pCmdParam->data, pCmdParam->psize, pCmdParam->vsize);

    memcpy(pReplyParam, pCmdParam, sizeof(effect_param_t) + pCmdParam->psize);

    switch (*(uint32_t *) pCmdParam->data) {
        case PARAM_GET_ENABLED: {
            pReplyParam->status = 0;
            pReplyParam->vsize = sizeof(int32_t);
            *(int32_t *) (pReplyParam->data + vOffset) = pContext->viper->enabled;
            *pReplySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
            return 0;
        }
        case PARAM_GET_CONFIGURE: {
            pReplyParam->status = 0;
            pReplyParam->vsize = sizeof(int32_t);
            *(int32_t *) (pReplyParam->data + vOffset) = pContext->isConfigValid;
            *pReplySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
            return 0;
        }
        case PARAM_GET_STREAMING: { // Is processing
            struct timeval time{};
            gettimeofday(&time, nullptr);

            uint64_t currentMs = (uint64_t) (time.tv_sec * 1000) + (uint64_t) (time.tv_usec / 1000);
            uint64_t lastProcessTime = pContext->viper->processTimeMs;

            uint64_t diff;
            if (currentMs > lastProcessTime) {
                diff = currentMs - lastProcessTime;
            } else {
                diff = lastProcessTime - currentMs;
            }

            pReplyParam->status = 0;
            pReplyParam->vsize = sizeof(int32_t);
            *(int32_t *) (pReplyParam->data + vOffset) = diff > 5000 ? 0 : 1;
            *pReplySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
            return 0;
        }
        case PARAM_GET_SAMPLING_RATE: {
            pReplyParam->status = 0;
            pReplyParam->vsize = sizeof(uint32_t);
            *(uint32_t *) (pReplyParam->data + vOffset) = pContext->viper->samplingRate;
            *pReplySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
            return 0;
        }
        case PARAM_GET_CONVOLUTION_KERNEL_ID: {
            pReplyParam->status = 0;
            pReplyParam->vsize = sizeof(uint32_t);
            *(uint32_t *) (pReplyParam->data + vOffset) = pContext->viper->convolver->GetKernelID();
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
    }
    return 0;
}

static int32_t Viper_ICommand(effect_handle_t self,
                              uint32_t cmdCode, uint32_t cmdSize, void *pCmdData,
                              uint32_t *replySize, void *pReplyData) {
    VIPER_LOGD("Viper_ICommand(self = %p, cmdCode = %d, cmdSize = %d, pCmdData = %p, replySize = %p, pReplyData = %p)", self, cmdCode, cmdSize, pCmdData, replySize, pReplyData);

    auto pContext = reinterpret_cast<ViperContext *>(self);

    if (pContext == nullptr || replySize == nullptr || pReplyData == nullptr) {
        VIPER_LOGD("Viper_ICommand() called with null self or replySize or pReplyData");
        return -EINVAL;
    }

    switch (cmdCode) {
        case EFFECT_CMD_INIT:
            *((int *) pReplyData) = 0;
            return 0;
        case EFFECT_CMD_SET_CONFIG: {
            *(int *) pReplyData = handleSetConfig(pContext, (effect_config_t *) pCmdData);
            return 0;
        }
        case EFFECT_CMD_RESET: {
            pContext->viper->ResetAllEffects();
            *((int *) pReplyData) = 0;
            return 0;
        }
        case EFFECT_CMD_ENABLE: {
            pContext->viper->ResetAllEffects();
            pContext->viper->enabled = true;
            *((int *) pReplyData) = 0;
            return 0;
        }
        case EFFECT_CMD_DISABLE: {
            pContext->viper->enabled = false;
            *((int *) pReplyData) = 0;
            return 0;
        }
        case EFFECT_CMD_SET_PARAM: {
            return handleSetParam(pContext, (effect_param_t *) pCmdData, pReplyData);
        }
        case EFFECT_CMD_GET_PARAM: {
            return handleGetParam(pContext, (effect_param_t *) pCmdData, (effect_param_t *) pReplyData, replySize);
        }
        case EFFECT_CMD_GET_CONFIG: {
            *(effect_config_t *) pReplyData = pContext->config;
            return 0;
        }
    }

    return -EINVAL;
}

static int32_t Viper_IGetDescriptor(effect_handle_t self, effect_descriptor_t *pDescriptor) {
    auto pContext = reinterpret_cast<ViperContext *>(self);

    if (pContext == nullptr || pDescriptor == nullptr) return -EINVAL;

    *pDescriptor = viper_descriptor;

    return 0;
}

static const effect_interface_s viper_interface = {
        .process = Viper_IProcess,
        .command = Viper_ICommand,
        .get_descriptor = Viper_IGetDescriptor
};

static void Viper_Init(ViperContext *pContext) {
    pContext->interface = &viper_interface;
    memset(&pContext->config, 0, sizeof(effect_config_t));
    pContext->viper = new ViPER();
}

static int32_t
Viper_Create(const effect_uuid_t *uuid, int32_t sessionId __unused, int32_t ioId __unused, effect_handle_t *pHandle) {
    VIPER_LOGD("Viper_Create(uuid = %p, sessionId = %d, ioId = %d, pHandle = %p)", uuid, sessionId, ioId, pHandle);

    if (uuid == nullptr || pHandle == nullptr) {
        VIPER_LOGD("Viper_Create() called with null uuid or pHandle");
        return -EINVAL;
    }

    if (memcmp(uuid, &viper_descriptor.uuid, sizeof(effect_uuid_t)) != 0) {
        VIPER_LOGD("Viper_Create() called with wrong uuid");
        return -EINVAL;
    }

    VIPER_LOGD("Creating new ViPER instance");
    auto *pContext = new ViperContext;
    Viper_Init(pContext);
    *pHandle = reinterpret_cast<effect_handle_t>(pContext);

    return 0;
}

static int32_t Viper_Release(effect_handle_t handle) {
    VIPER_LOGD("Viper_Release(handle = %p)", handle);

    auto pContext = reinterpret_cast<ViperContext *>(handle);

    if (pContext == nullptr) {
        VIPER_LOGD("Viper_Release() called with null handle");
        return -EINVAL;
    }

    VIPER_LOGD("Releasing ViPER instance");
    delete pContext->viper;
    delete pContext;

    return 0;
}

static int32_t Viper_GetDescriptor(const effect_uuid_t *uuid, effect_descriptor_t *pDescriptor) {
    VIPER_LOGD("Viper_GetDescriptor(uuid = %p, pDescriptor = %p)", uuid, pDescriptor);

    if (uuid == nullptr || pDescriptor == nullptr) {
        VIPER_LOGD("Viper_GetDescriptor() called with null uuid or pDescriptor");
        return -EINVAL;
    }

    if (memcmp(uuid, &viper_descriptor.uuid, sizeof(effect_uuid_t)) != 0) {
        VIPER_LOGD("Viper_GetDescriptor() called with wrong uuid");
        return -EINVAL;
    }

    *pDescriptor = viper_descriptor;

    return 0;
}

__attribute__ ((visibility ("default")))
audio_effect_library_t AUDIO_EFFECT_LIBRARY_INFO_SYM = {
        .tag = AUDIO_EFFECT_LIBRARY_TAG,
        .version = EFFECT_LIBRARY_API_VERSION,
        .name = VIPER_EFFECT_NAME,
        .implementor = VIPER_AUTHORS,
        .create_effect = Viper_Create,
        .release_effect = Viper_Release,
        .get_descriptor = Viper_GetDescriptor,
};

} // extern "C"
