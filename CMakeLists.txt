# Top-level CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(QuantLibrary)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Main library (optional if you want to make it modular)
# add_library(quantlib src/date.cpp)

# If you just want to build test executable:

# TEST TARGET
add_executable(test_tests
    src/date.cpp
    tests/test_date.cpp
)

# Add include path for test target
target_include_directories(test_tests PRIVATE include)
