#include <cstring>
#include <cerrno>

#include "viper/ViPER.h"
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
    ViPER *viper;
};

static int32_t Viper_IProcess(effect_handle_t self, audio_buffer_t *inBuffer, audio_buffer_t *outBuffer) {
    auto pContext = (ViperContext *) self;

    if (pContext == nullptr || pContext->viper == nullptr || inBuffer == nullptr || outBuffer == nullptr) {
        VIPER_LOGE("Viper_IProcess: pContext, pContext->viper, inBuffer or outBuffer is null!");
        return -EINVAL;
    }

    return pContext->viper->process(inBuffer, outBuffer);
}

static int32_t Viper_ICommand(effect_handle_t self,
                              uint32_t cmdCode, uint32_t cmdSize, void *pCmdData,
                              uint32_t *replySize, void *pReplyData) {
    auto pContext = (ViperContext *) self;

    if (pContext == nullptr || pContext->viper == nullptr) {
        VIPER_LOGE("Viper_ICommand: pContext or pContext->viper is null!");
        return -EINVAL;
    }

    return pContext->viper->command(cmdCode, cmdSize, pCmdData, replySize, pReplyData);
}

static int32_t Viper_IGetDescriptor(effect_handle_t self, effect_descriptor_t *pDescriptor) {
    auto *pContext = (ViperContext *) self;

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

    auto *pContext = new ViperContext();
    pContext->interface = &viper_interface;
    pContext->viper = new ViPER();

    *pHandle = (effect_handle_t) pContext;

    return 0;
}

static int32_t Viper_Release(effect_handle_t handle) {
    auto *pContext = (ViperContext *) handle;

    VIPER_LOGI("Enter Viper_Release()");

    if (pContext == nullptr) {
        VIPER_LOGE("Viper_Release: pContext is null!");
        return -EINVAL;
    }

    VIPER_LOGI("Viper_Release: deleting viper...");

    if (pContext->viper != nullptr) {
        delete pContext->viper;
        pContext->viper = nullptr;
    }
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
