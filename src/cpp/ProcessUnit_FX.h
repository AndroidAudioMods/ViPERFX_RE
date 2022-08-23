//
// Created by mart on 7/25/21.
//
#pragma once

#include "Effect.h"
#include "viper.h"
#include "utils/WaveBuffer_I32.h"
#include "effects/SpectrumExtend.h"
#include "effects/Reverberation.h"
#include "effects/DynamicSystem.h"
#include "effects/ViPERClarity.h"
#include "effects/SpeakerCorrection.h"
#include "effects/AnalogX.h"
#include "effects/TubeSimulator.h"
#include "effects/Cure.h"
#include "effects/DiffSurround.h"
#include "effects/VHE.h"
#include "effects/AdaptiveBuffer_F32.h"
#include "effects/Convolver.h"
#include "effects/ViPERDDC.h"
#include "effects/IIRFilter.h"
#include "effects/ColorfulMusic.h"
#include "effects/FETCompressor.h"
#include "effects/ViPERBass.h"
#include "effects/SoftwareLimiter.h"
#include "effects/PlaybackGain.h"

class ProcessUnit_FX : public Effect {
public:
    ProcessUnit_FX();

    ~ProcessUnit_FX();

    int32_t command(uint32_t cmdCode, uint32_t cmdSize, void *pCmdData, uint32_t *replySize, void *pReplyData) override;

    void processBuffer(float *buffer, int frameSize);

    // TODO: Parameter types/names
    void DispatchCommand(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);

    void ResetAllEffects();

    bool init_ok, enabled, force_enabled, fetcomp_enabled;
    FxMode mode;

    // Effects
    AdaptiveBuffer_F32 *adaptiveBuffer;
    WaveBuffer_I32 *waveBuffer;
    Convolver *convolver;
    VHE *vhe;
    ViPERDDC *viperDdc;
    SpectrumExtend *spectrumExtend;
    IIRFilter *iirFilter;
    ColorfulMusic *colorfulMusic;
    Reverberation *reverberation;
    PlaybackGain *playbackGain;
    FETCompressor *fetCompressor;
    DynamicSystem *dynamicSystem;
    ViPERBass *viperBass;
    ViPERClarity *viperClarity;
    DiffSurround *diffSurround;
    Cure *cure;
    TubeSimulator *tubeSimulator;
    AnalogX *analogX;
    SpeakerCorrection *speakerCorrection;
    SoftwareLimiter *softwareLimiters[2];

    int unk[3];
};
