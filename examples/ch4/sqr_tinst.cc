
// Dummy file to create the template instances.
// This is how we handle templates with g++
// Link the object generated from the compilation of this file with
// any program that uses the instances used here 


#ifdef NO_IMPLICIT_TEMPLATE

#include <complex>
#include "SciEng/utils.h"        /* the template fn sqr is declared here */

using sce::sqr;

template float sqr(float x);

template double sqr(double x);

template int sqr(int x);

template complex<double> sqr(complex<double> x);
#endif
