cmake_minimum_required(VERSION 3.30)

project(aoc-day-3 LANGUAGES CXX)

add_library(scanner scanner.cpp scanner.h)

add_executable(day-3 day-3.cpp)

target_link_libraries(day-3 PRIVATE scanner)
