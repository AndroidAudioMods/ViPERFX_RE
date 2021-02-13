//
// Created by mart on 2/12/21.
//

#include "ColorfulMusic.h"


// ColorfulMusic::ColorfulMusic()

ColorfulMusic::ColorfulMusic() {
    DepthSurround *this_00;
    float fVar1;

    this_00 = (DepthSurround *)&this->field_0x18;
    Stereo3DSurround::Stereo3DSurround((Stereo3DSurround *)this);
    fVar1 = (float)DepthSurround::DepthSurround(this_00);
    *(undefined4 *)&this->field_0x64 = 0xac44;
    *(undefined *)&this->field_0x68 = 0;
    Stereo3DSurround::SetStereoWiden((Stereo3DSurround *)this,fVar1);
    DepthSurround::SetSamplingRate((uint)this_00);
    DepthSurround::SetStrength(this_00,0);
    return this;
}



// ColorfulMusic::SetSamplingRate(unsigned int)

void ColorfulMusic::SetSamplingRate(uint param_1) {
    if (*(uint *)&this->field_0x64 == param_1) {
        return;
    }
    *(uint *)&this->field_0x64 = param_1;
    DepthSurround::SetSamplingRate(&this->field_0x18);
    return;
}



float ColorfulMusic::setStereoWidenValue(float param_1) {
    // TODO: S3DS call
}



float ColorfulMusic::setMidImageValue(float param_1) {
    // TODO: S3DS call
}



// ColorfulMusic::SetDepthValue(short)

void ColorfulMusic::SetDepthValue(short param_1) {
    DepthSurround::SetStrength((DepthSurround *)&this->field_0x18,param_1);
    return;
}



// ColorfulMusic::Reset()

void ColorfulMusic::Reset() {
    DepthSurround::SetSamplingRate(&this->field_0x18);
    return;
}



// ColorfulMusic::SetEnable(bool)

undefined4 ColorfulMusic::SetEnable(bool param_1) {
    char cVar1;

    cVar1 = *(char *)&this->field_0x68;
    if (cVar1 == '\0') {
        if (param_1 == false) {
            return 0;
        }
        Reset(this);
        cVar1 = *(char *)&this->field_0x68;
    }
    if (param_1 == (bool)cVar1) {
        return 0;
    }
    *(bool *)&this->field_0x68 = param_1;
    return 1;
}



// ColorfulMusic::Process(int*, int)

void ColorfulMusic::Process(int *param_1,int param_2) {
    if (*(char *)&this->field_0x68 == '\0') {
        return;
    }
    DepthSurround::Process((DepthSurround *)&this->field_0x18,param_1,param_2);
    Stereo3DSurround::Process((Stereo3DSurround *)this,param_1,param_2);
    return;
}

