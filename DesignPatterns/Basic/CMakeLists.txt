
project(DesignPatterns_Basic)


add_library(${PROJECT_NAME} STATIC "./def/Basic.cpp")



# Add include folder as available directory to this project only
target_include_directories(${PROJECT_NAME} PRIVATE "./include")

# Add include folder as available directory to main project
# INTERFACE: Make available to any project linked to this Project but not to this project itself
target_include_directories(${PROJECT_NAME} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:$include/Debug>)

# Link the compiler flags to this library
target_link_libraries(${PROJECT_NAME} compiler_flags)



# === INSTALLATION ===
# Installs library into lib folder
# EXPORT: Generates cmake file with all target projects defined in install
install(TARGETS ${PROJECT_NAME} compiler_flags EXPORT ${PROJECT_NAME}_Target CONFIGURATIONS Debug DESTINATION "lib/Debug")
install(FILES "./include/Command.hpp" CONFIGURATIONS Debug DESTINATION "include/Debug")



# Install EXPORTED library cmake file
install(EXPORT ${PROJECT_NAME}_Target FILE ${PROJECT_NAME}_Target.cmake DESTINATION "lib/cmake/${PROJECT_NAME}_Target")
include(CMakePackageConfigHelpers)
#Generate the config file for cmake exports
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake" INSTALL_DESTINATION "lib/cmake" NO_SET_AND_CHECK_MACRO NO_CHECK_REQUIRED_COMPONENTS_MACRO)
#Write file used by find_package during INSTALL
write_basic_package_version_file(
	"${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake" VERSION "1.0" COMPATIBILITY AnyNewerVersion
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake DESTINATION lib/cmake/${PROJECT_NAME}_Target)

# Below can be used to generate in the build
export(EXPORT ${PROJECT_NAME}_Target FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_Target.cmake")