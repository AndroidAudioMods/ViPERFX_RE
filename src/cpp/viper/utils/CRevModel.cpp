#include "CRevModel.h"

CRevModel::CRevModel() {
    buffers[0] = new float[1116];
    buffers[1] = new float[1139];
    buffers[2] = new float[1188];
    buffers[3] = new float[1211];
    buffers[4] = new float[1277];
    buffers[5] = new float[1300];
    buffers[6] = new float[1356];
    buffers[7] = new float[1379];
    buffers[8] = new float[1356];
    buffers[9] = new float[1445];
    buffers[10] = new float[1491];
    buffers[11] = new float[1514];
    buffers[12] = new float[1557];
    buffers[13] = new float[1580];
    buffers[14] = new float[1617];
    buffers[15] = new float[1640];
    buffers[16] = new float[556];
    buffers[17] = new float[579];
    buffers[18] = new float[441];
    buffers[19] = new float[464];
    buffers[20] = new float[341];
    buffers[21] = new float[364];
    buffers[22] = new float[225];
    buffers[23] = new float[248];

    combL[0].SetBuffer(buffers[0], 1116);
    combR[0].SetBuffer(buffers[1], 1139);
    combL[1].SetBuffer(buffers[2], 1188);
    combR[1].SetBuffer(buffers[3], 1211);
    combL[2].SetBuffer(buffers[4], 1277);
    combR[2].SetBuffer(buffers[5], 1300);
    combL[3].SetBuffer(buffers[6], 1356);
    combR[3].SetBuffer(buffers[7], 1379);
    combL[4].SetBuffer(buffers[8], 1356);
    combR[4].SetBuffer(buffers[9], 1445);
    combL[5].SetBuffer(buffers[10], 1491);
    combR[5].SetBuffer(buffers[11], 1514);
    combL[6].SetBuffer(buffers[12], 1557);
    combR[6].SetBuffer(buffers[13], 1580);
    combL[7].SetBuffer(buffers[14], 1617);
    combR[7].SetBuffer(buffers[15], 1640);
    allpassL[0].SetBuffer(buffers[16], 556);
    allpassR[0].SetBuffer(buffers[17], 579);
    allpassL[1].SetBuffer(buffers[18], 441);
    allpassR[1].SetBuffer(buffers[19], 464);
    allpassL[2].SetBuffer(buffers[20], 341);
    allpassR[2].SetBuffer(buffers[21], 364);
    allpassL[3].SetBuffer(buffers[22], 225);
    allpassR[3].SetBuffer(buffers[23], 248);

    allpassL[0].SetFeedback(0.5f);
    allpassR[0].SetFeedback(0.5f);
    allpassL[1].SetFeedback(0.5f);
    allpassR[1].SetFeedback(0.5f);
    allpassL[2].SetFeedback(0.5f);
    allpassR[2].SetFeedback(0.5f);
    allpassL[3].SetFeedback(0.5f);
    allpassR[3].SetFeedback(0.5f);

    SetWet(1 / 3.f);
    SetRoomSize(0.5f);
    SetDry(0.f);
    SetDamp(0.5f);
    SetWidth(1.f);
    SetMode(0.f);

    Mute();
}

CRevModel::~CRevModel() {
    for (int i = 0; i < 24; i++) {
        delete[] buffers[i];
    }
}

void CRevModel::Mute() {
    if (mode == 1) {
        return;
    }

    for (int i = 0; i < 8; i++) {
        combL[i].Mute();
        combR[i].Mute();
    }
    for (int i = 0; i < 4; i++) {
        allpassL[i].Mute();
        allpassR[i].Mute();
    }
}

void CRevModel::ProcessReplace(float *bufL, float *bufR, uint32_t size) {
    for (int idx = 0; idx < size; idx++) {
        float outL = 0.f;
        float outR = 0.f;
        float input = (*bufL + *bufR) * gain;

        for (int i = 0; i < 8; i++) {
            outL += combL[i].Process(input);
            outR += combR[i].Process(input);
        }

        for (int i = 0; i < 4; i++) {
            outL = allpassL[i].Process(outL);
            outR = allpassR[i].Process(outR);
        }

        *bufL = outL * wet1 + outR * wet2 + *bufL * dry;
        *bufR = outR * wet1 + outL * wet2 + *bufR * dry;

        bufL += 1;
        bufR += 1;
    }
}

void CRevModel::UpdateCoeffs() {
    wet1 = wet * (width / 2.f + 0.5f);
    wet2 = wet * ((1.f - width) / 2.f);

    if (mode == 1) {
        roomsize1 = 1.f;
        damp1 = 0.f;
        gain = 0.f;
    } else {
        roomsize1 = roomsize;
        damp1 = damp;
        gain = 0.015f;
    }

    for (int i = 0; i < 8; i++) {
        combL[i].SetFeedback(roomsize1);
        combR[i].SetFeedback(roomsize1);
    }

    for (int i = 0; i < 8; i++) {
        combL[i].SetDamp(damp1);
        combR[i].SetDamp(damp1);
    }
}

void CRevModel::Reset() {
    for (int i = 0; i < 8; i++) {
        combL[i].Mute();
        combR[i].Mute();
    }

    for (int i = 0; i < 4; i++) {
        allpassL[i].Mute();
        allpassR[i].Mute();
    }
}

void CRevModel::SetRoomSize(float value) {
    roomsize = (value * 0.28f) + 0.7f;
    UpdateCoeffs();
}

void CRevModel::SetDamp(float value) {
    damp = value * 0.4f;
    UpdateCoeffs();
}

void CRevModel::SetWet(float value) {
    wet = value * 3.f;
    UpdateCoeffs();
}

void CRevModel::SetDry(float value) {
    dry = value * 2.f;
}

void CRevModel::SetWidth(float value) {
    width = value;
    UpdateCoeffs();
}

void CRevModel::SetMode(int value) {
    mode = value;
    UpdateCoeffs();
}

float CRevModel::GetRoomSize() {
    return (roomsize - 0.7f) / 0.28f;
}

float CRevModel::GetDamp() {
    return damp / 0.4f;
}

float CRevModel::GetWet() {
    return wet / 3.f;
}

float CRevModel::GetDry() {
    return dry / 2.f;
}

float CRevModel::GetWidth() {
    return width;
}

int CRevModel::GetMode() {
    if (mode == 1) {
        return 1.f;
    } else {
        return 0.f;
    }
}
