cmake_minimum_required (VERSION 2.6)
# The version number.
project (Ice)

set (Ice_VERSION_MAJOR 1)
set (Ice_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/IceConfig.h.in"
  "${PROJECT_BINARY_DIR}/src/IceConfig.h"
  )
 
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")
set(SOURCES src/main.cpp src/Terra.cpp)
add_executable(Ice ${SOURCES})
