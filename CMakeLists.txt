cmake_minimum_required(VERSION 3.17)
project(Programming_Problems)

set(CMAKE_CXX_STANDARD 20)
find_package(Threads)
enable_testing()
add_subdirectory(3rdPartyLibs/googletest)
add_subdirectory(Codewars)
