cmake_minimum_required(VERSION 3.21) 
project(singleton-classic-static-example VERSION 0.1.0 LANGUAGES CXX)

# -------------------------------------------------------------
# Executable
# -------------------------------------------------------------
add_executable(singleton-classic-static-example
    main.cpp
    src/singleton.cpp
)

# -------------------------------------------------------------
# Compiler Features
# -------------------------------------------------------------
target_compile_features(singleton-classic-static-example PRIVATE cxx_std_17)

set_target_properties(singleton-classic-static-example PROPERTIES
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# -------------------------------------------------------------
# Include directories
# -------------------------------------------------------------
# PRIVATE means: Only this target needs 'inc' to build.
target_include_directories(singleton-classic-static-example PRIVATE
    inc
)