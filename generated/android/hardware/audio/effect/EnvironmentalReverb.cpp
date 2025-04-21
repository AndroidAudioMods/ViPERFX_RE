/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/EnvironmentalReverb.aidl
 */
#include "aidl/android/hardware/audio/effect/EnvironmentalReverb.h"

#include <android/binder_parcel_utils.h>

namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
const char* EnvironmentalReverb::descriptor = "android.hardware.audio.effect.EnvironmentalReverb";

binder_status_t EnvironmentalReverb::readFromParcel(const AParcel* _parcel) {
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
  case roomLevelMb: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<roomLevelMb>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<roomLevelMb>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case roomHfLevelMb: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<roomHfLevelMb>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<roomHfLevelMb>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case decayTimeMs: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<decayTimeMs>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<decayTimeMs>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case decayHfRatioPm: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<decayHfRatioPm>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<decayHfRatioPm>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case reflectionsLevelMb: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<reflectionsLevelMb>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<reflectionsLevelMb>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case reflectionsDelayMs: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<reflectionsDelayMs>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<reflectionsDelayMs>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case levelMb: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<levelMb>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<levelMb>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case delayMs: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<delayMs>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<delayMs>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case diffusionPm: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<diffusionPm>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<diffusionPm>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case densityPm: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<densityPm>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<densityPm>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case bypass: {
    bool _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<bool>) {
      set<bypass>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<bypass>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  }
  return STATUS_BAD_VALUE;
}
binder_status_t EnvironmentalReverb::writeToParcel(AParcel* _parcel) const {
  binder_status_t _aidl_ret_status = ::ndk::AParcel_writeData(_parcel, static_cast<int32_t>(getTag()));
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;
  switch (getTag()) {
  case vendor: return ::ndk::AParcel_writeData(_parcel, get<vendor>());
  case roomLevelMb: return ::ndk::AParcel_writeData(_parcel, get<roomLevelMb>());
  case roomHfLevelMb: return ::ndk::AParcel_writeData(_parcel, get<roomHfLevelMb>());
  case decayTimeMs: return ::ndk::AParcel_writeData(_parcel, get<decayTimeMs>());
  case decayHfRatioPm: return ::ndk::AParcel_writeData(_parcel, get<decayHfRatioPm>());
  case reflectionsLevelMb: return ::ndk::AParcel_writeData(_parcel, get<reflectionsLevelMb>());
  case reflectionsDelayMs: return ::ndk::AParcel_writeData(_parcel, get<reflectionsDelayMs>());
  case levelMb: return ::ndk::AParcel_writeData(_parcel, get<levelMb>());
  case delayMs: return ::ndk::AParcel_writeData(_parcel, get<delayMs>());
  case diffusionPm: return ::ndk::AParcel_writeData(_parcel, get<diffusionPm>());
  case densityPm: return ::ndk::AParcel_writeData(_parcel, get<densityPm>());
  case bypass: return ::ndk::AParcel_writeData(_parcel, get<bypass>());
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
const char* EnvironmentalReverb::Id::descriptor = "android.hardware.audio.effect.EnvironmentalReverb.Id";

binder_status_t EnvironmentalReverb::Id::readFromParcel(const AParcel* _parcel) {
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
    ::aidl::android::hardware::audio::effect::EnvironmentalReverb::Tag _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::EnvironmentalReverb::Tag>) {
      set<commonTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<commonTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  }
  return STATUS_BAD_VALUE;
}
binder_status_t EnvironmentalReverb::Id::writeToParcel(AParcel* _parcel) const {
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
