# CMakeList.txt : CMake project for DesignPatterns, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (${PROJECT_NAME} "${PROJECT_NAME}.cpp" "${PROJECT_NAME}.hpp")

# Define warning flags according to the compile used
set(gcc_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

# This library is used to define Compiler flags to be used across all build
add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_17)
# Generator expression
# $<x:y> x==true, then y
# Note that cmake contains some specific behavior according ot the flag
target_compile_definitions(compiler_flags INTERFACE $<$<CONFIG:Debug>:ONDEBUG=1>)
# add compiler options according to the compiler used
# $<BUILD_INTERFACE>: If project is being built
# $<INSTALL_INTERFACE>: If project is being installed
target_compile_options(compiler_flags INTERFACE "$<${gcc_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>" "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>")


set(MAIN_PROJECT_NAME ${PROJECT_NAME})

# Create list variable and appends library project names
list(APPEND LIBS ${PROJECT_NAME}_Basic)

add_subdirectory("Basic")


foreach(LIB IN LISTS LIBS)
	target_link_libraries(${PROJECT_NAME} PUBLIC ${LIB} compiler_flags)
endforeach()



# === INSTALLATION ===
# Generates install and build folder and sets the runtime variable to the respective paths
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build")
set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/install")
install(DIRECTORY DESTINATION "${CMAKE_SOURCE_DIR}/install")
#add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_SOURCE_DIR}/build")

# Intalls the main executable inside bin
# EXPORT ${PROJECT_NAME}_Target: Generates cmake file that allows this library to be imported by another cmake via find_package()
install(TARGETS ${PROJECT_NAME} CONFIGURATIONS Debug DESTINATION "bin/Debug")
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.hpp" CONFIGURATIONS Debug DESTINATION "include/Debug")

# Set the output directory for builds
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

