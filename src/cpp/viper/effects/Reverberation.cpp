#include "Reverberation.h"
#include "../constants.h"

Reverberation::Reverberation() {
    this->roomsize = 0.f;
    this->width = 0.f;
    this->damp = 0.f;
    this->wet = 0.f;
    this->dry = 0.5f;

    this->model.SetRoomSize(0.f);
    this->model.SetWidth(0.f);
    this->model.SetDamp(0.f);
    this->model.SetWet(0.f);
    this->model.SetDry(0.5f);

    this->samplerate = DEFAULT_SAMPLERATE;
    this->enabled = false;
}

void Reverberation::Reset() {
    this->model.Reset();
}

void Reverberation::Process(float *buffer, uint32_t size) {
    if (this->enabled) {
        this->model.ProcessReplace(buffer, &buffer[1], size);
    }
}

void Reverberation::SetEnable(bool enable) {
    if (!this->enabled && enable) {
        Reset();
    }
    this->enabled = enable;
}

void Reverberation::SetRoomSize(float value) {
    this->roomsize = value;
    this->model.SetRoomSize(value);
}

void Reverberation::SetDamp(float value) {
    this->damp = value;
    this->model.SetDamp(value);
}

void Reverberation::SetWet(float value) {
    this->wet = value;
    this->model.SetWet(value);
}

void Reverberation::SetDry(float value) {
    this->dry = value;
    this->model.SetDry(value);
}

void Reverberation::SetWidth(float value) {
    this->width = value;
    this->model.SetWidth(value);
}

void Reverberation::SetSamplingRate(uint32_t value) {
    this->samplerate = value;
    this->model.Reset();
}

Reverberation::~Reverberation() {

}
