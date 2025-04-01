#include <cstring>
#include "viper/ViPER.h"
#include "essential.h"
#include "viper/constants.h"
#include "ViperContext.h"
#include "aidl/android/hardware/audio/effect/Descriptor.h"
#include "aidl/android/hardware/audio/effect/Flags.h"
#include "aidl/android/hardware/audio/effect/IEffect.h"
#include "aidl/android/media/audio/common/AudioUuid.h"
#include <android/binder_status.h>
#include <android/binder_auto_utils.h>
#include "viper_aidl.h"

using aidl::android::hardware::audio::effect::Descriptor;
using aidl::android::hardware::audio::effect::Flags;
using aidl::android::hardware::audio::effect::IEffect;
using aidl::android::media::audio::common::AudioUuid;

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
                                     uint32_t *pReplySize, void *pReplyData) {
    auto viperHandle = reinterpret_cast<ViperHandle *>(self);
    if (viperHandle == nullptr) return -EINVAL;

    return viperHandle->context->handleCommand(cmdCode, cmdSize, pCmdData, pReplySize, pReplyData);
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
} // extern "C"


extern "C" binder_exception_t createEffect(const AudioUuid *audio_uuid, std::shared_ptr<IEffect> *instance) {
    if (audio_uuid == nullptr || instance == nullptr) {
        VIPER_LOGE("createEffect called with null arguments");
        return EX_ILLEGAL_ARGUMENT;
    }
    VIPER_LOGD("createEffect called");
    *instance = ndk::SharedRefBase::make<ViPER4AndroidAIDL>();
    return EX_ILLEGAL_ARGUMENT;
}

extern "C" binder_exception_t destroyEffect(const std::shared_ptr<IEffect> &instanceSp) {
    VIPER_LOGD("destroyEffect called");
    return EX_ILLEGAL_STATE;
}

inline AudioUuid stringToUuid(const char* str) {
    AudioUuid uuid{};
    uint32_t tmp[10];
    if (!str || sscanf(str, "%08x-%04x-%04x-%04x-%02x%02x%02x%02x%02x%02x", tmp,
                       tmp + 1, tmp + 2, tmp + 3, tmp + 4, tmp + 5, tmp + 6,
                       tmp + 7, tmp + 8, tmp + 9) < 10) {
        return uuid;
    }

    uuid.timeLow = (uint32_t)tmp[0];
    uuid.timeMid = (uint16_t)tmp[1];
    uuid.timeHiAndVersion = (uint16_t)tmp[2];
    uuid.clockSeq = (uint16_t)tmp[3];
    uuid.node.insert(uuid.node.end(), {(uint8_t)tmp[4], (uint8_t)tmp[5], (uint8_t)tmp[6],
                                       (uint8_t)tmp[7], (uint8_t)tmp[8], (uint8_t)tmp[9]});
    return uuid;
}

const AudioUuid kType = stringToUuid("b9bc100c-26cd-42e6-acb6-cad8c3f778de");
const AudioUuid kUuid = stringToUuid("90380da3-8536-4744-a6a3-5731970e640f");
const Descriptor kDescriptor = {
        .common = {
                .id = {
                        .type = kType,
                        .uuid = kUuid,
                        .proxy = std::nullopt
                },
                .flags = {
                        .type = Flags::Type::INSERT,
                        .insert = Flags::Insert::LAST,
                        .volume = Flags::Volume::NONE
                },
                .name = VIPER_NAME,
                .implementor = VIPER_AUTHORS,
        },
};

extern "C" binder_exception_t queryEffect(const AudioUuid *audio_uuid, Descriptor *descriptor) {
    if (audio_uuid == nullptr || descriptor == nullptr) {
        VIPER_LOGE("queryEffect called with null arguments");
        return EX_ILLEGAL_ARGUMENT;
    }
    if (*audio_uuid != kUuid) {
        VIPER_LOGE("queryEffect called with invalid uuid");
        return EX_ILLEGAL_ARGUMENT;
    }
    VIPER_LOGD("queryEffect: returning descriptor");
    *descriptor = kDescriptor;
    return EX_NONE;
}

extern "C"
__attribute__((visibility("default")))
audio_effect_library_t AUDIO_EFFECT_LIBRARY_INFO_SYM = {
        .tag = AUDIO_EFFECT_LIBRARY_TAG,
        .version = EFFECT_LIBRARY_API_VERSION,
        .name = VIPER_NAME,
        .implementor = VIPER_AUTHORS,
        .create_effect = viperLibraryCreate,
        .release_effect = viperLibraryRelease,
        .get_descriptor = viperLibraryGetDescriptor,
};