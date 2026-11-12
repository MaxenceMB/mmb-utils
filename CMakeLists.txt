cmake_minimum_required(VERSION 3.28)

project(mmbUtils
    VERSION 0.1.0
    DESCRIPTION "Utility library used in most MMB C++ projects."
    LANGUAGES CXX)

add_library(mmbUtils STATIC
    mmbUtils/src/Logs.cpp
    mmbUtils/include/mmb/Logs.h
)
add_library(mmb::Utils ALIAS mmbUtils)

target_include_directories(mmbUtils PUBLIC
    # Users write: #include <mmb/Logs.h>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/mmbUtils/include>
)

target_compile_features(mmbUtils PUBLIC cxx_std_20)

if(MSVC)
    target_compile_options(mmbUtils PRIVATE /W4 /permissive- /utf-8)
else()
    target_compile_options(mmbUtils PRIVATE -Wall -Wextra -Wpedantic)
endif()

set_target_properties(mmbUtils PROPERTIES FOLDER "external")
