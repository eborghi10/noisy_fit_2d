cmake_minimum_required (VERSION 3.8)
project (fit_noisy_data_2d)

set (CMAKE_CXX_STANDARD 17)

# Libraries
add_subdirectory(random_noise_generator)
add_subdirectory(linear_fitting)
add_subdirectory(third_party)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME}
	matplotlib_cpp
	${PROJECT_NAME}_arg_parser
	${PROJECT_NAME}_lf
	${PROJECT_NAME}_rng
)
