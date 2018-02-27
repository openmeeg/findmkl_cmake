cmake_minimum_required (VERSION 3.2)
project (CMakeHelloWorld VERSION 1.0)

# Find the BLAS stuff
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(BLA_DEFINITIONS)

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
    set(BLA_INCLUDE_DIR ${MKL_INCLUDE_DIR})
    set(BLAS_LIBRARIES ${MKL_LIBRARIES})
    set(BLA_DEFINITIONS USE_MKL)
endif()

# Tell CMake to use rpath with the libs we build
if (APPLE)
    set(CMAKE_MACOSX_RPATH 1)
    set(CMAKE_SKIP_BUILD_RPATH  FALSE)
    set(CMAKE_INSTALL_RPATH "@executable_path/../lib/")
    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
elseif(UNIX)  # means if LINUX
    # to fix the installed rpath so it looks in ../lib
    # https://www.semipol.de/2012/02/16/relative-rpath-settings-with-cmake.html
    set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")
endif()

message(STATUS "BLAS Libraries: ${BLAS_LIBRARIES}")

# include the subdirectory containing our libs
add_subdirectory(Hello_lib)
# indicate the entry point for the executable
add_executable(hello HelloWorld.cpp)

# Indicate which libraries to include during the link process.
target_link_libraries(hello Hello_lib::Hello_lib)

install (TARGETS hello DESTINATION bin)
