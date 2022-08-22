#include <cstring>

#include "Effect.h"
#include "ProcessUnit_FX.h"
#include "constants.h"
#include "log.h"

static effect_descriptor_t viper_descriptor = {
        // Identical type/uuid to original ViPER4Android
        .type = {0x00000000, 0x0000, 0x0000, 0x0000, {  0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
        .uuid = {0x41d3c987, 0xe6cf, 0x11e3, 0xa88a, { 0x11, 0xab, 0xa5, 0xd5, 0xc5, 0x1b } },
        .apiVersion = EFFECT_CONTROL_API_VERSION,
        .flags = EFFECT_FLAG_OUTPUT_BOTH | EFFECT_FLAG_INPUT_BOTH | EFFECT_FLAG_INSERT_LAST | EFFECT_FLAG_TYPE_INSERT,
        .cpuLoad = 8, // In 0.1 MIPS units as estimated on an ARM9E core (ARMv5TE) with 0 WS
        .memoryUsage = 1, // In KB and includes only dynamically allocated memory
};

extern "C" {
    struct ViperContext {
        const struct effect_interface_s *interface;
        ProcessUnit_FX *effect;
        effect_descriptor_t *descriptor;
    };

    static int32_t viper_process(effect_handle_t self, audio_buffer_t *in, audio_buffer_t *out) {
        auto pContext = (ViperContext *) self;

		if (pContext == nullptr) {
			v4a_printf(ANDROID_LOG_ERROR, "viper_process(), Error [pContext = NULL]");
			return -EINVAL;
		}

		if (in == nullptr) {
			v4a_printf(ANDROID_LOG_ERROR, "viper_process(), Error [in = NULL]");
			return -EINVAL;
		}

		if (out == nullptr) {
			v4a_printf(ANDROID_LOG_ERROR, "viper_process(), Error [out = NULL]");
			return -EINVAL;
		}

        return pContext->effect->process(in, out);
    }

    static int32_t viper_command(effect_handle_t self, uint32_t cmdCode, uint32_t cmdSize, void *pCmdData, uint32_t *replySize, void *pReplyData) {
        auto pContext = (ViperContext *) self;

		if (pContext == nullptr) {
			v4a_printf(ANDROID_LOG_ERROR, "viper_command(), Error [pContext = NULL]");
			return -EINVAL;
		}

        return pContext->effect->command(cmdCode, cmdSize, pCmdData, replySize, pReplyData);
    }

    static int32_t viper_get_descriptor(effect_handle_t self, effect_descriptor_t *pDescriptor) {
        auto *pContext = (ViperContext *) self;

		if (pContext == nullptr) {
			v4a_printf(ANDROID_LOG_ERROR, "viper_get_descriptor(), Error [pContext = NULL]");
			return -EINVAL;
		}

		if (pDescriptor == nullptr) {
			v4a_print(ANDROID_LOG_ERROR, "viper_get_descriptor(), Error [pDescriptor = NULL]");
			return -EINVAL;
		}

		*pDescriptor = *pContext->descriptor;

        return 0;
    }

    const effect_interface_s viper_interface = {
        .process = viper_process,
        .command = viper_command,
        .get_descriptor = viper_get_descriptor
    };

    int32_t viper_effect_create(const effect_uuid_t *uuid, int32_t sessionId, int32_t ioId, effect_handle_t *pHandle) {
        v4a_print(ANDROID_LOG_INFO, "Enter viper_effect_create()");

		if (uuid == nullptr) {
			v4a_printf(ANDROID_LOG_ERROR, "viper_effect_create(), Error [uuid = NULL]");
			return -EINVAL;
		}

		if (pHandle == nullptr) {
			v4a_printf(ANDROID_LOG_ERROR, "viper_effect_create(), Error [pHandle = NULL]");
			return -EINVAL;
		}

		if (memcmp(uuid, &viper_descriptor.uuid, sizeof(effect_uuid_t)) != 0) {
			v4a_print(ANDROID_LOG_ERROR, "viper_effect_create(), Error [effect not found]");
			return -EINVAL;
		}

		v4a_printf(ANDROID_LOG_INFO, "viper_effect_create(), uuid = %08x-%04x-%04x-%04x-%02x%02x%02x%02x%02x%02x", uuid->timeLow, uuid->timeMid, uuid->timeHiAndVersion, uuid->clockSeq, uuid->node[0], uuid->node[1], uuid->node[2], uuid->node[3], uuid->node[4], uuid->node[5]);
		v4a_print(ANDROID_LOG_INFO, "viper_effect_create(), v4a standard effect (normal), Constructing ProcessUnit_FX");

		auto *pContext = new ViperContext;
		pContext->interface = &viper_interface;
		pContext->effect = new ProcessUnit_FX();
		pContext->descriptor = &viper_descriptor;

		v4a_print(ANDROID_LOG_INFO, "Creating ViPER4Android Reworked [" VERSION_STRING "]");
		*pHandle = (effect_handle_t) pContext;

        return 0;
    }

    int32_t viper_effect_release(effect_handle_t handle) {
		auto *pContext = (ViperContext *) handle;

		v4a_print(ANDROID_LOG_INFO, "Enter viper_effect_release()");

		if (pContext == nullptr) {
			v4a_printf(ANDROID_LOG_ERROR, "viper_effect_release(), Error [pContext = NULL]");
			return -EINVAL;
		}

        v4a_print(ANDROID_LOG_INFO, "viper_effect_release(), Deconstructing ProcessUnit");

		if (pContext->effect != nullptr) {
			delete pContext->effect;
			pContext->effect = nullptr;
		}
		delete pContext;

        return 0;
    }

    int32_t viper_effect_get_descriptor(const effect_uuid_t *uuid, effect_descriptor_t *pDescriptor) {
        v4a_print(ANDROID_LOG_INFO, "Enter viper_effect_get_descriptor()");

		if (uuid == nullptr) {
			v4a_printf(ANDROID_LOG_ERROR, "viper_effect_get_descriptor(), Error [uuid = NULL]");
			return -EINVAL;
		}

		if (pDescriptor == nullptr) {
			v4a_printf(ANDROID_LOG_ERROR, "viper_effect_get_descriptor(), Error [pDescriptor = NULL]");
			return -EINVAL;
		}

		if (memcmp(uuid, &viper_descriptor.uuid, sizeof(effect_uuid_t)) != 0) {
			v4a_print(ANDROID_LOG_ERROR, "viper_effect_get_descriptor(), Error [effect not found]");
			return -EINVAL;
		}

		v4a_printf(ANDROID_LOG_INFO, "viper_effect_get_descriptor(), uuid = %08x-%04x-%04x-%04x-%02x%02x%02x%02x%02x%02x", uuid->timeLow, uuid->timeMid, uuid->timeHiAndVersion, uuid->clockSeq, uuid->node[0], uuid->node[1], uuid->node[2], uuid->node[3], uuid->node[4], uuid->node[5]);

		*pDescriptor = viper_descriptor;

        return 0;
    }

    audio_effect_library_t AUDIO_EFFECT_LIBRARY_INFO_SYM = {
        .tag = AUDIO_EFFECT_LIBRARY_TAG,
        .version = EFFECT_LIBRARY_API_VERSION,
        .name = "ViPER4Android FX Reworked",
        .implementor = "ViPER.WYF, Martmists, Iscle",
        .create_effect = viper_effect_create,
        .release_effect = viper_effect_release,
        .get_descriptor = viper_effect_get_descriptor,
    };
}
