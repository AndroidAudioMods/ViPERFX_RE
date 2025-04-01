cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_COMPILER_VERSION 20)
set(CMAKE_CXX_STANDARD 20)

# NDK Settings
#add_compile_definitions(ANDROID_ABI=arm64-v8a)
#add_compile_definitions(ANDROID_ABI=armeabi-v7a)
#add_compile_definitions(ANDROID_ARM_NEON=true)
#add_compile_definitions(ANDROID_PLATFORM=android-24)

project("ViPER4Android")
add_compile_definitions(VIPER_VERSION=20240314)
add_compile_definitions(__ANDROID_UNAVAILABLE_SYMBOLS_ARE_WEAK__)

## Find AIDL compiler
#find_program(AIDL_COMPILER aidl
#        PATHS ${ANDROID_SDK}/build-tools/*/
#        NO_DEFAULT_PATH)
#if(NOT AIDL_COMPILER)
#    message(FATAL_ERROR "Could not find AIDL compiler in Android SDK build tools")
#endif()
#
## Set up AIDL file generation
#set(AIDL_FILE "/home/iscle/Downloads/interfaces-refs_heads_main/audio/aidl/aidl_api/android.hardware.audio.effect/current/android/hardware/audio/effect/IEffect.aidl")
#set(AIDL_INCLUDE_DIRS
#        "/home/iscle/Downloads/interfaces-refs_heads_main/common/aidl/aidl_api/android.hardware.common/current/"
#        "/home/iscle/Downloads/interfaces-refs_heads_main/common/fmq/aidl/aidl_api/android.hardware.common.fmq/current/"
#        "/home/iscle/Downloads/interfaces-refs_heads_main/audio/aidl/aidl_api/android.hardware.audio.common/current/"
#        "/home/iscle/Downloads/interfaces-refs_heads_main/audio/aidl/aidl_api/android.hardware.audio.effect/current/"
#        "/home/iscle/Downloads/interfaces-refs_heads_main (1)/media/aidl_api/android.media.audio.common.types/current/"
#        "/home/iscle/Downloads/interfaces-refs_heads_main (1)/media/aidl_api/android.media.audio.eraser.types/current/"
#)
#
#set(AIDL_OUTPUT_DIR ${CMAKE_BINARY_DIR}/generated/aidl)
#set(AIDL_HEADER_OUTPUT_DIR ${CMAKE_BINARY_DIR}/generated/aidl/include)
#
#file(MAKE_DIRECTORY ${AIDL_OUTPUT_DIR})
#file(MAKE_DIRECTORY ${AIDL_HEADER_OUTPUT_DIR})
#
## Generate AIDL command
#set(AIDL_GENERATED_SRC ${AIDL_OUTPUT_DIR}/android/hardware/audio/effect/IEffect.cpp)
#set(AIDL_GENERATED_HEADER ${AIDL_HEADER_OUTPUT_DIR}/android/hardware/audio/effect/IEffect.h)
#
#add_custom_command(
#        OUTPUT ${AIDL_GENERATED_SRC} ${AIDL_GENERATED_HEADER}
#        COMMAND ${AIDL_COMPILER}
#        --lang=ndk
#        -o ${AIDL_OUTPUT_DIR}
#        -h ${AIDL_HEADER_OUTPUT_DIR}
#        --structured
#        --stability=vintf
#        ${AIDL_INCLUDE_DIRS_FLAGS}
#        ${AIDL_FILE}
#        DEPENDS ${AIDL_FILE}
#        COMMENT "Generating AIDL C++ bindings for IEffect"
#)
#
## Convert include dirs to -I flags
#set(AIDL_INCLUDE_DIRS_FLAGS "")
#foreach(dir ${AIDL_INCLUDE_DIRS})
#    set(AIDL_INCLUDE_DIRS_FLAGS "${AIDL_INCLUDE_DIRS_FLAGS} -I \"${dir}\"")
#endforeach()

set(AIDL_GENERATED_SRC
        src/generated/android/hardware/audio/effect/IEffect.cpp
)

# FFTS
#add_subdirectory(src/viper/ffts)

# ViPERFX
include_directories(src/cpp/include)
include_directories(src/generated/include)  # Add generated headers to include path

set(FILES
        # Add generated AIDL source
        ${AIDL_GENERATED_SRC}

        # Main
        src/cpp/viper/ViPER.cpp
        src/cpp/ViPER4Android.cpp
        src/cpp/ViperContext.cpp
        src/cpp/viper_aidl.cpp

        # Effects
        src/cpp/viper/effects/AnalogX.cpp
        src/cpp/viper/effects/ColorfulMusic.cpp
        src/cpp/viper/effects/Convolver.cpp
        src/cpp/viper/effects/Cure.cpp
        src/cpp/viper/effects/DiffSurround.cpp
        src/cpp/viper/effects/DynamicSystem.cpp
        src/cpp/viper/effects/FETCompressor.cpp
        src/cpp/viper/effects/IIRFilter.cpp
        src/cpp/viper/effects/PlaybackGain.cpp
        src/cpp/viper/effects/Reverberation.cpp
        src/cpp/viper/effects/SoftwareLimiter.cpp
        src/cpp/viper/effects/SpeakerCorrection.cpp
        src/cpp/viper/effects/SpectrumExtend.cpp
        src/cpp/viper/effects/TubeSimulator.cpp
        src/cpp/viper/effects/VHE.cpp
        src/cpp/viper/effects/ViPERBass.cpp
        src/cpp/viper/effects/ViPERClarity.cpp
        src/cpp/viper/effects/ViPERDDC.cpp

        # Utils
        src/cpp/viper/utils/AdaptiveBuffer.cpp
        src/cpp/viper/utils/Biquad.cpp
        src/cpp/viper/utils/CAllpassFilter.cpp
        src/cpp/viper/utils/CCombFilter.cpp
        src/cpp/viper/utils/CRevModel.cpp
        src/cpp/viper/utils/Crossfeed.cpp
        src/cpp/viper/utils/DepthSurround.cpp
        src/cpp/viper/utils/DynamicBass.cpp
        src/cpp/viper/utils/FIR.cpp
        src/cpp/viper/utils/Harmonic.cpp
        src/cpp/viper/utils/HiFi.cpp
        src/cpp/viper/utils/HighShelf.cpp
        src/cpp/viper/utils/IIR_1st.cpp
        src/cpp/viper/utils/IIR_NOrder_BW_BP.cpp
        src/cpp/viper/utils/IIR_NOrder_BW_LH.cpp
        src/cpp/viper/utils/MinPhaseIIRCoeffs.cpp
        src/cpp/viper/utils/MultiBiquad.cpp
        src/cpp/viper/utils/NoiseSharpening.cpp
        src/cpp/viper/utils/PassFilter.cpp
        src/cpp/viper/utils/PConvSingle.cpp
        src/cpp/viper/utils/PolesFilter.cpp
        src/cpp/viper/utils/Polyphase.cpp
        src/cpp/viper/utils/Stereo3DSurround.cpp
        src/cpp/viper/utils/Subwoofer.cpp
        src/cpp/viper/utils/TimeConstDelay.cpp
        src/cpp/viper/utils/WaveBuffer.cpp)

add_library(
        # Sets the name of the library.
        v4a_re

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ${FILES})

target_link_libraries(v4a_re log) # kissfft)
target_compile_options(v4a_re PRIVATE -flto -O3 -DNDEBUG)
#target_compile_options(v4afx_r PRIVATE -O2 -DNDEBUG -Wall -Wsign-conversion -Wno-unused-result -Wno-unneeded-internal-declaration -fstrict-aliasing -fvisibility=hidden -Wextra -Wno-unused-parameter)
