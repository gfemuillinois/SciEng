// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE

#include "Array/ConcreteRigidArray3d.h"
#include "Array/ConcreteFormedArray3d.h"

const int mat_dim = 25;

template class ConcreteRigidArray3d<double, mat_dim, mat_dim, mat_dim>;

template class ConcreteFormedArray3d<double>;

#endif
