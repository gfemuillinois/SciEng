// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE

#include "Array/ConcreteRigidArray1d.h"

#include "Array/ConcreteFormedArray1d.h"
#include "Array/ConcreteFortranArray1d.h"

const int vec_dim = 250;

template class ConcreteRigidArray1d<double, vec_dim>;

template class ConcreteFormedArray1d<double>;

template class ConcreteFortranArray1d<double>;

#endif
