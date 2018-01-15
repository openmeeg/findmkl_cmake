[![Build status](https://ci.appveyor.com/api/projects/status/h72xi6ffbd7p22j5?svg=true)](https://ci.appveyor.com/project/massich/findmkl-cmake-test)

[![Build status](https://travis-ci.org/massich/findmkl_cmake_test.svg?branch=master)](https://travis-ci.org/massich/findmkl_cmake_test/branches)


This is an extremely simple example C++ application which uses CMake to build a hello that links in different manners to LAPACK.

### Installation ###
As this is an example of how to use CMake you'll need to download it (http://www.cmake.org/cmake/resources/software.html) or install it via:
```bash
sudo apt-get install cmake
```
Once CMake has been install navigate to the root of the project and issue the following commands:
```bash
mkdir build
cd build
cmake .. && make
```

