
// Dummy file to create the template instance SimpleArray<float>
// This is how we handle templates with g++
// Link the object generated from the compilation of this file with
// any program that uses the instance SimpleArray<float> 


#ifdef NO_IMPLICIT_TEMPLATE

#include "examples/ch6/SimpleArray.h"

template class SimpleArray<float>;

#endif
