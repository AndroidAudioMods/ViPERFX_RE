cmake_minimum_required(VERSION 3.19)

project("ViPER4Android Reworked")

set(CMAKE_CXX_COMPILER_VERSION 20)

include_directories(include/)

add_compile_definitions(VERSION_MAJOR=1)
add_compile_definitions(VERSION_MINOR=0)
add_compile_definitions(VERSION_REVISION=0)
add_compile_definitions(VERSION_BUILD=0)
add_compile_definitions(VERSION_CODENAME="Reworked")

set(FILES
        # Main
        src/Effect.cpp
        src/ProcessUnit_FX.cpp
        src/viper.cpp

        # Effects
        src/effects/AnalogX.cpp
        src/effects/Cure.cpp
        src/effects/DynamicSystem.cpp
        src/effects/Reverberation.cpp
        src/effects/SpeakerCorrection.cpp
        src/effects/SpectrumExtend.cpp
        src/effects/TubeSimulator.cpp

        # Utils
        src/utils/CAllpassFilter.cpp
        src/utils/CCombFilter.cpp
        src/utils/CRevModel.cpp
        src/utils/Crossfeed.cpp
        src/utils/DepthSurround.cpp
        src/utils/DynamicBass.cpp
        src/utils/FixedBiquad.cpp
        src/utils/Harmonic.cpp
        src/utils/HighShelf.cpp
        src/utils/IIR_1st.cpp
        src/utils/IIR_NOrder_BW_BP.cpp
        src/utils/IIR_NOrder_BW_LH.cpp
        src/utils/MultiBiquad.cpp
        src/utils/NoiseSharpening.cpp
        src/utils/PassFilter.cpp
        src/utils/PolesFilter.cpp
        src/utils/Subwoofer.cpp
        src/utils/TimeConstDelay.cpp
)

add_library(
        # Sets the name of the library.
        v4afx_r

	# Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ${FILES})

target_link_libraries(
        v4afx_r
        log
)
