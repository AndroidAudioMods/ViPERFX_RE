#pragma once

#include <array>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace aidl::android::hardware::audio::effect {
    class Flags {
    public:
        enum class Type : int8_t {
            INSERT = 0,
            AUXILIARY = 1,
            REPLACE = 2,
            PRE_PROC = 3,
            POST_PROC = 4,
        };

        enum class Insert : int8_t {
            ANY = 0,
            FIRST = 1,
            LAST = 2,
            EXCLUSIVE = 3,
        };

        enum class Volume : int8_t {
            NONE = 0,
            CTRL = 1,
            IND = 2,
            MONITOR = 3,
        };

        enum class HardwareAccelerator : int8_t {
            NONE = 0,
            SIMPLE = 1,
            TUNNEL = 2,
        };

        ::aidl::android::hardware::audio::effect::Flags::Type type = ::aidl::android::hardware::audio::effect::Flags::Type::INSERT;
        ::aidl::android::hardware::audio::effect::Flags::Insert insert = ::aidl::android::hardware::audio::effect::Flags::Insert::ANY;
        ::aidl::android::hardware::audio::effect::Flags::Volume volume = ::aidl::android::hardware::audio::effect::Flags::Volume::NONE;
        ::aidl::android::hardware::audio::effect::Flags::HardwareAccelerator hwAcceleratorMode = ::aidl::android::hardware::audio::effect::Flags::HardwareAccelerator::NONE;
        bool offloadIndication = false;
        bool deviceIndication = false;
        bool audioModeIndication = false;
        bool audioSourceIndication = false;
        bool bypass = false;
        bool sinkMetadataIndication = false;
        bool sourceMetadataIndication = false;

        inline bool operator==(const Flags& _rhs) const {
            return std::tie(type, insert, volume, hwAcceleratorMode, offloadIndication, deviceIndication, audioModeIndication, audioSourceIndication, bypass, sinkMetadataIndication, sourceMetadataIndication) == std::tie(_rhs.type, _rhs.insert, _rhs.volume, _rhs.hwAcceleratorMode, _rhs.offloadIndication, _rhs.deviceIndication, _rhs.audioModeIndication, _rhs.audioSourceIndication, _rhs.bypass, _rhs.sinkMetadataIndication, _rhs.sourceMetadataIndication);
        }
        inline bool operator<(const Flags& _rhs) const {
            return std::tie(type, insert, volume, hwAcceleratorMode, offloadIndication, deviceIndication, audioModeIndication, audioSourceIndication, bypass, sinkMetadataIndication, sourceMetadataIndication) < std::tie(_rhs.type, _rhs.insert, _rhs.volume, _rhs.hwAcceleratorMode, _rhs.offloadIndication, _rhs.deviceIndication, _rhs.audioModeIndication, _rhs.audioSourceIndication, _rhs.bypass, _rhs.sinkMetadataIndication, _rhs.sourceMetadataIndication);
        }
        inline bool operator!=(const Flags& _rhs) const {
            return !(*this == _rhs);
        }
        inline bool operator>(const Flags& _rhs) const {
            return _rhs < *this;
        }
        inline bool operator>=(const Flags& _rhs) const {
            return !(*this < _rhs);
        }
        inline bool operator<=(const Flags& _rhs) const {
            return !(_rhs < *this);
        }
    };
} // namespace aidl::android::hardware::audio::effect
