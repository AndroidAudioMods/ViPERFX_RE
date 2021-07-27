//
// Created by mart on 7/26/21.
//

#pragma once


#include "../utils/Crossfeed.h"
#include "../utils/PassFilter.h"

class Cure : public Crossfeed {
public:
    Cure();

    void Process(float* buffer, uint32_t size);
    void Reset();
    void SetSamplingRate(uint32_t samplerate);

    PassFilter pass;
    bool enabled;
};
