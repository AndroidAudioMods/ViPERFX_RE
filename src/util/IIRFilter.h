//
// Created by mart on 2/12/21.
//

#ifndef VIPER_IIRFILTER_H
#define VIPER_IIRFILTER_H


class IIRFilter {
    int field_0x0;
    undefined4 samplerate;
    bool enabled; // Created by retype action
    undefined field_0x9;
    undefined field_0xa;
    undefined field_0xb;
    struct MinPhaseIIRCoeffs field_0xc;
    char field_0x18[1984];
    undefined4 field_0x7d8;
    undefined4 field_0x7dc;
    undefined4 field_0x7e0;
    undefined4 field_0x7e4;
    undefined field_0x7e8;
    undefined field_0x7e9;
    undefined field_0x7ea;
    undefined field_0x7eb;
    undefined field_0x7ec;
    undefined field_0x7ed;
    undefined field_0x7ee;
    undefined field_0x7ef;
    undefined field_0x7f0;
    undefined field_0x7f1;
    undefined field_0x7f2;
    undefined field_0x7f3;
    undefined field_0x7f4;
    undefined field_0x7f5;
    undefined field_0x7f6;
    undefined field_0x7f7;
    undefined field_0x7f8;
    undefined field_0x7f9;
    undefined field_0x7fa;
    undefined field_0x7fb;
    undefined field_0x7fc;
    undefined field_0x7fd;
    undefined field_0x7fe;
    undefined field_0x7ff;
    undefined field_0x800;
    undefined field_0x801;
    undefined field_0x802;
    undefined field_0x803;
    undefined field_0x804;
    undefined field_0x805;
    undefined field_0x806;
    undefined field_0x807;
    undefined field_0x808;
    undefined field_0x809;
    undefined field_0x80a;
    undefined field_0x80b;
    undefined field_0x80c;
    undefined field_0x80d;
    undefined field_0x80e;
    undefined field_0x80f;
    undefined field_0x810;
    undefined field_0x811;
    undefined field_0x812;
    undefined field_0x813;
    undefined field_0x814;
    undefined field_0x815;
    undefined field_0x816;
    undefined field_0x817;
    undefined field_0x818;
    undefined field_0x819;
    undefined field_0x81a;
    undefined field_0x81b;
    undefined field_0x81c;
    undefined field_0x81d;
    undefined field_0x81e;
    undefined field_0x81f;
    undefined field_0x820;
    undefined field_0x821;
    undefined field_0x822;
    undefined field_0x823;
    undefined field_0x824;
    undefined field_0x825;
    undefined field_0x826;
    undefined field_0x827;
    undefined field_0x828;
    undefined field_0x829;
    undefined field_0x82a;
    undefined field_0x82b;
    undefined field_0x82c;
    undefined field_0x82d;
    undefined field_0x82e;
    undefined field_0x82f;
    undefined field_0x830;
    undefined field_0x831;
    undefined field_0x832;
    undefined field_0x833;
    undefined field_0x834;
    undefined field_0x835;
    undefined field_0x836;
    undefined field_0x837;
    undefined field_0x838;
    undefined field_0x839;
    undefined field_0x83a;
    undefined field_0x83b;
    undefined field_0x83c;
    undefined field_0x83d;
    undefined field_0x83e;
    undefined field_0x83f;
    undefined field_0x840;
    undefined field_0x841;
    undefined field_0x842;
    undefined field_0x843;
    undefined field_0x844;
    undefined field_0x845;
    undefined field_0x846;
    undefined field_0x847;
    undefined field_0x848;
    undefined field_0x849;
    undefined field_0x84a;
    undefined field_0x84b;
    undefined field_0x84c;
    undefined field_0x84d;
    undefined field_0x84e;
    undefined field_0x84f;
    undefined field_0x850;
    undefined field_0x851;
    undefined field_0x852;
    undefined field_0x853;
    undefined field_0x854;
    undefined field_0x855;
    undefined field_0x856;
    undefined field_0x857;
    undefined field_0x858;
    undefined field_0x859;
    undefined field_0x85a;
    undefined field_0x85b;
    undefined field_0x85c;
    undefined field_0x85d;
    undefined field_0x85e;
    undefined field_0x85f;
    
public:
    ~IIRFilter();
    double SetBandLevel(int param_1,float param_2);
    void Reset();
    IIRFilter(int param_1);
    undefined4 SetEnable(bool param_1);
    void SetSamplingRate(int param_1);
    void Process(int *param_1,int param_2);
};


#endif //VIPER_IIRFILTER_H
