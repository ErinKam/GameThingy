cmake_minimum_required(VERSION 3.10) # Specify the minimum required CMake version
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(Game VERSION 1.0.0) # Set project name, version, and language

add_executable(${PROJECT_NAME} main.cpp lib/characters.cpp) # Create an executable
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/lib)
