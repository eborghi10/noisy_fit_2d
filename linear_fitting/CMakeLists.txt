find_package (Eigen3 REQUIRED)

include_directories(
	${CMAKE_CURRENT_LIST_DIR}
	${Eigen3_INCLUDE_DIRS}
)

set(CPP_SOURCE linear_fitting_factory.cpp)
set(HEADERS_DIR solvers)

add_library(${PROJECT_NAME}_lf ${CPP_SOURCE})
target_link_libraries(${PROJECT_NAME}_lf Eigen3::Eigen)
set_target_properties(${PROJECT_NAME}_lf
	PROPERTIES OUTPUT_NAME linear_fitting)

install(TARGETS ${PROJECT_NAME}_lf DESTINATION lib)
install(DIRECTORY ${HEADERS_DIR} DESTINATION include/${PROJECT_NAME})

# Testing

include(GoogleTest)
add_executable(${PROJECT_NAME}_lf_test test.cpp)
target_link_libraries(${PROJECT_NAME}_lf_test Eigen3::Eigen gtest gtest_main pthread)
gtest_add_tests(TARGET ${PROJECT_NAME}_lf_test TEST_LIST test)
set_target_properties(${PROJECT_NAME}_lf_test
	PROPERTIES OUTPUT_NAME linear_fitting_test)
set_tests_properties(${test} PROPERTIES TIMEOUT 10)
