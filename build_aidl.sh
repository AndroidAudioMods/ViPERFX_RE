#!/bin/bash

# Configuration
AIDL="${AIDL:-aidl}"
OUT_DIR="${OUT_DIR:-generated}"

# List of AIDL files to compile
AIDL_FILES=(
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/android/hardware/audio/common/AudioOffloadMetadata.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/android/hardware/audio/common/PlaybackTrackMetadata.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/android/hardware/audio/common/RecordTrackMetadata.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/android/hardware/audio/common/SinkMetadata.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/android/hardware/audio/common/SourceMetadata.aidl"

    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/AcousticEchoCanceler.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/AutomaticGainControlV1.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/AutomaticGainControlV2.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/BassBoost.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Capability.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/CommandId.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/DefaultExtension.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Descriptor.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Downmix.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/DynamicsProcessing.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/EnvironmentalReverb.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Equalizer.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Eraser.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Flags.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/HapticGenerator.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/IEffect.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/IFactory.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/LoudnessEnhancer.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/NoiseSuppression.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Parameter.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/PresetReverb.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Processing.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Range.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Spatializer.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/State.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/VendorExtension.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Virtualizer.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Visualizer.aidl"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/Volume.aidl"

    "hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/android/hardware/common/Ashmem.aidl"
    "hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/android/hardware/common/MappableFile.aidl"
    "hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/android/hardware/common/NativeHandle.aidl"

    "hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/android/hardware/common/fmq/GrantorDescriptor.aidl"
    "hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/android/hardware/common/fmq/MQDescriptor.aidl"
    "hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/android/hardware/common/fmq/SynchronizedReadWrite.aidl"
    "hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/android/hardware/common/fmq/UnsynchronizedWrite.aidl"

    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioAttributes.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioChannelLayout.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioConfig.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioConfigBase.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioContentType.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioDevice.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioDeviceAddress.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioDeviceDescription.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioDeviceType.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioDualMonoMode.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioEncapsulationMetadataType.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioEncapsulationMode.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioEncapsulationType.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioFlag.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioFormatDescription.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioFormatType.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioGain.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioGainConfig.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioGainMode.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioHalAttributesGroup.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioHalCapConfiguration.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioHalCapCriterion.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioHalCapCriterionV2.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioHalCapCriterionType.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioHalCapDomain.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioHalCapParameter.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioHalCapRule.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioHalEngineConfig.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioHalProductStrategy.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioHalVolumeCurve.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioHalVolumeGroup.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioInputFlags.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioIoFlags.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioLatencyMode.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioMMapPolicy.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioMMapPolicyInfo.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioMMapPolicyType.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioMode.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioOffloadInfo.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioOutputFlags.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioPlaybackRate.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioPolicyForceUse.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioPort.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioPortConfig.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioPortDeviceExt.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioPortExt.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioPortMixExt.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioPortMixExtUseCase.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioProductStrategyType.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioProfile.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioSource.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioStandard.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioStreamType.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioUsage.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioUuid.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/AudioVolumeGroupChangeEvent.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/Boolean.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/Byte.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/ExtraAudioDescriptor.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/Float.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/Double.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/HeadTracking.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/Int.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/Long.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/MicrophoneDynamicInfo.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/MicrophoneInfo.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/PcmType.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/Spatialization.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/android/media/audio/common/Void.aidl"

    "system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/android/media/audio/eraser/Capability.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/android/media/audio/eraser/Classification.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/android/media/audio/eraser/ClassificationConfig.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/android/media/audio/eraser/ClassificationMetadata.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/android/media/audio/eraser/ClassificationMetadataList.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/android/media/audio/eraser/ClassifierCapability.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/android/media/audio/eraser/Configuration.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/android/media/audio/eraser/IEraserCallback.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/android/media/audio/eraser/Mode.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/android/media/audio/eraser/RemixerCapability.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/android/media/audio/eraser/SeparatorCapability.aidl"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/android/media/audio/eraser/SoundClassification.aidl"
)

# Include paths
INCLUDE_PATHS=(
    "hardware_interfaces/common/aidl/aidl_api/android.hardware.common/current/"
    "hardware_interfaces/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.common/current/"
    "hardware_interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/current/"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.common.types/current/"
    "system_hardware_interfaces/media/aidl_api/android.media.audio.eraser.types/current/"
)

# Create output directories
mkdir -p "$OUT_DIR"
mkdir -p "$OUT_DIR/include"

# Build include path arguments
INCLUDE_ARGS=()
for path in "${INCLUDE_PATHS[@]}"; do
    INCLUDE_ARGS+=("-I" "$path")
done

# Compile each AIDL file
for aidl_file in "${AIDL_FILES[@]}"; do
    echo "Compiling $aidl_file"
    
    "$AIDL" --lang=ndk \
        -o "$OUT_DIR" \
        -h "$OUT_DIR/include" \
        --structured \
        --stability=vintf \
        --min_sdk_version=31 \
        "${INCLUDE_ARGS[@]}" \
        "$aidl_file"
    
    if [ $? -ne 0 ]; then
        echo "Failed to compile $aidl_file"
        exit 1
    fi
done

echo "All AIDL files compiled successfully"
