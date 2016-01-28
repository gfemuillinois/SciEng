# @file SetSolver/SciEng/LapackWrap/CMakeLists.txt  -- CMake file for LapackWrap

file(GLOB headers *.h)
file(GLOB sources BlasSubroutines.C LapackSubroutines.C LapackErr.C timer.C timeConcreteBlas1d_tinst.cc timeConcreteBlas2d_tinst.cc timeLapackWrap_tinst.cc)

set(lapackwrap_SRCS ${headers} ${sources} PARENT_SCOPE)