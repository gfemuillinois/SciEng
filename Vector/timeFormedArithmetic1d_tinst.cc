// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE
#include "FormedArithmetic.h"

template class ConcreteFormedArray1d<double>;

template class ConcreteArrayShape<1>;

template class DistributingEquivalentCategory<FormedArithmetic1d<double> >;

template class DistributingMetricSpace<FormedArithmetic1d<double>, double>;

#endif
