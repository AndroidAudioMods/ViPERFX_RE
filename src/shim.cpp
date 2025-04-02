/**
 * Shims for the "hidden" api, not found in the Android NDK.
 *
 * The symbols are compiled with the NDK, but the real Android ones have
 * a slightly different mangled name.
*/

#include <log/log.h>
#include <dlfcn.h>

// libcutils
void *ashmem_create_region;
void *ashmem_set_prot_region;
void *native_handle_create;
void *native_handle_delete;
void *native_handle_close;

// libfmq
void *_ZN7android8hardware7details5checkEbPKc;
void *_ZN7android8hardware7details8logErrorERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE; // ndk
void *_ZN7android8hardware9EventFlag15createEventFlagEPNSt6__ndk16atomicIjEEPPS1_; // ndk
void *_ZN7android8hardware9EventFlag15deleteEventFlagEPPS1_;

static void init_libcutils() {
    void *libcutils = dlopen("libcutils.so", RTLD_NOW);
    if (libcutils == nullptr) {
        ALOGE("Failed to load libcutils.so");
        return;
    }

    ashmem_create_region = dlsym(libcutils, "ashmem_create_region");
    ashmem_set_prot_region = dlsym(libcutils, "ashmem_set_prot_region");

    native_handle_create = dlsym(libcutils, "native_handle_create");
    native_handle_close = dlsym(libcutils, "native_handle_close");
    native_handle_delete = dlsym(libcutils, "native_handle_delete");

    if (ashmem_create_region == nullptr ||
        ashmem_set_prot_region == nullptr ||
        native_handle_create == nullptr ||
        native_handle_close == nullptr ||
        native_handle_delete == nullptr) {
        ALOGE("Failed to load symbols from libcutils.so");
    }

    dlclose(libcutils);
}

static void init_libfmq() {
    void *libfmq = dlopen("libfmq.so", RTLD_NOW);
    if (libfmq == nullptr) {
        ALOGE("Failed to load libfmq.so");
        return;
    }

    _ZN7android8hardware7details5checkEbPKc = dlsym(libfmq, "_ZN7android8hardware7details5checkEbPKc");
    // ndk variant, real symbol: _ZN7android8hardware7details8logErrorERKNSt3__112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE
    _ZN7android8hardware7details8logErrorERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE = dlsym(libfmq, "_ZN7android8hardware7details8logErrorERKNSt3__112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE");
    // ndk variant, real symbol: _ZN7android8hardware9EventFlag15createEventFlagEPNSt3__16atomicIjEEPPS1_
    _ZN7android8hardware9EventFlag15createEventFlagEPNSt6__ndk16atomicIjEEPPS1_ = dlsym(libfmq, "_ZN7android8hardware9EventFlag15createEventFlagEPNSt3__16atomicIjEEPPS1_");
    _ZN7android8hardware9EventFlag15deleteEventFlagEPPS1_ = dlsym(libfmq, "_ZN7android8hardware9EventFlag15deleteEventFlagEPPS1_");

    if (_ZN7android8hardware7details5checkEbPKc == nullptr ||
        _ZN7android8hardware7details8logErrorERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE == nullptr ||
        _ZN7android8hardware9EventFlag15createEventFlagEPNSt6__ndk16atomicIjEEPPS1_ == nullptr ||
        _ZN7android8hardware9EventFlag15deleteEventFlagEPPS1_ == nullptr) {
        ALOGE("Failed to load symbols from libfmq.so");
    }

    dlclose(libfmq);
}

__attribute__((constructor))
void shim_init() {
    ALOGD("shim_init");
    init_libcutils();
    init_libfmq();
    ALOGD("shim_init done");
}