cmake_minimum_required(VERSION 3.0)

project(PathfindingExe)

add_executable(
    PathfindingExe
    Main.cpp
    Simulation.hpp
    Algorithm.cpp
    AlgorithmRenderer.cpp
    Algorithm.hpp
    AlgorithmRenderer.hpp
    Utils.cpp
)

target_link_libraries(PathfindingExe sfml-graphics sfml-window sfml-system)