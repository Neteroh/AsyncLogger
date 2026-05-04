cmake_minimum_required(VERSION 3.20)

project(AsyncLogger
    VERSION 0.1.0
    LANGUAGES CXX
)

add_executable(AsyncLogger
    src/AsyncLogger.cpp
    include/AsyncLogger/AsyncLogger.h
)

target_compile_features(AsyncLogger PRIVATE cxx_std_20)

target_include_directories(AsyncLogger
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(MSVC)
    target_compile_options(AsyncLogger PRIVATE /W4 /permissive-)
else()
    target_compile_options(AsyncLogger PRIVATE -Wall -Wextra -Wpedantic)
endif()