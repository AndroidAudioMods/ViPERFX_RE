#include "MultiBiquad.h"
#include <cmath>

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

double MultiBiquad::ProcessSample(double sample) {
    double out = sample * this->b0 + this->x_1 * this->b1 + this->x_2 * this->b2 + this->y_1 * this->a1 +
                this->y_2 * this->a2;
    this->y_2 = this->y_1;
    this->y_1 = out;
    this->x_2 = this->x_1;
    this->x_1 = sample;
    return out;
}

void
MultiBiquad::RefreshFilter(FilterType type, float gainAmp, float frequency, uint32_t samplingRate, float qFactor, bool param_7) {
    float gain;

    if (type - 5 < 3) { // type - 5 < 3 is always true... right?
        gain = pow(10.0f, gainAmp / 40.0f);
    } else {
        gain = pow(10.0f, gainAmp / 20.0f);
    }

    double x = (2.0 * M_PI * (double) frequency) / (double) samplingRate;
    double sinX = sin(x);
    double cosX = cos(x);

    double y;
    double z;

    if (type - 6 < 2) {
        y = sinX / 2.0 * sqrt((1.0 / ((double) gain * 2.0)) * (1.0 / (double) qFactor - 1.0) + 2.0);
        z = sqrt((double) gain) * y;
    } else if (!param_7) {
        y = sinX / ((double) qFactor / 2.0);
        z = -1.0;
    } else {
        y = sinh(((double) qFactor * (log(2.0) / 2.0) * x) / sinX);
        z = -1.0;
    }

    double a0;
    double a1;
    double a2;
    double b0;
    double b1;
    double b2;

    switch (type) {
        case LOWPASS: {
            b1 = 1.0 - cosX;
            b0 = (1.0 - cosX) / 2.0;
            a1 = -cosX * 2.0;
            a2 = 1.0 - y;
            a0 = 1.0 + y;
            b2 = b0;
            break;
        }
        case HIGHPASS: {
            b1 = -1.0 - cosX;
            b0 = (1.0 + cosX) / 2.0;
            a1 = -cosX * 2.0;
            a2 = 1.0 - y;
            a0 = 1.0 + y;
            b2 = b0;
            break;
        }
        case BANDPASS: {
            b1 = 0.0;
            a1 = -cosX * 2.0;
            a2 = 1.0 - y;
            a0 = 1.0 + y;
            b0 = y;
            b2 = -y;
            break;
        }
        case BANDSTOP: {
            b1 = -cosX * 2.0;
            a2 = 1.0 - y;
            a0 = 1.0 + y;
            b0 = 1.0;
            b2 = 1.0;
            a1 = b1;
            break;
        }
        case ALLPASS: {
            b1 = -cosX * 2.0;
            a2 = 1.0 - y;
            a0 = 1.0 + y;
            b0 = a2;
            b2 = a0;
            a1 = b1;
            break;
        }
        case PEAK: {
            b1 = -cosX * 2.0;
            a2 = 1.0 - y / (double) gain;
            a0 = 1.0 + y / (double) gain;
            b0 = 1.0 + y * (double) gain;
            b2 = 1.0 - y * (double) gain;
            a1 = b1;
            break;
        }
        case LOWSHELF: {
            double tmp1 = (gain + 1.0) - (gain - 1.0) * cosX;
            double tmp2 = (gain + 1.0) + (gain - 1.0) * cosX;
            a1 = ((gain - 1.0) + (gain + 1.0) * cosX) * -2.0;
            a2 = tmp2 - z;
            b1 = (gain * 2.0) * ((gain - 1.0) - (gain + 1.0) * cosX);
            a0 = tmp2 + z;
            b0 = (tmp1 + z) * gain;
            b2 = (tmp1 - z) * gain;
            break;
        }
        case HIGHSHELF: {
            double tmp1 = (gain + 1.0) + (gain - 1.0) * cosX;
            double tmp2 = (gain + 1.0) - (gain - 1.0) * cosX;
            a2 = tmp2 - z;
            a0 = tmp2 + z;
            a1 = ((gain - 1.0) - (gain + 1.0) * cosX) * 2.0;
            b1 = gain * -2.0 * ((gain - 1.0) + (gain + 1.0) * cosX);
            b0 = (tmp1 + z) * gain;
            b2 = (tmp1 - z) * gain;
            break;
        }
    }

    this->x_1 = 0.0;
    this->x_2 = 0.0;
    this->y_1 = 0.0;
    this->y_2 = 0.0;

    this->a1 = -a1 / a0;
    this->a2 = -a2 / a0;
    this->b0 = b0 / a0;
    this->b1 = b1 / a0;
    this->b2 = b2 / a0;
}
