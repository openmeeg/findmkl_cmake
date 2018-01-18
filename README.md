[![Build status](https://ci.appveyor.com/api/projects/status/h72xi6ffbd7p22j5?svg=true)](https://ci.appveyor.com/project/massich/findmkl-cmake-test)

[![Build status](https://travis-ci.org/massich/findmkl_cmake_test.svg?branch=master)](https://travis-ci.org/massich/findmkl_cmake_test/branches)

This repo contains a FindMKL.cmake file that can be used to configure a CMake project that needs Intel MKL.

It is tested with an extremely simple example C++ application.

Tests are run on Mac, Linux and Windows, using both static or dynamic libraries.

To find the correct libraries to use at compilation, FindMKL.cmake uses the [mkl_link_tool](https://software.intel.com/en-us/articles/intel-mkl-command-line-link-tool) command. On Linux, it means that you need to be able to execute 32bits binaries (see our Travis config file).

### Installation ###
As this is an example of how to use CMake you'll need to download it (http://www.cmake.org/cmake/resources/software.html) or install it via:
```bash
sudo apt-get install cmake
```
Once CMake has been installed navigate to the root of the project and issue the following commands:
```bash
mkdir build
cd build
cmake .. && make
```

