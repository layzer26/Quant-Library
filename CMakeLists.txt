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
add_library(quantlib
    src/Date.cpp
    src/InterestRate.cpp
    src/YieldCurve.cpp
    src/DayCountConvention.cpp
    src/CashFlow.cpp
)

add_executable(test_all
    tests/test_all.cpp
    tests/test_date.cpp
    tests/test_interest_rate.cpp
    tests/test_getDaysBetween.cpp
    tests/test_isAfter.cpp
    tests/test_YieldCurve.cpp
    tests/test_cashflow.cpp
)

target_link_libraries(test_all quantlib)
target_include_directories(test_all PRIVATE include)
