/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/VendorExtension.aidl
 */
#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
class VendorExtension {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  ::ndk::AParcelableHolder extension{::ndk::STABILITY_VINTF};

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const VendorExtension& _rhs) const {
    return std::tie(extension) == std::tie(_rhs.extension);
  }
  inline bool operator<(const VendorExtension& _rhs) const {
    return std::tie(extension) < std::tie(_rhs.extension);
  }
  inline bool operator!=(const VendorExtension& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const VendorExtension& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const VendorExtension& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const VendorExtension& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "VendorExtension{";
    _aidl_os << "extension: " << ::android::internal::ToString(extension);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
