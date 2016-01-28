# @file SetSolver/SciEng/Units/CMakeLists.txt  -- CMake file for Units

file(GLOB headers *.h)
file(GLOB sources Physical.C)

set(units_SRCS ${headers} ${sources} PARENT_SCOPE)