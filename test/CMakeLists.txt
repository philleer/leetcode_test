
include_directories(${SRC_DIR})
include_directories(${SRC_UTILS_DIR})
file(GLOB_RECURSE TEST_LIST "${PROJECT_SOURCE_DIR}/test/*_test.c*")

foreach(test_file ${TEST_LIST})
	string(REGEX REPLACE ".+/(.+)\\..*" "\\1" TEST_FILE_NAME ${test_file})
	string(REGEX REPLACE ".+/(.+)_test\\..*" "\\1" TEST_SRC_FILE_NAME ${test_file})

	set(DEPENDENT_SRC "${test_file}")
	if ("${TEST_FILE_NAME}" STREQUAL "simple_test")
		set(DEPENDENT_SRC "${DEPENDENT_SRC};${SRC_DIR}/myclass.cc")
	else()
		set(DEPENDENT_SRC "${DEPENDENT_SRC};${SRC_DIR}/${TEST_SRC_FILE_NAME}.cc")
	endif()
	add_executable(${TEST_FILE_NAME} ${DEPENDENT_SRC})
	set_target_properties(${TEST_FILE_NAME} PROPERTIES LINKER_LANGUAGE CXX)
	target_link_libraries(${TEST_FILE_NAME} GTest::gtest GTest::gtest_main pthread)
	#gtest_discover_tests(myclass_test)
endforeach()

add_test(
		NAME simple_test
		COMMAND $<TARGET_FILE:simple_test>
	)
add_test(
		NAME myclass_test
		COMMAND $<TARGET_FILE:myclass_test>
	)
