﻿# CMakeList.txt : CMake project for DesignPatterns, include source and define
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
# Intalls the main executable inside bin
install(TARGETS ${PROJECT_NAME} CONFIGURATIONS Debug DESTINATION "bin/Debug")
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.hpp" CONFIGURATIONS Debug DESTINATION "include/Debug")