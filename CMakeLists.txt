cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 20)

project("ViPER4Android")
add_compile_definitions(VIPER_VERSION=20240314)

# External
set(CORE_SRC
        #[[external/core/libcutils/ashmem-host.cpp
        external/core/libcutils/native_handle.cpp
        external/core/libutils/SystemClock.cpp
        external/core/libutils/Timers.cpp]])

set(LIBFMQ_SRC
        #[[external/libfmq/EventFlag.cpp]])

include_directories(
        external/libbase/include
        external/core/include
        external/libfmq/include
        external/libfmq/base)

# AIDL
set(AIDL_SRC
        generated/android/media/audio/common/v1/AudioUuid.cpp

        src/android/media/audio/common/AudioPortDeviceExt.cpp
        src/android/media/audio/common/AudioProfile.cpp
        src/android/media/audio/common/AudioUsage.cpp
        src/android/media/audio/common/HeadTracking.cpp
        src/android/media/audio/common/AudioFormatDescription.cpp
        src/android/media/audio/common/AudioHalCapCriterion.cpp
        src/android/media/audio/common/AudioMMapPolicyType.cpp
        src/android/media/audio/common/AudioPolicyForceUse.cpp
        src/android/media/audio/common/AudioSource.cpp
        src/android/media/audio/common/AudioDualMonoMode.cpp
        src/android/media/audio/common/AudioPortExt.cpp
        src/android/media/audio/common/AudioDeviceAddress.cpp
        src/android/media/audio/common/PcmType.cpp
        src/android/media/audio/common/AudioDeviceType.cpp
        src/android/media/audio/common/AudioFlag.cpp
        src/android/media/audio/common/AudioMode.cpp
        src/android/media/audio/common/AudioGainMode.cpp
        src/android/media/audio/common/AudioGain.cpp
        src/android/media/audio/common/AudioConfig.cpp
        src/android/media/audio/common/AudioHalCapCriterionV2.cpp
        src/android/media/audio/common/MicrophoneDynamicInfo.cpp
        src/android/media/audio/common/AudioConfigBase.cpp
        src/android/media/audio/common/Float.cpp
        src/android/media/audio/common/AudioAttributes.cpp
        src/android/media/audio/common/Spatialization.cpp
        src/android/media/audio/common/AudioUuid.cpp
        src/android/media/audio/common/Double.cpp
        src/android/media/audio/common/AudioMMapPolicyInfo.cpp
        src/android/media/audio/common/AudioVolumeGroupChangeEvent.cpp
        src/android/media/audio/common/AudioIoFlags.cpp
        src/android/media/audio/common/AudioDeviceDescription.cpp
        src/android/media/audio/common/AudioHalVolumeCurve.cpp
        src/android/media/audio/common/AudioEncapsulationMetadataType.cpp
        src/android/media/audio/common/AudioHalCapParameter.cpp
        src/android/media/audio/common/ExtraAudioDescriptor.cpp
        src/android/media/audio/common/MicrophoneInfo.cpp
        src/android/media/audio/common/AudioHalVolumeGroup.cpp
        src/android/media/audio/common/AudioGainConfig.cpp
        src/android/media/audio/common/AudioHalCapConfiguration.cpp
        src/android/media/audio/common/AudioLatencyMode.cpp
        src/android/media/audio/common/AudioEncapsulationMode.cpp
        src/android/media/audio/common/AudioFormatType.cpp
        src/android/media/audio/common/AudioPort.cpp
        src/android/media/audio/common/Boolean.cpp
        src/android/media/audio/common/AudioHalEngineConfig.cpp
        src/android/media/audio/common/Int.cpp
        src/android/media/audio/common/AudioHalAttributesGroup.cpp
        src/android/media/audio/common/AudioStreamType.cpp
        src/android/media/audio/common/AudioPortConfig.cpp
        src/android/media/audio/common/Void.cpp
        src/android/media/audio/common/Long.cpp
        src/android/media/audio/common/AudioHalCapDomain.cpp
        src/android/media/audio/common/Byte.cpp
        src/android/media/audio/common/AudioHalCapRule.cpp
        src/android/media/audio/common/AudioStandard.cpp
        src/android/media/audio/common/AudioMMapPolicy.cpp
        src/android/media/audio/common/AudioHalCapCriterionType.cpp
        src/android/media/audio/common/AudioPortMixExt.cpp
        src/android/media/audio/common/AudioOutputFlags.cpp
        src/android/media/audio/common/AudioHalProductStrategy.cpp
        src/android/media/audio/common/AudioChannelLayout.cpp
        src/android/media/audio/common/AudioDevice.cpp
        src/android/media/audio/common/AudioPlaybackRate.cpp
        src/android/media/audio/common/AudioPortMixExtUseCase.cpp
        src/android/media/audio/common/AudioEncapsulationType.cpp
        src/android/media/audio/common/AudioOffloadInfo.cpp
        src/android/media/audio/common/AudioProductStrategyType.cpp
        src/android/media/audio/common/AudioContentType.cpp
        src/android/media/audio/common/AudioInputFlags.cpp

        src/android/media/audio/eraser/Configuration.cpp
        src/android/media/audio/eraser/Classification.cpp
        src/android/media/audio/eraser/ClassificationConfig.cpp
        src/android/media/audio/eraser/Capability.cpp
        src/android/media/audio/eraser/SeparatorCapability.cpp
        src/android/media/audio/eraser/IEraserCallback.cpp
        src/android/media/audio/eraser/SoundClassification.cpp
        src/android/media/audio/eraser/RemixerCapability.cpp
        src/android/media/audio/eraser/Mode.cpp
        src/android/media/audio/eraser/ClassificationMetadataList.cpp
        src/android/media/audio/eraser/ClassifierCapability.cpp
        src/android/media/audio/eraser/ClassificationMetadata.cpp

        src/android/hardware/audio/effect/BassBoost.cpp
        src/android/hardware/audio/effect/AutomaticGainControlV2.cpp
        src/android/hardware/audio/effect/PresetReverb.cpp
        src/android/hardware/audio/effect/Descriptor.cpp
        src/android/hardware/audio/effect/Downmix.cpp
        src/android/hardware/audio/effect/Virtualizer.cpp
        src/android/hardware/audio/effect/Processing.cpp
        src/android/hardware/audio/effect/LoudnessEnhancer.cpp
        src/android/hardware/audio/effect/Range.cpp
        src/android/hardware/audio/effect/Volume.cpp
        src/android/hardware/audio/effect/AcousticEchoCanceler.cpp
        src/android/hardware/audio/effect/Capability.cpp
        src/android/hardware/audio/effect/VendorExtension.cpp
        src/android/hardware/audio/effect/Visualizer.cpp
        src/android/hardware/audio/effect/Flags.cpp
        src/android/hardware/audio/effect/NoiseSuppression.cpp
        src/android/hardware/audio/effect/CommandId.cpp
        src/android/hardware/audio/effect/AutomaticGainControlV1.cpp
        src/android/hardware/audio/effect/EnvironmentalReverb.cpp
        src/android/hardware/audio/effect/Equalizer.cpp
        src/android/hardware/audio/effect/Parameter.cpp
        src/android/hardware/audio/effect/HapticGenerator.cpp
        src/android/hardware/audio/effect/Eraser.cpp
        src/android/hardware/audio/effect/State.cpp
        src/android/hardware/audio/effect/IFactory.cpp
        src/android/hardware/audio/effect/Spatializer.cpp
        src/android/hardware/audio/effect/DynamicsProcessing.cpp
        src/android/hardware/audio/effect/DefaultExtension.cpp
        src/android/hardware/audio/effect/IEffect.cpp

        src/android/hardware/audio/common/AudioOffloadMetadata.cpp
        src/android/hardware/audio/common/SinkMetadata.cpp
        src/android/hardware/audio/common/PlaybackTrackMetadata.cpp
        src/android/hardware/audio/common/SourceMetadata.cpp
        src/android/hardware/audio/common/RecordTrackMetadata.cpp

        src/android/hardware/common/Ashmem.cpp
        src/android/hardware/common/NativeHandle.cpp
        src/android/hardware/common/MappableFile.cpp

        src/android/hardware/common/fmq/MQDescriptor.cpp
        src/android/hardware/common/fmq/SynchronizedReadWrite.cpp
        src/android/hardware/common/fmq/GrantorDescriptor.cpp
        src/android/hardware/common/fmq/UnsynchronizedWrite.cpp)

include_directories(generated/include)

# ViPERFX
include_directories(src/include)

set(FILES
        # Shim
        src/shim.cpp
        src/AidlVersions.cpp

        # Main
        src/aidl/EffectThread.cpp

        src/viper/ViPER.cpp
        src/ViPER4Android.cpp
        src/ViperContext.cpp
        src/viper_aidl.cpp

        # Effects
        src/viper/effects/AnalogX.cpp
        src/viper/effects/ColorfulMusic.cpp
        src/viper/effects/Convolver.cpp
        src/viper/effects/Cure.cpp
        src/viper/effects/DiffSurround.cpp
        src/viper/effects/DynamicSystem.cpp
        src/viper/effects/FETCompressor.cpp
        src/viper/effects/IIRFilter.cpp
        src/viper/effects/PlaybackGain.cpp
        src/viper/effects/Reverberation.cpp
        src/viper/effects/SoftwareLimiter.cpp
        src/viper/effects/SpeakerCorrection.cpp
        src/viper/effects/SpectrumExtend.cpp
        src/viper/effects/TubeSimulator.cpp
        src/viper/effects/VHE.cpp
        src/viper/effects/ViPERBass.cpp
        src/viper/effects/ViPERClarity.cpp
        src/viper/effects/ViPERDDC.cpp

        # Utils
        src/viper/utils/AdaptiveBuffer.cpp
        src/viper/utils/Biquad.cpp
        src/viper/utils/CAllpassFilter.cpp
        src/viper/utils/CCombFilter.cpp
        src/viper/utils/CRevModel.cpp
        src/viper/utils/Crossfeed.cpp
        src/viper/utils/DepthSurround.cpp
        src/viper/utils/DynamicBass.cpp
        src/viper/utils/FIR.cpp
        src/viper/utils/Harmonic.cpp
        src/viper/utils/HiFi.cpp
        src/viper/utils/HighShelf.cpp
        src/viper/utils/IIR_1st.cpp
        src/viper/utils/IIR_NOrder_BW_BP.cpp
        src/viper/utils/IIR_NOrder_BW_LH.cpp
        src/viper/utils/MinPhaseIIRCoeffs.cpp
        src/viper/utils/MultiBiquad.cpp
        src/viper/utils/NoiseSharpening.cpp
        src/viper/utils/PassFilter.cpp
        src/viper/utils/PConvSingle.cpp
        src/viper/utils/PolesFilter.cpp
        src/viper/utils/Polyphase.cpp
        src/viper/utils/Stereo3DSurround.cpp
        src/viper/utils/Subwoofer.cpp
        src/viper/utils/TimeConstDelay.cpp
        src/viper/utils/WaveBuffer.cpp)

add_library(v4a_re SHARED
        ${CORE_SRC}
        ${LIBFMQ_SRC}
        ${AIDL_SRC}
        ${FILES})

target_link_libraries(v4a_re log binder_ndk) # kissfft)
target_link_options(v4a_re PRIVATE "LINKER:--no-demangle")
target_compile_options(v4a_re PRIVATE -flto -O3 -DNDEBUG)
#target_compile_options(v4afx_r PRIVATE -O2 -DNDEBUG -Wall -Wsign-conversion -Wno-unused-result -Wno-unneeded-internal-declaration -fstrict-aliasing -fvisibility=hidden -Wextra -Wno-unused-parameter)
