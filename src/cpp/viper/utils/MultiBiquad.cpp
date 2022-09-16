//
// Created by mart on 7/27/21.
//

#include <cmath>
#include "MultiBiquad.h"

MultiBiquad::MultiBiquad() {
    this->y_2 = 0;
    this->y_1 = 0;
    this->x_2 = 0;
    this->x_1 = 0;
    this->b0 = 0;
    this->b1 = 0;
    this->b2 = 0;
    this->a1 = 0;
    this->a2 = 0;
}

float MultiBiquad::ProcessSample(float sample) {
    float out = sample * this->b0 + this->x_1 * this->b1 + this->x_2 * this->b2 + this->y_1 * this->a1 +
                this->y_2 * this->a2;
    this->y_2 = this->y_1;
    this->y_1 = out;
    this->x_2 = this->x_1;
    this->x_1 = sample;
    return out;
}

void
MultiBiquad::RefreshFilter(FilterType type, float gainAmp, float freq, float samplerate, float qFactor, bool param_7) {
    bool uVar1;
    double dVar4;
    double dVar5;
    double dVar6;
    double dVar7;
    double dVar8;
    double dVar9;
    double dVar10;
    double dVar11;
    double a0;
    double a1;
    double a2;
    double b0;
    double b1;
    double b2;

    dVar10 = pow(10.0, gainAmp / 40.0);
    dVar4 = (freq * 2 * M_PI) / samplerate;
    dVar5 = sin(dVar4);
    dVar11 = cos(dVar4);
    uVar1 = type == HIGHSHELF;
    dVar4 = (1.0 / dVar10 + dVar10) * (1.0 / qFactor - 1.0) + 2.0;
    dVar6 = sqrt(dVar4);
    if (!(bool) uVar1) {
        dVar4 = sinh(dVar4);
        dVar6 = dVar4;
    }
    dVar4 = sqrt(dVar10);
    dVar5 = dVar5 * 0.5 * dVar6;
    if (!(bool) uVar1) {
        dVar4 = sinh(dVar10);
    }
    dVar4 = (dVar4 + dVar4) * dVar5;
    switch (type) {
        case LOWPASS:
            b1 = 1.0 - dVar11;
            dVar10 = b1;
            b0 = dVar10 * 0.5;
            a0 = dVar5 + 1.0;
            a1 = dVar11 * -2.0;
            a2 = 1.0 - dVar5;
            b2 = b0;
            break;
        case HIGHPASS:
            b1 = 0.0 - (dVar11 + 1.0);
            dVar10 = dVar11 + 1.0;
            b0 = dVar10 * 0.5;
            a0 = dVar5 + 1.0;
            a1 = dVar11 * -2.0;
            a2 = 1.0 - dVar5;
            b2 = b0;
            break;
        case BANDPASS:
            a1 = dVar11 * -2.0;
            a2 = 1.0 - dVar5;
            a0 = dVar5 + 1.0;
            b1 = 0.0;
            b0 = dVar5;
            b2 = 0.0 - dVar5;
            break;
        case BANDSTOP:
            b1 = dVar11 * -2.0;
            a2 = 1.0 - dVar5;
            a0 = dVar5 + 1.0;
            b0 = 1.0;
            b2 = 1.0;
            a1 = b1;
            break;
        case ALLPASS:
            b1 = dVar11 * -2.0;
            a2 = 1.0 - dVar5;
            a0 = dVar5 + 1.0;
            b0 = a2;
            b2 = a0;
            a1 = b1;
            break;
        case PEAK:
            b1 = dVar11 * -2.0;
            a2 = 1.0 - dVar5 / dVar10;
            a0 = dVar5 / dVar10 + 1.0;
            b0 = dVar5 * dVar10 + 1.0;
            b2 = 1.0 - dVar5 * dVar10;
            a1 = b1;
            break;
        case LOWSHELF:
            dVar6 = dVar10 - 1.0;
            dVar7 = dVar10 + 1.0;
            dVar5 = dVar7 - dVar6 * dVar11;
            dVar8 = dVar7 + dVar6 * dVar11;
            a0 = dVar8 + dVar4;
            b1 = (dVar10 + dVar10) * (dVar6 - dVar11 * dVar7);
            a2 = dVar8 - dVar4;
            a1 = (dVar6 + dVar11 * dVar7) * -2.0;
            b0 = (dVar5 + dVar4) * dVar10;
            b2 = (dVar5 - dVar4) * dVar10;
            break;
        case HIGHSHELF:
            dVar6 = dVar10 - 1.0;
            dVar8 = dVar10 + 1.0;
            dVar5 = dVar8 + dVar6 * dVar11;
            dVar9 = dVar8 - dVar6 * dVar11;
            dVar7 = dVar6 - dVar11 * dVar8;
            a0 = dVar9 + dVar4;
            b1 = dVar10 * -2.0 * (dVar6 + dVar11 * dVar8);
            a2 = dVar9 - dVar4;
            a1 = dVar7 + dVar7;
            b0 = (dVar5 + dVar4) * dVar10;
            b2 = (dVar5 - dVar4) * dVar10;
    }

    this->a1 = a1 / a0;
    this->a2 = a2 / a0;
    this->b0 = b0 / a0;
    this->b1 = b1 / a0;
    this->b2 = b2 / a0;

    this->y_2 = 0.f;
    this->y_1 = 0.f;
    this->x_2 = 0.f;
    this->x_1 = 0.f;
}
