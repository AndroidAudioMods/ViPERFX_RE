#include <string>
#include <log/log.h>

namespace android::hardware::details {
    void check(bool exp) {
        ALOGE_IF(!exp, "Check failed");
    }

    void check(bool exp, const char* message) {
        ALOGE_IF(!exp, "%s", message);
    }

    void logError(const std::string &message) {
        ALOGE("%s", message.c_str());
    }

    void errorWriteLog(int tag, const char* info) {
        ALOGE("%d: %s", tag, info);
    }
} // namespace android::hardware::details
