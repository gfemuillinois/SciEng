# @file SetSolver/SciEng/Function/CMakeLists.txt  -- CMake file for Function

file(GLOB headers *.h)
file(GLOB sources Function.C)

set(function_SRCS ${headers} ${sources} PARENT_SCOPE)