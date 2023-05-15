#include <cstring>
#include <cmath>
#include "SoftwareLimiter.h"

#ifndef uint
#define uint unsigned int
#endif

SoftwareLimiter::SoftwareLimiter() {
    this->ready = false;
    this->unknown4 = 0;
    this->unknown2 = 1.0;
    this->gate = 0.999999;
    this->unknown3 = 1.0;
    this->unknown1 = 1.0;

    Reset();
}

float SoftwareLimiter::Process(float sample) {
    bool bVar1;
    uint uVar3;
    uint uVar4;
    int iVar5;
    uint uVar6;
    uint uVar8;
    float fVar9;
    float fVar10;
    float abs_sample;

    abs_sample = std::abs(sample);
    if (abs_sample < this->gate) {
        if (this->ready) goto LAB_0006d86c;
        uVar8 = this->unknown4;
    }
    else {
        if (!this->ready) {
            memset(this->arr512, 0, sizeof(this->arr512));
            this->ready = true;
        }
LAB_0006d86c:
        uVar3 = 8;
        uVar8 = this->unknown4;
        uVar4 = uVar8;
        do {
            iVar5 = 2 << (uVar3 & 0xff);
            uVar6 = uVar4 ^ 1;
            this->arr512[512 + uVar4 - iVar5] = abs_sample;
            uVar4 = uVar4 / 2;
            if (abs_sample < this->arr512[512 + uVar6 - iVar5]) {
                abs_sample = this->arr512[512 + uVar6 - iVar5];
            }
            uVar3 = uVar3 - 1;
        } while (uVar3 != 0);
        if (this->gate < abs_sample) {
            bVar1 = this->ready;
            fVar10 = this->unknown1;
            uVar4 = (uVar8 + 1) % 256;
            this->arr256[uVar8] = sample;
            this->unknown4 = uVar4;
            if (bVar1) {
                fVar10 = this->gate / abs_sample;
            }
            abs_sample = this->arr256[uVar4];
            goto LAB_0006d8fc;
        }
        this->ready = false;
    }
    fVar10 = this->unknown1;
    this->arr256[uVar8] = sample;
    uVar8 = (uVar8 + 1) % 256;
    this->unknown4 = uVar8;
    abs_sample = this->arr256[uVar8];
LAB_0006d8fc:
    fVar9 = this->unknown2 * 0.9999 + 0.0001;
    fVar10 = fVar10 * 0.0999 + this->unknown3 * 0.8999;
    bVar1 = fVar10 < fVar9;
    this->unknown3 = fVar10;
    if (bVar1) {
        fVar9 = fVar10;
    }
    if (bVar1) {
        this->unknown2 = fVar10;
    }
    if (!bVar1) {
        this->unknown2 = fVar9;
    }
    fVar9 = abs_sample * fVar9;
    fVar10 = std::abs(fVar9);
    if (this->gate <= fVar10) {
        fVar9 = this->gate / std::abs(abs_sample);
    }
    if (this->gate <= fVar10) {
        this->unknown2 = fVar9;
        fVar9 = abs_sample * fVar9;
    }
    return fVar9;
}

void SoftwareLimiter::Reset() {
    memset(this->arr256, 0, sizeof(this->arr256));
    memset(this->arr512, 0, sizeof(this->arr512));
    this->ready = false;
    this->unknown4 = 0;
    this->unknown2 = 1.0;
    this->unknown3 = 1.0;
}

void SoftwareLimiter::SetGate(float gate) {
    this->gate = gate;
}
