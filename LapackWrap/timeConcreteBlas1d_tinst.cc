// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE

#include "LapackWrap/ConcreteBlas1d.h"


template class ConcreteBlas1d<double>;

template class ConcreteFortranArray1d<double>;

//template class ConcreteArrayShape<1>;

template class DistributingEquivalentCategory< ConcreteBlas1d<double> >;
#endif
