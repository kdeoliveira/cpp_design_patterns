
project(DesignPatterns_Basic)


add_library(${PROJECT_NAME} STATIC "./def/Basic.cpp")



# Add include folder as available directory to this project only
target_include_directories(${PROJECT_NAME} PRIVATE "./include")

# Add include folder as available directory to main project
# INTERFACE: Make available to any project linked to this Project but not to this project itself
target_include_directories(${PROJECT_NAME} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Link the compiler flags to this library
target_link_libraries(${PROJECT_NAME} compiler_flags)



# === INSTALLATION ===
# Installs library into lib folder
install(TARGETS ${PROJECT_NAME} compiler_flags CONFIGURATIONS Debug DESTINATION "lib/Debug")
install(FILES "./include/Command.hpp" CONFIGURATIONS Debug DESTINATION "include/Debug")