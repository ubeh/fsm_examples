cmake_minimum_required(VERSION 2.8.3)
project(sml_refactored)

# workaround for qt creator
FILE(GLOB_RECURSE header_files "include/*.h")
add_custom_target(sml_headers SOURCES ${header_files})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -Wconversion")

IF(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()



include_directories(
    include
    lib/sml/include
)

# controller library
add_library(
    controller
    src/controller.cpp
)





# fsm node
add_executable(
    sml
    src/main.cpp
)
target_link_libraries(
    sml
    controller
)
