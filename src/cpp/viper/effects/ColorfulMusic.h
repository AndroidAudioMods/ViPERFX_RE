#pragma once

#include <cstdint>
#include "../utils/Stereo3DSurround.h"
#include "../utils/DepthSurround.h"

class ColorfulMusic {
public:
    ColorfulMusic();
    ~ColorfulMusic();

    void Process(float *samples, uint32_t size);
    void Reset();
    void SetDepthValue(short depthValue);
    void SetEnable(bool enable);
    void SetMidImageValue(float midImageValue);
    void SetSamplingRate(uint32_t samplingRate);
    void SetWidenValue(float widenValue);

private:
    Stereo3DSurround *stereo3DSurround;
    DepthSurround *depthSurround;
    uint32_t samplingRate;
    bool enabled;

};


