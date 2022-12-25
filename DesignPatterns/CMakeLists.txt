# =====================================================
# CMakeList.txt 
# CMake project for main executable: DesignPatterns
# =====================================================

cmake_minimum_required (VERSION 3.15)

# Add source to this project's executable.
add_executable (${PROJECT_NAME} "${PROJECT_NAME}.cpp" "${PROJECT_NAME}.hpp" "Idiom/def/Idiom.cpp")


set(MAIN_PROJECT_NAME ${PROJECT_NAME})

# Create list variable and appends library project names
list(APPEND LIBS compiler_flags ${PROJECT_NAME}_Basic Idiom)

add_subdirectory("Basic")
add_subdirectory("Idiom")


foreach(LIB IN LISTS LIBS)
	target_link_libraries(${PROJECT_NAME} PUBLIC ${LIB})
endforeach()


# === INSTALLATION OF EXECUTABLE ===
# Generates install and build folder and sets the runtime variable to the respective paths
set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/install")
install(DIRECTORY DESTINATION ${CMAKE_SOURCE_DIR}/install)
#add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_SOURCE_DIR}/build")

# Intalls the main executable inside bin
# EXPORT ${PROJECT_NAME}_Target: Generates cmake file that allows this library to be imported by another cmake via find_package()
install(TARGETS ${PROJECT_NAME} compiler_flags CONFIGURATIONS Debug DESTINATION bin/Debug)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.hpp CONFIGURATIONS Debug DESTINATION include/Debug)


# Set the output directory for builds
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

