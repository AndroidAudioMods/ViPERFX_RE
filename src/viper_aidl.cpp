#include "viper_aidl.h"
#include "log.h"

::ndk::ScopedAStatus ViPER4AndroidAIDL::open(const aidl::android::hardware::audio::effect::Parameter::Common &in_common,
                                             const std::optional<::aidl::android::hardware::audio::effect::Parameter::Specific> &in_specific,
                                             ::aidl::android::hardware::audio::effect::IEffect::OpenEffectReturn *_aidl_return) {
    VIPER_LOGD("open called");
    return ndk::ScopedAStatus();
}

::ndk::ScopedAStatus ViPER4AndroidAIDL::close() {
    VIPER_LOGD("close called");
    return ndk::ScopedAStatus();
}

::ndk::ScopedAStatus
ViPER4AndroidAIDL::getDescriptor(::aidl::android::hardware::audio::effect::Descriptor *_aidl_return) {
    VIPER_LOGD("getDescriptor called");
    return ndk::ScopedAStatus();
}

::ndk::ScopedAStatus ViPER4AndroidAIDL::command(::aidl::android::hardware::audio::effect::CommandId in_commandId) {
    VIPER_LOGD("command called");
    return ndk::ScopedAStatus();
}

::ndk::ScopedAStatus ViPER4AndroidAIDL::getState(::aidl::android::hardware::audio::effect::State *_aidl_return) {
    VIPER_LOGD("getState called");
    return ndk::ScopedAStatus();
}

::ndk::ScopedAStatus
ViPER4AndroidAIDL::setParameter(const aidl::android::hardware::audio::effect::Parameter &in_param) {
    VIPER_LOGD("setParameter called");
    return ndk::ScopedAStatus();
}

::ndk::ScopedAStatus
ViPER4AndroidAIDL::getParameter(const aidl::android::hardware::audio::effect::Parameter::Id &in_paramId,
                                ::aidl::android::hardware::audio::effect::Parameter *_aidl_return) {
    VIPER_LOGD("getParameter called");
    return ndk::ScopedAStatus();
}

::ndk::ScopedAStatus
ViPER4AndroidAIDL::reopen(::aidl::android::hardware::audio::effect::IEffect::OpenEffectReturn *_aidl_return) {
    VIPER_LOGD("reopen called");
    return ndk::ScopedAStatus();
}
