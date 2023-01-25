#include <cstring>
#include <ctime>
#include <cstdlib>
#include "viper/ViPER.h"
#include "essential.h"
#include "log.h"
#include "viper/constants.h"

#define VIPER_EFFECT_NAME "ViPER4Android"

extern "C" {
static effect_descriptor_t viperDescriptor = {
        .type = *EFFECT_UUID_NULL,
        .uuid = {0x90380da3, 0x8536, 0x4744, 0xa6a3, {0x57, 0x31, 0x97, 0x0e, 0x64, 0x0f}},
        .apiVersion = EFFECT_CONTROL_API_VERSION,
        .flags = EFFECT_FLAG_OUTPUT_DIRECT | EFFECT_FLAG_INPUT_DIRECT | EFFECT_FLAG_INSERT_LAST | EFFECT_FLAG_TYPE_INSERT,
        .cpuLoad = 8, // In 0.1 MIPS units as estimated on an ARM9E core (ARMv5TE) with 0 WS
        .memoryUsage = 1, // In KB and includes only dynamically allocated memory
        .name = VIPER_EFFECT_NAME,
        .implementor = VIPER_AUTHORS
};

struct ViPERContext {
    // Interface, MUST be the first member of the structure
    const struct effect_interface_s *interface;

    // Config
    effect_config_t config;
    bool isConfigValid;

    // Processing buffer
    float *buffer;
    size_t bufferFrameCount;

    // Viper
    bool enabled;
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

static audio_buffer_t *getBuffer(buffer_config_s *config, audio_buffer_t *buffer) {
    if (buffer != nullptr) return buffer;
    return &config->buffer;
}

static int32_t ViPERInterfaceProcess(effect_handle_t self, audio_buffer_t *inBuffer, audio_buffer_t *outBuffer) {
    auto pContext = reinterpret_cast<ViPERContext *>(self);

    if (pContext == nullptr || !pContext->isConfigValid) {
        return -EINVAL;
    }

    if (!pContext->enabled) {
        return -ENODATA;
    }

    inBuffer = getBuffer(&pContext->config.inputCfg, inBuffer);
    outBuffer = getBuffer(&pContext->config.outputCfg, outBuffer);
    if (inBuffer == nullptr || outBuffer == nullptr ||
        inBuffer->raw == nullptr || outBuffer->raw == nullptr ||
        inBuffer->frameCount != outBuffer->frameCount ||
        inBuffer->frameCount == 0) {
        return -EINVAL;
    }

    size_t frameCount = inBuffer->frameCount;
    if (frameCount > pContext->bufferFrameCount) {
        delete[] pContext->buffer;
        pContext->buffer = new float[frameCount * 2];
        pContext->bufferFrameCount = frameCount;
    }
    float *buffer = pContext->buffer;

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
            return -EINVAL;
    }

    pContext->viper->processBuffer(buffer, frameCount);

    const bool accumulate = pContext->config.outputCfg.accessMode == EFFECT_BUFFER_ACCESS_ACCUMULATE;
    switch (pContext->config.outputCfg.format) {
        case AUDIO_FORMAT_PCM_16_BIT:
            floatToPcm16(outBuffer->s16, buffer, frameCount, accumulate);
            break;
        case AUDIO_FORMAT_PCM_32_BIT:
            floatToPcm32(outBuffer->s32, buffer, frameCount, accumulate);
            break;
        case AUDIO_FORMAT_PCM_FLOAT:
            floatToFloat(outBuffer->f32, buffer, frameCount, accumulate);
            break;
        default:
            return -EINVAL;
    }

    return 0;
}

static int handleSetConfig(ViPERContext *pContext, effect_config_t *newConfig) {
    VIPER_LOGI("Checking input and output configuration ...");

    VIPER_LOGI("Input buffer frame count: %d", newConfig->inputCfg.buffer.frameCount);
    VIPER_LOGI("Input sampling rate: %d", newConfig->inputCfg.samplingRate);
    VIPER_LOGI("Input channels: %d", newConfig->inputCfg.channels);
    VIPER_LOGI("Input format: %d", newConfig->inputCfg.format);
    VIPER_LOGI("Input access mode: %d", newConfig->inputCfg.accessMode);
    VIPER_LOGI("Output buffer frame count: %d", newConfig->outputCfg.buffer.frameCount);
    VIPER_LOGI("Output sampling rate: %d", newConfig->outputCfg.samplingRate);
    VIPER_LOGI("Output channels: %d", newConfig->outputCfg.channels);
    VIPER_LOGI("Output format: %d", newConfig->outputCfg.format);
    VIPER_LOGI("Output access mode: %d", newConfig->outputCfg.accessMode);

    pContext->isConfigValid = false;
    delete[] pContext->buffer;
    pContext->buffer = nullptr;

    if (newConfig->inputCfg.buffer.frameCount != newConfig->outputCfg.buffer.frameCount) {
        VIPER_LOGE("ViPER4Android disabled, reason [in.FC = %d, out.FC = %d]",
                   newConfig->inputCfg.buffer.frameCount, newConfig->outputCfg.buffer.frameCount);
//        pContext->disableReason = "Invalid frame count";
        return 0;
    }

    if (newConfig->inputCfg.samplingRate != newConfig->outputCfg.samplingRate) {
        VIPER_LOGE("ViPER4Android disabled, reason [in.SR = %d, out.SR = %d]",
                   newConfig->inputCfg.samplingRate, newConfig->outputCfg.samplingRate);
//        pContext->disableReason = "Invalid sampling rate";
        return 0;
    }

    if (newConfig->inputCfg.samplingRate > 48000) {
        VIPER_LOGE("ViPER4Android disabled, reason [SR out of range]");
//        pContext->disableReason = "Sampling rate out of range";
        return 0;
    }

    if (newConfig->inputCfg.channels != newConfig->outputCfg.channels) {
        VIPER_LOGE("ViPER4Android disabled, reason [in.CH = %d, out.CH = %d]",
                   newConfig->inputCfg.channels, newConfig->outputCfg.channels);
//        pContext->disableReason = "Invalid channel count";
        return 0;
    }

    if (newConfig->inputCfg.channels != AUDIO_CHANNEL_OUT_STEREO) {
        VIPER_LOGE("ViPER4Android disabled, reason [CH != 2]");
//        pContext->disableReason = "Channel count != 2";
        return 0;
    }

    if (newConfig->inputCfg.format != AUDIO_FORMAT_PCM_16_BIT &&
        newConfig->inputCfg.format != AUDIO_FORMAT_PCM_32_BIT &&
        newConfig->inputCfg.format != AUDIO_FORMAT_PCM_FLOAT) {
        VIPER_LOGE("ViPER4Android disabled, reason [in.FMT = %d]", newConfig->inputCfg.format);
        VIPER_LOGE("We only accept AUDIO_FORMAT_PCM_16_BIT, AUDIO_FORMAT_PCM_32_BIT and AUDIO_FORMAT_PCM_FLOAT input format!");
//        pContext->disableReason = "Invalid input format";
        return 0;
    }

    if (newConfig->outputCfg.format != AUDIO_FORMAT_PCM_16_BIT &&
        newConfig->outputCfg.format != AUDIO_FORMAT_PCM_32_BIT &&
        newConfig->outputCfg.format != AUDIO_FORMAT_PCM_FLOAT) {
        VIPER_LOGE("ViPER4Android disabled, reason [out.FMT = %d]", newConfig->outputCfg.format);
        VIPER_LOGE("We only accept AUDIO_FORMAT_PCM_16_BIT, AUDIO_FORMAT_PCM_32_BIT and AUDIO_FORMAT_PCM_FLOAT output format!");
//        pContext->disableReason = "Invalid output format";
        return 0;
    }

    VIPER_LOGI("Input and output configuration checked.");

    // Config
    pContext->config = *newConfig;
    pContext->isConfigValid = true;
//    pContext->disableReason = "";
    // Processing buffer
    pContext->buffer = new float[newConfig->inputCfg.buffer.frameCount * 2];
    pContext->bufferFrameCount = newConfig->inputCfg.buffer.frameCount;
    // ViPER
    pContext->viper->samplingRate = newConfig->inputCfg.samplingRate;
    pContext->viper->ResetAllEffects();

    return 0;
}

static int32_t handleSetParam(ViPERContext *pContext, effect_param_t *pCmdParam, void *pReplyData) {
    // The value offset of an effect parameter is computed by rounding up
    // the parameter size to the next 32 bit alignment.
    uint32_t vOffset = ((pCmdParam->psize + sizeof(int32_t) - 1) / sizeof(int32_t)) * sizeof(int32_t);

    *(int *) pReplyData = 0;

    int param = *(int *) (pCmdParam->data);
    int *intValues = (int *) (pCmdParam->data + vOffset);
    switch (pCmdParam->vsize) {
        case sizeof(int): {
            pContext->viper->DispatchCommand(param, intValues[0], 0, 0, 0, 0, nullptr);
            return 0;
        }
        case sizeof(int) * 2: {
            pContext->viper->DispatchCommand(param, intValues[0], intValues[1], 0, 0, 0, nullptr);
            return 0;
        }
        case sizeof(int) * 3: {
            pContext->viper->DispatchCommand(param, intValues[0], intValues[1], intValues[2], 0, 0, nullptr);
            return 0;
        }
        case sizeof(int) * 4: {
            pContext->viper->DispatchCommand(param, intValues[0], intValues[1], intValues[2], intValues[3], 0, nullptr);
            return 0;
        }
        case 256:
        case 1024: {
            uint32_t arrSize = *(uint32_t *) (pCmdParam->data + vOffset);
            signed char *arr = (signed char *) (pCmdParam->data + vOffset + sizeof(uint32_t));
            pContext->viper->DispatchCommand(param, 0, 0, 0, 0, arrSize, arr);
            return 0;
        }
        case 8192: {
            int value1 = *(int *) (pCmdParam->data + vOffset);
            uint32_t arrSize = *(uint32_t *) (pCmdParam->data + vOffset + sizeof(int));
            signed char *arr = (signed char *) (pCmdParam->data + vOffset + sizeof(int) + sizeof(uint32_t));
            pContext->viper->DispatchCommand(param, value1, 0, 0, 0, arrSize, arr);
            return 0;
        }
        default: {
            return -EINVAL;
        }
    }
}

static int32_t handleGetParam(ViPERContext *pContext, effect_param_t *pCmdParam, effect_param_t *pReplyParam, uint32_t *pReplySize) {
    // The value offset of an effect parameter is computed by rounding up
    // the parameter size to the next 32 bit alignment.
    uint32_t vOffset = ((pCmdParam->psize + sizeof(int32_t) - 1) / sizeof(int32_t)) * sizeof(int32_t);

    VIPER_LOGD("ViPERInterfaceCommand() EFFECT_CMD_GET_PARAM called with data = %d, psize = %d, vsize = %d", *(uint32_t *) pCmdParam->data, pCmdParam->psize, pCmdParam->vsize);

    memcpy(pReplyParam, pCmdParam, sizeof(effect_param_t) + pCmdParam->psize);

    switch (*(uint32_t *) pCmdParam->data) {
        case PARAM_GET_ENABLED: {
            pReplyParam->status = 0;
            pReplyParam->vsize = sizeof(int32_t);
            *(int32_t *) (pReplyParam->data + vOffset) = pContext->enabled;
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
        default: {
            return -EINVAL;
        }
    }
}

#define SET_INT32(ptr, value) (*(int32_t *) (ptr) = (value))
#define GET_REPLY_SIZE(ptr) (ptr == nullptr ? 0 : *ptr)

static int32_t ViPERInterfaceCommand(effect_handle_t self,
                                     uint32_t cmdCode, uint32_t cmdSize, void *pCmdData,
                                     uint32_t *replySize, void *pReplyData) {
    auto context = reinterpret_cast<ViPERContext *>(self);
    if (context == nullptr) return -EINVAL;

    switch (cmdCode) {
        case EFFECT_CMD_INIT: {
            if (GET_REPLY_SIZE(replySize) != sizeof(int32_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_INIT called with invalid replySize = %d, pReplyData = %p, expected replySize = %d", GET_REPLY_SIZE(replySize), pReplyData, sizeof(int32_t));
                return -EINVAL;
            }
            SET_INT32(pReplyData, 0);
            return 0;
        }
        case EFFECT_CMD_SET_CONFIG: {
            if (cmdSize < sizeof(effect_config_t) || pCmdData == nullptr || GET_REPLY_SIZE(replySize) != sizeof(int32_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_SET_CONFIG called with invalid cmdSize = %d, pCmdData = %p, replySize = %d, pReplyData = %p, expected cmdSize = %d, replySize = %d", cmdSize, pCmdData, GET_REPLY_SIZE(replySize), pReplyData, sizeof(effect_config_t), sizeof(int32_t));
                return -EINVAL;
            }
            SET_INT32(pReplyData, handleSetConfig(context, (effect_config_t *) pCmdData));
            return 0;
        }
        case EFFECT_CMD_RESET: {
            if (GET_REPLY_SIZE(replySize) != sizeof(int32_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_RESET called with invalid replySize = %d, pReplyData = %p, expected replySize = %d", GET_REPLY_SIZE(replySize), pReplyData, sizeof(int32_t));
                return -EINVAL;
            }
            context->viper->ResetAllEffects();
            SET_INT32(pReplyData, 0);
            return 0;
        }
        case EFFECT_CMD_ENABLE: {
            if (GET_REPLY_SIZE(replySize) != sizeof(int32_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_ENABLE called with invalid replySize = %d, pReplyData = %p, expected replySize = %d", GET_REPLY_SIZE(replySize), pReplyData, sizeof(int32_t));
                return -EINVAL;
            }
            context->viper->ResetAllEffects();
            context->enabled = true;
            SET_INT32(pReplyData, 0);
            return 0;
        }
        case EFFECT_CMD_DISABLE: {
            if (GET_REPLY_SIZE(replySize) != sizeof(int32_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_DISABLE called with invalid replySize = %d, pReplyData = %p, expected replySize = %d", GET_REPLY_SIZE(replySize), pReplyData, sizeof(int32_t));
                return -EINVAL;
            }
            context->enabled = false;
            SET_INT32(pReplyData, 0);
            return 0;
        }
        case EFFECT_CMD_SET_PARAM: {
            if (cmdSize < sizeof(effect_param_t) || pCmdData == nullptr || GET_REPLY_SIZE(replySize) != sizeof(int32_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_SET_PARAM called with invalid cmdSize = %d, pCmdData = %p, replySize = %d, pReplyData = %p, expected cmdSize = %d, replySize = %d", cmdSize, pCmdData, GET_REPLY_SIZE(replySize), pReplyData, sizeof(effect_param_t), sizeof(int32_t));
                return -EINVAL;
            }
            return handleSetParam(context, (effect_param_t *) pCmdData, pReplyData);
        }
        case EFFECT_CMD_GET_PARAM: {
            if (cmdSize < sizeof(effect_param_t) || pCmdData == nullptr || GET_REPLY_SIZE(replySize) < sizeof(effect_param_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_GET_PARAM called with invalid cmdSize = %d, pCmdData = %p, replySize = %d, pReplyData = %p, expected cmdSize = %d, replySize = %d", cmdSize, pCmdData, GET_REPLY_SIZE(replySize), pReplyData, sizeof(effect_param_t), sizeof(effect_param_t));
                return -EINVAL;
            }
            return handleGetParam(context, (effect_param_t *) pCmdData, (effect_param_t *) pReplyData, replySize);
        }
        case EFFECT_CMD_GET_CONFIG: {
            if (GET_REPLY_SIZE(replySize) != sizeof(effect_config_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_GET_CONFIG called with invalid replySize = %d, pReplyData = %p, expected replySize = %d", GET_REPLY_SIZE(replySize), pReplyData, sizeof(effect_config_t));
                return -EINVAL;
            }
            *(effect_config_t *) pReplyData = context->config;
            return 0;
        }
        default: {
            VIPER_LOGE("ViPERInterfaceCommand called with unknown command: %d", cmdCode);
            return -EINVAL;
        }
    }
}

static int32_t ViPERInterfaceGetDescriptor(effect_handle_t self, effect_descriptor_t *pDescriptor) {
    auto context = reinterpret_cast<ViPERContext *>(self);
    if (context == nullptr || pDescriptor == nullptr) return -EINVAL;

    *pDescriptor = viperDescriptor;
    return 0;
}

static const effect_interface_s viper_interface = {
        .process = ViPERInterfaceProcess,
        .command = ViPERInterfaceCommand,
        .get_descriptor = ViPERInterfaceGetDescriptor
};

static ViPERContext *createViPERContext() {
    auto context = new ViPERContext();
    context->interface = &viper_interface;
    context->viper = new ViPER();
    return context;
}

static int32_t
ViPERCreate(const effect_uuid_t *uuid, int32_t sessionId __unused, int32_t ioId __unused, effect_handle_t *pHandle) {
    if (uuid == nullptr || pHandle == nullptr) return -EINVAL;
    if (memcmp(uuid, &viperDescriptor.uuid, sizeof(effect_uuid_t)) != 0) return -ENOENT;

    VIPER_LOGD("Creating ViPER");
    auto context = createViPERContext();
    *pHandle = reinterpret_cast<effect_handle_t>(context);

    return 0;
}

static void deleteViPERContext(ViPERContext *context) {
    delete[] context->buffer;
    delete context->viper;
    delete context;
}

static int32_t ViPERRelease(effect_handle_t handle) {
    auto context = reinterpret_cast<ViPERContext *>(handle);
    if (context == nullptr) return -EINVAL;

    VIPER_LOGD("Releasing ViPER");
    deleteViPERContext(context);

    return 0;
}

static int32_t ViPERGetDescriptor(const effect_uuid_t *uuid, effect_descriptor_t *pDescriptor) {
    if (uuid == nullptr || pDescriptor == nullptr) return -EINVAL;
    if (memcmp(uuid, &viperDescriptor.uuid, sizeof(effect_uuid_t)) != 0) return -ENOENT;

    *pDescriptor = viperDescriptor;
    return 0;
}

__attribute__ ((visibility ("default")))
audio_effect_library_t AUDIO_EFFECT_LIBRARY_INFO_SYM = {
        .tag = AUDIO_EFFECT_LIBRARY_TAG,
        .version = EFFECT_LIBRARY_API_VERSION,
        .name = VIPER_EFFECT_NAME,
        .implementor = VIPER_AUTHORS,
        .create_effect = ViPERCreate,
        .release_effect = ViPERRelease,
        .get_descriptor = ViPERGetDescriptor,
};

} // extern "C"
