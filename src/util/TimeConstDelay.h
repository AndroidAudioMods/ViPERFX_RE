//
// Created by mart on 2/12/21.
//

#ifndef VIPER_TIMECONSTDELAY_H
#define VIPER_TIMECONSTDELAY_H


class TimeConstDelay {
    undefined4 field_0x0;
    undefined4 field_0x4;
    undefined4 field_0x8;

public:
    TimeConstDelay();
    ~TimeConstDelay();
    void SetParameters(uint param_1,float param_2);
    undefined4 ProcessSample(int param_1);
};


#endif //VIPER_TIMECONSTDELAY_H
