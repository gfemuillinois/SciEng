
// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE

#include <iostream>

#include "SciEng/utils.h"
#include "Array/ConcreteFormedArray1d.h"
#include "Array/ConcreteFormedArray2d.h"

#include "IteratorFrobenius.h"

template class ConcreteFormedArray1d<double>;

template class ConcreteFormedArray2d<double>;

template ConcreteFormedArray1d<double>::EltT FrobeniusNorm<ConcreteFormedArray1d<double> >
( ConcreteFormedArray1d<double> const & );

template ConcreteFormedArray2d<double>::EltT FrobeniusNorm<ConcreteFormedArray2d<double> >
( ConcreteFormedArray2d<double> const & );


#endif
