# EXCEPT - An exception library for C++

| License | Linux & Windows & MacOS                                                                                                                                                     | SonarCloud |
| -------- |-----------------------------------------------------------------------------------------------------------------------------------------------------------| ------- |
| [![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](http://www.gnu.org/licenses/gpl-3.0)     | [![Build Status](https://github.com/crillab/except/actions/workflows/cmake.yml/badge.svg)](https://github.com/crillab/except/actions/workflows/cmake.yml) |  

## Description

`EXCEPT` provides classes for classic exceptions (inspired by the classic JAVA exceptions).

- `IllegalArgumentException`
- `IllegalStateException`
- `ParseException`
- `UnsupportedOperationException`
- `OSException`

## Build

The latest release is available [here](/releases/latest)

`EXCEPT` is developed using [C++ 17](https://en.cppreference.com/w/cpp/17),
[CMake 3.23](https://cmake.org/).
Installing CMake is required if you want to build from source.
To do so, after having installed all the needed tools, you will need to clone
the project:

```bash
git clone https://github.com/crillab/except.git --recursive
cd except
mkdir build
cd build 
cmake .. -DCMAKE_BUILD_TYPE=RELEASE
cmake --build . 
```

## Using CMake

This library is designed for simplified use in projects using CMake. To use this project, it is possible to
create a sub-module in your project with the following commands:

```bash
git submodule add https://github.com/crillab/except libs/except
git submodule update --remote --recursive --init
```

And then add the following instructions in your CMakeLists.txt file:

```cmake
add_subdirectory(libs/except)
add_executable(your_program main.c)
target_link_libraries(your_program exception)
```

