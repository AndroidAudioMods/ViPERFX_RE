#include <cerrno>
#include <cstring>
#include <cmath>
#include <chrono>
#include "ViperContext.h"
#include "log.h"
#include "viper/constants.h"

#define SET(type, ptr, value) (*(type *) (ptr) = (value))

ViperContext::ViperContext() :
        config({}),
        disableReason(DisableReason::UNKNOWN),
        buffer(std::vector<float>()),
        bufferFrameCount(0),
        enabled(false) {
    VIPER_LOGI("ViperContext created");
}

void ViperContext::copyBufferConfig(buffer_config_t *dest, buffer_config_t *src) {
    if (src->mask & EFFECT_CONFIG_BUFFER) {
        dest->buffer = src->buffer;
    }

    if (src->mask & EFFECT_CONFIG_SMP_RATE) {
        dest->samplingRate = src->samplingRate;
    }

    if (src->mask & EFFECT_CONFIG_CHANNELS) {
        dest->channels = src->channels;
    }

    if (src->mask & EFFECT_CONFIG_FORMAT) {
        dest->format = src->format;
    }

    if (src->mask & EFFECT_CONFIG_ACC_MODE) {
        dest->accessMode = src->accessMode;
    }

    if (src->mask & EFFECT_CONFIG_PROVIDER) {
        dest->bufferProvider = src->bufferProvider;
    }

    dest->mask |= src->mask;
}

void ViperContext::handleSetConfig(effect_config_t *newConfig) {
    VIPER_LOGI("Checking input and output configuration ...");

    VIPER_LOGI("Input mask: 0x%04X", newConfig->inputCfg.mask);
    VIPER_LOGI("Input buffer frame count: %zu", newConfig->inputCfg.buffer.frameCount);
    VIPER_LOGI("Input sampling rate: %d", newConfig->inputCfg.samplingRate);
    VIPER_LOGI("Input channels: %d", newConfig->inputCfg.channels);
    VIPER_LOGI("Input format: %d", newConfig->inputCfg.format);
    VIPER_LOGI("Input access mode: %d", newConfig->inputCfg.accessMode);
    VIPER_LOGI("Output mask: 0x%04X", newConfig->outputCfg.mask);
    VIPER_LOGI("Output buffer frame count: %zu", newConfig->outputCfg.buffer.frameCount);
    VIPER_LOGI("Output sampling rate: %d", newConfig->outputCfg.samplingRate);
    VIPER_LOGI("Output channels: %d", newConfig->outputCfg.channels);
    VIPER_LOGI("Output format: %d", newConfig->outputCfg.format);
    VIPER_LOGI("Output access mode: %d", newConfig->outputCfg.accessMode);

    setDisableReason(DisableReason::UNKNOWN);

    copyBufferConfig(&config.inputCfg, &newConfig->inputCfg);
    copyBufferConfig(&config.outputCfg, &newConfig->outputCfg);

    if (config.inputCfg.buffer.frameCount != config.outputCfg.buffer.frameCount) {
        VIPER_LOGE("ViPER4Android disabled, reason [in.FC = %zu, out.FC = %zu]",
                   config.inputCfg.buffer.frameCount, config.outputCfg.buffer.frameCount);
        setDisableReason(DisableReason::INVALID_FRAME_COUNT);
        return;
    }

    if (config.inputCfg.samplingRate != config.outputCfg.samplingRate) {
        VIPER_LOGE("ViPER4Android disabled, reason [in.SR = %d, out.SR = %d]",
                   config.inputCfg.samplingRate, config.outputCfg.samplingRate);
        setDisableReason(DisableReason::INVALID_SAMPLING_RATE);
        return;
    }

//    if (config.inputCfg.samplingRate > 48000) {
//        VIPER_LOGE("ViPER4Android disabled, reason [SR out of range]");
//        setDisableReason(DisableReason::INVALID_SAMPLING_RATE, "Sampling rate out of range: " + std::to_string(config.inputCfg.samplingRate));
//        return;
//    }

    if (config.inputCfg.channels != config.outputCfg.channels) {
        VIPER_LOGE("ViPER4Android disabled, reason [in.CH = %d, out.CH = %d]",
                   config.inputCfg.channels, config.outputCfg.channels);
        setDisableReason(DisableReason::INVALID_CHANNEL_COUNT);
        return;
    }

    if (config.inputCfg.channels != AUDIO_CHANNEL_OUT_STEREO) {
        VIPER_LOGE("ViPER4Android disabled, reason [CH != 2]");
        setDisableReason(DisableReason::INVALID_CHANNEL_COUNT);
        return;
    }

    if (config.inputCfg.format != AUDIO_FORMAT_PCM_16_BIT &&
        config.inputCfg.format != AUDIO_FORMAT_PCM_32_BIT &&
        config.inputCfg.format != AUDIO_FORMAT_PCM_FLOAT) {
        VIPER_LOGE("ViPER4Android disabled, reason [in.FMT = %d]", config.inputCfg.format);
        VIPER_LOGE("We only accept AUDIO_FORMAT_PCM_16_BIT, AUDIO_FORMAT_PCM_32_BIT and AUDIO_FORMAT_PCM_FLOAT input format!");
        setDisableReason(DisableReason::INVALID_FORMAT);
        return;
    }

    if (config.outputCfg.format != AUDIO_FORMAT_PCM_16_BIT &&
        config.outputCfg.format != AUDIO_FORMAT_PCM_32_BIT &&
        config.outputCfg.format != AUDIO_FORMAT_PCM_FLOAT) {
        VIPER_LOGE("ViPER4Android disabled, reason [out.FMT = %d]", config.outputCfg.format);
        VIPER_LOGE("We only accept AUDIO_FORMAT_PCM_16_BIT, AUDIO_FORMAT_PCM_32_BIT and AUDIO_FORMAT_PCM_FLOAT output format!");
        setDisableReason(DisableReason::INVALID_FORMAT);
        return;
    }

    VIPER_LOGI("Input and output configuration checked.");
    setDisableReason(DisableReason::NONE);

    // Processing buffer
    buffer.resize(config.inputCfg.buffer.frameCount * 2);
    bufferFrameCount = config.inputCfg.buffer.frameCount;

    // ViPER
    viper.setSamplingRate(config.inputCfg.samplingRate);
    viper.reset();
}

int32_t ViperContext::handleSetParam(effect_param_t *pCmdParam, void *pReplyData) {
    // The value offset of an effect parameter is computed by rounding up
    // the parameter size to the next 32 bit alignment.
    uint32_t vOffset = ((pCmdParam->psize + sizeof(int32_t) - 1) / sizeof(int32_t)) * sizeof(int32_t);

    if (pCmdParam->psize != sizeof(uint32_t)) {
        VIPER_LOGE("handleSetParam() EFFECT_CMD_SET_PARAM called with invalid psize = %d, expected psize = %zu", pCmdParam->vsize, sizeof(uint32_t));
        return -EINVAL;
    }

    *(int32_t *) pReplyData = 0;

    uint32_t key = *(uint32_t *) (pCmdParam->data);
    switch (key) {
        case PARAM_SET_RESET: {
            viper.reset();
            return 0;
        }
        case PARAM_SET_DDC_ENABLE: {

            return 0;
        }
        case PARAM_SET_DDC_COEFFICIENTS: {

            return 0;
        }
        case PARAM_SET_VIPER_BASS_ENABLE: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_VIPER_BASS_ENABLE called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            bool enable = *(uint8_t *) (pCmdParam->data + vOffset) != 0;
            viper.viperBass.SetEnable(enable);
            return 0;
        }
        case PARAM_SET_VIPER_BASS_MODE: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_VIPER_BASS_MODE called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            uint8_t mode = *(uint8_t *) (pCmdParam->data + vOffset);
            if (mode > 2) {
                VIPER_LOGE("handleSetParam() PARAM_SET_VIPER_BASS_MODE called with invalid mode = %d, expected mode = 0, 1 or 2", mode);
                *(int32_t *) pReplyData = -EINVAL;
                return 0;
            }

            viper.viperBass.SetProcessMode(static_cast<ViPERBass::ProcessMode>(mode));
            return 0;
        }
        case PARAM_SET_VIPER_BASS_FREQUENCY: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_VIPER_BASS_FREQUENCY called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            uint8_t frequency = *(uint8_t *) (pCmdParam->data + vOffset);
            viper.viperBass.SetSpeaker(frequency);
            return 0;
        }
        case PARAM_SET_VIPER_BASS_GAIN: {
            if (pCmdParam->vsize != sizeof(uint16_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_VIPER_BASS_GAIN called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint16_t));
                return -EINVAL;
            }
            uint16_t gain = *(uint16_t *) (pCmdParam->data + vOffset);
            viper.viperBass.SetBassFactor(static_cast<float>(gain) / 100.0f);
            return 0;
        }
        case PARAM_SET_VIPER_CLARITY_ENABLE: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_VIPER_CLARITY_ENABLE called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            bool enable = *(uint8_t *) (pCmdParam->data + vOffset) != 0;
            viper.viperClarity.SetEnable(enable);
            return 0;
        }
        case PARAM_SET_VIPER_CLARITY_MODE: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_VIPER_CLARITY_MODE called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            uint8_t mode = *(uint8_t *) (pCmdParam->data + vOffset);
            if (mode > 2) {
                VIPER_LOGE("handleSetParam() PARAM_SET_VIPER_CLARITY_MODE called with invalid mode = %d, expected mode = 0, 1 or 2", mode);
                *(int32_t *) pReplyData = -EINVAL;
                return 0;
            }

            viper.viperClarity.SetProcessMode(static_cast<ViPERClarity::ClarityMode>(mode));
            return 0;
        }
        case PARAM_SET_VIPER_CLARITY_GAIN: {
            if (pCmdParam->vsize != sizeof(uint16_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_VIPER_CLARITY_GAIN called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint16_t));
                return -EINVAL;
            }
            uint16_t gain = *(uint16_t *) (pCmdParam->data + vOffset);
            viper.viperClarity.SetClarity(static_cast<float>(gain) / 100.0f);
            return 0;
        }
        case PARAM_SET_OUTPUT_GAIN: {
            // 0 - 255
            if (pCmdParam->vsize != sizeof(uint8_t) * 2) {
                VIPER_LOGE("handleSetParam() PARAM_SET_OUTPUT_GAIN called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t) * 2);
                return -EINVAL;
            }
            uint8_t gainL = *(uint8_t *) (pCmdParam->data + vOffset);
            uint8_t gainR = *(uint8_t *) (pCmdParam->data + vOffset + sizeof(uint8_t));
            viper.setGain(static_cast<float>(gainL) / 100.0f, static_cast<float>(gainR) / 100.0f);
            return 0;
        }
        case PARAM_SET_THRESHOLD_LIMIT: {
            // 0 - 100 (TODO: Check range)
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_THRESHOLD_LIMIT called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            uint8_t limit = *(uint8_t *) (pCmdParam->data + vOffset);
            viper.setThresholdLimit(static_cast<float>(limit) / 100.0f);
            return 0;
        }
        case PARAM_SET_SPEAKER_OPTIMIZATION_ENABLE: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_SPEAKER_OPTIMIZATION_ENABLE called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            bool enable = *(uint8_t *) (pCmdParam->data + vOffset) != 0;
            viper.speakerCorrection.SetEnable(enable);
            return 0;
        }
        case PARAM_SET_ANALOGX_ENABLE: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_ANALOGX_ENABLE called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            bool enable = *(uint8_t *) (pCmdParam->data + vOffset) != 0;
            viper.analogX.SetEnable(enable);
            return 0;
        }
        case PARAM_SET_ANALOGX_LEVEL: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_ANALOGX_LEVEL called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            uint8_t level = *(uint8_t *) (pCmdParam->data + vOffset);
            if (level > 2) {
                VIPER_LOGE("handleSetParam() PARAM_SET_ANALOGX_LEVEL called with invalid level = %d, expected level = 0, 1 or 2", level);
                *(int32_t *) pReplyData = -EINVAL;
                return 0;
            }

            viper.analogX.SetProcessingModel(level);
            return 0;
        }
        case PARAM_SET_TUBE_SIMULATOR_ENABLE: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_TUBE_SIMULATOR_ENABLE called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            bool enable = *(uint8_t *) (pCmdParam->data + vOffset) != 0;
            viper.tubeSimulator.SetEnable(enable);
            return 0;
        }
        case PARAM_SET_CURE_ENABLE: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_CURE_ENABLE called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            bool enable = *(uint8_t *) (pCmdParam->data + vOffset) != 0;
            viper.cure.SetEnable(enable);
            return 0;
        }
        case PARAM_SET_CURE_LEVEL: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_CURE_LEVEL called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            uint8_t level = *(uint8_t *) (pCmdParam->data + vOffset);
            switch (level) {
                case 0: {
                    struct Crossfeed::Preset preset = {
                            .cutoff = 650,
                            .feedback = 95,
                    };
                    viper.cure.SetPreset(preset);
                    break;
                }
                case 1: {
                    struct Crossfeed::Preset preset = {
                            .cutoff = 700,
                            .feedback = 60,
                    };
                    viper.cure.SetPreset(preset);
                    break;
                }
                case 2: {
                    struct Crossfeed::Preset preset = {
                            .cutoff = 700,
                            .feedback = 45,
                    };
                    viper.cure.SetPreset(preset);
                    break;
                }
                default:
                    VIPER_LOGE("handleSetParam() PARAM_SET_CURE_LEVEL called with invalid level = %d, expected level = 0, 1 or 2", level);
                    *(int32_t *) pReplyData = -EINVAL;
                    break;
            }
            return 0;
        }
        case PARAM_SET_REVERBERATION_ENABLE: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_REVERBERATION_ENABLE called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            bool enable = *(uint8_t *) (pCmdParam->data + vOffset) != 0;
            viper.reverberation.SetEnable(enable);
            return 0;
        }
        case PARAM_SET_REVERBERATION_ROOM_SIZE: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_REVERBERATION_ROOM_SIZE called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            uint8_t roomSize = *(uint8_t *) (pCmdParam->data + vOffset);
            viper.reverberation.SetRoomSize(static_cast<float>(roomSize) / 100.0f);
            return 0;
        }
        case PARAM_SET_REVERBERATION_SOUND_FIELD: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_REVERBERATION_SOUND_FIELD called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            uint8_t soundField = *(uint8_t *) (pCmdParam->data + vOffset);
            viper.reverberation.SetWidth(static_cast<float>(soundField) / 100.0f);
            return 0;
        }
        case PARAM_SET_REVERBERATION_DAMPING: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_REVERBERATION_DAMPING called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            uint8_t damping = *(uint8_t *) (pCmdParam->data + vOffset);
            viper.reverberation.SetDamp(static_cast<float>(damping) / 100.0f);
            return 0;
        }
        case PARAM_SET_REVERBERATION_WET_SIGNAL: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_REVERBERATION_WET_SIGNAL called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            uint8_t wetSignal = *(uint8_t *) (pCmdParam->data + vOffset);
            viper.reverberation.SetWet(static_cast<float>(wetSignal) / 100.0f);
            return 0;
        }
        case PARAM_SET_REVERBERATION_DRY_SIGNAL: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_REVERBERATION_DRY_SIGNAL called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            uint8_t drySignal = *(uint8_t *) (pCmdParam->data + vOffset);
            viper.reverberation.SetDry(static_cast<float>(drySignal) / 100.0f);
            return 0;
        }
        case PARAM_SET_DIFFERENTIAL_SURROUND_ENABLE: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_DIFFERENTIAL_SURROUND_ENABLE called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            bool enable = *(uint8_t *) (pCmdParam->data + vOffset) != 0;
            viper.diffSurround.SetEnable(enable);
            return 0;
        }
        case PARAM_SET_DIFFERENTIAL_SURROUND_DELAY: {
            if (pCmdParam->vsize != sizeof(uint16_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_DIFFERENTIAL_SURROUND_DELAY called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint16_t));
                return -EINVAL;
            }
            uint16_t delay = *(uint16_t *) (pCmdParam->data + vOffset);
            viper.diffSurround.SetDelayTime(static_cast<float>(delay) / 100.0f);
            return 0;
        }
        case PARAM_SET_FIELD_SURROUND_ENABLE: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_FIELD_SURROUND_ENABLE called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            bool enable = *(uint8_t *) (pCmdParam->data + vOffset) != 0;
            viper.colorfulMusic.SetEnable(enable);
            return 0;
        }
        case PARAM_SET_FIELD_SURROUND_DEPTH: {
            if (pCmdParam->vsize != sizeof(uint16_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_FIELD_SURROUND_DEPTH called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint16_t));
                return -EINVAL;
            }
            uint16_t depth = *(uint16_t *) (pCmdParam->data + vOffset);
            viper.colorfulMusic.SetDepthValue(depth);
            return 0;
        }
        case PARAM_SET_FIELD_SURROUND_MID_IMAGE: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_FIELD_SURROUND_MID_IMAGE called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            uint8_t midImage = *(uint8_t *) (pCmdParam->data + vOffset);
            viper.colorfulMusic.SetMidImageValue(static_cast<float>(midImage) / 100.0f);
            return 0;
        }
        case PARAM_SET_IIR_EQUALIZER_ENABLE: {
            if (pCmdParam->vsize != sizeof(uint8_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_IIR_EQUALIZER_ENABLE called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t));
                return -EINVAL;
            }
            bool enable = *(uint8_t *) (pCmdParam->data + vOffset) != 0;
            viper.iirFilter.SetEnable(enable);
            return 0;
        }
        case PARAM_SET_IIR_EQUALIZER_BAND_LEVEL: {
            if (pCmdParam->vsize != sizeof(uint8_t) + sizeof(int16_t)) {
                VIPER_LOGE("handleSetParam() PARAM_SET_IIR_EQUALIZER_BAND_LEVEL called with invalid vsize = %d, expected vsize = %zu", pCmdParam->vsize, sizeof(uint8_t) + sizeof(int16_t));
                return -EINVAL;
            }
            uint8_t band = *(uint8_t *) (pCmdParam->data + vOffset);
            int16_t level = *(int16_t *) (pCmdParam->data + vOffset + sizeof(uint8_t));
            viper.iirFilter.SetBandLevel(band, static_cast<float>(level) / 100.0f);
            return 0;
        }
        default: {
            VIPER_LOGE("handleSetParam() called with unknown key: %d", key);
            return -EINVAL;
        }
    }
}

int32_t ViperContext::handleGetParam(effect_param_t *pCmdParam, effect_param_t *pReplyParam, uint32_t *pReplySize) {
    // The value offset of an effect parameter is computed by rounding up
    // the parameter size to the next 32 bit alignment.
    uint32_t vOffset = ((pCmdParam->psize + sizeof(int32_t) - 1) / sizeof(int32_t)) * sizeof(int32_t);

    if (pCmdParam->psize != sizeof(uint32_t)) {
        VIPER_LOGE("handleGetParam() EFFECT_CMD_GET_PARAM called with invalid psize = %d, expected psize = %zu", pCmdParam->vsize, sizeof(uint32_t));
        return -EINVAL;
    }

    memcpy(pReplyParam, pCmdParam, sizeof(effect_param_t) + pCmdParam->psize);

    uint32_t key = *(uint32_t *) (pCmdParam->data);
    switch (key) {
        case PARAM_GET_ENABLED: {
            pReplyParam->status = 0;
            pReplyParam->vsize = sizeof(uint8_t);
            *(uint8_t *) (pReplyParam->data + vOffset) = enabled;
            *pReplySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
            return 0;
        }
        case PARAM_GET_FRAME_COUNT: {
            pReplyParam->status = 0;
            pReplyParam->vsize = sizeof(uint64_t);
            *(uint64_t *) (pReplyParam->data + vOffset) = viper.getFrameCount();
            *pReplySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
            return 0;
        }
        case PARAM_GET_VERSION: {
            pReplyParam->status = 0;
            pReplyParam->vsize = sizeof(uint32_t);
            *(uint32_t *) (pReplyParam->data + vOffset) = VIPER_VERSION;
            *pReplySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
            return 0;
        }
        case PARAM_GET_DISABLE_REASON: {
            pReplyParam->status = 0;
            pReplyParam->vsize = sizeof(int32_t);
            *(int32_t *) (pReplyParam->data + vOffset) = static_cast<int32_t>(disableReason);
            *pReplySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
            return 0;
        }
        case PARAM_GET_CONFIG: {
            pReplyParam->status = 0;
            pReplyParam->vsize = 40;
            // Input
            SET(uint64_t, pReplyParam->data + vOffset, config.inputCfg.buffer.frameCount);
            SET(uint32_t, pReplyParam->data + vOffset + 8, config.inputCfg.samplingRate);
            SET(uint32_t, pReplyParam->data + vOffset + 12, config.inputCfg.channels);
            SET(uint8_t, pReplyParam->data + vOffset + 16, config.inputCfg.format);
            SET(uint8_t, pReplyParam->data + vOffset + 17, config.inputCfg.accessMode);
            SET(uint16_t, pReplyParam->data + vOffset + 18, config.inputCfg.mask);
            // Output
            SET(uint64_t, pReplyParam->data + vOffset + 20, config.outputCfg.buffer.frameCount);
            SET(uint32_t, pReplyParam->data + vOffset + 28, config.outputCfg.samplingRate);
            SET(uint32_t, pReplyParam->data + vOffset + 32, config.outputCfg.channels);
            SET(uint8_t, pReplyParam->data + vOffset + 36, config.outputCfg.format);
            SET(uint8_t, pReplyParam->data + vOffset + 37, config.outputCfg.accessMode);
            SET(uint16_t, pReplyParam->data + vOffset + 38, config.outputCfg.mask);
            *pReplySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
            return 0;
        }
        case PARAM_GET_ARCHITECTURE: {
            pReplyParam->status = 0;
            pReplyParam->vsize = sizeof(uint8_t);
            *(uint8_t *) (pReplyParam->data + vOffset) = static_cast<uint8_t>(VIPER_ARCHITECTURE);
            *pReplySize = sizeof(effect_param_t) + pReplyParam->psize + vOffset + pReplyParam->vsize;
            return 0;
        }
        default: {
            VIPER_LOGE("handleGetParam() called with unknown key: %d", key);
            return -EINVAL;
        }
    }
}

int32_t ViperContext::handleCommand(uint32_t cmdCode, uint32_t cmdSize, void *pCmdData, uint32_t *pReplySize, void *pReplyData) {
    uint32_t replySize = pReplySize == nullptr ? 0 : *pReplySize;
    switch (cmdCode) {
        case EFFECT_CMD_INIT: {
            if (replySize != sizeof(int32_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_INIT called with invalid replySize = %d, pReplyData = %p, expected replySize = %zu", replySize, pReplyData, sizeof(int32_t));
                return -EINVAL;
            }
            SET(int32_t, pReplyData, 0);
            return 0;
        }
        case EFFECT_CMD_SET_CONFIG: {
            if (cmdSize != sizeof(effect_config_t) || pCmdData == nullptr || replySize != sizeof(int32_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_SET_CONFIG called with invalid cmdSize = %d, pCmdData = %p, replySize = %d, pReplyData = %p, expected cmdSize = %zu, expected replySize = %zu", cmdSize, pCmdData, replySize, pReplyData, sizeof(effect_config_t), sizeof(int32_t));
                return -EINVAL;
            }
            handleSetConfig((effect_config_t *) pCmdData);
            SET(int32_t, pReplyData, 0);
            return 0;
        }
        case EFFECT_CMD_RESET: {
            if (replySize != sizeof(int32_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_RESET called with invalid replySize = %d, pReplyData = %p, expected replySize = %zu", replySize, pReplyData, sizeof(int32_t));
                return -EINVAL;
            }
            viper.reset();
            SET(int32_t, pReplyData, 0);
            return 0;
        }
        case EFFECT_CMD_ENABLE: {
            if (replySize != sizeof(int32_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_ENABLE called with invalid replySize = %d, pReplyData = %p, expected replySize = %zu", replySize, pReplyData, sizeof(int32_t));
                return -EINVAL;
            }
            enabled = true;
            SET(int32_t, pReplyData, 0);
            return 0;
        }
        case EFFECT_CMD_DISABLE: {
            if (replySize != sizeof(int32_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_DISABLE called with invalid replySize = %d, pReplyData = %p, expected replySize = %zu", replySize, pReplyData, sizeof(int32_t));
                return -EINVAL;
            }
            enabled = false;
            SET(int32_t, pReplyData, 0);
            return 0;
        }
        case EFFECT_CMD_SET_PARAM: {
            if (cmdSize < sizeof(effect_param_t) || pCmdData == nullptr || replySize != sizeof(int32_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_SET_PARAM called with invalid cmdSize = %d, pCmdData = %p, replySize = %d, pReplyData = %p, expected cmdSize >= %zu, expected replySize >= %zu", cmdSize, pCmdData, replySize, pReplyData, sizeof(effect_param_t), sizeof(int32_t));
                return -EINVAL;
            }
            return handleSetParam((effect_param_t *) pCmdData, pReplyData);
        }
        case EFFECT_CMD_GET_PARAM: {
            if (cmdSize < sizeof(effect_param_t) || pCmdData == nullptr || replySize < sizeof(effect_param_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_GET_PARAM called with invalid cmdSize = %d, pCmdData = %p, replySize = %d, pReplyData = %p, expected cmdSize >= %zu, expected replySize >= %zu", cmdSize, pCmdData, replySize, pReplyData, sizeof(effect_param_t), sizeof(effect_param_t));
                return -EINVAL;
            }
            return handleGetParam((effect_param_t *) pCmdData, (effect_param_t *) pReplyData, pReplySize);
        }
        case EFFECT_CMD_GET_CONFIG: {
            if (replySize != sizeof(effect_config_t) || pReplyData == nullptr) {
                VIPER_LOGE("EFFECT_CMD_GET_CONFIG called with invalid replySize = %d, pReplyData = %p, expected replySize = %zu", replySize, pReplyData, sizeof(effect_config_t));
                return -EINVAL;
            }
            *(effect_config_t *) pReplyData = config;
            return 0;
        }
        default: {
            VIPER_LOGE("handleCommand called with unknown command: %d", cmdCode);
            return -EINVAL;
        }
    }
}

template <typename T>
void pcmToFloat(float* dst, const T* src, size_t frameCount) {
    constexpr float max_val = static_cast<float>(std::numeric_limits<T>::max());
    for (size_t i = 0; i < frameCount * 2; i++) {
        dst[i] = static_cast<float>(src[i]) / max_val;
    }
}

template <typename T>
static const T& clamp(const T& v, const T& lo, const T& hi) {
    return std::min(std::max(v, lo), hi);
}

static void floatToFloat(float *dst, const float *src, size_t frameCount, bool accumulate) {
    if (accumulate) {
        for (size_t i = 0; i < frameCount * 2; i++) {
            dst[i] = clamp(dst[i] + src[i], -1.0f, 1.0f);
        }
    } else {
        memcpy(dst, src, frameCount * 2 * sizeof(float));
    }
}

template <typename T, typename U>
void floatToPcm(T *dst, const float *src, size_t frameCount, bool accumulate) {
    constexpr T max_val = std::numeric_limits<T>::max();
    constexpr T min_val = std::numeric_limits<T>::min();

    for (size_t i = 0; i < frameCount * 2; i++) {
        T pcm = static_cast<T>(src[i] * static_cast<float>(max_val));
        if (accumulate) {
            U temp = static_cast<U>(dst[i]) + pcm;
            dst[i] = static_cast<T>(clamp(temp, static_cast<U>(min_val), static_cast<U>(max_val)));
        } else {
            dst[i] = pcm;
        }
    }
}

static audio_buffer_t *getBuffer(buffer_config_s *config, audio_buffer_t *buffer) {
    if (buffer != nullptr) return buffer;
    if (config->mask & EFFECT_CONFIG_BUFFER) return &config->buffer;
    // EFFECT_CONFIG_PROVIDER not implemented, it's not used by any known effect
    return nullptr;
}

int32_t ViperContext::process(audio_buffer_t *inBuffer, audio_buffer_t *outBuffer) {
    if (disableReason != DisableReason::NONE) {
        return -EINVAL;
    }

    if (!enabled) {
        return -ENODATA;
    }
    
    inBuffer = getBuffer(&config.inputCfg, inBuffer);
    outBuffer = getBuffer(&config.outputCfg, outBuffer);
    if (inBuffer == nullptr || outBuffer == nullptr ||
        inBuffer->raw == nullptr || outBuffer->raw == nullptr ||
        inBuffer->frameCount != outBuffer->frameCount ||
        inBuffer->frameCount == 0) {
        return -EINVAL;
    }

    size_t frameCount = inBuffer->frameCount;
    if (frameCount > bufferFrameCount) {
        // This should never happen, but just in case
        buffer.resize(frameCount * 2);
        bufferFrameCount = frameCount;
    }

    switch (config.inputCfg.format) {
        case AUDIO_FORMAT_PCM_16_BIT:
            pcmToFloat<int16_t>(buffer.data(), inBuffer->s16, frameCount);
            break;
        case AUDIO_FORMAT_PCM_32_BIT:
            pcmToFloat<int32_t>(buffer.data(), inBuffer->s32, frameCount);
            break;
        case AUDIO_FORMAT_PCM_FLOAT:
            floatToFloat(buffer.data(), inBuffer->f32, frameCount, false);
            break;
        default:
            return -EINVAL;
    }

    viper.process(buffer, frameCount);

    const bool accumulate = config.outputCfg.accessMode == EFFECT_BUFFER_ACCESS_ACCUMULATE;
    switch (config.outputCfg.format) {
        case AUDIO_FORMAT_PCM_16_BIT:
            floatToPcm<int16_t, int32_t>(outBuffer->s16, buffer.data(), frameCount, accumulate);
            break;
        case AUDIO_FORMAT_PCM_32_BIT:
            floatToPcm<int32_t, int64_t>(outBuffer->s32, buffer.data(), frameCount, accumulate);
            break;
        case AUDIO_FORMAT_PCM_FLOAT:
            floatToFloat(outBuffer->f32, buffer.data(), frameCount, accumulate);
            break;
        default:
            return -EINVAL;
    }

    return 0;
}

void ViperContext::setDisableReason(DisableReason reason) {
    this->disableReason = reason;
}
