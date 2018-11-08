cmake_minimum_required (VERSION 2.6)
project (Tutorial)
# The version number.
set (Tutorial_VERSION_MAJOR 2)
set (Tutorial_VERSION_MINOR 3)
 
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/src/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/src/TutorialConfig.h"
  )
 
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}/src")

# should we use our own math functions?
option (USE_MYMATH 
        "Use tutorial provided math implementation" ON) 

# add the MathFunctions library?
#
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/libs/funcs")
  add_subdirectory (libs/funcs)
  set (EXTRA_LIBS ${EXTRA_LIBS} util)
endif (USE_MYMATH)
 
# add the executable
add_executable(Tutorial hello.cpp) # produce Tutorial.exe, which name can by self-defined

# ${EXTRA_LIBS} is going to be replace by util, the library util.lib link by project, add to project automatically
target_link_libraries (Tutorial ${EXTRA_LIBS})