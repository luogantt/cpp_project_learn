cmake_minimum_required(VERSION 3.21)
project(untitled1 CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(untitled1 main.cu)

set_target_properties(untitled1 PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
