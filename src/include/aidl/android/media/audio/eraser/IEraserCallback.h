/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/android/media/audio/eraser/IEraserCallback.aidl
 */
#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#include <aidl/android/media/audio/eraser/ClassificationMetadataList.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::media::audio::eraser {
class ClassificationMetadataList;
}  // namespace aidl::android::media::audio::eraser
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace eraser {
class IEraserCallbackDelegator;

class IEraserCallback : public ::ndk::ICInterface {
public:
  typedef IEraserCallbackDelegator DefaultDelegator;
  static const char* descriptor;
  IEraserCallback();
  virtual ~IEraserCallback();

  static constexpr uint32_t TRANSACTION_onClassifierUpdate = FIRST_CALL_TRANSACTION + 0;

  static std::shared_ptr<IEraserCallback> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IEraserCallback>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IEraserCallback>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IEraserCallback>& impl);
  static const std::shared_ptr<IEraserCallback>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onClassifierUpdate(int32_t in_soundSourceId, const ::aidl::android::media::audio::eraser::ClassificationMetadataList& in_metadata) = 0;
private:
  static std::shared_ptr<IEraserCallback> default_impl;
};
class IEraserCallbackDefault : public IEraserCallback {
public:
  ::ndk::ScopedAStatus onClassifierUpdate(int32_t in_soundSourceId, const ::aidl::android::media::audio::eraser::ClassificationMetadataList& in_metadata) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace eraser
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
