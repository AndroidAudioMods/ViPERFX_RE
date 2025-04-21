#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <aidl/android/media/audio/common/v1/AudioUuid.h>
#include "../../../../../AidlVersions.h"

using namespace aidl::android::media::audio::common;

namespace android::media::audio::common {
class AudioUuid {
public:
    int32_t timeLow() const;
    int32_t timeMid() const;
    int32_t timeHiAndVersion() const;
    int32_t clockSeq() const;
    std::vector<uint8_t> node() const;

    AudioUuid& operator=(const AudioUuid& _rhs);

    inline bool operator==(const AudioUuid& _rhs) const {
        int32_t timeLow = this->timeLow();
        int32_t timeMid = this->timeMid();
        int32_t timeHiAndVersion = this->timeHiAndVersion();
        int32_t clockSeq = this->clockSeq();
        std::vector<uint8_t> node = this->node();

        int32_t rhsTimeLow = _rhs.timeLow();
        int32_t rhsTimeMid = _rhs.timeMid();
        int32_t rhsTimeHiAndVersion = _rhs.timeHiAndVersion();
        int32_t rhsClockSeq = _rhs.clockSeq();
        std::vector<uint8_t> rhsNode = _rhs.node();

        return std::tie(timeLow, timeMid, timeHiAndVersion, clockSeq, node) == std::tie(rhsTimeLow, rhsTimeMid, rhsTimeHiAndVersion, rhsClockSeq, rhsNode);
    }
    inline bool operator<(const AudioUuid& _rhs) const {
        int32_t timeLow = this->timeLow();
        int32_t timeMid = this->timeMid();
        int32_t timeHiAndVersion = this->timeHiAndVersion();
        int32_t clockSeq = this->clockSeq();
        std::vector<uint8_t> node = this->node();

        int32_t rhsTimeLow = _rhs.timeLow();
        int32_t rhsTimeMid = _rhs.timeMid();
        int32_t rhsTimeHiAndVersion = _rhs.timeHiAndVersion();
        int32_t rhsClockSeq = _rhs.clockSeq();
        std::vector<uint8_t> rhsNode = _rhs.node();

        return std::tie(timeLow, timeMid, timeHiAndVersion, clockSeq, node) < std::tie(rhsTimeLow, rhsTimeMid, rhsTimeHiAndVersion, rhsClockSeq, rhsNode);
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
private:
    uint32_t version = AidlVersions::androidMediaAudioCommonTypesVersion;
    v1::AudioUuid *uuid_v1 = (v1::AudioUuid *) this;
};
} // namespace android::media::audio::common
