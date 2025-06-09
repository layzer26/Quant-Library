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

# TEST TARGETS
## Date Test Target
add_executable(test_date
    src/date.cpp
    tests/test_date.cpp
    
)
target_include_directories(test_date PRIVATE include)

##Interest Rate Test Target
add_executable(test_interest_rate
    src/InterestRate.cpp
    tests/test_interest_rate.cpp
)


# Add include path for test target
target_include_directories(test_interest_rate PRIVATE include)
