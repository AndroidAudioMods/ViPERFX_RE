#pragma once

#include <aidl/android/media/audio/common/AudioUuid.h>
#include <aidl/android/media/audio/common/PcmType.h>

using aidl::android::media::audio::common::AudioUuid;
using aidl::android::media::audio::common::PcmType;

inline AudioUuid stringToUuid(const char* str) {
    AudioUuid uuid{};
    uint32_t tmp[10];
    if (!str || sscanf(str, "%08x-%04x-%04x-%04x-%02x%02x%02x%02x%02x%02x", tmp,
                       tmp + 1, tmp + 2, tmp + 3, tmp + 4, tmp + 5, tmp + 6,
                       tmp + 7, tmp + 8, tmp + 9) < 10) {
        return uuid;
    }

    uuid.timeLow = (uint32_t)tmp[0];
    uuid.timeMid = (uint16_t)tmp[1];
    uuid.timeHiAndVersion = (uint16_t)tmp[2];
    uuid.clockSeq = (uint16_t)tmp[3];
    uuid.node.insert(uuid.node.end(), {(uint8_t)tmp[4], (uint8_t)tmp[5], (uint8_t)tmp[6],
                                       (uint8_t)tmp[7], (uint8_t)tmp[8], (uint8_t)tmp[9]});
    return uuid;
}

constexpr size_t getPcmSampleSizeInBytes(::aidl::android::media::audio::common::PcmType pcm) {
    using ::aidl::android::media::audio::common::PcmType;
    switch (pcm) {
        case PcmType::UINT_8_BIT:
            return 1;
        case PcmType::INT_16_BIT:
            return 2;
        case PcmType::INT_32_BIT:
            return 4;
        case PcmType::FIXED_Q_8_24:
            return 4;
        case PcmType::FLOAT_32_BIT:
            return 4;
        case PcmType::INT_24_BIT:
            return 3;
    }
    return 0;
}

constexpr size_t getChannelCount(
        const ::aidl::android::media::audio::common::AudioChannelLayout& layout,
        int32_t mask = std::numeric_limits<int32_t>::max()) {
    using Tag = ::aidl::android::media::audio::common::AudioChannelLayout::Tag;
    switch (layout.getTag()) {
        case Tag::none:
            return 0;
        case Tag::invalid:
            return 0;
        case Tag::indexMask:
            return __builtin_popcount(layout.get<Tag::indexMask>() & mask);
        case Tag::layoutMask:
            return __builtin_popcount(layout.get<Tag::layoutMask>() & mask);
        case Tag::voiceMask:
            return __builtin_popcount(layout.get<Tag::voiceMask>() & mask);
    }
    return 0;
}

constexpr size_t getFrameSizeInBytes(
        const ::aidl::android::media::audio::common::AudioFormatDescription& format,
        const ::aidl::android::media::audio::common::AudioChannelLayout& layout) {
    if (format == ::aidl::android::media::audio::common::AudioFormatDescription{}) {
        // Unspecified format.
        return 0;
    }
    using ::aidl::android::media::audio::common::AudioFormatType;
    if (format.type == AudioFormatType::PCM) {
        return getPcmSampleSizeInBytes(format.pcm) * getChannelCount(layout);
    } else if (format.type == AudioFormatType::NON_PCM) {
        // For non-PCM formats always use the underlying PCM size. The default value for
        // PCM is "UINT_8_BIT", thus non-encapsulated streams have the frame size of 1.
        return getPcmSampleSizeInBytes(format.pcm);
    }
    // Something unexpected.
    return 0;
}
