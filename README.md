# Singleton pattern examples in C++

A collection of minimal, self-contained C++ examples demonstrating multiple ways to implement the Singleton design pattern. The repository includes modern, thread-safe techniques (Meyer's Singleton) and legacy aproaches (Double-Checked Locking) for comparison.

## 🔍 Overview

### 1️⃣ singleton-classic-example

* 🔳 **Singleton with a static member instance.**
* 🧩 **Static member variable**
* 💾 **Static memory allocation**
* ⚡ **Eager initialization** → Created before `main` starts
* 🧼 **Automatic cleanup** → Destroyed after `main` exits
* 🔒 **Initialization is Thread-safe**
    * The static member is initialized before `main` in a single-threaded context, so no construction race is possible.
* ⚠️ **Static Initialization Order Fiasco**
    * Can suffer from SIOF If the singleton instance is accessed during the initialization of another static object, it may lead to UB due to the order of initialization.
* ⚠️ **Static Destruction Order Fiasco**
    * A symmetric problem, If one static object's destructor calls another static that has been destroyed, it results in UB.

### 2️⃣ singleton-meyers-example

* 🔳 **Meyer's Singleton** → The simplest and safest modern C++ singleton implementation.
* 🧩 **Static local variable**
* 💾 **Static memory allocation**
* ⏳ **Lazy initialization** → Created only on first call to `getInstance()`
* 🧼 **Automatic cleanup** → Destroyed after `main` exits
* 🔒 **Initialization is Thread-safe since C++11**
    * A function-local static variable is initialized exactly once, even in a multi-threaded environment.
* ⚠️ The Meyer's Singleton fixes **Static Initialization Order Fiasco**, but can suffer from **Static Destruction Order Fiasco**.

### 3️⃣ singleton-classic-dynamic-example
* **Singleton with a static member pointer** → Dynamically allocated on first use.
* 🧩 **Static member pointer**
* 💾 **Dynamic memory allocation**
* ⏳ **Lazy initialization** → Created only on first call to `getInstance()`
* 🧹 **Manual cleanup** → Requires manual destruction via `delInstance()`
* ⚠️ **Not Thread-safe**
    * Two threads could call `delInstance()` simultaneously, or one calls `getInstance()` while another calls `delInstance()`, leading to a race on the pointer.
* ⚠️ **Static Destruction Order Fiasco**
    * If another static's destructor calls `getInstance()` after `delInstance()` has run, you're dereferencing a deleted pointer, right back to UB.
* ❗ Not recommended for multi-threaded applications.


### 4️⃣ singleton-cherno-example
* **Cherno-style Singleton** → [Why I don't like Singletons - Youtube](https://youtu.be/IMZMLvIwa-k?si=Q__9r--DOre6jahY)
* 🧩 **Static global variable**
* 💾 **Dynamic memory allocation**
* ⏳ **Lazy initialization** → Created only on first call to `getInstance()`
* 🧹 **Manual cleanup** → Requires manual destruction via `delInstance()`
* ⚠️ **Not Thread-safe** → Same as [singleton-classic-dynamic-example](#3️⃣-singleton-classic-dynamic-example)
* ❗ Not recommended for multi-threaded applications.

### 5️⃣ singleton-dclp-example
* **Singleton with Double-Checked Locking Pattern (DCLP)** → Classic but unsafe lazy-initialization pattern.
* 🧩 **Static member pointer**
* 💾 **Dynamic memory allocation**
* ⏳ **Lazy initialization** → Created only on first call to `getInstance()`
* 🧹 **Manual cleanup** → Requires manual destruction via `delInstance()`
* ⚠️ **Not Thread-safe** → Suffers from data races and reordering issues.
* ❌ **DCLP is unreliable** → Multiple threads may observe a partially constructed object.
* ⛔ **Obsoleted by C++11** → Local static initialization is the correct modern solution.
* Reference: [C++ and the Perils of Double-Checked Locking by Scott Meyers and Andrei Alexandrescu](https://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf)

### 6️⃣ singleton-leaky-example
* 🔳 **"Leaky" Singleton** → A heap-allocated Meyer's Singleton.
* 🧩 **Static local pointer**
* 💾 **Dynamic memory allocation**
* ⏳ **Lazy initialization** → Created only on first call to `getInstance()`
* 🧹 **No cleanup** → You are intentionally leaking the memory.
    * When the process ends, the Operating System reclaims the entire memory block anyway. "Leaking" at process exit is technically harmless.
* 🔒 **Initialization is Thread-safe since C++11**
    * The local static pointer initialization is still protected by C++11's thread-safe static init guarantee, so the `new` only fires once, safely.
* ❎ **Avoids Static Initialization Order Fiasco**
    * Since the destructor is never called, it can't try to access other dead objects during shutdown.

---

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
cmake --build --preset linux-ninja-debug --target 02-singleton-meyers-example
```

## 🏃 Running Examples

### 🖥️ Windows (MSVC)
```bash
build/windows-msvc/singleton-meyers-example/Debug/02-singleton-meyers-example.exe
```

### 🖥️ Windows (MinGW)
```bash
build/windows-ninja-debug/singleton-meyers-example/02-singleton-meyers-example.exe
```


### 🐧 Linux
```bash
./build/linux-ninja-debug/singleton-meyers-example/02-singleton-meyers-example
```

