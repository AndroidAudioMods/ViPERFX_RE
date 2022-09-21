#pragma once

enum FilterType {
    LOWPASS = 0,
    HIGHPASS = 1,
    BANDPASS = 2,
    BANDSTOP = 3,
    ALLPASS = 4,
    PEAK = 5,
    LOWSHELF = 6,
    HIGHSHELF = 7
};

class MultiBiquad {
public:
    MultiBiquad();

    double ProcessSample(double sample);
    void RefreshFilter(FilterType type, float gainAmp, float frequency, uint32_t samplingRate, float qFactor, bool param_7);

private:
    double x_1;
    double x_2;
    double y_1;
    double y_2;
    double a1;
    double a2;
    double b0;
    double b1;
    double b2;
};



