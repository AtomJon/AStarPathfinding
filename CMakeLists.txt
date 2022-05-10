cmake_minimum_required(VERSION 3.0)

project(Main)

add_executable(
    Main
    Main.cpp
    Simulation.hpp
    Algorithm.cpp
    AlgorithmRenderer.cpp
    Algorithm.hpp
    AlgorithmRenderer.hpp
    Utils.cpp
)

target_link_libraries(Main sfml-graphics sfml-window sfml-system)