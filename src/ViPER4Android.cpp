#include <cstring>
#include "viper/ViPER.h"
#include "essential.h"
#include "viper/constants.h"
#include "ViperContext.h"

extern "C" {
struct ViperHandle {
    const struct effect_interface_s *iface; // Always keep as first member
    ViperContext *context;
};

static const effect_descriptor_t viperDescriptor = {
        .type = *EFFECT_UUID_NULL,
        .uuid = {0x90380da3, 0x8536, 0x4744, 0xa6a3, {0x57, 0x31, 0x97, 0x0e, 0x64, 0x0f}},
        .apiVersion = EFFECT_CONTROL_API_VERSION,
        .flags = EFFECT_FLAG_OUTPUT_DIRECT | EFFECT_FLAG_INPUT_DIRECT | EFFECT_FLAG_INSERT_LAST |
                 EFFECT_FLAG_TYPE_INSERT,
        .cpuLoad = 8, // In 0.1 MIPS units as estimated on an ARM9E core (ARMv5TE) with 0 WS
        .memoryUsage = 1, // In KB and includes only dynamically allocated memory
        .name = VIPER_NAME,
        .implementor = VIPER_AUTHORS
};

static int32_t viperInterfaceProcess(effect_handle_t self, audio_buffer_t *inBuffer, audio_buffer_t *outBuffer) {
    auto viperHandle = reinterpret_cast<ViperHandle *>(self);
    if (viperHandle == nullptr) return -EINVAL;

    return viperHandle->context->process(inBuffer, outBuffer);
}

static int32_t viperInterfaceCommand(effect_handle_t self,
                                     uint32_t cmdCode, uint32_t cmdSize, void *pCmdData,
                                     uint32_t *replySize, void *pReplyData) {
    auto viperHandle = reinterpret_cast<ViperHandle *>(self);
    if (viperHandle == nullptr) return -EINVAL;

    return viperHandle->context->handleCommand(cmdCode, cmdSize, pCmdData, replySize, pReplyData);
}

static int32_t viperInterfaceGetDescriptor(effect_handle_t self, effect_descriptor_t *pDescriptor) {
    if (pDescriptor == nullptr) return -EINVAL;
    *pDescriptor = viperDescriptor;
    return 0;
}

static const effect_interface_s viperInterface = {
        .process = viperInterfaceProcess,
        .command = viperInterfaceCommand,
        .get_descriptor = viperInterfaceGetDescriptor
};

static int32_t
viperLibraryCreate(const effect_uuid_t *uuid, int32_t sessionId __unused, int32_t ioId __unused,
                   effect_handle_t *pHandle) {
    if (uuid == nullptr || pHandle == nullptr) return -EINVAL;
    if (memcmp(uuid, &viperDescriptor.uuid, sizeof(effect_uuid_t)) != 0) return -ENOENT;

    ViperHandle *viperHandle = new ViperHandle();
    viperHandle->iface = &viperInterface;
    viperHandle->context = new ViperContext();
    *pHandle = reinterpret_cast<effect_handle_t>(viperHandle);
    return 0;
}

static int32_t viperLibraryRelease(effect_handle_t handle) {
    auto viperHandle = reinterpret_cast<ViperHandle *>(handle);
    if (viperHandle == nullptr) return -EINVAL;

    delete viperHandle->context;
    return 0;
}

static int32_t viperLibraryGetDescriptor(const effect_uuid_t *uuid, effect_descriptor_t *pDescriptor) {
    if (uuid == nullptr || pDescriptor == nullptr) return -EINVAL;
    if (memcmp(uuid, &viperDescriptor.uuid, sizeof(effect_uuid_t)) != 0) return -ENOENT;

    *pDescriptor = viperDescriptor;
    return 0;
}

__attribute__ ((visibility ("default")))
audio_effect_library_t AUDIO_EFFECT_LIBRARY_INFO_SYM = {
        .tag = AUDIO_EFFECT_LIBRARY_TAG,
        .version = EFFECT_LIBRARY_API_VERSION,
        .name = VIPER_NAME,
        .implementor = VIPER_AUTHORS,
        .create_effect = viperLibraryCreate,
        .release_effect = viperLibraryRelease,
        .get_descriptor = viperLibraryGetDescriptor,
};
} // extern "C"