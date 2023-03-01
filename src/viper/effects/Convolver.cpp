#include "Convolver.h"
#include "../constants.h"
#include <cstring>
#include <cstddef>

// Iscle: Right now, this is a mixture between the 2.5.0.4 driver and 2.3.4.0. It'll be corrected later.

Convolver::Convolver() {
    this->enable = false;
    this->samplingRate = VIPER_DEFAULT_SAMPLING_RATE;
    this->waveBufferL = new WaveBuffer(2, 0x1000);
    this->waveBufferR = new WaveBuffer(2, 0x1000);
    memset(this->kernelFilePath, 0, sizeof(this->kernelFilePath));
    this->kernelId = 0;
    this->unknown1 = nullptr;
    this->unknown2 = 0;
    this->crossChannel = 0.0;
    this->unknown3 = 0;
    this->unknown4 = 0;
    this->unknown5 = 0;
}

Convolver::~Convolver() {
    delete this->waveBufferL;
    delete this->waveBufferR;
    delete[] this->unknown1;
}

void Convolver::CommitKernelBuffer(uint32_t param_1, uint32_t param_2, uint32_t kernelId) {
    if (this->unknown1 == nullptr) {
        this->unknown2 = 0;
        this->unknown3 = 0;
        this->unknown4 = 0;
        return;
    }

    if (this->unknown2 != param_1) {
        delete[] this->unknown1;
        this->unknown1 = nullptr;
        this->unknown2 = 0;
        this->unknown3 = 0;
        this->unknown4 = 0;
        return;
    }

    if (this->unknown3 == 0) {
        delete[] this->unknown1;
        this->unknown1 = nullptr;
        this->unknown2 = 0;
        this->unknown3 = 0;
        this->unknown4 = 0;
        return;
    }


}

bool Convolver::GetEnabled() {
    return this->enable;
}

uint32_t Convolver::GetKernelID() {
    return this->kernelId;
}

void Convolver::PrepareKernelBuffer(uint32_t param_1, uint32_t param_2, int32_t param_3) {
    if (param_3 == 0) {
        if (param_2 - 1 < 2) {
            delete[] this->unknown1;
            this->unknown1 = nullptr;
            this->unknown2 = param_1;
            this->unknown3 = 0;
            this->unknown4 = param_2;
        }
    } else {
        delete[] this->unknown1;
        this->unknown1 = nullptr;
        this->unknown2 = 0;
        this->unknown3 = 0;
        this->unknown4 = 0;
        this->unknown5 = 0;
        this->kernelCh1.Reset();
        this->kernelCh2.Reset();
        this->kernelCh3.Reset();
        this->kernelCh4.Reset();
        this->kernelCh1.UnloadKernel();
        this->kernelCh2.UnloadKernel();
        this->kernelCh3.UnloadKernel();
        this->kernelCh4.UnloadKernel();
        memset(this->kernelFilePath, 0, sizeof(this->kernelFilePath));
        this->kernelId = 0;
    }
}

uint32_t Convolver::Process(float *source, float *dest, uint32_t frameSize) {
    return frameSize;
}

void Convolver::Reset() {
    this->waveBufferL->Reset();
    this->waveBufferR->Reset();
    this->kernelCh1.Reset();
    this->kernelCh2.Reset();
    this->kernelCh3.Reset();
    this->kernelCh4.Reset();
}

void Convolver::SetCrossChannel(float crossChannel) {
    if (crossChannel <= 0.0) {
        this->isValidCrossChannel = false;
        return;
    }

    if (crossChannel > 1.0) {
        crossChannel = 1.0;
    }

    this->crossChannel = crossChannel;
    this->isValidCrossChannel = true;
}

void Convolver::SetEnable(bool enabled) {
    if (this->enable != enabled) {
        if (enabled) {
            Reset();
        }
        this->enable = enabled;
    }
}

void Convolver::SetKernel(float *buf, uint32_t len) {
    if (len < 16) return;

    this->kernelCh1.Reset();
    this->kernelCh2.Reset();
    this->kernelCh3.Reset();
    this->kernelCh4.Reset();

    int ret1 = this->kernelCh1.LoadKernel(buf, len, 0x1000);
    int ret2 = this->kernelCh2.LoadKernel(buf, len, 0x1000);
    int ret3 = this->kernelCh3.LoadKernel(buf, len, 0x1000);
    int ret4 = this->kernelCh4.LoadKernel(buf, len, 0x1000);
    if (!ret1 || !ret2 || !ret3 || !ret4) {
        this->kernelCh1.UnloadKernel();
        this->kernelCh2.UnloadKernel();
        this->kernelCh3.UnloadKernel();
        this->kernelCh4.UnloadKernel();
    }

    this->kernelId = 0;
    this->unknown5 = 0;
    Reset();
}

void Convolver::SetKernelBuffer(uint32_t param_1, float *buf, uint32_t len) {
    if (buf == nullptr || len == 0) return;
    if (this->unknown2 != param_1) return;

    float *newArray = new float[(this->unknown3 + len) * 4];
    if (this->unknown1 != nullptr) {
        memcpy(newArray, this->unknown1, this->unknown3 * 4);
        delete[] this->unknown1;
        this->unknown1 = newArray;
    }
    memcpy(this->unknown1 + this->unknown3 * 4, buf, len * 4);
    this->unknown3 += len;
}

void Convolver::SetKernelStereo(float *param_1, float *param_2, uint32_t param_3) {
    if (param_3 < 16) return;

    this->kernelCh1.Reset();
    this->kernelCh2.Reset();
    this->kernelCh3.Reset();
    this->kernelCh4.Reset();

    int ret1 = this->kernelCh1.LoadKernel(param_1, param_3, 0x1000);
    int ret2 = this->kernelCh2.LoadKernel(param_2, param_3, 0x1000);
    int ret3 = this->kernelCh3.LoadKernel(param_1, param_3, 0x1000);
    int ret4 = this->kernelCh4.LoadKernel(param_2, param_3, 0x1000);
    if (!ret1 || !ret2 || !ret3 || !ret4) {
        this->kernelCh1.UnloadKernel();
        this->kernelCh2.UnloadKernel();
        this->kernelCh3.UnloadKernel();
        this->kernelCh4.UnloadKernel();
    }

    this->kernelId = 0;
    this->unknown5 = 0;
    Reset();
}

void Convolver::SetSamplingRate(uint32_t samplingRate) {
    if (this->samplingRate != samplingRate) {
        this->samplingRate = samplingRate;
    }
}


