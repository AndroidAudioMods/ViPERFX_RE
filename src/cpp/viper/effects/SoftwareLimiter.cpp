#include <cstring>
#include "SoftwareLimiter.h"

SoftwareLimiter::SoftwareLimiter() {
    this->ready = false;
    this->unknown4 = 0;
    this->unknown2 = 1.0;
    this->gate = 0.999999;
    this->unknown3 = 1.0;
    this->unknown1 = 1.0;
    this->ResetLimiter();
}

void SoftwareLimiter::Process(float *samples, uint32_t size) {

}

void SoftwareLimiter::ResetLimiter() {
    memset(this->arr256, 0, 256);
    memset(this->arr512, 0, 512);
    this->ready = false;
    this->unknown4 = 0;
    this->unknown2 = 1.0;
    this->unknown3 = 1.0;
}

void SoftwareLimiter::SetGate(float gate) {
    this->gate = gate;
}
