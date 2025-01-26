cmake_minimum_required(VERSION 3.16)
project(mcl-heat-transfer LANGUAGES CXX)

# Enable C++17 or higher
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use vcpkg toolchain
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  message(FATAL_ERROR "Please specify the vcpkg toolchain file.")
endif()

# Find dependencies - installed through vcpkg
#find_package(spdlog REQUIRED)
#find_package(yaml-cpp REQUIRED)
find_package(GTest CONFIG REQUIRED)

# Enable testing
enable_testing()


# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/inc)

# Add the tests directory
add_subdirectory(src)
add_subdirectory(tests)