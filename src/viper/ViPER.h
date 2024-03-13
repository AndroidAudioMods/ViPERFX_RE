#pragma once

#include "utils/WaveBuffer.h"
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
#include "utils/AdaptiveBuffer.h"
#include "effects/Convolver.h"
#include "effects/ViPERDDC.h"
#include "effects/IIRFilter.h"
#include "effects/ColorfulMusic.h"
#include "effects/FETCompressor.h"
#include "effects/ViPERBass.h"
#include "effects/SoftwareLimiter.h"
#include "effects/PlaybackGain.h"
#include "../ViPER4Android.h"
#include <array>

class ViPER {
public:
    ViPER();

    void process(std::vector<float>& buffer, uint32_t size);
    // TODO: Parameter types/names
    void DispatchCommand(int param, int val1, int val2, int val3, int val4, uint32_t arrSize, signed char *arr);
    void resetAllEffects();

//private:
    uint64_t frameCount;
    uint32_t samplingRate;

    // Effects
    AdaptiveBuffer adaptiveBuffer;
    WaveBuffer waveBuffer;
    Convolver convolver;
    VHE vhe;
    ViPERDDC viperDdc;
    SpectrumExtend spectrumExtend;
    IIRFilter iirFilter;
    ColorfulMusic colorfulMusic;
    Reverberation reverberation;
    PlaybackGain playbackGain;
    FETCompressor fetCompressor;
    DynamicSystem dynamicSystem;
    ViPERBass viperBass;
    ViPERClarity viperClarity;
    DiffSurround diffSurround;
    Cure cure;
    TubeSimulator tubeSimulator;
    AnalogX analogX;
    SpeakerCorrection speakerCorrection;
    std::array<SoftwareLimiter, 2> softwareLimiters;

    float frameScale;
    float leftPan;
    float rightPan;
};
