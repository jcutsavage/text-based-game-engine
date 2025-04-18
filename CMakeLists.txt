cmake_minimum_required(VERSION 3.20)
project(text-based-game-engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Standard CMake find_package, using Conan-generated config
find_package(fmt REQUIRED CONFIG)

file(GLOB_RECURSE SOURCES "src/**/*.cpp")

add_executable(text_game ${SOURCES})

include_directories(
    ${CMAKE_SOURCE_DIR}/src/main/cpp/TextGame
    ${CMAKE_SOURCE_DIR}/src/main/cpp/Utilities
)

target_link_libraries(text_game PRIVATE fmt::fmt)
