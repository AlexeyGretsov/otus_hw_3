cmake_minimum_required(VERSION 3.31)

project(otus_hw_3_research)

add_executable(operator_new_overload operator_new_overload.cpp)
set_target_properties(operator_new_overload PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

