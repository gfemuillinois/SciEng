
// Dummy file to create the template instances

#ifdef NO_IMPLICIT_TEMPLATE

#include "tASGArray.h"

template std::ostream & operator<< <ConcreteRowMajorSubscriptor<1>, double>
(std::ostream &, ConcreteArray1dConstRef<ConcreteRowMajorSubscriptor<1>, double> const &);

template class ConcreteFormedArray1d<double>;

template class AbelianSemiGroupCategory<AdditiveArray>;

template class ConcreteArrayShape<1>;

#endif
