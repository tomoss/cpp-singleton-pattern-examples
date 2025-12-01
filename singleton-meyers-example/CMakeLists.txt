cmake_minimum_required(VERSION 3.21) 
project(singleton-meyers-example VERSION 0.1.0 LANGUAGES CXX)

# -------------------------------------------------------------
# Executable
# -------------------------------------------------------------
add_executable(singleton-meyers-example
    main.cpp
    src/singleton.cpp
)

# -------------------------------------------------------------
# Compiler Features
# -------------------------------------------------------------
target_compile_features(singleton-meyers-example PRIVATE cxx_std_17)

set_target_properties(singleton-meyers-example PROPERTIES
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# -------------------------------------------------------------
# Include directories
# -------------------------------------------------------------
# PRIVATE means: Only this target needs 'inc' to build.
target_include_directories(singleton-meyers-example PRIVATE
    inc
)