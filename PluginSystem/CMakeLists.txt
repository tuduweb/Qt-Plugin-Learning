cmake_minimum_required(VERSION 3.8)
project(PluginSystem VERSION 2)

file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

message("hello world ${HEADERS}")
message("hello world ${SOURCES}")