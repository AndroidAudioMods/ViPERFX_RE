/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/android/media/audio/eraser/IEraserCallback.aidl
 */
#include "aidl/android/media/audio/eraser/IEraserCallback.h"

#include <android/binder_parcel_utils.h>
#include <aidl/android/media/audio/eraser/BnEraserCallback.h>
#include <aidl/android/media/audio/eraser/BpEraserCallback.h>

namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace eraser {
static binder_status_t _aidl_android_media_audio_eraser_IEraserCallback_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnEraserCallback> _aidl_impl = std::static_pointer_cast<BnEraserCallback>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*onClassifierUpdate*/): {
      int32_t in_soundSourceId;
      ::aidl::android::media::audio::eraser::ClassificationMetadataList in_metadata;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_soundSourceId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_metadata);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onClassifierUpdate(in_soundSourceId, in_metadata);
      _aidl_ret_status = STATUS_OK;
      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_android_media_audio_eraser_IEraserCallback_clazz = ::ndk::ICInterface::defineClass(IEraserCallback::descriptor, _aidl_android_media_audio_eraser_IEraserCallback_onTransact);

BpEraserCallback::BpEraserCallback(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpEraserCallback::~BpEraserCallback() {}

::ndk::ScopedAStatus BpEraserCallback::onClassifierUpdate(int32_t in_soundSourceId, const ::aidl::android::media::audio::eraser::ClassificationMetadataList& in_metadata) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_soundSourceId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_metadata);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*onClassifierUpdate*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IEraserCallback::getDefaultImpl()) {
    _aidl_status = IEraserCallback::getDefaultImpl()->onClassifierUpdate(in_soundSourceId, in_metadata);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
// Source for BnEraserCallback
BnEraserCallback::BnEraserCallback() {}
BnEraserCallback::~BnEraserCallback() {}
::ndk::SpAIBinder BnEraserCallback::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_android_media_audio_eraser_IEraserCallback_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markVintfStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IEraserCallback
const char* IEraserCallback::descriptor = "android.media.audio.eraser.IEraserCallback";
IEraserCallback::IEraserCallback() {}
IEraserCallback::~IEraserCallback() {}


std::shared_ptr<IEraserCallback> IEraserCallback::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_android_media_audio_eraser_IEraserCallback_clazz)) {
    #if __ANDROID_API__ >= 31
    const AIBinder_Class* originalClass = AIBinder_getClass(binder.get());
    if (originalClass == nullptr) return nullptr;
    if (0 == strcmp(AIBinder_Class_getDescriptor(originalClass), descriptor)) {
      return ::ndk::SharedRefBase::make<BpEraserCallback>(binder);
    }
    #endif
    return nullptr;
  }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IEraserCallback>(interface);
  }
  return ::ndk::SharedRefBase::make<BpEraserCallback>(binder);
}

binder_status_t IEraserCallback::writeToParcel(AParcel* parcel, const std::shared_ptr<IEraserCallback>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IEraserCallback::readFromParcel(const AParcel* parcel, std::shared_ptr<IEraserCallback>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IEraserCallback::fromBinder(binder);
  return STATUS_OK;
}
bool IEraserCallback::setDefaultImpl(const std::shared_ptr<IEraserCallback>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IEraserCallback::default_impl);
  if (impl) {
    IEraserCallback::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IEraserCallback>& IEraserCallback::getDefaultImpl() {
  return IEraserCallback::default_impl;
}
std::shared_ptr<IEraserCallback> IEraserCallback::default_impl = nullptr;
::ndk::ScopedAStatus IEraserCallbackDefault::onClassifierUpdate(int32_t /*in_soundSourceId*/, const ::aidl::android::media::audio::eraser::ClassificationMetadataList& /*in_metadata*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IEraserCallbackDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IEraserCallbackDefault::isRemote() {
  return false;
}
}  // namespace eraser
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
