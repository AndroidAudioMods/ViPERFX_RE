#include "Polyphase.h"
#include "../constants.h"

static const float POLYPHASE_COEFFICIENTS_2[] = {
        -0.002339,
        -0.002073,
        -0.001940,
        -0.001675,
        -0.001515,
        -0.001329,
        -0.001223,
        -0.001037,
        -0.000904,
        -0.000851,
        -0.000532,
        -0.000851,
        -0.000106,
        -0.001010,
        0.000558,
        -0.001435,
        0.001302,
        -0.001967,
        0.002259,
        -0.002605,
        0.003216,
        -0.003562,
        0.004784,
        -0.005475,
        0.007655,
        -0.008506,
        0.017622,
        -0.024639,
        0.028679,
        -0.017303,
        -0.032507,
        0.623321,
        0.184702,
        -0.166867,
        0.025729,
        -0.078490,
        -0.015735,
        -0.041199,
        -0.023151,
        -0.031524,
        -0.020121,
        -0.024985,
        -0.017303,
        -0.019616,
        -0.015018,
        -0.015204,
        -0.012838,
        -0.011881,
        -0.010951,
        -0.009516,
        -0.009090,
        -0.007788,
        -0.007442,
        -0.006353,
        -0.006087,
        -0.005183,
        -0.004970,
        -0.004253,
        -0.003987,
        -0.003482,
        -0.003216,
        -0.002871,
        -0.002578
};

static const float POLYPHASE_COEFFICIENTS_OTHER[] = {
        -0.014194,
        -0.002339,
        -0.006220,
        -0.019722,
        -0.020626,
        -0.014885,
        -0.012240,
        -0.012386,
        -0.011801,
        -0.011376,
        -0.016293,
        -0.018845,
        -0.018327,
        -0.013902,
        -0.014951,
        -0.015895,
        -0.019044,
        -0.017928,
        -0.020094,
        -0.017715,
        -0.018845,
        -0.015377,
        -0.018354,
        -0.016665,
        -0.018951,
        -0.011416,
        -0.019469,
        -0.017250,
        0.003549,
        -0.076045,
        0.288350,
        0.267751,
        -0.041212,
        -0.005130,
        -0.088418,
        -0.089348,
        -0.087686,
        -0.065625,
        -0.041305,
        -0.013343,
        0.001422,
        0.010313,
        0.005834,
        -0.001170,
        -0.014499,
        -0.021822,
        -0.030792,
        -0.029331,
        -0.031071,
        -0.018407,
        -0.027271,
        -0.008373,
        -0.010791,
        -0.040680,
        0.229171,
        0.080324,
        -0.070955,
        0.021689,
        -0.046607,
        -0.025011,
        -0.026886,
        -0.027271,
        -0.032919
};

Polyphase::Polyphase(int unknown1) {
    this->samplingRate = DEFAULT_SAMPLERATE;
    this->fir1 = new FIR();
    this->fir2 = new FIR();
    this->waveBuffer1 = new WaveBuffer(2, 0x1000);
    this->waveBuffer2 = new WaveBuffer(2, 0x1000);
    this->buffer = new float[0x7e0];

    if (unknown1 == 2) {
        this->fir1->LoadCoefficients(POLYPHASE_COEFFICIENTS_2, sizeof(POLYPHASE_COEFFICIENTS_2) / sizeof(float), 1008);
        this->fir2->LoadCoefficients(POLYPHASE_COEFFICIENTS_2, sizeof(POLYPHASE_COEFFICIENTS_2) / sizeof(float), 1008);
    } else { // if (unknown1 < 2)
        this->fir1->LoadCoefficients(POLYPHASE_COEFFICIENTS_OTHER, sizeof(POLYPHASE_COEFFICIENTS_OTHER) / sizeof(float), 1008);
        this->fir2->LoadCoefficients(POLYPHASE_COEFFICIENTS_OTHER, sizeof(POLYPHASE_COEFFICIENTS_OTHER) / sizeof(float), 1008);
    }
}

Polyphase::~Polyphase() {
    delete this->fir1;
    delete this->fir2;
    delete this->waveBuffer1;
    delete this->waveBuffer2;
    delete[] this->buffer;
}

uint32_t Polyphase::GetLatency() {
    return 63;
}

uint32_t Polyphase::Process(float *samples, uint32_t size) {
    if (this->waveBuffer1->PushSamples(samples, size)) {
        while (this->waveBuffer1->GetBufferOffset() >= 1008) {
            if (this->waveBuffer1->PopSamples(this->buffer, 1008, false) == 1008) {
                this->fir1->FilterSamplesInterleaved(this->buffer, 1008, 2);
                this->fir2->FilterSamplesInterleaved(this->buffer + 1, 1008, 2);
                this->waveBuffer2->PushSamples(this->buffer, 1008);
            }
        }

        if (this->waveBuffer2->GetBufferOffset() < size) {
            return 0;
        }

        this->waveBuffer2->PopSamples(samples, size, true);
    }

    return size;
}

void Polyphase::Reset() {
    this->fir1->Reset();
    this->fir2->Reset();
    this->waveBuffer1->Reset();
    this->waveBuffer2->Reset();
}

void Polyphase::SetSamplingRate(uint32_t samplingRate) {
    if (this->samplingRate != samplingRate) {
        this->samplingRate = samplingRate;
    }
}

