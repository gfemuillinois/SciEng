// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE

#include "Array/ConcreteFortranArray2d.h"

#include "Array/FormedArray1d.h"
#include "Array/FormedArray2d.h"
#include "Array/FormedArray3d.h"

template class ConcreteFortranArray2d<double>;

template class ConcreteArray2dRef<ConcreteColumnMajorSubscriptor<2>, double>;

template std::ostream & operator<< <double>
(std::ostream &, ConstArray2d<double> const &);

template std::ostream & operator<< <int>
(std::ostream &, ConstArray1d<int> const &);

template std::ostream & operator<< <ConcreteColumnMajorSubscriptor<2>, double>
(std::ostream &, ConcreteArray2dConstRef<ConcreteColumnMajorSubscriptor<2>, double> const &);

template class FormedArray1d<int>;

template class FormedArray2d<double>;

template class ConcreteFormedArray2d<int>;

template class ConcreteFormedArray2d<double>;

template class ConcreteFormedArray1d<int>;


template class ConcreteArrayProjection1d<ConcreteColumnMajorSubscriptor<2>, double>;

#endif
