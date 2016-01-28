# @file SetSolver/SciEng/Algebra/CMakeLists.txt  -- CMake file for Algebra

file(GLOB headers *.h)
#file(GLOB sources *.C)

file(GLOB sources ComplexFloat.C)

set(algebra_SRCS ${headers} ${sources} PARENT_SCOPE)