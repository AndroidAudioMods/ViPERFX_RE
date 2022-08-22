//
// Created by mart on 9/12/21.
//

#include <cstdlib>
#include <cstring>
#include "PConvSingle_F32.h"

PConvSingle_F32::PConvSingle_F32() {
    this->enabled = false;
    this->segments = 0;
    this->segmentSize = 0;
    this->data = nullptr;
}

PConvSingle_F32::~PConvSingle_F32() {
    ReleaseResources();
}

void PConvSingle_F32::Reset() {
    // TODO
}

int PConvSingle_F32::GetFFTSize() {
    return this->segmentSize * 2;
}

int PConvSingle_F32::GetSegmentCount() {
    return this->segments;
}

int PConvSingle_F32::GetSegmentSize() {
    return this->segmentSize;
}

bool PConvSingle_F32::InstanceUsable() {
    return this->enabled;
}

void PConvSingle_F32::Convolve(float *buffer) {
    ConvSegment(buffer, false, 0);
}

void PConvSingle_F32::ConvolveInterleaved(float *buffer, int channel) {
    ConvSegment(buffer, true, channel);
}

void PConvSingle_F32::ConvSegment(float *buffer, bool interleaved, int channel) {
    // TODO
}

int PConvSingle_F32::LoadKernel(float *buf, int param_2, int segmentSize) {
    if (buf == nullptr) {
        return 0;
    }
    if (param_2 > 0 && segmentSize > 0 && segmentSize % 2 == 0) {
        this->enabled = false;
        ReleaseResources();
        this->data = (PConvData *) malloc(0x140);  // TODO: Sizeof
        memset(this->data, 0, 0x140);  // Ditto
        this->segmentSize = segmentSize;
        int n = ProcessKernel(buf, param_2, 1);
        if (n != 0) {
            this->enabled = true;
            return n;
        }
        ReleaseResources();
    }
    return 0;
}

int PConvSingle_F32::LoadKernel(float *buf, float *param_2, int segmentSize, int param_4, int param_5) {
    if (buf == nullptr) {
        return 0;
    }
    if (param_5 > 0 && segmentSize > 0 && segmentSize % 2 == 0) {
        this->enabled = false;
        ReleaseResources();
        this->data = (PConvData *) malloc(0x140);  // TODO: Sizeof
        memset(this->data, 0, 0x140);  // Ditto
        this->segmentSize = segmentSize;
        int n = ProcessKernel(1, param_2, param_4, param_5);
        if (n != 0) {
            this->enabled = true;
            return n;
        }
        ReleaseResources();
    }
    return 0;
}

int PConvSingle_F32::ProcessKernel(float *param_1, int param_2, int param_3) {
    // TODO
    return 0;
}

int PConvSingle_F32::ProcessKernel(int param_2, float *param_3, int param_4, int param_5) {
    // TODO
    return 0;
}

void PConvSingle_F32::ReleaseResources() {
    // TODO
}

void PConvSingle_F32::UnloadKernel() {
    this->enabled = false;
    ReleaseResources();
}
