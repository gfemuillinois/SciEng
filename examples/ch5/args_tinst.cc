// Dummy file to create the template instances
// This is how we handle templates with g++
// Link the object generated from the compilation of this file with
// any program that uses the instances created here


#ifdef NO_IMPLICIT_TEMPLATE

#include <math.h>

#include "Array/ConcreteFormedArray1d.h"

template class ConcreteFormedArray1d<float>;

template class ConcreteArrayShape<1>;
#endif
