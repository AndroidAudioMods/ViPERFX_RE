#pragma once

#include <cstdint>

class FETCompressor {
public:
    enum Parameter {
        ENABLE = 0,
        THRESHOLD,
        RATIO,
        KNEE,
        AUTO_KNEE,
        GAIN,
        AUTO_GAIN,
        ATTACK,
        AUTO_ATTACK,
        RELEASE,
        AUTO_RELEASE,
        KNEE_MULTI,
        MAX_ATTACK,
        MAX_RELEASE,
        CREST,
        ADAPT,
        NO_CLIP
    };

    FETCompressor();

    float GetMeter(int param_1);
    float GetParameter(FETCompressor::Parameter parameter);
    float GetParameterDefault(FETCompressor::Parameter parameter);
    void Process(float *samples, uint32_t size);
    double ProcessSidechain(double in);
    void Reset();
    void SetParameter(FETCompressor::Parameter parameter, float value);
    void SetSamplingRate(uint32_t samplingRate);

private:
    uint32_t samplingRate;
    float parameters[17];
    float unk22;
    bool enable;
    bool autoKnee;
    bool autoGain;
    bool autoAttack;
    bool autoRelease;
    float unk27;
    float unk28;
    float unk29;
    float unk23;
    float threshold;
    float knee;
    float unk24;
    float gain;
    float ratio;
    float unk25;
    float unk26;
    float attack1;
    float attack2;
    float release1;
    float release2;
    float kneeMulti;
    float maxAttack;
    float maxRelease;
    float crest1;
    float crest2;
    float adapt1;
    float adapt2;
    float noClip;
};


