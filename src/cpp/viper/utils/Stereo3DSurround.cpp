#include "Stereo3DSurround.h"

Stereo3DSurround::Stereo3DSurround() {
    this->midImage = 1.0f;
    this->stereoWiden = 0.0f;
    this->unknown1 = 1.0f;
    this->unknown2 = 0.5f;
    this->coeffLeft = 0.5f;
    this->coeffRight = 0.5f;
}

void Stereo3DSurround::Process(float *samples, uint32_t size) {

}

void Stereo3DSurround::SetMiddleImage(float middleImage) {

}

void Stereo3DSurround::SetStereoWiden(float stereoWiden) {

}
