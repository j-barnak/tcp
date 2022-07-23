cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(tcp)

set(SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp 
)

add_executable(tcp ${SOURCES})

# DEPENDENCIES
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
target_include_directories(tcp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Debugging Options
add_compile_options(-Wall -W -Werror -g -ggdb)
target_compile_features(tcp
    PRIVATE
        cxx_std_20
)

target_link_libraries(tcp ${CONAN_LIBS})
