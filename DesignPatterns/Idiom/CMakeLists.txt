# =========================================
# CMakeList.txt 
# CMake for static library: Idioms
# Note that for GNUINstallDirst, configuration must be set inside *.pc.in file
# =====================================================

project("Idiom" VERSION 0.0.1)

add_library(${PROJECT_NAME} STATIC ./def/Idiom.cpp)

include(GNUInstallDirs)

target_include_directories(${PROJECT_NAME} PRIVATE "./include")

target_include_directories(${PROJECT_NAME} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
#Alternative for Release/Debug: $<$<CONFIG:Debug>:include/Debug>$<$<CONFIG:Release>:include/Release>

target_link_libraries(${PROJECT_NAME} compiler_flags)


set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "./include/Crtp.hpp;./include/Common.hpp")

# == INSTALLATION == 
install(TARGETS ${PROJECT_NAME} compiler_flags 
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
		)


configure_file(idioms.pc.in idioms.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/${MAIN_PROJECT_NAME}/${PROJECT_NAME}/idioms.pc
		DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)