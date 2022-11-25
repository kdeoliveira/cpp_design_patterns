# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("DesignPatterns" VERSION 0.0.1)

include(CPack)
include(CTest)
# Include user-defined functions/var
include(definition.cmake)


# Include sub-projects.
add_subdirectory ("DesignPatterns")



# === Testing ===
# Inside build dir: ctest -C Debug -VV

# Check if application runs
add_test(NAME ShouldRun COMMAND ${PROJECT_NAME})

# Checks if Debug is outputted
do_test(${PROJECT_NAME} DebugMode "In debug*" )
do_test(${PROJECT_NAME} OsVersion "[*Windows|*Linux]"> )

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

# For building:
# 1) Generate cmake config files for build and install: cmake [dir of main CMakeLists.txt]; Note the files will be generated where the cmake command is executed

# 2) Create build: cmake --build [build dir] --config [Release/Debug]

# 3) Install application: # cmake --install [dir containing binaries] --config [Release/Debug] --prefix [installation dir]



# Get specific cmake folder
# CMAKE_CURRENT_SOURCE_DIR: Current folder
# CMAKE_SOURCE_DIR: Get top level folder
# PROJECT_BINARY_DIRL Get folder where last project() has been defined




