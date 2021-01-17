cmake_minimum_required(VERSION 3.17)
project(CodeWars)

set(CMAKE_CXX_STANDARD 20)

add_library(Codewars)
target_sources(Codewars
        PUBLIC
        Functions.cpp
)

add_executable(Codewars_tests)
target_sources(
        Codewars_tests
        PUBLIC
        TestFile.cpp)
target_link_libraries(
        Codewars_tests
        PUBLIC
        Codewars
        googletest)
