#include "Convolver.h"

Convolver::Convolver() {

}

Convolver::~Convolver() {

}

void Convolver::CommitKernelBuffer(uint32_t param_1, uint32_t param_2, uint32_t kernelId) {

}

bool Convolver::GetEnabled() {
    return false;
}

uint32_t Convolver::GetKernelID() {
    return 0;
}

void Convolver::PrepareKernelBuffer(uint32_t param_1, uint32_t param_2, int32_t kernelId) {

}

uint32_t Convolver::Process(float *source, float *dest, uint32_t frameSize) {
    return frameSize;
}

void Convolver::Reset() {

}

void Convolver::SetCrossChannel(float param_1) {

}

void Convolver::SetEnable(bool enabled) {

}

void Convolver::SetKernel(float *param_1, uint32_t param_2) {

}

void Convolver::SetKernel(const char *param_1) {

}

void Convolver::SetKernelBuffer(uint32_t param_1, float *param_2, uint32_t param_3) {

}

void Convolver::SetKernelStereo(float *param_1, float *param_2, uint32_t param_3) {

}

void Convolver::SetSamplingRate(uint32_t param_1) {

}


