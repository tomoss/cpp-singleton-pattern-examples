cmake_minimum_required(VERSION 3.21)
project(singleton-classic-dynamic-example VERSION 0.1.0 LANGUAGES CXX)

# Export compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(singleton-classic-dynamic-example
    src/main.cpp
    src/singleton.cpp
)

target_include_directories(singleton-classic-dynamic-example PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)