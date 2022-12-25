# =====================================================
# CMakeList.txt 
# CMake for general projects
# =====================================================

cmake_minimum_required (VERSION 3.15)

project ("DesignPatterns" VERSION 0.0.1)

# Include user-defined functions/var
include(definition.cmake)


# == Compiler Definitions ==
# Define warning and complementary flags for x86 adn arms compilers
set(gcc_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

# This library is used to define Compiler flags to be used across all build
add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_17)
# Generator expression
# $<x:y> x==true, then y
# Note that cmake contains some specific behavior according ot the flag
target_compile_definitions(compiler_flags INTERFACE $<$<CONFIG:Debug>:ONDEBUG>)
# add compiler options according to the compiler used
# $<BUILD_INTERFACE>: If project is being built
# $<INSTALL_INTERFACE>: If project is being installed
target_compile_options(compiler_flags INTERFACE "$<${gcc_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>" "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>")



# Include sub-projects.
add_subdirectory ("DesignPatterns")
add_subdirectory ("Libraries")

# === Testing ===
# Inside build dir: ctest -C Debug -VV
include(CTest)

# Check if application runs
add_test(NAME ShouldRun COMMAND ${PROJECT_NAME})

# Checks if Debug is outputted
do_test(${PROJECT_NAME} DebugMode "In debug*" )
do_test(${PROJECT_NAME} OsVersion "[*Windows | *Linux]")

# === Runtime Verification ===
include(CheckCXXSourceCompiles)
check_cxx_source_compiles("
  #include <windows.h>
  int main() {
    
    return 0;
  }
" IS_WINDOWS)

if(DEFINED IS_WINDOWS)
	target_compile_definitions(${PROJECT_NAME} PRIVATE "CXX_WIN")
endif()
# === Packaging and Installers ===
# Package: cpack -G [TGZ | ZIP] -C Debug
include(InstallRequiredSystemLibraries) #Includes any required runtime libraries foor the current platform
#set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")
include(CPack)

# For building:
# 1) Generate cmake config files for build and install: cmake -B [build dir] -S [dir of main CMakeLists.txt] -G [Ninja|Visual Studio 16 2019]; Note the files will be generated where the cmake command is executed
# Note for windows-only: cmake [dir of main CMakeLists.txt]

# 2) Create build: cmake --build [build dir] --config [Release/Debug]

# 3) Install application: # cmake --install [dir containing binaries] --config [Release/Debug] --prefix [installation dir]



# Get specific cmake folder
# CMAKE_CURRENT_SOURCE_DIR: Current folder
# CMAKE_SOURCE_DIR: Get top level folder
# PROJECT_BINARY_DIRL Get folder where last project() has been defined




