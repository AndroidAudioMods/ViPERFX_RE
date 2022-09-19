#pragma once

enum FilterType {
    LOWPASS,
    HIGHPASS,
    BANDPASS,
    BANDSTOP,
    ALLPASS,
    PEAK,
    LOWSHELF,
    HIGHSHELF
};

class MultiBiquad {
public:
    MultiBiquad();

    double ProcessSample(double sample);

    void RefreshFilter(FilterType type, double gainAmp, double freq, double samplingRate, double qFactor, bool param_7);

    double y_2, y_1, x_2, x_1;
    double b0, b1, b2, a1, a2;
};



