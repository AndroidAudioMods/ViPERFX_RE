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
    if (ashmem_create_region == nullptr) {
        ALOGE("Failed to load symbol ashmem_create_region from libcutils.so");
        goto exit;
    }

    ashmem_set_prot_region = dlsym(libcutils, "ashmem_set_prot_region");
    if (ashmem_set_prot_region == nullptr) {
        ALOGE("Failed to load symbol ashmem_set_prot_region from libcutils.so");
        goto exit;
    }

    native_handle_create = dlsym(libcutils, "native_handle_create");
    if (native_handle_create == nullptr) {
        ALOGE("Failed to load symbol native_handle_create from libcutils.so");
        goto exit;
    }

    native_handle_close = dlsym(libcutils, "native_handle_close");
    if (native_handle_close == nullptr) {
        ALOGE("Failed to load symbol native_handle_close from libcutils.so");
        goto exit;
    }

    native_handle_delete = dlsym(libcutils, "native_handle_delete");
    if (native_handle_delete == nullptr) {
        ALOGE("Failed to load symbol native_handle_delete from libcutils.so");
        goto exit;
    }

    ALOGD("ashmem_create_region: %p", ashmem_create_region);
    ALOGD("ashmem_set_prot_region: %p", ashmem_set_prot_region);
    ALOGD("native_handle_create: %p", native_handle_create);
    ALOGD("native_handle_close: %p", native_handle_close);
    ALOGD("native_handle_delete: %p", native_handle_delete);

exit:
    dlclose(libcutils);
}

static void init_libfmq() {
    void *libfmq = dlopen("libfmq.so", RTLD_NOW);
    if (libfmq == nullptr) {
        ALOGE("Failed to load libfmq.so");
        return;
    }

    _ZN7android8hardware7details5checkEbPKc = dlsym(libfmq, "_ZN7android8hardware7details5checkEbPKc");
    if (_ZN7android8hardware7details5checkEbPKc == nullptr) {
        ALOGE("Failed to load symbol _ZN7android8hardware7details5checkEbPKc from libfmq.so");
        goto exit;
    }

    // ndk variant, real symbol: _ZN7android8hardware7details8logErrorERKNSt3__112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE
    _ZN7android8hardware7details8logErrorERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE = dlsym(libfmq, "_ZN7android8hardware7details8logErrorERKNSt3__112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE");
    if (_ZN7android8hardware7details8logErrorERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE == nullptr) {
        ALOGE("Failed to load symbol _ZN7android8hardware7details8logErrorERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE from libfmq.so");
        goto exit;
    }

    // ndk variant, real symbol: _ZN7android8hardware9EventFlag15createEventFlagEPNSt3__16atomicIjEEPPS1_
    _ZN7android8hardware9EventFlag15createEventFlagEPNSt6__ndk16atomicIjEEPPS1_ = dlsym(libfmq, "_ZN7android8hardware9EventFlag15createEventFlagEPNSt3__16atomicIjEEPPS1_");
    if (_ZN7android8hardware9EventFlag15createEventFlagEPNSt6__ndk16atomicIjEEPPS1_ == nullptr) {
        ALOGE("Failed to load symbol _ZN7android8hardware9EventFlag15createEventFlagEPNSt3__16atomicIjEEPPS1_ from libfmq.so");
        goto exit;
    }

    _ZN7android8hardware9EventFlag15deleteEventFlagEPPS1_ = dlsym(libfmq, "_ZN7android8hardware9EventFlag15deleteEventFlagEPPS1_");
    if (_ZN7android8hardware9EventFlag15deleteEventFlagEPPS1_ == nullptr) {
        ALOGE("Failed to load symbol _ZN7android8hardware9EventFlag15deleteEventFlagEPPS1_ from libfmq.so");
        goto exit;
    }

    ALOGD("_ZN7android8hardware7details5checkEbPKc: %p", _ZN7android8hardware7details5checkEbPKc);
    ALOGD("_ZN7android8hardware7details8logErrorERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE: %p", _ZN7android8hardware7details8logErrorERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE);
    ALOGD("_ZN7android8hardware9EventFlag15createEventFlagEPNSt6__ndk16atomicIjEEPPS1_: %p", _ZN7android8hardware9EventFlag15createEventFlagEPNSt6__ndk16atomicIjEEPPS1_);
    ALOGD("_ZN7android8hardware9EventFlag15deleteEventFlagEPPS1_: %p", _ZN7android8hardware9EventFlag15deleteEventFlagEPPS1_);

exit:
    dlclose(libfmq);
}

__attribute__((constructor))
void shim_init() {
    init_libcutils();
    init_libfmq();
}