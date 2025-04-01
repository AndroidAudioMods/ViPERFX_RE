#include "Reverberation.h"
#include "../constants.h"

Reverberation::Reverberation() {
    this->model.SetRoomSize(0.0);
    this->model.SetWidth(0.0);
    this->model.SetDamp(0.0);
    this->model.SetWet(0.0);
    this->model.SetDry(0.5);
    this->model.Reset();

    this->enable = false;
}

void Reverberation::Process(float *buffer, uint32_t size) {
    if (this->enable) {
        this->model.ProcessReplace(buffer, buffer + 1, size);
    }
}

void Reverberation::Reset() {
    this->model.Reset();
}

void Reverberation::SetDamp(float value) {
    this->model.SetDamp(value);
}

void Reverberation::SetDry(float value) {
    this->model.SetDry(value);
}

void Reverberation::SetEnable(bool enable) {
    if (this->enable != enable) {
        if (!this->enable) {
            Reset();
        }
        this->enable = enable;
    }
}

void Reverberation::SetRoomSize(float value) {
    this->model.SetRoomSize(value);
}

void Reverberation::SetWet(float value) {
    this->model.SetWet(value);
}

void Reverberation::SetWidth(float value) {
    this->model.SetWidth(value);
}