cmake_minimum_required(VERSION 3.21) 
project(singleton-cherno-example VERSION 0.1.0 LANGUAGES CXX)

add_executable(singleton-cherno-example
    src/main.cpp
    src/singleton.cpp
)

target_include_directories(singleton-cherno-example PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)