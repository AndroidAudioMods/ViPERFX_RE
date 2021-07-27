//
// Created by mart on 7/27/21.
//

#pragma once


enum FilterType {

};


class MultiBiquad {
public:
    MultiBiquad();

    float ProcessSample(float sample);
    void RefreshFilter(FilterType type, float gainAmp, float freq, float samplerate, float qFactor, bool param_7);

    float y_2, y_1, x_2, x_1;
    float b0, b1, b2, a1, a2;
};



