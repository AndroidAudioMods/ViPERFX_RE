#pragma once

#include <cstdint>

class Stereo3DSurround {
public:
    Stereo3DSurround();

    void Process(float *samples, uint32_t size);
    void SetMiddleImage(float middleImage);
    void SetStereoWiden(float stereoWiden);

private:
    void ConfigureVariables();

    float stereoWiden;
    float middleImage;
    float unknown1;
    float unknown2;
    float coeffLeft;
    float coeffRight;
};


