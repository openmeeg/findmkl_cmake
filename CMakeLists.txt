cmake_minimum_required (VERSION 3.2)
project (CMakeHelloWorld)

#version number
set (CMakeHelloWorld_VERSION_MAJOR 1)
set (CMakeHelloWorld_VERSION_MINOR 0)

# Find the BLAS stuff
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

set(BLA_DEFINITIONS)

if (BLA_VENDOR MATCHES Intel)
    if ("$ENV{MKLROOT}" STREQUAL "")
        message(FATAL_ERROR "MKLROOT is not set. Please source the Intel MKL mklvars.sh file.")
    endif()

    # user defined options for MKL
    option(MKL_USE_parallel "Use MKL parallel" True)
    option(MKL_USE_sdl "Single Dynamic Library or static/dynamic" False)
    set(MKL_USE_interface "lp64" CACHE STRING "for Intel(R)64 compatible arch: ilp64/lp64 or for ia32 arch: cdecl/stdcall")

    if (BLA_VENDOR MATCHES "_seq")
        set(MKL_USE_parallel OFF)
    else()
        set(MKL_USE_parallel ON)
    endif()

    find_package(MKL REQUIRED)

    if (MKL_FOUND)
        include_directories(${MKL_INCLUDE_DIR})
        set(BLAS_LIBRARIES ${MKL_LIBRARIES})
        set(BLA_DEFINITIONS USE_MKL)
    endif()
else()
    find_package(BLAS REQUIRED)
    if (BLA_VENDOR MATCHES ATLAS)
        find_library(CBLAS_LIB NAMES cblas)
        set(BLAS_LIBRARIES "${BLAS_LIBRARIES};${CBLAS_LIB}")
    endif()
endif()

message(STATUS "BLAS Libraries: ${BLAS_LIBRARIES}")

# include the subdirectory containing our libs
add_subdirectory(Hello)
include_directories(Hello)
# indicate the entry point for the executable
add_executable(CMakeHelloWorld Hello HelloWorld.cpp)

# Indicate which libraries to include during the link process.
target_link_libraries(CMakeHelloWorld Hello ${BLAS_LIBRARIES})

# install (TARGETS CMakeHelloWorld DESTINATION bin)
