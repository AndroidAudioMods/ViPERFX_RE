#include <cmath>
#include "IIR_1st.h"

// Seems to be taken from https://github.com/michaelwillis/dragonfly-reverb/blob/master/common/freeverb/efilter.cpp
// Or similar sources

IIR_1st::IIR_1st() {
    this->b0 = 0.f;
    this->b1 = 0.f;
    this->a1 = 0.f;
    Mute();
}

void IIR_1st::Mute() {
    this->prevSample = 0.f;
}

void IIR_1st::SetCoefficients(float b0, float b1, float a1) {
    this->b0 = b0;
    this->b1 = b1;
    this->a1 = a1;
}

#define angle(freq, samplingRate) (expf(-1*(float)M_PI*(freq)/((float)(samplingRate)/2.f)))
#define omega() (2.f * (float)M_PI * frequency / (float)samplingRate)
#define omega_2() ((float)M_PI * frequency / (float)samplingRate)

void IIR_1st::setHPF_A(float frequency, uint32_t samplingRate) {
    this->a1 = angle(frequency, samplingRate);
    float norm = (1 + a1) / 2.f;
    this->b0 = norm;
    this->b1 = -norm;
}

void IIR_1st::setHPF_BW(float frequency, uint32_t samplingRate) {
    float omega_2 = omega_2();
    float tan_omega_2 = tanf(omega_2);
    this->b0 = 1 / (1 + tan_omega_2);
    this->b1 = -this->b0;
    this->a1 = (1 - tan_omega_2) / (1 + tan_omega_2);
}

void IIR_1st::setHPF_C(float frequency, uint32_t samplingRate) {
    this->b0 = (float) samplingRate / ((float) samplingRate + frequency);
    this->b1 = -1 * this->b0;
    this->a1 = ((float) samplingRate - frequency) / ((float) samplingRate + frequency);
}

void IIR_1st::setHPFwLPS_A(float frequency, uint32_t samplingRate) {
    this->a1 = -0.12f;
    this->b0 = -1.f;
    this->b1 = angle(frequency, samplingRate);
    float norm = (1 - this->a1) / fabsf(this->b0 + this->b1);
    this->b0 *= norm;
    this->b1 *= norm;;
}

void IIR_1st::setHSF_A(float f1, float f2, uint32_t samplingRate) {
    this->a1 = angle(f1, samplingRate);
    this->b0 = -1.f;
    this->b1 = angle(f2, samplingRate);
    float norm = (1 - this->a1) / (this->b0 + this->b1);
    this->b0 *= norm;
    this->b1 *= norm;
}

void IIR_1st::setLPF_A(float frequency, uint32_t samplingRate) {
    this->a1 = angle(frequency, samplingRate);
    this->b0 = 1.f;
    this->b1 = 0.12f;
    float norm = (1 + this->a1) / (this->b0 + this->b1);
    this->b0 *= norm;
    this->b1 *= norm;
}

void IIR_1st::setLPF_BW(float frequency, uint32_t samplingRate) {
    float omega_2 = omega_2();
    float tan_omega_2 = tanf(omega_2);
    this->a1 = (1 - tan_omega_2) / (1 + tan_omega_2);
    this->b0 = tan_omega_2 / (1 + tan_omega_2);
    this->b1 = this->b0;
}

void IIR_1st::setLPF_C(float frequency, uint32_t samplingRate) {
    this->b0 = frequency / ((float) samplingRate + frequency);
    this->b1 = this->b0;
    this->a1 = ((float) samplingRate - frequency) / ((float) samplingRate + frequency);
}

void IIR_1st::setLSF_A(float f1, float f2, uint32_t samplingRate) {
    this->a1 = angle(f1, samplingRate);
    this->b0 = -1.f;
    this->b1 = angle(f2, samplingRate);
}

void IIR_1st::setPole(float a1) {
    this->a1 = a1;
    this->b0 = 1.f - fabsf(a1);
    this->b1 = 0.f;
}

void IIR_1st::setPoleHPF(float frequency, uint32_t samplingRate) {
    float omega = omega();
    float cos_omega = cosf(omega);
    float tmp = (2.f + cos_omega);
    float coeff = tmp - sqrtf(tmp * tmp - 1.f);
    this->a1 = -coeff;
    this->b0 = 1.f - coeff;
    this->b1 = 0;
}

void IIR_1st::setPoleLPF(float frequency, uint32_t samplingRate) {
    float omega = omega();
    float cos_omega = cosf(omega);
    float tmp = (2.f - cos_omega);
    float coeff = tmp - sqrtf(tmp * tmp - 1.f);
    this->a1 = coeff;
    this->b0 = 1.f - coeff;
    this->b1 = 0.f;
}

void IIR_1st::setZero(float b1) {
    this->a1 = 0;
    this->b0 = -1;
    this->b1 = b1;
    float norm = fabsf(this->b0) + fabsf(this->b1);
    this->b0 *= norm;
    this->b1 *= norm;
}

void IIR_1st::setZeroHPF(float frequency, uint32_t samplingRate) {
    float omega = omega();
    float cos_omega = cosf(omega);
    float tmp = (1.f - 2.f * cos_omega);
    float coeff = tmp - sqrtf(tmp * tmp - 1.f);
    this->a1 = 0.f;
    this->b0 = 1.f / (1.f + coeff);
    this->b1 = -coeff / (1.f + coeff);
}

void IIR_1st::setZeroLPF(float frequency, uint32_t samplingRate) {
    float omega = omega();
    float cos_omega = cosf(omega);
    float tmp = (1.f + 2.f * cos_omega);
    float coeff = tmp - sqrtf(tmp * tmp - 1.f);
    this->a1 = 0.f;
    this->b0 = 1.f / (1.f + coeff);
    this->b1 = coeff / (1.f + coeff);
}