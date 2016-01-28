# @file SetSolver/SciEng/DataModeling/CMakeLists.txt  -- CMake file for DataModeling

file(GLOB headers *.h)
file(GLOB sources GaussianDeviates.C FormedPhysicalData.C)

set(datamodeling_SRCS ${sources} PARENT_SCOPE)

list(REMOVE_ITEM headers ${CMAKE_CURRENT_SOURCE_DIR}/UniformDeviates.h)
set(datamodeling_GROUP ${headers} PARENT_SCOPE)