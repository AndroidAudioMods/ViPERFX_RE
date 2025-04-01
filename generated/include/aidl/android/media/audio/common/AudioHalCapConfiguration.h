/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/iscle/Android/Sdk/build-tools/35.0.1/aidl --lang=ndk -o generated -h generated/include --structured --stability=vintf --min_sdk_version=31 -I hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/ -I hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/ -I hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/ -I system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/ system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioHalCapConfiguration.aidl
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
#include <aidl/android/media/audio/common/AudioHalCapParameter.h>
#include <aidl/android/media/audio/common/AudioHalCapRule.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::media::audio::common {
class AudioHalCapRule;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class AudioHalCapConfiguration {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  std::string name;
  ::aidl::android::media::audio::common::AudioHalCapRule rule;
  std::vector<::aidl::android::media::audio::common::AudioHalCapParameter> parameterSettings;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const AudioHalCapConfiguration& _rhs) const {
    return std::tie(name, rule, parameterSettings) == std::tie(_rhs.name, _rhs.rule, _rhs.parameterSettings);
  }
  inline bool operator<(const AudioHalCapConfiguration& _rhs) const {
    return std::tie(name, rule, parameterSettings) < std::tie(_rhs.name, _rhs.rule, _rhs.parameterSettings);
  }
  inline bool operator!=(const AudioHalCapConfiguration& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AudioHalCapConfiguration& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AudioHalCapConfiguration& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AudioHalCapConfiguration& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "AudioHalCapConfiguration{";
    _aidl_os << "name: " << ::android::internal::ToString(name);
    _aidl_os << ", rule: " << ::android::internal::ToString(rule);
    _aidl_os << ", parameterSettings: " << ::android::internal::ToString(parameterSettings);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
