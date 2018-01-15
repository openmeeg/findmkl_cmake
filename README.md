[![Build status](https://ci.appveyor.com/api/projects/status/b6jv06rqce382gh7?branch=master&svg=true)](https://ci.appveyor.com/project/massich/cpp-mkl-test)
[![Build status](https://travis-ci.org/massich/cpp-mkl-test.svg?branch=master)](https://travis-ci.org/massich/cpp-mkl-test.svg?branch=master)


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

