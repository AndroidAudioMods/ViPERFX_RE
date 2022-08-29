cmake_minimum_required(VERSION 3.16.3)
set(CMAKE_CXX_COMPILER_VERSION 20)

project("ViPER4Android Reworked")
add_compile_definitions(VERSION_MAJOR=1)
add_compile_definitions(VERSION_MINOR=0)
add_compile_definitions(VERSION_CODENAME="Reworked")

# KISS FFT
set(KISSFFT_PKGCONFIG OFF)
set(KISSFFT_STATIC ON)
set(KISSFFT_TEST OFF)
set(KISSFFT_TOOLS OFF)
add_subdirectory(src/cpp/viper/kissfft)

# ViPERFX
include_directories(src/include)

set(FILES
        # Main
        src/cpp/viper/Effect.cpp
        src/cpp/viper/ViPER.cpp
        src/cpp/ViPER4Android.cpp

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
        src/cpp/viper/utils/AdaptiveBuffer_F32.cpp
        src/cpp/viper/utils/CAllpassFilter.cpp
        src/cpp/viper/utils/CCombFilter.cpp
        src/cpp/viper/utils/CRevModel.cpp
        src/cpp/viper/utils/Crossfeed.cpp
        src/cpp/viper/utils/DepthSurround.cpp
        src/cpp/viper/utils/DynamicBass.cpp
        src/cpp/viper/utils/FixedBiquad.cpp
        src/cpp/viper/utils/Harmonic.cpp
        src/cpp/viper/utils/HiFi.cpp
        src/cpp/viper/utils/HighShelf.cpp
        src/cpp/viper/utils/IIR_1st.cpp
        src/cpp/viper/utils/IIR_NOrder_BW_BP.cpp
        src/cpp/viper/utils/IIR_NOrder_BW_LH.cpp
        src/cpp/viper/utils/MultiBiquad.cpp
        src/cpp/viper/utils/NoiseSharpening.cpp
        src/cpp/viper/utils/PassFilter.cpp
        src/cpp/viper/utils/PConvSingle_F32.cpp
        src/cpp/viper/utils/PolesFilter.cpp
        src/cpp/viper/utils/Subwoofer.cpp
        src/cpp/viper/utils/TimeConstDelay.cpp
        src/cpp/viper/utils/WaveBuffer_I32.cpp)

message(${CMAKE_BUILD_TYPE})

add_library(
        # Sets the name of the library.
        v4afx_r

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ${FILES})

target_link_libraries(v4afx_r log kissfft)
