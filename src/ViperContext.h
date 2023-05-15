#pragma once

#include <vector>
#include <cstddef>
#include "essential.h"
#include "viper/ViPER.h"
#include <string>

class ViperContext {
public:
    enum class DisableReason {
        NONE,
        UNKNOWN,
        INVALID_FRAME_COUNT,
        INVALID_SAMPLING_RATE,
        INVALID_CHANNEL_COUNT,
        INVALID_FORMAT,
    };

    ViperContext();

    int32_t handleCommand(uint32_t cmdCode, uint32_t cmdSize, void *pCmdData, uint32_t *replySize, void *pReplyData);
    int32_t process(audio_buffer_t *inBuffer, audio_buffer_t *outBuffer);

private:
    effect_config_t config;
    DisableReason disableReason;
    std::string disableReasonMessage;

    // Processing buffer
    std::vector<float> buffer;
    size_t bufferFrameCount;

    // Viper
    bool enabled;
    ViPER viper;

    void handleSetConfig(effect_config_t *newConfig);
    int32_t handleSetParam(effect_param_t *pCmdParam, void *pReplyData);
    int32_t handleGetParam(effect_param_t *pCmdParam, effect_param_t *pReplyParam, uint32_t *pReplySize);

    void setDisableReason(DisableReason reason);
    void setDisableReason(DisableReason reason, std::string message);
};
