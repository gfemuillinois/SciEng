
// Dummy file to create the template instances CheckedSimpleArray<float>
// This is how we handle template instatiations with g++
// Link the object generated from the compilation of this file with
// any program that uses the instance CheckedSimpleArray<float> 


#ifdef NO_IMPLICIT_TEMPLATE

#include "CheckedSimpleArray.h"

template class CheckedSimpleArray<float>;

#endif
