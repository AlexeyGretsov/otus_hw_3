cmake_minimum_required(VERSION 3.31)

project(otus_hw_3_allocators_test)

add_executable(otus_hw_3_allocators_test allocator.cpp)
set_target_properties(otus_hw_3_allocators_test PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

