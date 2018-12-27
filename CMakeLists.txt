# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name
project(ProducerConsumer CXX)
find_package(Threads REQUIRED)

# Set the output folder where your program will be created
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++14")
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

if(THREADS_FOUND AND NOT TARGET Threads::Threads)
add_library(Threads::Threads INTERFACE IMPORTED)
endif()

add_executable(ProducerConsumer ${PROJECT_SOURCE_DIR}/ConsumerThread.cpp ${PROJECT_SOURCE_DIR}/Item.cpp ${PROJECT_SOURCE_DIR}/Sort.cpp ${PROJECT_SOURCE_DIR}/Thread.cpp ${PROJECT_SOURCE_DIR}/SynchronizedFile.cpp ${PROJECT_SOURCE_DIR}/Main.cpp)

