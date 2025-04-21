/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioDeviceDescription.aidl
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
#include <aidl/android/media/audio/common/AudioDeviceType.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class AudioDeviceDescription {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  ::aidl::android::media::audio::common::AudioDeviceType type = ::aidl::android::media::audio::common::AudioDeviceType::NONE;
  std::string connection;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const AudioDeviceDescription& _rhs) const {
    return std::tie(type, connection) == std::tie(_rhs.type, _rhs.connection);
  }
  inline bool operator<(const AudioDeviceDescription& _rhs) const {
    return std::tie(type, connection) < std::tie(_rhs.type, _rhs.connection);
  }
  inline bool operator!=(const AudioDeviceDescription& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AudioDeviceDescription& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AudioDeviceDescription& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AudioDeviceDescription& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  static const char* CONNECTION_ANALOG;
  static const char* CONNECTION_BT_A2DP;
  static const char* CONNECTION_BT_LE;
  static const char* CONNECTION_BT_SCO;
  static const char* __attribute__((deprecated("Bus devices are attached, and must be represented using `{IN|OUT}_BUS` type + empty connection. Bus connection. Mostly used in automotive scenarios."))) CONNECTION_BUS;
  static const char* CONNECTION_HDMI;
  static const char* CONNECTION_HDMI_ARC;
  static const char* CONNECTION_HDMI_EARC;
  static const char* CONNECTION_IP_V4;
  static const char* CONNECTION_SPDIF;
  static const char* CONNECTION_WIRELESS;
  static const char* CONNECTION_USB;
  static const char* CONNECTION_VIRTUAL;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "AudioDeviceDescription{";
    _aidl_os << "type: " << ::android::internal::ToString(type);
    _aidl_os << ", connection: " << ::android::internal::ToString(connection);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
