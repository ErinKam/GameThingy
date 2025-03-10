cmake_minimum_required(VERSION 3.10) # Specify the minimum required CMake version

# Project Information
project(MyGame VERSION 1.0.0 LANGUAGES CXX) # Set project name, version, and language

# Compiler Flags (Optional, but recommended)
set(CMAKE_CXX_STANDARD 17) # Set C++ standard (e.g., 11, 14, 17, 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra") # Add compiler flags

# Build Type (Release or Debug)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
      "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel."
      FORCE)
endif()

add_library(characters STATIC /lib/characters.cpp /lib/characters.h) # Create a static library
target_include_directories(characters PUBLIC ${CMAKE_SOURCE_DIR}/lib)
# Executable Target
add_executable(${PROJECT_NAME} "main.cpp") # Create an executable

target_link_directories(${PROJECT_NAME} PUBLIC characters)

# External Libraries (e.g., using find_package)
# find_package(Boost REQUIRED COMPONENTS filesystem system)
# if(Boost_FOUND)
#   target_link_libraries(MyExecutable PRIVATE Boost::filesystem Boost::system)
# endif()

# Install Rules (Optional, for packaging and deployment)
# install(TARGETS MyExecutable DESTINATION bin)
# install(DIRECTORY include/ DESTINATION include)

# Subdirectories (Optional, for larger projects with multiple components)
# add_subdirectory(lib)
# add_subdirectory(tests)

# Tests (Optional, using CTest)
# enable_testing()
# add_test(NAME MyTest COMMAND MyExecutableTest)