# Quant-Library

A modern C++ quantitative finance library inspired by QuantLib.  
This project provides reusable components for date handling, interest rate modeling, financial calculations, and quantitative models — with a focus on clean architecture, extensibility, and testability.

## Features

- Date utilities
  - Business day calculation
  - Basic calendar support
  - Date formatting and conventions
- Interest rate models
  - Simple and compound interest
  - Support for variable compounding frequencies
  - Variance-adjusted rates
  - Simulate monthly contributions
- Modular architecture (easy to extend)
- Built with CMake
- Unit tests included

## Project Structure

Quant-Library/
├── CMakeLists.txt
│
├── include\quantlib
│ └── Date.h
│ └──InterestRate.h
│
├── src/ # Core source code
│ └── Date.cpp 
│ └── InterestRate.cpp
│
├── tests/ # Unit tests
│ └── test_date.cpp
│ └── test_interest_rate.cpp


## Build Instructions

### Prerequisites

- CMake >= 3.15
- GCC >= 9.0 (tested with GCC 14.2)
- C++17 or higher
- MSYS2 / MinGW64 (Windows)

### Building the Project

mkdir build
cd build
cmake ..
cmake --build .
---

## Implemented Classes

### QuantLib::Date

Models calendar dates

Business day checks

Date comparison via isAfter()

Day difference via getDaysBetween()

Display and format utilities

### QuantLib::InterestRate

Models interest rates

Supports:

Simple interest

Compound interest

Compound interest with variance

Compound interest with monthly contributions

Multiple compounding frequencies (Annual, SemiAnnual, Quarterly, Monthly, Daily)

## Roadmap

- Core Date class
- Calendar conventions
- Interest rate models
- Day count conventions
- Yield curve bootstrapping
- Option pricing (Black-Scholes, Binomial trees)
- Portfolio valuation framework
- Documentation

## Contributing

Contributions are welcome.  
To get started:

1. Fork this repository
2. Clone your fork:
3. Create a branch:
4. Commit your changes
5. Submit a Pull Request

## License

This project is licensed under the MIT License.  
See [LICENSE](LICENSE) for details.

## About

Developed by [Liam Naidoo](https://github.com/layzer26) as a portfolio project to explore quantitative finance and C++ best practices.

