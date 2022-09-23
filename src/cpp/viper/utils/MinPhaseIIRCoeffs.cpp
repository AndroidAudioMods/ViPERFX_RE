#include "MinPhaseIIRCoeffs.h"
#include "../constants.h"
#include <cmath>

static const float MIN_PHASE_IIR_COEFFS_FREQ_10[] = {
        31.0,
        62.0,
        125.0,
        250.0,
        500.0,
        1000.0,
        2000.0,
        4000.0,
        8000.0,
        16000.0
};

static const float MIN_PHASE_IIR_COEFFS_FREQ_15[] = {
        25.0,
        40.0,
        63.0,
        100.0,
        160.0,
        250.0,
        400.0,
        630.0,
        1000.0,
        1600.0,
        2500.0,
        4000.0,
        6300.0,
        10000.0,
        16000.0
};

static const float MIN_PHASE_IIR_COEFFS_FREQ_25[] = {
        20.0,
        31.5,
        40.0,
        50.0,
        80.0,
        100.0,
        125.0,
        160.0,
        250.0,
        315.0,
        400.0,
        500.0,
        800.0,
        1000.0,
        1250.0,
        1600.0,
        2500.0,
        3150.0,
        4000.0,
        5000.0,
        8000.0,
        10000.0,
        12500.0,
        16000.0,
        20000.0
};

static const float MIN_PHASE_IIR_COEFFS_FREQ_31[] = {
        20.0,
        25.0,
        31.5,
        40.0,
        50.0,
        63.0,
        80.0,
        100.0,
        125.0,
        160.0,
        200.0,
        250.0,
        315.0,
        400.0,
        500.0,
        630.0,
        800.0,
        1000.0,
        1250.0,
        1600.0,
        2000.0,
        2500.0,
        3150.0,
        4000.0,
        5000.0,
        6300.0,
        8000.0,
        10000.0,
        12500.0,
        16000.0,
        20000.0
};

MinPhaseIIRCoeffs::MinPhaseIIRCoeffs() {
    this->coeffs = nullptr;
    this->samplingRate = DEFAULT_SAMPLERATE;
    this->freqs = 0;
}

MinPhaseIIRCoeffs::~MinPhaseIIRCoeffs() {
    delete this->coeffs;
}

void MinPhaseIIRCoeffs::Find_F1_F2(double param_2, double param_3, double *parma_4, double *param_5) {
    double x = pow(2.0, param_3 / 2.0);
    *param_5 = param_2 / x;
    *parma_4 = param_2 * x;
}

float *MinPhaseIIRCoeffs::GetCoefficients() {
    return this->coeffs;
}

float MinPhaseIIRCoeffs::GetIndexFrequency(uint32_t index) {
    switch (this->freqs) {
        case 10:
            return MIN_PHASE_IIR_COEFFS_FREQ_10[index];
        case 15:
            return MIN_PHASE_IIR_COEFFS_FREQ_15[index];
        case 25:
            return MIN_PHASE_IIR_COEFFS_FREQ_25[index];
        case 31:
            return MIN_PHASE_IIR_COEFFS_FREQ_31[index];
        default:
            return 0.0;
    }
}

int MinPhaseIIRCoeffs::SolveRoot(double param_2, double param_3, double param_4, double *param_5) {
    double x = (param_4 - pow(param_3, 2.0) / (param_2 * 4.0)) / param_2;
    double y = param_3 / (param_2 * 2.0);

    if (x >= 0.0) {
        return -1;
    }

    double z = sqrt(-x);
    double a = -y - z;
    double b = z - y;
    if (a > b) {
        *param_5 = b;
    } else {
        *param_5 = a;
    }

    return 0;
}

int MinPhaseIIRCoeffs::UpdateCoeffs(uint32_t freqs, int samplingRate) {
    if ((freqs != 10 && freqs != 15 && freqs != 25 && freqs != 31) || samplingRate != 44100) {
        return 0;
    }

    this->freqs = freqs;
    this->samplingRate = samplingRate;

    delete this->coeffs;
    this->coeffs = new float[freqs * 5];

    return 0;
}
