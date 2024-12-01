cmake_minimum_required(VERSION 3.30)

project(aoc-day-2 LANGUAGES CXX)

add_library(sort sort.cpp sort.h)

add_executable(day-2 day-2.cpp)

target_link_libraries(day-2 PRIVATE sort)
