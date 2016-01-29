# @file SetSolver/SciEng/SciEng/CMakeLists.txt  -- CMake file for SciEng

file(GLOB headers *.h)
file(GLOB sources ArrayErr.C SciEngString.C SciEngErr.C Boolean.C Fallible.C NewHandler.C SciEngEnvironment.C Terminate.C)

set(scieng2_SRCS ${sources} PARENT_SCOPE)
set(scieng2_GROUP ${headers} PARENT_SCOPE)