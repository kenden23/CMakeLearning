cmake_minimum_required (VERSION 2.6)
# the name of the project
project (Tutorial)
# The version number. according to @Tutorial_VERSION_MAJOR@ in .in file, in the middle of @@
set (Tutorial_VERSION_MAJOR 2)
set (Tutorial_VERSION_MINOR 3)
 
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  # set the Tutorial_VERSION_MAJOR here #define Tutorial_VERSION_MAJOR @Tutorial_VERSION_MAJOR@
  "${PROJECT_SOURCE_DIR}/src/TutorialConfig.h.in"
  # generate the new TutorialConfig.h for the project, with values generate by .in file
  # and ignore all the original values in this header file
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

# the library util.lib link by project, add to project automatically
# ${EXTRA_LIBS} is going to be replaced by libs\funcs\Debug\util.lib
# It will add correct path automatically, good.
target_link_libraries (Tutorial ${EXTRA_LIBS})