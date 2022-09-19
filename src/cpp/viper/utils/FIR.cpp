#include "FIR.h"

FIR::FIR() {

}

FIR::~FIR() {
    delete this->offsetBlock;
    delete this->coeffs;
    delete this->block;
}

void FIR::FilterSamples(float *samples, uint32_t size) {
    this->FilterSamplesInterleaved(samples, size, 1);
}

void FIR::FilterSamplesInterleaved(float *samples, uint32_t size, uint32_t channels) {

}

int FIR::GetBlockLength() {
    return this->blockLength;
}

int FIR::LoadCoefficients(const float *coeffs, uint32_t coeffsize, int blockLength) {
    return 0;
}

void FIR::Reset() {
    if (this->offsetBlock != nullptr && this->coeffsize + this->blockLength > -1) {
        for (int i = 0; i < this->coeffsize + this->blockLength; i++) {
            this->offsetBlock[i] = 0;
        }
    }
}
