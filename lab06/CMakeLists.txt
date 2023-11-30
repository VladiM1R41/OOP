cmake_minimum_required(VERSION 3.10)
project(lab6)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest)

add_library(${CMAKE_PROJECT_NAME}_lib NPC.cpp Dragon.cpp WanderingKnight.cpp Toad.cpp)
target_link_directories(${CMAKE_PROJECT_NAME}_lib PUBLIC NPC.hpp Dragon.hpp WanderingKnight.hpp Toad.hpp)

add_executable(${CMAKE_PROJECT_NAME}_exe main.cpp)
add_executable(${CMAKE_PROJECT_NAME}_test test.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}_exe ${CMAKE_PROJECT_NAME}_lib)
target_include_directories(${CMAKE_PROJECT_NAME}_test PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(${CMAKE_PROJECT_NAME}_test ${CMAKE_PROJECT_NAME}_lib gtest gtest_main)
add_test(basic test_lab2)