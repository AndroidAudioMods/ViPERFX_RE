#include <remote.h>
#include <dsp_capabilities_utils.h>
extern "C" {
#include <pd_status_notification.h>
}
#include "v4a.h"
#include "ViperContext.h"
#include "ViPER4Android.h"
#include "log.h"
#include "hexagon.h"

#define STATUS_CONTEXT 0x37303061

int pd_status_notifier_callback(void *context, int domain, int session, remote_rpc_status_flags_t status){
    int nErr = AEE_SUCCESS;
    switch (status){
        case FASTRPC_USER_PD_UP:
                VIPER_LOGI("PD is up");
                break;
        case FASTRPC_USER_PD_EXIT:
                VIPER_LOGI("PD closed");
                break;
        case FASTRPC_USER_PD_FORCE_KILL:
                VIPER_LOGI("PD force kill");
                break;
        case FASTRPC_USER_PD_EXCEPTION:
                VIPER_LOGI("PD exception");
                break;
        case FASTRPC_DSP_SSR:
               VIPER_LOGI("DSP SSR");
               break;
        default:
               nErr = AEE_EBADITEM;
               break;
    }
    return nErr;
}

ViperContext::ViperContext() : mHandleLock() {
    std::lock_guard<std::mutex> guard(mHandleLock);

    VIPER_LOGI("ViperContext created");
    int nErr = 0;

    {
        uint32_t cap = 0;
        if (AEE_SUCCESS != (nErr = get_hex_arch_ver(CDSP_DOMAIN_ID, &cap))) {
            VIPER_LOGF("get_hex_arch_ver failed: 0x%x", nErr);
        } else {
            VIPER_LOGI("CDSP arch: 0x%08x", cap);
        }
    }

    {
        struct remote_rpc_control_unsigned_module data;
        data.domain = CDSP_DOMAIN_ID;
        data.enable = 1;
        if (AEE_SUCCESS != (nErr = remote_session_control(DSPRPC_CONTROL_UNSIGNED_MODULE, (void*)&data, sizeof(data)))) {
            VIPER_LOGF("remote_session_control failed (unsigned PD): 0x%x", nErr);
        }
    }

    {
        struct remote_rpc_thread_params data;
        data.domain = CDSP_DOMAIN_ID;
        data.prio = -1;
        data.stack_size = 7*1024*1024;;
        if (AEE_SUCCESS != (nErr = remote_session_control(FASTRPC_THREAD_PARAMS, (void*)&data, sizeof(data)))) {
            VIPER_LOGF("remote_session_control failed (stack size): 0x%x", nErr);
        }
    }

    if(AEE_SUCCESS != (nErr = request_status_notifications_enable(CDSP_DOMAIN_ID, (void*)STATUS_CONTEXT, pd_status_notifier_callback))) {
        if(nErr != AEE_EUNSUPPORTEDAPI) {
           VIPER_LOGF("request_status_notifications_enable failed: 0x%x", nErr);
        }
    }

    if (AEE_SUCCESS == (nErr = v4a_open(v4a_URI CDSP_DOMAIN, &handle))) {
        VIPER_LOGI("Offloaded effect library initialized: 0x%lx", handle);
    } else {
        VIPER_LOGF("Failed to initialize offloaded effect library: 0x%x", nErr);
    }
}

ViperContext::~ViperContext() {
    std::lock_guard<std::mutex> guard(mHandleLock);
    v4a_close(handle);
}

int32_t ViperContext::handleCommand(uint32_t cmdCode, uint32_t cmdSize, void *pCmdData, uint32_t *pReplySize, void *pReplyData) {
    std::lock_guard<std::mutex> guard(mHandleLock);
    hexagon_effect_config_t qdspCfg;
    effect_config_t *cfg = nullptr;
    if (cmdCode == EFFECT_CMD_SET_CONFIG) {
        cfg = (effect_config_t *) pCmdData;
        if (cfg->inputCfg.mask & EFFECT_CONFIG_FORMAT) {
            switch (cfg->inputCfg.format) {
                case AUDIO_FORMAT_PCM_FLOAT:
                case AUDIO_FORMAT_PCM_32_BIT:
                case AUDIO_FORMAT_PCM_8_24_BIT:
                    in_size = 4;
                    break;
                case AUDIO_FORMAT_PCM_24_BIT_PACKED:
                    in_size = 3;
                    break;
                case AUDIO_FORMAT_PCM_16_BIT:
                    in_size = 2;
                    break;
            }
        }
        if (cfg->outputCfg.mask & EFFECT_CONFIG_FORMAT) {
            switch (cfg->outputCfg.format) {
                case AUDIO_FORMAT_PCM_FLOAT:
                case AUDIO_FORMAT_PCM_32_BIT:
                case AUDIO_FORMAT_PCM_8_24_BIT:
                    out_size = 4;
                    break;
                case AUDIO_FORMAT_PCM_24_BIT_PACKED:
                    out_size = 3;
                    break;
                case AUDIO_FORMAT_PCM_16_BIT:
                    out_size = 2;
                    break;
            }
        }
        host2hexagon(cfg, &qdspCfg);
        cmdSize = sizeof(qdspCfg);
        pCmdData = (void *) &qdspCfg;
    } else if (cmdCode == EFFECT_CMD_GET_CONFIG) {
        cfg = (effect_config_t *) pReplyData;
        *pReplySize = sizeof(qdspCfg);
        pReplyData = (void *) &qdspCfg;
    } else if (cmdCode == EFFECT_CMD_SET_PARAM) {
        uint32_t key = *(uint32_t *) (((effect_param_t *) pCmdData)->data);
        if (key >= PARAM_SET_MAX) {
            VIPER_LOGE("handleSetParam: called with unknown key: %d", key);
            return -EINVAL;
        }
    } else if (cmdCode == EFFECT_CMD_GET_PARAM) {
        uint32_t key = *(uint32_t *) (((effect_param_t *) pCmdData)->data);
        if (key >= PARAM_GET_MAX) {
            VIPER_LOGE("handleGetParam: called with unknown key: %d", key);
            return -EINVAL;
        }
    } else if (cmdCode == EFFECT_CMD_DUMP) {
        return -EINVAL;
    }

    int replySize = pReplySize == nullptr ? 0 : *pReplySize;

    int32_t result = v4a_command(handle, cmdCode, (const uint8_t *) pCmdData, cmdSize, (uint8_t *) pReplyData, replySize, pReplySize);
    VIPER_LOGD("v4a_command: %d", result);

    if (cmdCode == EFFECT_CMD_GET_CONFIG) {
        hexagon2host(&qdspCfg, cfg);
        *pReplySize = sizeof(*cfg);
    }

    return result;
}

int32_t ViperContext::process(audio_buffer_t *in, audio_buffer_t *out) {
    std::lock_guard<std::mutex> guard(mHandleLock);
    return v4a_process(handle, (const uint8_t *) in->raw, in->frameCount * in_size * 2, (uint8_t *) out->raw, in->frameCount * out_size * 2, in->frameCount);
}

