/*
 * Copyright (C) 2022 The Android Open Source Project
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

#include <cstddef>
#include <memory>

#define LOG_TAG "AHAL_EffectThread"
#include <log/log.h>
#include <pthread.h>
#include <sys/resource.h>

#include "EffectThread.h"
#include "EffectTypes.h"

namespace aidl::android::hardware::audio::effect {

    EffectThread::~EffectThread() {
        destroyThread();
    }

    RetCode EffectThread::createThread(const std::string& name, int priority) {
        if (mThread.joinable()) {
            ALOGW("%s %s thread already created, no-op", mName.c_str(), __func__);
            return RetCode::SUCCESS;
        }

        mName = name;
        mPriority = priority;
        {
            std::lock_guard lg(mThreadMutex);
            mStop = true;
            mExit = false;
        }

        mThread = std::thread(&EffectThread::threadLoop, this);
        ALOGV("%s %s priority %d done", mName.c_str(), __func__, mPriority);
        return RetCode::SUCCESS;
    }

    RetCode EffectThread::destroyThread() {
        {
            std::lock_guard lg(mThreadMutex);
            mStop = mExit = true;
        }

        mCv.notify_one();
        if (mThread.joinable()) {
            mThread.join();
        }

        ALOGV("%s", mName.c_str());
        return RetCode::SUCCESS;
    }

    RetCode EffectThread::startThread() {
        {
            std::lock_guard lg(mThreadMutex);
            if (mDraining) {
                mDraining = false;
            } else {
                mStop = false;
            }
            mCv.notify_one();
        }

        ALOGV("%s", mName.c_str());
        return RetCode::SUCCESS;
    }

    RetCode EffectThread::stopThread() {
        {
            std::lock_guard lg(mThreadMutex);
            mStop = true;
            mCv.notify_one();
        }

        ALOGV("%s", mName.c_str());
        return RetCode::SUCCESS;
    }

    RetCode EffectThread::startDraining() {
        std::lock_guard lg(mThreadMutex);
        mDraining = true;
        mCv.notify_one();

        ALOGV("%s", mName.c_str());
        return RetCode::SUCCESS;
    }

    RetCode EffectThread::finishDraining() {
        std::lock_guard lg(mThreadMutex);
        mDraining = false;
        mStop = true;
        mCv.notify_one();

        ALOGV("%s", mName.c_str());
        return RetCode::SUCCESS;
    }

    void EffectThread::threadLoop() {
        pthread_setname_np(pthread_self(), mName.substr(0, kMaxTaskNameLen - 1).c_str());
        setpriority(PRIO_PROCESS, 0, mPriority);
        while (true) {
            {
                std::unique_lock l(mThreadMutex);
                ::android::base::ScopedLockAssertion lock_assertion(mThreadMutex);
                mCv.wait(l, [&]() REQUIRES(mThreadMutex) { return mExit || !mStop; });
                if (mExit) {
                    ALOGV("%s threadLoop EXIT!", mName.c_str());
                    return;
                }
            }
            process();
        }
    }

}  // namespace aidl::android::hardware::audio::effect