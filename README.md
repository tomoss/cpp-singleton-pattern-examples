# Singleton pattern examples in C++

A collection of minimal, self-contained C++ examples demonstrating multiple ways to implement the Singleton design pattern. The repository includes modern, thread-safe techniques (Meyers Singleton) and legacy aproaches (Raw Pointers, Double-Checked Locking) for comparison.

## Prerequisites

Before building, ensure you have the following installed:

### Common Requirements (All Platforms)

* **CMake** (v3.20 or newer required for Presets)

### Windows - Visual Studio MSVC (Preset: windows-msvc)

* **Visual Studio 2022**
* **Workload Required:** Desktop development with C++
* **Note:** The preset uses the Visual Studio 17 2022 generator.

### Windows - MinGW (Preset: windows-mingw)

* **MinGW-w64 Toolchain**
* **Make Tool: mingw32-make** (Included with most MinGW installers).
* **Configuration:** The bin folder of your MinGW installation (e.g., C:\msys64\mingw64\bin) must be in your system PATH environment variable.

### Linux (Preset: linux-ninja)

* **C++ Compiler:** GCC or Clang (supporting C++17)

* **Generator: Ninja Build System**

Install Command (Ubuntu/Debian):
```bash
sudo apt update && sudo apt install build-essential ninja-build cmake
```
