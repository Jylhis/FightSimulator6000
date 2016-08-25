cmake_minimum_required (VERSION 2.8)
project (FightSimulator6000 CXX)

# The version number.
set (VERSION_MAJOR 0)
set (VERSION_MINOR 4)
set (VERSION_PATCH 4)

set (CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

include_directories(${CMAKE_CURRENT_BINARY_DIR})
configure_file (
  "src/version.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/version.h"
  @ONLY
)

set(SRC
    "src/battlefield.h"
    "src/battlefield.cpp"
    "src/main.cpp"
)
add_executable(FightSim ${SRC})
