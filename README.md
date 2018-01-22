[![Build status](https://travis-ci.org/massich/findmkl_cmake_test.svg?branch=master)](https://travis-ci.org/massich/findmkl_cmake_test/branches)
[![Build status](https://ci.appveyor.com/api/projects/status/h72xi6ffbd7p22j5?svg=true)](https://ci.appveyor.com/project/massich/findmkl-cmake-test)

This repo provides FindMKL.cmake file, which can be used to configure a CMake project that needs Intel MKL.
We basically took [this](https://github.com/jameskbride/cmake-hello-world) extremely simple C++ example,
modify the code to require MKL, provide CMake package finder for MKL and add all the Contineous Integration (CI) to test it against different scenarios. 

Tests are run on Mac, Linux and Windows, using both static or dynamic libraries.

To find the correct libraries to use at compilation, FindMKL.cmake uses the [mkl_link_tool](https://software.intel.com/en-us/articles/intel-mkl-command-line-link-tool) command. On Linux, it means that you need to be able to execute 32bits binaries (see our Travis config file).

### How to run this example ###
The best way to understand how to run a project (or install its dependencies) is always looking to CI's configuration ([.travis.yml](./.travis.yml) and [.appveyor.yml](./.appveyor.yml)). 
But as a summary, as this is an example of how to use MKL and CMake you'll need to [install MKL](https://software.intel.com/en-us/articles/intel-mkl-113-install-guide) and [download CMake](http://www.cmake.org/cmake/resources/software.html). If you are using an ubuntu, CMake can be install it via:
```bash
sudo apt-get install cmake
```
Once CMake and MKL have been installed navigate to the root of the project and issue the following commands:
```bash
mkdir build
cd build
cmake .. && cmake --build .
```

### How to use this project ###
Actually you can use this project in whatever manner you like. But we think that there are two main ways to use this project:

1. Clone/Fork/Download the entire project and use it as your starting point. This has the advantage that travis and appveyor would be already configured, for you. The only step required to have CI up and running would be to activate your porject in those platforms.

2. Download [`FindMKL.cmake`](./cmake/FindMKL.cmake) and place it wherever is needed in your project.
