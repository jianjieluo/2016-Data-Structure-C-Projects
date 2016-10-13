cmake_minimum_required(VERSION 3.5)

project(airport)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -g")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SOURCE)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(airport ${SOURCE})
