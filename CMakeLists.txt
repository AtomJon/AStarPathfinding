enable_testing()

set(CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_STANDARD 17)

if(USE_TOOLCHAIN)
    if ( CMAKE_HOST_SYSTEM_NAME MATCHES "Linux" )
        set(CMAKE_TOOLCHAIN_FILE  "${CMAKE_SOURCE_DIR}/cmake/Toolchain-windows.cmake")
    elseif( CMAKE_HOST_SYSTEM_NAME MATCHES "Windows" )
        set(CMAKE_TOOLCHAIN_FILE  "${CMAKE_SOURCE_DIR}/cmake/Toolchain-linux.cmake")
    endif()
endif()

cmake_minimum_required(VERSION 3.5)

project(PathfindingExe)

set(PROJECT_BINARY_DIR "${CMAKE_SOURCE_DIR}/build")

add_executable(
    PathfindingExe
    src/Main.cpp
    src/Utils.cpp
    src/BaseAlgorithm.hpp
    src/PheromoneAlgorithm.hpp
    src/PheromoneAlgorithm.cpp
    src/AlgorithmRenderer.cpp
    src/AlgorithmRenderer.hpp
    src/BaseGridLoader.hpp
    src/RandomGridLoader.hpp
    src/RandomGridLoader.cpp
    src/FileGridLoader.hpp
    src/FileGridLoader.cpp
    src/GridRenderer.cpp
    src/GridRenderer.hpp
    src/SimulationRenderer.cpp
    src/SimulationRenderer.hpp
    src/Simulation.hpp
    src/Simulation.cpp
)


find_package(SFML COMPONENTS graphics window system REQUIRED)

include_directories(${SFML_INCLUDE_DIRS})

target_link_libraries(PathfindingExe sfml::sfml)

# include(${CMAKE_SOURCE_DIR}/test/CMakeLists.txt)

# "C:\Program Files\CMake\bin\cmake.EXE" -DCMAKE_POLICY_DEFAULT_CMP0091=NEW -DCMAKE_TOOLCHAIN_FILE=F:/MyPrograms/C++/test_crosscompile/AStarPathfinding/build/conan_toolchain.cmake -SF:/MyPrograms/C++/test_crosscompile/AStarPathfinding -BF:/MyPrograms/C++/test_crosscompile/AStarPathfinding/build -G "Visual Studio 17 2022" -T v143 -A x64