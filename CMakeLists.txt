option(USE_TOOLCHAIN "Use the toolchain file provided for making a crossplatform build. If you are on linux, this will create a windows executable and vise-versa for windows." OFF)

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

cmake_minimum_required(VERSION 3.0)

project(PathfindingExe)

set(PROJECT_BINARY_DIR "${CMAKE_SOURCE_DIR}/build")

add_library(
    NeutronicPathfinding
    Utils.cpp
    BaseAlgorithm.hpp
    PheromoneAlgorithm.hpp
    PheromoneAlgorithm.cpp
    AlgorithmRenderer.cpp
    AlgorithmRenderer.hpp
    BaseGridLoader.hpp
    RandomGridLoader.hpp
    RandomGridLoader.cpp
    FileGridLoader.hpp
    FileGridLoader.cpp
    GridRenderer.cpp
    GridRenderer.hpp
    Simulation.hpp
    Simulation.cpp
    
)

add_executable(
    PathfindingExe
    Main.cpp
)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/lib/${CMAKE_SYSTEM_NAME}/SFML-2.5.1")
# set(SFML_STATIC_LIBRARIES TRUE)

include_directories("${SFML_DIR}/include")
find_package(SFML PATHS "${SFML_DIR}/lib/cmake/SFML" COMPONENTS graphics window system REQUIRED)

# if(NOT SFML_STATIC_LIBRARIES)
    # add_custom_target(copy)
    # add_custom_command(
    #     TARGET PathfindingExe POST_BUILD
    #     COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/SFML/bin $<TARGET_FILE_DIR:PathfindingExe>
    # )
# endif()

# file(COPY ${CMAKE_SOURCE_DIR}/SFML/bin DESTINATION bin)

set(PROJECT_LIBS NeutronicPathfinding sfml-graphics sfml-window sfml-system)

target_link_libraries(PathfindingExe ${PROJECT_LIBS})

include(${CMAKE_SOURCE_DIR}/test/CMakeLists.txt)