# Singleton Pattern Examples in C++

A collection of minimal, self-contained C++ examples demonstrating multiple ways to implement the Singleton design pattern. The repository includes modern, thread-safe techniques (Meyer's Singleton) and legacy approaches (Double-Checked Locking) for comparison.

## 🔍 Overview

<table>
  <thead>
    <tr>
      <th>Example</th>
      <th>Initialization</th>
      <th>Storage duration</th>
      <th>Cleanup</th>
      <th>Thread-safe Initialization</th>
      <th>Notes</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>singleton-classic-example</code></td>
      <td>Eager</td>
      <td>Static</td>
      <td>Automatic</td>
      <td>Yes</td>
      <td>
      Can suffer from SIOF and static destruction order issues.
      </td>
    </tr>
    <tr>
      <td><code>singleton-meyers-example</code></td>
      <td>Lazy</td>
      <td>Static</td>
      <td>Automatic</td>
      <td>Yes (since C++11)</td>
      <td>
        Avoids classic SIOF because the object is created on first use.<br><br>
        May still suffer from static destruction order issues during program shutdown.
      </td>
    </tr>
    <tr>
      <td><code>singleton-classic-dynamic-example</code></td>
      <td>Lazy</td>
      <td>Dynamic</td>
      <td>Manual</td>
      <td>No</td>
      <td>
        Races may occur if multiple threads call <code>getInstance()</code> or
        <code>delInstance()</code> concurrently.<br><br>
        Manual lifetime management is error-prone.
      </td>
    </tr>
    <tr>
      <td><code>singleton-cherno-example</code></td>
      <td>Lazy</td>
      <td>Dynamic</td>
      <td>Manual</td>
      <td>No</td>
      <td>
        Similar problems to <code>singleton-classic-dynamic-example</code>: manual cleanup,
        unsafe lifetime management and no thread safety.
      </td>
    </tr>
    <tr>
      <td><code>singleton-dclp-example</code></td>
      <td>Lazy</td>
      <td>Dynamic</td>
      <td>Manual</td>
      <td>No</td>
      <td>
        Classic Double-Checked Locking Pattern (DCLP).<br><br>
        Historically unsafe because of data races and reordering issues.<br><br>
        Obsolete in modern C++.
      </td>
    </tr>
    <tr>
      <td><code>singleton-leaky-example</code></td>
      <td>Lazy</td>
      <td>Dynamic</td>
      <td>None</td>
      <td>Yes (since C++11)</td>
      <td>
        Intentionally leaks memory to avoid shutdown-order problems.<br><br>
        Useful when destruction order is more dangerous than not deleting the instance.
      </td>
    </tr>
  </tbody>
</table>

---

### 1️⃣ singleton-classic-example

🔳 **Singleton with a static member instance.**
* 🧩 **Variable**: Static member variable
* 💾 **Storage**: Static storage duration
* ⚡ **Initialization:** Eager → Created before `main()` starts
* 🧼 **Cleanup:** Automatic → Destroyed after `main()` exits
* 🔒 **Thread safety:** Construction is effectively safe because initialization happens before `main()` in a single-threaded context
* ⚠️ **Static Initialization Order Fiasco ([SIOF](https://en.cppreference.com/w/cpp/language/siof.html)):**
    * If a static object in another translation unit accesses the singleton during its own initialization, the singleton may not be constructed yet.
* ⚠️ **Static Destruction Order Fiasco:**
    * If a static object in another translation unit accesses the singleton during its own destruction, the singleton may already have been destroyed.

### 2️⃣ singleton-meyers-example

🔳 **Meyer's Singleton** → The simplest and safest modern C++ singleton implementation.
* 🧩 **Variable**: Static local variable
* 💾 **Storage**: Static storage duration
* ⏳ **Initialization:** Lazy → Created only on first call to `getInstance()`
* 🧼 **Cleanup:** Automatic → Destroyed after `main()` exits
* 🔒 **Thread safety:** Initialization is thread-safe since C++11
    * A function-local static variable is initialized exactly once, even in a multi-threaded environment.
* ✅ **Fixes SIOF:** Avoids the classic static initialization order problem because the object is created on first use.
* ⚠️ **Still vulnerable to Static Destruction Order Fiasco**

### 3️⃣ singleton-classic-dynamic-example

🔳 **Singleton with a static member pointer** → Dynamically allocated on first use.
* 🧩 **Variable**: Static member pointer
* 💾 **Storage**: Dynamic storage duration
* ⏳ **Initialization:** Lazy → Created only on first call to `getInstance()`
* 🧹 **Cleanup:** Manual → Requires manual destruction via `delInstance()`
* ⚠️ **Thread safety:** Not guaranteed
    * Two threads could call `delInstance()` simultaneously, or one calls `getInstance()` while another calls `delInstance()`, leading to a race on the pointer.
* ⚠️ **Manual lifetime management is error-prone**
    * Because the singleton is destroyed explicitly via `delInstance()`, the program must ensure no code still uses the old instance after deletion.


### 4️⃣ singleton-cherno-example

🔳 **Cherno-style Singleton** — inspired by [Why I don't like Singletons - Cherno](https://youtu.be/IMZMLvIwa-k?si=Q__9r--DOre6jahY)

* 🧩 **Variable**: Static global pointer
* 💾 **Storage**: Dynamic storage duration
* ⏳ **Initialization:** Lazy → Created only on first call to `getInstance()`
* 🧹 **Cleanup:** Manual → Requires manual destruction via `delInstance()`
* ⚠️ **Thread safety:** Not guaranteed, same as [singleton-classic-dynamic-example](#3️⃣-singleton-classic-dynamic-example)
* ⚠️ **Manual lifetime management is error-prone** → Same as [singleton-classic-dynamic-example](#3️⃣-singleton-classic-dynamic-example)

### 5️⃣ singleton-dclp-example

🔳 **Singleton with Double-Checked Locking Pattern (DCLP)** → Classic, but unsafe lazy-initialization pattern.
* 🧩 **Variable**: Static member pointer
* 💾 **Storage**: Dynamic storage duration
* ⏳ **Initialization:** Lazy → Created only on first call to `getInstance()`
* 🧹 **Cleanup:** Manual → Requires manual destruction via `delInstance()`
* ⚠️ **Thread safety:** Not guaranteed, suffers from data races and reordering issues.
* ❌ **DCLP is unreliable** → Multiple threads may observe a partially constructed object.
* ⛔ **Largely obsolete since C++11** → Thread-safe function-local static initialization is the simpler and preferred modern solution.
* 📖 **Reference:** [C++ and the Perils of Double-Checked Locking by Scott Meyers and Andrei Alexandrescu](https://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf)

### 6️⃣ singleton-leaky-example

🔳 **"Leaky" Singleton** → A heap-allocated singleton initialized through a function-local static pointer.
* 🧩 **Variable**: Static local pointer
* 💾 **Storage**: Dynamic storage duration
* ⏳ **Initialization:** Lazy → Created only on first call to `getInstance()`
* 🧹 **Cleanup:** No cleanup, the object is intentionally never deleted.
    * The memory is intentionally left allocated until process termination.
    * In practice, the operating system reclaims the memory when the process exits.
* 🔒 **Thread safety:** Initialization is thread-safe since C++11
    * The local static pointer initialization is still protected by C++11's thread-safe static init guarantee, so the `new` only fires once, safely.
* ✅ **Avoids both construction and destruction order problems**
    * Because the object is created on first use, it avoids SIOF
    * Because it is never destroyed, it avoids static destruction order issues
* ⚠️ **Trade-off:** intentionally leaks memory by design
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

* **C++ Compiler: GCC 10+ or Clang 10+ (supporting C++20)**
* **Generator: Ninja**
* **Install Command (Ubuntu/Debian):** ```bash sudo apt update && sudo apt install build-essential ninja-build cmake ```
* **Note:** GCC 10+ is available by default on Ubuntu 22.04+. On older distros, install via `sudo apt install gcc-10 g++-10`.

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
