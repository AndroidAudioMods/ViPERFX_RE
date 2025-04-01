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
    if (!interleaved) {

    } else {
        // TODO
    }
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

int PConvSingle::LoadKernel(const float *kernel, int kernelSize, int segmentSize) {
    if (kernel != nullptr && kernelSize >= 2 && segmentSize >= 2 && (segmentSize & (segmentSize - 1)) == 0) {
        this->instanceUsable = false;
        ReleaseResources();
        this->data = new PConvData(); //(PConvData *) malloc(0x140);  // TODO: Sizeof
        this->segmentSize = segmentSize;
        int n = ProcessKernel(kernel, kernelSize, 1);
        if (n != 0) {
            this->instanceUsable = true;
            return n;
        }
        ReleaseResources();
    }
    return 0;
}

int PConvSingle::LoadKernel(const float *kernel, float param_3, int kernelSize, int segmentSize) {
    if (kernel != nullptr && kernelSize >= 2 && segmentSize >= 2 && (segmentSize & (segmentSize - 1)) == 0) {
        this->instanceUsable = false;
        ReleaseResources();
        this->data = new PConvData(); //(PConvData *) malloc(0x140);  // TODO: Sizeof
        this->segmentSize = segmentSize;
        int n = ProcessKernel(kernel, param_3, kernelSize, 1);
        if (n != 0) {
            this->instanceUsable = true;
            return n;
        }
        ReleaseResources();
    }
    return 0;
}

int PConvSingle::ProcessKernel(const float *kernel, int kernelSize, int param_4) {
    // TODO
    return 0;
}

int PConvSingle::ProcessKernel(const float *kernel, float param_3, int kernelSize, int param_5) {
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
