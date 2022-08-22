//
// Created by mart on 7/25/21.
//

#include "ProcessUnit_FX.h"
#include "Effect.h"
#include "constants.h"

ProcessUnit_FX::ProcessUnit_FX() {
    v4a_print(ANDROID_LOG_INFO, "Welcome to ViPER4Android Reworked driver[SQ]");
    v4a_printf(ANDROID_LOG_INFO, "Current version is %s %s", VERSION_STRING, VERSION_CODENAME);
}

ProcessUnit_FX::~ProcessUnit_FX() {

}

int32_t
ProcessUnit_FX::command(uint32_t cmdCode, uint32_t cmdSize, void *pCmdData, uint32_t *replySize, void *pReplyData) {
    // TODO
    return -1;
}

void ProcessUnit_FX::processBuffer(float *buffer, int frameSize) {
    // TODO
}

void ProcessUnit_FX::DispatchCommand(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6,
                                     int param_7) {
    // TODO
}

void ProcessUnit_FX::ResetAllEffects() {
    // TODO
}
