# Quant Library (C++)

This is a professional Quantitative Finance C++ Library project.

The goal of this library is to provide reusable, well-tested components for quantitative finance applications. The code is written in modern C++17, built with CMake, and organized for scalability and maintainability.

## Current Module

### Date & Calendar Module

Implements:

- Date class
    - getDay()
    - getMonth()
    - getYear()
    - display()
    - dayOfWeek()  (0 = Saturday, ..., 6 = Friday)
    - isBusinessDay() (returns true if Monday-Friday)

## Purpose

Core Date & Calendar engine for the future Quant Library.

Used in:

- Bond pricing
- Option expiry calculation
- Monte Carlo simulation grids
- Risk reporting
- Yield curves

Foundation for:

- Business day conventions
- Holiday calendars
- Day count conventions

## Build Instructions

### Prerequisites

- GCC (tested with GCC 15.1, MinGW64)
- CMake >= 3.10
- Make (mingw32-make on Windows)

### Build

In MSYS2 MinGW64 shell:

