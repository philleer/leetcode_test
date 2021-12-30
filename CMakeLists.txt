cmake_minimum_required(VERSION 3.0)

project(LeetCode)

set(CMAKE_BUILD_TYPE RELEASE)
if((${CMAKE_BUILD_TYPE}) STREQUAL "RELEASE")
	set(CMAKE_BUILD_TYPE RELEASE)
elseif((${CMAKE_BUILD_TYPE}) STREQUAL "DEBUG")
	set(CMAKE_BUILD_TYPE DEBUG)
else()
	set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -O2 -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")

set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(INCLUDES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/includes)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SRC_UTILS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/utils)
set(INCLUDES_UTILS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/includes/utils)
set(3RDPARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty)

enable_testing()

set(GFLAGS_IS_SUBPROJECT TRUE)
set(GFLAGS_BUILD_SHARED_LIBS ON)
set(GFLAGS_BUILD_STATIC_LIBS OFF)
set(GFLAGS_BUILD_gflags_LIB ON)
add_subdirectory(3rdparty/gflags)
#add_subdirectory(3rdparty/glog)
#find_package(GTest  REQUIRED)

set(GFLAGS_HEADER_OUTPUT_DIR ${3RDPARTY_DIR}/gflags/include)
if (NOT EXISTS ${GFLAGS_HEADER_OUTPUT_DIR})
	file(MAKE_DIRECTORY ${GFLAGS_HEADER_OUTPUT_DIR})
endif()
file(GLOB_RECURSE GFLAGS_HEADER_LIST "${3RDPARTY_DIR}/gflags/src/*.h.in")
foreach (gflags_header ${GFLAGS_HEADER_LIST})
	string(REGEX REPLACE ".+/(.+)\\..*" "\\1" GFLAGS_HEADER_FILE_NAME ${gflags_header})
	#message(STATUS ${GFLAGS_HEADER_FILE_NAME})
	configure_file(${gflags_header} ${GFLAGS_HEADER_OUTPUT_DIR}/${GFLAGS_HEADER_FILE_NAME} @ONLY)
endforeach()
include_directories(${GFLAGS_HEADER_OUTPUT_DIR})

#if (GTEST_FOUND)
#	#message(STATUS "GTEST:${GTEST_INCLUDE_DIRS}")
#	#message(STATUS "GTEST:${GTEST_LIBRARIES}")
#	include_directories(${GTEST_INCLUDE_DIRS})
#endif()

file(GLOB_RECURSE SRC_LIST "${SRC_DIR}/*.c*")
file(GLOB_RECURSE SRC_UTILS_LIST "${SRC_UTILS_DIR}/*.c*")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
foreach(src ${SRC_LIST})
	string(FIND ${src} ${SRC_UTILS_DIR} EXCLUDE_DIR_FOUND)
	if (NOT ${EXCLUDE_DIR_FOUND} EQUAL -1)
		continue()
	endif()
	string(REGEX REPLACE ".+/(.+)\\..*" "\\1" SRC_FILE_NAME ${src})
	add_executable(${SRC_FILE_NAME} ${src} ${SRC_UTILS_LIB})
	set_target_properties(${SRC_FILE_NAME} PROPERTIES LINKER_LANGUAGE CXX)
	target_link_libraries(${SRC_FILE_NAME}
				${SRC_UTILS_LIB}
				#glog::glog
				gflags::gflags
				#${GTEST_LIBRARIES}
				pthread
			)
endforeach(src ${SRC_LIST})

