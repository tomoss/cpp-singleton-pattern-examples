cmake_minimum_required(VERSION 3.21)

project(cpp-singleton-pattern-examples
    VERSION 0.1.0
    LANGUAGES CXX
)

add_subdirectory(01-singleton-classic-example)
add_subdirectory(02-singleton-meyers-example)
add_subdirectory(03-singleton-classic-dynamic-example)

add_subdirectory(singleton-cherno-example)

add_subdirectory(singleton-dclp-example)
add_subdirectory(singleton-smart-pointer-example)