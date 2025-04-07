#include <android/media/audio/common/AudioUuid.h>
#include <aidl/android/media/audio/common/v1/AudioUuid.h>
#include <log/log.h>

namespace android::media::audio::common {
int32_t AudioUuid::timeLow() const {
    switch (version) {
        case 1:
            return uuid_v1->timeLow;
        default:
            ALOGE("AudioUuid::timeLow: Unknown version");
            return 0;
    }
}

int32_t AudioUuid::timeMid() const {
    switch (version) {
        case 1:
            return uuid_v1->timeMid;
        default:
            ALOGE("AudioUuid::timeMid: Unknown version");
            return 0;
    }
}

int32_t AudioUuid::timeHiAndVersion() const {
    switch (version) {
        case 1:
            return uuid_v1->timeHiAndVersion;
        default:
            ALOGE("AudioUuid::timeHiAndVersion: Unknown version");
            return 0;
    }
}

int32_t AudioUuid::clockSeq() const {
    switch (version) {
        case 1:
            return uuid_v1->clockSeq;
        default:
            ALOGE("AudioUuid::clockSeq: Unknown version");
            return 0;
    }
}

std::vector<uint8_t> AudioUuid::node() const {
    switch (version) {
        case 1:
            return uuid_v1->node;
        default:
            ALOGE("AudioUuid::node: Unknown version");
            return {};
    }
}

AudioUuid& AudioUuid::operator=(const AudioUuid& _rhs) {
    switch (version) {
        case 1:
            uuid_v1->timeLow = _rhs.timeLow();
            uuid_v1->timeMid = _rhs.timeMid();
            uuid_v1->timeHiAndVersion = _rhs.timeHiAndVersion();
            uuid_v1->clockSeq = _rhs.clockSeq();
            uuid_v1->node = _rhs.node();
            break;
        default:
            ALOGE("AudioUuid::operator=: Unknown version");
            break;
    }
    return *this;
}
} // namespace android::media::audio::common
