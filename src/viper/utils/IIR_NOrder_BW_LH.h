#pragma once

#include "IIR_1st.h"
#include <vector>

class IIR_NOrder_BW_LH {
public:
    explicit IIR_NOrder_BW_LH(uint32_t order);

    void Mute();
    void setLPF(float frequency, uint32_t samplingRate);
    void setHPF(float frequency, uint32_t samplingRate);


    std::vector<IIR_1st> filters;
    uint32_t order;
};

inline float do_filter_lh(IIR_NOrder_BW_LH *filt, float sample) {
    for (uint32_t idx = 0; idx < filt->order; idx++) {
        sample = do_filter(&filt->filters[idx], sample);
    }
    return sample;
}

inline float do_filter_lh(IIR_NOrder_BW_LH& filt, float sample) {
    for (uint32_t idx = 0; idx < filt.order; idx++) {
        sample = do_filter(&filt.filters[idx], sample);
    }
    return sample;
}
