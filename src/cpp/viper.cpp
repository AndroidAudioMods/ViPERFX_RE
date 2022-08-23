#include <cstring>

#include "ProcessUnit_FX.h"
#include "constants.h"
#include "log.h"

#define EFFECT_NAME "ViPER4Android Reworked " VERSION_STRING
#define EFFECT_IMPLEMENTOR "ViPER.WYF, Martmists, Iscle"

static effect_descriptor_t viper_descriptor = {
        // Identical type/uuid to original ViPER4Android
        .type = {0x00000000, 0x0000, 0x0000, 0x0000, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
        .uuid = {0x41d3c987, 0xe6cf, 0x11e3, 0xa88a, {0x11, 0xab, 0xa5, 0xd5, 0xc5, 0x1b}},
        .apiVersion = EFFECT_CONTROL_API_VERSION,
        .flags = EFFECT_FLAG_OUTPUT_BOTH | EFFECT_FLAG_INPUT_BOTH | EFFECT_FLAG_INSERT_LAST | EFFECT_FLAG_TYPE_INSERT,
        .cpuLoad = 8, // In 0.1 MIPS units as estimated on an ARM9E core (ARMv5TE) with 0 WS
        .memoryUsage = 1, // In KB and includes only dynamically allocated memory
        .name = EFFECT_NAME,
        .implementor = EFFECT_IMPLEMENTOR
};

extern "C" {
struct ViperContext {
    const struct effect_interface_s *interface; // Should always be the first struct member
    ProcessUnit_FX *effect;
};

static int32_t ViperProcess(effect_handle_t self, audio_buffer_t *inBuffer, audio_buffer_t *outBuffer) {
    auto pContext = (ViperContext *) self;

    if (pContext == nullptr) {
        v4a_printf(ANDROID_LOG_ERROR, "ViperProcess(), Error [pContext = NULL]");
        return -EINVAL;
    }

    if (inBuffer == nullptr) {
        v4a_printf(ANDROID_LOG_ERROR, "ViperProcess(), Error [inBuffer = NULL]");
        return -EINVAL;
    }

    if (outBuffer == nullptr) {
        v4a_printf(ANDROID_LOG_ERROR, "ViperProcess(), Error [outBuffer = NULL]");
        return -EINVAL;
    }

    return pContext->effect->process(inBuffer, outBuffer);
}

static int32_t
ViperCommand(effect_handle_t self, uint32_t cmdCode, uint32_t cmdSize, void *pCmdData, uint32_t *replySize,
              void *pReplyData) {
    auto pContext = (ViperContext *) self;

    if (pContext == nullptr) {
        v4a_printf(ANDROID_LOG_ERROR, "ViperCommand(), Error [pContext = NULL]");
        return -EINVAL;
    }

    return pContext->effect->command(cmdCode, cmdSize, pCmdData, replySize, pReplyData);
}

static int32_t ViperGetDescriptor(effect_handle_t self, effect_descriptor_t *pDescriptor) {
    auto *pContext = (ViperContext *) self;

    if (pContext == nullptr) {
        v4a_printf(ANDROID_LOG_ERROR, "ViperGetDescriptor(), Error [pContext = NULL]");
        return -EINVAL;
    }

    if (pDescriptor == nullptr) {
        v4a_print(ANDROID_LOG_ERROR, "ViperGetDescriptor(), Error [pDescriptor = NULL]");
        return -EINVAL;
    }

    *pDescriptor = viper_descriptor;

    return 0;
}

const effect_interface_s viper_interface = {
        .process = ViperProcess,
        .command = ViperCommand,
        .get_descriptor = ViperGetDescriptor
};

int32_t ViperEffectCreate(const effect_uuid_t *uuid, int32_t sessionId, int32_t ioId, effect_handle_t *pHandle) {
    v4a_print(ANDROID_LOG_INFO, "Enter ViperEffectCreate()");

    if (uuid == nullptr) {
        v4a_printf(ANDROID_LOG_ERROR, "ViperEffectCreate(), Error [uuid = NULL]");
        return -EINVAL;
    }

    if (pHandle == nullptr) {
        v4a_printf(ANDROID_LOG_ERROR, "ViperEffectCreate(), Error [pHandle = NULL]");
        return -EINVAL;
    }

    if (memcmp(uuid, &viper_descriptor.uuid, sizeof(effect_uuid_t)) != 0) {
        v4a_print(ANDROID_LOG_ERROR, "ViperEffectCreate(), Error [effect not found]");
        return -EINVAL;
    }

    v4a_printf(ANDROID_LOG_INFO, "ViperEffectCreate(), uuid = %08x-%04x-%04x-%04x-%02x%02x%02x%02x%02x%02x",
               uuid->timeLow, uuid->timeMid, uuid->timeHiAndVersion, uuid->clockSeq, uuid->node[0], uuid->node[1],
               uuid->node[2], uuid->node[3], uuid->node[4], uuid->node[5]);
    v4a_print(ANDROID_LOG_INFO, "ViperEffectCreate(), Constructing ProcessUnit_FX");

    auto *pContext = new ViperContext;
    pContext->interface = &viper_interface;
    pContext->effect = new ProcessUnit_FX();

    *pHandle = (effect_handle_t) pContext;

    return 0;
}

int32_t ViperEffectRelease(effect_handle_t handle) {
    auto *pContext = (ViperContext *) handle;

    v4a_print(ANDROID_LOG_INFO, "Enter ViperEffectRelease()");

    if (pContext == nullptr) {
        v4a_printf(ANDROID_LOG_ERROR, "ViperEffectRelease(), Error [pContext = NULL]");
        return -EINVAL;
    }

    v4a_print(ANDROID_LOG_INFO, "ViperEffectRelease(), Deconstructing ProcessUnit");

    if (pContext->effect != nullptr) {
        delete pContext->effect;
        pContext->effect = nullptr;
    }
    delete pContext;

    return 0;
}

int32_t ViperEffectGetDescriptor(const effect_uuid_t *uuid, effect_descriptor_t *pDescriptor) {
    v4a_print(ANDROID_LOG_INFO, "Enter ViperEffectGetDescriptor()");

    if (uuid == nullptr) {
        v4a_printf(ANDROID_LOG_ERROR, "ViperEffectGetDescriptor(), Error [uuid = NULL]");
        return -EINVAL;
    }

    if (pDescriptor == nullptr) {
        v4a_printf(ANDROID_LOG_ERROR, "ViperEffectGetDescriptor(), Error [pDescriptor = NULL]");
        return -EINVAL;
    }

    if (memcmp(uuid, &viper_descriptor.uuid, sizeof(effect_uuid_t)) != 0) {
        v4a_print(ANDROID_LOG_ERROR, "ViperEffectGetDescriptor(), Error [effect not found]");
        return -EINVAL;
    }

    v4a_printf(ANDROID_LOG_INFO, "ViperEffectGetDescriptor(), uuid = %08x-%04x-%04x-%04x-%02x%02x%02x%02x%02x%02x",
               uuid->timeLow, uuid->timeMid, uuid->timeHiAndVersion, uuid->clockSeq, uuid->node[0], uuid->node[1],
               uuid->node[2], uuid->node[3], uuid->node[4], uuid->node[5]);

    *pDescriptor = viper_descriptor;

    return 0;
}

audio_effect_library_t AUDIO_EFFECT_LIBRARY_INFO_SYM = {
        .tag = AUDIO_EFFECT_LIBRARY_TAG,
        .version = EFFECT_LIBRARY_API_VERSION,
        .name = EFFECT_NAME,
        .implementor = EFFECT_IMPLEMENTOR,
        .create_effect = ViperEffectCreate,
        .release_effect = ViperEffectRelease,
        .get_descriptor = ViperEffectGetDescriptor,
};
}
