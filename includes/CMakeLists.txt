find_package (Eigen3 REQUIRED)
find_package(PythonLibs REQUIRED)

include_directories(
	${CMAKE_CURRENT_LIST_DIR}
	${Eigen3_INCLUDE_DIRS}
	${PYTHON_INCLUDE_DIRS}
)

### Matplotlib

include(GNUInstallDirs)

add_library(matplotlib_cpp INTERFACE)
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
target_link_libraries(matplotlib_cpp INTERFACE
  Python3::Python
  Python3::Module
	${PYTHON_LIBRARY}
)
find_package(Python3 COMPONENTS NumPy)
if(Python3_NumPy_FOUND)
  target_link_libraries(matplotlib_cpp INTERFACE
    Python3::NumPy
  )
else()
  target_compile_definitions(matplotlib_cpp INTERFACE WITHOUT_NUMPY)
endif()
install(
  TARGETS matplotlib_cpp
  EXPORT install_targets
)

#####################

add_library(${PROJECT_NAME}_arg_parser INTERFACE)
