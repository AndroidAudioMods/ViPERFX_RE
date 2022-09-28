#include <cstring>
#include <cerrno>
#include <ctime>

#include "viper/ViPER.h"
#include "essential.h"
#include "log.h"
#include "viper/constants.h"

#define VIPER_EFFECT_NAME "ViPER4Android"

static effect_descriptor_t viper_descriptor = {
        // Identical type/uuid to original ViPER4Android
        .type = {0x00000000, 0x0000, 0x0000, 0x0000, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
        .uuid = {0x41d3c987, 0xe6cf, 0x11e3, 0xa88a, {0x11, 0xab, 0xa5, 0xd5, 0xc5, 0x1b}},
        .apiVersion = EFFECT_CONTROL_API_VERSION,
        .flags = EFFECT_FLAG_OUTPUT_BOTH | EFFECT_FLAG_INPUT_BOTH | EFFECT_FLAG_INSERT_LAST | EFFECT_FLAG_TYPE_INSERT,
        .cpuLoad = 8, // In 0.1 MIPS units as estimated on an ARM9E core (ARMv5TE) with 0 WS
        .memoryUsage = 1, // In KB and includes only dynamically allocated memory
        .name = VIPER_EFFECT_NAME,
        .implementor = VIPER_AUTHORS
};

extern "C" {
struct ViperContext {
    const struct effect_interface_s *interface; // Should always be the first struct member
    effect_config_t config;
    ViPER *viper;
};

static int32_t Viper_IProcess(effect_handle_t self, audio_buffer_t *inBuffer, audio_buffer_t *outBuffer) {
    auto pContext = reinterpret_cast<ViperContext *>(self);

    if (pContext == nullptr ||
        inBuffer == nullptr || outBuffer == nullptr ||
        inBuffer->raw == nullptr || outBuffer->raw == nullptr ||
        inBuffer->frameCount != outBuffer->frameCount ||
        inBuffer->frameCount == 0) {
        return -EINVAL;
    }

    float *inBufferPtr = inBuffer->f32;
    float *outBufferPtr = outBuffer->f32;

    if (inBufferPtr != outBufferPtr) {
        memcpy(outBufferPtr, inBufferPtr, outBuffer->frameCount * 2 * sizeof(float));
    }

    /*return */pContext->viper->processBuffer(outBufferPtr, outBuffer->frameCount);
    return 0; // TODO: Return code from processBuffer()
}

static int configure(ViperContext *pContext, effect_config_t *newConfig) {
    VIPER_LOGI("Begin audio configure ...");
    VIPER_LOGI("Checking input and output configuration ...");

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

    if (newConfig->inputCfg.format != AUDIO_FORMAT_PCM_FLOAT) {
        VIPER_LOGE("ViPER4Android disabled, reason [in.FMT = %d]", newConfig->inputCfg.format);
        VIPER_LOGE("We only accept f32 format");
        return -EINVAL;
    }

    if (newConfig->outputCfg.format != AUDIO_FORMAT_PCM_FLOAT) {
        VIPER_LOGE("ViPER4Android disabled, reason [out.FMT = %d]", newConfig->outputCfg.format);
        VIPER_LOGE("We only accept f32 format");
        return -EINVAL;
    }

    VIPER_LOGI("Input and output configuration checked.");

    pContext->config = *newConfig;

    VIPER_LOGI("Audio configure finished");

    return 0;
}

static int32_t Viper_ICommand(effect_handle_t self,
                              uint32_t cmdCode, uint32_t cmdSize, void *pCmdData,
                              uint32_t *replySize, void *pReplyData) {
    auto pContext = reinterpret_cast<ViperContext *>(self);

    if (pContext == nullptr || pContext->viper == nullptr) {
        VIPER_LOGE("Viper_ICommand: pContext or pContext->viper is null!");
        return -EINVAL;
    }

    VIPER_LOGD("Viper_ICommand() called with cmdCode = %d", cmdCode);
    switch (cmdCode) {
        case EFFECT_CMD_INIT:
            *((int *) pReplyData) = 0;
            return 0;
        case EFFECT_CMD_SET_CONFIG: {
            auto currentSampleRate = pContext->viper->samplingRate;

            *(int *) pReplyData = configure(pContext, (effect_config_t *) pCmdData);
            if (*(int *) pReplyData == 0) {
                if (currentSampleRate != pContext->viper->samplingRate) {
                    pContext->viper->ResetAllEffects();
                }
            }

            return 0;
        }
        case EFFECT_CMD_RESET: {
            pContext->viper->ResetAllEffects();
            break;
        }
        case EFFECT_CMD_ENABLE: {
            if (!pContext->viper->enabled) {
                pContext->viper->ResetAllEffects();
            }
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
            auto pCmdParam = (effect_param_t *) pCmdData;
            // The value offset of an effect parameter is computed by rounding up
            // the parameter size to the next 32 bit alignment.
            uint32_t vOffset = ((pCmdParam->psize + sizeof(int32_t) - 1) / sizeof(int32_t)) * sizeof(int32_t);

            int param = *(int *) (pCmdParam->data);
            *(int *) pReplyData = 0;

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
        }
        case EFFECT_CMD_GET_PARAM: {
            auto *pCmdParam = reinterpret_cast<effect_param_t *>(pCmdData);
            auto *pReplyParam = reinterpret_cast<effect_param_t *>(pReplyData);

            // The value offset of an effect parameter is computed by rounding up
            // the parameter size to the next 32 bit alignment.
            uint32_t vOffset = ((pCmdParam->psize + sizeof(int32_t) - 1) / sizeof(int32_t)) * sizeof(int32_t);

            memcpy(pReplyParam, pCmdParam, sizeof(effect_param_t) + pCmdParam->psize);

            switch (*(uint32_t *) pCmdParam->data) {
                case PARAM_GET_DRIVER_VERSION: {
                    pReplyParam->status = 0;
                    pReplyParam->vsize = sizeof(uint32_t);
                    *(uint32_t *) (pReplyParam->data + vOffset) = 0x2050004; // As original, change as needed
                    *replySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
                    return 0;
                }
                case PARAM_GET_ENABLED: {
                    pReplyParam->status = 0;
                    pReplyParam->vsize = sizeof(int32_t);
                    *(int32_t *) (pReplyParam->data + vOffset) = pContext->viper->enabled;
                    *replySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
                    return 0;
                }
                case PARAM_GET_CONFIGURE: {
                    pReplyParam->status = 0;
                    pReplyParam->vsize = sizeof(int32_t);
                    *(int32_t *) (pReplyParam->data + vOffset) = 1; // TODO?
                    *replySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
                    return 0;
                }
                case PARAM_GET_DRVCANWORK: {
                    pReplyParam->status = 0;
                    pReplyParam->vsize = sizeof(int32_t);
                    *(int32_t *) (pReplyParam->data + vOffset) = pContext->viper->init_ok;
                    *replySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
                    return 0;
                }
                case PARAM_GET_STREAMING: { // Is processing
                    struct timeval time{};
                    gettimeofday(&time, nullptr);

                    // TODO: Do some calculations

                    return 0;
                }
                case PARAM_GET_SAMPLINGRATE: {
                    pReplyParam->status = 0;
                    pReplyParam->vsize = sizeof(uint32_t);
                    *(uint32_t *) (pReplyParam->data + vOffset) = pContext->viper->samplingRate;
                    *replySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
                    return 0;
                }
                case PARAM_GET_CONVKNLID: {
                    pReplyParam->status = 0;
                    pReplyParam->vsize = sizeof(uint32_t);
                    *(uint32_t *) (pReplyParam->data + vOffset) = pContext->viper->convolver->GetKernelID();
                    *replySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
                    return 0;
                }
            }
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

    if (pContext == nullptr || pDescriptor == nullptr) {
        VIPER_LOGE("Viper_IGetDescriptor: pContext or pDescriptor is null!");
        return -EINVAL;
    }

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

    pContext->config.inputCfg.accessMode = EFFECT_BUFFER_ACCESS_READ;
    pContext->config.inputCfg.format = AUDIO_FORMAT_PCM_FLOAT;
    pContext->config.inputCfg.samplingRate = DEFAULT_SAMPLERATE;
    pContext->config.inputCfg.channels = AUDIO_CHANNEL_OUT_STEREO;
    pContext->config.inputCfg.mask = AUDIO_PORT_CONFIG_ALL;

    pContext->config.outputCfg.accessMode = EFFECT_BUFFER_ACCESS_WRITE;
    pContext->config.outputCfg.format = AUDIO_FORMAT_PCM_FLOAT;
    pContext->config.outputCfg.samplingRate = DEFAULT_SAMPLERATE;
    pContext->config.outputCfg.channels = AUDIO_CHANNEL_OUT_STEREO;
    pContext->config.outputCfg.mask = AUDIO_PORT_CONFIG_ALL;

    pContext->viper = new ViPER();
}

static int32_t
Viper_Create(const effect_uuid_t *uuid, int32_t sessionId __unused, int32_t ioId __unused, effect_handle_t *pHandle) {
    VIPER_LOGI("Enter Viper_Create()");

    if (uuid == nullptr || pHandle == nullptr) {
        VIPER_LOGE("Viper_Create: uuid or pHandle is null!");
        return -EINVAL;
    }

    if (memcmp(uuid, &viper_descriptor.uuid, sizeof(effect_uuid_t)) != 0) {
        VIPER_LOGE("Viper_Create: uuid is not viper_descriptor.uuid!");
        return -EINVAL;
    }

    VIPER_LOGI("Viper_Create: uuid matches, creating viper...");

    auto *pContext = new ViperContext;
    Viper_Init(pContext);
    *pHandle = reinterpret_cast<effect_handle_t>(pContext);

    return 0;
}

static int32_t Viper_Release(effect_handle_t handle) {
    auto pContext = reinterpret_cast<ViperContext *>(handle);

    VIPER_LOGI("Enter Viper_Release()");

    if (pContext == nullptr) {
        VIPER_LOGE("Viper_Release: pContext is null!");
        return -EINVAL;
    }

    VIPER_LOGI("Viper_Release: deleting viper...");

    delete pContext->viper;
    delete pContext;

    return 0;
}

static int32_t Viper_GetDescriptor(const effect_uuid_t *uuid, effect_descriptor_t *pDescriptor) {
    VIPER_LOGI("Enter Viper_GetDescriptor()");

    if (uuid == nullptr || pDescriptor == nullptr) {
        VIPER_LOGE("Viper_GetDescriptor: uuid or pDescriptor is null!");
        return -EINVAL;
    }

    if (memcmp(uuid, &viper_descriptor.uuid, sizeof(effect_uuid_t)) != 0) {
        VIPER_LOGE("Viper_GetDescriptor: uuid is not viper_descriptor.uuid!");
        return -EINVAL;
    }

    VIPER_LOGI("Viper_GetDescriptor: uuid matches, returning descriptor...");

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
