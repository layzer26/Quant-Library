# Quant-Library

A modern C++ quantitative finance library inspired by QuantLib.  
This project provides reusable components for date handling, financial calculations, and quantitative models, with a focus on clean architecture and testability.

## Features

- Date utilities (business days, calendars, conventions)
- Financial models (coming soon)
- Modular architecture
- Built with CMake
- Unit tests included

## Project Structure

Quant-Library/
├── CMakeLists.txt
├── src/ # Core source code
│ └── Date.cpp/hpp # Example module
├── tests/ # Unit tests
│ └── test_date.cpp
└── build/ # (generated) build files

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

