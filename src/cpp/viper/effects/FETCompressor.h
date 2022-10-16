#pragma once

#include <cstdint>

class FETCompressor {
public:
    FETCompressor();

    float GetMeter(int param_1);
    float GetParameter(uint32_t index);
    float GetParameterDefault(uint32_t index);
    void Process(float *samples, uint32_t size);
    double ProcessSidechain(double in);
    void Reset();
    void SetParameter(uint32_t index, float value);
    void SetSamplingRate(uint32_t samplingRate);

private:
    uint32_t samplingRate;
    float parameters[17];
    float unk22;
    bool unk1;
    bool unk5;
    bool unk7;
    bool unk10;
    bool unk13;
    float unk27;
    float unk28;
    float unk29;
    float unk23;
    float unk2;
    float unk4;
    float unk24;
    float unk6;
    float unk3;
    float unk25;
    float unk26;
    float unk8;
    float unk9;
    float unk11;
    float unk12;
    float unk14;
    float unk15;
    float unk16;
    float unk17;
    float unk18;
    float unk19;
    float unk20;
    float unk21;
};


