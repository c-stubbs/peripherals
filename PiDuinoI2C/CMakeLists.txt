cmake_minimum_required(VERSION 3.5)
project(i2c_testing)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find pigpio from Findpigpio.cmake
find_package(PkgConfig REQUIRED)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/external/")

# Find Dependencies
find_package(pigpio REQUIRED)

# Set the include directories
include_directories(include
  ${CMAKE_CURRENT_LIST_DIR}
  ${pigpio_INCLUDE_DIRS}
)

# Create Executable
add_executable(i2c_test src/PiDuinoI2C_example.cpp)
target_link_libraries(i2c_test PUBLIC ${pigpiod_if2_LIBRARY})

