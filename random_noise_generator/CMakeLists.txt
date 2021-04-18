find_package (Eigen3 REQUIRED)

include_directories(
	${CMAKE_CURRENT_LIST_DIR}
	${Eigen3_INCLUDE_DIRS}
)

set(CPP_SOURCE random_noise_factory.cpp)
set(HEADERS_DIR noises)

add_library(${PROJECT_NAME}_rng ${CPP_SOURCE})
target_link_libraries(${PROJECT_NAME}_rng Eigen3::Eigen)
set_target_properties(${PROJECT_NAME}_rng
	PROPERTIES OUTPUT_NAME random_noise_generator)

install(TARGETS ${PROJECT_NAME}_rng DESTINATION lib)
install(DIRECTORY ${HEADERS_DIR} DESTINATION include/${PROJECT_NAME})
