cmake_minimum_required(VERSION 3.19)

project("ViPER4Android Reworked")

set(CMAKE_CXX_COMPILER_VERSION 20)

include_directories(include/)
message(${ANDROID_NDK}/include/)

set(FILES
        # Main
        src/Effect.cpp
        src/ProcessUnit_FX.cpp
        src/viper.cpp

        # Effects
        src/effects/Cure.cpp
        src/effects/TubeSimulator.cpp

        # Utils
        src/utils/CAllpassFilter.cpp
        src/utils/Crossfeed.cpp
        src/utils/FixedBiquad.cpp
        src/utils/IIR_1st.cpp
        src/utils/IIR_NOrder_BW_BP.cpp
        src/utils/IIR_NOrder_BW_LH.cpp
        src/utils/MultiBiquad.cpp
        src/utils/PassFilter.cpp
        src/utils/TimeConstDelay.cpp
)

add_library(
        # Sets the name of the library.
        v4afx_r

	# Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ${FILES})

