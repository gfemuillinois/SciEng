// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE
#include "FormedArithmetic.h"

template class ConcreteFormedArray1d<double>;

//template class ConcreteArrayShape<1>;

template class DistributingEquivalentCategory<FormedArithmetic1d<double> >;

template class DistributingMetricSpace<FormedArithmetic1d<double>, double>;

template ostream & operator<<<ConcreteRowMajorSubscriptor<1>, double>(ostream &, ConcreteArray1dConstRef<ConcreteRowMajorSubscriptor<1>, double> const &);

template void ConcreteArray1d<ConcreteRowMajorSubscriptor<1>, double>::swap(ConcreteArray1d<ConcreteRowMajorSubscriptor<1>, double> &);

#endif
