cmake_minimum_required(VERSION 3.4.1)

add_library( # Sets the name of the library.
        native-lib
        SHARED
        native-lib.cpp
        egl/EglHelper.cpp
        )

target_link_libraries(
        native-lib
        EGL
        GLESv2
        android
        log
)