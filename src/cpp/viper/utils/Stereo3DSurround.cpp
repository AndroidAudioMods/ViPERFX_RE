#include "Stereo3DSurround.h"

Stereo3DSurround::Stereo3DSurround() {
    this->middleImage = 1.0;
    this->stereoWiden = 0.0;
    this->unknown1 = 1.0;
    this->unknown2 = 0.5;
    this->coeffLeft = 0.5;
    this->coeffRight = 0.5;
}

void Stereo3DSurround::Process(float *samples, uint32_t size) {
    if (size >= 2) {

    }
}

inline void Stereo3DSurround::ConfigureVariables() {
    this->unknown1 = this->stereoWiden + 1.0f;

    float x = this->unknown1 + 1.0f;
    float y;
    if (x < 2.0) {
        y = 0.5;
    } else {
        y = 1.0f / x;
    }

    this->unknown2 = y;
    this->coeffLeft = this->middleImage * y;
    this->coeffRight = this->unknown1 * y;
}

void Stereo3DSurround::SetMiddleImage(float middleImage) {
    this->middleImage = middleImage;
    this->ConfigureVariables();
}

void Stereo3DSurround::SetStereoWiden(float stereoWiden) {
    this->stereoWiden = stereoWiden;
    this->ConfigureVariables();
}
