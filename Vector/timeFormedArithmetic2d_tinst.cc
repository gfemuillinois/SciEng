// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE

#include "FormedArithmetic.h"

template class ConcreteFormedArray2d<double>;

template class ConcreteArrayShape<2>;

template class ConcreteArray2dRef<ConcreteRowMajorSubscriptor<2>, double>;

template class DistributingEquivalentCategory<FormedArithmetic2d<double> >;
#endif
