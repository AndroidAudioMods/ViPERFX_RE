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
        generated/android/media/audio/common/AudioPortDeviceExt.cpp
        generated/android/media/audio/common/AudioProfile.cpp
        generated/android/media/audio/common/AudioUsage.cpp
        generated/android/media/audio/common/HeadTracking.cpp
        generated/android/media/audio/common/AudioFormatDescription.cpp
        generated/android/media/audio/common/AudioHalCapCriterion.cpp
        generated/android/media/audio/common/AudioMMapPolicyType.cpp
        generated/android/media/audio/common/AudioPolicyForceUse.cpp
        generated/android/media/audio/common/AudioSource.cpp
        generated/android/media/audio/common/AudioDualMonoMode.cpp
        generated/android/media/audio/common/AudioPortExt.cpp
        generated/android/media/audio/common/AudioDeviceAddress.cpp
        generated/android/media/audio/common/PcmType.cpp
        generated/android/media/audio/common/AudioDeviceType.cpp
        generated/android/media/audio/common/AudioFlag.cpp
        generated/android/media/audio/common/AudioMode.cpp
        generated/android/media/audio/common/AudioGainMode.cpp
        generated/android/media/audio/common/AudioGain.cpp
        generated/android/media/audio/common/AudioConfig.cpp
        generated/android/media/audio/common/AudioHalCapCriterionV2.cpp
        generated/android/media/audio/common/MicrophoneDynamicInfo.cpp
        generated/android/media/audio/common/AudioConfigBase.cpp
        generated/android/media/audio/common/Float.cpp
        generated/android/media/audio/common/AudioAttributes.cpp
        generated/android/media/audio/common/Spatialization.cpp
        generated/android/media/audio/common/AudioUuid.cpp
        generated/android/media/audio/common/Double.cpp
        generated/android/media/audio/common/AudioMMapPolicyInfo.cpp
        generated/android/media/audio/common/AudioVolumeGroupChangeEvent.cpp
        generated/android/media/audio/common/AudioIoFlags.cpp
        generated/android/media/audio/common/AudioDeviceDescription.cpp
        generated/android/media/audio/common/AudioHalVolumeCurve.cpp
        generated/android/media/audio/common/AudioEncapsulationMetadataType.cpp
        generated/android/media/audio/common/AudioHalCapParameter.cpp
        generated/android/media/audio/common/ExtraAudioDescriptor.cpp
        generated/android/media/audio/common/MicrophoneInfo.cpp
        generated/android/media/audio/common/AudioHalVolumeGroup.cpp
        generated/android/media/audio/common/AudioGainConfig.cpp
        generated/android/media/audio/common/AudioHalCapConfiguration.cpp
        generated/android/media/audio/common/AudioLatencyMode.cpp
        generated/android/media/audio/common/AudioEncapsulationMode.cpp
        generated/android/media/audio/common/AudioFormatType.cpp
        generated/android/media/audio/common/AudioPort.cpp
        generated/android/media/audio/common/Boolean.cpp
        generated/android/media/audio/common/AudioHalEngineConfig.cpp
        generated/android/media/audio/common/Int.cpp
        generated/android/media/audio/common/AudioHalAttributesGroup.cpp
        generated/android/media/audio/common/AudioStreamType.cpp
        generated/android/media/audio/common/AudioPortConfig.cpp
        generated/android/media/audio/common/Void.cpp
        generated/android/media/audio/common/Long.cpp
        generated/android/media/audio/common/AudioHalCapDomain.cpp
        generated/android/media/audio/common/Byte.cpp
        generated/android/media/audio/common/AudioHalCapRule.cpp
        generated/android/media/audio/common/AudioStandard.cpp
        generated/android/media/audio/common/AudioMMapPolicy.cpp
        generated/android/media/audio/common/AudioHalCapCriterionType.cpp
        generated/android/media/audio/common/AudioPortMixExt.cpp
        generated/android/media/audio/common/AudioOutputFlags.cpp
        generated/android/media/audio/common/AudioHalProductStrategy.cpp
        generated/android/media/audio/common/AudioChannelLayout.cpp
        generated/android/media/audio/common/AudioDevice.cpp
        generated/android/media/audio/common/AudioPlaybackRate.cpp
        generated/android/media/audio/common/AudioPortMixExtUseCase.cpp
        generated/android/media/audio/common/AudioEncapsulationType.cpp
        generated/android/media/audio/common/AudioOffloadInfo.cpp
        generated/android/media/audio/common/AudioProductStrategyType.cpp
        generated/android/media/audio/common/AudioContentType.cpp
        generated/android/media/audio/common/AudioInputFlags.cpp

        generated/android/media/audio/eraser/Configuration.cpp
        generated/android/media/audio/eraser/Classification.cpp
        generated/android/media/audio/eraser/ClassificationConfig.cpp
        generated/android/media/audio/eraser/Capability.cpp
        generated/android/media/audio/eraser/SeparatorCapability.cpp
        generated/android/media/audio/eraser/IEraserCallback.cpp
        generated/android/media/audio/eraser/SoundClassification.cpp
        generated/android/media/audio/eraser/RemixerCapability.cpp
        generated/android/media/audio/eraser/Mode.cpp
        generated/android/media/audio/eraser/ClassificationMetadataList.cpp
        generated/android/media/audio/eraser/ClassifierCapability.cpp
        generated/android/media/audio/eraser/ClassificationMetadata.cpp

        generated/android/hardware/audio/effect/BassBoost.cpp
        generated/android/hardware/audio/effect/AutomaticGainControlV2.cpp
        generated/android/hardware/audio/effect/PresetReverb.cpp
        generated/android/hardware/audio/effect/Descriptor.cpp
        generated/android/hardware/audio/effect/Downmix.cpp
        generated/android/hardware/audio/effect/Virtualizer.cpp
        generated/android/hardware/audio/effect/Processing.cpp
        generated/android/hardware/audio/effect/LoudnessEnhancer.cpp
        generated/android/hardware/audio/effect/Range.cpp
        generated/android/hardware/audio/effect/Volume.cpp
        generated/android/hardware/audio/effect/AcousticEchoCanceler.cpp
        generated/android/hardware/audio/effect/Capability.cpp
        generated/android/hardware/audio/effect/VendorExtension.cpp
        generated/android/hardware/audio/effect/Visualizer.cpp
        generated/android/hardware/audio/effect/Flags.cpp
        generated/android/hardware/audio/effect/NoiseSuppression.cpp
        generated/android/hardware/audio/effect/CommandId.cpp
        generated/android/hardware/audio/effect/AutomaticGainControlV1.cpp
        generated/android/hardware/audio/effect/EnvironmentalReverb.cpp
        generated/android/hardware/audio/effect/Equalizer.cpp
        generated/android/hardware/audio/effect/Parameter.cpp
        generated/android/hardware/audio/effect/HapticGenerator.cpp
        generated/android/hardware/audio/effect/Eraser.cpp
        generated/android/hardware/audio/effect/State.cpp
        generated/android/hardware/audio/effect/IFactory.cpp
        generated/android/hardware/audio/effect/Spatializer.cpp
        generated/android/hardware/audio/effect/DynamicsProcessing.cpp
        generated/android/hardware/audio/effect/DefaultExtension.cpp
        generated/android/hardware/audio/effect/IEffect.cpp

        generated/android/hardware/audio/common/AudioOffloadMetadata.cpp
        generated/android/hardware/audio/common/SinkMetadata.cpp
        generated/android/hardware/audio/common/PlaybackTrackMetadata.cpp
        generated/android/hardware/audio/common/SourceMetadata.cpp
        generated/android/hardware/audio/common/RecordTrackMetadata.cpp

        generated/android/hardware/common/Ashmem.cpp
        generated/android/hardware/common/NativeHandle.cpp
        generated/android/hardware/common/MappableFile.cpp

        generated/android/hardware/common/fmq/MQDescriptor.cpp
        generated/android/hardware/common/fmq/SynchronizedReadWrite.cpp
        generated/android/hardware/common/fmq/GrantorDescriptor.cpp
        generated/android/hardware/common/fmq/UnsynchronizedWrite.cpp)

include_directories(generated/include)

# ViPERFX
include_directories(src/include)

set(FILES
        # Shim
        src/shim.cpp

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

target_link_libraries(v4a_re log binder_ndk)
target_link_options(v4a_re PRIVATE "LINKER:--no-demangle")
target_compile_options(v4a_re PRIVATE -flto -O3 -DNDEBUG)
#target_compile_options(v4afx_r PRIVATE -O2 -DNDEBUG -Wall -Wsign-conversion -Wno-unused-result -Wno-unneeded-internal-declaration -fstrict-aliasing -fvisibility=hidden -Wextra -Wno-unused-parameter)
