/*
 * Copyright (C) 2022 The Android Open Source Project
 *               2025 anonymix007
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <aidl/android/hardware/audio/effect/BnEffect.h>
#include <fmq/AidlMessageQueue.h>
#include <cstdlib>
#include <memory>

#include "effect-impl/EffectImpl.h"

#include "ViperContext.h"

namespace aidl::android::hardware::audio::effect {

static inline bool aidl2legacy_ParameterCommon_effect_config_t(const Parameter::Common& common, effect_config_t &conf) {
    // FIXME: This shouldn't be false
    auto tmp = ::aidl::android::aidl2legacy_AudioConfig_buffer_config_t(common.input, false);
    if (tmp.ok()) {
        conf.inputCfg = tmp.value();
    } else {
        return false;
    }

    tmp = ::aidl::android::aidl2legacy_AudioConfig_buffer_config_t(common.output, false);
    if (tmp.ok()) {
        conf.outputCfg = tmp.value();
    } else {;
        return false;
    }

    return true;
}

class ViperAidlContext final : public EffectContext, public ViperContext {
  public:
    ViperAidlContext(int statusDepth, const Parameter::Common& common)
        : EffectContext(statusDepth, common),
          ViperContext() {
        LOG(DEBUG) << __func__;
    }

    RetCode setCommon(const Parameter::Common& common) override {
        if (auto ret = EffectContext::setCommon(common); ret != RetCode::SUCCESS) {
            return ret;
        }

        int32_t ret = 0;
        uint32_t ret_size = sizeof(ret);
        effect_config_t conf;

        if (!aidl2legacy_ParameterCommon_effect_config_t(common, conf)) {
            LOG(ERROR) << __func__ << ": ViperAidlContext::setCommon: aidl2legacy_ParameterCommon_effect_config_t failed";
            return RetCode::ERROR_ILLEGAL_PARAMETER;
        }

        int32_t status = handleCommand(EFFECT_CMD_SET_CONFIG, sizeof(conf), &conf, &ret_size, &ret);
        if (status < 0) {
            LOG(ERROR) << __func__ << ": ViperAidlContext::handleCommand SET CONFIG failed: " << status;
            return RetCode::ERROR_ILLEGAL_PARAMETER;
        }
        if (ret < 0) {
            LOG(ERROR) << __func__ << ": ViperAidlContext::handleCommand SET CONFIG failed (internal): " << ret;
            return RetCode::ERROR_ILLEGAL_PARAMETER;
        }
        return RetCode::SUCCESS;
    }
};

class ViperAidl final : public EffectImpl {
  public:
    static const std::string kEffectName;
    static const Capability kEqCap;
    static const Descriptor kDesc;

    ViperAidl() { LOG(DEBUG) << __func__; }
    ~ViperAidl() {
        cleanUp();
        LOG(DEBUG) << __func__;
    }

    ndk::ScopedAStatus getDescriptor(Descriptor* _aidl_return) override;
    ndk::ScopedAStatus setParameterSpecific(const Parameter::Specific& specific)
            REQUIRES(mImplMutex) override;
    ndk::ScopedAStatus getParameterSpecific(const Parameter::Id& id, Parameter::Specific* specific)
            REQUIRES(mImplMutex) override;

    std::shared_ptr<EffectContext> createContext(const Parameter::Common& common)
            REQUIRES(mImplMutex) override;
    ndk::ScopedAStatus commandImpl(CommandId id) REQUIRES(mImplMutex);

    RetCode releaseContext() REQUIRES(mImplMutex) override;

    IEffect::Status effectProcessImpl(float* in, float* out, int samples)
            REQUIRES(mImplMutex) override;
    std::string getEffectName() override { return kEffectName; }

  private:
    std::shared_ptr<ViperAidlContext> mContext;
};

constexpr char kEffectImplUuidViper[] = "90380da3-8536-4744-a6a3-5731970e640f";
inline const AudioUuid& getEffectImplUuidViper() {
    static const ::android::base::NoDestructor<AudioUuid> uuid(stringToUuid(kEffectImplUuidViper));
    return *uuid;
}

constexpr char kEffectTypeUuidViper[] = "b9bc100c-26cd-42e6-acb6-cad8c3f778de";
inline const AudioUuid& getEffectTypeUuidViper() {
    static const ::android::base::NoDestructor<AudioUuid> uuid(stringToUuid(kEffectTypeUuidViper));
    return *uuid;
}
}  // namespace aidl::android::hardware::audio::effect
