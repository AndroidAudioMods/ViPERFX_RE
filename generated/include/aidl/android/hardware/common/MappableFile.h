/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/android/hardware/common/MappableFile.aidl
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
namespace common {
class MappableFile {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int64_t length = 0L;
  int32_t prot = 0;
  ::ndk::ScopedFileDescriptor fd;
  int64_t offset = 0L;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const MappableFile& _rhs) const {
    return std::tie(length, prot, fd, offset) == std::tie(_rhs.length, _rhs.prot, _rhs.fd, _rhs.offset);
  }
  inline bool operator<(const MappableFile& _rhs) const {
    return std::tie(length, prot, fd, offset) < std::tie(_rhs.length, _rhs.prot, _rhs.fd, _rhs.offset);
  }
  inline bool operator!=(const MappableFile& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const MappableFile& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const MappableFile& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const MappableFile& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "MappableFile{";
    _aidl_os << "length: " << ::android::internal::ToString(length);
    _aidl_os << ", prot: " << ::android::internal::ToString(prot);
    _aidl_os << ", fd: " << ::android::internal::ToString(fd);
    _aidl_os << ", offset: " << ::android::internal::ToString(offset);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace common
}  // namespace hardware
}  // namespace android
}  // namespace aidl
