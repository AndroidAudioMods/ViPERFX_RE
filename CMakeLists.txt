cmake_minimum_required(VERSION 3.16.3)

project("ViPER4Android Reworked")

set(CMAKE_CXX_COMPILER_VERSION 20)

include_directories(src/include/)

add_compile_definitions(VERSION_MAJOR=1)
add_compile_definitions(VERSION_MINOR=0)
add_compile_definitions(VERSION_REVISION=0)
add_compile_definitions(VERSION_BUILD=0)
add_compile_definitions(VERSION_CODENAME="Reworked")

set(FILES
        # Main
        src/cpp/Effect.cpp
        src/cpp/ProcessUnit_FX.cpp
        src/cpp/viper.cpp

        # Effects
        src/cpp/effects/AnalogX.cpp
        src/cpp/effects/Cure.cpp
        src/cpp/effects/DiffSurround.cpp
        src/cpp/effects/DynamicSystem.cpp
        src/cpp/effects/Reverberation.cpp
        src/cpp/effects/SpeakerCorrection.cpp
        src/cpp/effects/SpectrumExtend.cpp
        src/cpp/effects/TubeSimulator.cpp
        src/cpp/effects/VHE.cpp
        src/cpp/effects/ViPERClarity.cpp

        # Utils
        src/cpp/utils/CAllpassFilter.cpp
        src/cpp/utils/CCombFilter.cpp
        src/cpp/utils/CRevModel.cpp
        src/cpp/utils/Crossfeed.cpp
        src/cpp/utils/DepthSurround.cpp
        src/cpp/utils/DynamicBass.cpp
        src/cpp/utils/FixedBiquad.cpp
        src/cpp/utils/Harmonic.cpp
        src/cpp/utils/HiFi.cpp
        src/cpp/utils/HighShelf.cpp
        src/cpp/utils/IIR_1st.cpp
        src/cpp/utils/IIR_NOrder_BW_BP.cpp
        src/cpp/utils/IIR_NOrder_BW_LH.cpp
        src/cpp/utils/MultiBiquad.cpp
        src/cpp/utils/NoiseSharpening.cpp
        src/cpp/utils/PassFilter.cpp
        src/cpp/utils/PConvSingle_F32.cpp
        src/cpp/utils/PolesFilter.cpp
        src/cpp/utils/Subwoofer.cpp
        src/cpp/utils/TimeConstDelay.cpp
        src/cpp/utils/WaveBuffer_I32.cpp)

message(${CMAKE_BUILD_TYPE})


add_library(
        # Sets the name of the library.
        v4afx_r

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ${FILES})

find_library(log-lib log)

target_link_libraries(v4afx_r ${log-lib})
