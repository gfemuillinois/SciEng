// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE

#include "RigidArithmetic.h"

template class DistributingEquivalentCategory<RigidArithmetic1d<double, 250> >;

template class DistributingMetricSpace<RigidArithmetic1d<double, 250>, double>;

template void crossProd<double>
(RigidArithmetic1d<double, 3> const &, RigidArithmetic1d<double, 3> const &, 
 RigidArithmetic1d<double, 3> &);

template std::ostream & operator<<<double, 3>(std::ostream &, ConcreteRigidArray1d<double, 3> const &);

#endif
