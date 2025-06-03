
cmake_minimum_required(VERSION 3.10)

project(QuantLibCpp VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 
include_directories(include)
#  QuantLib library
add_executable(test_date src/test_date.cpp src/date.cpp)

# TO DO: Add QuantLib library as a dependency
# Find the QuantLib package
# Note: No library yet — will add later with add_library()
# Link the QuantLib library to  test executable  