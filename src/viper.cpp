#include <cstring>
#include <hardware/audio_effect.h>
#include <cstdlib>

#include "Effect.h"
#include "ProcessUnit_FX.h"

static effect_descriptor_t viper_descriptor = {
        // Identical type/uuid to original ViPER4Android
        .type = {0x00000000, 0x0000, 0x0000, 0x0000, {  0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
        .uuid = {0x41d3c987, 0xe6cf, 0x11e3, 0xa88a, { 0x11, 0xab, 0xa5, 0xd5, 0xc5, 0x1b } },
        .apiVersion = 0x20000,
        .flags = 0xf010,
        .cpuLoad = 0x08,
        .memoryUsage = 0x01,
};

extern "C" {
    typedef struct {
        const struct effect_interface_s* interface;
        Effect* effect;
        effect_descriptor_t* descriptor;
    } handle;

    static int32_t generic_process(effect_handle_t self, audio_buffer_t *in, audio_buffer_t *out) {
        auto e = (handle *) self;
        return e->effect->process(in, out);
    }
    static int32_t generic_command(effect_handle_t self, uint32_t cmdCode, uint32_t cmdSize, void *pCmdData, uint32_t *replySize, void *pReplyData) {
        auto e = (handle *) self;
        return e->effect->command(cmdCode, cmdSize, pCmdData, replySize, pReplyData);
    }
    static int32_t generic_getDescriptor(effect_handle_t self, effect_descriptor_t *pDescriptor) {
        auto e = (handle *) self;
        strcpy(viper_descriptor.name, "ViPER4Android Reworked [1.0.0.0]");
        strcpy(viper_descriptor.implementor, "ViPER.WYF, Martmists, Iscle");

        memcpy(pDescriptor, e->descriptor, sizeof(effect_descriptor_t));
        return 0;
    }

    const effect_interface_s viper_interface = {
        .process = generic_process,
        .command = generic_command,
        .get_descriptor = generic_getDescriptor,
        .process_reverse = nullptr
    };

    int32_t EffectCreate(const effect_uuid_t *uuid, int32_t sessionId, int32_t ioId, effect_handle_t *pEffect) {
        if (memcmp(uuid, &viper_descriptor.uuid, sizeof(effect_uuid_t)) == 0) {
            // UUID matches
            strcpy(viper_descriptor.name, "ViPER4Android Reworked [1.0.0.0]");
            strcpy(viper_descriptor.implementor, "ViPER.WYF, Martmists, Iscle");

            auto ptr = (handle*)calloc(1, sizeof(handle));
            ptr->interface = &viper_interface;
            ptr->effect = new ProcessUnit_FX();
            ptr->descriptor = &viper_descriptor;
            *pEffect = (effect_handle_t)ptr;
        } else {
            return -ENOENT;
        }
        return 0;
    }

    int32_t EffectRelease(effect_handle_t ei) {
        auto ptr = (handle*)ei;
        delete ptr->effect;
        free(ptr);
        return 0;
    }

    int32_t EffectGetDescriptor(const effect_uuid_t *uuid, effect_descriptor_t *pDescriptor) {
        if (memcmp(uuid, &viper_descriptor.uuid, sizeof(effect_uuid_t)) == 0) {
            strcpy(viper_descriptor.name, "ViPER4Android Reworked [1.0.0.0]");
            strcpy(viper_descriptor.implementor, "ViPER.WYF, Martmists, Iscle");

            memcpy(pDescriptor, &viper_descriptor, sizeof(effect_descriptor_t));
        } else {
            return -EINVAL;
        }
        return 0;
    }

    audio_effect_library_t AUDIO_EFFECT_LIBRARY_INFO_SYM = {
        .tag =  ((('A') << 24) | (('E') << 16) | (('L') << 8) | ('I')),
        .version = 0x30000,
        .name = "ViPER4Android FX Reworked",
        .implementor = "ViPER.WYF, Martmists, Iscle",
        .create_effect = EffectCreate,
        .release_effect = EffectRelease,
        .get_descriptor = EffectGetDescriptor,
    };
}
