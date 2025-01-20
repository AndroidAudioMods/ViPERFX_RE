#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "v4a.h"
#include "log.h"
#include "ViperContext.h"

int v4a_open(const char *uri, remote_handle64 *handle) {
    *handle = (remote_handle64) new ViperContext();
    return 0;
}

int v4a_close(remote_handle64 handle) {
    if (handle) {
        delete reinterpret_cast<ViperContext *>(handle);
    }
    return 0;
}

int32_t v4a_command(remote_handle64 handle, uint32_t cmdCode, const uint8_t *pCmdData, int cmdSize, uint8_t *pReplyData, int replySize, uint32_t *pReplySize) {
    return reinterpret_cast<ViperContext *>(handle)->handleCommand(cmdCode, cmdSize, (void *) pCmdData, pReplySize, (void *) pReplyData);
}

int32_t v4a_process(remote_handle64 handle, const uint8_t *inPcm, int inPcmLen, uint8_t *outPcm, int outPcmLen, uint32_t frameCount) {
    audio_buffer_t in = {
        .frameCount = frameCount,
        .raw = (void *) inPcm,
    };
    audio_buffer_t out = {
        .frameCount = frameCount,
        .raw = (void *) outPcm,
    };
    return reinterpret_cast<ViperContext *>(handle)->process(&in, &out);
}
