cmake_minimum_required(VERSION 3.20)
project(my_cpp_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

# Standard CMake find_package, using Conan-generated config
find_package(fmt REQUIRED CONFIG)

add_executable(myapp src/main.cpp)
target_link_libraries(myapp PRIVATE fmt::fmt)

#enable_testing()
#add_executable(tests test/test.cpp)
#target_link_libraries(tests ${CONAN_LIBS})
#add_test(NAME example_test COMMAND tests)