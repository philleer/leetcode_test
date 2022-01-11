cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(LeetCode)

#====================================================
## C++ compiler options
#====================================================
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

set(CMAKE_BUILD_TYPE RELEASE)
if("${CMAKE_BUILD_TYPE}" STREQUAL "RELEASE")
	set(CMAKE_BUILD_TYPE RELEASE)
elseif("${CMAKE_BUILD_TYPE}" STREQUAL "DEBUG")
	set(CMAKE_BUILD_TYPE DEBUG)
else()
	set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()
message(STATUS "BUILD_TYPE: ${CMAKE_BUILD_TYPE}")


#====================================================
## Workspace variable settings
#====================================================
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SRC_UTILS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/utils)
set(3RDPARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty)

# Set output directory to store executables
# create if not exist
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Set basic include directories
include_directories(${SRC_UTILS_DIR})

## Search for source files
file(GLOB_RECURSE SRC_LIST "${SRC_DIR}/[^.]*.c*")
file(GLOB_RECURSE SRC_UTILS_LIST "${SRC_UTILS_DIR}/[^.]*.c*")


#====================================================
## GFLAGS configuration
#====================================================
set(GFLAGS_IS_SUBPROJECT TRUE)
set(GFLAGS_BUILD_SHARED_LIBS ON)
set(GFLAGS_BUILD_STATIC_LIBS OFF)
set(GFLAGS_BUILD_gflags_LIB ON)
add_subdirectory(3rdparty/gflags)

set(GFLAGS_HEADER_OUTPUT_DIR ${3RDPARTY_DIR}/gflags/include)
if (NOT EXISTS ${GFLAGS_HEADER_OUTPUT_DIR})
	file(MAKE_DIRECTORY ${GFLAGS_HEADER_OUTPUT_DIR})
endif()

file(GLOB_RECURSE GFLAGS_HEADER_LIST "${3RDPARTY_DIR}/gflags/src/*.h.in")
foreach (gflags_header ${GFLAGS_HEADER_LIST})
	string(REGEX REPLACE ".+/(.+)\\..*" "\\1" GFLAGS_HEADER_FILE_NAME ${gflags_header})
	configure_file(${gflags_header} ${GFLAGS_HEADER_OUTPUT_DIR}/${GFLAGS_HEADER_FILE_NAME} @ONLY)
endforeach()
include_directories(${GFLAGS_HEADER_OUTPUT_DIR})


#====================================================
## GoogleTest configuration
#====================================================
enable_testing()	# 测试当前目录和所有子文件夹
include(GoogleTest)
option(BUILD_GMOCK "Builds the googlemock subproject" ON)
option(INSTALL_GTEST "Enable installation of googletest. (Projects embedding googletest may want to turn this OFF.)" ON)
set(GTEST_BUILD_SHARED_LIBS ON)
set(BUILD_GMOCK OFF)
set(INSTALL_GTEST OFF)
add_subdirectory(3rdparty/googletest)
add_subdirectory(test)


#====================================================
## Compile target executables
#====================================================
add_subdirectory(3rdparty/spdlog)


#====================================================
## Compile target executables
#====================================================
foreach(src ${SRC_LIST})
	string(FIND ${src} ${SRC_UTILS_DIR} EXCLUDE_DIR_FOUND)
	if (NOT ${EXCLUDE_DIR_FOUND} EQUAL -1)
		continue()
	endif()
	string(REGEX REPLACE ".+/(.+)\\..*" "\\1" SRC_FILE_NAME ${src})
	add_executable(${SRC_FILE_NAME} ${src} ${SRC_UTILS_LIST})
	set_target_properties(${SRC_FILE_NAME} PROPERTIES LINKER_LANGUAGE CXX)
	target_link_libraries(${SRC_FILE_NAME} # ${SRC_UTILS_LIB}
				spdlog::spdlog
				gflags::gflags
				GTest::gtest
				GTest::gtest_main
				pthread
			)
endforeach(src ${SRC_LIST})

