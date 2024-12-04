cmake_minimum_required(VERSION 3.30)

project(aoc-day-1 LANGUAGES CXX)

add_library(sort sort.cpp sort.h)

add_executable(day-1 day-1.cpp)

target_link_libraries(day-1 PRIVATE sort)
