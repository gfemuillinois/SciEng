
// Dummy file to create the template instances 

#ifdef NO_IMPLICIT_TEMPLATE

#include "LapackWrap/Lapack.h"
#include "LapackWrap/RectSVDRep.h"

template class LapackUnfactored< RectSVDRep<double> >;

template class LapackFactored< RectSVDRep<double> >;

template ostream & operator<< <ConcreteColumnMajorSubscriptor<1>, double>
(ostream &, ConcreteArray1dConstRef<ConcreteColumnMajorSubscriptor<1>, double> const &);

template class ConcreteFortranArray1d<double>;

#endif
