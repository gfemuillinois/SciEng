// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE

#include "RigidArithmetic.h"

template class ConcreteRigidArray2d<double, 25, 25>;

template class DistributingEquivalentCategory<RigidArithmetic2d<double, 25, 25> >;

#endif
