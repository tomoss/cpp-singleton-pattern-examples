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

---

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

---

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

---

### 4️⃣ singleton-cherno-example

🔳 **Cherno-style Singleton** — inspired by [Why I don't like Singletons - Cherno](https://youtu.be/IMZMLvIwa-k?si=Q__9r--DOre6jahY)

* 🧩 **Variable**: Static global pointer
* 💾 **Storage**: Dynamic storage duration
* ⏳ **Initialization:** Lazy → Created only on first call to `getInstance()`
* 🧹 **Cleanup:** Manual → Requires manual destruction via `delInstance()`
* ⚠️ **Thread safety:** Not guaranteed, same as [singleton-classic-dynamic-example](#3️⃣-singleton-classic-dynamic-example)
* ⚠️ **Manual lifetime management is error-prone** → Same as [singleton-classic-dynamic-example](#3️⃣-singleton-classic-dynamic-example)

---

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

---

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

* CMake (v3.20 or newer required for Presets)
* C++ compiler supporting C++20 (required for `syncstream`)

#### 🖥️ Windows - Visual Studio MSVC (Preset: `windows-msvc`)

* Visual Studio 2022
* Workload Required: Desktop development with C++
* Note: The preset uses the Visual Studio 17 2022 generator.

#### 🖥️ Windows - MinGW (Preset: `windows-ninja-debug`)

* MinGW-w64 Toolchain
* Generator: Ninja

#### 🐧 Linux (Preset: `linux-ninja-debug`)

* C++ Compiler (GCC/Clang)
* Generator: Ninja

---

## 🏗️ Build Instructions
The commands below are executed from the **root of the repository**.
#### 1. Configure Workspace (run once)
* 🖥️ Windows (MSVC) → `cmake --preset windows-msvc`
* 🖥️ Windows (GCC, Ninja) → `cmake --preset windows-gcc-debug`
* 🖥️ Windows (Clang, Ninja) → `cmake --preset windows-clang-debug`
* 🐧 Linux (GCC) → `cmake --preset linux-gcc-debug`
* 🐧 Linux (Clang) → `cmake --preset linux-clang-debug`
#### Build All (debug)
* 🖥️ Windows (MSVC) → `cmake --build --preset windows-msvc-debug`
* 🖥️ Windows (GCC, Ninja) → `cmake --build --preset windows-gcc-debug`
* 🖥️ Windows (Clang, Ninja) → `cmake --build --preset windows-clang-debug`
* 🐧 Linux (GCC) → `cmake --build --preset linux-gcc-debug`
* 🐧 Linux (Clang) → `cmake --build --preset linux-clang-debug`
#### Build Specific Project
```bash
cmake --build --preset <preset> --target <target_name>
```
Example:
```bash
cmake --build --preset linux-gcc-debug --target 02-singleton-meyers-example
```
---
## 🏃 Running Examples
#### 🖥️ Windows (MSVC)
```bash
build/windows-msvc/02-singleton-meyers-example/Debug/02-singleton-meyers-example.exe
```
#### 🖥️ Windows (GCC, Ninja)
```bash
build/windows-gcc-debug/02-singleton-meyers-example/02-singleton-meyers-example.exe
```
#### 🖥️ Windows (Clang, Ninja)
```bash
build/windows-clang-debug/02-singleton-meyers-example/02-singleton-meyers-example.exe
```
#### 🐧 Linux (GCC)
```bash
./build/linux-gcc-debug/02-singleton-meyers-example/02-singleton-meyers-example
```
#### 🐧 Linux (Clang)
```bash
./build/linux-clang-debug/02-singleton-meyers-example/02-singleton-meyers-example
```