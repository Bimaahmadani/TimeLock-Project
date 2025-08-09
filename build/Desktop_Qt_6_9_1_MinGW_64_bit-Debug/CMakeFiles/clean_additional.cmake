# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TimeLock_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TimeLock_autogen.dir\\ParseCache.txt"
  "TimeLock_autogen"
  )
endif()
