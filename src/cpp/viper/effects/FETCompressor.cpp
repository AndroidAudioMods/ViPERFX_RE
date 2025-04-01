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
        SetParameter((FETCompressor::Parameter) i, GetParameterDefault((FETCompressor::Parameter) i));
    }

    Reset();
}

float FETCompressor::GetMeter(int param_1) {
    if (param_1 != 0) {
        return 0.0;
    }

    if (this->enable) {
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

float FETCompressor::GetParameter(FETCompressor::Parameter parameter) {
    return this->parameters[parameter];
}

float FETCompressor::GetParameterDefault(FETCompressor::Parameter parameter) {
    if (parameter < 17) {
        return DEFAULT_FETCOMP_PARAMETERS[parameter];
    }
    return 0.0;
}

void FETCompressor::Process(float *samples, uint32_t size) {
    return;
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
        if (this->enable) {
            samples[i] *= (float) out;
            samples[i + 1] *= (float) out;
        }

        this->unk23 = this->unk23 + (this->threshold - this->unk23) * this->unk22;
        this->unk24 = this->unk24 + this->unk22 * (this->gain - this->unk24);
    }
}

double FETCompressor::ProcessSidechain(double in) {
    double in2 = in * in;
    if (in2 < 0.000001) {
        in2 = 0.000001;
    }

    float a = this->attack2;
    float b = this->unk25 + this->crest2 * (in2 - this->unk25);
    float c = this->unk26 + this->crest2 * (in2 - this->unk26);
    float d = this->attack1;

    if (in2 < b) {
        in2 = b;
    }

    this->unk26 = c;
    this->unk25 = in2;

    in2 /= c;

    if (this->autoAttack) {

    }

    if (this->autoRelease) {

    }

    if (in >= 0.000001) {

    }

    if (!this->autoKnee) {

    } else {

    }

    if (this->autoGain) {
        if (!this->noClip) {

        } else {

        }

//        return exp(-a - fVar6); // FIXME: Change "a" and "fVar6" variable
    }

    return exp(this->unk24 - a); // FIXME: Change "a" variable
}

void FETCompressor::Reset() {
    this->unk22 = calculate_exp_something(this->samplingRate, 0.05);
    this->unk23 = this->threshold;
    this->unk24 = this->gain;
    this->unk25 = 0.000001;
    this->unk26 = 0.000001;
    this->unk27 = 0.0;
    this->unk28 = 0.0;
    this->unk29 = 0.0;
}

void FETCompressor::SetParameter(FETCompressor::Parameter parameter, float value) {
    this->parameters[parameter] = value;

    switch (parameter) {
        case ENABLE: {
            this->enable = value >= 0.5;
            break;
        }
        case THRESHOLD: {
            this->threshold = log(pow(10.0, (value * -60.0) / 20.0));
            break;
        }
        case RATIO: {
            this->ratio = -value;
            break;
        }
        case KNEE: {
            this->knee = log(pow(10.0, (value * 60.0) / 20));
            break;
        }
        case AUTO_KNEE: {
            this->autoKnee = value >= 0.5;
            break;
        }
        case GAIN: {
            this->gain = log(pow(10.0, (value * 60.0) / 20.0));
            break;
        }
        case AUTO_GAIN: {
            this->autoGain = value >= 0.5;
            break;
        }
        case ATTACK: {
            double tmp = exp(value * 7.600903 - 9.21034);
            this->attack1 = tmp;
            if (tmp <= 0.0) {
                tmp = 1.0;
            } else {
                tmp = calculate_exp_something(this->samplingRate, tmp);
            }
            this->attack2 = tmp;
            break;
        }
        case AUTO_ATTACK: {
            this->autoAttack = value >= 0.5;
            break;
        }
        case RELEASE: {
            double tmp = exp(value * 5.991465 - 5.298317);
            this->release1 = tmp;
            if (tmp <= 0.0) {
                tmp = 1.0;
            } else {
                tmp = calculate_exp_something(this->samplingRate, tmp);
            }
            this->release2 = tmp;
            break;
        }
        case AUTO_RELEASE: {
            this->autoRelease = value >= 0.5;
            break;
        }
        case KNEE_MULTI: {
            this->kneeMulti = value * 4.0;
            break;
        }
        case MAX_ATTACK: {
            this->maxAttack = exp(value * 7.600903 - 9.21034);
            break;
        }
        case MAX_RELEASE: {
            this->maxRelease = exp(value * 5.991465 - 5.298317);
            break;
        }
        case CREST: {
            double tmp = exp(value * 5.991465 - 5.298317);
            this->crest1 = tmp;
            if (tmp <= 0.0) {
                tmp = 1.0;
            } else {
                tmp = calculate_exp_something(this->samplingRate, tmp);
            }
            this->crest2 = tmp;
            break;
        }
        case ADAPT: {
            double tmp = exp(value * 1.386294);
            this->adapt1 = tmp;
            if (tmp <= 0.0) {
                tmp = 1.0;
            } else {
                tmp = calculate_exp_something(this->samplingRate, tmp);
            }
            this->adapt2 = tmp;
            break;
        }
        case NO_CLIP: {
            this->noClip = value >= 0.5;
            break;
        }
    }
}

void FETCompressor::SetSamplingRate(uint32_t samplingRate) {
    this->samplingRate = samplingRate;

    for (uint32_t i = 0; i < 17; i++) {
        SetParameter((FETCompressor::Parameter) i, GetParameter((FETCompressor::Parameter) i));
    }

    Reset();
}
