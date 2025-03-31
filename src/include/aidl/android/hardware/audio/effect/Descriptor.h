#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <aidl/android/hardware/audio/effect/Flags.h>
#include <aidl/android/media/audio/common/AudioUuid.h>

namespace aidl::android::hardware::audio::effect {
    class Descriptor {
    public:
        class Identity {
        public:
            ::aidl::android::media::audio::common::AudioUuid type;
            ::aidl::android::media::audio::common::AudioUuid uuid;
            std::optional<::aidl::android::media::audio::common::AudioUuid> proxy;

            inline bool operator==(const Identity& _rhs) const {
                return std::tie(type, uuid, proxy) == std::tie(_rhs.type, _rhs.uuid, _rhs.proxy);
            }
            inline bool operator<(const Identity& _rhs) const {
                return std::tie(type, uuid, proxy) < std::tie(_rhs.type, _rhs.uuid, _rhs.proxy);
            }
            inline bool operator!=(const Identity& _rhs) const {
                return !(*this == _rhs);
            }
            inline bool operator>(const Identity& _rhs) const {
                return _rhs < *this;
            }
            inline bool operator>=(const Identity& _rhs) const {
                return !(*this < _rhs);
            }
            inline bool operator<=(const Identity& _rhs) const {
                return !(_rhs < *this);
            }
        };
        class Common {
        public:
            ::aidl::android::hardware::audio::effect::Descriptor::Identity id;
            ::aidl::android::hardware::audio::effect::Flags flags;
            int32_t cpuLoad = 0;
            int32_t memoryUsage = 0;
            std::string name;
            std::string implementor;

            inline bool operator==(const Common& _rhs) const {
                return std::tie(id, flags, cpuLoad, memoryUsage, name, implementor) == std::tie(_rhs.id, _rhs.flags, _rhs.cpuLoad, _rhs.memoryUsage, _rhs.name, _rhs.implementor);
            }
            inline bool operator<(const Common& _rhs) const {
                return std::tie(id, flags, cpuLoad, memoryUsage, name, implementor) < std::tie(_rhs.id, _rhs.flags, _rhs.cpuLoad, _rhs.memoryUsage, _rhs.name, _rhs.implementor);
            }
            inline bool operator!=(const Common& _rhs) const {
                return !(*this == _rhs);
            }
            inline bool operator>(const Common& _rhs) const {
                return _rhs < *this;
            }
            inline bool operator>=(const Common& _rhs) const {
                return !(*this < _rhs);
            }
            inline bool operator<=(const Common& _rhs) const {
                return !(_rhs < *this);
            }
        };
        ::aidl::android::hardware::audio::effect::Descriptor::Common common;
        /*::aidl::android::hardware::audio::effect::Capability capability;*/

        inline bool operator==(const Descriptor& _rhs) const {
            return std::tie(common/*, capability*/) == std::tie(_rhs.common/*, _rhs.capability*/);
        }
        inline bool operator<(const Descriptor& _rhs) const {
            return std::tie(common/*, capability*/) < std::tie(_rhs.common/*, _rhs.capability*/);
        }
        inline bool operator!=(const Descriptor& _rhs) const {
            return !(*this == _rhs);
        }
        inline bool operator>(const Descriptor& _rhs) const {
            return _rhs < *this;
        }
        inline bool operator>=(const Descriptor& _rhs) const {
            return !(*this < _rhs);
        }
        inline bool operator<=(const Descriptor& _rhs) const {
            return !(_rhs < *this);
        }
    };
} // namespace aidl::android::hardware::audio::effect
