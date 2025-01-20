#pragma once

#include <vector>
#include <cstddef>
#include "essential.h"
#ifndef HEXAGON_STUB
#include "viper/ViPER.h"
#else
#include <mutex>
#endif
#include <string>

class ViperContext {
public:
    enum class DisableReason : int32_t {
        UNKNOWN = -1,
        NONE = 0,
        INVALID_FRAME_COUNT,
        INVALID_SAMPLING_RATE,
        INVALID_CHANNEL_COUNT,
        INVALID_FORMAT,
    };

    ViperContext();
    ~ViperContext();

    int32_t handleCommand(uint32_t cmdCode, uint32_t cmdSize, void *pCmdData, uint32_t *replySize, void *pReplyData);
    int32_t process(audio_buffer_t *inBuffer, audio_buffer_t *outBuffer);

private:
#ifdef HEXAGON_STUB
    std::mutex mHandleLock;
    uint64_t handle = 0;
    size_t in_size = 0;
    size_t out_size = 0;
#else
    effect_config_t config;
    DisableReason disableReason;

    // Processing buffer
    std::vector<float> buffer;
    size_t bufferFrameCount;

    // Viper
    bool enabled;
    ViPER viper;

    static void copyBufferConfig(buffer_config_t *dest, buffer_config_t *src);
    void handleSetConfig(effect_config_t *newConfig);
    int32_t handleSetParam(effect_param_t *pCmdParam, void *pReplyData);
    int32_t handleGetParam(effect_param_t *pCmdParam, effect_param_t *pReplyParam, uint32_t *pReplySize);

    void setDisableReason(DisableReason reason);
#endif
};
