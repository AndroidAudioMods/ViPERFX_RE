#include <cstring>
#include "FIR.h"

FIR::FIR() {
    this->coeffsSize = 0;
    this->blockLength = 0;
    this->hasCoefficients = false;
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
        memset(this->block.data() + size, 0, (this->blockLength - size) * sizeof(float));
    }

    memcpy(this->offsetBlock.data() + this->coeffsSize - 1, this->block.data(), this->blockLength * sizeof(float));

    for (uint32_t i = 0; i < this->blockLength; i++) {
        float sample = 0.0f;

        for (uint32_t j = 0; j < this->coeffsSize; j++) {
            sample += this->coeffs[j] * this->offsetBlock[this->coeffsSize + i - j - 1];
        }

        if (i < size) {
            samples[i * channels] = sample;
        }
    }

    if (this->coeffsSize > 1) {
        float *pfVar1 = this->block.data();
        float *pfVar6 = pfVar1 + this->blockLength;
        float *pfVar2 = this->offsetBlock.data() + this->coeffsSize;
        do {
            pfVar6 = pfVar6 - 1;
            pfVar2[-2] = *pfVar6;
            pfVar2 = pfVar2 - 1;
        } while (pfVar6 != pfVar1 + this->blockLength + 1 - this->coeffsSize);
    }
}

uint32_t FIR::GetBlockLength() {
    return this->blockLength;
}

int FIR::LoadCoefficients(const float *coeffs, uint32_t coeffsSize, uint32_t blockLength) {
    if (coeffs == nullptr || coeffsSize == 0 || blockLength == 0) return 0;

    this->offsetBlock = std::vector<float>(coeffsSize + blockLength + 1);
    this->coeffs = std::vector<float>(coeffsSize);
    this->block = std::vector<float>(blockLength);

    this->coeffsSize = coeffsSize;
    this->blockLength = blockLength;

    memcpy(this->coeffs.data(), coeffs, coeffsSize * sizeof(float));

    Reset();
    this->hasCoefficients = true;

    return 1;
}

void FIR::Reset() {
    if (this->coeffsSize + this->blockLength > 0) {
        memset(this->offsetBlock.data(), 0, (this->coeffsSize + this->blockLength + 1) * sizeof(float));
    }
}
