// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE

#include "FormedArithmetic.h"

template class ConcreteFormedArray2d<double>;

template class ConcreteArrayShape<2>;

template class ConcreteArray2dRef<ConcreteRowMajorSubscriptor<2>, double>;

template class DistributingEquivalentCategory<FormedArithmetic2d<double> >;

template  std::ostream & operator<<<ConcreteRowMajorSubscriptor<2>, double>(std::ostream &, ConcreteArray2dConstRef<ConcreteRowMajorSubscriptor<2>, double> const&);

template void ConcreteArray2d<ConcreteRowMajorSubscriptor<2>, double>::swap(ConcreteArray2d<ConcreteRowMajorSubscriptor<2>, double>&);

#endif
