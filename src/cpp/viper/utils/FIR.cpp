#include <cstring>
#include "FIR.h"

FIR::FIR() {
    this->offsetBlock = nullptr;
    this->coeffs = nullptr;
    this->block = nullptr;
    this->coeffsSize = 0;
    this->blockLength = 0;
    this->hasCoefficients = false;
}

FIR::~FIR() {
    delete[] this->offsetBlock;
    delete[] this->coeffs;
    delete[] this->block;
}

void FIR::FilterSamples(float *samples, uint32_t size) {
    this->FilterSamplesInterleaved(samples, size, 1);
}

void FIR::FilterSamplesInterleaved(float *samples, uint32_t size, uint32_t channels) {
    if (!this->hasCoefficients || size == 0) return;

    for (uint32_t i = 0; i < size; i++) {
        this->block[i] = samples[i * channels];
    }

    if (this->blockLength > size) {
        memset(this->block + size, 0, (this->blockLength - size) * sizeof(float));
    }

    memcpy(this->offsetBlock + this->coeffsSize - 1, this->block, this->blockLength * sizeof(float));

    for (uint32_t i = 0; i < this->blockLength; i++) {
        float sample = 0.0f;

        for (uint32_t j = 0; j < this->coeffsSize; j++) {
            sample += this->coeffs[j] * this->offsetBlock[this->coeffsSize + i - 1 - j];
        }

        if (i < size) {
            samples[channels * i] = sample;
        }
    }

    if (this->coeffsSize > 1) {
        memcpy(this->offsetBlock + this->coeffsSize - 2, this->block + this->blockLength - 1, this->blockLength - (this->coeffsSize - 1) * sizeof(float));
    }
}

uint32_t FIR::GetBlockLength() {
    return this->blockLength;
}

int FIR::LoadCoefficients(const float *coeffs, uint32_t coeffsSize, uint32_t blockLength) {
    if (coeffs == nullptr || coeffsSize == 0 || blockLength == 0) return 0;

    delete[] this->offsetBlock;
    delete[] this->coeffs;
    delete[] this->block;

    this->offsetBlock = new float[coeffsSize + blockLength + 1];
    this->coeffs = new float[coeffsSize];
    this->block = new float[blockLength];

    this->coeffsSize = coeffsSize;
    this->blockLength = blockLength;

    memcpy(this->coeffs, coeffs, coeffsSize * sizeof(float));

    this->Reset();
    this->hasCoefficients = true;

    return 1;
}

void FIR::Reset() {
    if (this->offsetBlock != nullptr && this->coeffsSize + this->blockLength > 0) {
        memset(this->offsetBlock, 0, (this->coeffsSize + this->blockLength) * sizeof(float));
    }
}
