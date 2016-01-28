# @file SetSolver/SciEng/CMakeLists.txt  -- CMake file for the SciEng module

add_subdirectory(Algebra)
add_subdirectory(Array)
add_subdirectory(AutoDeriv)
add_subdirectory(DataModeling)
add_subdirectory(Function)
add_subdirectory(LapackWrap)
add_subdirectory(SciEng)
add_subdirectory(Units)
add_subdirectory(Vector)

set(scieng_STAT_SRCS ${headers} ${sources} ${algebra_SRCS} ${array_SRCS} ${autoderiv_SRCS} ${datamodeling_SRCS} ${function_SRCS} ${lapackwrap_SRCS} ${scieng2_SRCS} ${units_SRCS} ${vector_SRCS} PARENT_SCOPE)
set(scieng_STAT_GROUP ${scieng2_GROUP} ${datamodeling_GROUP})