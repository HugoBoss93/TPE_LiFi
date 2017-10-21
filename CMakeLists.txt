cmake_minimum_required(VERSION 3.8)
project(TPE_LiFi)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SRC_LiFi "src/*.h" "src/*.cpp")

find_package(spdlog CONFIG REQUIRED)
find_package(Threads)
add_executable(TPE_LiFi ${SRC_LiFi})
target_link_libraries(TPE_LiFi spdlog::spdlog ${CMAKE_THREAD_LIBS_INIT})
