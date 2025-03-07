cmake_minimum_required(VERSION 3.10) # Specify the minimum required CMake version

# Project Information
project(MyProject VERSION 1.0.0 LANGUAGES CXX) # Set project name, version, and language

# Compiler Flags (Optional, but recommended)
set(CMAKE_CXX_STANDARD 17) # Set C++ standard (e.g., 11, 14, 17, 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Require the specified C++ standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra") # Add compiler flags

# Build Type (Release or Debug)
#if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  #set(CMAKE_BUILD_TYPE "Release" CACHE STRING
      #"Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel."
      #FORCE)
#endif()

# Include Directories (where header files are located)
include_directories(include) # Add the 'include' directory
include_directories(${CMAKE_SOURCE_DIR}/lib)

# Source Files
#file(GLOB SOURCES "src/*.cpp") # Automatically find source files in 'src'

# Executable Target
#add_executable(MyExecutable ${SOURCES}) # Create an executable

# Library Target (Optional)
# add_library(MyLibrary STATIC ${SOURCES_LIBRARY}) # Create a static library
# target_include_directories(MyLibrary PUBLIC include) # Ensure the include directory is exposed to targets that link to the library.

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