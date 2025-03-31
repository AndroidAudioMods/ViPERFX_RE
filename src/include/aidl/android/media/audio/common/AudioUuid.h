#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace aidl::android::media::audio::common {
    class AudioUuid {
    public:
        int32_t timeLow = 0;
        int32_t timeMid = 0;
        int32_t timeHiAndVersion = 0;
        int32_t clockSeq = 0;
        std::vector<uint8_t> node;

        inline bool operator==(const AudioUuid& _rhs) const {
            return std::tie(timeLow, timeMid, timeHiAndVersion, clockSeq, node) == std::tie(_rhs.timeLow, _rhs.timeMid, _rhs.timeHiAndVersion, _rhs.clockSeq, _rhs.node);
        }
        inline bool operator<(const AudioUuid& _rhs) const {
            return std::tie(timeLow, timeMid, timeHiAndVersion, clockSeq, node) < std::tie(_rhs.timeLow, _rhs.timeMid, _rhs.timeHiAndVersion, _rhs.clockSeq, _rhs.node);
        }
        inline bool operator!=(const AudioUuid& _rhs) const {
            return !(*this == _rhs);
        }
        inline bool operator>(const AudioUuid& _rhs) const {
            return _rhs < *this;
        }
        inline bool operator>=(const AudioUuid& _rhs) const {
            return !(*this < _rhs);
        }
        inline bool operator<=(const AudioUuid& _rhs) const {
            return !(_rhs < *this);
        }
    };
} // namespace aidl::android::media::audio::common
