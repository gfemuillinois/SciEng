# @file SetSolver/SciEng/Array/CMakeLists.txt  -- CMake file for Array

file(GLOB headers *.h)
file(GLOB sources ArrayShape.C ConcreteFortranSymmetricPackedArray2d.C)

set(array_SRCS ${headers} ${sources} PARENT_SCOPE)