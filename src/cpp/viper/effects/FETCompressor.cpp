#include <cmath>
#include "FETCompressor.h"
#include "../constants.h"

static const float DEFAULT_FETCOMP_PARAMETERS[] = {
        1.000000,
        0.000000,
        0.000000,
        0.000000,
        1.000000,
        0.000000,
        1.000000,
        0.514679,
        1.000000,
        0.384311,
        1.000000,
        0.500000,
        0.879450,
        0.884311,
        0.615689,
        0.660964,
        1.000000
};

static double calculate_exp_something(double param_1, double param_2) {
    return 1.0 - exp(-1.0 / (param_2 * param_1));
}

FETCompressor::FETCompressor() {
    this->samplingRate = VIPER_DEFAULT_SAMPLING_RATE;

    for (uint32_t i = 0; i < 17; i++) {
        SetParameter(i, GetParameterDefault(i));
    }

    Reset();
}

float FETCompressor::GetMeter(int param_1) {
    if (param_1 != 0) {
        return 0.0;
    }

    if (this->unk1) {
        float tmp = (6.907755 - this->unk28) / 6.907755;
        if (tmp < 1.0) {
            if (tmp < 0.0) {
                tmp = 0.0;
            }
            return tmp;
        }
    }

    return 1.0;
}

float FETCompressor::GetParameter(uint32_t index) {
    return this->parameters[index];
}

float FETCompressor::GetParameterDefault(uint32_t index) {
    if (index < 17) {
        return DEFAULT_FETCOMP_PARAMETERS[index];
    }
    return 0.0;
}

void FETCompressor::Process(float *samples, uint32_t size) {
    if (size == 0) return;

    for (uint32_t i = 0; i < size * 2; i += 2) {
        double inL = abs(samples[i]);
        double inR = abs(samples[i + 1]);

        double in;
        if (inL > inR) {
            in = inL;
        } else {
            in = inR;
        }

        double out = ProcessSidechain(in);
        if (this->unk1) {
            samples[i] *= (float) out;
            samples[i + 1] *= (float) out;
        }

        this->unk23 = this->unk23 + (this->unk2 - this->unk23) * this->unk22;
        this->unk24 = this->unk24 + this->unk22 * (this->unk6 - this->unk24);
    }
}

double FETCompressor::ProcessSidechain(double in) {
    double in2 = pow(in, 2.0);
    if (in2 < 0.000001) {
        in2 = 0.000001;
    }

    float a = this->unk9;
    float b = this->unk25 + this->unk18 * (in2 - this->unk25);
    float c = this->unk26 + this->unk18 * (in2 - this->unk26);
    float d = this->unk8;

    if (in2 < b) {
        in2 = b;
    }

    this->unk26 = c;
    this->unk25 = in2;

    in2 /= c;

    if (this->unk10) {

    }

    if (this->unk13) {

    }

    if (in >= 0.000001) {

    }

    if (!this->unk5) {

    } else {

    }

    if (this->unk7) {
        if (!this->unk21) {

        } else {

        }

//        return exp(-a - fVar6); // FIXME: Change "a" and "fVar6" variable
    }

    return exp(this->unk24 - a); // FIXME: Change "a" variable
}

void FETCompressor::Reset() {
    this->unk22 = calculate_exp_something(this->samplingRate, 0.05);
    this->unk23 = this->unk2;
    this->unk24 = this->unk6;
    this->unk25 = 0.000001;
    this->unk26 = 0.000001;
    this->unk27 = 0.0;
    this->unk28 = 0.0;
    this->unk29 = 0.0;
}

void FETCompressor::SetParameter(uint32_t index, float value) {
    this->parameters[index] = value;

    switch (index) {
        case 0: {
            this->unk1 = value >= 0.5;
            break;
        }
        case 1: {
            this->unk2 = log(pow(10.0, (value * -60.0) / 20.0));
            break;
        }
        case 2: {
            this->unk3 = -value;
            break;
        }
        case 3: {
            this->unk4 = log(pow(10.0, (value * 60.0) / 20));
            break;
        }
        case 4: {
            this->unk5 = value >= 0.5;
            break;
        }
        case 5: {
            this->unk6 = log(pow(10.0, (value * 60.0) / 20.0));
            break;
        }
        case 6: {
            this->unk7 = value >= 0.5;
            break;
        }
        case 7: {
            double tmp = exp(value * 7.600903 - 9.21034);
            this->unk8 = tmp;
            if (tmp <= 0.0) {
                tmp = 1.0;
            } else {
                tmp = calculate_exp_something(this->samplingRate, tmp);
            }
            this->unk9 = tmp;
            break;
        }
        case 8: {
            this->unk10 = value >= 0.5;
            break;
        }
        case 9: {
            double tmp = exp(value * 5.991465 - 5.298317);
            this->unk11 = tmp;
            if (tmp <= 0.0) {
                tmp = 1.0;
            } else {
                tmp = calculate_exp_something(this->samplingRate, tmp);
            }
            this->unk12 = tmp;
            break;
        }
        case 10: {
            this->unk13 = value >= 0.5;
            break;
        }
        case 11: {
            this->unk14 =  value * 4.0;
            break;
        }
        case 12: {
            this->unk15 = exp(value * 7.600903 - 9.21034);
            break;
        }
        case 13: {
            this->unk16 = exp(value * 5.991465 - 5.298317);
            break;
        }
        case 14: {
            double tmp = exp(value * 5.991465 - 5.298317);
            this->unk17 = tmp;
            if (tmp <= 0.0) {
                tmp = 1.0;
            } else {
                tmp = calculate_exp_something(this->samplingRate, tmp);
            }
            this->unk18 = tmp;
            break;
        }
        case 15: {
            double tmp = exp(value * 1.386294);
            this->unk19 = tmp;
            if (tmp <= 0.0) {
                tmp = 1.0;
            } else {
                tmp = calculate_exp_something(this->samplingRate, tmp);
            }
            this->unk20 = tmp;
            break;
        }
        case 16: {
            this->unk21 = value >= 0.5;
            break;
        }
    }
}

void FETCompressor::SetSamplingRate(uint32_t samplingRate) {
    this->samplingRate = samplingRate;

    for (uint32_t i = 0; i < 17; i++) {
        SetParameter(i, GetParameter(i));
    }

    Reset();
}
