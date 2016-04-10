cmake_minimum_required (VERSION 2.8)
project (FightSimulator6000)

# The version number.
set (VERSION_MAJOR 0)
set (VERSION_MINOR 4)
set (VERSION_PATCH 4)

set (CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

# TODO: PROJECT_SOURCE_DIR variable
file(GLOB SRC
    "src/*.h"
    "src/*.cpp"
)

configure_file (
  "src/version.h.in"
  "src/version.h"
  )

add_executable(FightSim ${SRC})

# enable_testing()

# add_test(DoesItRun test/DoesItRun.sh)
