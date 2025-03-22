cmake_minimum_required(VERSION 3.31)

project(otus_hw_3)

add_subdirectory(research)

add_executable(${CMAKE_PROJECT_NAME} 
	main.cpp
)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
