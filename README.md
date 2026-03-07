# Singleton pattern examples in C++

A collection of minimal, self-contained C++ examples demonstrating multiple ways to implement the Singleton design pattern. The repository includes modern, thread-safe techniques (Meyers Singleton) and legacy aproaches (Raw Pointers, Double-Checked Locking) for comparison.

## 🔍 Overview

### 1️⃣ singleton-classic-example

* 🔳 Singleton with a static member instance.

* 🧩 Static member variable

* 💾 Static memory allocation

* ⚡ Eager initialization → constructed before `main` starts

* 🧼 Automatic cleanup → destroyed after `main` exits

* 🔒 Initialization is Thread-safe
    * The static member is initialized before `main` in a single-threaded context, so no construction race is possible.

* ⚠️ Can suffer from the *Static Initialization Order Fiasco*
    * If the singleton instance is accessed during the initialization of another static object, it may lead to UB due to the order of initialization.

* ⚠️ A symmetric problem, it can suffer from *Static Destruction Order Fiasco*.
    * If one static object's destructor calls another static that has been destroyed, it results in UB. 

### 2️⃣ singleton-meyers-example

* 🔳 Meyer's Singleton → The simplest and safest modern C++ singleton implementation.

* 🧩 Static local variable

* 💾 Static memory allocation

* ⏳ Lazy initialization → constructed only on first call to `getInstance()`

* 🧼 Automatic cleanup → destroyed after `main` exits

* 🔒 Initialization is Thread-safe since C++11
    * A function-local static variable is initialized exactly once, even in a multi-threaded environment.

* The Meyer's Singleton fixes *Static Initialization Order Fiasco*, but can suffer from *Static Destruction Order Fiasco*.

* 👌 This is the best and simplest way to implement a singleton in C++11 and later.

### ⭐ singleton-cherno-example
* Cherno-style Singleton - https://youtu.be/IMZMLvIwa-k?si=Q__9r--DOre6jahY
* 🧩 Static global variable
* 💾 Dynamic memory allocation
* ⏳ Lazy initialization
* 🧹 Manual destruction required (via delInstance())
* ⚠️ Not thread-safe
* 🔴 Suitable only for single-threaded

### ⭐ singleton-classic-dynamic-example
* Singleton with a static member pointer — dynamically allocated on first use.
* 🧩 Static member pointer
* 💾 Dynamic memory allocation
* ⏳ Lazy initialization (created only on first call to getInstance())
* 🧹 Requires manual destruction via delInstance()
* ⚠️ Not thread-safe
* 🔴 Not recommended for multi-threaded applications

### ⭐ singleton-dclp-example
* Double-Checked Locking Pattern (DCLP) — classic but unsafe lazy-initialization pattern.
* 🧩 Static member pointer
* 💾 Dynamic memory allocation
* ⏳ Lazy initialization
* 🧹 Destroyed manually via delInstance()
* ⚠️ Not thread-safe in C++ — suffers from data races and reordering issues
* ❌ DCLP is unreliable because multiple threads may observe a partially constructed object
* ⛔ Obsoleted by C++11 (local static initialization is the correct modern solution)
* Reference: [https://www.aristeia.com/Papers/DDJ_Jul_Aug_2004](https://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf)

### ⭐ singleton-smart-pointer-example
* Singleton using a static local smart pointer
* 🧩 Static local variable
* 💾 Dynamic memory allocation
* ⏳ Lazy initialization (instance created on first getInstance() call)
* 🧼 Automatically destroyed after main() exits
* 🔒 Thread-safe initialization (C++11+)

## ⚙️ Prerequisites

Before building, ensure you have the following installed:

### Common Requirements (All Platforms)

* **CMake** (v3.20 or newer required for Presets)
* **Ninja** (Used on Linux and Windows (GCC))

### 🖥️ Windows - Visual Studio MSVC (Preset: windows-msvc)

* **Visual Studio 2022**
* **Workload Required: Desktop development with C++**
* **Note: The preset uses the Visual Studio 17 2022 generator.**

### 🖥️ Windows - MinGW (Preset: windows-ninja-debug)

* **MinGW-w64 Toolchain**
* **Generator: Ninja**
* **Configuration: The bin folder of your MinGW installation (e.g., C:\msys64\mingw64\bin) must be in your system PATH environment variable.**

### 🐧 Linux (Preset: linux-ninja-debug)

* **C++ Compiler: GCC or Clang (supporting C++11)**
* **Generator: Ninja**
* **Install Command (Ubuntu/Debian):** ```bash sudo apt update && sudo apt install build-essential ninja-build cmake ```

## 🏗️ Build Instructions

The commands below are executed from the **root of the repository**.

### 1. Configure Workspace (Run Once)

#### 🖥️ Windows (MSVC)

```bash
cmake --preset windows-msvc
```

#### 🖥️ Windows (MinGW - Debug)

```bash
cmake --preset windows-ninja-debug
```

#### 🐧 Linux (Ninja - Debug)

```bash
cmake --preset linux-ninja-debug
```

### Build All (Debug)

#### 🖥️ Windows (MSVC)

```bash
cmake --build --preset windows-msvc-debug
```

#### 🖥️ Windows (MinGW - Debug)

```bash
cmake --build --preset windows-ninja-debug
```

#### 🐧 Linux (Ninja - Debug)

```bash
cmake --build --preset linux-ninja-debug
```

### Build Specific Project

```bash
cmake --build --preset <preset> --target <target_name>
```

Example:
```bash
cmake --build --preset linux-ninja-debug --target singleton-meyers-example
```

## 🏃 Running Examples

### 🖥️ Windows (MSVC)
```bash
build/windows-msvc/singleton-meyers-example/Debug/singleton-meyers-example.exe
```

### 🖥️ Windows (MinGW)
```bash
build/windows-ninja-debug/singleton-meyers-example/singleton-meyers-example.exe
```


### 🐧 Linux
```bash
./build/linux-ninja-debug/singleton-meyers-example/singleton-meyers-example
```

