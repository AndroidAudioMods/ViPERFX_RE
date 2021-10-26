plugins {
    id("com.android.application") version "7.0.3"
}

repositories {
    google()
    mavenCentral()
}

android {
    compileSdk = 23
    ndkVersion = "23.1.7779620"

    externalNativeBuild {
        cmake {
            version = "3.21.3"
            path = file("CMakeLists.txt")
        }
    }

    defaultConfig {
        externalNativeBuild {
            cmake {
                arguments += listOf("-DANDROID_ARM_NEON=ON", "-DANDROID_TOOLCHAIN=clang")
                cFlags += listOf("-D__STDC_FORMAT_MACROS")
                cppFlags += listOf("-fexceptions", "-frtti")
            }
        }

        ndk {
            abiFilters += listOf("armeabi-v7a","arm64-v8a","x86","x86_64")
//            abiFilters += listOf("x86", "armeabi-v7a")
//            abiFilters += listOf("x86", "x86_64", "armeabi", "armeabi-v7a", "arm64-v8a")
        }
    }
}
