cmake_minimum_required(VERSION 3.28)

project(otus_hw_3)

enable_testing()
find_package(GTest REQUIRED)

add_executable(${CMAKE_PROJECT_NAME} 
	allocator.h
	main.cpp
)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

# if (ENABLE_GTEST)
# 	add_executable(${project_tests_name}
# 		test_version.cc
# 	)
# 	set_target_properties(${project_tests_name} PROPERTIES
# 		CXX_STANDARD 14
# 		CXX_STANDARD_REQUIRED ON
# 	)
# 	include_directories(${GTEST_INCLUDE_DIR})

# 	target_link_libraries(${project_tests_name} 
# 		GTest::GTest 
# 		GTest::Main
# 		${project_lib_name}
# 	)

# 	message(STATUS "Adds test ${project_tests_name}")

# 	add_test(NAME ${project_tests_name} COMMAND ${project_tests_name}
# )
# endif()

install(TARGETS ${CMAKE_PROJECT_NAME} RUNTIME DESTINATION bin)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	set(CPACK_GENERATOR TGZ)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set(CPACK_GENERATOR DEB)
endif()

set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PATCH_VERSION})

set(CPACK_PACKAGE_CONTACT alexey.gretsov@gmail.com)

include(CPack)

