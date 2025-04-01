/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Spatializer.aidl
 */
#include "aidl/android/hardware/audio/effect/Spatializer.h"

#include <android/binder_parcel_utils.h>

namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
const char* Spatializer::descriptor = "android.hardware.audio.effect.Spatializer";

binder_status_t Spatializer::readFromParcel(const AParcel* _parcel) {
  binder_status_t _aidl_ret_status;
  int32_t _aidl_tag;
  if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_tag)) != STATUS_OK) return _aidl_ret_status;
  switch (static_cast<Tag>(_aidl_tag)) {
  case vendor: {
    ::aidl::android::hardware::audio::effect::VendorExtension _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::VendorExtension>) {
      set<vendor>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<vendor>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case supportedChannelLayout: {
    std::vector<::aidl::android::media::audio::common::AudioChannelLayout> _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<std::vector<::aidl::android::media::audio::common::AudioChannelLayout>>) {
      set<supportedChannelLayout>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<supportedChannelLayout>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case spatializationLevel: {
    ::aidl::android::media::audio::common::Spatialization::Level _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::media::audio::common::Spatialization::Level>) {
      set<spatializationLevel>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<spatializationLevel>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case spatializationMode: {
    ::aidl::android::media::audio::common::Spatialization::Mode _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::media::audio::common::Spatialization::Mode>) {
      set<spatializationMode>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<spatializationMode>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case headTrackingSensorId: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<headTrackingSensorId>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<headTrackingSensorId>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case headTrackingMode: {
    ::aidl::android::media::audio::common::HeadTracking::Mode _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::media::audio::common::HeadTracking::Mode>) {
      set<headTrackingMode>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<headTrackingMode>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case headTrackingConnectionMode: {
    ::aidl::android::media::audio::common::HeadTracking::ConnectionMode _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::media::audio::common::HeadTracking::ConnectionMode>) {
      set<headTrackingConnectionMode>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<headTrackingConnectionMode>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case headTrackingSensorData: {
    ::aidl::android::media::audio::common::HeadTracking::SensorData _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::media::audio::common::HeadTracking::SensorData>) {
      set<headTrackingSensorData>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<headTrackingSensorData>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case spatializedChannelLayout: {
    std::vector<::aidl::android::media::audio::common::AudioChannelLayout> _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<std::vector<::aidl::android::media::audio::common::AudioChannelLayout>>) {
      set<spatializedChannelLayout>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<spatializedChannelLayout>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  }
  return STATUS_BAD_VALUE;
}
binder_status_t Spatializer::writeToParcel(AParcel* _parcel) const {
  binder_status_t _aidl_ret_status = ::ndk::AParcel_writeData(_parcel, static_cast<int32_t>(getTag()));
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;
  switch (getTag()) {
  case vendor: return ::ndk::AParcel_writeData(_parcel, get<vendor>());
  case supportedChannelLayout: return ::ndk::AParcel_writeData(_parcel, get<supportedChannelLayout>());
  case spatializationLevel: return ::ndk::AParcel_writeData(_parcel, get<spatializationLevel>());
  case spatializationMode: return ::ndk::AParcel_writeData(_parcel, get<spatializationMode>());
  case headTrackingSensorId: return ::ndk::AParcel_writeData(_parcel, get<headTrackingSensorId>());
  case headTrackingMode: return ::ndk::AParcel_writeData(_parcel, get<headTrackingMode>());
  case headTrackingConnectionMode: return ::ndk::AParcel_writeData(_parcel, get<headTrackingConnectionMode>());
  case headTrackingSensorData: return ::ndk::AParcel_writeData(_parcel, get<headTrackingSensorData>());
  case spatializedChannelLayout: return ::ndk::AParcel_writeData(_parcel, get<spatializedChannelLayout>());
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
const char* Spatializer::Id::descriptor = "android.hardware.audio.effect.Spatializer.Id";

binder_status_t Spatializer::Id::readFromParcel(const AParcel* _parcel) {
  binder_status_t _aidl_ret_status;
  int32_t _aidl_tag;
  if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_tag)) != STATUS_OK) return _aidl_ret_status;
  switch (static_cast<Tag>(_aidl_tag)) {
  case vendorExtensionTag: {
    ::aidl::android::hardware::audio::effect::VendorExtension _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::VendorExtension>) {
      set<vendorExtensionTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<vendorExtensionTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case commonTag: {
    ::aidl::android::hardware::audio::effect::Spatializer::Tag _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::Spatializer::Tag>) {
      set<commonTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<commonTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  }
  return STATUS_BAD_VALUE;
}
binder_status_t Spatializer::Id::writeToParcel(AParcel* _parcel) const {
  binder_status_t _aidl_ret_status = ::ndk::AParcel_writeData(_parcel, static_cast<int32_t>(getTag()));
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;
  switch (getTag()) {
  case vendorExtensionTag: return ::ndk::AParcel_writeData(_parcel, get<vendorExtensionTag>());
  case commonTag: return ::ndk::AParcel_writeData(_parcel, get<commonTag>());
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
