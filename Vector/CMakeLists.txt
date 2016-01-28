# @file SetSolver/SciEng/Vector/CMakeLists.txt  -- CMake file for Vector

file(GLOB headers *.h)
file(GLOB sources MisMatchedSizeErr.C ConcreteVector3d.C timer.C timeRigidArithmetic1d_tinst.cc timeFormedArithmetic1d_tinst.cc timeRigidArithmetic2d_tinst.cc timeFormedArithmetic2d_tinst.cc)

set(vector_SRCS ${headers} ${sources} PARENT_SCOPE)