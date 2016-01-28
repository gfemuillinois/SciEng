# @file SetSolver/SciEng/AutoDeriv/CMakeLists.txt  -- CMake file for AutoDeriv

file(GLOB headers *.h)
#file(GLOB sources *.c *.cpp *.C)

#set(autoderiv_SRCS ${headers} PARENT_SCOPE)
set(autoderiv_SRCS ${headers} ${sources} PARENT_SCOPE)