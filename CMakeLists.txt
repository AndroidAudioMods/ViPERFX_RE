cmake_minimum_required(VERSION 3.16.3)
set(CMAKE_CXX_COMPILER_VERSION 20)

# NDK Settings
#set(ANDROID_ABI arm64-v8a)
set(ANDROID_ABI armeabi-v7a)
set(ANDROID_ARM_NEON true)
set(ANDROID_PLATFORM android-21)

project("ViPER4Android")
add_compile_definitions(VERSION_CODE=1)
add_compile_definitions(VERSION_NAME="1.0.0")

## KISS FFT
#set(KISSFFT_PKGCONFIG OFF)
#set(KISSFFT_STATIC ON)
#set(KISSFFT_TEST OFF)
#set(KISSFFT_TOOLS OFF)
#add_subdirectory(src/cpp/viper/kissfft)

# ViPERFX
include_directories(src/include)

set(FILES
        # Main
        src/viper/ViPER.cpp
        src/ViPER4Android.cpp

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

message(${CMAKE_BUILD_TYPE})

add_library(
        # Sets the name of the library.
        v4afx_r

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ${FILES})

target_link_libraries(v4afx_r log) # kissfft)
target_compile_options(v4afx_r PRIVATE -Wall -Wextra -Wno-unused-parameter)
