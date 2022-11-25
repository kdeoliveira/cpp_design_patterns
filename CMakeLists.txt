# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("DesignPatterns" VERSION 0.0.1)

include(CPack)

# Include sub-projects.
add_subdirectory ("DesignPatterns")


# For building:
# 1) Generate cmake config files for build and install: cmake [config dir]

# 2) Create build: cmake --build [dir of main CMakeLists.txt] --config [Release/Debug]

# 3) Install application: # cmake --install [dir of main CMakeLists.txt] --config [Release/Debug] --prefix [installation dir]



# Get specific cmake folder
# CMAKE_CURRENT_SOURCE_DIR: Current folder
# CMAKE_SOURCE_DIR: Get top level folder
# PROJECT_BINARY_DIRL Get folder where last project() has been defined