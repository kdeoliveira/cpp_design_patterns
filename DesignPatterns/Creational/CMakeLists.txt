# =========================================
# CMakeList.txt 
# CMake for static library: Creational Design Patterns
# =====================================================

project("DesignPatterns_Creational" VERSION 0.0.1)

add_library(${PROJECT_NAME} STATIC ./def/Creational.cpp)

include(GNUInstallDirs)

target_include_directories(${PROJECT_NAME} PRIVATE "./include")

target_include_directories(${PROJECT_NAME} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include/Debug/${PROJECT_NAME}>)

target_link_libraries(${PROJECT_NAME} compiler_flags)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "./include/Factory.hpp;./include/Common.hpp")

# Set to a predefined include location
set(CMAKE_INSTALL_INCLUDEDIR include/Debug/${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME} compiler_flags
		CONFIGURATIONS Debug
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
		)

configure_file(creational.pc.in creational.pc @ONLY)

install(FILES ${CMAKE_BINARY_DIR}/${MAIN_PROJECT_NAME}/Creational/creational.pc
		DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

