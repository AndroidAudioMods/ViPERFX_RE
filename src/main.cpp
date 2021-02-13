//
// Created by mart on 2/12/21.
//

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "main.h"
#include "effects/Effect.h"
#include "util/misc.h"
#include "ProcessUnit_FX.h"
#include "data.h"

int EffectRelease(handle *param_1) {
    Effect *this_;

    if (param_1 != nullptr) {
        __android_log_print(4,"ViPER4Android_v2","EffectRelease(), Deconstructing ProcessUnit");
        this_ = param_1->field_0x4;
        delete this_;

        free(param_1);
        return OK;
    }
    return EINVAL;
}



// uuidToString(effect_uuid_s const*, char*)

int uuidToString(effect_uuid_s *param_1,char *param_2) {
    sprintf(param_2,"%08x-%04x-%04x-%04x-%02x%02x%02x%02x%02x%02x",
            param_1->field_0x0,
            (uint)param_1->field_0x4,
            (uint)param_1->field_0x6,
            (uint)param_1->field_0x8,
            (uint)param_1->field_0xa,
            (uint)param_1->field_0xb,
            (uint)param_1->field_0xc,
            (uint)param_1->field_0xd,
            (uint)param_1->field_0xe,
            (uint)param_1->field_0xf);
    return OK;
}

int EffectCreate(effect_uuid_s *uuid, int sessionId, int ioId, handle *pHandle) {
    int iVar1;
    handle* ptr;
    ProcessUnit_FX *this_;
    char acStack164 [128];
    int local_24;

    local_24 = __stack_chk_guard;
    __android_log_print(4,"ViPER4Android_v2","Enter EffectCreate()");
    if (uuid == nullptr) {
        __android_log_print(4,"ViPER4Android_v2","EffectCreate(), Error [uuid = nullptr]");
        iVar1 = -0x16;
    }
    else {
        if (pHandle == nullptr) {
            __android_log_print(4,"ViPER4Android_v2","EffectCreate(), Error [pEffect = nullptr]");
            iVar1 = -0x16;
        }
        else {
            uuidToString(uuid, acStack164);
            __android_log_print(4,"ViPER4Android_v2","EffectCreate(), uuid = %s",acStack164);
            iVar1 = memcmp(uuid, &DAT_000d127c, 0x10);
            if (iVar1 == 0) {
                ptr = (handle*)calloc(1,0xc);
                if (ptr == nullptr) {
                    __android_log_print(4,"ViPER4Android_v2",
                                        "EffectCreate(), v4a standard effect, Error [calloc() return nullptr]");
                    iVar1 = -0x16;
                }
                else {
                    __android_log_print(4,"ViPER4Android_v2",

                                        "EffectCreate(), v4a standard effect (normal), Constructing ProcessUnit_FX"
                    );
                    ptr->interface = (intf *)&PTR_LAB_000d0cb0;
                    this_ = new ProcessUnit_FX();
                    ptr->core = this_;
                    if (this_ == nullptr) {
                        __android_log_print(4,"ViPER4Android_v2",

                                            "EffectCreate(), v4a standard effect, Error [new ProcessUnit_FX() return nullptr]"
                        );
                        __android_log_print(4,"ViPER4Android_v2",

                                            "EffectCreate(), v4a standard effect, Error [ProcessUnit_FX construct failed]"
                        );
                        free(ptr);
                        iVar1 = -0x16;
                    }
                    else {
                        ptr->descriptor = &DAT_000d126c;
                        __android_log_print(4,"ViPER4Android_v2","Creating %s",
                                            s_ViPER4Android__2_5_0_4__000d1298);
                        *&pHandle = ptr;
                    }
                }
            }
            else {
                __android_log_print(4,"ViPER4Android_v2","EffectCreate(), Error [effect not found]");
                iVar1 = -2;
            }
        }
    }
    if (local_24 == __stack_chk_guard) {
        return iVar1;
    }
    // WARNING: Subroutine does not return
    __stack_chk_fail();
}



int EffectGetDescriptor(effect_uuid_s *uuid, effect_descriptor_t *pDescriptor) {
    int iVar1;
    char uuidAsString [128];
    int local_24;

    __android_log_print(4, "ViPER4Android_v2", "Enter EffectGetDescriptor()");

    if (uuid == nullptr) {
        __android_log_print(4, "ViPER4Android_v2", "EffectGetDescriptor(), uuid = nullptr");
        return -EINVAL;
    }

    if (pDescriptor == nullptr) {
        __android_log_print(4, "ViPER4Android_v2", "EffectGetDescriptor(), pDescriptor = nullptr");
        return -EINVAL;
    }

    uuidToString(uuid, uuidAsString);
    __android_log_print(4, "ViPER4Android_v2", "EffectGetDescriptor(), uuid = %s", uuidAsString);
    iVar1 = memcmp(uuid, &DAT_000d126c.uuid, 0x10);
    if (iVar1 == 0) {
        memcpy(pDescriptor, &DAT_000d126c, 0xac);
        return OK;
    }

    __android_log_print(4,"ViPER4Android_v2","EffectGetDescriptor(), Error [uuid not found]");
    return -ENOENT;
}


int GetLibraryVersionMain() {
    return 2;
}



int GetLibraryVersionSub() {
    return 5;
}



int GetLibraryVersionExt() {
    return 0;
}



int GetLibraryVersionBuild() {
    return 4;
}



char * GetLibraryVersionCodename() {
    return (char*)"Beautiful";
}
