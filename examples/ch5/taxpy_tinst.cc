// Dummy file to create the template instances
// This is how we handle templates with g++
// Link the object generated from the compilation of this file with
// any program that uses the instances created here


#ifdef NO_IMPLICIT_TEMPLATE

#include <complex>

#include "axpy.h"

template void axpy(double alpha, const Vector<double>& x, 
		   Vector<double>& y);

template void axpy(int alpha, const Vector<int>& x, 
		   Vector<int>& y);

template void axpy(complex<double> alpha, const Vector<complex<double> >& x, 
		   Vector<complex<double> >& y);

#include "Array/ConcreteArrayShape.h"

#include "Array/ConcreteArray1d.h"

#include "Array/ConcreteFormedArray1d.h"

#include <complex>

template class ConcreteFormedArray1d<double>;

template class ConcreteFormedArray1d<int>;

template class ConcreteFormedArray1d<complex<double> >;

#endif
