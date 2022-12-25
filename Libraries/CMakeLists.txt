# =========================================
# CMakeList.txt 
# CMake for static library: Shared Libraries
# Note that for GNUINstallDirst, configuration must be set inside *.pc.in file
# =====================================================

cmake_minimum_required (VERSION 3.8)

project("Libraries" VERSION 0.0.1)

add_library(${PROJECT_NAME} SHARED ./src/lib.cxx ./src/utils.cxx )

include(GNUInstallDirs) #Contain deifnitions for installing libraries in os
include(GenerateExportHeader) #Generates the dllexports/dllimports declarations



target_include_directories(${PROJECT_NAME} PRIVATE "./src")
target_include_directories(${PROJECT_NAME} PRIVATE "./include")

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_BINARY_DIR}/${PROJECT_NAME}) #Contains the exported macro header file generated


set_target_properties(
	${PROJECT_NAME} PROPERTIES	VERSION ${PROJECT_VERSION}			#define version of this library
								SOVERSION 1							#define major version for generated shared object files
								PUBLIC_HEADER ./include/lib.hpp		#header file for entry point containing main definitions (used for shared libraries)
)

# Prevents compilers from automatically exporting functions defined in this library
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

# Provides definitions for dllexports when generating shared libraries
generate_export_header(
	${PROJECT_NAME} BASE_NAME ${PROJECT_NAME}
	EXPORT_MACRO_NAME SHARED_EXPORT
	EXPORT_FILE_NAME lib_exports.hpp
	STATIC_DEFINE SHARED_EXPORTS_BUILT_AS_STATIC
)

set(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS -DLIBSHARED_AND_STATIC_STATIC_DEFINE)

install(
	TARGETS ${PROJECT_NAME}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/lib_exports.hpp DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}) #Copies generated file to install prefix dir

# Exports project with pkg-config defintions (Makefiles, Autotools and Cmake)
# CMAKE_INSTALL_DATAROOTDIR = ./share folder
configure_file(lib.pc.in lib.pc @ONLY)	#only expands cmake variables in pc.in file
										#generates configuration file (in build dir)

install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/lib.pc
		DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)