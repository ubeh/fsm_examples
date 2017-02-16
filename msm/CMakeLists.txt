cmake_minimum_required(VERSION 2.8.3)
project(msm)

# workaround for qt creator
FILE(GLOB_RECURSE header_files "include/*.h")
add_custom_target(msm_headers SOURCES ${header_files})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -Wconversion")

IF(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

find_package(Boost REQUIRED COMPONENTS system)

include_directories(
    include
    ${Boost_INCLUDE_DIRS}
)

# controller library
add_library(
    controller
    src/controller.cpp
)
target_link_libraries(
    controller
    ${Boost_LIBRARIES}
)

# fsm node
add_executable(
    msm
    src/main.cpp
)
target_link_libraries(
    msm
    controller
    ${Boost_LIBRARIES}
)
