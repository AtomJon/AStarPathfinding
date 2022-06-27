message("Scanning for tests")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(CTEST_BINARY_DIRECTORY ${PROJECT_BINARY_DIR})

file(GLOB files "${CMAKE_SOURCE_DIR}/**/test_*.cpp")

foreach(file ${files})
	string(REGEX REPLACE "(^.*/|\\.[^.]*$)" "" file_without_ext ${file})
	message("Found test '${file_without_ext}'.")
	
	add_executable(${file_without_ext} ${file})
	target_link_libraries(${file_without_ext} ${PROJECT_LIBS})
	add_test(${file_without_ext} ${file_without_ext})
	set_tests_properties(${file_without_ext}
		PROPERTIES
		PASS_REGULAR_EXPRESSION "Test passed")
	set_tests_properties(${file_without_ext}
		PROPERTIES
		FAIL_REGULAR_EXPRESSION "(Exception|Test failed)")
	set_tests_properties(${file_without_ext}
		PROPERTIES
		TIMEOUT 120)
endforeach()