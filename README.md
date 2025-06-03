
QUANT-LIBRARY-cpp/      <-- Project root folder
├── CMakeLists.txt      <-- Build system config
├── include/            <-- Public header files
│   └── quantlib/
│       └── date.h
├── src/                <-- Small executables, demos
│   └── test_date.cpp
├── tests/              <-- Unit tests
│   └── test_date.cpp
└── README.md           

Understood — here is a **clean, professional version** of the README and .gitignore for your GitHub repository — **no emojis, no fluff**, fully suitable for a professional GitHub portfolio:

---

# Quant-Library: Date & Calendar Module (C++)

This is the first module of a professional Quantitative Finance C++ Library project.

The goal of this library is to provide reusable, well-tested components for quantitative finance applications. The code is written in modern C++17, built with CMake, and organized for scalability and maintainability.

## Module Features

### Date class

* Represents a date: day, month, year
* Public API:

  * `getDay()`
  * `getMonth()`
  * `getYear()`
  * `display()`
  * `dayOfWeek()`
    Returns weekday (0 = Saturday, ..., 6 = Friday)
  * `isBusinessDay()`
    Returns whether the date is a business day (Monday to Friday, weekends excluded)

## Purpose of this Module

This is the core Date & Calendar engine for the future Quant Library.

It will be used in:

* Bond pricing
* Option expiry calculation
* Monte Carlo simulation grids
* Risk reporting
* Yield curves

It forms the foundation for:

* Business day conventions
* Holiday calendars
* Day count conventions

## Build Instructions

### Prerequisites

* GCC (tested with GCC 15.1, MinGW64)
* CMake >= 3.10
* Make (mingw32-make on Windows)

### Build

In MSYS2 MinGW64 shell:

```
cd /path/to/Quant-Library
mkdir -p build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
```

### Run

```
./test_date.exe
```

## Example Output

```
Date: 15/3/2023
Day of week (0=Sat, ..., 6=Fri): 3
The date is a business day.
```

## Planned Features

* Calendar class (with holiday support)
* advance() method to move dates by N business days
* dayCountFraction() for yield curves and bonds
* Unit tests with GoogleTest
* GitHub Actions CI for continuous integration

## Project Goals

This Quant Library project demonstrates:

* Clean modern C++ design
* Use of CMake and unit testing
* Core quantitative finance models
* Reusable and scalable architecture suitable for professional fintech projects and portfolios

## Status

Module 1 (Date & Calendar) — Completed and tested

---

And here is a recommended `.gitignore` for your project:

---

# .gitignore

```
# Build folders
/build/
/CMakeFiles/
/CMakeCache.txt
/Makefile
/*.o
/*.obj

# Executables
/*.exe

# IDE files (optional)
/.vscode/
/.idea/

