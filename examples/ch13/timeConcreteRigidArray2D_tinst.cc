// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE

#include "Array/ConcreteRigidArray2d.h"

#include "Array/ConcreteFormedArray2d.h"
#include "Array/ConcreteFortranArray2d.h"

const int mat_dim = 50;

template class ConcreteRigidArray2d<double, mat_dim, mat_dim>;

template class ConcreteFormedArray2d<double>;

template class ConcreteFortranArray2d<double>;

template class ConcreteArray2dRef<ConcreteRowMajorSubscriptor<2>, double>;

#endif
