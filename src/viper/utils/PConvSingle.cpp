#include <cstdlib>
#include <cstring>
#include "PConvSingle.h"

PConvSingle::PConvSingle() {
    this->instanceUsable = false;
    this->segmentCount = 0;
    this->segmentSize = 0;
//    this->data = nullptr;
}

PConvSingle::~PConvSingle() {
    ReleaseResources();
}

void PConvSingle::Convolve(float *buffer) {
    ConvSegment(buffer, false, 0);
}

void PConvSingle::ConvolveInterleaved(float *buffer, int channel) {
    ConvSegment(buffer, true, channel);
}

void PConvSingle::ConvSegment(float *buffer, bool interleaved, int channel) {
    // TODO
}

int PConvSingle::GetFFTSize() {
    return this->segmentSize * 2;
}

int PConvSingle::GetSegmentCount() {
    return this->segmentCount;
}

int PConvSingle::GetSegmentSize() {
    return this->segmentSize;
}

bool PConvSingle::InstanceUsable() {
    return this->instanceUsable;
}

int PConvSingle::LoadKernel(float *buf, int param_2, int segmentSize) {
    if (buf != nullptr && param_2 > 0 && segmentSize > 0 && segmentSize % 2 == 0) {
        this->instanceUsable = false;
        ReleaseResources();
        this->data = new PConvData(); //(PConvData *) malloc(0x140);  // TODO: Sizeof
        this->segmentSize = segmentSize;
        int n = ProcessKernel(buf, param_2, 1);
        if (n != 0) {
            this->instanceUsable = true;
            return n;
        }
        ReleaseResources();
    }
    return 0;
}

int PConvSingle::LoadKernel(const float *param_2,float param_3,int param_4,int param_5) {
//    if (buf != nullptr && param_5 > 0 && segmentSize > 0 && segmentSize % 2 == 0) {
//        this->enable = false;
//        ReleaseResources();
////        this->data = new PConvData(); //(PConvData *) malloc(0x140);  // TODO: Sizeof
//        this->segmentSize = segmentSize;
//        int n = ProcessKernel(1, param_2, param_4, param_5);
//        if (n != 0) {
//            this->enable = true;
//            return n;
//        }
//        ReleaseResources();
//    }
    return 0;
}

int PConvSingle::ProcessKernel(float *param_1, int param_2, int param_3) {
    // TODO
    return 0;
}

int PConvSingle::ProcessKernel(int param_2, float *param_3, int param_4, int param_5) {
    // TODO
    return 0;
}

void PConvSingle::ReleaseResources() {
    if (this->data != nullptr) {
        // TODO
    }
    this->instanceUsable = false;
    this->segmentCount = 0;
    this->segmentSize = 0;
}

void PConvSingle::Reset() {
    if (!this->instanceUsable) return;
    // TODO
}

void PConvSingle::UnloadKernel() {
    this->instanceUsable = false;
    ReleaseResources();
}
