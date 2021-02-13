
#ifndef VIPER_MAIN
#define VIPER_MAIN

#include "util/misc.h"
#include "ProcessUnit_FX.h"

// We don't really care about this file, it's just compat with android API

typedef struct intf {
    int32_t (*process)(effect_handle_t self,
                       audio_buffer_t *inBuffer,
                       audio_buffer_t *outBuffer);
    int32_t (*command)(effect_handle_t self,
                       uint32_t cmdCode,
                       uint32_t cmdSize,
                       void *pCmdData,
                       uint32_t *replySize,
                       void *pReplyData);
    int32_t (*get_descriptor)(effect_handle_t self,
                              effect_descriptor_t *pDescriptor);
    int32_t (*process_reverse)(effect_handle_t self,
                               audio_buffer_t *inBuffer,
                               audio_buffer_t *outBuffer);
} intf;

typedef struct handle {
    intf* interface;
    ProcessUnit_FX* core;
    void* descriptor;
} handle;

extern "C" {
    int EffectRelease(handle *param_1);
    int uuidToString(effect_uuid_s *param_1,char *param_2);
    int EffectCreate(effect_uuid_s *uuid, int sessionId, int ioId, handle *pHandle);
    int EffectGetDescriptor(effect_uuid_s *uuid, effect_descriptor_t *pDescriptor);
    int GetLibraryVersionMain();
    int GetLibraryVersionSub();
    int GetLibraryVersionExt();
    int GetLibraryVersionBuild();
    char * GetLibraryVersionCodename();
};

#endif
