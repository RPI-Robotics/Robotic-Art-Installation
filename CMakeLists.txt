# CMakeList.txt : CMake project for RAI, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("RAI")

# Add source to this project's executable.
add_executable (RAI "RAI.cpp" "RAI.h" "include/BVHNode.h" "include/segmentContainer.h" "include/path.h" "include/e42motor.h" "include/n17motor.h" "include/m57motor.h" "include/armController.h" "include/timingUtility.h" "include/canvasController.h" "include/hardwareController.h" "include/svgParser.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RAI PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
