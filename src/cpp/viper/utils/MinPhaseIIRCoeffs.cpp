#include "MinPhaseIIRCoeffs.h"
#include "../constants.h"
#include <cmath>

static const float MIN_PHASE_IIR_COEFFS_FREQ_10BANDS[] = {
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

static const float MIN_PHASE_IIR_COEFFS_FREQ_15BANDS[] = {
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

static const float MIN_PHASE_IIR_COEFFS_FREQ_25BANDS[] = {
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

static const float MIN_PHASE_IIR_COEFFS_FREQ_31BANDS[] = {
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
    this->bands = 0;
}

MinPhaseIIRCoeffs::~MinPhaseIIRCoeffs() {
    delete[] this->coeffs;
}

void MinPhaseIIRCoeffs::Find_F1_F2(double param_2, double param_3, double *param_4, double *param_5) {
    double x = pow(2.0, param_3 / 2.0);
    *param_5 = param_2 / x;
    *param_4 = param_2 * x;
}

float *MinPhaseIIRCoeffs::GetCoefficients() {
    return this->coeffs;
}

float MinPhaseIIRCoeffs::GetIndexFrequency(uint32_t index) {
    switch (this->bands) {
        case 10:
            return MIN_PHASE_IIR_COEFFS_FREQ_10BANDS[index];
        case 15:
            return MIN_PHASE_IIR_COEFFS_FREQ_15BANDS[index];
        case 25:
            return MIN_PHASE_IIR_COEFFS_FREQ_25BANDS[index];
        case 31:
            return MIN_PHASE_IIR_COEFFS_FREQ_31BANDS[index];
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

int MinPhaseIIRCoeffs::UpdateCoeffs(uint32_t bands, uint32_t samplingRate) {
    if ((bands != 10 && bands != 15 && bands != 25 && bands != 31) || samplingRate != 44100) {
        return 0;
    }

    this->bands = bands;
    this->samplingRate = samplingRate;

    delete[] this->coeffs;
    this->coeffs = new float[bands * 4]();

    const float *coeffsArray;
    double tmp;

    switch (bands) {
        case 10:
            coeffsArray = MIN_PHASE_IIR_COEFFS_FREQ_10BANDS;
            tmp = 3.0 / 3.0;
            break;
        case 15:
            coeffsArray = MIN_PHASE_IIR_COEFFS_FREQ_15BANDS;
            tmp = 2.0 / 3.0;
            break;
        case 25:
            coeffsArray = MIN_PHASE_IIR_COEFFS_FREQ_25BANDS;
            tmp = 1.0 / 3.0;
            break;
        case 31:
            coeffsArray = MIN_PHASE_IIR_COEFFS_FREQ_31BANDS;
            tmp = 1.0 / 3.0;
            break;
    }

    for (uint32_t i = 0; i < bands; i++) {
        double ret1;
        double ret2;
        this->Find_F1_F2(coeffsArray[i], tmp, &ret1, &ret2);

        double x = (2.0 * M_PI * (double) coeffsArray[i]) / (double) this->samplingRate;
        double y = (2.0 * M_PI * ret2) / (double) this->samplingRate;

        double cosX = cos(x);
        double cosY = cos(y);
        double sinY = sin(y);

        double a = cosX * cosY;
        double b = pow(cosX, 2.0) / 2.0;
        double c = pow(sinY, 2.0);

        if (this->SolveRoot(((b - a) + 0.5) - c, c + (((b + pow(cosY, 2.0)) - a) - 0.5), ((pow(cosX, 2.0) / 8.0 - cosX * cosY / 4.0) + 0.125) - c / 4.0, &ret1) == 0) {
            this->coeffs[4 * i] = (float) (ret1 * 2.0);
            this->coeffs[4 * i + 1] = (float) (0.5 - ret1);
            this->coeffs[4 * i + 2] = (float) ((ret1 + 0.5) * cosX);
        }
    }

    return 1;
}
