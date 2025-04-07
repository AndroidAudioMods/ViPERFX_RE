/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/android/media/audio/eraser/IEraserCallback.aidl
 */
#pragma once

#include "aidl/android/media/audio/eraser/IEraserCallback.h"

#include <android/binder_ibinder.h>
#include <cassert>

#ifndef __BIONIC__
#ifndef __assert2
#define __assert2(a,b,c,d) ((void)0)
#endif
#endif

namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace eraser {
class BnEraserCallback : public ::ndk::BnCInterface<IEraserCallback> {
public:
  BnEraserCallback();
  virtual ~BnEraserCallback();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
class IEraserCallbackDelegator : public BnEraserCallback {
public:
  explicit IEraserCallbackDelegator(const std::shared_ptr<IEraserCallback> &impl) : _impl(impl) {
  }

  ::ndk::ScopedAStatus onClassifierUpdate(int32_t in_soundSourceId, const ::aidl::android::media::audio::eraser::ClassificationMetadataList& in_metadata) override {
    return _impl->onClassifierUpdate(in_soundSourceId, in_metadata);
  }
protected:
private:
  std::shared_ptr<IEraserCallback> _impl;
};

}  // namespace eraser
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
