cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(observers)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(CXX_SOURCE_FILES main.cpp observer.h observable.h)

add_executable(${CMAKE_PROJECT_NAME} ${CXX_SOURCE_FILES})